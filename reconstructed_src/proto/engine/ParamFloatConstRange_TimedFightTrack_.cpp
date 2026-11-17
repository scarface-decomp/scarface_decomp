// ============================================================================
// SCARFACE: THE WORLD IS YOURS — April 2006 prototype game.xbe, engine/ParamFloatConstRange_TimedFightTrack_.cpp (4 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 4 of 5 functions matched (80.00%). NOT COMPLETE YET.
// The 1 still to do are listed in their place in Original_Binary_Order_Proto.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] fight::ParamFloatConstRange<TimedFightTrack>::vfunc_00 (0x000D6CA0, 30 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as om::EntityType<GlobalVehicleSound>::vfunc_00 (0x000653D0), which was matched first;
// its addresses and names were swapped for this function's.
// fight::ParamFloatConstRange<TimedFightTrack>::vfunc_00 (0x000D6CA0, 30 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __cdecl sub_00025160(int);
extern "C" void __cdecl sub_001FC2B0(void);

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
    sub_001FC2B0();
    if (a1 & 1) {
        sub_00025160((int)this);
    }
    return this;
}

// ============================================================================
// [VERIFIED] fight::ParamFloatConstRange<TimedFightTrack>::vfunc_02 (0x001A6230, 5 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// fight::ParamFloatConstRange<TimedFightTrack>::vfunc_02 (Proto 0x001A6230, 5 bytes)
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
// [VERIFIED] fight::ParamFloatConstRange<TimedFightTrack>::vfunc_04 (0x001FC410, 72 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// fight::ParamFloatConstRange<TimedFightTrack>::vfunc_04 (Proto 0x001FC410, 72 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
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
    virtual void vfunc_10(int, int, int);
    void sub_001F9B70();
};

class TimedFightTrack;

namespace fight { 
template <class T0> class ParamFloatConstRange
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04(int a1, int a2);
    virtual void vfunc_05(int, int);
    int m_Field04; // +0x04
};
}

template <> void fight::ParamFloatConstRange<TimedFightTrack>::vfunc_04(int a1, int a2)
{
    int local_4;

    local_4 = 0;
    ((Object*)a2)->vfunc_10(m_Field04, (int)(&local_4), 0);
    if (!*(bool*)(a2 + 16)) {
        vfunc_05(a1, local_4);
    }
    ((Object*)a2)->sub_001F9B70();
}

// ============================================================================
// [VERIFIED] fight::ParamFloatConstRange<TimedFightTrack>::vfunc_01 (0x00205320, 6 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// fight::ParamFloatConstRange<TimedFightTrack>::vfunc_01 (Proto 0x00205320, 6 bytes)
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

