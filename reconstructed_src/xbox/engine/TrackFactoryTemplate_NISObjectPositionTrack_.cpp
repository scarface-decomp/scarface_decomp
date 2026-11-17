// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail Xbox default.xbe, engine/TrackFactoryTemplate_NISObjectPositionTrack_.cpp (2 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: COMPLETE. All 2 functions are matched.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] fight::TrackFactoryTemplate<NISObjectPositionTrack>::vfunc_03 (0x001839F0, 43 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as fight::ConditionFactoryTemplate<AnimationStateCondition>::vfunc_03 (0x000DE4D0), which was matched first;
// its addresses and names were swapped for this function's.
// fight::TrackFactoryTemplate<NISObjectPositionTrack>::vfunc_03 (0x001839F0, 43 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_003B6B70[];
extern "C" void __cdecl sub_0023F7A0(int);
extern "C" void __cdecl sub_00185710(void);

class NISObjectPositionTrack;

namespace fight { 
template <class T0> class TrackFactoryTemplate
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual TrackFactoryTemplate<NISObjectPositionTrack>* vfunc_03(int a1);
    void sub_0023E5E0();
};
}

template <> fight::TrackFactoryTemplate<NISObjectPositionTrack>* fight::TrackFactoryTemplate<NISObjectPositionTrack>::vfunc_03(int a1)
{
    *(int*)this = (int)DAT_003B6B70;
    sub_00185710();
    sub_0023E5E0();
    if (a1 & 1) {
        sub_0023F7A0((int)this);
    }
    return this;
}

// ============================================================================
// [VERIFIED] fight::TrackFactoryTemplate<NISObjectPositionTrack>::vfunc_07 (0x00183A20, 52 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as fight::TrackFactoryTemplate<NISObjectPositionTrack>::vfunc_07 (Proto 0x00161F50), which was matched first;
// its addresses and names were swapped for this function's.
// fight::TrackFactoryTemplate<NISObjectPositionTrack>::vfunc_07 (Proto 0x00183A20, 52 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_00242D20(int);
    int sub_001862D0();
};

extern "C" int __cdecl sub_0023F760(int);

class NISObjectPositionTrack;

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

template <> int fight::TrackFactoryTemplate<NISObjectPositionTrack>::vfunc_07()
{
    int r_edi, r_esi, t1;

    r_edi = (int)this;
    t1 = sub_0023F760(40);
    if (t1) {
        r_esi = ((Object*)t1)->sub_001862D0();
    } else {
        r_esi = 0;
    }
    if (r_edi) {
        r_edi += 8;
        ((Object*)r_esi + 8)->sub_00242D20(r_edi);
    }
    return r_esi;
}

