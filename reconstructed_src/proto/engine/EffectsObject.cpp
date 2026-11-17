// ============================================================================
// SCARFACE: THE WORLD IS YOURS — April 2006 prototype game.xbe, engine/EffectsObject.cpp (2 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 2 of 4 functions matched (50.00%). NOT COMPLETE YET.
// The 2 still to do are listed in their place in Original_Binary_Order_Proto.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] EffectsObject::vfunc_00 (0x001979C0, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as CollisionBehaviourTypeGroup::vfunc_00 (0x000123B0), which was matched first;
// its addresses and names were swapped for this function's.
// EffectsObject::vfunc_00 (0x001979C0, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_00413BB4[];

class EffectsObject
{
public:
    virtual void* vfunc_00();
};

void* EffectsObject::vfunc_00()
{
    return DAT_00413BB4;
}

// ============================================================================
// [VERIFIED] EffectsObject::vfunc_01 (0x00197BA0, 78 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// EffectsObject::vfunc_01 (Proto 0x00197BA0, 78 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0039FD1C[];
extern "C" void __cdecl sub_00025160(int);
extern "C" void __cdecl sub_00041390(int);

class EffectsObject
{
public:
    virtual void vfunc_00();
    virtual EffectsObject* vfunc_01(int a1);
    void sub_00027AE0();
    char m_pad04[0xA0];
    int m_FieldA4; // +0xA4
    char m_padA8[0x38];
    int m_FieldE0; // +0xE0
};

EffectsObject* EffectsObject::vfunc_01(int a1)
{
    *(int*)this = (int)DAT_0039FD1C;
    sub_00025160(m_FieldA4);
    if (m_FieldE0) {
        sub_00041390((int)(&m_FieldE0));
    }
    sub_00027AE0();
    if (a1 & 1) {
        sub_00025160((int)this);
    }
    return this;
}

