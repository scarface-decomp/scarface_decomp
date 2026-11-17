// ============================================================================
// SCARFACE: THE WORLD IS YOURS — April 2006 prototype game.xbe, audio/SeqEventStream_.cpp (2 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: COMPLETE. All 2 functions are matched.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] om::MetaType<audio::SeqEventStream>::vfunc_00 (0x002A86D0, 36 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as om::MetaType<audio::SeqEvent>::vfunc_00 (0x002D0EA0), which was matched first;
// its addresses and names were swapped for this function's.
// om::MetaType<audio::SeqEventStream>::vfunc_00 (0x002A86D0, 36 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_003BAC70[];
extern "C" void __cdecl sub_00291D80(int);
extern "C" void __cdecl sub_00292750(void);

namespace audio { class SeqEventStream; }

namespace om { 
template <class T0> class MetaType
{
public:
    virtual MetaType<audio::SeqEventStream>* vfunc_00(int a1);
};
}

template <> om::MetaType<audio::SeqEventStream>* om::MetaType<audio::SeqEventStream>::vfunc_00(int a1)
{
    *(int*)this = (int)DAT_003BAC70;
    sub_00292750();
    if (a1 & 1) {
        sub_00291D80((int)this);
    }
    return this;
}

// ============================================================================
// [VERIFIED] audio::SeqEventType<audio::SeqEventStream>::vfunc_01 (0x002A8920, 49 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// audio::SeqEventType<audio::SeqEventStream>::vfunc_01 (Proto 0x002A8920, 49 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_00072F90();
    void sub_0029E890();
};

extern "C" char DAT_003BAC88[];
extern "C" char DAT_004912A8[];
extern "C" int __cdecl sub_00293590(int);

namespace audio { class SeqEventStream; }

namespace audio { 
template <class T0> class SeqEventType
{
public:
    virtual void vfunc_00();
    virtual int vfunc_01();
};
}

template <> int audio::SeqEventType<audio::SeqEventStream>::vfunc_01()
{
    int t1;

    t1 = sub_00293590((int)DAT_004912A8);
    if (t1) {
        ((Object*)t1)->sub_0029E890();
        *(int*)t1 = (int)DAT_003BAC88;
        ((Object*)t1 + 48)->sub_00072F90();
        return t1;
    }
    return 0;
}

