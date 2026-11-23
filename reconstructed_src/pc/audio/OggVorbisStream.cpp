// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail PC Scarface.exe v1.00.2, audio/OggVorbisStream.cpp (9 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 9 of 12 functions matched (75.00%). NOT COMPLETE YET.
// The 3 still to do are listed in their place in Original_Binary_Order_PC_1002.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] audio::OggVorbisStream::vfunc_00 (0x006F4D00, 40 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// bin: pc
// va: 0x006F4D00
// what: 
// tool: the portal's starter code (no AI)

// audio::OggVorbisStream::vfunc_00 (PC 0x006F4D00, 40 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field04
{
    virtual void vfunc_00();
    virtual int vfunc_01();
};

namespace audio {

class OggVorbisStream
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
    Field04* m_Field04; // +0x04
    char m_pad08[0x2E4];
    int m_Field2EC; // +0x2EC
};

void OggVorbisStream::vfunc_00()
{
    if (!m_Field04->vfunc_01()) {
        m_Field04->vfunc_00();
    }
    m_Field2EC = 1;
    vfunc_11();
}

}

// ============================================================================
// [VERIFIED] audio::OggVorbisStream::vfunc_12 (0x006F4D30, 12 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as audio::HalRadicalAdpcmDecodeStream::vfunc_12 (0x002E0A30), which was matched first;
// its addresses and names were swapped for this function's.
// audio::OggVorbisStream::vfunc_12 (0x006F4D30, 12 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

namespace audio {

class OggVorbisStream
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
    virtual void vfunc_13();
    virtual void vfunc_14();
    virtual void vfunc_15();
    virtual void vfunc_16();
    virtual void vfunc_17(int);
};

void OggVorbisStream::vfunc_12()
{
    if (this) {
        vfunc_17(1);
    }
}

}

// ============================================================================
// [VERIFIED] audio::OggVorbisStream::vfunc_01 (0x006F4D80, 7 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// What it does: Returns the number stored at +0x2EC in the audio stream.
// ============================================================================
// bin: pc
// va: 0x006F4D80
// what: Returns the number stored at +0x2EC in the audio stream.
// tool: Claude Opus 5.5 (transplanted from pc:0x006E1CF0, nearest by portal/tools/similar.py)
// audio::OggVorbisStream::vfunc_01
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.


namespace audio {
class OggVorbisStream
{
public:
    virtual void vfunc_00();
    virtual int vfunc_01();
    char m_pad04[0x2E8];
    int m_Field2EC; // +0x2EC
};

int OggVorbisStream::vfunc_01()
{
    return m_Field2EC;
}
}

// ============================================================================
// [VERIFIED] audio::OggVorbisStream::vfunc_02 (0x006F4D90, 7 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// What it does: Returns the address of the block at +0x2DC inside the audio stream.
// ============================================================================
// bin: pc
// va: 0x006F4D90
// what: Returns the address of the block at +0x2DC inside the audio stream.
// tool: Claude Opus 5.5 (transplanted from pc:0x006E4260, nearest by portal/tools/similar.py)
// audio::OggVorbisStream::vfunc_02
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.


namespace audio {
class OggVorbisStream
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void* vfunc_02();
    char m_pad04[0x2D8];
    int m_Field2DC; // +0x2DC
};

void* OggVorbisStream::vfunc_02()
{
    return &m_Field2DC;
}
}

// ============================================================================
// [VERIFIED] audio::OggVorbisStream::vfunc_03 (0x006F4DA0, 15 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G7 /Gd /GR /EHsc /Zp4
// ============================================================================
// bin: pc
// va: 0x006F4DA0
// what: 
// tool: the portal's starter code (no AI)

// audio::OggVorbisStream::vfunc_03 (PC 0x006F4DA0, 15 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

namespace audio {

class OggVorbisStream
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual int vfunc_03();
    char m_pad04[0x2D8];
    int m_Field2DC; // +0x2DC
};

int OggVorbisStream::vfunc_03()
{
    return ((((unsigned int)m_Field2DC) >> 4) & 31) + ((((unsigned int)m_Field2DC) >> 4) & 31);
}

}

// ============================================================================
// [VERIFIED] audio::OggVorbisStream::vfunc_10 (0x006F4DC0, 8 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as audio::HalRadicalAdpcmDecodeStream::vfunc_10 (Proto 0x002AD200), which was matched first;
// its addresses and names were swapped for this function's.
// audio::OggVorbisStream::vfunc_10 (Proto 0x006F4DC0, 8 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field04
{
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
};

namespace audio {

class OggVorbisStream
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
    Field04* m_Field04; // +0x04
};

void OggVorbisStream::vfunc_10()
{
    m_Field04->vfunc_10();
}

}

// ============================================================================
// [VERIFIED] audio::OggVorbisStream::vfunc_04 (0x006F4DD0, 13 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// bin: pc
// va: 0x006F4DD0
// what: 
// tool: the portal's starter code (no AI)

// audio::OggVorbisStream::vfunc_04 (PC 0x006F4DD0, 13 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

namespace audio {

class OggVorbisStream
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual int vfunc_04();
    char m_pad04[0x2DC];
    int m_Field2E0; // +0x2E0
    int m_Field2E4; // +0x2E4
};

int OggVorbisStream::vfunc_04()
{
    return m_Field2E0 - m_Field2E4;
}

}

// ============================================================================
// [VERIFIED] audio::OggVorbisStream::vfunc_08 (0x006F4E60, 27 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// bin: pc
// va: 0x006F4E60
// what: 
// tool: the portal's starter code (no AI)

// audio::OggVorbisStream::vfunc_08 (PC 0x006F4E60, 27 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

namespace audio {

class OggVorbisStream
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
    virtual bool vfunc_08(int a1);
    char m_pad04[0x2E4];
    int m_Field2E8; // +0x2E8
};

bool OggVorbisStream::vfunc_08(int a1)
{
    *(int*)a1 = m_Field2E8;
    m_Field2E8 = 0;
    return true;
}

}

// ============================================================================
// [VERIFIED] audio::OggVorbisStream::vfunc_17 (0x006F4F60, 95 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G7 /Gd /GR /EHsc /Zp4
// ============================================================================
// bin: pc
// va: 0x006F4F60
// what: 
// tool: the portal's starter code (no AI)

// audio::OggVorbisStream::vfunc_17 (PC 0x006F4F60, 95 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
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
};

extern "C" char DAT_00772B5C[];
extern "C" char DAT_007F6D80[];
extern "C" void __cdecl sub_0043CE70(int);
extern "C" void __cdecl sub_006EE890(int, int);
extern "C" void __cdecl sub_00702724(int);

namespace audio {

class OggVorbisStream
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
    virtual void vfunc_13();
    virtual void vfunc_14();
    virtual void vfunc_15();
    virtual void vfunc_16();
    virtual OggVorbisStream* vfunc_17(int a1);
    int m_Field04; // +0x04
    int m_Field08; // +0x08
    char m_pad0C[0x2CC];
    int m_Field2D8; // +0x2D8
    char m_pad2DC[0x14];
    int m_Field2F0; // +0x2F0
};

OggVorbisStream* OggVorbisStream::vfunc_17(int a1)
{
    int t1;

    t1 = m_Field04;
    *(int*)this = (int)DAT_00772B5C;
    ((Object*)t1)->vfunc_12();
    sub_0043CE70(m_Field2F0);
    if (m_Field2D8) {
        sub_00702724((int)(&m_Field08));
    }
    sub_0043CE70(m_Field2D8);
    if (a1 & 1) {
        sub_006EE890((int)DAT_007F6D80, (int)this);
    }
    return this;
}

}

