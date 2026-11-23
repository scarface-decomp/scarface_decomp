// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail Xbox default.xbe, engine/GroundObject.cpp (3 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 3 of 5 functions matched (60.00%). NOT COMPLETE YET.
// The 2 still to do are listed in their place in Original_Binary_Order_Xbox.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] GroundObject::vfunc_00 (0x00189340, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// What it does: Returns GroundObject's static class record (ConcreteClassRep<GroundObject>), the object's run-time type.
// ============================================================================
// Same machine code as CollisionBehaviourTypeGroup::vfunc_00 (0x000123B0), which was matched first;
// its addresses and names were swapped for this function's.
// GroundObject::vfunc_00 (0x00189340, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_00434074[];

class GroundObject
{
public:
    virtual void* vfunc_00();
};

void* GroundObject::vfunc_00()
{
    return DAT_00434074;
}

// ============================================================================
// [VERIFIED] GroundObject::vfunc_39 (0x00189350, 5 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as SoundEntityLoader::vfunc_04 (0x00064FA0), which was matched first;
// its addresses and names were swapped for this function's.
// GroundObject::vfunc_39 (0x00189350, 5 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __cdecl sub_0002A7C0(void);

class GroundObject
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_39();
};

void GroundObject::vfunc_39()
{
    sub_0002A7C0();
}

// ============================================================================
// [VERIFIED] GroundObject::vfunc_01 (0x00189470, 78 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// GroundObject::vfunc_01 (0x00189470, 78 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_003B8BDC[];
extern "C" void __cdecl sub_00027600(int);
extern "C" void __cdecl sub_00048680(int);

class GroundObject
{
public:
    virtual void vfunc_00();
    virtual GroundObject* vfunc_01(int a1);
    void sub_0002A770();
    void sub_001893C0();
    char m_pad04[0xA4];
    int m_FieldA8; // +0xA8
};

GroundObject* GroundObject::vfunc_01(int a1)
{
    *(int*)this = (int)DAT_003B8BDC;
    if (m_FieldA8) {
        sub_00048680((int)(&m_FieldA8));
        m_FieldA8 = 0;
    }
    sub_001893C0();
    sub_0002A770();
    if (a1 & 1) {
        sub_00027600((int)this);
    }
    return this;
}

