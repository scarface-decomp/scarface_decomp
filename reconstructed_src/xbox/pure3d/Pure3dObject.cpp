// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail Xbox default.xbe, pure3d/Pure3dObject.cpp (4 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 4 of 8 functions matched (50.00%). NOT COMPLETE YET.
// The 4 still to do are listed in their place in Original_Binary_Order_Xbox.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] pure3d::frontend::Pure3dObject::vfunc_15 (0x0024A370, 20 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as pure3d::frontend::Pure3dObject::vfunc_15 (Proto 0x00207B00), which was matched first;
// its addresses and names were swapped for this function's.
// pure3d::frontend::Pure3dObject::vfunc_15 (Proto 0x0024A370, 20 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field48
{
    void sub_00242EB0();
};

namespace pure3d { namespace frontend {

class Pure3dObject
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
    char m_pad04[0x44];
    Field48 m_Field48; // +0x48
    char m_pad49[0x4B];
    unsigned char m_Field94; // +0x94
};

void Pure3dObject::vfunc_15()
{
    m_Field48.sub_00242EB0();
    m_Field94 &= 247;
}

} }

// ============================================================================
// [VERIFIED] pure3d::frontend::Pure3dObject::vfunc_12 (0x0024A470, 5 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as pure3d::frontend::Pure3dObject::vfunc_12 (Proto 0x00207C70), which was matched first;
// its addresses and names were swapped for this function's.
// pure3d::frontend::Pure3dObject::vfunc_12 (Proto 0x0024A470, 5 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

namespace pure3d { namespace frontend {

class Pure3dObject
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
};

void Pure3dObject::vfunc_12()
{
    vfunc_11();
}

} }

// ============================================================================
// [VERIFIED] pure3d::frontend::Pure3dObject::vfunc_14 (0x0024A530, 10 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as pure3d::frontend::Pure3dObject::vfunc_14 (Proto 0x00207CE0), which was matched first;
// its addresses and names were swapped for this function's.
// pure3d::frontend::Pure3dObject::vfunc_14 (Proto 0x0024A530, 10 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __stdcall sub_00248B30(int);

namespace pure3d { namespace frontend {

class Pure3dObject
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
    char m_pad04[0x40];
    int m_Field44; // +0x44
};

void Pure3dObject::vfunc_14()
{
    sub_00248B30(m_Field44);
}

} }

// ============================================================================
// [VERIFIED] pure3d::frontend::Pure3dObject::vfunc_03 (0x0024A800, 46 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// pure3d::frontend::Pure3dObject::vfunc_03 (0x0024A800, 46 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.
#pragma optimize("y", off)

extern "C" char DAT_003D5054[];
extern "C" void __cdecl sub_0023F7A0(int);
extern "C" void __cdecl sub_0024A700(void);

namespace pure3d { namespace frontend {

class Pure3dObject
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual Pure3dObject* vfunc_03(int a1);
    void sub_002489A0();
};

Pure3dObject* Pure3dObject::vfunc_03(int a1)
{
    *(int*)this = (int)DAT_003D5054;
    sub_0024A700();
    sub_002489A0();
    if (a1 & 1) {
        sub_0023F7A0((int)this);
    }
    return this;
}

} }

