// ============================================================================
// SCARFACE: THE WORLD IS YOURS — April 2006 prototype game.xbe, engine/FireObject.cpp (5 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 5 of 6 functions matched (83.33%). NOT COMPLETE YET.
// The 1 still to do are listed in their place in Original_Binary_Order_Proto.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] FireObject::vfunc_00 (0x00166070, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as CollisionBehaviourTypeGroup::vfunc_00 (0x000123B0), which was matched first;
// its addresses and names were swapped for this function's.
// FireObject::vfunc_00 (0x00166070, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0040EEF8[];

class FireObject
{
public:
    virtual void* vfunc_00();
};

void* FireObject::vfunc_00()
{
    return DAT_0040EEF8;
}

// ============================================================================
// [VERIFIED] FireObject::vfunc_05 (0x00166080, 94 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// FireObject::vfunc_05 (Proto 0x00166080, 94 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field78
{
    void sub_000B76E0(int);
};

struct Object
{
    void sub_00024AB0(int);
    void sub_00024AD0();
};

extern "C" int __cdecl sub_00028120(int);

class FireObject
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual void vfunc_05(int a1);
    void sub_00028C40(int);
    char m_pad04[0x2C];
    int m_Field30; // +0x30
    char m_pad34[0x44];
    Field78 m_Field78; // +0x78
    char m_pad79[0x17];
    int m_Field90; // +0x90
};

void FireObject::vfunc_05(int a1)
{
    int local_4;

    ((Object*)(int)(&local_4))->sub_00024AB0(14);
    sub_00028C40(a1);
    if (sub_00028120(m_Field90)) {
        if (!*(bool*)(sub_00028120(m_Field90) + 34)) goto L_50;
        m_Field78.sub_000B76E0((int)(&m_Field30));
    }
L_50:
    ((Object*)(int)(&local_4))->sub_00024AD0();
}

// ============================================================================
// [VERIFIED] FireObject::vfunc_28 (0x00166210, 70 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// FireObject::vfunc_28 (Proto 0x00166210, 70 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field78
{
    void sub_000B76E0(int);
};

extern "C" void __stdcall sub_00026F90(int);
extern "C" int __cdecl sub_00028120(int);

class FireObject
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
    virtual void vfunc_28(int a1);
    char m_pad04[0x2C];
    int m_Field30; // +0x30
    char m_pad34[0x44];
    Field78 m_Field78; // +0x78
    char m_pad79[0x17];
    int m_Field90; // +0x90
};

void FireObject::vfunc_28(int a1)
{
    sub_00026F90(a1);
    if (sub_00028120(m_Field90)) {
        if (!*(bool*)(sub_00028120(m_Field90) + 34)) goto L_42;
        m_Field78.sub_000B76E0((int)(&m_Field30));
    }
L_42:
    ;
}

// ============================================================================
// [VERIFIED] FireObject::vfunc_30 (0x00166260, 70 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// FireObject::vfunc_30 (Proto 0x00166260, 70 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field78
{
    void sub_000B76E0(int);
};

extern "C" void __stdcall sub_00026F40(int);
extern "C" int __cdecl sub_00028120(int);

class FireObject
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
    virtual void vfunc_30(int a1);
    char m_pad04[0x2C];
    int m_Field30; // +0x30
    char m_pad34[0x44];
    Field78 m_Field78; // +0x78
    char m_pad79[0x17];
    int m_Field90; // +0x90
};

void FireObject::vfunc_30(int a1)
{
    sub_00026F40(a1);
    if (sub_00028120(m_Field90)) {
        if (!*(bool*)(sub_00028120(m_Field90) + 34)) goto L_42;
        m_Field78.sub_000B76E0((int)(&m_Field30));
    }
L_42:
    ;
}

// ============================================================================
// [VERIFIED] FireObject::vfunc_01 (0x00166710, 51 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// FireObject::vfunc_01 (Proto 0x00166710, 51 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field78
{
    void sub_000B7820();
};

extern "C" char DAT_003961EC[];
extern "C" void __cdecl sub_00025160(int);
extern "C" void __cdecl sub_001662B0(void);

class FireObject
{
public:
    virtual void vfunc_00();
    virtual FireObject* vfunc_01(int a1);
    void sub_000277E0();
    char m_pad04[0x74];
    Field78 m_Field78; // +0x78
};

FireObject* FireObject::vfunc_01(int a1)
{
    *(int*)this = (int)DAT_003961EC;
    sub_001662B0();
    m_Field78.sub_000B7820();
    sub_000277E0();
    if (a1 & 1) {
        sub_00025160((int)this);
    }
    return this;
}

