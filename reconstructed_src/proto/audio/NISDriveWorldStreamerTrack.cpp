// ============================================================================
// SCARFACE: THE WORLD IS YOURS — April 2006 prototype game.xbe, audio/NISDriveWorldStreamerTrack.cpp (3 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: COMPLETE. All 3 functions are matched.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] NISDriveWorldStreamerTrack::vfunc_08 (0x001640A0, 16 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as SpeedCondition::vfunc_08 (0x000DD280), which was matched first;
// its addresses and names were swapped for this function's.
// NISDriveWorldStreamerTrack::vfunc_08 (0x001640A0, 16 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_0045DF30;

class NISDriveWorldStreamerTrack
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

int NISDriveWorldStreamerTrack::vfunc_08(int a1)
{
    return *(int*)(DAT_0045DF30 + (a1 * 4));
}

// ============================================================================
// [VERIFIED] NISDriveWorldStreamerTrack::vfunc_20 (0x001640D0, 46 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as DramaticCameraTrack::vfunc_20 (0x000E8A00), which was matched first;
// its addresses and names were swapped for this function's.
// NISDriveWorldStreamerTrack::vfunc_20 (0x001640D0, 46 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    int sub_0015E3A0(int, int);
};

extern "C" int DAT_003F52D0;
extern "C" int __cdecl sub_00025140(int, int);

class NISDriveWorldStreamerTrack
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

int NISDriveWorldStreamerTrack::vfunc_20(int a1)
{
    int t2;

    t2 = sub_00025140(16, DAT_003F52D0);
    if (t2) {
        return ((Object*)t2)->sub_0015E3A0((int)this, a1);
    }
    return 0;
}

// ============================================================================
// [VERIFIED] NISDriveWorldStreamerTrack::vfunc_03 (0x00164970, 36 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as CollisionBehaviourTypeGroup::vfunc_01 (0x00013840), which was matched first;
// its addresses and names were swapped for this function's.
// NISDriveWorldStreamerTrack::vfunc_03 (0x00164970, 36 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0039595C[];
extern "C" void __cdecl sub_001FCF60(int);
extern "C" void __cdecl sub_00020600(void);

class NISDriveWorldStreamerTrack
{
public:
    virtual void vfunc_00();
    virtual NISDriveWorldStreamerTrack* vfunc_03(int a1);
};

NISDriveWorldStreamerTrack* NISDriveWorldStreamerTrack::vfunc_03(int a1)
{
    *(int*)this = (int)DAT_0039595C;
    sub_00020600();
    if (a1 & 1) {
        sub_001FCF60((int)this);
    }
    return this;
}

