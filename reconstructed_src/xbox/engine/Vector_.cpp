// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail Xbox default.xbe, engine/Vector_.cpp (3 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 3 of 6 functions matched (50.00%). NOT COMPLETE YET.
// The 3 still to do are listed in their place in Original_Binary_Order_Xbox.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] CScript::Function2<float, math::Vector, math::Vector>::vfunc_00 (0x00099020, 25 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// CScript::Function2<float, math::Vector, math::Vector>::vfunc_00 (0x00099020, 25 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __cdecl sub_00099040(int, int, int);

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

template <> void CScript::Function2<float, math::Vector, math::Vector>::vfunc_00(int a1, int a2)
{
    sub_00099040(a1, a2, m_Field0C);
}

// ============================================================================
// [VERIFIED] CScript::Function1<math::Vector, math::Vector>::vfunc_00 (0x000991B0, 25 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// CScript::Function1<math::Vector, math::Vector>::vfunc_00 (0x000991B0, 25 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __cdecl sub_000991D0(int, int, int);

namespace math { class Vector; }
namespace math { class Vector; }

namespace CScript { 
template <class T0, class T1> class Function1
{
public:
    virtual void vfunc_00(int a1, int a2);
    char m_pad04[0x8];
    int m_Field0C; // +0x0C
};
}

template <> void CScript::Function1<math::Vector, math::Vector>::vfunc_00(int a1, int a2)
{
    sub_000991D0(a1, a2, m_Field0C);
}

// ============================================================================
// [VERIFIED] CScript::Function2<math::Vector, math::Vector, math::Vector>::vfunc_00 (0x000992C0, 25 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// CScript::Function2<math::Vector, math::Vector, math::Vector>::vfunc_00 (0x000992C0, 25 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __cdecl sub_000992E0(int, int, int);

namespace math { class Vector; }
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

template <> void CScript::Function2<math::Vector, math::Vector, math::Vector>::vfunc_00(int a1, int a2)
{
    sub_000992E0(a1, a2, m_Field0C);
}

