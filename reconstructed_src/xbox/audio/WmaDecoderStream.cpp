// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail Xbox default.xbe, audio/WmaDecoderStream.cpp (4 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 4 of 12 functions matched (33.33%). NOT COMPLETE YET.
// The 8 still to do are listed in their place in Original_Binary_Order_Xbox.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] audio::WmaDecoderStream::vfunc_02 (0x002D80D0, 4 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// audio::WmaDecoderStream::vfunc_02 (0x002D80D0, 4 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

namespace audio {

class WmaDecoderStream
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void* vfunc_02();
    char m_pad04[0x5C];
    int m_Field60; // +0x60
};

void* WmaDecoderStream::vfunc_02()
{
    return &m_Field60;
}

}

// ============================================================================
// [VERIFIED] audio::WmaDecoderStream::vfunc_03 (0x002D80E0, 21 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// audio::WmaDecoderStream::vfunc_03 (0x002D80E0, 21 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

namespace audio {

class WmaDecoderStream
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual int vfunc_03();
    char m_pad04[0x5C];
    int m_Field60; // +0x60
};

int WmaDecoderStream::vfunc_03()
{
    return ((((unsigned int)m_Field60) >> 4) & 31) * ((((unsigned int)m_Field60) >> 29) & 3);
}

}

// ============================================================================
// [VERIFIED] audio::WmaDecoderStream::vfunc_04 (0x002D8100, 7 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// audio::WmaDecoderStream::vfunc_04 (0x002D8100, 7 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

namespace audio {

class WmaDecoderStream
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual int vfunc_04();
    char m_pad04[0x60];
    int m_Field64; // +0x64
    char m_pad68[0x4];
    int m_Field6C; // +0x6C
};

int WmaDecoderStream::vfunc_04()
{
    return m_Field64 - m_Field6C;
}

}

// ============================================================================
// [VERIFIED] audio::WmaDecoderStream::vfunc_10 (0x002D8160, 8 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// audio::WmaDecoderStream::vfunc_10 (0x002D8160, 8 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field5C
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

class WmaDecoderStream
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
    char m_pad04[0x58];
    Field5C* m_Field5C; // +0x5C
};

void WmaDecoderStream::vfunc_10()
{
    m_Field5C->vfunc_10();
}

}

