// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail Xbox default.xbe, engine/GenericBarMeter.cpp (1 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 1 of 8 functions matched (12.50%). NOT COMPLETE YET.
// The 7 still to do are listed in their place in Original_Binary_Order_Xbox.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] GenericBarMeter::vfunc_00 (0x0018F780, 60 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// What it does: GenericBarMeter's deleting destructor: destroys the object, frees its memory when asked (flag bit 0), and returns it.
// ============================================================================
// Same machine code as GenericBarMeter::vfunc_00 (Proto 0x0016BC70), which was matched first;
// its addresses and names were swapped for this function's.
// GenericBarMeter::vfunc_00 (Proto 0x0018F780, 60 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_003B9FA0[];
extern "C" char DAT_003BA008[];
extern "C" void __cdecl sub_00027600(int);
extern "C" void __stdcall sub_0018F4C0(int);

class GenericBarMeter
{
public:
    virtual GenericBarMeter* vfunc_00(int a1);
    char m_pad04[0x4];
    int m_Field08; // +0x08
    char m_pad0C[0x4];
    int m_Field10; // +0x10
};

GenericBarMeter* GenericBarMeter::vfunc_00(int a1)
{
    *(int*)this = (int)DAT_003BA008;
    if (m_Field10) {
        sub_0018F4C0(m_Field08);
        m_Field10 = 0;
    }
    *(int*)this = (int)DAT_003B9FA0;
    if (a1 & 1) {
        sub_00027600((int)this);
    }
    return this;
}

