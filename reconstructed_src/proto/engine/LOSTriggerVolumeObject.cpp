// ============================================================================
// SCARFACE: THE WORLD IS YOURS — April 2006 prototype game.xbe, engine/LOSTriggerVolumeObject.cpp (3 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: COMPLETE. All 3 functions are matched.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] LOSTriggerVolumeObject::vfunc_00 (0x001D7F80, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as CollisionBehaviourTypeGroup::vfunc_00 (0x000123B0), which was matched first;
// its addresses and names were swapped for this function's.
// LOSTriggerVolumeObject::vfunc_00 (0x001D7F80, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_00425A8C[];

class LOSTriggerVolumeObject
{
public:
    virtual void* vfunc_00();
};

void* LOSTriggerVolumeObject::vfunc_00()
{
    return DAT_00425A8C;
}

// ============================================================================
// [VERIFIED] LOSTriggerVolumeObject::vfunc_05 (0x001D7F90, 29 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// LOSTriggerVolumeObject::vfunc_05 (Proto 0x001D7F90, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct FieldA4
{
    void sub_000D0C00(int);
};

extern "C" void __stdcall sub_001D7CE0(int);

class LOSTriggerVolumeObject
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual void vfunc_05(int a1);
    char m_pad04[0x74];
    int m_Field78; // +0x78
    char m_pad7C[0x28];
    FieldA4 m_FieldA4; // +0xA4
};

void LOSTriggerVolumeObject::vfunc_05(int a1)
{
    sub_001D7CE0(0);
    m_FieldA4.sub_000D0C00(m_Field78);
}

// ============================================================================
// [VERIFIED] LOSTriggerVolumeObject::vfunc_01 (0x001D8140, 30 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as Collidable::vfunc_03 (0x00011F20), which was matched first;
// its addresses and names were swapped for this function's.
// LOSTriggerVolumeObject::vfunc_01 (0x001D8140, 30 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __cdecl sub_001D7F10(void);
extern "C" void __cdecl sub_00025160(int);

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
    sub_001D7F10();
    if (a1 & 1) {
        sub_00025160((int)this);
    }
    return this;
}

