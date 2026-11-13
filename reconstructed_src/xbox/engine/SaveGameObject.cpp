// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail Xbox default.xbe, engine/SaveGameObject.cpp (3 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 3 of 5 functions matched (60.00%). NOT COMPLETE YET.
// The 2 still to do are listed in their place in Original_Binary_Order_Xbox.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] SaveGameObject::vfunc_00 (0x000C6FA0, 65 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// SaveGameObject::vfunc_00 (0x000C6FA0, 65 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field0C
{
    void sub_000999A0();
};

struct Object
{
    void sub_00026EC0(int);
    void sub_00026EE0();
};

extern "C" int DAT_004245D4;
extern "C" void __cdecl sub_00027600(int);

class SaveGameObject
{
public:
    virtual void vfunc_00();
    char m_pad04[0x8];
    Field0C m_Field0C; // +0x0C
    char m_pad0D[0xF];
    int m_Field1C; // +0x1C
};

void SaveGameObject::vfunc_00()
{
    int local_4;

    if (m_Field1C) {
        ((Object*)(int)(&local_4))->sub_00026EC0(DAT_004245D4);
        sub_00027600(m_Field1C);
        m_Field1C = 0;
        ((Object*)(int)(&local_4))->sub_00026EE0();
    }
    m_Field0C.sub_000999A0();
}

// ============================================================================
// [VERIFIED] SaveGameObject::vfunc_00 (0x000C7B10, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as CollisionBehaviourTypeGroup::vfunc_00 (0x000123B0), which was matched first;
// its addresses and names were swapped for this function's.
// SaveGameObject::vfunc_00 (0x000C7B10, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_00424808[];

class SaveGameObject
{
public:
    virtual void* vfunc_00();
};

void* SaveGameObject::vfunc_00()
{
    return DAT_00424808;
}

// ============================================================================
// [VERIFIED] SaveGameObject::vfunc_01 (0x000C8630, 30 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as Collidable::vfunc_03 (0x00011F20), which was matched first;
// its addresses and names were swapped for this function's.
// SaveGameObject::vfunc_01 (0x000C8630, 30 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __cdecl sub_000C7B20(void);
extern "C" void __cdecl sub_00027600(int);

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
    sub_000C7B20();
    if (a1 & 1) {
        sub_00027600((int)this);
    }
    return this;
}

