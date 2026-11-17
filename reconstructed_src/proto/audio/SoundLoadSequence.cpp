// ============================================================================
// SCARFACE: THE WORLD IS YOURS — April 2006 prototype game.xbe, audio/SoundLoadSequence.cpp (1 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 1 of 2 functions matched (50.00%). NOT COMPLETE YET.
// The 1 still to do are listed in their place in Original_Binary_Order_Proto.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] SoundLoadSequence::vfunc_03 (0x00077520, 69 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// SoundLoadSequence::vfunc_03 (Proto 0x00077520, 69 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field08
{
    virtual void vfunc_00();
    virtual void vfunc_01();
};

struct Object
{
    void sub_000772D0(int);
};

extern "C" char DAT_0037D85C[];
extern "C" char DAT_00382CF4[];
extern "C" int DAT_0045398C;
extern "C" char DAT_004539BC[];
extern "C" void __cdecl sub_002935D0(int, int);

class SoundLoadSequence
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual SoundLoadSequence* vfunc_03(int a1);
    char m_pad04[0x4];
    Field08* m_Field08; // +0x08
};

SoundLoadSequence* SoundLoadSequence::vfunc_03(int a1)
{
    *(int*)this = (int)DAT_00382CF4;
    ((Object*)DAT_0045398C)->sub_000772D0((int)this);
    m_Field08->vfunc_01();
    m_Field08 = 0;
    *(int*)this = (int)DAT_0037D85C;
    if (a1 & 1) {
        sub_002935D0((int)DAT_004539BC, (int)this);
    }
    return this;
}

