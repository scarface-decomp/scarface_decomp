// ============================================================================
// SCARFACE: THE WORLD IS YOURS — April 2006 prototype game.xbe, core/SequenceTrack_.cpp (3 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: COMPLETE. All 3 functions are matched.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] FightTree::FightActionController<fight::SequenceTrack>::vfunc_03 (0x00020440, 30 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as FightTree::FightActionController<fight::EnterExitScriptTrack>::vfunc_03 (0x000227A0), which was matched first;
// its addresses and names were swapped for this function's.
// FightTree::FightActionController<fight::SequenceTrack>::vfunc_03 (0x00020440, 30 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __cdecl sub_001FC060(void);
extern "C" void __cdecl sub_001FCF60(int);

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
    sub_001FC060();
    if (a1 & 1) {
        sub_001FCF60((int)this);
    }
    return this;
}

// ============================================================================
// [VERIFIED] FightTree::FightActionController<fight::SequenceTrack>::vfunc_08 (0x001FC020, 16 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// FightTree::FightActionController<fight::SequenceTrack>::vfunc_08 (Proto 0x001FC020, 16 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_00463B24;

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
    return *(int*)(DAT_00463B24 + (a1 * 4));
}

// ============================================================================
// [VERIFIED] FightTree::FightActionController<fight::SequenceTrack>::vfunc_20 (0x001FC200, 92 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// FightTree::FightActionController<fight::SequenceTrack>::vfunc_20 (Proto 0x001FC200, 92 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    virtual void vfunc_00();
    virtual void vfunc_01();
    void sub_001F7720();
};

extern "C" char DAT_003ADAB8[];
extern "C" int __cdecl sub_00025120(int);

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
    virtual void vfunc_08();
    virtual void vfunc_09();
    virtual void vfunc_10();
    virtual void vfunc_11();
    virtual void vfunc_12();
    virtual void vfunc_13();
    virtual void vfunc_14();
    virtual void vfunc_15();
    virtual void vfunc_16();
    virtual void vfunc_17();
    virtual void vfunc_18();
    virtual void vfunc_19();
    virtual int vfunc_20(int a1);
};
}

template <> int FightTree::FightActionController<fight::SequenceTrack>::vfunc_20(int a1)
{
    int r_edi, r_esi, t5;

    r_edi = (int)this;
    r_esi = sub_00025120(16);
    if (r_esi) {
        ((Object*)r_esi)->sub_001F7720();
        *(int*)r_esi = (int)DAT_003ADAB8;
        *(int*)(r_esi + 12) = 0;
        *(int*)(r_esi + 8) = (int)this;
        ((Object*)r_edi)->vfunc_00();
        r_edi = a1;
        if (a1) {
            ((Object*)r_edi)->vfunc_00();
        }
        t5 = *(int*)(r_esi + 12);
        if (*(int*)(r_esi + 12)) {
            ((Object*)t5)->vfunc_01();
        }
        *(int*)(r_esi + 12) = r_edi;
        return r_esi;
    }
    return 0;
}

