// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail Xbox default.xbe, engine/Method4_void__float__float__float__float_.cpp (1 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: COMPLETE. All 1 functions are matched.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] CScript::Method4<void, float, float, float, float>::vfunc_00 (0x00136540, 25 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// What it does: Script method thunk: calls the bound function with the two arguments and the stored value at +0x0C.
// ============================================================================
// bin: xb
// va: 0x00136540
// what: Script method thunk: calls the bound function with the two arguments and the stored value at +0x0C.
// tool: Claude Opus 5.5 (byte copy of the matched 0x0002E1D0 with its own addresses, examiner A6: ?$Method4@XMMMM@CScript::vfunc_00)

extern "C" void __cdecl sub_00136560(int, int, int);

class Method_00136540
{
public:
    virtual void sub_00136540(int a1, int a2);
    char m_pad04[0x8];
    int m_Field0C; // +0x0C
};

void Method_00136540::sub_00136540(int a1, int a2)
{
    sub_00136560(a1, a2, m_Field0C);
}

