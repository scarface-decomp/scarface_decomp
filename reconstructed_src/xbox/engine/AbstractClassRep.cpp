// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail Xbox default.xbe, engine/AbstractClassRep.cpp (1 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 1 of 2 functions matched (50.00%). NOT COMPLETE YET.
// The 1 still to do are listed in their place in Original_Binary_Order_Xbox.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] AbstractClassRep::vfunc_01 (0x002FBA99, 20 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as AbstractClassRep::vfunc_01 (Proto 0x002C8D5D), which was matched first;
// its addresses and names were swapped for this function's.
// AbstractClassRep::vfunc_01 (Proto 0x002FBA99, 20 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_004C066C;
extern "C" void __cdecl sub_002FF3F0(int);

class AbstractClassRep
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
};

void AbstractClassRep::vfunc_01()
{
    int t1;

    t1 = DAT_004C066C;
    if (DAT_004C066C) {
        ((void (__cdecl*)(void))t1)();
    }
    sub_002FF3F0(25);
}

