// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail Xbox default.xbe, engine/AirplaneArtTemplate.cpp (4 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 4 of 5 functions matched (80.00%). NOT COMPLETE YET.
// The 1 still to do are listed in their place in Original_Binary_Order_Xbox.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] AirplaneArtTemplate::vfunc_00 (0x00200340, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as CollisionBehaviourTypeGroup::vfunc_00 (0x000123B0), which was matched first;
// its addresses and names were swapped for this function's.
// AirplaneArtTemplate::vfunc_00 (0x00200340, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_00441A00[];

class AirplaneArtTemplate
{
public:
    virtual void* vfunc_00();
};

void* AirplaneArtTemplate::vfunc_00()
{
    return DAT_00441A00;
}

// ============================================================================
// [VERIFIED] AirplaneArtTemplate::vfunc_01 (0x00200350, 36 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as CollisionBehaviourTypeGroup::vfunc_01 (0x00013840), which was matched first;
// its addresses and names were swapped for this function's.
// AirplaneArtTemplate::vfunc_01 (0x00200350, 36 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_003CB8FC[];
extern "C" void __cdecl sub_00027600(int);
extern "C" void __cdecl sub_0020C530(void);

class AirplaneArtTemplate
{
public:
    virtual void vfunc_00();
    virtual AirplaneArtTemplate* vfunc_01(int a1);
};

AirplaneArtTemplate* AirplaneArtTemplate::vfunc_01(int a1)
{
    *(int*)this = (int)DAT_003CB8FC;
    sub_0020C530();
    if (a1 & 1) {
        sub_00027600((int)this);
    }
    return this;
}

// ============================================================================
// [VERIFIED] AirplaneArtTemplate::vfunc_10 (0x00200450, 16 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as LoadPackage::vfunc_06 (0x001C63F0), which was matched first;
// its addresses and names were swapped for this function's.
// AirplaneArtTemplate::vfunc_10 (0x00200450, 16 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __cdecl sub_0020CA50(void);

class AirplaneArtTemplate
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual void vfunc_05();
    virtual void vfunc_10();
    void sub_00200380();
};

void AirplaneArtTemplate::vfunc_10()
{
    sub_0020CA50();
    sub_00200380();
}

// ============================================================================
// [VERIFIED] AirplaneArtTemplate::vfunc_11 (0x0020CA60, 14 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as CharacterFightTreeTemplate::vfunc_11 (0x001FB1F0), which was matched first;
// its addresses and names were swapped for this function's.
// AirplaneArtTemplate::vfunc_11 (0x0020CA60, 14 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __cdecl sub_0020C680(void);

class AirplaneArtTemplate
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
    char m_pad04[0x1E];
    bool m_Field22; // +0x22
};

void AirplaneArtTemplate::vfunc_11()
{
    sub_0020C680();
    m_Field22 = false;
}

