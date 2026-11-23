// ============================================================================
// SCARFACE: THE WORLD IS YOURS — April 2006 prototype game.xbe, audio/ContentStream.cpp (1 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: COMPLETE. All 1 functions are matched.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] om::ContentStream::vfunc_00 (0x00293E50, 45 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// What it does: om::ContentStream's deleting destructor: destroys the object, frees its memory when asked (flag bit 0), and returns it.
// ============================================================================
// om::ContentStream::vfunc_00 (Proto 0x00293E50, 45 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    virtual void vfunc_00();
    virtual void vfunc_01();
};

extern "C" char DAT_003834C4[];
extern "C" char DAT_003B92CC[];
extern "C" void __cdecl sub_00025160(int);

namespace om {

class ContentStream
{
public:
    virtual ContentStream* vfunc_00(int a1);
    char m_pad04[0x1C];
    int m_Field20; // +0x20
};

ContentStream* ContentStream::vfunc_00(int a1)
{
    int t1;

    t1 = m_Field20;
    *(int*)this = (int)DAT_003B92CC;
    ((Object*)t1)->vfunc_01();
    *(int*)this = (int)DAT_003834C4;
    if (a1 & 1) {
        sub_00025160((int)this);
    }
    return this;
}

}

