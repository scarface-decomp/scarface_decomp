// ============================================================================
// SCARFACE: THE WORLD IS YOURS — April 2006 prototype game.xbe, om/Sequence_.cpp (4 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: COMPLETE. All 4 functions are matched.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] om::MetaType<audio::Sequence>::vfunc_00 (0x00294C50, 36 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as om::MetaType<audio::SeqEvent>::vfunc_00 (0x002D0EA0), which was matched first;
// its addresses and names were swapped for this function's.
// om::MetaType<audio::Sequence>::vfunc_00 (0x00294C50, 36 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_003B942C[];
extern "C" void __cdecl sub_00291D80(int);
extern "C" void __cdecl sub_00292750(void);

namespace audio { class Sequence; }

namespace om { 
template <class T0> class MetaType
{
public:
    virtual MetaType<audio::Sequence>* vfunc_00(int a1);
};
}

template <> om::MetaType<audio::Sequence>* om::MetaType<audio::Sequence>::vfunc_00(int a1)
{
    *(int*)this = (int)DAT_003B942C;
    sub_00292750();
    if (a1 & 1) {
        sub_00291D80((int)this);
    }
    return this;
}

// ============================================================================
// [VERIFIED] om::EntityType<audio::Sequence>::vfunc_03 (0x00294EE0, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as om::EntityType<audio::Mix>::vfunc_03 (0x002D0FD0), which was matched first;
// its addresses and names were swapped for this function's.
// om::EntityType<audio::Sequence>::vfunc_03 (0x00294EE0, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_003F94A4[];

namespace audio { class Sequence; }

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

template <> void* om::EntityType<audio::Sequence>::vfunc_03()
{
    return DAT_003F94A4;
}

// ============================================================================
// [VERIFIED] om::EntityType<audio::Sequence>::vfunc_02 (0x00294EF0, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as om::EntityType<audio::Mix>::vfunc_02 (0x002D0FE0), which was matched first;
// its addresses and names were swapped for this function's.
// om::EntityType<audio::Sequence>::vfunc_02 (0x00294EF0, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_00490C28;

namespace audio { class Sequence; }

namespace om { 
template <class T0> class EntityType
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual int vfunc_02();
};
}

template <> int om::EntityType<audio::Sequence>::vfunc_02()
{
    return DAT_00490C28;
}

// ============================================================================
// [VERIFIED] om::EntityType<audio::Sequence>::vfunc_01 (0x00294F20, 41 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as om::EntityType<audio::Mix>::vfunc_01 (0x002D0FF0), which was matched first;
// its addresses and names were swapped for this function's.
// om::EntityType<audio::Sequence>::vfunc_01 (0x00294F20, 41 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    int sub_00293FF0(int);
};

extern "C" int DAT_0044AE9C;
extern "C" int __cdecl sub_00293590(int);

namespace audio { class Sequence; }

namespace om { 
template <class T0> class EntityType
{
public:
    virtual void vfunc_00();
    virtual int vfunc_01(int a1);
};
}

template <> int om::EntityType<audio::Sequence>::vfunc_01(int a1)
{
    int r_eax;

    r_eax = DAT_0044AE9C;
    if (r_eax) {
        r_eax += 4;
    } else {
        r_eax = 0;
    }
    r_eax = sub_00293590(r_eax);
    if (r_eax) {
        return ((Object*)r_eax)->sub_00293FF0(a1);
    }
    r_eax = 0;
    return r_eax;
}

