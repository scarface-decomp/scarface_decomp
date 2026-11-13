// ============================================================================
// SCARFACE: THE WORLD IS YOURS — April 2006 prototype game.xbe, engine/ExoticsPresentationState.cpp (2 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 2 of 9 functions matched (22.22%). NOT COMPLETE YET.
// The 7 still to do are listed in their place in Original_Binary_Order_Proto.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] ExoticsPresentationState::vfunc_05 (0x001ED8F0, 48 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as HUDPresentationState::vfunc_05 (0x0022E2E0), which was matched first;
// its addresses and names were swapped for this function's.
// ExoticsPresentationState::vfunc_05 (0x001ED8F0, 48 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_003ABD20[];
extern "C" int DAT_00462F98;
extern "C" int __cdecl sub_00065ED0(int, int, int, int, int);

class ExoticsPresentationState
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual int vfunc_05();
    char m_pad04[0x4];
    int m_Field08; // +0x08
};

int ExoticsPresentationState::vfunc_05()
{
    int r_eax;

    r_eax = DAT_00462F98;
    if (*(int*)(r_eax + 20) == *(int*)(r_eax + 24)) {
        r_eax = sub_00065ED0((int)DAT_003ABD20, 0, 0, 0, -1);
        m_Field08 = 3;
    }
    return r_eax;
}

// ============================================================================
// [VERIFIED] ExoticsPresentationState::vfunc_07 (0x001ED950, 48 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as ExoticsPresentationState::vfunc_07 (0x0022E800), which was matched first;
// its addresses and names were swapped for this function's.
// ExoticsPresentationState::vfunc_07 (0x001ED950, 48 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_003ABD5C[];
extern "C" int DAT_00462F98;
extern "C" int __cdecl sub_00065ED0(int, int, int, int, int);

class ExoticsPresentationState
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual void vfunc_05();
    virtual void vfunc_06();
    virtual int vfunc_07();
    char m_pad04[0x4];
    int m_Field08; // +0x08
};

int ExoticsPresentationState::vfunc_07()
{
    int r_eax;

    r_eax = DAT_00462F98;
    if (*(int*)(r_eax + 20) == *(int*)(r_eax + 24)) {
        r_eax = sub_00065ED0((int)DAT_003ABD5C, 0, 0, 0, -1);
        m_Field08 = 5;
    }
    return r_eax;
}

