// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail Xbox default.xbe, engine/CharacterTunablesObject.cpp (2 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: COMPLETE. All 2 functions are matched.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] CharacterTunablesObject::vfunc_00 (0x001FAF00, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as CollisionBehaviourTypeGroup::vfunc_00 (0x000123B0), which was matched first;
// its addresses and names were swapped for this function's.
// CharacterTunablesObject::vfunc_00 (0x001FAF00, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0043FAD8[];

class CharacterTunablesObject
{
public:
    virtual void* vfunc_00();
};

void* CharacterTunablesObject::vfunc_00()
{
    return DAT_0043FAD8;
}

// ============================================================================
// [VERIFIED] CharacterTunablesObject::vfunc_01 (0x001FB260, 46 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as SoundPlayTrack::vfunc_03 (0x000E9E90), which was matched first;
// its addresses and names were swapped for this function's.
// CharacterTunablesObject::vfunc_01 (0x001FB260, 46 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field20
{
    void sub_002A9290();
};

extern "C" char DAT_003CAA2C[];
extern "C" void __cdecl sub_00027600(int);

class CharacterTunablesObject
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual CharacterTunablesObject* vfunc_01(int a1);
    void sub_0002C720();
    char m_pad04[0x1C];
    Field20 m_Field20; // +0x20
};

CharacterTunablesObject* CharacterTunablesObject::vfunc_01(int a1)
{
    *(int*)this = (int)DAT_003CAA2C;
    m_Field20.sub_002A9290();
    sub_0002C720();
    if (a1 & 1) {
        sub_00027600((int)this);
    }
    return this;
}

