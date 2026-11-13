// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail Xbox default.xbe, engine/FireObject.cpp (4 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 4 of 6 functions matched (66.67%). NOT COMPLETE YET.
// The 2 still to do are listed in their place in Original_Binary_Order_Xbox.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] FireObject::vfunc_00 (0x001881C0, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as CollisionBehaviourTypeGroup::vfunc_00 (0x000123B0), which was matched first;
// its addresses and names were swapped for this function's.
// FireObject::vfunc_00 (0x001881C0, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_00433ECC[];

class FireObject
{
public:
    virtual void* vfunc_00();
};

void* FireObject::vfunc_00()
{
    return DAT_00433ECC;
}

// ============================================================================
// [VERIFIED] FireObject::vfunc_30 (0x00188370, 70 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// FireObject::vfunc_30 (0x00188370, 70 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field74
{
    void sub_000C5250(int);
};

extern "C" void __stdcall sub_00029610(int);
extern "C" int __cdecl sub_0002AC90(int);

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
    char m_pad04[0x30];
    int m_Field34; // +0x34
    char m_pad38[0x3C];
    Field74 m_Field74; // +0x74
    char m_pad75[0x17];
    int m_Field8C; // +0x8C
};

void FireObject::vfunc_30(int a1)
{
    sub_00029610(a1);
    if (sub_0002AC90(m_Field8C)) {
        if (!*(bool*)(sub_0002AC90(m_Field8C) + 34)) goto L_42;
        m_Field74.sub_000C5250((int)(&m_Field34));
    }
L_42:
    ;
}

// ============================================================================
// [VERIFIED] FireObject::vfunc_32 (0x001883C0, 70 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as FireObject::vfunc_30 (0x00188370), which was matched first;
// its addresses and names were swapped for this function's.
// FireObject::vfunc_32 (0x001883C0, 70 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field74
{
    void sub_000C5250(int);
};

extern "C" void __stdcall sub_00029540(int);
extern "C" int __cdecl sub_0002AC90(int);

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
    virtual void vfunc_32(int a1);
    char m_pad04[0x30];
    int m_Field34; // +0x34
    char m_pad38[0x3C];
    Field74 m_Field74; // +0x74
    char m_pad75[0x17];
    int m_Field8C; // +0x8C
};

void FireObject::vfunc_32(int a1)
{
    sub_00029540(a1);
    if (sub_0002AC90(m_Field8C)) {
        if (!*(bool*)(sub_0002AC90(m_Field8C) + 34)) goto L_42;
        m_Field74.sub_000C5250((int)(&m_Field34));
    }
L_42:
    ;
}

// ============================================================================
// [VERIFIED] FireObject::vfunc_01 (0x00188860, 51 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// FireObject::vfunc_01 (0x00188860, 51 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field74
{
    void sub_000C5390();
};

extern "C" char DAT_003B8904[];
extern "C" void __cdecl sub_00027600(int);
extern "C" void __cdecl sub_00188410(void);

class FireObject
{
public:
    virtual void vfunc_00();
    virtual FireObject* vfunc_01(int a1);
    void sub_00029F90();
    char m_pad04[0x70];
    Field74 m_Field74; // +0x74
};

FireObject* FireObject::vfunc_01(int a1)
{
    *(int*)this = (int)DAT_003B8904;
    sub_00188410();
    m_Field74.sub_000C5390();
    sub_00029F90();
    if (a1 & 1) {
        sub_00027600((int)this);
    }
    return this;
}

