// ============================================================================
// SCARFACE: THE WORLD IS YOURS — April 2006 prototype game.xbe, engine/DramaticCameraTrack.cpp (4 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: COMPLETE. All 4 functions are matched.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] DramaticCameraTrack::vfunc_33 (0x000D6390, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as GlobalVehicleSound::vfunc_12 (0x00065430), which was matched first;
// its addresses and names were swapped for this function's.
// DramaticCameraTrack::vfunc_33 (0x000D6390, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_00459FB4;

class DramaticCameraTrack
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
    virtual int vfunc_33();
};

int DramaticCameraTrack::vfunc_33()
{
    return DAT_00459FB4;
}

// ============================================================================
// [VERIFIED] DramaticCameraTrack::vfunc_08 (0x000D63C0, 16 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as SpeedCondition::vfunc_08 (0x000DD280), which was matched first;
// its addresses and names were swapped for this function's.
// DramaticCameraTrack::vfunc_08 (0x000D63C0, 16 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_00459FB8;

class DramaticCameraTrack
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

int DramaticCameraTrack::vfunc_08(int a1)
{
    return *(int*)(DAT_00459FB8 + (a1 * 4));
}

// ============================================================================
// [VERIFIED] DramaticCameraTrack::vfunc_20 (0x000D63D0, 46 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as DramaticCameraTrack::vfunc_20 (0x000E8A00), which was matched first;
// its addresses and names were swapped for this function's.
// DramaticCameraTrack::vfunc_20 (0x000D63D0, 46 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    int sub_000D2A60(int, int);
};

extern "C" int DAT_003F52D0;
extern "C" int __cdecl sub_00025140(int, int);

class DramaticCameraTrack
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

int DramaticCameraTrack::vfunc_20(int a1)
{
    int t2;

    t2 = sub_00025140(16, DAT_003F52D0);
    if (t2) {
        return ((Object*)t2)->sub_000D2A60((int)this, a1);
    }
    return 0;
}

// ============================================================================
// [VERIFIED] DramaticCameraTrack::vfunc_03 (0x000D6570, 63 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// DramaticCameraTrack::vfunc_03 (Proto 0x000D6570, 63 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_001B7A10();
};

extern "C" char DAT_00387694[];
extern "C" void __cdecl sub_001FCF60(int);

class DramaticCameraTrack
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual DramaticCameraTrack* vfunc_03(int a1);
    void sub_00020600();
    char m_pad04[0x70];
    int m_Field74; // +0x74
};

DramaticCameraTrack* DramaticCameraTrack::vfunc_03(int a1)
{
    int r_ebx, r_esi;

    *(int*)this = (int)DAT_00387694;
    r_esi = (int)(&m_Field74);
    r_ebx = 4;
    do {
        r_esi -= 16;
        ((Object*)r_esi)->sub_001B7A10();
        r_ebx -= 1;
    } while (r_ebx);
    sub_00020600();
    if (a1 & 1) {
        sub_001FCF60((int)this);
    }
    return this;
}

