// ============================================================================
// SCARFACE: THE WORLD IS YOURS — April 2006 prototype game.xbe, engine/Method5_void__float__float__float__float__float_.cpp (1 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: COMPLETE. All 1 functions are matched.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] CScript::Method5<void, float, float, float, float, float>::vfunc_00 (0x0011B320, 25 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as CScript::Method5<void, float, float, float, float, float>::vfunc_00 (0x00136480), which was matched first;
// its addresses and names were swapped for this function's.
// bin: xb
// va: 0x0011B320
// what: Script method thunk: calls the bound function with the two arguments and the stored value at +0x0C.
// tool: Claude Opus 5.5 (byte copy of the matched 0x0002E1D0 with its own addresses, examiner A6: ?$Method5@XMMMMM@CScript::vfunc_00)

extern "C" void __cdecl sub_0011B340(int, int, int);

class Method_0011B320
{
public:
    virtual void sub_0011B320(int a1, int a2);
    char m_pad04[0x8];
    int m_Field0C; // +0x0C
};

void Method_0011B320::sub_0011B320(int a1, int a2)
{
    sub_0011B340(a1, a2, m_Field0C);
}

