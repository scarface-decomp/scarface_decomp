// ============================================================================
// SCARFACE: THE WORLD IS YOURS — April 2006 prototype game.xbe, audio/MemStream.cpp (1 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 1 of 7 functions matched (14.29%). NOT COMPLETE YET.
// The 6 still to do are listed in their place in Original_Binary_Order_Proto.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] MemStream::vfunc_00 (0x0006B1C0, 51 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as MemStream::vfunc_00 (0x00075860), which was matched first;
// its addresses and names were swapped for this function's.
// MemStream::vfunc_00 (0x0006B1C0, 51 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_003826A4[];
extern "C" void __cdecl sub_00025160(int);
extern "C" void __cdecl sub_0006BF70(void);

class MemStream
{
public:
    virtual MemStream* vfunc_00(int a1);
    int m_Field04; // +0x04
    char m_pad08[0x4];
    int m_Field0C; // +0x0C
    char m_pad10[0x4];
    int m_Field14; // +0x14
};

MemStream* MemStream::vfunc_00(int a1)
{
    *(int*)this = (int)DAT_003826A4;
    m_Field0C = 0;
    m_Field14 = 0;
    m_Field04 = 4;
    sub_0006BF70();
    if (a1 & 1) {
        sub_00025160((int)this);
    }
    return this;
}

