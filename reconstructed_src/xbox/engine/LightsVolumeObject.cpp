// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail Xbox default.xbe, engine/LightsVolumeObject.cpp (2 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 2 of 3 functions matched (66.67%). NOT COMPLETE YET.
// The 1 still to do are listed in their place in Original_Binary_Order_Xbox.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] LightsVolumeObject::vfunc_00 (0x0021D450, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// What it does: Returns LightsVolumeObject's static class record (ConcreteClassRep<LightsVolumeObject>), the object's run-time type.
// ============================================================================
// Same machine code as CollisionBehaviourTypeGroup::vfunc_00 (0x000123B0), which was matched first;
// its addresses and names were swapped for this function's.
// LightsVolumeObject::vfunc_00 (0x0021D450, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0044D518[];

class LightsVolumeObject
{
public:
    virtual void* vfunc_00();
};

void* LightsVolumeObject::vfunc_00()
{
    return DAT_0044D518;
}

// ============================================================================
// [VERIFIED] LightsVolumeObject::vfunc_01 (0x0021D630, 89 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// LightsVolumeObject::vfunc_01 (0x0021D630, 89 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_001C5730();
};

extern "C" char DAT_003D0984[];
extern "C" void __cdecl sub_00027600(int);
extern "C" void __cdecl sub_00049900(int);

class LightsVolumeObject
{
public:
    virtual void vfunc_00();
    virtual LightsVolumeObject* vfunc_01(int a1);
    void sub_0002C720();
    char m_pad04[0x8];
    int m_Field0C; // +0x0C
    char m_pad10[0x10];
    int m_Field20; // +0x20
};

LightsVolumeObject* LightsVolumeObject::vfunc_01(int a1)
{
    int t2;

    *(int*)this = (int)DAT_003D0984;
    if (m_Field20) {
        sub_00049900(m_Field0C);
        t2 = m_Field20;
        if (m_Field20) {
            ((Object*)t2)->sub_001C5730();
            sub_00027600(t2);
        }
        m_Field20 = 0;
    }
    sub_0002C720();
    if (a1 & 1) {
        sub_00027600((int)this);
    }
    return this;
}

