// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail Xbox default.xbe, audio/StreamPlayerAllocator.cpp (3 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 3 of 5 functions matched (60.00%). NOT COMPLETE YET.
// The 2 still to do are listed in their place in Original_Binary_Order_Xbox.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] SoundAllocator::StreamPlayerAllocator::vfunc_02 (0x00082860, 31 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as core::BaseObject::vfunc_00 (0x00026BB0), which was matched first;
// its addresses and names were swapped for this function's.
// SoundAllocator::StreamPlayerAllocator::vfunc_02 (0x00082860, 31 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_003A377C[];
extern "C" void __cdecl sub_00027600(int);

namespace SoundAllocator {

class StreamPlayerAllocator
{
public:
    virtual StreamPlayerAllocator* vfunc_02(int a1);
};

StreamPlayerAllocator* StreamPlayerAllocator::vfunc_02(int a1)
{
    *(int*)this = (int)DAT_003A377C;
    if (a1 & 1) {
        sub_00027600((int)this);
    }
    return this;
}

}

// ============================================================================
// [VERIFIED] audio::StreamPlayerAllocator::vfunc_00 (0x002D22B0, 44 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// bin: xb
// va: 0x002D22B0
// what: 
// tool: the portal's starter code (no AI)

// audio::StreamPlayerAllocator::vfunc_00 (0x002D22B0, 44 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char sub_00020000[];
extern "C" int __cdecl sub_002D41D0(int, int, int, int, int, int, int);

namespace audio {

class StreamPlayerAllocator
{
public:
    virtual int vfunc_00(int a1, int a2, int a3, int a4, int a5, int a6);
};

int StreamPlayerAllocator::vfunc_00(int a1, int a2, int a3, int a4, int a5, int a6)
{
    int t1;

    t1 = sub_002D41D0(a4, 1, a3, a5, 0, 0, 1);
    *(int*)a6 = (int)sub_00020000;
    return t1;
}

}

// ============================================================================
// [VERIFIED] audio::StreamPlayerAllocator::vfunc_01 (0x002D22E0, 14 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as audio::StreamPlayerAllocator::vfunc_01 (Proto 0x002963B0), which was matched first;
// its addresses and names were swapped for this function's.
// audio::StreamPlayerAllocator::vfunc_01 (Proto 0x002D22E0, 14 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __cdecl sub_002D4340(int);

namespace audio {

class StreamPlayerAllocator
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01(int a1, int a2);
};

void StreamPlayerAllocator::vfunc_01(int a1, int a2)
{
    sub_002D4340(a2);
}

}

