import os
import sys

sys.path.insert(0, os.path.join(os.path.dirname(__file__), "..", "tools"))

from cpp_policy import check_genuine_cpp, check_preprocessed, format_violations, strip_cpp_comments  # noqa: E402


def rules(src):
    return sorted({v.rule for v in check_genuine_cpp(src)})


# ---------------- comment stripping ----------------

def test_strip_keeps_urls_in_strings():
    src = 'const char* u = "http://example.com"; int x = 1;'
    assert strip_cpp_comments(src) == src


def test_strip_block_comment_marker_inside_string():
    src = 'const char* s = "/*"; int keep = 1; /* real */ int also = 2;'
    out = strip_cpp_comments(src)
    assert "int keep = 1;" in out and "int also = 2;" in out and "real" not in out


def test_strip_preserves_line_count():
    src = "int a;\n/* one\ntwo\nthree */\nint b; // tail\n"
    assert strip_cpp_comments(src).count("\n") == src.count("\n")


def test_strip_char_literals():
    src = "char q = '\"'; char s = '/'; int z; // c"
    out = strip_cpp_comments(src)
    assert "char q = '\"';" in out and "int z;" in out and "// c" not in out


# ---------------- allowed code ----------------

def test_plain_cpp_is_ok():
    src = """
    #include "scarface_engine.h"
    #include <string.h>
    #pragma pack(push, 4)
    struct Car { int pad[7]; float m_speed; bool naked; };
    #pragma pack(pop)
    float Car_GetSpeed(const Car* c) { return c->m_speed; }   // naked is a member name here
    const char* msg = "__asm is just text inside a string";
    """
    assert check_genuine_cpp(src) == []


def test_identifier_naked_is_allowed():
    assert rules("int naked = 0; void SetNaked(bool naked);") == []


# ---------------- forbidden constructs ----------------

def test_inline_asm_variants():
    assert "token:__asm" in rules("void f() { __asm { nop } }")
    assert "token:_asm" in rules("void f() { _asm nop }")
    assert "token:_emit" in rules("void f() { __asm _emit 0x90 }")


def test_asm_hidden_by_line_splice():
    src = "void f() { __a\\\nsm { nop } }"
    assert "token:__asm" in rules(src)


def test_asm_hidden_after_url_comment_trick():
    # Old regex stripper treated // inside the string as a comment and deleted the __asm after it.
    src = 'const char* u = "http://x"; void f() { __asm { nop } }'
    assert "token:__asm" in rules(src)


def test_trigraph_directive():
    src = "??=pragma code_seg(\".text$a\")\nint x;"
    assert "pragma:code_seg" in rules(src)


def test_declspec_naked_and_allocate():
    assert "declspec:naked" in rules("__declspec(naked) void f() {}")
    assert "declspec:naked" in rules("__declspec( naked ) void f() {}")
    assert "declspec:naked" in rules("_declspec(naked) void f() {}")
    assert "declspec:allocate" in rules('__declspec(allocate(".text$x")) unsigned char b[] = {0x90};')


def test_section_pragmas():
    for p in ("code_seg", "data_seg", "const_seg", "bss_seg", "section", "alloc_text", "init_seg", "comment"):
        assert "pragma:" + p in rules('#pragma %s(".text")\nint x;' % p), p


def test_pragma_operator():
    assert "token:__pragma" in rules('__pragma(data_seg(".text")) int x;')


def test_import_using_and_includes():
    assert "directive:import" in rules('#import "foo.tlb"')
    assert "directive:using" in rules('#using <mscorlib.dll>')
    assert "include" in rules('#include "C:\\\\secrets\\\\key.txt"')
    assert "include" in rules('#include "/etc/passwd"')
    assert "include" in rules('#include "../../server/config.py"')
    assert "include" in rules('#define P "x.h"\n#include P')


def test_keywords_in_strings_and_comments_are_ignored():
    src = '// __asm { nop }\n/* __declspec(naked) */\nconst char* s = "#pragma code_seg";\nint ok;'
    assert check_genuine_cpp(src) == []


def test_line_numbers_are_physical():
    src = "int a;\n\n/* x\n y */\nvoid f() { __asm nop }\n"
    vs = check_genuine_cpp(src)
    assert vs and vs[0].line == 5


def test_format_violations_message():
    msg = format_violations(check_genuine_cpp("void f() { __asm nop }"))
    assert "Genuine C++ policy" in msg and "line 1" in msg


# ---------------- preprocessed output ----------------

PP = r'''#line 1 "c:\\work\\sub\\submission.cpp"
#line 1 "c:\\vc71\\include\\winnt.h"
__declspec(naked) void sdk_helper() {}
#pragma comment(lib, "kernel32.lib")
#line 3 "c:\\work\\sub\\submission.cpp"
void f() { __asm nop }
'''


def test_preprocessed_ignores_sdk_headers():
    vs = check_preprocessed(PP, user_paths=[r"c:\work\sub"])
    assert [v.rule for v in vs] == ["token:__asm"]


def test_preprocessed_without_filter_checks_everything():
    rs = {v.rule for v in check_preprocessed(PP)}
    assert {"declspec:naked", "pragma:comment", "token:__asm"} <= rs


def test_macro_built_asm_caught_in_preprocessed_output():
    # Raw source hides it behind token pasting; cl /E output shows the real token.
    raw = "#define A(x) __as##x\nvoid f() { A(m) nop }"
    assert check_genuine_cpp(raw) == []          # documented limitation of the raw pre-check
    pp = '#line 1 "c:\\\\work\\\\sub\\\\s.cpp"\n\nvoid f() { __asm nop }\n'
    assert "token:__asm" in {v.rule for v in check_preprocessed(pp, user_paths=["c:/work/sub"])}
