// ============================================================================
// SCARFACE: THE WORLD IS YOURS — April 2006 prototype game.xbe, engine/TrackFactoryTemplate_NISActivateVehicleTrack_.cpp (1 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 1 of 2 functions matched (50.00%). NOT COMPLETE YET.
// The 1 still to do are listed in their place in Original_Binary_Order_Proto.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] fight::TrackFactoryTemplate<NISActivateVehicleTrack>::vfunc_03 (0x001619E0, 43 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as fight::ConditionFactoryTemplate<AnimationStateCondition>::vfunc_03 (0x000DE4D0), which was matched first;
// its addresses and names were swapped for this function's.
// fight::TrackFactoryTemplate<NISActivateVehicleTrack>::vfunc_03 (0x001619E0, 43 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_003944C0[];
extern "C" void __cdecl sub_001FCF60(int);
extern "C" void __cdecl sub_00163A40(void);

class NISActivateVehicleTrack;

namespace fight { 
template <class T0> class TrackFactoryTemplate
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual TrackFactoryTemplate<NISActivateVehicleTrack>* vfunc_03(int a1);
    void sub_001FBF30();
};
}

template <> fight::TrackFactoryTemplate<NISActivateVehicleTrack>* fight::TrackFactoryTemplate<NISActivateVehicleTrack>::vfunc_03(int a1)
{
    *(int*)this = (int)DAT_003944C0;
    sub_00163A40();
    sub_001FBF30();
    if (a1 & 1) {
        sub_001FCF60((int)this);
    }
    return this;
}

