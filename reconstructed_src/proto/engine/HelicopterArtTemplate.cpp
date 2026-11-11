// ============================================================================
// SCARFACE: THE WORLD IS YOURS — April 2006 prototype game.xbe, engine/HelicopterArtTemplate.cpp (3 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 3 of 4 functions matched (75.00%). NOT COMPLETE YET.
// The 1 still to do are listed in their place in Original_Binary_Order_Proto.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] HelicopterArtTemplate::vfunc_00 (0x001C6160, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as CollisionBehaviourTypeGroup::vfunc_00 (0x000123B0), which was matched first;
// its addresses and names were swapped for this function's.
// HelicopterArtTemplate::vfunc_00 (0x001C6160, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0041D608[];

class HelicopterArtTemplate
{
public:
    virtual void* vfunc_00();
};

void* HelicopterArtTemplate::vfunc_00()
{
    return DAT_0041D608;
}

// ============================================================================
// [VERIFIED] HelicopterArtTemplate::vfunc_05 (0x001C6170, 5 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as SoundEntityLoader::vfunc_04 (0x00064FA0), which was matched first;
// its addresses and names were swapped for this function's.
// HelicopterArtTemplate::vfunc_05 (0x001C6170, 5 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __cdecl sub_001D1320(void);

class HelicopterArtTemplate
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_05();
};

void HelicopterArtTemplate::vfunc_05()
{
    sub_001D1320();
}

// ============================================================================
// [VERIFIED] HelicopterArtTemplate::vfunc_01 (0x001C6180, 36 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as CollisionBehaviourTypeGroup::vfunc_01 (0x00013840), which was matched first;
// its addresses and names were swapped for this function's.
// HelicopterArtTemplate::vfunc_01 (0x001C6180, 36 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_003A5D84[];
extern "C" void __cdecl sub_00025160(int);
extern "C" void __cdecl sub_001D1010(void);

class HelicopterArtTemplate
{
public:
    virtual void vfunc_00();
    virtual HelicopterArtTemplate* vfunc_01(int a1);
};

HelicopterArtTemplate* HelicopterArtTemplate::vfunc_01(int a1)
{
    *(int*)this = (int)DAT_003A5D84;
    sub_001D1010();
    if (a1 & 1) {
        sub_00025160((int)this);
    }
    return this;
}

