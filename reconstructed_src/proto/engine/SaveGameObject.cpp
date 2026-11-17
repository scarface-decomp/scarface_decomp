// ============================================================================
// SCARFACE: THE WORLD IS YOURS — April 2006 prototype game.xbe, engine/SaveGameObject.cpp (4 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 4 of 6 functions matched (66.67%). NOT COMPLETE YET.
// The 2 still to do are listed in their place in Original_Binary_Order_Proto.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] SaveGameObject::vfunc_00 (0x000B92E0, 61 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// SaveGameObject::vfunc_00 (Proto 0x000B92E0, 61 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field08
{
    void sub_00031F20();
};

struct Object
{
    void sub_00024AB0(int);
    void sub_00024AD0();
};

extern "C" void __cdecl sub_00025160(int);

class SaveGameObject
{
public:
    virtual void vfunc_00();
    char m_pad04[0x4];
    Field08 m_Field08; // +0x08
    char m_pad09[0xF];
    int m_Field18; // +0x18
};

void SaveGameObject::vfunc_00()
{
    int local_4;

    if (m_Field18) {
        ((Object*)(int)(&local_4))->sub_00024AB0(1);
        sub_00025160(m_Field18);
        m_Field18 = 0;
        ((Object*)(int)(&local_4))->sub_00024AD0();
    }
    m_Field08.sub_00031F20();
}

// ============================================================================
// [VERIFIED] SaveGameObject::vfunc_03 (0x000B9320, 4 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// SaveGameObject::vfunc_03 (Proto 0x000B9320, 4 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

class SaveGameObject
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual int vfunc_03();
    char m_pad04[0x20];
    int m_Field24; // +0x24
};

int SaveGameObject::vfunc_03()
{
    return m_Field24;
}

// ============================================================================
// [VERIFIED] SaveGameObject::vfunc_00 (0x000B9990, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as CollisionBehaviourTypeGroup::vfunc_00 (0x000123B0), which was matched first;
// its addresses and names were swapped for this function's.
// SaveGameObject::vfunc_00 (0x000B9990, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_003FF52C[];

class SaveGameObject
{
public:
    virtual void* vfunc_00();
};

void* SaveGameObject::vfunc_00()
{
    return DAT_003FF52C;
}

// ============================================================================
// [VERIFIED] SaveGameObject::vfunc_01 (0x000BA240, 30 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as Collidable::vfunc_03 (0x00011F20), which was matched first;
// its addresses and names were swapped for this function's.
// SaveGameObject::vfunc_01 (0x000BA240, 30 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __cdecl sub_000B99A0(void);
extern "C" void __cdecl sub_00025160(int);

class SaveGameObject
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual SaveGameObject* vfunc_01(int a1);
};

SaveGameObject* SaveGameObject::vfunc_01(int a1)
{
    sub_000B99A0();
    if (a1 & 1) {
        sub_00025160((int)this);
    }
    return this;
}

