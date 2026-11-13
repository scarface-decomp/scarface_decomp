// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail Xbox default.xbe, om/Allocator.cpp (1 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: COMPLETE. All 1 functions are matched.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] om::Allocator::vfunc_00 (0x002CFA80, 31 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as core::BaseObject::vfunc_00 (0x00026BB0), which was matched first;
// its addresses and names were swapped for this function's.
// om::Allocator::vfunc_00 (0x002CFA80, 31 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_003DFD60[];
extern "C" void __cdecl sub_00027600(int);

namespace om {

class Allocator
{
public:
    virtual Allocator* vfunc_00(int a1);
};

Allocator* Allocator::vfunc_00(int a1)
{
    *(int*)this = (int)DAT_003DFD60;
    if (a1 & 1) {
        sub_00027600((int)this);
    }
    return this;
}

}

