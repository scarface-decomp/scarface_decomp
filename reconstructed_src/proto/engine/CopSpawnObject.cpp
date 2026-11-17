// ============================================================================
// SCARFACE: THE WORLD IS YOURS — April 2006 prototype game.xbe, engine/CopSpawnObject.cpp (5 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 5 of 10 functions matched (50.00%). NOT COMPLETE YET.
// The 5 still to do are listed in their place in Original_Binary_Order_Proto.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] CopSpawnObject::vfunc_05 (0x001A2680, 5 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as SoundEntityLoader::vfunc_04 (0x00064FA0), which was matched first;
// its addresses and names were swapped for this function's.
// CopSpawnObject::vfunc_05 (0x001A2680, 5 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __cdecl sub_001B0CD0(void);

class CopSpawnObject
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_05();
};

void CopSpawnObject::vfunc_05()
{
    sub_001B0CD0();
}

// ============================================================================
// [VERIFIED] CopSpawnObject::vfunc_00 (0x001A3170, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as CollisionBehaviourTypeGroup::vfunc_00 (0x000123B0), which was matched first;
// its addresses and names were swapped for this function's.
// CopSpawnObject::vfunc_00 (0x001A3170, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_004173F0[];

class CopSpawnObject
{
public:
    virtual void* vfunc_00();
};

void* CopSpawnObject::vfunc_00()
{
    return DAT_004173F0;
}

// ============================================================================
// [VERIFIED] CopSpawnObject::vfunc_35 (0x001A4020, 150 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// CopSpawnObject::vfunc_35 (Proto 0x001A4020, 150 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field118
{
    void sub_00029460();
};

struct Field90
{
    int sub_001A62B0();
    void sub_001A6530(int);
};

extern "C" void __stdcall sub_001A3180(int);

class CopSpawnObject
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
    virtual void vfunc_35();
    void sub_001A3310(int);
    char m_pad04[0x8C];
    Field90* m_Field90; // +0x90
    bool m_Field94; // +0x94
    char m_pad95[0x3];
    Field90* m_Field98; // +0x98
    bool m_Field9C; // +0x9C
    char m_pad9D[0x7B];
    Field118* m_Field118; // +0x118
};

void CopSpawnObject::vfunc_35()
{
    sub_001A3180(0);
    if (m_Field94) {
        if (!*(bool*)((int)m_Field90 + 20)) {
            if (m_Field90->sub_001A62B0()) goto L_3E;
        }
        m_Field90->sub_001A6530(32);
        m_Field94 = false;
    }
L_3E:
    if (m_Field9C) {
        if (!*(bool*)((int)m_Field98 + 20)) {
            if (m_Field98->sub_001A62B0()) goto L_72;
        }
        m_Field98->sub_001A6530(32);
        m_Field9C = false;
    }
L_72:
    sub_001A3310(0);
    if (m_Field118) {
        m_Field118->sub_00029460();
        m_Field118 = 0;
    }
}

// ============================================================================
// [VERIFIED] CopSpawnObject::vfunc_01 (0x001A46B0, 30 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as Collidable::vfunc_03 (0x00011F20), which was matched first;
// its addresses and names were swapped for this function's.
// CopSpawnObject::vfunc_01 (0x001A46B0, 30 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __cdecl sub_001A3F70(void);
extern "C" void __cdecl sub_00025160(int);

class CopSpawnObject
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual CopSpawnObject* vfunc_01(int a1);
};

CopSpawnObject* CopSpawnObject::vfunc_01(int a1)
{
    sub_001A3F70();
    if (a1 & 1) {
        sub_00025160((int)this);
    }
    return this;
}

// ============================================================================
// [VERIFIED] CopSpawnObject::vfunc_43 (0x00214440, 6 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// CopSpawnObject::vfunc_43 (Proto 0x00214440, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

class CopSpawnObject
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
    virtual void vfunc_35();
    virtual void vfunc_36();
    virtual void vfunc_37();
    virtual void vfunc_38();
    virtual void vfunc_39();
    virtual void vfunc_40();
    virtual void vfunc_41();
    virtual void vfunc_42();
    virtual int vfunc_43();
};

int CopSpawnObject::vfunc_43()
{
    return 32;
}

