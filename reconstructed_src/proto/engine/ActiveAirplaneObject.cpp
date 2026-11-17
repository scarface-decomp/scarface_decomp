// ============================================================================
// SCARFACE: THE WORLD IS YOURS — April 2006 prototype game.xbe, engine/ActiveAirplaneObject.cpp (6 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 6 of 15 functions matched (40.00%). NOT COMPLETE YET.
// The 9 still to do are listed in their place in Original_Binary_Order_Proto.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] ActiveAirplaneObject::vfunc_10 (0x001D8160, 11 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// ActiveAirplaneObject::vfunc_10 (Proto 0x001D8160, 11 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_00091360();
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
    ((Object*)(int)this + 1624)->sub_00091360();
}

// ============================================================================
// [VERIFIED] ActiveAirplaneObject::vfunc_03 (0x001D8170, 17 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// ActiveAirplaneObject::vfunc_03 (Proto 0x001D8170, 17 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __cdecl sub_001DDE70(void);

class ActiveAirplaneObject
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    char m_pad04[0x6D8];
    bool m_Field6DC; // +0x6DC
};

void ActiveAirplaneObject::vfunc_03()
{
    sub_001DDE70();
    m_Field6DC = false;
}

// ============================================================================
// [VERIFIED] ActiveAirplaneObject::vfunc_09 (0x001D81C0, 63 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// ActiveAirplaneObject::vfunc_09 (Proto 0x001D81C0, 63 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field6C0
{
    void sub_00099AE0(int, int);
};

struct Object
{
    void sub_00024AB0(int);
    void sub_00024AD0();
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
    void sub_001DF450();
    char m_pad04[0x3C];
    int m_Field40; // +0x40
    char m_pad44[0x4];
    int m_Field48; // +0x48
    char m_pad4C[0x5F4];
    int m_Field640; // +0x640
    char m_pad644[0x7C];
    Field6C0 m_Field6C0; // +0x6C0
};

void ActiveAirplaneObject::vfunc_09()
{
    int local_4;

    ((Object*)(int)(&local_4))->sub_00024AB0(13);
    sub_001DF450();
    m_Field6C0.sub_00099AE0((int)(&m_Field640), (int)(&m_Field48));
    m_Field40 = (int)(&m_Field6C0);
    ((Object*)(int)(&local_4))->sub_00024AD0();
}

// ============================================================================
// [VERIFIED] ActiveAirplaneObject::vfunc_00 (0x001D82B0, 60 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// ActiveAirplaneObject::vfunc_00 (Proto 0x001D82B0, 60 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field640
{
    void sub_0008F8C0();
};

struct Field6C0
{
    void sub_00099AB0();
};

extern "C" char DAT_003A9374[];
extern "C" void __cdecl sub_00025160(int);

class ActiveAirplaneObject
{
public:
    virtual ActiveAirplaneObject* vfunc_00(int a1);
    void sub_001DDBF0();
    char m_pad04[0x63C];
    Field640 m_Field640; // +0x640
    char m_pad641[0x7F];
    Field6C0 m_Field6C0; // +0x6C0
};

ActiveAirplaneObject* ActiveAirplaneObject::vfunc_00(int a1)
{
    *(int*)this = (int)DAT_003A9374;
    m_Field6C0.sub_00099AB0();
    m_Field640.sub_0008F8C0();
    sub_001DDBF0();
    if (a1 & 1) {
        sub_00025160((int)this);
    }
    return this;
}

// ============================================================================
// [VERIFIED] ActiveAirplaneObject::vfunc_01 (0x001D83B0, 38 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// ActiveAirplaneObject::vfunc_01 (Proto 0x001D83B0, 38 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field640
{
    void sub_0008FB50(int);
};

extern "C" void __stdcall sub_001DF0F0(int);

class ActiveAirplaneObject
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01(int a1);
    void sub_001D82F0();
    char m_pad04[0x63C];
    Field640 m_Field640; // +0x640
};

void ActiveAirplaneObject::vfunc_01(int a1)
{
    sub_001DF0F0(a1);
    m_Field640.sub_0008FB50(a1);
    sub_001D82F0();
}

// ============================================================================
// [VERIFIED] ActiveAirplaneObject::vfunc_08 (0x001D9990, 61 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// ActiveAirplaneObject::vfunc_08 (Proto 0x001D9990, 61 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field640
{
    void sub_000A4C10(int);
};

extern "C" int __cdecl sub_00028120(int);
extern "C" void __cdecl sub_001DB710(void);

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
    char m_pad04[0x638];
    int m_Field63C; // +0x63C
    Field640 m_Field640; // +0x640
};

void ActiveAirplaneObject::vfunc_08()
{
    sub_001DB710();
    if (sub_00028120(m_Field63C)) {
        m_Field640.sub_000A4C10(sub_00028120(m_Field63C) + 224);
    }
}

