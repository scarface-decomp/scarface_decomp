// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail Xbox default.xbe, pure3d/Drawable.cpp (3 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 3 of 4 functions matched (75.00%). NOT COMPLETE YET.
// The 1 still to do are listed in their place in Original_Binary_Order_Xbox.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] pure3d::frontend::Drawable::vfunc_10 (0x00248990, 5 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as pure3d::frontend::Drawable::vfunc_10 (Proto 0x00205D50), which was matched first;
// its addresses and names were swapped for this function's.
// pure3d::frontend::Drawable::vfunc_10 (Proto 0x00248990, 5 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

namespace pure3d { namespace frontend {

class Drawable
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual void vfunc_05();
    virtual void vfunc_06();
    virtual void vfunc_07();
    virtual void vfunc_08();
    virtual void vfunc_09();
    virtual int vfunc_10();
    char m_pad04[0xC];
    unsigned char m_Field10; // +0x10
};

int Drawable::vfunc_10()
{
    return m_Field10;
}

} }

// ============================================================================
// [VERIFIED] pure3d::frontend::Drawable::vfunc_14 (0x00248B20, 9 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as pure3d::frontend::Drawable::vfunc_14 (Proto 0x00205F20), which was matched first;
// its addresses and names were swapped for this function's.
// pure3d::frontend::Drawable::vfunc_14 (Proto 0x00248B20, 9 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

namespace pure3d { namespace frontend {

class Drawable
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual void vfunc_05();
    virtual void vfunc_06();
    virtual void vfunc_07();
    virtual void vfunc_08();
    virtual void vfunc_09();
    virtual void vfunc_10();
    virtual void vfunc_11();
    virtual void vfunc_12();
    virtual void vfunc_13();
    virtual int vfunc_14();
    char m_pad04[0x1C];
    int m_Field20; // +0x20
    int m_Field24; // +0x24
};

int Drawable::vfunc_14()
{
    m_Field20 = 0;
    m_Field24 = 0;
    return 0;
}

} }

// ============================================================================
// [VERIFIED] pure3d::frontend::Drawable::vfunc_03 (0x00248C00, 39 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// What it does: Deleting destructor: puts back the class's vtable, runs the destructor, then frees the object when asked to.
// ============================================================================
// bin: xb
// va: 0x00248C00
// what: Deleting destructor: puts back the class's vtable, runs the destructor, then frees the object when asked to.
// tool: Claude Opus 5.5 (byte copy of the matched 0x00239CE0 with its own addresses, examiner A6: pure3d::frontend::Drawable::vfunc_03)

extern "C" char DAT_003D4F14[];
extern "C" void __cdecl sub_0023F7A0(void* p);

class Class_00248C00
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual Class_00248C00* sub_00248C00(unsigned int flags);
    void sub_0028D470();
};

#pragma optimize("y", off)
Class_00248C00* Class_00248C00::sub_00248C00(unsigned int flags)
{
    *(void**)this = DAT_003D4F14;
    sub_0028D470();
    if (flags & 1)
        sub_0023F7A0(this);
    return this;
}
#pragma optimize("", on)

