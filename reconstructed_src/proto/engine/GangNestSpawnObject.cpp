// ============================================================================
// SCARFACE: THE WORLD IS YOURS — April 2006 prototype game.xbe, engine/GangNestSpawnObject.cpp (7 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 7 of 8 functions matched (87.50%). NOT COMPLETE YET.
// The 1 still to do are listed in their place in Original_Binary_Order_Proto.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] GangNestSpawnObject::vfunc_00 (0x001A79A0, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as CollisionBehaviourTypeGroup::vfunc_00 (0x000123B0), which was matched first;
// its addresses and names were swapped for this function's.
// GangNestSpawnObject::vfunc_00 (0x001A79A0, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_00417104[];

class GangNestSpawnObject
{
public:
    virtual void* vfunc_00();
};

void* GangNestSpawnObject::vfunc_00()
{
    return DAT_00417104;
}

// ============================================================================
// [VERIFIED] GangNestSpawnObject::vfunc_05 (0x001A79B0, 5 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as SoundEntityLoader::vfunc_04 (0x00064FA0), which was matched first;
// its addresses and names were swapped for this function's.
// GangNestSpawnObject::vfunc_05 (0x001A79B0, 5 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __cdecl sub_001AA030(void);

class GangNestSpawnObject
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_05();
};

void GangNestSpawnObject::vfunc_05()
{
    sub_001AA030();
}

// ============================================================================
// [VERIFIED] GangNestSpawnObject::vfunc_33 (0x001A79C0, 25 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// bin: proto
// va: 0x001A79C0
// what: 
// tool: the portal's starter code (no AI)

// GangNestSpawnObject::vfunc_33 (Proto 0x001A79C0, 25 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" bool __cdecl sub_001AA070(void);

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
    virtual int vfunc_33();
    char m_pad04[0x52];
    bool m_Field56; // +0x56
};

int GangNestSpawnObject::vfunc_33()
{
    if (!m_Field56) {
        if (!sub_001AA070()) goto L_16;
        return 1;
    }
L_16:
    return 0;
}

// ============================================================================
// [VERIFIED] GangNestSpawnObject::vfunc_01 (0x001A79E0, 36 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as CollisionBehaviourTypeGroup::vfunc_01 (0x00013840), which was matched first;
// its addresses and names were swapped for this function's.
// GangNestSpawnObject::vfunc_01 (0x001A79E0, 36 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_003A1CFC[];
extern "C" void __cdecl sub_00025160(int);
extern "C" void __cdecl sub_001AA010(void);

class GangNestSpawnObject
{
public:
    virtual void vfunc_00();
    virtual GangNestSpawnObject* vfunc_01(int a1);
};

GangNestSpawnObject* GangNestSpawnObject::vfunc_01(int a1)
{
    *(int*)this = (int)DAT_003A1CFC;
    sub_001AA010();
    if (a1 & 1) {
        sub_00025160((int)this);
    }
    return this;
}

// ============================================================================
// [VERIFIED] GangNestSpawnObject::vfunc_30 (0x001A7A10, 69 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// bin: proto
// va: 0x001A7A10
// what: 
// tool: the portal's starter code (no AI)

// GangNestSpawnObject::vfunc_30 (Proto 0x001A7A10, 69 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_003A1D84[];
extern "C" void __cdecl sub_000658E0(int, int, int, int);
extern "C" int __cdecl sub_0008E650(int);
extern "C" int __cdecl sub_0008EC60(int);

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
    virtual void vfunc_30(int a1, int a2, int a3);
    char m_pad04[0xC];
    int m_Field10; // +0x10
    char m_pad14[0x3C];
    int m_Field50; // +0x50
    bool m_Field54; // +0x54
};

void GangNestSpawnObject::vfunc_30(int a1, int a2, int a3)
{
    int t2, t3;

    if (m_Field54) {
        if (m_Field50 < 0) goto L_41;
        t2 = m_Field10;
        t3 = sub_0008E650(0);
        sub_000658E0(3, (int)DAT_003A1D84, sub_0008EC60(t2), t3);
        m_Field50 = -1;
    }
L_41:
    ;
}

// ============================================================================
// [VERIFIED] GangNestSpawnObject::vfunc_31 (0x001A7A60, 77 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// bin: proto
// va: 0x001A7A60
// what: 
// tool: the portal's starter code (no AI)

// GangNestSpawnObject::vfunc_31 (Proto 0x001A7A60, 77 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_003A1D84[];
extern "C" void __cdecl sub_000658E0(int, int, int, int);
extern "C" int __cdecl sub_0008E650(int);
extern "C" int __cdecl sub_0008EC60(int);

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
    virtual void vfunc_31(int a1, int a2, int a3);
    char m_pad04[0xC];
    int m_Field10; // +0x10
    char m_pad14[0x3C];
    int m_Field50; // +0x50
    bool m_Field54; // +0x54
};

void GangNestSpawnObject::vfunc_31(int a1, int a2, int a3)
{
    int t1, t2, t3;

    if (m_Field54) {
        t1 = m_Field50;
        if (m_Field50 < 0) goto L_49;
        m_Field50 = t1 - 1;
        if ((t1 - 1) > 0) goto L_49;
        t2 = m_Field10;
        t3 = sub_0008E650(1);
        sub_000658E0(3, (int)DAT_003A1D84, sub_0008EC60(t2), t3);
        m_Field50 = -1;
    }
L_49:
    ;
}

// ============================================================================
// [VERIFIED] GangNestSpawnObject::vfunc_27 (0x001AA050, 29 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// GangNestSpawnObject::vfunc_27 (Proto 0x001AA050, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_001A8800(int);
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
    virtual void vfunc_27(int a1);
    void sub_000269E0(int);
};

void GangNestSpawnObject::vfunc_27(int a1)
{
    ((Object*)a1)->sub_001A8800((int)this);
    sub_000269E0(a1);
}

