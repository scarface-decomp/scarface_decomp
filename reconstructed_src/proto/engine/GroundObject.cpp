// ============================================================================
// SCARFACE: THE WORLD IS YOURS — April 2006 prototype game.xbe, engine/GroundObject.cpp (3 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 3 of 5 functions matched (60.00%). NOT COMPLETE YET.
// The 2 still to do are listed in their place in Original_Binary_Order_Proto.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] GroundObject::vfunc_00 (0x00167030, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as CollisionBehaviourTypeGroup::vfunc_00 (0x000123B0), which was matched first;
// its addresses and names were swapped for this function's.
// GroundObject::vfunc_00 (0x00167030, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0040F0A0[];

class GroundObject
{
public:
    virtual void* vfunc_00();
};

void* GroundObject::vfunc_00()
{
    return DAT_0040F0A0;
}

// ============================================================================
// [VERIFIED] GroundObject::vfunc_35 (0x00167040, 5 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as SoundEntityLoader::vfunc_04 (0x00064FA0), which was matched first;
// its addresses and names were swapped for this function's.
// GroundObject::vfunc_35 (0x00167040, 5 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __cdecl sub_00027D50(void);

class GroundObject
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_35();
};

void GroundObject::vfunc_35()
{
    sub_00027D50();
}

// ============================================================================
// [VERIFIED] GroundObject::vfunc_01 (0x00167160, 78 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// GroundObject::vfunc_01 (Proto 0x00167160, 78 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0039644C[];
extern "C" void __cdecl sub_00025160(int);
extern "C" void __cdecl sub_00041390(int);

class GroundObject
{
public:
    virtual void vfunc_00();
    virtual GroundObject* vfunc_01(int a1);
    void sub_00027D00();
    void sub_001670B0();
    char m_pad04[0x9C];
    int m_FieldA0; // +0xA0
};

GroundObject* GroundObject::vfunc_01(int a1)
{
    *(int*)this = (int)DAT_0039644C;
    if (m_FieldA0) {
        sub_00041390((int)(&m_FieldA0));
        m_FieldA0 = 0;
    }
    sub_001670B0();
    sub_00027D00();
    if (a1 & 1) {
        sub_00025160((int)this);
    }
    return this;
}

