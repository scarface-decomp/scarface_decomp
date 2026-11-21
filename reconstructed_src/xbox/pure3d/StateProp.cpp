// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail Xbox default.xbe, pure3d/StateProp.cpp (4 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 4 of 13 functions matched (30.77%). NOT COMPLETE YET.
// The 9 still to do are listed in their place in Original_Binary_Order_Xbox.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] pure3d::prop::StateProp::vfunc_16 (0x00280C00, 22 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as pure3d::prop::StateProp::vfunc_16 (Proto 0x0023C200), which was matched first;
// its addresses and names were swapped for this function's.
// pure3d::prop::StateProp::vfunc_16 (Proto 0x00280C00, 22 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field98
{
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
    virtual void vfunc_14();
    virtual void vfunc_15();
    virtual void vfunc_16();
};

namespace pure3d { namespace prop {

class StateProp
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
    virtual void vfunc_14();
    virtual void vfunc_15();
    virtual void vfunc_16();
    void sub_00280730();
    char m_pad04[0x94];
    Field98* m_Field98; // +0x98
};

void StateProp::vfunc_16()
{
    m_Field98->vfunc_16();
    sub_00280730();
}

} }

// ============================================================================
// [VERIFIED] pure3d::prop::StateProp::vfunc_05 (0x00281330, 34 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// pure3d::prop::StateProp::vfunc_05 (0x00281330, 34 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    int sub_002810D0(int);
};

extern "C" int __cdecl sub_0023F760(int);

namespace pure3d { namespace prop {

class StateProp
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual int vfunc_05();
};

int StateProp::vfunc_05()
{
    int t1;

    t1 = sub_0023F760(304);
    if (t1) {
        return ((Object*)t1)->sub_002810D0((int)this);
    }
    return 0;
}

} }

// ============================================================================
// [VERIFIED] pure3d::prop::StateProp::vfunc_03 (0x00281910, 33 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as pure3d::frontend::Text::vfunc_03 (0x00249C40), which was matched first;
// its addresses and names were swapped for this function's.
// bin: xb
// va: 0x00281910
// what: Deleting destructor: runs the destructor, then frees the object when asked to.
// tool: Claude Opus 5.5 (byte copy of the matched 0x0023B160 with its own addresses, examiner A6: pure3d::prop::StateProp::vfunc_03)

extern "C" void __cdecl sub_0023F7A0(void* p);

class Class_00281910
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual Class_00281910* sub_00281910(unsigned int flags);
    void sub_00281280();
};

#pragma optimize("y", off)
Class_00281910* Class_00281910::sub_00281910(unsigned int flags)
{
    sub_00281280();
    if (flags & 1)
        sub_0023F7A0(this);
    return this;
}
#pragma optimize("", on)

// ============================================================================
// [VERIFIED] pure3d::prop::StateProp::vfunc_11 (0x00281C60, 23 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as pure3d::prop::StateProp::vfunc_11 (Proto 0x0023D260), which was matched first;
// its addresses and names were swapped for this function's.
// pure3d::prop::StateProp::vfunc_11 (Proto 0x00281C60, 23 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __stdcall sub_00281C00(int);

namespace pure3d { namespace prop {

class StateProp
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
    virtual void vfunc_08(int, int);
    virtual void vfunc_09();
    virtual void vfunc_10();
    virtual void vfunc_11();
};

void StateProp::vfunc_11()
{
    sub_00281C00(0);
    vfunc_08(0, 0);
}

} }

