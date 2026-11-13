// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail Xbox default.xbe, core/SequenceTrack_.cpp (2 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 2 of 3 functions matched (66.67%). NOT COMPLETE YET.
// The 1 still to do are listed in their place in Original_Binary_Order_Xbox.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] FightTree::FightActionController<fight::SequenceTrack>::vfunc_03 (0x000227C0, 30 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as FightTree::FightActionController<fight::EnterExitScriptTrack>::vfunc_03 (0x000227A0), which was matched first;
// its addresses and names were swapped for this function's.
// FightTree::FightActionController<fight::SequenceTrack>::vfunc_03 (0x000227C0, 30 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __cdecl sub_0023E7C0(void);
extern "C" void __cdecl sub_0023F7A0(int);

namespace fight { class SequenceTrack; }

namespace FightTree { 
template <class T0> class FightActionController
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual FightActionController<fight::SequenceTrack>* vfunc_03(int a1);
};
}

template <> FightTree::FightActionController<fight::SequenceTrack>* FightTree::FightActionController<fight::SequenceTrack>::vfunc_03(int a1)
{
    sub_0023E7C0();
    if (a1 & 1) {
        sub_0023F7A0((int)this);
    }
    return this;
}

// ============================================================================
// [VERIFIED] FightTree::FightActionController<fight::SequenceTrack>::vfunc_08 (0x0023E770, 19 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// FightTree::FightActionController<fight::SequenceTrack>::vfunc_08 (0x0023E770, 19 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.
#pragma optimize("y", off)

extern "C" int DAT_00492E6C;

namespace fight { class SequenceTrack; }

namespace FightTree { 
template <class T0> class FightActionController
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual void vfunc_05();
    virtual void vfunc_06();
    virtual void vfunc_07();
    virtual int vfunc_08(int a1);
};
}

template <> int FightTree::FightActionController<fight::SequenceTrack>::vfunc_08(int a1)
{
    return *(int*)(DAT_00492E6C + (a1 * 4));
}

