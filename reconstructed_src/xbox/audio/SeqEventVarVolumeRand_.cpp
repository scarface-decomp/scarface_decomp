// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail Xbox default.xbe, audio/SeqEventVarVolumeRand_.cpp (1 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: COMPLETE. All 1 functions are matched.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] audio::SeqEventType<audio::SeqEventVarVolumeRand>::vfunc_01 (0x002DB4F0, 55 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// audio::SeqEventType<audio::SeqEventVarVolumeRand>::vfunc_01 (0x002DB4F0, 55 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_002D6B50();
};

extern "C" char DAT_003E0D30[];
extern "C" char DAT_00464570[];
extern "C" int __cdecl sub_002CF960(int);

namespace audio { class SeqEventVarVolumeRand; }

namespace audio { 
template <class T0> class SeqEventType
{
public:
    virtual void vfunc_00();
    virtual int vfunc_01();
};
}

template <> int audio::SeqEventType<audio::SeqEventVarVolumeRand>::vfunc_01()
{
    int t1;

    t1 = sub_002CF960((int)DAT_00464570);
    if (t1) {
        ((Object*)t1)->sub_002D6B50();
        *(int*)t1 = (int)DAT_003E0D30;
        *(int*)(t1 + 8) = 0x3F000000;
        *(int*)(t1 + 12) = 0x3F800000;
        return t1;
    }
    return 0;
}

