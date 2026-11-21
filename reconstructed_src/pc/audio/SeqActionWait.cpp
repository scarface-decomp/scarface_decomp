// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail PC Scarface.exe v1.00.2, audio/SeqActionWait.cpp (5 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 5 of 6 functions matched (83.33%). NOT COMPLETE YET.
// The 1 still to do are listed in their place in Original_Binary_Order_PC_1002.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] audio::SeqActionWait::vfunc_02 (0x006F78E0, 21 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as audio::SeqActionWait::vfunc_02 (Proto 0x002A3D90), which was matched first;
// its addresses and names were swapped for this function's.
// audio::SeqActionWait::vfunc_02 (Proto 0x006F78E0, 21 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __stdcall sub_006F57A0(int, int);

namespace audio {

class SeqActionWait
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02(int a1, int a2);
};

void SeqActionWait::vfunc_02(int a1, int a2)
{
    a2 = a1;
    a1 = 1;
    sub_006F57A0(a1, a2);
}

}

// ============================================================================
// [VERIFIED] audio::SeqActionWait::vfunc_01 (0x006F7900, 15 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as audio::SeqActionWait::vfunc_01 (Proto 0x002A3DB0), which was matched first;
// its addresses and names were swapped for this function's.
// audio::SeqActionWait::vfunc_01 (Proto 0x006F7900, 15 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __stdcall sub_006F57A0(int, int);

namespace audio {

class SeqActionWait
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01(int a1);
};

void SeqActionWait::vfunc_01(int a1)
{
    sub_006F57A0(3, a1);
}

}

// ============================================================================
// [VERIFIED] audio::SeqActionWait::vfunc_03 (0x006F7910, 15 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as audio::SeqActionWait::vfunc_03 (Proto 0x002A3DC0), which was matched first;
// its addresses and names were swapped for this function's.
// audio::SeqActionWait::vfunc_03 (Proto 0x006F7910, 15 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __stdcall sub_006F57A0(int, int);

namespace audio {

class SeqActionWait
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03(int a1);
};

void SeqActionWait::vfunc_03(int a1)
{
    sub_006F57A0(4, a1);
}

}

// ============================================================================
// [VERIFIED] audio::SeqActionWait::vfunc_04 (0x006F7920, 15 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as audio::SeqActionWait::vfunc_04 (Proto 0x002A3DD0), which was matched first;
// its addresses and names were swapped for this function's.
// audio::SeqActionWait::vfunc_04 (Proto 0x006F7920, 15 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __stdcall sub_006F57A0(int, int);

namespace audio {

class SeqActionWait
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04(int a1);
};

void SeqActionWait::vfunc_04(int a1)
{
    sub_006F57A0(5, a1);
}

}

// ============================================================================
// [VERIFIED] audio::SeqActionWait::vfunc_00 (0x006F7970, 36 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as SoundManager::SoundPlayerHandle::vfunc_00 (0x00077F00), which was matched first;
// its addresses and names were swapped for this function's.
// audio::SeqActionWait::vfunc_00 (0x006F7970, 36 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_00772F80[];
extern "C" char DAT_007F73D4[];
extern "C" void __cdecl sub_006EE890(int, int);

namespace audio {

class SeqActionWait
{
public:
    virtual SeqActionWait* vfunc_00(int a1);
};

SeqActionWait* SeqActionWait::vfunc_00(int a1)
{
    *(int*)this = (int)DAT_00772F80;
    if (a1 & 1) {
        sub_006EE890((int)DAT_007F73D4, (int)this);
    }
    return this;
}

}

