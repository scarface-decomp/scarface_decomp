// ============================================================================
// SCARFACE: THE WORLD IS YOURS — April 2006 prototype game.xbe, engine/ActiveHelicopterObject.cpp (6 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 6 of 13 functions matched (46.15%). NOT COMPLETE YET.
// The 7 still to do are listed in their place in Original_Binary_Order_Proto.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] ActiveHelicopterObject::vfunc_10 (0x001D9F60, 11 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// ActiveHelicopterObject::vfunc_10 (Proto 0x001D9F60, 11 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_000AA7F0();
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
    ((Object*)(int)this + 1608)->sub_000AA7F0();
}

// ============================================================================
// [VERIFIED] ActiveHelicopterObject::vfunc_03 (0x001D9F70, 17 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// ActiveHelicopterObject::vfunc_03 (Proto 0x001D9F70, 17 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __cdecl sub_001DDE70(void);

class ActiveHelicopterObject
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    char m_pad04[0x6C4];
    bool m_Field6C8; // +0x6C8
};

void ActiveHelicopterObject::vfunc_03()
{
    sub_001DDE70();
    m_Field6C8 = false;
}

// ============================================================================
// [VERIFIED] ActiveHelicopterObject::vfunc_01 (0x001D9F90, 31 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// ActiveHelicopterObject::vfunc_01 (Proto 0x001D9F90, 31 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field640
{
    void sub_00098D70(int);
};

extern "C" void __stdcall sub_001DF0F0(int);

class ActiveHelicopterObject
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01(int a1);
    char m_pad04[0x63C];
    Field640 m_Field640; // +0x640
};

void ActiveHelicopterObject::vfunc_01(int a1)
{
    sub_001DF0F0(a1);
    m_Field640.sub_00098D70(a1);
}

// ============================================================================
// [VERIFIED] ActiveHelicopterObject::vfunc_09 (0x001D9FE0, 72 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// ActiveHelicopterObject::vfunc_09 (Proto 0x001D9FE0, 72 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field640
{
    void sub_00098D90();
};

struct Field6B8
{
    void sub_00099AE0(int, int);
};

struct Object
{
    void sub_00024AB0(int);
    void sub_00024AD0();
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
    void sub_001DF450();
    char m_pad04[0x3C];
    int m_Field40; // +0x40
    char m_pad44[0x4];
    int m_Field48; // +0x48
    char m_pad4C[0x5F4];
    Field640 m_Field640; // +0x640
    char m_pad641[0x77];
    Field6B8 m_Field6B8; // +0x6B8
};

void ActiveHelicopterObject::vfunc_09()
{
    int local_4;

    ((Object*)(int)(&local_4))->sub_00024AB0(13);
    sub_001DF450();
    m_Field6B8.sub_00099AE0((int)(&m_Field640), (int)(&m_Field48));
    m_Field40 = (int)(&m_Field6B8);
    m_Field640.sub_00098D90();
    ((Object*)(int)(&local_4))->sub_00024AD0();
}

// ============================================================================
// [VERIFIED] ActiveHelicopterObject::vfunc_11 (0x001DA030, 11 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// ActiveHelicopterObject::vfunc_11 (Proto 0x001DA030, 11 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_00098E00();
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
    virtual void vfunc_11();
};

void ActiveHelicopterObject::vfunc_11()
{
    ((Object*)(int)this + 1600)->sub_00098E00();
}

// ============================================================================
// [VERIFIED] ActiveHelicopterObject::vfunc_00 (0x001DA0F0, 60 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// ActiveHelicopterObject::vfunc_00 (Proto 0x001DA0F0, 60 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field640
{
    void sub_00098D30();
};

struct Field6B8
{
    void sub_00099AB0();
};

extern "C" char DAT_003A983C[];
extern "C" void __cdecl sub_00025160(int);

class ActiveHelicopterObject
{
public:
    virtual ActiveHelicopterObject* vfunc_00(int a1);
    void sub_001DDBF0();
    char m_pad04[0x63C];
    Field640 m_Field640; // +0x640
    char m_pad641[0x77];
    Field6B8 m_Field6B8; // +0x6B8
};

ActiveHelicopterObject* ActiveHelicopterObject::vfunc_00(int a1)
{
    *(int*)this = (int)DAT_003A983C;
    m_Field6B8.sub_00099AB0();
    m_Field640.sub_00098D30();
    sub_001DDBF0();
    if (a1 & 1) {
        sub_00025160((int)this);
    }
    return this;
}

