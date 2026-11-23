// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail Xbox default.xbe, engine/GangNestSpawnObject.cpp (6 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 6 of 8 functions matched (75.00%). NOT COMPLETE YET.
// The 2 still to do are listed in their place in Original_Binary_Order_Xbox.cpp as "// [TODO] address name (size)"
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

// ============================================================================
// [VERIFIED] GangNestSpawnObject::vfunc_32 (0x001DFCF0, 85 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// bin: xb
// va: 0x001DFCF0
// what: 
// tool: the portal's starter code (no AI)

// GangNestSpawnObject::vfunc_32 (0x001DFCF0, 85 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_003C7C34[];
extern "C" void __cdecl sub_0006FC30(int, int, int, int);
extern "C" int __cdecl sub_00099C10(int);
extern "C" int __cdecl sub_0009A220(int);

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
    virtual void vfunc_32(int a1, int a2, int a3);
    char m_pad04[0xC];
    int m_Field10; // +0x10
    char m_pad14[0x40];
    int m_Field54; // +0x54
    char m_pad58[0x8];
    unsigned char m_Field60; // +0x60
};

void GangNestSpawnObject::vfunc_32(int a1, int a2, int a3)
{
    unsigned char t1;
    int t2, t3;

    t1 = m_Field60;
    if (m_Field60 & 1) {
        if (m_Field54 < 0) goto L_51;
        if (!(t1 & 32)) goto L_51;
        if (!(t1 & 16)) {
            t2 = m_Field10;
            t3 = sub_00099C10(0);
            sub_0006FC30(3, (int)DAT_003C7C34, sub_0009A220(t2), t3);
            m_Field60 = (unsigned char)(m_Field60 | 16);
        }
        m_Field54 = -1;
    }
L_51:
    ;
}

// ============================================================================
// [VERIFIED] GangNestSpawnObject::vfunc_29 (0x001E3460, 29 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as GangNestSpawnObject::vfunc_27 (Proto 0x001AA050), which was matched first;
// its addresses and names were swapped for this function's.
// GangNestSpawnObject::vfunc_29 (Proto 0x001E3460, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_001E0B60(int);
};

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
    virtual void vfunc_29(int a1);
    void sub_00028FE0(int);
};

void GangNestSpawnObject::vfunc_29(int a1)
{
    ((Object*)a1)->sub_001E0B60((int)this);
    sub_00028FE0(a1);
}

