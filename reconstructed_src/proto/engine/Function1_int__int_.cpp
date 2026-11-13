// ============================================================================
// SCARFACE: THE WORLD IS YOURS — April 2006 prototype game.xbe, engine/Function1_int__int_.cpp (1 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: COMPLETE. All 1 functions are matched.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] CScript::Function1<int, int>::vfunc_00 (0x0008DE80, 25 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as CScript::Function1<int, int>::vfunc_00 (0x00070780), which was matched first;
// its addresses and names were swapped for this function's.
// CScript::Function1<int, int>::vfunc_00 (0x0008DE80, 25 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int __cdecl sub_000663B0(void);

namespace CScript { 
template <class T0, class T1> class Function1
{
public:
    virtual void vfunc_00(int a1, int a2);
    char m_pad04[0x8];
    int m_Field0C; // +0x0C
};
}

template <> void CScript::Function1<int, int>::vfunc_00(int a1, int a2)
{
    int t1;

    t1 = m_Field0C;
    *(int*)a2 = ((int (__cdecl*)(int))t1)(sub_000663B0());
}

