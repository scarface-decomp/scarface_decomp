// ============================================================================
// SCARFACE: THE WORLD IS YOURS — April 2006 prototype game.xbe, audio/SeqEventSilence_.cpp (1 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: COMPLETE. All 1 functions are matched.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] audio::SeqEventType<audio::SeqEventSilence>::vfunc_01 (0x002A92A0, 55 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// audio::SeqEventType<audio::SeqEventSilence>::vfunc_01 (Proto 0x002A92A0, 55 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0029E890();
};

extern "C" char DAT_003BAD18[];
extern "C" char DAT_004912D8[];
extern "C" int __cdecl sub_00293590(int);

namespace audio { class SeqEventSilence; }

namespace audio { 
template <class T0> class SeqEventType
{
public:
    virtual void vfunc_00();
    virtual int vfunc_01();
};
}

template <> int audio::SeqEventType<audio::SeqEventSilence>::vfunc_01()
{
    int t1;

    t1 = sub_00293590((int)DAT_004912D8);
    if (t1) {
        ((Object*)t1)->sub_0029E890();
        *(int*)t1 = (int)DAT_003BAD18;
        *(int*)(t1 + 48) = 500;
        *(int*)(t1 + 52) = 1000;
        return t1;
    }
    return 0;
}

