// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail Xbox default.xbe, om/AllocatorNew__.cpp (2 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 2 of 12 functions matched (16.67%). NOT COMPLETE YET.
// The 10 still to do are listed in their place in Original_Binary_Order_Xbox.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] om::MetaAttribScalar<container::ArrayDynamic<unsigned short, container::AllocatorNew>>::vfunc_03 (0x00083F40, 19 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// om::MetaAttribScalar<container::ArrayDynamic<unsigned short, container::AllocatorNew>>::vfunc_03 (0x00083F40, 19 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_00083F60(int);
};

namespace om {

class MetaAttribScalar_container__ArrayDynamic_unsigned_short__container__AllocatorNew__
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03(int a1);
    char m_pad04[0x10];
    int m_Field14; // +0x14
    char m_pad18[0x24];
    int m_Field3C; // +0x3C
};

void MetaAttribScalar_container__ArrayDynamic_unsigned_short__container__AllocatorNew__::vfunc_03(int a1)
{
    ((Object*)m_Field14 + a1)->sub_00083F60((int)(&m_Field3C));
}

}

// ============================================================================
// [VERIFIED] om::MetaAttribScalar<container::ArrayDynamic<om::String, container::AllocatorNew>>::vfunc_03 (0x00084060, 19 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// om::MetaAttribScalar<container::ArrayDynamic<om::String, container::AllocatorNew>>::vfunc_03 (0x00084060, 19 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_00084080(int);
};

namespace om {

class MetaAttribScalar_container__ArrayDynamic_om__String__container__AllocatorNew__
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03(int a1);
    char m_pad04[0x10];
    int m_Field14; // +0x14
    char m_pad18[0x24];
    int m_Field3C; // +0x3C
};

void MetaAttribScalar_container__ArrayDynamic_om__String__container__AllocatorNew__::vfunc_03(int a1)
{
    ((Object*)m_Field14 + a1)->sub_00084080((int)(&m_Field3C));
}

}

