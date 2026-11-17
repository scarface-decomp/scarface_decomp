// ============================================================================
// SCARFACE: THE WORLD IS YOURS — April 2006 prototype game.xbe, om/CaseSensitive32BitKey__.cpp (1 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 1 of 6 functions matched (16.67%). NOT COMPLETE YET.
// The 5 still to do are listed in their place in Original_Binary_Order_Proto.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] om::Garbage<om::Name<om::CaseSensitive32BitKey>>::vfunc_00 (0x002A2230, 30 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// om::Garbage<om::Name<om::CaseSensitive32BitKey>>::vfunc_00 (Proto 0x002A2230, 30 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __cdecl sub_002A2250(void);
extern "C" void __cdecl sub_002A22A0(int);

namespace om {

class Garbage_om__Name_om__CaseSensitive32BitKey__
{
public:
    virtual Garbage_om__Name_om__CaseSensitive32BitKey__* vfunc_00(int a1);
};

Garbage_om__Name_om__CaseSensitive32BitKey__* Garbage_om__Name_om__CaseSensitive32BitKey__::vfunc_00(int a1)
{
    sub_002A2250();
    if (a1 & 1) {
        sub_002A22A0((int)this);
    }
    return this;
}

}

