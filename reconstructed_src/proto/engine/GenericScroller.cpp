// ============================================================================
// SCARFACE: THE WORLD IS YOURS — April 2006 prototype game.xbe, engine/GenericScroller.cpp (1 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 1 of 2 functions matched (50.00%). NOT COMPLETE YET.
// The 1 still to do are listed in their place in Original_Binary_Order_Proto.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] GenericScroller::vfunc_00 (0x001703F0, 67 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// GenericScroller::vfunc_00 (Proto 0x001703F0, 67 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0037D8E8[];
extern "C" char DAT_00383680[];
extern "C" char DAT_0039861C[];
extern "C" char DAT_0039863C[];
extern "C" void __cdecl sub_00025160(int);
extern "C" void __cdecl sub_00065830(int, int, int);

class GenericScroller
{
public:
    virtual GenericScroller* vfunc_00(bool a1);
    char m_pad04[0x8];
    int m_Field0C; // +0x0C
    char m_pad10[0x14];
    bool m_Field24; // +0x24
};

GenericScroller* GenericScroller::vfunc_00(bool a1)
{
    *(int*)this = (int)DAT_0039861C;
    sub_00065830((int)DAT_0039863C, (int)DAT_0037D8E8, (int)DAT_00383680);
    m_Field0C = 0;
    m_Field24 = true;
    if (1 & a1) {
        sub_00025160((int)this);
    }
    return this;
}

