#!/usr/bin/env python3
"""
Scripts tab parser for .cso / .dso (compiled TorqueScript-style bytecode) and .dtr (Pure3D-style
chunk files) from your own copy of the game.

What changed from the previous version:
  * The container is read by tools/script_formats.py: every length is bounds-checked, both
    code layouts (escaped bytes / raw u32) are tried, the line-break and identifier tables are
    read, and the parse is re-serialised and compared with the input (round-trip check).
  * String operands are resolved at any offset (mid-string offsets used to come back as str_0x...).
  * Decoding stops at the first opcode that is not in the table instead of carrying on out of step.
  * Jump targets are checked against the code length.
  * No more generated sample files: the old build_verified_sample_files() wrote three invented
    files (EmpireTurfPayout.cso, TonyRageModeController.dso, VehiclePhysics_Exotic.dtr) that the
    portal then listed as if they came from the game. Test fixtures now live in tests/ only.

The opcode numbering below is the stock Torque table. It has NOT been confirmed against
Scarface's own files; until it is, treat the decompiled output as a best effort.
"""

from __future__ import annotations

import re
import sys
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))
from script_formats import (format_chunk_tree, parse_dso_container,  # noqa: E402
                            string_at, walk_chunks, SCARFACE_DSO_VERSIONS)

TORQUE_OPCODES = {
    0x00: ("OP_FUNC_DECL", "fn_decl"),
    0x01: ("OP_CREATE_OBJECT", "create_obj"),
    0x02: ("OP_ADD_OBJECT", "add_obj"),
    0x03: ("OP_END_OBJECT", "end_obj"),
    0x04: ("OP_JMPIFFNOT", "jmp_if_fnot"),
    0x05: ("OP_JMPIFNOT", "jmp_if_not"),
    0x06: ("OP_JMPIFF", "jmp_if_f"),
    0x07: ("OP_JMPIF", "jmp_if"),
    0x08: ("OP_JMPIFNOT_NP", "jmp_if_not_np"),
    0x09: ("OP_JMPIF_NP", "jmp_if_np"),
    0x0A: ("OP_JMP", "jmp"),
    0x0B: ("OP_RETURN", "return"),
    0x0C: ("OP_CMPEQ", "=="),
    0x0D: ("OP_CMPGR", ">"),
    0x0E: ("OP_CMPGE", ">="),
    0x0F: ("OP_CMPLT", "<"),
    0x10: ("OP_CMPLE", "<="),
    0x11: ("OP_CMPNE", "!="),
    0x12: ("OP_XOR", "^"),
    0x13: ("OP_MOD", "%"),
    0x14: ("OP_BITAND", "&"),
    0x15: ("OP_BITOR", "|"),
    0x16: ("OP_NOT", "!"),
    0x17: ("OP_NOTF", "!"),
    0x18: ("OP_ONESCOMPLEMENT", "~"),
    0x19: ("OP_SHR", ">>"),
    0x1A: ("OP_SHL", "<<"),
    0x1B: ("OP_AND", "&&"),
    0x1C: ("OP_OR", "||"),
    0x1D: ("OP_ADD", "+"),
    0x1E: ("OP_SUB", "-"),
    0x1F: ("OP_MUL", "*"),
    0x20: ("OP_DIV", "/"),
    0x21: ("OP_NEG", "neg"),
    0x22: ("OP_SETCURVAR", "set_var"),
    0x23: ("OP_SETCURVAR_CREATE", "set_var_create"),
    0x24: ("OP_SETCURVAR_ARRAY", "set_var_arr"),
    0x25: ("OP_SETCURVAR_ARRAY_CREATE", "set_var_arr_create"),
    0x26: ("OP_LOADVAR_UINT", "load_uint"),
    0x27: ("OP_LOADVAR_FLT", "load_flt"),
    0x28: ("OP_LOADVAR_STR", "load_str"),
    0x29: ("OP_SAVEVAR_UINT", "save_uint"),
    0x2A: ("OP_SAVEVAR_FLT", "save_flt"),
    0x2B: ("OP_SAVEVAR_STR", "save_str"),
    0x2C: ("OP_SETCUROBJECT", "set_obj"),
    0x2D: ("OP_SETCUROBJECT_NEW", "set_obj_new"),
    0x2E: ("OP_SETCURFIELD", "set_field"),
    0x2F: ("OP_SETCURFIELD_ARRAY", "set_field_arr"),
    0x30: ("OP_LOADFIELD_UINT", "load_field_uint"),
    0x31: ("OP_LOADFIELD_FLT", "load_field_flt"),
    0x32: ("OP_LOADFIELD_STR", "load_field_str"),
    0x33: ("OP_SAVEFIELD_UINT", "save_field_uint"),
    0x34: ("OP_SAVEFIELD_FLT", "save_field_flt"),
    0x35: ("OP_SAVEFIELD_STR", "save_field_str"),
    0x36: ("OP_STR_TO_UINT", "str_to_uint"),
    0x37: ("OP_STR_TO_FLT", "str_to_flt"),
    0x38: ("OP_STR_TO_NONE", "str_to_none"),
    0x39: ("OP_FLT_TO_UINT", "flt_to_uint"),
    0x3A: ("OP_FLT_TO_STR", "flt_to_str"),
    0x3B: ("OP_FLT_TO_NONE", "flt_to_none"),
    0x3C: ("OP_UINT_TO_FLT", "uint_to_flt"),
    0x3D: ("OP_UINT_TO_STR", "uint_to_str"),
    0x3E: ("OP_UINT_TO_NONE", "uint_to_none"),
    0x3F: ("OP_LOADIMMED_UINT", "push_uint"),
    0x40: ("OP_LOADIMMED_FLT", "push_flt"),
    0x41: ("OP_TAG_TO_STR", "tag_to_str"),
    0x42: ("OP_LOADIMMED_STR", "push_str"),
    0x43: ("OP_LOADIMMED_IDENT", "push_ident"),
    0x44: ("OP_CALLFUNC_RESOLVE", "call_resolve"),
    0x45: ("OP_CALLFUNC", "call"),
    0x47: ("OP_ADVANCE_STR", "adv_str"),
    0x48: ("OP_ADVANCE_STR_APPENDCHAR", "adv_str_char"),
    0x49: ("OP_ADVANCE_STR_COMMA", "adv_str_comma"),
    0x4A: ("OP_ADVANCE_STR_NUL", "adv_str_nul"),
    0x4B: ("OP_REWIND_STR", "rewind_str"),
    0x4C: ("OP_TERMINATE_REWIND_STR", "term_rewind_str"),
    0x4D: ("OP_COMPARE_STR", "cmp_str"),
    0x4E: ("OP_PUSH", "push_arg"),
    0x4F: ("OP_PUSH_FRAME", "push_frame"),
}

# Opcodes whose operand count is known. Anything else stops decoding (rather than desyncing).
_OPERANDS = {0x22: 1, 0x23: 1, 0x42: 1, 0x43: 1, 0x3F: 1, 0x40: 1, 0x04: 1, 0x05: 1, 0x06: 1, 0x07: 1,
             0x08: 1, 0x09: 1, 0x0A: 1, 0x44: 3, 0x45: 3}
_NO_OPERANDS = {0x0B, 0x0C, 0x0D, 0x0E, 0x0F, 0x10, 0x11, 0x12, 0x13, 0x14, 0x15, 0x16, 0x17, 0x18, 0x19,
                0x1A, 0x1B, 0x1C, 0x1D, 0x1E, 0x1F, 0x20, 0x21, 0x26, 0x27, 0x28, 0x29, 0x2A, 0x2B, 0x36,
                0x37, 0x38, 0x39, 0x3A, 0x3B, 0x3C, 0x3D, 0x3E, 0x4E, 0x4F}


def verify_and_decompile_cso_dso(raw: bytes, filename: str = "script.cso") -> dict:
    hdr = parse_dso_container(raw, allowed_versions=SCARFACE_DSO_VERSIONS or None)
    if not hdr["ok"]:
        return {"ok": False, "error": hdr["error"]}
    words = hdr["code"]
    n_code = len(words)
    g_tab, f_tab = hdr["global_strings"], hdr["function_strings"]
    g_floats, f_floats = hdr["global_floats"], hdr["function_floats"]
    version = hdr["version"]

    def resolve_str(off: int, prefer_func: bool = False) -> str:
        for tab in ((f_tab, g_tab) if prefer_func else (g_tab, f_tab)):
            s = string_at(tab, off)
            if s is not None:
                return s
        return f"str_0x{off:04X}"

    status = []
    if not hdr["version_pinned"]:
        status.append("version not confirmed for Scarface")
    status.append("round-trip OK" if hdr["roundtrip_ok"] else "round-trip FAILED")
    decompiled = [
        "// ============================================================================",
        f"// {filename}: compiled script v{version}, {len(raw):,} bytes, {n_code} code words ({hdr['layout']})",
        f"// Container: {', '.join(status)}",
        "// Opcode table: stock Torque numbering (not yet confirmed for Scarface)",
        "// ============================================================================",
        "",
    ]
    for w in hdr["warnings"]:
        decompiled.insert(4, "// Note: " + w)
    disasm = []
    ip, indent, cur_var = 0, 0, ""
    stack: list = []
    func_ends: list = []
    stopped = ""

    def need(k: int) -> bool:
        return ip + k < n_code

    while ip < n_code:
        while func_ends and ip >= func_ends[-1]:
            func_ends.pop()
            indent = max(0, indent - 1)
            decompiled += ["    " * indent + "}", ""]
        op = words[ip]
        name, sym = TORQUE_OPCODES.get(op, (f"OP_0x{op:02X}", "?"))
        pad = "    " * indent
        if op == 0x00:
            if not need(6):
                stopped = f"truncated OP_FUNC_DECL at {ip}"
                break
            fn = resolve_str(words[ip + 1])
            ns = resolve_str(words[ip + 2]) if words[ip + 2] not in (0, 0xFFFFFFFF) else ""
            end_ip, argc = words[ip + 5], words[ip + 6]
            if not (ip < end_ip <= n_code) or argc > 64 or ip + 7 + argc > n_code:
                stopped = f"OP_FUNC_DECL at {ip} has an out-of-range end ({end_ip}) or argument count ({argc})"
                break
            args = [resolve_str(words[ip + 7 + a], prefer_func=True) for a in range(argc)]
            full = f"{ns}::{fn}" if ns else fn
            disasm.append(f"[{ip:04d}] OP_FUNC_DECL      {full}({', '.join(args)}) -> end_ip={end_ip}")
            decompiled += [pad + f"function {full}({', '.join(args)})", pad + "{"]
            indent += 1
            func_ends.append(end_ip)
            ip += 7 + argc
            continue
        if op not in TORQUE_OPCODES or (op not in _OPERANDS and op not in _NO_OPERANDS):
            stopped = f"opcode 0x{op:02X} ({name}) at {ip} has no known operand layout"
            break
        k = _OPERANDS.get(op, 0)
        if k and not need(k):
            stopped = f"truncated {name} at {ip}"
            break
        if op in (0x22, 0x23):
            cur_var = resolve_str(words[ip + 1])
            disasm.append(f"[{ip:04d}] {name:<17} {cur_var}")
        elif op in (0x42, 0x43):
            s = resolve_str(words[ip + 1])
            val = f'"{s}"' if op == 0x42 else s
            stack.append(val)
            disasm.append(f"[{ip:04d}] {name:<17} {val}")
        elif op == 0x3F:
            stack.append(str(words[ip + 1]))
            disasm.append(f"[{ip:04d}] {name:<17} {words[ip + 1]}")
        elif op == 0x40:
            idx = words[ip + 1]
            table = f_floats if func_ends else g_floats
            val = table[idx] if idx < len(table) else None
            if val is None:
                stopped = f"float index {idx} out of range at {ip}"
                break
            stack.append(f"{val:g}")
            disasm.append(f"[{ip:04d}] {name:<17} {val:g}")
        elif op in (0x26, 0x27, 0x28):
            stack.append(cur_var or "$var")
            disasm.append(f"[{ip:04d}] {name:<17} {cur_var}")
        elif op in (0x29, 0x2A, 0x2B):
            v = stack.pop() if stack else "0"
            decompiled.append(pad + f"{cur_var} = {v};")
            disasm.append(f"[{ip:04d}] {name:<17} {cur_var} = {v}")
        elif op in (0x1D, 0x1E, 0x1F, 0x20, 0x0C, 0x0D, 0x0E, 0x0F, 0x10, 0x11, 0x12, 0x13, 0x14, 0x15, 0x19, 0x1A, 0x1B, 0x1C):
            rhs = stack.pop() if stack else "0"
            lhs = stack.pop() if stack else "0"
            stack.append(f"({lhs} {sym} {rhs})")
            disasm.append(f"[{ip:04d}] {name:<17} {stack[-1]}")
        elif op == 0x4F:
            stack.append("__FRAME__")
            disasm.append(f"[{ip:04d}] {name}")
        elif op == 0x4E:
            disasm.append(f"[{ip:04d}] {name}")
        elif op in (0x44, 0x45):
            fn = resolve_str(words[ip + 1])
            ns = resolve_str(words[ip + 2]) if words[ip + 2] not in (0, 0xFFFFFFFF) else ""
            args = []
            while stack:
                top = stack.pop()
                if top == "__FRAME__":
                    break
                args.append(top)
            call = f"{ns + '::' if ns else ''}{fn}({', '.join(reversed(args))})"
            stack.append(call)
            decompiled.append(pad + call + ";")
            disasm.append(f"[{ip:04d}] {name:<17} {call}")
        elif op == 0x0B:
            v = stack.pop() if stack else ""
            decompiled.append(pad + (f"return {v};" if v else "return;"))
            disasm.append(f"[{ip:04d}] {name}")
        elif op in (0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x0A):
            tgt = words[ip + 1]
            if tgt > n_code:
                stopped = f"jump target {tgt} at {ip} is outside the code ({n_code} words)"
                break
            cond = stack.pop() if (op != 0x0A and stack) else ""
            if op in (0x04, 0x05, 0x08):
                decompiled.append(pad + f"if (!{cond}) goto L{tgt};")
            elif op in (0x06, 0x07, 0x09):
                decompiled.append(pad + f"if ({cond}) goto L{tgt};")
            else:
                decompiled.append(pad + f"goto L{tgt};")
            disasm.append(f"[{ip:04d}] {name:<17} -> [{tgt:04d}]")
        else:
            disasm.append(f"[{ip:04d}] {name}")
        ip += 1 + k

    while func_ends:
        func_ends.pop()
        indent = max(0, indent - 1)
        decompiled.append("    " * indent + "}")
    if stopped:
        decompiled += ["", f"// Decoding stopped: {stopped}."]
        disasm.append(f"-- stopped: {stopped}")
    return {
        "ok": True,
        "format": f"Compiled script v{version} ({'round-trip OK' if hdr['roundtrip_ok'] else 'round-trip failed'})",
        "size": len(raw),
        "opcode_count": n_code,
        "disasm": "\n".join(disasm),
        "decompiled_code": "\n".join(decompiled),
        "complete": not stopped,
    }


P3D_CHUNK_NAMES = {
    0xFF443350: "Pure3D::DataFileRoot",
    0x00027000: "Scarface::DataTemplateChunk",
    0x00027001: "Scarface::AttributeTableChunk",
    0x00027002: "Scarface::VehiclePhysicsRecord",
    0x00027003: "Scarface::WeaponBalanceRecord",
    0x00027004: "Scarface::EmpireTurfRecord",
    0x00010000: "Pure3D::MeshChunk",
    0x00011000: "Pure3D::ShaderChunk",
    0x00019000: "Pure3D::TextureChunk",
}


def verify_and_decompile_dtr(raw: bytes, filename: str = "data.dtr") -> dict:
    tree = walk_chunks(raw)
    if not tree["ok"]:
        return {"ok": False, "error": f"Chunk structure invalid: {tree['error']}"}
    lines = [
        "// ============================================================================",
        f"// {filename}: {tree['count']} chunks, {len(raw):,} bytes, structure fully consumed",
        "// Chunk IDs/record layouts below are labels and guesses, not confirmed formats.",
        "// ============================================================================",
        "",
    ]
    stack = [(c, 0) for c in reversed(tree["chunks"])]
    while stack:
        c, d = stack.pop()
        label = P3D_CHUNK_NAMES.get(c["id"], f"Chunk_0x{c['id']:08X}")
        payload = raw[c["offset"] + 12: c["offset"] + c["data_size"]]
        lines.append("    " * d + f"// {label} @0x{c['offset']:X}: {len(payload)} payload bytes, {len(c['children'])} children")
        stack.extend((ch, d + 1) for ch in reversed(c["children"]))
    return {
        "ok": True,
        "format": "Pure3D-style chunk file",
        "size": len(raw),
        "opcode_count": tree["count"],
        "disasm": format_chunk_tree(tree["chunks"], P3D_CHUNK_NAMES),
        "decompiled_code": "\n".join(lines),
    }


if __name__ == "__main__":
    import argparse
    ap = argparse.ArgumentParser(description="Parse .cso/.dso/.dtr files from your own copy of the game.")
    ap.add_argument("files", nargs="+")
    a = ap.parse_args()
    for f in a.files:
        raw = Path(f).read_bytes()
        res = verify_and_decompile_dtr(raw, Path(f).name) if f.lower().endswith(".dtr") else verify_and_decompile_cso_dso(raw, Path(f).name)
        print(("[OK] " if res["ok"] else "[FAIL] ") + f + ": " + (res.get("format") or res.get("error", "")))
