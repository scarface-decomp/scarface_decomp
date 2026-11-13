// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail PC Scarface.exe v1.00.2, audio/OmHalStream.cpp (4 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 4 of 8 functions matched (50.00%). NOT COMPLETE YET.
// The 4 still to do are listed in their place in Original_Binary_Order_PC_1002.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] audio::OmHalStream::vfunc_10 (0x006EBDF0, 11 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as audio::OmHalStream::vfunc_10 (0x002D5910), which was matched first;
// its addresses and names were swapped for this function's.
// audio::OmHalStream::vfunc_10 (0x006EBDF0, 11 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_006EB6D0();
};

namespace audio {

class OmHalStream
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
};

void OmHalStream::vfunc_10()
{
    ((Object*)(int)this + 448)->sub_006EB6D0();
}

}

// ============================================================================
// [VERIFIED] audio::OmHalStream::vfunc_08 (0x006EBFA0, 36 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as audio::OmHalStream::vfunc_08 (0x002D5B00), which was matched first;
// its addresses and names were swapped for this function's.
// audio::OmHalStream::vfunc_08 (0x006EBFA0, 36 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

namespace audio {

class OmHalStream
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
    char m_pad04[0x4];
    int m_Field08; // +0x08
    char m_pad0C[0x1AC];
    int m_Field1B8; // +0x1B8
};

bool OmHalStream::vfunc_08(int a1)
{
    *(int*)a1 = m_Field1B8;
    m_Field08 -= m_Field1B8;
    m_Field1B8 = 0;
    return true;
}

}

// ============================================================================
// [VERIFIED] audio::OmHalStream::vfunc_09 (0x006EBFD0, 17 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as audio::OmHalStream::vfunc_09 (0x002D5B30), which was matched first;
// its addresses and names were swapped for this function's.
// audio::OmHalStream::vfunc_09 (0x006EBFD0, 17 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

namespace audio {

class OmHalStream
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
    virtual int vfunc_09(int a1);
};

int OmHalStream::vfunc_09(int a1)
{
    return (a1 << 4) + (int)this + 184;
}

}

// ============================================================================
// [VERIFIED] audio::OmHalStream::vfunc_12 (0x006EC5F0, 40 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as audio::OmHalStream::vfunc_12 (0x002D6170), which was matched first;
// its addresses and names were swapped for this function's.
// audio::OmHalStream::vfunc_12 (0x006EC5F0, 40 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field1C0
{
    void sub_006EBBD0();
};

extern "C" char DAT_007724CC[];
extern "C" char DAT_007F646C[];
extern "C" void __cdecl sub_006EE890(int, int);

namespace audio {

class OmHalStream
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
    char m_pad04[0x1BC];
    Field1C0 m_Field1C0; // +0x1C0
};

void OmHalStream::vfunc_12()
{
    if (this) {
        *(int*)this = (int)DAT_007724CC;
        m_Field1C0.sub_006EBBD0();
        sub_006EE890((int)DAT_007F646C, (int)this);
    }
}

}

