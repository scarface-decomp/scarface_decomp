// ============================================================================
// SCARFACE: THE WORLD IS YOURS — April 2006 prototype game.xbe, engine/LayeredAnimationTrack.cpp (3 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 3 of 4 functions matched (75.00%). NOT COMPLETE YET.
// The 1 still to do are listed in their place in Original_Binary_Order_Proto.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] LayeredAnimationTrack::vfunc_33 (0x000D6EE0, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as GlobalVehicleSound::vfunc_12 (0x00065430), which was matched first;
// its addresses and names were swapped for this function's.
// LayeredAnimationTrack::vfunc_33 (0x000D6EE0, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_00459FCC;

class LayeredAnimationTrack
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

int LayeredAnimationTrack::vfunc_33()
{
    return DAT_00459FCC;
}

// ============================================================================
// [VERIFIED] LayeredAnimationTrack::vfunc_08 (0x000D6F10, 16 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as SpeedCondition::vfunc_08 (0x000DD280), which was matched first;
// its addresses and names were swapped for this function's.
// LayeredAnimationTrack::vfunc_08 (0x000D6F10, 16 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_00459FD0;

class LayeredAnimationTrack
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

int LayeredAnimationTrack::vfunc_08(int a1)
{
    return *(int*)(DAT_00459FD0 + (a1 * 4));
}

// ============================================================================
// [VERIFIED] LayeredAnimationTrack::vfunc_03 (0x000D6FB0, 46 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as Animation360Track::vfunc_03 (0x000E7400), which was matched first;
// its addresses and names were swapped for this function's.
// LayeredAnimationTrack::vfunc_03 (0x000D6FB0, 46 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field1C
{
    void sub_001B7A10();
};

extern "C" char DAT_00387A2C[];
extern "C" void __cdecl sub_001FCF60(int);

class LayeredAnimationTrack
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual LayeredAnimationTrack* vfunc_03(int a1);
    void sub_00020600();
    char m_pad04[0x18];
    Field1C m_Field1C; // +0x1C
};

LayeredAnimationTrack* LayeredAnimationTrack::vfunc_03(int a1)
{
    *(int*)this = (int)DAT_00387A2C;
    m_Field1C.sub_001B7A10();
    sub_00020600();
    if (a1 & 1) {
        sub_001FCF60((int)this);
    }
    return this;
}

