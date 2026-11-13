// ============================================================================
// SCARFACE: THE WORLD IS YOURS — April 2006 prototype game.xbe, core/EnterExitScriptTrack__.cpp (2 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: COMPLETE. All 2 functions are matched.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] fight::TrackFactoryTemplate<FightTree::FightActionController<fight::EnterExitScriptTrack>>::vfunc_03 (0x000202E0, 43 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as fight::TrackFactoryTemplate<FightTree::FightActionController<fight::EnterExitScriptTrack>>::vfunc_03 (0x00022650), which was matched first;
// its addresses and names were swapped for this function's.
// fight::TrackFactoryTemplate<FightTree::FightActionController<fight::EnterExitScriptTrack>>::vfunc_03 (0x000202E0, 43 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0037D918[];
extern "C" void __cdecl sub_001FCF60(int);
extern "C" void __cdecl sub_001B7A10(void);

namespace fight {

class TrackFactoryTemplate_FightTree__FightActionController_fight__EnterExitScriptTrack__
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual TrackFactoryTemplate_FightTree__FightActionController_fight__EnterExitScriptTrack__* vfunc_03(int a1);
    void sub_001FBF30();
};

TrackFactoryTemplate_FightTree__FightActionController_fight__EnterExitScriptTrack__* TrackFactoryTemplate_FightTree__FightActionController_fight__EnterExitScriptTrack__::vfunc_03(int a1)
{
    *(int*)this = (int)DAT_0037D918;
    sub_001B7A10();
    sub_001FBF30();
    if (a1 & 1) {
        sub_001FCF60((int)this);
    }
    return this;
}

}

// ============================================================================
// [VERIFIED] fight::TrackFactoryTemplate<FightTree::FightActionController<fight::EnterExitScriptTrack>>::vfunc_07 (0x00020310, 61 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as fight::TrackFactoryTemplate<FightTree::FightActionController<fight::EnterExitScriptTrack>>::vfunc_07 (0x00022680), which was matched first;
// its addresses and names were swapped for this function's.
// fight::TrackFactoryTemplate<FightTree::FightActionController<fight::EnterExitScriptTrack>>::vfunc_07 (0x00020310, 61 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_001F82D0();
    void sub_0008D490(int);
};

extern "C" char DAT_0037D93C[];
extern "C" int __cdecl sub_001FCF20(int);

namespace fight {

class TrackFactoryTemplate_FightTree__FightActionController_fight__EnterExitScriptTrack__
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual void vfunc_05();
    virtual void vfunc_06();
    virtual int vfunc_07();
};

int TrackFactoryTemplate_FightTree__FightActionController_fight__EnterExitScriptTrack__::vfunc_07()
{
    int r_edi, r_esi;

    r_edi = (int)this;
    r_esi = sub_001FCF20(148);
    if (r_esi) {
        ((Object*)r_esi)->sub_001F82D0();
        *(int*)r_esi = (int)DAT_0037D93C;
    } else {
        r_esi = 0;
    }
    if (r_edi) {
        r_edi += 8;
        ((Object*)r_esi + 8)->sub_0008D490(r_edi);
    }
    return r_esi;
}

}

