// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail Xbox default.xbe, engine/Method4_void__const_char___float__float__bool_.cpp (1 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: COMPLETE. All 1 functions are matched.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] CScript::Method4<void, const char*, float, float, bool>::vfunc_00 (0x00136310, 25 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as CScript::Method4<void, const char*, int, int, float>::vfunc_00 (0x00136120), which was matched first;
// its addresses and names were swapped for this function's.
// CScript::Method4<void, const char*, float, float, bool>::vfunc_00 (0x00136310, 25 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __cdecl sub_00136330(float, float, float);

namespace CScript {

class Method4_void__const_char___int__int__float_
{
public:
    virtual void vfunc_00(float a1, float a2);
    char m_pad04[0x8];
    float m_Field0C; // +0x0C
};

void Method4_void__const_char___int__int__float_::vfunc_00(float a1, float a2)
{
    sub_00136330(a1, a2, m_Field0C);
}

}

