// ============================================================================
// SCARFACE: THE WORLD IS YOURS — April 2006 prototype game.xbe, om/String_.cpp (2 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 2 of 13 functions matched (15.38%). NOT COMPLETE YET.
// The 11 still to do are listed in their place in Original_Binary_Order_Proto.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] om::MetaAttribScalar<om::String>::vfunc_05 (0x000782B0, 19 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as om::MetaAttribScalar<om::String>::vfunc_03 (0x00083940), which was matched first;
// its addresses and names were swapped for this function's.
// om::MetaAttribScalar<om::String>::vfunc_05 (0x000782B0, 19 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_00291180(int);
};

namespace om { class String; }

namespace om { 
template <class T0> class MetaAttribScalar
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_05(int a1);
    char m_pad04[0x10];
    int m_Field14; // +0x14
    char m_pad18[0x1C];
    int m_Field34; // +0x34
};
}

template <> void om::MetaAttribScalar<om::String>::vfunc_05(int a1)
{
    ((Object*)m_Field14 + a1)->sub_00291180((int)(&m_Field34));
}

// ============================================================================
// [VERIFIED] om::MetaAttrib<om::String>::vfunc_00 (0x00078A90, 31 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// om::MetaAttrib<om::String>::vfunc_00 (Proto 0x00078A90, 31 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_00382D14[];
extern "C" void __cdecl sub_00078AB0(int);

namespace om { class String; }

namespace om { 
template <class T0> class MetaAttrib
{
public:
    virtual MetaAttrib<om::String>* vfunc_00(int a1);
};
}

template <> om::MetaAttrib<om::String>* om::MetaAttrib<om::String>::vfunc_00(int a1)
{
    *(int*)this = (int)DAT_00382D14;
    if (a1 & 1) {
        sub_00078AB0((int)this);
    }
    return this;
}

