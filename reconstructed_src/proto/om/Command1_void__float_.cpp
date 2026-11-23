// ============================================================================
// SCARFACE: THE WORLD IS YOURS — April 2006 prototype game.xbe, om/Command1_void__float_.cpp (1 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: COMPLETE. All 1 functions are matched.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] om::Command1<void, float>::vfunc_00 (0x0029F5B0, 31 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// bin: proto
// va: 0x0029F5B0
// what: 
// tool: the portal's starter code (no AI)

// om::Command1<void, float>::vfunc_00 (Proto 0x0029F5B0, 31 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_003B9B10[];
extern "C" void __cdecl sub_00025160(int);

namespace om { 
template <class T0, class T1> class Command1
{
public:
    virtual Command1<void, float>* vfunc_00(int a1);
};
}

template <> om::Command1<void, float>* om::Command1<void, float>::vfunc_00(int a1)
{
    *(int*)this = (int)DAT_003B9B10;
    if (a1 & 1) {
        sub_00025160((int)this);
    }
    return this;
}

