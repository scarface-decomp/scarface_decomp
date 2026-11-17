// ============================================================================
// SCARFACE: THE WORLD IS YOURS — April 2006 prototype game.xbe, audio/StdStream.cpp (1 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: COMPLETE. All 1 functions are matched.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] om::StdStream::vfunc_00 (0x00293E10, 56 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// om::StdStream::vfunc_00 (Proto 0x00293E10, 56 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_003834C4[];
extern "C" char DAT_003B92A4[];
extern "C" void __cdecl sub_00025160(int);
extern "C" void __cdecl sub_002CB933(int);

namespace om {

class StdStream
{
public:
    virtual StdStream* vfunc_00(int a1);
    char m_pad04[0x1C];
    int m_Field20; // +0x20
    bool m_Field24; // +0x24
};

StdStream* StdStream::vfunc_00(int a1)
{
    *(int*)this = (int)DAT_003B92A4;
    if (m_Field24) {
        sub_002CB933(m_Field20);
    }
    *(int*)this = (int)DAT_003834C4;
    if (a1 & 1) {
        sub_00025160((int)this);
    }
    return this;
}

}

