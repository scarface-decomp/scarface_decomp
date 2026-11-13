// ============================================================================
// SCARFACE: THE WORLD IS YOURS — April 2006 prototype game.xbe, om/SeqEventVarPitchRand_.cpp (1 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: COMPLETE. All 1 functions are matched.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] om::MetaType<audio::SeqEventVarPitchRand>::vfunc_00 (0x002A7C50, 36 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as om::MetaType<audio::SeqEvent>::vfunc_00 (0x002D0EA0), which was matched first;
// its addresses and names were swapped for this function's.
// om::MetaType<audio::SeqEventVarPitchRand>::vfunc_00 (0x002A7C50, 36 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_003BAAFC[];
extern "C" void __cdecl sub_00291D80(int);
extern "C" void __cdecl sub_00292750(void);

namespace audio { class SeqEventVarPitchRand; }

namespace om { 
template <class T0> class MetaType
{
public:
    virtual MetaType<audio::SeqEventVarPitchRand>* vfunc_00(int a1);
};
}

template <> om::MetaType<audio::SeqEventVarPitchRand>* om::MetaType<audio::SeqEventVarPitchRand>::vfunc_00(int a1)
{
    *(int*)this = (int)DAT_003BAAFC;
    sub_00292750();
    if (a1 & 1) {
        sub_00291D80((int)this);
    }
    return this;
}

