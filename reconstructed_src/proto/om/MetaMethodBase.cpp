// ============================================================================
// SCARFACE: THE WORLD IS YOURS — April 2006 prototype game.xbe, om/MetaMethodBase.cpp (1 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: COMPLETE. All 1 functions are matched.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] om::MetaMethodBase::vfunc_00 (0x002A09B0, 31 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as core::BaseObject::vfunc_00 (0x00026BB0), which was matched first;
// its addresses and names were swapped for this function's.
// om::MetaMethodBase::vfunc_00 (0x002A09B0, 31 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_003B9F1C[];
extern "C" void __cdecl sub_00025160(int);

namespace om {

class MetaMethodBase
{
public:
    virtual MetaMethodBase* vfunc_00(int a1);
};

MetaMethodBase* MetaMethodBase::vfunc_00(int a1)
{
    *(int*)this = (int)DAT_003B9F1C;
    if (a1 & 1) {
        sub_00025160((int)this);
    }
    return this;
}

}

