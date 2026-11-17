// ============================================================================
// SCARFACE: THE WORLD IS YOURS — April 2006 prototype game.xbe, fe/GameOverHUD.cpp (4 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 4 of 12 functions matched (33.33%). NOT COMPLETE YET.
// The 8 still to do are listed in their place in Original_Binary_Order_Proto.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] GameOverHUD::vfunc_00 (0x0016A980, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as CollisionBehaviourTypeGroup::vfunc_00 (0x000123B0), which was matched first;
// its addresses and names were swapped for this function's.
// GameOverHUD::vfunc_00 (0x0016A980, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_004100F8[];

class GameOverHUD
{
public:
    virtual void* vfunc_00();
};

void* GameOverHUD::vfunc_00()
{
    return DAT_004100F8;
}

// ============================================================================
// [VERIFIED] GameOverHUD::vfunc_00 (0x0016AA20, 51 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// GameOverHUD::vfunc_00 (Proto 0x0016AA20, 51 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0016E3C0(int, int);
};

class GameOverHUD
{
public:
    virtual void vfunc_00(int a1, int a2);
    char m_pad04[0x45];
    bool m_Field49; // +0x49
};

void GameOverHUD::vfunc_00(int a1, int a2)
{
    if (a1 == 137) {
        m_Field49 = *(int*)(a2 + 8) == 1;
        a2 = 1;
        a1 = 1;
        ((Object*)(int)this + -64)->sub_0016E3C0(a1, a2);
        return;
    }
}

// ============================================================================
// [VERIFIED] GameOverHUD::vfunc_01 (0x0016AD70, 65 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// GameOverHUD::vfunc_01 (Proto 0x0016AD70, 65 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    virtual void vfunc_00(int);
};

extern "C" char DAT_00397340[];
extern "C" char DAT_0039734C[];
extern "C" void __cdecl sub_00025160(int);

class GameOverHUD
{
public:
    virtual void vfunc_00();
    virtual GameOverHUD* vfunc_01(int a1);
    void sub_0016E130();
    char m_pad04[0x3C];
    int m_Field40; // +0x40
    char m_pad44[0x28];
    int m_Field6C; // +0x6C
};

GameOverHUD* GameOverHUD::vfunc_01(int a1)
{
    int t1;

    t1 = m_Field6C;
    *(int*)this = (int)DAT_0039734C;
    m_Field40 = (int)DAT_00397340;
    if (m_Field6C) {
        ((Object*)t1)->vfunc_00(1);
        m_Field6C = 0;
    }
    sub_0016E130();
    if (a1 & 1) {
        sub_00025160((int)this);
    }
    return this;
}

// ============================================================================
// [VERIFIED] GameOverHUD::vfunc_41 (0x00178DA0, 5 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as SoundEntityLoader::vfunc_04 (0x00064FA0), which was matched first;
// its addresses and names were swapped for this function's.
// GameOverHUD::vfunc_41 (0x00178DA0, 5 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __cdecl sub_0016E450(void);

class GameOverHUD
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_41();
};

void GameOverHUD::vfunc_41()
{
    sub_0016E450();
}

