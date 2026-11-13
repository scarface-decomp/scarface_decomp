// ============================================================================
// SCARFACE: THE WORLD IS YOURS — April 2006 prototype game.xbe, world/JointCollisionTrack.cpp (3 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 3 of 4 functions matched (75.00%). NOT COMPLETE YET.
// The 1 still to do are listed in their place in Original_Binary_Order_Proto.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] JointCollisionTrack::vfunc_08 (0x000D5EE0, 25 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as LocomotionAnimDataTrack::vfunc_08 (0x000E9840), which was matched first;
// its addresses and names were swapped for this function's.
// JointCollisionTrack::vfunc_08 (0x000D5EE0, 25 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_004017F0[];

class JointCollisionTrack
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

int JointCollisionTrack::vfunc_08(int a1)
{
    int r_eax;

    r_eax = 0;
    if (a1 >= 0) {
        if ((unsigned int)a1 >= (unsigned int)3) goto L_16;
        r_eax = DAT_004017F0[a1];
    }
L_16:
    return r_eax;
}

// ============================================================================
// [VERIFIED] JointCollisionTrack::vfunc_20 (0x000D5F00, 46 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as JointCollisionTrack::vfunc_20 (0x000E8380), which was matched first;
// its addresses and names were swapped for this function's.
// JointCollisionTrack::vfunc_20 (0x000D5F00, 46 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    int sub_000D21A0(int, int);
};

extern "C" int DAT_003F52D0;
extern "C" int __cdecl sub_00025140(int, int);

class JointCollisionTrack
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

int JointCollisionTrack::vfunc_20(int a1)
{
    int t2;

    t2 = sub_00025140(28, DAT_003F52D0);
    if (t2) {
        return ((Object*)t2)->sub_000D21A0((int)this, a1);
    }
    return 0;
}

// ============================================================================
// [VERIFIED] JointCollisionTrack::vfunc_03 (0x000D5F40, 46 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as Animation360Track::vfunc_03 (0x000E7400), which was matched first;
// its addresses and names were swapped for this function's.
// JointCollisionTrack::vfunc_03 (0x000D5F40, 46 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field1C
{
    void sub_001B7A10();
};

extern "C" char DAT_0038740C[];
extern "C" void __cdecl sub_001FCF60(int);

class JointCollisionTrack
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual JointCollisionTrack* vfunc_03(int a1);
    void sub_00020600();
    char m_pad04[0x18];
    Field1C m_Field1C; // +0x1C
};

JointCollisionTrack* JointCollisionTrack::vfunc_03(int a1)
{
    *(int*)this = (int)DAT_0038740C;
    m_Field1C.sub_001B7A10();
    sub_00020600();
    if (a1 & 1) {
        sub_001FCF60((int)this);
    }
    return this;
}

