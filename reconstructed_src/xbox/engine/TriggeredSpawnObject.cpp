// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail Xbox default.xbe, engine/TriggeredSpawnObject.cpp (3 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 3 of 5 functions matched (60.00%). NOT COMPLETE YET.
// The 2 still to do are listed in their place in Original_Binary_Order_Xbox.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] TriggeredSpawnObject::vfunc_00 (0x001EA800, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as CollisionBehaviourTypeGroup::vfunc_00 (0x000123B0), which was matched first;
// its addresses and names were swapped for this function's.
// TriggeredSpawnObject::vfunc_00 (0x001EA800, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0043DA1C[];

class TriggeredSpawnObject
{
public:
    virtual void* vfunc_00();
};

void* TriggeredSpawnObject::vfunc_00()
{
    return DAT_0043DA1C;
}

// ============================================================================
// [VERIFIED] TriggeredSpawnObject::vfunc_51 (0x001EA810, 9 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// What it does: Reads flag bit 0 of the byte at +0x1F4.
// ============================================================================
// bin: xb
// va: 0x001EA810
// what: Reads flag bit 0 of the byte at +0x1F4.
// tool: Claude Opus 5.5 (generated from the shape 'read one flag bit', checked on decomp.me preset 266 by example)
class Class_001EA810
{
public:
    bool sub_001EA810();
    char m_pad00[0x1F4];
    unsigned char m_Flag0 : 1;
};

bool Class_001EA810::sub_001EA810()
{
    return m_Flag0;
}

// ============================================================================
// [VERIFIED] TriggeredSpawnObject::vfunc_01 (0x001EA8B0, 36 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as CollisionBehaviourTypeGroup::vfunc_01 (0x00013840), which was matched first;
// its addresses and names were swapped for this function's.
// TriggeredSpawnObject::vfunc_01 (0x001EA8B0, 36 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_003C8CBC[];
extern "C" void __cdecl sub_00027600(int);
extern "C" void __cdecl sub_001E2B80(void);

class TriggeredSpawnObject
{
public:
    virtual void vfunc_00();
    virtual TriggeredSpawnObject* vfunc_01(int a1);
};

TriggeredSpawnObject* TriggeredSpawnObject::vfunc_01(int a1)
{
    *(int*)this = (int)DAT_003C8CBC;
    sub_001E2B80();
    if (a1 & 1) {
        sub_00027600((int)this);
    }
    return this;
}

