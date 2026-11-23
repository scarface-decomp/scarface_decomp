// ============================================================================
// SCARFACE: THE WORLD IS YOURS — April 2006 prototype game.xbe, engine/FireTemplate.cpp (3 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 3 of 4 functions matched (75.00%). NOT COMPLETE YET.
// The 1 still to do are listed in their place in Original_Binary_Order_Proto.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] FireTemplate::vfunc_00 (0x00166790, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as CollisionBehaviourTypeGroup::vfunc_00 (0x000123B0), which was matched first;
// its addresses and names were swapped for this function's.
// FireTemplate::vfunc_00 (0x00166790, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0040EFDC[];

class FireTemplate
{
public:
    virtual void* vfunc_00();
};

void* FireTemplate::vfunc_00()
{
    return DAT_0040EFDC;
}

// ============================================================================
// [VERIFIED] FireTemplate::vfunc_12 (0x001667C0, 24 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// bin: proto
// va: 0x001667C0
// what: 
// tool: the portal's starter code (no AI)

// FireTemplate::vfunc_12 (Proto 0x001667C0, 24 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field24
{
    void sub_000B79B0();
};

class FireTemplate
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual void vfunc_05();
    virtual void vfunc_06();
    virtual void vfunc_07();
    virtual void vfunc_08();
    virtual void vfunc_09();
    virtual void vfunc_10();
    virtual void vfunc_11();
    virtual void vfunc_12();
    char m_pad04[0x1E];
    bool m_Field22; // +0x22
    char m_pad23[0x1];
    Field24 m_Field24; // +0x24
};

void FireTemplate::vfunc_12()
{
    if (m_Field22) {
        m_Field24.sub_000B79B0();
        m_Field22 = false;
    }
}

// ============================================================================
// [VERIFIED] FireTemplate::vfunc_01 (0x001667E0, 52 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as FireTemplate::vfunc_01 (0x00188930), which was matched first;
// its addresses and names were swapped for this function's.
// FireTemplate::vfunc_01 (0x001667E0, 52 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field24
{
    void sub_000B7A20();
};

extern "C" char DAT_0037F29C[];
extern "C" char DAT_0039627C[];
extern "C" void __cdecl sub_00025160(int);

class FireTemplate
{
public:
    virtual void vfunc_00();
    virtual FireTemplate* vfunc_01(int a1);
    void sub_00029C00();
    char m_pad04[0x20];
    Field24 m_Field24; // +0x24
};

FireTemplate* FireTemplate::vfunc_01(int a1)
{
    *(int*)this = (int)DAT_0039627C;
    m_Field24.sub_000B7A20();
    *(int*)this = (int)DAT_0037F29C;
    sub_00029C00();
    if (a1 & 1) {
        sub_00025160((int)this);
    }
    return this;
}

