// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail Xbox default.xbe, audio/Sequence.cpp (3 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 3 of 5 functions matched (60.00%). NOT COMPLETE YET.
// The 2 still to do are listed in their place in Original_Binary_Order_Xbox.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] audio::Sequence::vfunc_12 (0x002CFB30, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as core::MemoryAllocatorMalloc::vfunc_12 (0x0028D100), which was matched first;
// its addresses and names were swapped for this function's.
// audio::Sequence::vfunc_12 (0x002CFB30, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_00476364;

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
    virtual int vfunc_12();
};

int Sequence::vfunc_12()
{
    return DAT_00476364;
}

}

// ============================================================================
// [VERIFIED] audio::Sequence::vfunc_05 (0x002CFC80, 32 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// audio::Sequence::vfunc_05 (0x002CFC80, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field44
{
    void sub_002CFBD0();
};

extern "C" void __cdecl sub_002CFC40(void);

namespace audio {

class Sequence
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual void vfunc_05(int a1);
    virtual void vfunc_06(int);
    char m_pad04[0x40];
    Field44 m_Field44; // +0x44
};

void Sequence::vfunc_05(int a1)
{
    sub_002CFC40();
    m_Field44.sub_002CFBD0();
    vfunc_06(a1);
}

}

// ============================================================================
// [VERIFIED] audio::Sequence::vfunc_07 (0x002CFF00, 64 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as audio::Sequence::vfunc_09 (Proto 0x002947D0), which was matched first;
// its addresses and names were swapped for this function's.
// audio::Sequence::vfunc_07 (Proto 0x002CFF00, 64 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" bool __cdecl sub_002D6340(int, int);

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
    virtual int vfunc_07(int a1);
    bool sub_002CFB60(int);
    bool sub_002CFDC0(int);
};

int Sequence::vfunc_07(int a1)
{
    if (sub_002D6340(a1, 1)) {
        if (!sub_002CFDC0(a1)) goto L_39;
        if (!sub_002CFB60(a1)) goto L_39;
        return 1;
    }
L_39:
    return 0;
}

}

