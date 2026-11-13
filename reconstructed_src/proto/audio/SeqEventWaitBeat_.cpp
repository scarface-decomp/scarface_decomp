// ============================================================================
// SCARFACE: THE WORLD IS YOURS — April 2006 prototype game.xbe, audio/SeqEventWaitBeat_.cpp (1 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: COMPLETE. All 1 functions are matched.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] audio::SeqEventType<audio::SeqEventWaitBeat>::vfunc_01 (0x002A4690, 27 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as audio::SeqEventType<audio::SeqEventChannelSendVolumes>::vfunc_01 (0x002D93F0), which was matched first;
// its addresses and names were swapped for this function's.
// audio::SeqEventType<audio::SeqEventWaitBeat>::vfunc_01 (0x002A4690, 27 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    int sub_002A4360();
};

extern "C" char DAT_00491064[];
extern "C" int __cdecl sub_00293590(int);

namespace audio { class SeqEventWaitBeat; }

namespace audio { 
template <class T0> class SeqEventType
{
public:
    virtual void vfunc_00();
    virtual int vfunc_01();
};
}

template <> int audio::SeqEventType<audio::SeqEventWaitBeat>::vfunc_01()
{
    int t1;

    t1 = sub_00293590((int)DAT_00491064);
    if (t1) {
        return ((Object*)t1)->sub_002A4360();
    }
    return 0;
}

