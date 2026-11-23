// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail PC Scarface.exe v1.00.2, audio/StreamPlayerAllocator.cpp (2 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: COMPLETE. All 2 functions are matched.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] audio::StreamPlayerAllocator::vfunc_00 (0x006F09B0, 44 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// bin: pc
// va: 0x006F09B0
// what: 
// tool: the portal's starter code (no AI)

// audio::StreamPlayerAllocator::vfunc_00 (PC 0x006F09B0, 44 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int __cdecl sub_006F2080(int, int, int, int, int, int, int);

namespace audio {

class StreamPlayerAllocator
{
public:
    virtual int vfunc_00(int a1, int a2, int a3, int a4, int a5, int a6);
};

int StreamPlayerAllocator::vfunc_00(int a1, int a2, int a3, int a4, int a5, int a6)
{
    int t1;

    t1 = sub_006F2080(a4, 1, a3, a5, 0, 0, 1);
    *(int*)a6 = 0x20000;
    return t1;
}

}

// ============================================================================
// [VERIFIED] audio::StreamPlayerAllocator::vfunc_01 (0x006F09E0, 14 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as audio::StreamPlayerAllocator::vfunc_01 (Proto 0x002963B0), which was matched first;
// its addresses and names were swapped for this function's.
// audio::StreamPlayerAllocator::vfunc_01 (Proto 0x006F09E0, 14 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __cdecl sub_006F21F0(int);

namespace audio {

class StreamPlayerAllocator
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01(int a1, int a2);
};

void StreamPlayerAllocator::vfunc_01(int a1, int a2)
{
    sub_006F21F0(a2);
}

}

