// ============================================================================
// SCARFACE: THE WORLD IS YOURS — April 2006 prototype game.xbe, audio/TrackFactoryTemplate_SoundPlayTrack_.cpp (2 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: COMPLETE. All 2 functions are matched.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] fight::TrackFactoryTemplate<SoundPlayTrack>::vfunc_03 (0x000CD500, 43 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as fight::ConditionFactoryTemplate<AnimationStateCondition>::vfunc_03 (0x000DE4D0), which was matched first;
// its addresses and names were swapped for this function's.
// fight::TrackFactoryTemplate<SoundPlayTrack>::vfunc_03 (0x000CD500, 43 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_003863E8[];
extern "C" void __cdecl sub_001FCF60(int);
extern "C" void __cdecl sub_000D75E0(void);

class SoundPlayTrack;

namespace fight { 
template <class T0> class TrackFactoryTemplate
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual TrackFactoryTemplate<SoundPlayTrack>* vfunc_03(int a1);
    void sub_001FBF30();
};
}

template <> fight::TrackFactoryTemplate<SoundPlayTrack>* fight::TrackFactoryTemplate<SoundPlayTrack>::vfunc_03(int a1)
{
    *(int*)this = (int)DAT_003863E8;
    sub_000D75E0();
    sub_001FBF30();
    if (a1 & 1) {
        sub_001FCF60((int)this);
    }
    return this;
}

// ============================================================================
// [VERIFIED] fight::TrackFactoryTemplate<SoundPlayTrack>::vfunc_07 (0x000CD530, 52 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as fight::TrackFactoryTemplate<LayeredAnimationTrack>::vfunc_07 (0x000DEEA0), which was matched first;
// its addresses and names were swapped for this function's.
// fight::TrackFactoryTemplate<SoundPlayTrack>::vfunc_07 (0x000CD530, 52 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    int sub_000D7610();
    void sub_0008D490(int);
};

extern "C" int __cdecl sub_001FCF20(int);

class SoundPlayTrack;

namespace fight { 
template <class T0> class TrackFactoryTemplate
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
}

template <> int fight::TrackFactoryTemplate<SoundPlayTrack>::vfunc_07()
{
    int r_edi, r_esi, t1;

    r_edi = (int)this;
    t1 = sub_001FCF20(44);
    if (t1) {
        r_esi = ((Object*)t1)->sub_000D7610();
    } else {
        r_esi = 0;
    }
    if (r_edi) {
        r_edi += 8;
        ((Object*)r_esi + 8)->sub_0008D490(r_edi);
    }
    return r_esi;
}

