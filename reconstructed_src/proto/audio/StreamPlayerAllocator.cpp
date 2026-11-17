// ============================================================================
// SCARFACE: THE WORLD IS YOURS — April 2006 prototype game.xbe, audio/StreamPlayerAllocator.cpp (4 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 4 of 5 functions matched (80.00%). NOT COMPLETE YET.
// The 1 still to do are listed in their place in Original_Binary_Order_Proto.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] SoundAllocator::StreamPlayerAllocator::vfunc_01 (0x00077180, 22 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// SoundAllocator::StreamPlayerAllocator::vfunc_01 (Proto 0x00077180, 22 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_00453980;
extern "C" void __cdecl sub_0029A9A0(int);

namespace SoundAllocator {

class StreamPlayerAllocator
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01(int a1, int a2);
};

void StreamPlayerAllocator::vfunc_01(int a1, int a2)
{
    *(int*)(DAT_00453980 + 80) -= 1;
    sub_0029A9A0(a2);
}

}

// ============================================================================
// [VERIFIED] SoundAllocator::StreamPlayerAllocator::vfunc_02 (0x00077210, 31 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as core::BaseObject::vfunc_00 (0x00026BB0), which was matched first;
// its addresses and names were swapped for this function's.
// SoundAllocator::StreamPlayerAllocator::vfunc_02 (0x00077210, 31 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_00382CE4[];
extern "C" void __cdecl sub_00025160(int);

namespace SoundAllocator {

class StreamPlayerAllocator
{
public:
    virtual StreamPlayerAllocator* vfunc_02(int a1);
};

StreamPlayerAllocator* StreamPlayerAllocator::vfunc_02(int a1)
{
    *(int*)this = (int)DAT_00382CE4;
    if (a1 & 1) {
        sub_00025160((int)this);
    }
    return this;
}

}

// ============================================================================
// [VERIFIED] audio::StreamPlayerAllocator::vfunc_00 (0x00296380, 34 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// audio::StreamPlayerAllocator::vfunc_00 (Proto 0x00296380, 34 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __cdecl sub_0029ABB0(int, int, int, int, int, int, int);

namespace audio {

class StreamPlayerAllocator
{
public:
    virtual void vfunc_00(int a1, int a2, int a3, int a4);
};

void StreamPlayerAllocator::vfunc_00(int a1, int a2, int a3, int a4)
{
    sub_0029ABB0(a3, 1, a2, a4, 0, 0, 1);
}

}

// ============================================================================
// [VERIFIED] audio::StreamPlayerAllocator::vfunc_01 (0x002963B0, 14 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// audio::StreamPlayerAllocator::vfunc_01 (Proto 0x002963B0, 14 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __cdecl sub_0029A9A0(int);

namespace audio {

class StreamPlayerAllocator
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01(int a1, int a2);
};

void StreamPlayerAllocator::vfunc_01(int a1, int a2)
{
    sub_0029A9A0(a2);
}

}

