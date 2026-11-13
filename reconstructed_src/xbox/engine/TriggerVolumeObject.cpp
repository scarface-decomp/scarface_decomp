// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail Xbox default.xbe, engine/TriggerVolumeObject.cpp (2 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 2 of 3 functions matched (66.67%). NOT COMPLETE YET.
// The 1 still to do are listed in their place in Original_Binary_Order_Xbox.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] TriggerVolumeObject::vfunc_00 (0x00212E70, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as CollisionBehaviourTypeGroup::vfunc_00 (0x000123B0), which was matched first;
// its addresses and names were swapped for this function's.
// TriggerVolumeObject::vfunc_00 (0x00212E70, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0044C068[];

class TriggerVolumeObject
{
public:
    virtual void* vfunc_00();
};

void* TriggerVolumeObject::vfunc_00()
{
    return DAT_0044C068;
}

// ============================================================================
// [VERIFIED] TriggerVolumeObject::vfunc_01 (0x00212F40, 61 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// TriggerVolumeObject::vfunc_01 (0x00212F40, 61 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_003CF60C[];
extern "C" void __cdecl sub_00027600(int);
extern "C" void __cdecl sub_00097090(int);

class TriggerVolumeObject
{
public:
    virtual void vfunc_00();
    virtual TriggerVolumeObject* vfunc_01(int a1);
    void sub_00029F90();
    char m_pad04[0x70];
    int m_Field74; // +0x74
};

TriggerVolumeObject* TriggerVolumeObject::vfunc_01(int a1)
{
    int t1;

    t1 = m_Field74;
    *(int*)this = (int)DAT_003CF60C;
    if (m_Field74) {
        sub_00097090(t1);
        m_Field74 = 0;
    }
    sub_00029F90();
    if (a1 & 1) {
        sub_00027600((int)this);
    }
    return this;
}

