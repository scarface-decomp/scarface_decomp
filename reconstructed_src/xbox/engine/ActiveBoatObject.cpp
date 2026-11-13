// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail Xbox default.xbe, engine/ActiveBoatObject.cpp (6 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 6 of 15 functions matched (40.00%). NOT COMPLETE YET.
// The 9 still to do are listed in their place in Original_Binary_Order_Xbox.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] ActiveBoatObject::vfunc_10 (0x00214B50, 11 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as ActiveAirplaneObject::vfunc_10 (0x00213440), which was matched first;
// its addresses and names were swapped for this function's.
// ActiveBoatObject::vfunc_10 (0x00214B50, 11 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_000A3370();
};

class ActiveBoatObject
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

void ActiveBoatObject::vfunc_10()
{
    ((Object*)(int)this + 1656)->sub_000A3370();
}

// ============================================================================
// [VERIFIED] ActiveBoatObject::vfunc_03 (0x00214B60, 5 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as PropAttachToObjectBehaviour::vfunc_01 (0x0008FAF0), which was matched first;
// its addresses and names were swapped for this function's.
// ActiveBoatObject::vfunc_03 (0x00214B60, 5 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __cdecl sub_00219B10(void);

class ActiveBoatObject
{
public:
    virtual void vfunc_00();
    virtual void vfunc_03();
};

void ActiveBoatObject::vfunc_03()
{
    sub_00219B10();
}

// ============================================================================
// [VERIFIED] ActiveBoatObject::vfunc_09 (0x00214BA0, 72 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// ActiveBoatObject::vfunc_09 (0x00214BA0, 72 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field660
{
    void sub_000A0DE0();
};

struct Field788
{
    void sub_000A58C0(int, int);
};

struct Object
{
    void sub_00026EC0(int);
    void sub_00026EE0();
};

class ActiveBoatObject
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
    char m_pad661[0x127];
    Field788 m_Field788; // +0x788
};

void ActiveBoatObject::vfunc_09()
{
    int local_4;

    ((Object*)(int)(&local_4))->sub_00026EC0(13);
    sub_0021AA40();
    m_Field788.sub_000A58C0((int)(&m_Field660), (int)(&m_Field48));
    m_Field40 = (int)(&m_Field788);
    m_Field660.sub_000A0DE0();
    ((Object*)(int)(&local_4))->sub_00026EE0();
}

// ============================================================================
// [VERIFIED] ActiveBoatObject::vfunc_19 (0x00214BF0, 31 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// ActiveBoatObject::vfunc_19 (0x00214BF0, 31 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field660
{
    void sub_000A0F20(int);
};

extern "C" void __stdcall sub_00217260(int);

class ActiveBoatObject
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
    virtual void vfunc_19(int a1);
    char m_pad04[0x65C];
    Field660 m_Field660; // +0x660
};

void ActiveBoatObject::vfunc_19(int a1)
{
    sub_00217260(a1);
    m_Field660.sub_000A0F20(a1);
}

// ============================================================================
// [VERIFIED] ActiveBoatObject::vfunc_00 (0x00214D00, 60 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// ActiveBoatObject::vfunc_00 (0x00214D00, 60 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field660
{
    void sub_000A0C40();
};

struct Field788
{
    void sub_000A5890();
};

extern "C" char DAT_003CFB74[];
extern "C" void __cdecl sub_00027600(int);

class ActiveBoatObject
{
public:
    virtual ActiveBoatObject* vfunc_00(int a1);
    void sub_002198B0();
    char m_pad04[0x65C];
    Field660 m_Field660; // +0x660
    char m_pad661[0x127];
    Field788 m_Field788; // +0x788
};

ActiveBoatObject* ActiveBoatObject::vfunc_00(int a1)
{
    *(int*)this = (int)DAT_003CFB74;
    m_Field788.sub_000A5890();
    m_Field660.sub_000A0C40();
    sub_002198B0();
    if (a1 & 1) {
        sub_00027600((int)this);
    }
    return this;
}

// ============================================================================
// [VERIFIED] ActiveBoatObject::vfunc_15 (0x0021BA60, 24 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as ActiveWheeledVehicleObject::vfunc_15 (0x0021B8B0), which was matched first;
// its addresses and names were swapped for this function's.
// ActiveBoatObject::vfunc_15 (0x0021BA60, 24 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int __cdecl sub_0007A880(int, int);

class ActiveBoatObject
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
    virtual int vfunc_15(int a1);
    char m_pad04[0x14];
    int m_Field18; // +0x18
};

int ActiveBoatObject::vfunc_15(int a1)
{
    int r_eax;

    r_eax = m_Field18;
    if (r_eax) {
        r_eax = sub_0007A880(r_eax, a1);
    }
    return r_eax;
}

