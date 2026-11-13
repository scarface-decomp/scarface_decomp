// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail PC Scarface.exe v1.00.2, audio/SeqEvent.cpp (2 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 2 of 3 functions matched (66.67%). NOT COMPLETE YET.
// The 1 still to do are listed in their place in Original_Binary_Order_PC_1002.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] audio::SeqEvent::vfunc_00 (0x006F5740, 18 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as audio::SeqEvent::vfunc_00 (0x002D6A00), which was matched first;
// its addresses and names were swapped for this function's.
// audio::SeqEvent::vfunc_00 (0x006F5740, 18 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __cdecl sub_006FF600(int, int);

namespace audio {

class SeqEvent
{
public:
    virtual void vfunc_00(int a1);
};

void SeqEvent::vfunc_00(int a1)
{
    sub_006FF600(a1, 0);
}

}

// ============================================================================
// [VERIFIED] audio::SeqEvent::vfunc_04 (0x006F5830, 31 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as core::BaseObject::vfunc_00 (0x00026BB0), which was matched first;
// its addresses and names were swapped for this function's.
// audio::SeqEvent::vfunc_04 (0x006F5830, 31 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_00772DC8[];
extern "C" void __cdecl sub_0043CE70(int);

namespace audio {

class SeqEvent
{
public:
    virtual SeqEvent* vfunc_04(int a1);
};

SeqEvent* SeqEvent::vfunc_04(int a1)
{
    *(int*)this = (int)DAT_00772DC8;
    if (a1 & 1) {
        sub_0043CE70((int)this);
    }
    return this;
}

}

