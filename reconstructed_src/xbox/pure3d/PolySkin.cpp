// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail Xbox default.xbe, pure3d/PolySkin.cpp (5 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 5 of 14 functions matched (35.71%). NOT COMPLETE YET.
// The 9 still to do are listed in their place in Original_Binary_Order_Xbox.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] pure3d::PolySkin::vfunc_17 (0x00277C40, 13 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// pure3d::PolySkin::vfunc_17 (0x00277C40, 13 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.
#pragma optimize("y", off)

namespace pure3d {

class PolySkin
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
    virtual bool vfunc_17(bool a1);
    char m_pad04[0x4C];
    bool m_Field50; // +0x50
};

bool PolySkin::vfunc_17(bool a1)
{
    m_Field50 = a1;
    return a1;
}

}

// ============================================================================
// [VERIFIED] pure3d::PolySkin::vfunc_18 (0x00277C50, 13 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// pure3d::PolySkin::vfunc_18 (0x00277C50, 13 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.
#pragma optimize("y", off)

namespace pure3d {

class PolySkin
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
    virtual void vfunc_17();
    virtual int vfunc_18(int a1);
    char m_pad04[0x50];
    int m_Field54; // +0x54
};

int PolySkin::vfunc_18(int a1)
{
    m_Field54 = a1;
    return a1;
}

}

// ============================================================================
// [VERIFIED] pure3d::PolySkin::vfunc_12 (0x00277E40, 41 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// pure3d::PolySkin::vfunc_12 (0x00277E40, 41 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.
#pragma optimize("y", off)

struct Object
{
    virtual void vfunc_00();
    virtual void vfunc_01();
};

namespace pure3d {

class PolySkin
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
    virtual void vfunc_12(int a1);
    char m_pad04[0x5C];
    int m_Field60; // +0x60
};

void PolySkin::vfunc_12(int a1)
{
    int r_edi, t2;

    r_edi = a1;
    if (a1) {
        ((Object*)r_edi)->vfunc_00();
    }
    t2 = m_Field60;
    if (m_Field60) {
        ((Object*)t2)->vfunc_01();
    }
    m_Field60 = r_edi;
}

}

// ============================================================================
// [VERIFIED] pure3d::PolySkin::vfunc_03 (0x00277F00, 33 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as fight::Branch::vfunc_03 (0x0023B160), which was matched first;
// its addresses and names were swapped for this function's.
extern "C" void __cdecl sub_0023F7A0(void* p);

namespace pure3d {

class PolySkin
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual PolySkin* vfunc_03(unsigned int flags);
    void sub_00277D90();
};

#pragma optimize("y", off)
PolySkin* PolySkin::vfunc_03(unsigned int flags)
{
    sub_00277D90();
    if (flags & 1)
        sub_0023F7A0(this);
    return this;
}
#pragma optimize("", on)

}

// ============================================================================
// [VERIFIED] pure3d::PolySkin::vfunc_30 (0x00278140, 44 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// pure3d::PolySkin::vfunc_30 (0x00278140, 44 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.
#pragma optimize("y", off)

struct Object
{
    int sub_00277F30(int, int);
};

extern "C" int __cdecl sub_0023F760(int);

namespace pure3d {

class PolySkin
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
    virtual void vfunc_17();
    virtual void vfunc_18();
    virtual void vfunc_19();
    virtual void vfunc_20();
    virtual void vfunc_21();
    virtual void vfunc_22();
    virtual void vfunc_23();
    virtual void vfunc_24();
    virtual void vfunc_25();
    virtual void vfunc_26();
    virtual void vfunc_27();
    virtual void vfunc_28();
    virtual void vfunc_29();
    virtual int vfunc_30(int a1);
};

int PolySkin::vfunc_30(int a1)
{
    int t1;

    t1 = sub_0023F760(112);
    if (t1) {
        return ((Object*)t1)->sub_00277F30((int)this, a1);
    }
    return 0;
}

}

