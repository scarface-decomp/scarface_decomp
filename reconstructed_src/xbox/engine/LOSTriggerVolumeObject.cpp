// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail Xbox default.xbe, engine/LOSTriggerVolumeObject.cpp (3 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: COMPLETE. All 3 functions are matched.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] LOSTriggerVolumeObject::vfunc_00 (0x00213250, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as CollisionBehaviourTypeGroup::vfunc_00 (0x000123B0), which was matched first;
// its addresses and names were swapped for this function's.
// LOSTriggerVolumeObject::vfunc_00 (0x00213250, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0044C094[];

class LOSTriggerVolumeObject
{
public:
    virtual void* vfunc_00();
};

void* LOSTriggerVolumeObject::vfunc_00()
{
    return DAT_0044C094;
}

// ============================================================================
// [VERIFIED] LOSTriggerVolumeObject::vfunc_04 (0x00213260, 29 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// LOSTriggerVolumeObject::vfunc_04 (0x00213260, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct FieldA0
{
    void sub_0006BD80(int);
};

extern "C" void __stdcall sub_00212FB0(int);

class LOSTriggerVolumeObject
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04(int a1);
    char m_pad04[0x70];
    int m_Field74; // +0x74
    char m_pad78[0x28];
    FieldA0 m_FieldA0; // +0xA0
};

void LOSTriggerVolumeObject::vfunc_04(int a1)
{
    sub_00212FB0(0);
    m_FieldA0.sub_0006BD80(m_Field74);
}

// ============================================================================
// [VERIFIED] LOSTriggerVolumeObject::vfunc_01 (0x00213410, 30 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as Collidable::vfunc_03 (0x00011F20), which was matched first;
// its addresses and names were swapped for this function's.
// LOSTriggerVolumeObject::vfunc_01 (0x00213410, 30 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __cdecl sub_002131E0(void);
extern "C" void __cdecl sub_00027600(int);

class LOSTriggerVolumeObject
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual LOSTriggerVolumeObject* vfunc_01(int a1);
};

LOSTriggerVolumeObject* LOSTriggerVolumeObject::vfunc_01(int a1)
{
    sub_002131E0();
    if (a1 & 1) {
        sub_00027600((int)this);
    }
    return this;
}

