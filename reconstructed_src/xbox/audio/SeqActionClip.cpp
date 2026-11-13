// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail Xbox default.xbe, audio/SeqActionClip.cpp (3 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 3 of 6 functions matched (50.00%). NOT COMPLETE YET.
// The 3 still to do are listed in their place in Original_Binary_Order_Xbox.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] audio::SeqActionClip::vfunc_03 (0x002DDC10, 54 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// audio::SeqActionClip::vfunc_03 (0x002DDC10, 54 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __cdecl sub_002DF270(int);
extern "C" int __cdecl sub_002E0320(int);

namespace audio {

class SeqActionClip
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03(int a1);
    void sub_002D6A60(int, int);
    char m_pad04[0x18];
    int m_Field1C; // +0x1C
};

void SeqActionClip::vfunc_03(int a1)
{
    int t1;

    t1 = m_Field1C;
    if (m_Field1C) {
        if (sub_002E0320(t1) != 1) goto L_24;
        sub_002DF270(m_Field1C);
    }
L_24:
    sub_002D6A60(4, a1);
}

}

// ============================================================================
// [VERIFIED] audio::SeqActionClip::vfunc_04 (0x002DDC50, 54 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// audio::SeqActionClip::vfunc_04 (0x002DDC50, 54 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __cdecl sub_002DF270(int);
extern "C" int __cdecl sub_002E0320(int);

namespace audio {

class SeqActionClip
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04(int a1);
    void sub_002D6A60(int, int);
    char m_pad04[0x18];
    int m_Field1C; // +0x1C
};

void SeqActionClip::vfunc_04(int a1)
{
    int t1;

    t1 = m_Field1C;
    if (m_Field1C) {
        if (sub_002E0320(t1) != 1) goto L_24;
        sub_002DF270(m_Field1C);
    }
L_24:
    sub_002D6A60(5, a1);
}

}

// ============================================================================
// [VERIFIED] audio::SeqActionClip::vfunc_00 (0x002DDDB0, 36 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as SoundManager::SoundPlayerHandle::vfunc_00 (0x00077F00), which was matched first;
// its addresses and names were swapped for this function's.
// audio::SeqActionClip::vfunc_00 (0x002DDDB0, 36 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_003E07F4[];
extern "C" char DAT_00464C2C[];
extern "C" void __cdecl sub_002CF980(int, int);

namespace audio {

class SeqActionClip
{
public:
    virtual SeqActionClip* vfunc_00(int a1);
};

SeqActionClip* SeqActionClip::vfunc_00(int a1)
{
    *(int*)this = (int)DAT_003E07F4;
    if (a1 & 1) {
        sub_002CF980((int)DAT_00464C2C, (int)this);
    }
    return this;
}

}

