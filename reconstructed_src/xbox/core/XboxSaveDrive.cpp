// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail Xbox default.xbe, core/XboxSaveDrive.cpp (11 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 11 of 21 functions matched (52.38%). NOT COMPLETE YET.
// The 10 still to do are listed in their place in Original_Binary_Order_Xbox.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] core::XboxSaveDrive::vfunc_00 (0x002BF800, 12 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as core::File::vfunc_00 (0x002AAF50), which was matched first;
// its addresses and names were swapped for this function's.
// core::XboxSaveDrive::vfunc_00 (0x002BF800, 12 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_004BFE18[];
extern "C" void __cdecl sub_00283B80(int);

namespace core {

class XboxSaveDrive
{
public:
    virtual void vfunc_00();
};

void XboxSaveDrive::vfunc_00()
{
    sub_00283B80((int)DAT_004BFE18);
}

}

// ============================================================================
// [VERIFIED] core::XboxSaveDrive::vfunc_01 (0x002BF810, 12 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as core::File::vfunc_00 (0x002AAF50), which was matched first;
// its addresses and names were swapped for this function's.
// core::XboxSaveDrive::vfunc_01 (0x002BF810, 12 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_004BFE18[];
extern "C" void __cdecl sub_00283B70(int);

namespace core {

class XboxSaveDrive
{
public:
    virtual void vfunc_01();
};

void XboxSaveDrive::vfunc_01()
{
    sub_00283B70((int)DAT_004BFE18);
}

}

// ============================================================================
// [VERIFIED] core::XboxSaveDrive::vfunc_05 (0x002BF830, 7 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as core::XboxSaveDrive::vfunc_05 (Proto 0x002834A0), which was matched first;
// its addresses and names were swapped for this function's.
// core::XboxSaveDrive::vfunc_05 (Proto 0x002BF830, 7 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

namespace core {

class XboxSaveDrive
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual void* vfunc_05();
    char m_pad04[0xE4];
    int m_FieldE8; // +0xE8
};

void* XboxSaveDrive::vfunc_05()
{
    return &m_FieldE8;
}

}

// ============================================================================
// [VERIFIED] core::XboxSaveDrive::vfunc_12 (0x002BF840, 61 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as core::XboxSaveDrive::vfunc_12 (Proto 0x002834B0), which was matched first;
// its addresses and names were swapped for this function's.
// core::XboxSaveDrive::vfunc_12 (Proto 0x002BF840, 61 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_004BFE3C;
extern "C" int DAT_004BFE44;
extern "C" void __stdcall sub_00233A9F(int);

namespace core {

class XboxSaveDrive
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
    virtual int vfunc_12(int a1, int a2);
    virtual void vfunc_13(int, int);
    char m_pad04[0xE0];
    int m_FieldE4; // +0xE4
};

int XboxSaveDrive::vfunc_12(int a1, int a2)
{
    vfunc_13(a1, a2);
    if (DAT_004BFE3C == a1) {
        DAT_004BFE44 = 0;
    }
    sub_00233A9F(a1);
    m_FieldE4 -= 1;
    return 1;
}

}

// ============================================================================
// [VERIFIED] core::XboxSaveDrive::vfunc_01 (0x002BF880, 6 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// What it does: core::XboxSaveDrive: Always returns 8172.
// ============================================================================
// Same machine code as core::XboxSaveDrive::vfunc_01 (Proto 0x00283500), which was matched first;
// its addresses and names were swapped for this function's.
// core::XboxSaveDrive::vfunc_01 (Proto 0x002BF880, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

namespace core {

class XboxSaveDrive
{
public:
    virtual void vfunc_00();
    virtual int vfunc_01();
};

int XboxSaveDrive::vfunc_01()
{
    return 8172;
}

}

// ============================================================================
// [VERIFIED] core::XboxSaveDrive::vfunc_02 (0x002BF890, 8 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// What it does: core::XboxSaveDrive: Always returns 4.
// ============================================================================
// Same machine code as core::XboxSaveDrive::vfunc_02 (Proto 0x002834F0), which was matched first;
// its addresses and names were swapped for this function's.
// core::XboxSaveDrive::vfunc_02 (Proto 0x002BF890, 8 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

namespace core {

class XboxSaveDrive
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual int vfunc_02(int a1);
};

int XboxSaveDrive::vfunc_02(int a1)
{
    return 4;
}

}

// ============================================================================
// [VERIFIED] core::XboxSaveDrive::vfunc_15 (0x002BFD10, 31 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as core::XboxSaveDrive::vfunc_15 (Proto 0x00283980), which was matched first;
// its addresses and names were swapped for this function's.
// bin: proto
// va: 0x002BFD10
// what: 
// tool: the portal's starter code (no AI)

// core::XboxSaveDrive::vfunc_15 (Proto 0x002BFD10, 31 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    int sub_002CC250(int, int, int);
};

namespace core {

class XboxSaveDrive
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
    virtual int vfunc_15(int a1, int a2, int a3);
};

int XboxSaveDrive::vfunc_15(int a1, int a2, int a3)
{
    a3 = a2;
    a2 = a1;
    a1 = (int)this;
    return ((Object*)(int)this + 220)->sub_002CC250(a1, a2, a3);
}

}

// ============================================================================
// [VERIFIED] core::XboxSaveDrive::vfunc_00 (0x002BFD30, 8 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as core::ControllerSystemXBox::vfunc_00 (0x00248810), which was matched first;
// its addresses and names were swapped for this function's.
// core::XboxSaveDrive::vfunc_00 (0x002BFD30, 8 bytes)
// An adjustor thunk. Nobody wrote this function: the compiler adds it for a class with two base
// classes that both declare the same virtual function. Called through the second base's table, it
// moves `this` back 4 bytes to the start of the object and jumps to the real function at
// 0x002C00D0. So it is matched by declaring the class that way, not by writing a body.
// The two bases and their names are guesses; the first base is the part of the object in front
// of the second base (4 bytes).

namespace core {
class ControllerSystemXBox_Base0 { public: virtual void sub_002C00D0(); };
class ControllerSystemXBox_Base1 { public: virtual void sub_002C00D0(); };

class XboxSaveDrive : public ControllerSystemXBox_Base0, public ControllerSystemXBox_Base1
{
public:
    XboxSaveDrive();
    virtual void sub_002C00D0();          // the real function; the thunk jumps here
};

XboxSaveDrive::XboxSaveDrive() {}                  // building one is what makes the compiler write its tables and the thunk
}

// ============================================================================
// [VERIFIED] core::XboxSaveDrive::vfunc_02 (0x002BFD40, 8 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as core::Drive::vfunc_02 (Proto 0x0026EEC0), which was matched first;
// its addresses and names were swapped for this function's.
// core::XboxSaveDrive::vfunc_02 (Proto 0x002BFD40, 8 bytes)
// An adjustor thunk. Nobody wrote this function: the compiler adds it for a class with two base
// classes that both declare the same virtual function. Called through the second base's table, it
// moves `this` back 12 bytes to the start of the object and jumps to the real function at
// 0x002C00D0. So it is matched by declaring the class that way, not by writing a body.
// The two bases and their names are guesses; the first base is the part of the object in front
// of the second base (12 bytes).

namespace core {
class Drive_Base0 { public: virtual void sub_002C00D0(); char m_pad04[0x8]; };
class Drive_Base1 { public: virtual void sub_002C00D0(); };

class XboxSaveDrive : public Drive_Base0, public Drive_Base1
{
public:
    XboxSaveDrive();
    virtual void sub_002C00D0();          // the real function; the thunk jumps here
};

XboxSaveDrive::XboxSaveDrive() {}                  // building one is what makes the compiler write its tables and the thunk
}

// ============================================================================
// [VERIFIED] core::XboxSaveDrive::vfunc_22 (0x002BFD50, 63 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as core::XboxSaveDrive::vfunc_22 (Proto 0x002839C0), which was matched first;
// its addresses and names were swapped for this function's.
// core::XboxSaveDrive::vfunc_22 (Proto 0x002BFD50, 63 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __stdcall sub_0030A4EB(int);

namespace core {

class XboxSaveDrive
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
    virtual int vfunc_22(int a1);
};

int XboxSaveDrive::vfunc_22(int a1)
{
    int t1;

    t1 = *(int*)((*(int*)a1 * 520) + (int)this + 784);
    if (*(int*)((*(int*)a1 * 520) + (int)this + 784) != -1) {
        sub_0030A4EB(t1);
        *(int*)((*(int*)a1 * 520) + (int)this + 784) = -1;
    }
    return 1;
}

}

// ============================================================================
// [VERIFIED] core::XboxSaveDrive::vfunc_03 (0x002C00D0, 36 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// What it does: core::XboxSaveDrive's deleting destructor: destroys the object, frees its memory when asked (flag bit 0), and returns it.
// ============================================================================
// Same machine code as core::ControllerSystemXBox::vfunc_03 (0x00248820), which was matched first;
// its addresses and names were swapped for this function's.
// core::XboxSaveDrive::vfunc_03 (0x002C00D0, 36 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_0045894C;
extern "C" void __cdecl sub_002444F0(int, int);
extern "C" void __cdecl sub_002BFD90(void);

namespace core {

class XboxSaveDrive
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual XboxSaveDrive* vfunc_03(int a1);
};

XboxSaveDrive* XboxSaveDrive::vfunc_03(int a1)
{
    sub_002BFD90();
    if (a1 & 1) {
        sub_002444F0(DAT_0045894C, (int)this);
    }
    return this;
}

}

