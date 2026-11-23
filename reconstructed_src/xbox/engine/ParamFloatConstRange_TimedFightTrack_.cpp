// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail Xbox default.xbe, engine/ParamFloatConstRange_TimedFightTrack_.cpp (3 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 3 of 5 functions matched (60.00%). NOT COMPLETE YET.
// The 2 still to do are listed in their place in Original_Binary_Order_Xbox.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] fight::ParamFloatConstRange<TimedFightTrack>::vfunc_00 (0x000DDEC0, 30 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// What it does: fight::ParamFloatConstRange<TimedFightTrack>'s deleting destructor: destroys the object, frees its memory when asked (flag bit 0), and returns it.
// ============================================================================
// Same machine code as om::EntityType<GlobalVehicleSound>::vfunc_00 (0x000653D0), which was matched first;
// its addresses and names were swapped for this function's.
// fight::ParamFloatConstRange<TimedFightTrack>::vfunc_00 (0x000DDEC0, 30 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __cdecl sub_00027600(int);
extern "C" void __cdecl sub_0023EA70(void);

class TimedFightTrack;

namespace fight { 
template <class T0> class ParamFloatConstRange
{
public:
    virtual ParamFloatConstRange<TimedFightTrack>* vfunc_00(int a1);
};
}

template <> fight::ParamFloatConstRange<TimedFightTrack>* fight::ParamFloatConstRange<TimedFightTrack>::vfunc_00(int a1)
{
    sub_0023EA70();
    if (a1 & 1) {
        sub_00027600((int)this);
    }
    return this;
}

// ============================================================================
// [VERIFIED] fight::ParamFloatConstRange<TimedFightTrack>::vfunc_02 (0x00239CB0, 5 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as fight::ParamFloatConstRange<TimedFightTrack>::vfunc_02 (Proto 0x001A6230), which was matched first;
// its addresses and names were swapped for this function's.
// fight::ParamFloatConstRange<TimedFightTrack>::vfunc_02 (Proto 0x00239CB0, 5 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

class TimedFightTrack;

namespace fight { 
template <class T0> class ParamFloatConstRange
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual bool vfunc_02(int a1, int a2);
};
}

template <> bool fight::ParamFloatConstRange<TimedFightTrack>::vfunc_02(int a1, int a2)
{
    return true;
}

// ============================================================================
// [VERIFIED] fight::ParamFloatConstRange<TimedFightTrack>::vfunc_01 (0x002D5930, 6 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// What it does: fight::ParamFloatConstRange<TimedFightTrack>: Always returns 2.
// ============================================================================
// Same machine code as fight::ParamFloatConstRange<TimedFightTrack>::vfunc_01 (Proto 0x00205320), which was matched first;
// its addresses and names were swapped for this function's.
// fight::ParamFloatConstRange<TimedFightTrack>::vfunc_01 (Proto 0x002D5930, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

class TimedFightTrack;

namespace fight { 
template <class T0> class ParamFloatConstRange
{
public:
    virtual void vfunc_00();
    virtual int vfunc_01();
};
}

template <> int fight::ParamFloatConstRange<TimedFightTrack>::vfunc_01()
{
    return 2;
}

