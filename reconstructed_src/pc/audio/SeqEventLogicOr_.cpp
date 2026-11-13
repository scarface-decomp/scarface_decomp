// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail PC Scarface.exe v1.00.2, audio/SeqEventLogicOr_.cpp (1 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: COMPLETE. All 1 functions are matched.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] audio::SeqEventType<audio::SeqEventLogicOr>::vfunc_01 (0x006FAF70, 62 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as audio::SeqEventType<audio::SeqEventLogicOr>::vfunc_01 (0x002DD360), which was matched first;
// its addresses and names were swapped for this function's.
// audio::SeqEventType<audio::SeqEventLogicOr>::vfunc_01 (0x006FAF70, 62 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_006F5850();
};

extern "C" char DAT_00773890[];
extern "C" char DAT_007F7D94[];
extern "C" int __cdecl sub_006EE870(int);

namespace audio { class SeqEventLogicOr; }

namespace audio { 
template <class T0> class SeqEventType
{
public:
    virtual void vfunc_00();
    virtual int vfunc_01();
};
}

template <> int audio::SeqEventType<audio::SeqEventLogicOr>::vfunc_01()
{
    int t1;

    t1 = sub_006EE870((int)DAT_007F7D94);
    if (t1) {
        ((Object*)t1)->sub_006F5850();
        *(int*)(t1 + 8) = 0;
        *(int*)(t1 + 12) = 0;
        *(int*)t1 = (int)DAT_00773890;
        *(int*)(t1 + 16) = 0x3F000000;
        return t1;
    }
    return 0;
}

