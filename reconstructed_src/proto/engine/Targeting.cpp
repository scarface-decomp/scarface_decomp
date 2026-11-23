// ============================================================================
// SCARFACE: THE WORLD IS YOURS — April 2006 prototype game.xbe, engine/Targeting.cpp (3 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 3 of 4 functions matched (75.00%). NOT COMPLETE YET.
// The 1 still to do are listed in their place in Original_Binary_Order_Proto.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] Targeting::vfunc_00 (0x001BB050, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as CollisionBehaviourTypeGroup::vfunc_00 (0x000123B0), which was matched first;
// its addresses and names were swapped for this function's.
// Targeting::vfunc_00 (0x001BB050, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_00418728[];

class Targeting
{
public:
    virtual void* vfunc_00();
};

void* Targeting::vfunc_00()
{
    return DAT_00418728;
}

// ============================================================================
// [VERIFIED] Targeting::vfunc_01 (0x001BB0F0, 36 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as CollisionBehaviourTypeGroup::vfunc_01 (0x00013840), which was matched first;
// its addresses and names were swapped for this function's.
// Targeting::vfunc_01 (0x001BB0F0, 36 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_003A4324[];
extern "C" void __cdecl sub_00025160(int);
extern "C" void __cdecl sub_000277E0(void);

class Targeting
{
public:
    virtual void vfunc_00();
    virtual Targeting* vfunc_01(int a1);
};

Targeting* Targeting::vfunc_01(int a1)
{
    *(int*)this = (int)DAT_003A4324;
    sub_000277E0();
    if (a1 & 1) {
        sub_00025160((int)this);
    }
    return this;
}

// ============================================================================
// [VERIFIED] Targeting::vfunc_10 (0x001BB390, 57 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// bin: proto
// va: 0x001BB390
// what: 
// tool: the portal's starter code (no AI)

// Targeting::vfunc_10 (Proto 0x001BB390, 57 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    int sub_0008D4E0(int);
    void sub_001BF6E0();
};

extern "C" Object DAT_00462DD4;
extern "C" int DAT_00462DD8;
extern "C" int __cdecl sub_001BD8D0(void);

class Targeting
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
    virtual void vfunc_10(int a1);
    char m_pad04[0x145];
    bool m_Field149; // +0x149
    bool m_Field14A; // +0x14A
};

void Targeting::vfunc_10(int a1)
{
    int t3;

    if (DAT_00462DD4.sub_0008D4E0(DAT_00462DD8)) {
        t3 = sub_001BD8D0();
        if (t3) {
            ((Object*)t3)->sub_001BF6E0();
        }
        m_Field149 = true;
        m_Field14A = true;
    }
}

