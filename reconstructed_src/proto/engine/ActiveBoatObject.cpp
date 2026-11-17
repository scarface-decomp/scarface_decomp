// ============================================================================
// SCARFACE: THE WORLD IS YOURS — April 2006 prototype game.xbe, engine/ActiveBoatObject.cpp (6 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 6 of 11 functions matched (54.55%). NOT COMPLETE YET.
// The 5 still to do are listed in their place in Original_Binary_Order_Proto.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] ActiveBoatObject::vfunc_10 (0x001D9720, 11 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// ActiveBoatObject::vfunc_10 (Proto 0x001D9720, 11 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_000913C0();
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
    ((Object*)(int)this + 1624)->sub_000913C0();
}

// ============================================================================
// [VERIFIED] ActiveBoatObject::vfunc_03 (0x001D9730, 5 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as PropAttachToObjectBehaviour::vfunc_01 (0x0008FAF0), which was matched first;
// its addresses and names were swapped for this function's.
// ActiveBoatObject::vfunc_03 (0x001D9730, 5 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __cdecl sub_001DDE70(void);

class ActiveBoatObject
{
public:
    virtual void vfunc_00();
    virtual void vfunc_03();
};

void ActiveBoatObject::vfunc_03()
{
    sub_001DDE70();
}

// ============================================================================
// [VERIFIED] ActiveBoatObject::vfunc_09 (0x001D9770, 72 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// ActiveBoatObject::vfunc_09 (Proto 0x001D9770, 72 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field640
{
    void sub_00095040();
};

struct Field768
{
    void sub_00099A60(int, int);
};

struct Object
{
    void sub_00024AB0(int);
    void sub_00024AD0();
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
    void sub_001DF450();
    char m_pad04[0x3C];
    int m_Field40; // +0x40
    char m_pad44[0x4];
    int m_Field48; // +0x48
    char m_pad4C[0x5F4];
    Field640 m_Field640; // +0x640
    char m_pad641[0x127];
    Field768 m_Field768; // +0x768
};

void ActiveBoatObject::vfunc_09()
{
    int local_4;

    ((Object*)(int)(&local_4))->sub_00024AB0(13);
    sub_001DF450();
    m_Field768.sub_00099A60((int)(&m_Field640), (int)(&m_Field48));
    m_Field40 = (int)(&m_Field768);
    m_Field640.sub_00095040();
    ((Object*)(int)(&local_4))->sub_00024AD0();
}

// ============================================================================
// [VERIFIED] ActiveBoatObject::vfunc_11 (0x001D97C0, 11 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// ActiveBoatObject::vfunc_11 (Proto 0x001D97C0, 11 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_00095320();
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
    virtual void vfunc_11();
};

void ActiveBoatObject::vfunc_11()
{
    ((Object*)(int)this + 1600)->sub_00095320();
}

// ============================================================================
// [VERIFIED] ActiveBoatObject::vfunc_20 (0x001D97D0, 31 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// ActiveBoatObject::vfunc_20 (Proto 0x001D97D0, 31 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field640
{
    void sub_00095180(int);
};

extern "C" void __stdcall sub_001DB750(int);

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
    virtual void vfunc_19();
    virtual void vfunc_20(int a1);
    char m_pad04[0x63C];
    Field640 m_Field640; // +0x640
};

void ActiveBoatObject::vfunc_20(int a1)
{
    sub_001DB750(a1);
    m_Field640.sub_00095180(a1);
}

// ============================================================================
// [VERIFIED] ActiveBoatObject::vfunc_00 (0x001D98E0, 60 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// ActiveBoatObject::vfunc_00 (Proto 0x001D98E0, 60 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field640
{
    void sub_00094E50();
};

struct Field768
{
    void sub_00099AB0();
};

extern "C" char DAT_003A96D4[];
extern "C" void __cdecl sub_00025160(int);

class ActiveBoatObject
{
public:
    virtual ActiveBoatObject* vfunc_00(int a1);
    void sub_001DDBF0();
    char m_pad04[0x63C];
    Field640 m_Field640; // +0x640
    char m_pad641[0x127];
    Field768 m_Field768; // +0x768
};

ActiveBoatObject* ActiveBoatObject::vfunc_00(int a1)
{
    *(int*)this = (int)DAT_003A96D4;
    m_Field768.sub_00099AB0();
    m_Field640.sub_00094E50();
    sub_001DDBF0();
    if (a1 & 1) {
        sub_00025160((int)this);
    }
    return this;
}

