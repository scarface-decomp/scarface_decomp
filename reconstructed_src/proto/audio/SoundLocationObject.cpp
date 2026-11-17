// ============================================================================
// SCARFACE: THE WORLD IS YOURS — April 2006 prototype game.xbe, audio/SoundLocationObject.cpp (3 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: COMPLETE. All 3 functions are matched.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] SoundLocationObject::vfunc_00 (0x0019FC50, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as CollisionBehaviourTypeGroup::vfunc_00 (0x000123B0), which was matched first;
// its addresses and names were swapped for this function's.
// SoundLocationObject::vfunc_00 (0x0019FC50, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_00414C4C[];

class SoundLocationObject
{
public:
    virtual void* vfunc_00();
};

void* SoundLocationObject::vfunc_00()
{
    return DAT_00414C4C;
}

// ============================================================================
// [VERIFIED] SoundLocationObject::vfunc_05 (0x0019FCC0, 34 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// SoundLocationObject::vfunc_05 (Proto 0x0019FCC0, 34 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field88
{
    void sub_0019FA10();
};

extern "C" void __stdcall sub_00028C40(int);

class SoundLocationObject
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual void vfunc_05(int a1);
    char m_pad04[0x84];
    Field88* m_Field88; // +0x88
    int m_Field8C; // +0x8C
};

void SoundLocationObject::vfunc_05(int a1)
{
    sub_00028C40(a1);
    m_Field8C = (int)m_Field88;
    m_Field88->sub_0019FA10();
}

// ============================================================================
// [VERIFIED] SoundLocationObject::vfunc_01 (0x0019FCF0, 30 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as Collidable::vfunc_03 (0x00011F20), which was matched first;
// its addresses and names were swapped for this function's.
// SoundLocationObject::vfunc_01 (0x0019FCF0, 30 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __cdecl sub_0019FC60(void);
extern "C" void __cdecl sub_00025160(int);

class SoundLocationObject
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual SoundLocationObject* vfunc_01(int a1);
};

SoundLocationObject* SoundLocationObject::vfunc_01(int a1)
{
    sub_0019FC60();
    if (a1 & 1) {
        sub_00025160((int)this);
    }
    return this;
}

