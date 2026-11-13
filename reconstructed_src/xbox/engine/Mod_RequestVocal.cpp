// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail Xbox default.xbe, engine/Mod_RequestVocal.cpp (1 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 1 of 3 functions matched (33.33%). NOT COMPLETE YET.
// The 2 still to do are listed in their place in Original_Binary_Order_Xbox.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] AICommandMods::Mod_RequestVocal::vfunc_00 (0x001354B0, 75 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as AICommandMods::Mod_ExecScript::vfunc_00 (0x001350E0), which was matched first;
// its addresses and names were swapped for this function's.
// AICommandMods::Mod_RequestVocal::vfunc_00 (0x001354B0, 75 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_00026F40(int);
    void sub_00026F60();
};

extern "C" char DAT_003B179C[];
extern "C" char DAT_003B19B8[];
extern "C" int DAT_0048A09C;
extern "C" void __cdecl sub_00027600(int);

namespace AICommandMods {

class Mod_RequestVocal
{
public:
    virtual Mod_RequestVocal* vfunc_00(int a1);
    char m_pad04[0x4];
    int m_Field08; // +0x08
};

Mod_RequestVocal* Mod_RequestVocal::vfunc_00(int a1)
{
    int local_4;

    *(int*)this = (int)DAT_003B19B8;
    ((Object*)(int)(&local_4))->sub_00026F40(DAT_0048A09C);
    sub_00027600(m_Field08);
    ((Object*)(int)(&local_4))->sub_00026F60();
    *(int*)this = (int)DAT_003B179C;
    if (a1 & 1) {
        sub_00027600((int)this);
    }
    return this;
}

}

