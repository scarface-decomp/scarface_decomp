// ============================================================================
// SCARFACE: THE WORLD IS YOURS — April 2006 prototype game.xbe, engine/TutorialPresentationState.cpp (4 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 4 of 8 functions matched (50.00%). NOT COMPLETE YET.
// The 4 still to do are listed in their place in Original_Binary_Order_Proto.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] TutorialPresentationState::vfunc_12 (0x001ED1A0, 67 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// bin: proto
// va: 0x001ED1A0
// what: 
// tool: the portal's starter code (no AI)

// TutorialPresentationState::vfunc_12 (Proto 0x001ED1A0, 67 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0016F030();
};

extern "C" char DAT_003ABBC0[];
extern "C" int DAT_0045E07C;
extern "C" bool DAT_00462F96;
extern "C" bool __cdecl sub_00059BF0(int);
extern "C" void __cdecl sub_00065ED0(int, int, int, int, int);

class TutorialPresentationState
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
    char m_pad04[0x4];
    int m_Field08; // +0x08
};

void TutorialPresentationState::vfunc_12()
{
    if (sub_00059BF0(0)) {
        sub_00065ED0((int)DAT_003ABBC0, 0, 0, 0, -1);
        if (!DAT_00462F96) {
            ((Object*)DAT_0045E07C)->sub_0016F030();
        }
        m_Field08 = 10;
    }
}

// ============================================================================
// [VERIFIED] TutorialPresentationState::vfunc_05 (0x001EE140, 48 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as HUDPresentationState::vfunc_05 (0x0022E2E0), which was matched first;
// its addresses and names were swapped for this function's.
// TutorialPresentationState::vfunc_05 (0x001EE140, 48 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_003ABFE0[];
extern "C" int DAT_00462F98;
extern "C" int __cdecl sub_00065ED0(int, int, int, int, int);

class TutorialPresentationState
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

int TutorialPresentationState::vfunc_05()
{
    int r_eax;

    r_eax = DAT_00462F98;
    if (*(int*)(r_eax + 20) == *(int*)(r_eax + 24)) {
        r_eax = sub_00065ED0((int)DAT_003ABFE0, 0, 0, 0, -1);
        m_Field08 = 3;
    }
    return r_eax;
}

// ============================================================================
// [VERIFIED] TutorialPresentationState::vfunc_07 (0x001EE1E0, 48 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as ExoticsPresentationState::vfunc_07 (0x0022E800), which was matched first;
// its addresses and names were swapped for this function's.
// TutorialPresentationState::vfunc_07 (0x001EE1E0, 48 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_003AC01C[];
extern "C" int DAT_00462F98;
extern "C" int __cdecl sub_00065ED0(int, int, int, int, int);

class TutorialPresentationState
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

int TutorialPresentationState::vfunc_07()
{
    int r_eax;

    r_eax = DAT_00462F98;
    if (*(int*)(r_eax + 20) == *(int*)(r_eax + 24)) {
        r_eax = sub_00065ED0((int)DAT_003AC01C, 0, 0, 0, -1);
        m_Field08 = 5;
    }
    return r_eax;
}

// ============================================================================
// [VERIFIED] TutorialPresentationState::vfunc_08 (0x001EE210, 48 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// TutorialPresentationState::vfunc_08 (Proto 0x001EE210, 48 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_003AC03C[];
extern "C" int DAT_00462F98;
extern "C" int __cdecl sub_00065ED0(int, int, int, int, int);

class TutorialPresentationState
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
    virtual int vfunc_08();
    char m_pad04[0x4];
    int m_Field08; // +0x08
};

int TutorialPresentationState::vfunc_08()
{
    int r_eax;

    r_eax = DAT_00462F98;
    if (*(int*)(r_eax + 20) == *(int*)(r_eax + 24)) {
        r_eax = sub_00065ED0((int)DAT_003AC03C, 0, 0, 0, -1);
        m_Field08 = 6;
    }
    return r_eax;
}

