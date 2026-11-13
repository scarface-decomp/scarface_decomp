// ============================================================================
// SCARFACE: THE WORLD IS YOURS — April 2006 prototype game.xbe, audio/MetaType_StatePropSound_.cpp (1 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: COMPLETE. All 1 functions are matched.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] om::MetaType<StatePropSound>::vfunc_00 (0x0005B130, 36 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as om::MetaType<GlobalVehicleSound>::vfunc_00 (0x00064FB0), which was matched first;
// its addresses and names were swapped for this function's.
// om::MetaType<StatePropSound>::vfunc_00 (0x0005B130, 36 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_00381110[];
extern "C" void __cdecl sub_00291D80(int);
extern "C" void __cdecl sub_00292750(void);

class StatePropSound;

namespace om { 
template <class T0> class MetaType
{
public:
    virtual MetaType<StatePropSound>* vfunc_00(int a1);
};
}

template <> om::MetaType<StatePropSound>* om::MetaType<StatePropSound>::vfunc_00(int a1)
{
    *(int*)this = (int)DAT_00381110;
    sub_00292750();
    if (a1 & 1) {
        sub_00291D80((int)this);
    }
    return this;
}

