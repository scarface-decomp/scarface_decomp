// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail Xbox default.xbe, engine/GameLoadingManager.cpp (2 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 2 of 4 functions matched (50.00%). NOT COMPLETE YET.
// The 2 still to do are listed in their place in Original_Binary_Order_Xbox.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] GameLoadingManager::vfunc_00 (0x0022B340, 46 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// GameLoadingManager::vfunc_00 (0x0022B340, 46 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_003D2028[];
extern "C" int DAT_00491F98;
extern "C" void __cdecl sub_00027600(int);
extern "C" void __cdecl sub_000EA330(void);

class GameLoadingManager
{
public:
    virtual GameLoadingManager* vfunc_00(int a1);
};

GameLoadingManager* GameLoadingManager::vfunc_00(int a1)
{
    *(int*)this = (int)DAT_003D2028;
    DAT_00491F98 = -0x22222223;
    sub_000EA330();
    if (a1 & 1) {
        sub_00027600((int)this);
    }
    return this;
}

// ============================================================================
// [VERIFIED] GameLoadingManager::vfunc_01 (0x0022B370, 91 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// GameLoadingManager::vfunc_01 (0x0022B370, 91 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_0044DF90;
extern "C" bool DAT_00492006;
extern "C" void __cdecl sub_0004A480(int, int);
extern "C" void __cdecl sub_001D6380(void);
extern "C" void __cdecl sub_0022B0F0(void);

class GameLoadingManager
{
public:
    virtual void vfunc_00();
    virtual int vfunc_01(int a1, int a2);
    int m_Field04; // +0x04
};

int GameLoadingManager::vfunc_01(int a1, int a2)
{
    int r_eax;

    r_eax = m_Field04;
    if (!r_eax) {
        sub_0004A480(1, 1);
        sub_001D6380();
        m_Field04 += 1;
    }
    if (m_Field04 == 1) {
        sub_0022B0F0();
        m_Field04 += 1;
    }
    r_eax = 2;
    if (m_Field04 == 2) {
        if (DAT_00492006) {
            if (DAT_0044DF90 == -1) goto L_57;
        }
        m_Field04 = 0;
        r_eax = 1;
    }
L_57:
    return r_eax;
}

