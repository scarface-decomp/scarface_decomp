// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail Xbox default.xbe, om/SeqEvent_.cpp (1 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: COMPLETE. All 1 functions are matched.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] om::MetaType<audio::SeqEvent>::vfunc_00 (0x002D0EA0, 36 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// om::MetaType<audio::SeqEvent>::vfunc_00 (0x002D0EA0, 36 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_003DFE60[];
extern "C" void __cdecl sub_002CEBD0(int);
extern "C" void __cdecl sub_002CEF70(void);

namespace audio { class SeqEvent; }

namespace om { 
template <class T0> class MetaType
{
public:
    virtual MetaType<audio::SeqEvent>* vfunc_00(int a1);
};
}

template <> om::MetaType<audio::SeqEvent>* om::MetaType<audio::SeqEvent>::vfunc_00(int a1)
{
    *(int*)this = (int)DAT_003DFE60;
    sub_002CEF70();
    if (a1 & 1) {
        sub_002CEBD0((int)this);
    }
    return this;
}

