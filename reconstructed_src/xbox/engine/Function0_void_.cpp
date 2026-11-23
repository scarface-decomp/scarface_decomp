// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail Xbox default.xbe, engine/Function0_void_.cpp (1 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: COMPLETE. All 1 functions are matched.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] CScript::Function0<void>::vfunc_00 (0x00070770, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as CScript::Function0<void>::vfunc_00 (Proto 0x000663A0), which was matched first;
// its addresses and names were swapped for this function's.
// bin: proto
// va: 0x00070770
// what: 
// tool: the portal's starter code (no AI)

// CScript::Function0<void>::vfunc_00 (Proto 0x00070770, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

namespace CScript { 
template <class T0> class Function0
{
public:
    virtual void vfunc_00(int a1, int a2);
    char m_pad04[0x8];
    int m_Field0C; // +0x0C
};
}

template <> void CScript::Function0<void>::vfunc_00(int a1, int a2)
{
    ((void (__cdecl*)(void))m_Field0C)();
}

