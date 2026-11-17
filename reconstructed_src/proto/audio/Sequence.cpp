// ============================================================================
// SCARFACE: THE WORLD IS YOURS — April 2006 prototype game.xbe, audio/Sequence.cpp (3 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 3 of 7 functions matched (42.86%). NOT COMPLETE YET.
// The 4 still to do are listed in their place in Original_Binary_Order_Proto.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] audio::Sequence::vfunc_14 (0x00294030, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as core::MemoryAllocatorMalloc::vfunc_12 (0x0028D100), which was matched first;
// its addresses and names were swapped for this function's.
// audio::Sequence::vfunc_14 (0x00294030, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_0044AE9C;

namespace audio {

class Sequence
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
    virtual int vfunc_14();
};

int Sequence::vfunc_14()
{
    return DAT_0044AE9C;
}

}

// ============================================================================
// [VERIFIED] audio::Sequence::vfunc_07 (0x002943D0, 43 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// audio::Sequence::vfunc_07 (Proto 0x002943D0, 43 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field38
{
    void sub_00296E70();
};

struct Field4C
{
    void sub_00294290();
};

struct Field54
{
    void sub_002942E0();
};

namespace audio {

class Sequence
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual void vfunc_05();
    virtual void vfunc_06();
    virtual void vfunc_07(int a1);
    virtual void vfunc_08(int);
    char m_pad04[0x34];
    Field38 m_Field38; // +0x38
    char m_pad39[0x13];
    Field4C m_Field4C; // +0x4C
    char m_pad4D[0x7];
    Field54 m_Field54; // +0x54
};

void Sequence::vfunc_07(int a1)
{
    m_Field38.sub_00296E70();
    m_Field4C.sub_00294290();
    m_Field54.sub_002942E0();
    vfunc_08(a1);
}

}

// ============================================================================
// [VERIFIED] audio::Sequence::vfunc_09 (0x002947D0, 64 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// audio::Sequence::vfunc_09 (Proto 0x002947D0, 64 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" bool __cdecl sub_0029B950(int, int);

namespace audio {

class Sequence
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
    bool sub_00294100(int);
    bool sub_00294680(int);
};

int Sequence::vfunc_09(int a1)
{
    if (sub_0029B950(a1, 1)) {
        if (!sub_00294680(a1)) goto L_39;
        if (!sub_00294100(a1)) goto L_39;
        return 1;
    }
L_39:
    return 0;
}

}

