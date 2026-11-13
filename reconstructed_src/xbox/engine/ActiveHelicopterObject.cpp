// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail Xbox default.xbe, engine/ActiveHelicopterObject.cpp (5 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 5 of 12 functions matched (41.67%). NOT COMPLETE YET.
// The 7 still to do are listed in their place in Original_Binary_Order_Xbox.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] ActiveHelicopterObject::vfunc_10 (0x002156C0, 11 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// ActiveHelicopterObject::vfunc_10 (0x002156C0, 11 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_000A5670();
};

class ActiveHelicopterObject
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
};

void ActiveHelicopterObject::vfunc_10()
{
    ((Object*)(int)this + 1640)->sub_000A5670();
}

// ============================================================================
// [VERIFIED] ActiveHelicopterObject::vfunc_03 (0x002156D0, 17 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// ActiveHelicopterObject::vfunc_03 (0x002156D0, 17 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __cdecl sub_00219B10(void);

class ActiveHelicopterObject
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    char m_pad04[0x6E4];
    bool m_Field6E8; // +0x6E8
};

void ActiveHelicopterObject::vfunc_03()
{
    sub_00219B10();
    m_Field6E8 = false;
}

// ============================================================================
// [VERIFIED] ActiveHelicopterObject::vfunc_01 (0x002156F0, 31 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as ActiveBoatObject::vfunc_19 (0x00214BF0), which was matched first;
// its addresses and names were swapped for this function's.
// ActiveHelicopterObject::vfunc_01 (0x002156F0, 31 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field660
{
    void sub_000A4CE0(int);
};

extern "C" void __stdcall sub_0021B3F0(int);

class ActiveHelicopterObject
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
    virtual void vfunc_01(int a1);
    char m_pad04[0x65C];
    Field660 m_Field660; // +0x660
};

void ActiveHelicopterObject::vfunc_01(int a1)
{
    sub_0021B3F0(a1);
    m_Field660.sub_000A4CE0(a1);
}

// ============================================================================
// [VERIFIED] ActiveHelicopterObject::vfunc_09 (0x00215740, 72 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// ActiveHelicopterObject::vfunc_09 (0x00215740, 72 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field660
{
    void sub_000A4D00();
};

struct Field6D8
{
    void sub_000A5930(int, int);
};

struct Object
{
    void sub_00026EC0(int);
    void sub_00026EE0();
};

class ActiveHelicopterObject
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
    void sub_0021AA40();
    char m_pad04[0x3C];
    int m_Field40; // +0x40
    char m_pad44[0x4];
    int m_Field48; // +0x48
    char m_pad4C[0x614];
    Field660 m_Field660; // +0x660
    char m_pad661[0x77];
    Field6D8 m_Field6D8; // +0x6D8
};

void ActiveHelicopterObject::vfunc_09()
{
    int local_4;

    ((Object*)(int)(&local_4))->sub_00026EC0(13);
    sub_0021AA40();
    m_Field6D8.sub_000A5930((int)(&m_Field660), (int)(&m_Field48));
    m_Field40 = (int)(&m_Field6D8);
    m_Field660.sub_000A4D00();
    ((Object*)(int)(&local_4))->sub_00026EE0();
}

// ============================================================================
// [VERIFIED] ActiveHelicopterObject::vfunc_00 (0x00215840, 60 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// ActiveHelicopterObject::vfunc_00 (0x00215840, 60 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field660
{
    void sub_000A4CA0();
};

struct Field6D8
{
    void sub_000A5890();
};

extern "C" char DAT_003CFD34[];
extern "C" void __cdecl sub_00027600(int);

class ActiveHelicopterObject
{
public:
    virtual ActiveHelicopterObject* vfunc_00(int a1);
    void sub_002198B0();
    char m_pad04[0x65C];
    Field660 m_Field660; // +0x660
    char m_pad661[0x77];
    Field6D8 m_Field6D8; // +0x6D8
};

ActiveHelicopterObject* ActiveHelicopterObject::vfunc_00(int a1)
{
    *(int*)this = (int)DAT_003CFD34;
    m_Field6D8.sub_000A5890();
    m_Field660.sub_000A4CA0();
    sub_002198B0();
    if (a1 & 1) {
        sub_00027600((int)this);
    }
    return this;
}

