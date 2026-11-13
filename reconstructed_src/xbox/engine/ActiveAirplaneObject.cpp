// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail Xbox default.xbe, engine/ActiveAirplaneObject.cpp (6 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 6 of 15 functions matched (40.00%). NOT COMPLETE YET.
// The 9 still to do are listed in their place in Original_Binary_Order_Xbox.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] ActiveAirplaneObject::vfunc_10 (0x00213440, 11 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// ActiveAirplaneObject::vfunc_10 (0x00213440, 11 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0009CA80();
};

class ActiveAirplaneObject
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

void ActiveAirplaneObject::vfunc_10()
{
    ((Object*)(int)this + 1656)->sub_0009CA80();
}

// ============================================================================
// [VERIFIED] ActiveAirplaneObject::vfunc_03 (0x00213450, 17 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// ActiveAirplaneObject::vfunc_03 (0x00213450, 17 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __cdecl sub_00219B10(void);

class ActiveAirplaneObject
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    char m_pad04[0x6F8];
    bool m_Field6FC; // +0x6FC
};

void ActiveAirplaneObject::vfunc_03()
{
    sub_00219B10();
    m_Field6FC = false;
}

// ============================================================================
// [VERIFIED] ActiveAirplaneObject::vfunc_09 (0x002134A0, 63 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// ActiveAirplaneObject::vfunc_09 (0x002134A0, 63 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field6E0
{
    void sub_000A5930(int, int);
};

struct Object
{
    void sub_00026EC0(int);
    void sub_00026EE0();
};

class ActiveAirplaneObject
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
    int m_Field660; // +0x660
    char m_pad664[0x7C];
    Field6E0 m_Field6E0; // +0x6E0
};

void ActiveAirplaneObject::vfunc_09()
{
    int local_4;

    ((Object*)(int)(&local_4))->sub_00026EC0(13);
    sub_0021AA40();
    m_Field6E0.sub_000A5930((int)(&m_Field660), (int)(&m_Field48));
    m_Field40 = (int)(&m_Field6E0);
    ((Object*)(int)(&local_4))->sub_00026EE0();
}

// ============================================================================
// [VERIFIED] ActiveAirplaneObject::vfunc_00 (0x002135F0, 60 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// ActiveAirplaneObject::vfunc_00 (0x002135F0, 60 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field660
{
    void sub_0009B090();
};

struct Field6E0
{
    void sub_000A5890();
};

extern "C" char DAT_003CF75C[];
extern "C" void __cdecl sub_00027600(int);

class ActiveAirplaneObject
{
public:
    virtual ActiveAirplaneObject* vfunc_00(int a1);
    void sub_002198B0();
    char m_pad04[0x65C];
    Field660 m_Field660; // +0x660
    char m_pad661[0x7F];
    Field6E0 m_Field6E0; // +0x6E0
};

ActiveAirplaneObject* ActiveAirplaneObject::vfunc_00(int a1)
{
    *(int*)this = (int)DAT_003CF75C;
    m_Field6E0.sub_000A5890();
    m_Field660.sub_0009B090();
    sub_002198B0();
    if (a1 & 1) {
        sub_00027600((int)this);
    }
    return this;
}

// ============================================================================
// [VERIFIED] ActiveAirplaneObject::vfunc_01 (0x002136F0, 38 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// ActiveAirplaneObject::vfunc_01 (0x002136F0, 38 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field660
{
    void sub_0009B2A0(int);
};

extern "C" void __stdcall sub_0021B3F0(int);

class ActiveAirplaneObject
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01(int a1);
    void sub_00213630();
    char m_pad04[0x65C];
    Field660 m_Field660; // +0x660
};

void ActiveAirplaneObject::vfunc_01(int a1)
{
    sub_0021B3F0(a1);
    m_Field660.sub_0009B2A0(a1);
    sub_00213630();
}

// ============================================================================
// [VERIFIED] ActiveAirplaneObject::vfunc_08 (0x00214DB0, 61 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// ActiveAirplaneObject::vfunc_08 (0x00214DB0, 61 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field660
{
    void sub_00240C70(int);
};

extern "C" int __cdecl sub_0002AC90(int);
extern "C" void __cdecl sub_002171F0(void);

class ActiveAirplaneObject
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
    char m_pad04[0x658];
    int m_Field65C; // +0x65C
    Field660 m_Field660; // +0x660
};

void ActiveAirplaneObject::vfunc_08()
{
    sub_002171F0();
    if (sub_0002AC90(m_Field65C)) {
        m_Field660.sub_00240C70(sub_0002AC90(m_Field65C) + 236);
    }
}

