// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail PC Scarface.exe v1.00.2, audio/SeqActionChannelSendVolumes.cpp (5 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 5 of 7 functions matched (71.43%). NOT COMPLETE YET.
// The 2 still to do are listed in their place in Original_Binary_Order_PC_1002.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] audio::SeqActionChannelSendVolumes::vfunc_02 (0x006F57E0, 16 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G7 /Gd /GR /EHsc /Zp4
// ============================================================================
// bin: pc
// va: 0x006F57E0
// what: 
// tool: the portal's starter code (no AI)

// audio::SeqActionChannelSendVolumes::vfunc_02 (PC 0x006F57E0, 16 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

namespace audio {

class SeqActionChannelSendVolumes
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual int vfunc_02(int a1, int a2);
    char m_pad04[0x8];
    int m_Field0C; // +0x0C
};

int SeqActionChannelSendVolumes::vfunc_02(int a1, int a2)
{
    if (m_Field0C != 1) {
        m_Field0C = 1;
    }
    return 1;
}

}

// ============================================================================
// [VERIFIED] audio::SeqActionChannelSendVolumes::vfunc_01 (0x006F57F0, 32 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G7 /Gd /GR /EHsc /Zp4
// ============================================================================
// bin: pc
// va: 0x006F57F0
// what: 
// tool: the portal's starter code (no AI)

// audio::SeqActionChannelSendVolumes::vfunc_01 (PC 0x006F57F0, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

namespace audio {

class SeqActionChannelSendVolumes
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01(int a1);
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual void vfunc_05();
    virtual void vfunc_06(int);
    char m_pad04[0x8];
    int m_Field0C; // +0x0C
};

void SeqActionChannelSendVolumes::vfunc_01(int a1)
{
    vfunc_06(a1);
    if (m_Field0C) {
        m_Field0C = 0;
    }
}

}

// ============================================================================
// [VERIFIED] audio::SeqActionChannelSendVolumes::vfunc_03 (0x006F5810, 16 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G7 /Gd /GR /EHsc /Zp4
// ============================================================================
// bin: pc
// va: 0x006F5810
// what: 
// tool: the portal's starter code (no AI)

// audio::SeqActionChannelSendVolumes::vfunc_03 (PC 0x006F5810, 16 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

namespace audio {

class SeqActionChannelSendVolumes
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual int vfunc_03(int a1);
    char m_pad04[0x8];
    int m_Field0C; // +0x0C
};

int SeqActionChannelSendVolumes::vfunc_03(int a1)
{
    if (m_Field0C != 4) {
        m_Field0C = 4;
    }
    return 4;
}

}

// ============================================================================
// [VERIFIED] audio::SeqActionChannelSendVolumes::vfunc_04 (0x006F5820, 16 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G7 /Gd /GR /EHsc /Zp4
// ============================================================================
// bin: pc
// va: 0x006F5820
// what: 
// tool: the portal's starter code (no AI)

// audio::SeqActionChannelSendVolumes::vfunc_04 (PC 0x006F5820, 16 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

namespace audio {

class SeqActionChannelSendVolumes
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual int vfunc_04(int a1);
    char m_pad04[0x8];
    int m_Field0C; // +0x0C
};

int SeqActionChannelSendVolumes::vfunc_04(int a1)
{
    if (m_Field0C != 5) {
        m_Field0C = 5;
    }
    return 5;
}

}

// ============================================================================
// [VERIFIED] audio::SeqActionChannelSendVolumes::vfunc_00 (0x006F6B30, 36 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as SoundManager::SoundPlayerHandle::vfunc_00 (0x00077F00), which was matched first;
// its addresses and names were swapped for this function's.
// audio::SeqActionChannelSendVolumes::vfunc_00 (0x006F6B30, 36 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_00772F80[];
extern "C" char DAT_007F7144[];
extern "C" void __cdecl sub_006EE890(int, int);

namespace audio {

class SeqActionChannelSendVolumes
{
public:
    virtual SeqActionChannelSendVolumes* vfunc_00(int a1);
};

SeqActionChannelSendVolumes* SeqActionChannelSendVolumes::vfunc_00(int a1)
{
    *(int*)this = (int)DAT_00772F80;
    if (a1 & 1) {
        sub_006EE890((int)DAT_007F7144, (int)this);
    }
    return this;
}

}

