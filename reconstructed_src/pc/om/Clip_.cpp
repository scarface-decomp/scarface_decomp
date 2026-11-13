// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail PC Scarface.exe v1.00.2, om/Clip_.cpp (3 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 3 of 4 functions matched (75.00%). NOT COMPLETE YET.
// The 1 still to do are listed in their place in Original_Binary_Order_PC_1002.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] om::MetaType<audio::Clip>::vfunc_00 (0x006EEB20, 36 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as om::MetaType<audio::SeqEvent>::vfunc_00 (0x002D0EA0), which was matched first;
// its addresses and names were swapped for this function's.
// om::MetaType<audio::Clip>::vfunc_00 (0x006EEB20, 36 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_00772728[];
extern "C" void __cdecl sub_006EC7B0(int);
extern "C" void __cdecl sub_006ECB50(void);

namespace audio { class Clip; }

namespace om { 
template <class T0> class MetaType
{
public:
    virtual MetaType<audio::Clip>* vfunc_00(int a1);
};
}

template <> om::MetaType<audio::Clip>* om::MetaType<audio::Clip>::vfunc_00(int a1)
{
    *(int*)this = (int)DAT_00772728;
    sub_006ECB50();
    if (a1 & 1) {
        sub_006EC7B0((int)this);
    }
    return this;
}

// ============================================================================
// [VERIFIED] om::EntityType<audio::Clip>::vfunc_03 (0x006EECB0, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as om::EntityType<audio::Mix>::vfunc_03 (0x002D0FD0), which was matched first;
// its addresses and names were swapped for this function's.
// om::EntityType<audio::Clip>::vfunc_03 (0x006EECB0, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_007C6038[];

namespace audio { class Clip; }

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

template <> void* om::EntityType<audio::Clip>::vfunc_03()
{
    return DAT_007C6038;
}

// ============================================================================
// [VERIFIED] om::EntityType<audio::Clip>::vfunc_02 (0x006EECC0, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as om::EntityType<audio::Mix>::vfunc_02 (0x002D0FE0), which was matched first;
// its addresses and names were swapped for this function's.
// om::EntityType<audio::Clip>::vfunc_02 (0x006EECC0, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_0085CEE0;

namespace audio { class Clip; }

namespace om { 
template <class T0> class EntityType
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual int vfunc_02();
};
}

template <> int om::EntityType<audio::Clip>::vfunc_02()
{
    return DAT_0085CEE0;
}

