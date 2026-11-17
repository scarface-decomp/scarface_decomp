// ============================================================================
// SCARFACE: THE WORLD IS YOURS — April 2006 prototype game.xbe, audio/SeqEventContainer.cpp (1 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 1 of 6 functions matched (16.67%). NOT COMPLETE YET.
// The 5 still to do are listed in their place in Original_Binary_Order_Proto.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] audio::SeqEventContainer::vfunc_06 (0x0029EED0, 53 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// audio::SeqEventContainer::vfunc_06 (Proto 0x0029EED0, 53 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field08
{
    void sub_002AE240();
};

struct Field30
{
    void sub_0029EDE0();
};

extern "C" char DAT_003B9A18[];
extern "C" char DAT_003B9A70[];
extern "C" void __cdecl sub_00025160(int);

namespace audio {

class SeqEventContainer
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual void vfunc_05();
    virtual SeqEventContainer* vfunc_06(int a1);
    char m_pad04[0x4];
    Field08 m_Field08; // +0x08
    char m_pad09[0x27];
    Field30 m_Field30; // +0x30
};

SeqEventContainer* SeqEventContainer::vfunc_06(int a1)
{
    *(int*)this = (int)DAT_003B9A70;
    m_Field30.sub_0029EDE0();
    *(int*)this = (int)DAT_003B9A18;
    m_Field08.sub_002AE240();
    if (a1 & 1) {
        sub_00025160((int)this);
    }
    return this;
}

}

