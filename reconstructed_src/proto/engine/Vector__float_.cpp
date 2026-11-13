// ============================================================================
// SCARFACE: THE WORLD IS YOURS — April 2006 prototype game.xbe, engine/Vector__float_.cpp (1 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 1 of 3 functions matched (33.33%). NOT COMPLETE YET.
// The 2 still to do are listed in their place in Original_Binary_Order_Proto.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] CScript::Function2<math::Vector, math::Vector, float>::vfunc_00 (0x0008DD60, 25 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as CScript::Function2<math::Vector, math::Vector, float>::vfunc_00 (0x000993B0), which was matched first;
// its addresses and names were swapped for this function's.
// CScript::Function2<math::Vector, math::Vector, float>::vfunc_00 (0x0008DD60, 25 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __cdecl sub_0008DD80(int, int, int);

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
    sub_0008DD80(a1, a2, m_Field0C);
}

