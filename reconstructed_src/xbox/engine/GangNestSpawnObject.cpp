// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail Xbox default.xbe, engine/GangNestSpawnObject.cpp (4 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 4 of 8 functions matched (50.00%). NOT COMPLETE YET.
// The 4 still to do are listed in their place in Original_Binary_Order_Xbox.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] GangNestSpawnObject::vfunc_00 (0x001DFC30, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as CollisionBehaviourTypeGroup::vfunc_00 (0x000123B0), which was matched first;
// its addresses and names were swapped for this function's.
// GangNestSpawnObject::vfunc_00 (0x001DFC30, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0043D8BC[];

class GangNestSpawnObject
{
public:
    virtual void* vfunc_00();
};

void* GangNestSpawnObject::vfunc_00()
{
    return DAT_0043D8BC;
}

// ============================================================================
// [VERIFIED] GangNestSpawnObject::vfunc_04 (0x001DFC40, 5 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as SoundEntityLoader::vfunc_04 (0x00064FA0), which was matched first;
// its addresses and names were swapped for this function's.
// GangNestSpawnObject::vfunc_04 (0x001DFC40, 5 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __cdecl sub_001E3440(void);

class GangNestSpawnObject
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
};

void GangNestSpawnObject::vfunc_04()
{
    sub_001E3440();
}

// ============================================================================
// [VERIFIED] GangNestSpawnObject::vfunc_35 (0x001DFC50, 24 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// GangNestSpawnObject::vfunc_35 (0x001DFC50, 24 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" bool __cdecl sub_001E3480(void);

class GangNestSpawnObject
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
    virtual void vfunc_20();
    virtual void vfunc_21();
    virtual void vfunc_22();
    virtual void vfunc_23();
    virtual void vfunc_24();
    virtual void vfunc_25();
    virtual void vfunc_26();
    virtual void vfunc_27();
    virtual void vfunc_28();
    virtual void vfunc_29();
    virtual void vfunc_30();
    virtual void vfunc_31();
    virtual void vfunc_32();
    virtual void vfunc_33();
    virtual void vfunc_34();
    virtual int vfunc_35();
    char m_pad04[0x5C];
    int m_Field60; // +0x60
};

int GangNestSpawnObject::vfunc_35()
{
    if (!(m_Field60 & 4)) {
        if (!sub_001E3480()) goto L_15;
        return 1;
    }
L_15:
    return 0;
}

// ============================================================================
// [VERIFIED] GangNestSpawnObject::vfunc_01 (0x001DFCC0, 36 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as CollisionBehaviourTypeGroup::vfunc_01 (0x00013840), which was matched first;
// its addresses and names were swapped for this function's.
// GangNestSpawnObject::vfunc_01 (0x001DFCC0, 36 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_003C7BA4[];
extern "C" void __cdecl sub_00027600(int);
extern "C" void __cdecl sub_001E3420(void);

class GangNestSpawnObject
{
public:
    virtual void vfunc_00();
    virtual GangNestSpawnObject* vfunc_01(int a1);
};

GangNestSpawnObject* GangNestSpawnObject::vfunc_01(int a1)
{
    *(int*)this = (int)DAT_003C7BA4;
    sub_001E3420();
    if (a1 & 1) {
        sub_00027600((int)this);
    }
    return this;
}

