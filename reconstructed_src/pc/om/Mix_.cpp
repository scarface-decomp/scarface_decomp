// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail PC Scarface.exe v1.00.2, om/Mix_.cpp (5 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: COMPLETE. All 5 functions are matched.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] om::MetaType<audio::Mix>::vfunc_00 (0x006EEAF0, 36 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as om::MetaType<audio::SeqEvent>::vfunc_00 (0x002D0EA0), which was matched first;
// its addresses and names were swapped for this function's.
// om::MetaType<audio::Mix>::vfunc_00 (0x006EEAF0, 36 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_00772718[];
extern "C" void __cdecl sub_006EC7B0(int);
extern "C" void __cdecl sub_006ECB50(void);

namespace audio { class Mix; }

namespace om { 
template <class T0> class MetaType
{
public:
    virtual MetaType<audio::Mix>* vfunc_00(int a1);
};
}

template <> om::MetaType<audio::Mix>* om::MetaType<audio::Mix>::vfunc_00(int a1)
{
    *(int*)this = (int)DAT_00772718;
    sub_006ECB50();
    if (a1 & 1) {
        sub_006EC7B0((int)this);
    }
    return this;
}

// ============================================================================
// [VERIFIED] om::EntityType<audio::Mix>::vfunc_03 (0x006EEBF0, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as om::EntityType<audio::Mix>::vfunc_03 (0x002D0FD0), which was matched first;
// its addresses and names were swapped for this function's.
// om::EntityType<audio::Mix>::vfunc_03 (0x006EEBF0, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_007C1624[];

namespace audio { class Mix; }

namespace om { 
template <class T0> class EntityType
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void* vfunc_03();
};
}

template <> void* om::EntityType<audio::Mix>::vfunc_03()
{
    return DAT_007C1624;
}

// ============================================================================
// [VERIFIED] om::EntityType<audio::Mix>::vfunc_02 (0x006EEC00, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as om::EntityType<audio::Mix>::vfunc_02 (0x002D0FE0), which was matched first;
// its addresses and names were swapped for this function's.
// om::EntityType<audio::Mix>::vfunc_02 (0x006EEC00, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_0085CEDC;

namespace audio { class Mix; }

namespace om { 
template <class T0> class EntityType
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual int vfunc_02();
};
}

template <> int om::EntityType<audio::Mix>::vfunc_02()
{
    return DAT_0085CEDC;
}

// ============================================================================
// [VERIFIED] om::EntityType<audio::Mix>::vfunc_01 (0x006EEC10, 41 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as om::EntityType<audio::Mix>::vfunc_01 (0x002D0FF0), which was matched first;
// its addresses and names were swapped for this function's.
// om::EntityType<audio::Mix>::vfunc_01 (0x006EEC10, 41 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    int sub_006F6020(int);
};

extern "C" int DAT_00811DA8;
extern "C" int __cdecl sub_006EE870(int);

namespace audio { class Mix; }

namespace om { 
template <class T0> class EntityType
{
public:
    virtual void vfunc_00();
    virtual int vfunc_01(int a1);
};
}

template <> int om::EntityType<audio::Mix>::vfunc_01(int a1)
{
    int r_eax;

    r_eax = DAT_00811DA8;
    if (r_eax) {
        r_eax += 4;
    } else {
        r_eax = 0;
    }
    r_eax = sub_006EE870(r_eax);
    if (r_eax) {
        return ((Object*)r_eax)->sub_006F6020(a1);
    }
    r_eax = 0;
    return r_eax;
}

// ============================================================================
// [VERIFIED] om::EntityType<audio::Mix>::vfunc_00 (0x006F67D0, 30 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as FightTree::FightActionController<fight::EnterExitScriptTrack>::vfunc_03 (0x000227A0), which was matched first;
// its addresses and names were swapped for this function's.
// om::EntityType<audio::Mix>::vfunc_00 (0x006F67D0, 30 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __cdecl sub_006ED0A0(void);
extern "C" void __cdecl sub_0043CE70(int);

namespace audio { class Mix; }

namespace om { 
template <class T0> class EntityType
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual EntityType<audio::Mix>* vfunc_00(int a1);
};
}

template <> om::EntityType<audio::Mix>* om::EntityType<audio::Mix>::vfunc_00(int a1)
{
    sub_006ED0A0();
    if (a1 & 1) {
        sub_0043CE70((int)this);
    }
    return this;
}

