// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail Xbox default.xbe, engine/SpawnTriggerObject.cpp (2 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 2 of 3 functions matched (66.67%). NOT COMPLETE YET.
// The 1 still to do are listed in their place in Original_Binary_Order_Xbox.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] SpawnTriggerObject::vfunc_00 (0x001EA5A0, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// What it does: Returns SpawnTriggerObject's static class record (ConcreteClassRep<SpawnTriggerObject>), the object's run-time type.
// ============================================================================
// Same machine code as CollisionBehaviourTypeGroup::vfunc_00 (0x000123B0), which was matched first;
// its addresses and names were swapped for this function's.
// SpawnTriggerObject::vfunc_00 (0x001EA5A0, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0043DC2C[];

class SpawnTriggerObject
{
public:
    virtual void* vfunc_00();
};

void* SpawnTriggerObject::vfunc_00()
{
    return DAT_0043DC2C;
}

// ============================================================================
// [VERIFIED] SpawnTriggerObject::vfunc_01 (0x001EA740, 70 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as SpawnTriggerObject::vfunc_01 (Proto 0x001B1250), which was matched first;
// its addresses and names were swapped for this function's.
// SpawnTriggerObject::vfunc_01 (Proto 0x001EA740, 70 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_00096D50();
};

extern "C" char DAT_003C8C2C[];
extern "C" void __cdecl sub_00027600(int);
extern "C" void __cdecl sub_000968A0(int);

class SpawnTriggerObject
{
public:
    virtual void vfunc_00();
    virtual SpawnTriggerObject* vfunc_01(int a1);
    void sub_0002C720();
    char m_pad04[0x1C];
    int m_Field20; // +0x20
};

SpawnTriggerObject* SpawnTriggerObject::vfunc_01(int a1)
{
    int t1;

    t1 = m_Field20;
    *(int*)this = (int)DAT_003C8C2C;
    if (m_Field20) {
        ((Object*)t1)->sub_00096D50();
        sub_000968A0(t1);
        m_Field20 = 0;
    }
    sub_0002C720();
    if (a1 & 1) {
        sub_00027600((int)this);
    }
    return this;
}

