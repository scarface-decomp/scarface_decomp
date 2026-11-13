// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail Xbox default.xbe, audio/SeqActionChannelSendVolumes.cpp (4 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 4 of 7 functions matched (57.14%). NOT COMPLETE YET.
// The 3 still to do are listed in their place in Original_Binary_Order_Xbox.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] audio::SeqActionChannelSendVolumes::vfunc_02 (0x002D6AA0, 18 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// audio::SeqActionChannelSendVolumes::vfunc_02 (0x002D6AA0, 18 bytes)
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
// [VERIFIED] audio::SeqActionChannelSendVolumes::vfunc_03 (0x002D6AF0, 18 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// audio::SeqActionChannelSendVolumes::vfunc_03 (0x002D6AF0, 18 bytes)
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
// [VERIFIED] audio::SeqActionChannelSendVolumes::vfunc_04 (0x002D6B10, 18 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// audio::SeqActionChannelSendVolumes::vfunc_04 (0x002D6B10, 18 bytes)
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
// [VERIFIED] audio::SeqActionChannelSendVolumes::vfunc_00 (0x002D8F50, 36 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as SoundManager::SoundPlayerHandle::vfunc_00 (0x00077F00), which was matched first;
// its addresses and names were swapped for this function's.
// audio::SeqActionChannelSendVolumes::vfunc_00 (0x002D8F50, 36 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_003E07F4[];
extern "C" char DAT_00463EBC[];
extern "C" void __cdecl sub_002CF980(int, int);

namespace audio {

class SeqActionChannelSendVolumes
{
public:
    virtual SeqActionChannelSendVolumes* vfunc_00(int a1);
};

SeqActionChannelSendVolumes* SeqActionChannelSendVolumes::vfunc_00(int a1)
{
    *(int*)this = (int)DAT_003E07F4;
    if (a1 & 1) {
        sub_002CF980((int)DAT_00463EBC, (int)this);
    }
    return this;
}

}

