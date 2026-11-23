// ============================================================================
// SCARFACE: THE WORLD IS YOURS — April 2006 prototype game.xbe, audio/SoundCueAction.cpp (3 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: COMPLETE. All 3 functions are matched.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] SoundCueAction::vfunc_06 (0x000D3F60, 24 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// SoundCueAction::vfunc_06 (Proto 0x000D3F60, 24 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field08
{
    void sub_00297970();
};

class SoundCueAction
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual void vfunc_05();
    virtual bool vfunc_06(int a1);
    char m_pad04[0x4];
    Field08* m_Field08; // +0x08
    int m_Field0C; // +0x0C
};

bool SoundCueAction::vfunc_06(int a1)
{
    if (m_Field0C) {
        if (!m_Field08) goto L_13;
        m_Field08->sub_00297970();
    }
L_13:
    return true;
}

// ============================================================================
// [VERIFIED] SoundCueAction::vfunc_11 (0x000D3F80, 21 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 /arch:SSE
// ============================================================================
// bin: proto
// va: 0x000D3F80
// what: 
// tool: the portal's starter code (no AI)

// SoundCueAction::vfunc_11 (Proto 0x000D3F80, 21 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

class SoundCueAction
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
    virtual bool vfunc_11(float a1);
    char m_pad04[0xC];
    float m_Field10; // +0x10
};

bool SoundCueAction::vfunc_11(float a1)
{
    m_Field10 = a1 + m_Field10;
    return true;
}

// ============================================================================
// [VERIFIED] SoundCueAction::vfunc_03 (0x000D4030, 76 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as SoundPlayAction::vfunc_03 (0x000E6400), which was matched first;
// its addresses and names were swapped for this function's.
// SoundCueAction::vfunc_03 (0x000D4030, 76 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    virtual void vfunc_00();
    virtual void vfunc_01();
};

extern "C" char DAT_00386A54[];
extern "C" void __cdecl sub_00025160(int);

class SoundCueAction
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual SoundCueAction* vfunc_03(int a1);
    void sub_0001F600();
    char m_pad04[0x4];
    int m_Field08; // +0x08
    int m_Field0C; // +0x0C
};

SoundCueAction* SoundCueAction::vfunc_03(int a1)
{
    int t1, t3;

    t1 = m_Field08;
    *(int*)this = (int)DAT_00386A54;
    if (m_Field08) {
        ((Object*)t1)->vfunc_01();
        m_Field08 = 0;
    }
    t3 = m_Field0C;
    if (m_Field0C) {
        ((Object*)t3)->vfunc_01();
        m_Field08 = 0;
    }
    sub_0001F600();
    if (a1 & 1) {
        sub_00025160((int)this);
    }
    return this;
}

