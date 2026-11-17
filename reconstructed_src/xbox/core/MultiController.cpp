// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail Xbox default.xbe, core/MultiController.cpp (8 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 8 of 17 functions matched (47.06%). NOT COMPLETE YET.
// The 9 still to do are listed in their place in Original_Binary_Order_Xbox.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] pure3d::MultiController::vfunc_08 (0x00272240, 31 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// pure3d::MultiController::vfunc_08 (0x00272240, 31 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.
#pragma optimize("y", off)

namespace pure3d {

class MultiController
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
    virtual void vfunc_08(float a1, bool a2);
    char m_pad04[0xC];
    float m_Field10; // +0x10
    char m_pad14[0x4];
    float m_Field18; // +0x18
};

void MultiController::vfunc_08(float a1, bool a2)
{
    int r_eax;

    r_eax = a2;
    m_Field10 = (a1 * m_Field18) + m_Field10;
    if (a2 == 1) {
        r_eax = *(int*)this;
        r_eax = ((int (__cdecl*)(void))*(int*)(r_eax + 36))();
    }
}

}

// ============================================================================
// [VERIFIED] pure3d::MultiController::vfunc_10 (0x00272260, 13 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// pure3d::MultiController::vfunc_10 (0x00272260, 13 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.
#pragma optimize("y", off)

namespace pure3d {

class MultiController
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
    virtual int vfunc_10(int a1);
    char m_pad04[0x14];
    int m_Field18; // +0x18
};

int MultiController::vfunc_10(int a1)
{
    m_Field18 = a1;
    return a1;
}

}

// ============================================================================
// [VERIFIED] pure3d::MultiController::vfunc_13 (0x00272290, 4 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as pure3d::MultiController::vfunc_13 (Proto 0x000D58F0), which was matched first;
// its addresses and names were swapped for this function's.
// pure3d::MultiController::vfunc_13 (Proto 0x00272290, 4 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

namespace pure3d {

class MultiController
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
    virtual float vfunc_13();
    char m_pad04[0x24];
    float m_Field28; // +0x28
};

float MultiController::vfunc_13()
{
    return m_Field28;
}

}

// ============================================================================
// [VERIFIED] pure3d::MultiController::vfunc_17 (0x002722A0, 29 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// pure3d::MultiController::vfunc_17 (0x002722A0, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.
#pragma optimize("y", off)

namespace pure3d {

class MultiController
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
    virtual int vfunc_17(int a1, int a2);
    char m_pad04[0x10];
    float m_Field14; // +0x14
    char m_pad18[0x8];
    float m_Field20; // +0x20
    float m_Field24; // +0x24
};

int MultiController::vfunc_17(int a1, int a2)
{
    *(float*)a1 = m_Field20 * m_Field14;
    *(float*)a2 = m_Field24 * m_Field14;
    return a1;
}

}

// ============================================================================
// [VERIFIED] pure3d::MultiController::vfunc_19 (0x002722C0, 4 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as pure3d::MultiController::vfunc_19 (Proto 0x00242680), which was matched first;
// its addresses and names were swapped for this function's.
// pure3d::MultiController::vfunc_19 (Proto 0x002722C0, 4 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

namespace pure3d {

class MultiController
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
    virtual int vfunc_19();
    char m_pad04[0x30];
    int m_Field34; // +0x34
};

int MultiController::vfunc_19()
{
    return m_Field34;
}

}

// ============================================================================
// [VERIFIED] pure3d::MultiController::vfunc_23 (0x00272310, 4 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as pure3d::MultiController::vfunc_23 (Proto 0x000D5910), which was matched first;
// its addresses and names were swapped for this function's.
// pure3d::MultiController::vfunc_23 (Proto 0x00272310, 4 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

namespace pure3d {

class MultiController
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
    virtual float vfunc_23();
    char m_pad04[0x28];
    float m_Field2C; // +0x2C
};

float MultiController::vfunc_23()
{
    return m_Field2C;
}

}

// ============================================================================
// [VERIFIED] pure3d::MultiController::vfunc_05 (0x00272D40, 31 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as pure3d::MultiController::vfunc_05 (Proto 0x00224AA0), which was matched first;
// its addresses and names were swapped for this function's.
// pure3d::MultiController::vfunc_05 (Proto 0x00272D40, 31 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    int sub_00272BE0(int);
};

extern "C" int __cdecl sub_0023F760(int);

namespace pure3d {

class MultiController
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual int vfunc_05();
};

int MultiController::vfunc_05()
{
    int t1;

    t1 = sub_0023F760(76);
    if (t1) {
        return ((Object*)t1)->sub_00272BE0((int)this);
    }
    return 0;
}

}

// ============================================================================
// [VERIFIED] pure3d::MultiController::vfunc_03 (0x00272D60, 33 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as fight::Branch::vfunc_03 (0x0023B160), which was matched first;
// its addresses and names were swapped for this function's.
extern "C" void __cdecl sub_0023F7A0(void* p);

namespace pure3d {

class MultiController
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual MultiController* vfunc_03(unsigned int flags);
    void sub_00272CF0();
};

#pragma optimize("y", off)
MultiController* MultiController::vfunc_03(unsigned int flags)
{
    sub_00272CF0();
    if (flags & 1)
        sub_0023F7A0(this);
    return this;
}
#pragma optimize("", on)

}

