// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail Xbox default.xbe, engine/StatePropTemplate.cpp (2 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: COMPLETE. All 2 functions are matched.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] StatePropTemplate::vfunc_00 (0x002120E0, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as CollisionBehaviourTypeGroup::vfunc_00 (0x000123B0), which was matched first;
// its addresses and names were swapped for this function's.
// StatePropTemplate::vfunc_00 (0x002120E0, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0044BA6C[];

class StatePropTemplate
{
public:
    virtual void* vfunc_00();
};

void* StatePropTemplate::vfunc_00()
{
    return DAT_0044BA6C;
}

// ============================================================================
// [VERIFIED] StatePropTemplate::vfunc_01 (0x00212380, 52 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as FireTemplate::vfunc_01 (0x00188930), which was matched first;
// its addresses and names were swapped for this function's.
// StatePropTemplate::vfunc_01 (0x00212380, 52 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field24
{
    void sub_00087CB0();
};

extern "C" char DAT_0039FE34[];
extern "C" char DAT_003CF28C[];
extern "C" void __cdecl sub_00027600(int);

class StatePropTemplate
{
public:
    virtual void vfunc_00();
    virtual StatePropTemplate* vfunc_01(int a1);
    void sub_0002C720();
    char m_pad04[0x20];
    Field24 m_Field24; // +0x24
};

StatePropTemplate* StatePropTemplate::vfunc_01(int a1)
{
    *(int*)this = (int)DAT_003CF28C;
    m_Field24.sub_00087CB0();
    *(int*)this = (int)DAT_0039FE34;
    sub_0002C720();
    if (a1 & 1) {
        sub_00027600((int)this);
    }
    return this;
}

