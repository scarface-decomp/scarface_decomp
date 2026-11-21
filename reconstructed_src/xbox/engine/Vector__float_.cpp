// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail Xbox default.xbe, engine/Vector__float_.cpp (2 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: COMPLETE. All 2 functions are matched.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] CScript::Function2<math::Vector, math::Vector, float>::vfunc_00 (0x000993B0, 25 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// CScript::Function2<math::Vector, math::Vector, float>::vfunc_00 (0x000993B0, 25 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __cdecl sub_000993D0(int, int, int);

namespace math { class Vector; }
namespace math { class Vector; }

namespace CScript { 
template <class T0, class T1, class T2> class Function2
{
public:
    virtual void vfunc_00(int a1, int a2);
    char m_pad04[0x8];
    int m_Field0C; // +0x0C
};
}

template <> void CScript::Function2<math::Vector, math::Vector, float>::vfunc_00(int a1, int a2)
{
    sub_000993D0(a1, a2, m_Field0C);
}

// ============================================================================
// [VERIFIED] CScript::Method2<void, math::Vector, float>::vfunc_00 (0x001363B0, 25 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// What it does: Script method thunk: calls the bound function with the two arguments and the stored value at +0x0C.
// ============================================================================
// bin: xb
// va: 0x001363B0
// what: Script method thunk: calls the bound function with the two arguments and the stored value at +0x0C.
// tool: Claude Opus 5.5 (byte copy of the matched 0x0002E1D0 with its own addresses, examiner A6: ?$Method2@XVVector@math@@M@CScript::vfunc_00)

extern "C" void __cdecl sub_001363D0(int, int, int);

class Method_001363B0
{
public:
    virtual void sub_001363B0(int a1, int a2);
    char m_pad04[0x8];
    int m_Field0C; // +0x0C
};

void Method_001363B0::sub_001363B0(int a1, int a2)
{
    sub_001363D0(a1, a2, m_Field0C);
}

