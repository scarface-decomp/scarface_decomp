// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail Xbox default.xbe, fe/InvSelectionHUD.cpp (2 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 2 of 9 functions matched (22.22%). NOT COMPLETE YET.
// The 7 still to do are listed in their place in Original_Binary_Order_Xbox.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] InvSelectionHUD::vfunc_00 (0x001A5030, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as CollisionBehaviourTypeGroup::vfunc_00 (0x000123B0), which was matched first;
// its addresses and names were swapped for this function's.
// InvSelectionHUD::vfunc_00 (0x001A5030, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0043768C[];

class InvSelectionHUD
{
public:
    virtual void* vfunc_00();
};

void* InvSelectionHUD::vfunc_00()
{
    return DAT_0043768C;
}

// ============================================================================
// [VERIFIED] InvSelectionHUD::vfunc_01 (0x001A5560, 81 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// InvSelectionHUD::vfunc_01 (0x001A5560, 81 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    virtual void vfunc_00(int);
};

extern "C" char DAT_003BE2B8[];
extern "C" char DAT_003BE2D4[];
extern "C" int DAT_0048C894;
extern "C" void __cdecl sub_00027600(int);

class InvSelectionHUD
{
public:
    virtual void vfunc_00();
    virtual InvSelectionHUD* vfunc_01(int a1);
    void sub_00193F80();
    char m_pad04[0x60];
    int m_Field64; // +0x64
    char m_pad68[0x160];
    int m_Field1C8; // +0x1C8
};

InvSelectionHUD* InvSelectionHUD::vfunc_01(int a1)
{
    int t1;

    t1 = m_Field1C8;
    *(int*)this = (int)DAT_003BE2D4;
    m_Field64 = (int)DAT_003BE2B8;
    if (m_Field1C8) {
        ((Object*)t1)->vfunc_00(1);
        m_Field1C8 = 0;
    }
    DAT_0048C894 = 0;
    sub_00193F80();
    if (a1 & 1) {
        sub_00027600((int)this);
    }
    return this;
}

