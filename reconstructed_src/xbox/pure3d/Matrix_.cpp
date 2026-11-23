// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail Xbox default.xbe, pure3d/Matrix_.cpp (1 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: COMPLETE. All 1 functions are matched.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] pure3d::pddiStack<math::Matrix>::vfunc_00 (0x0029E600, 47 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// What it does: pure3d::pddiStack<math::Matrix>'s deleting destructor: destroys the object, frees its memory when asked (flag bit 0), and returns it.
// ============================================================================
// bin: xb
// va: 0x0029E600
// what: 
// tool: the portal's starter code (no AI)

// pure3d::pddiStack<math::Matrix>::vfunc_00 (0x0029E600, 47 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.
// This function keeps a frame pointer (push ebp; mov ebp, esp), so it is built with them on.
#pragma optimize("y", off)

extern "C" char DAT_003D9A20[];
extern "C" void __cdecl sub_00027600(int);

namespace math { class Matrix; }

namespace pure3d { 
template <class T0> class pddiStack
{
public:
    virtual pddiStack<math::Matrix>* vfunc_00(bool a1);
    char m_pad04[0x8];
    int m_Field0C; // +0x0C
};
}

template <> pure3d::pddiStack<math::Matrix>* pure3d::pddiStack<math::Matrix>::vfunc_00(bool a1)
{
    *(int*)this = (int)DAT_003D9A20;
    sub_00027600(m_Field0C);
    if (a1 & 1) {
        sub_00027600((int)this);
    }
    return this;
}

