// ============================================================================
// SCARFACE: THE WORLD IS YOURS — April 2006 prototype game.xbe, core/XboxDrive.cpp (4 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 4 of 20 functions matched (20.00%). NOT COMPLETE YET.
// The 16 still to do are listed in their place in Original_Binary_Order_Proto.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] core::XboxDrive::vfunc_00 (0x00282800, 14 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as core::XboxDrive::vfunc_00 (0x002BEB90), which was matched first;
// its addresses and names were swapped for this function's.
// core::XboxDrive::vfunc_00 (0x00282800, 14 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __cdecl sub_0023F190(int);

namespace core {

class XboxDrive
{
public:
    virtual void vfunc_00();
    char m_pad04[0x1EC];
    int m_Field1F0; // +0x1F0
};

void XboxDrive::vfunc_00()
{
    sub_0023F190(m_Field1F0);
}

}

// ============================================================================
// [VERIFIED] core::XboxDrive::vfunc_01 (0x00282810, 14 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as core::XboxDrive::vfunc_00 (0x002BEB90), which was matched first;
// its addresses and names were swapped for this function's.
// core::XboxDrive::vfunc_01 (0x00282810, 14 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __cdecl sub_0023F180(int);

namespace core {

class XboxDrive
{
public:
    virtual void vfunc_01();
    char m_pad04[0x1EC];
    int m_Field1F0; // +0x1F0
};

void XboxDrive::vfunc_01()
{
    sub_0023F180(m_Field1F0);
}

}

// ============================================================================
// [VERIFIED] core::XboxDrive::vfunc_00 (0x00282AF0, 8 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as core::ControllerSystemXBox::vfunc_00 (0x00248810), which was matched first;
// its addresses and names were swapped for this function's.
// core::XboxDrive::vfunc_00 (0x00282AF0, 8 bytes)
// An adjustor thunk. Nobody wrote this function: the compiler adds it for a class with two base
// classes that both declare the same virtual function. Called through the second base's table, it
// moves `this` back 4 bytes to the start of the object and jumps to the real function at
// 0x00282D40. So it is matched by declaring the class that way, not by writing a body.
// The two bases and their names are guesses; the first base is the part of the object in front
// of the second base (4 bytes).

namespace core {
class ControllerSystemXBox_Base0 { public: virtual void sub_00282D40(); };
class ControllerSystemXBox_Base1 { public: virtual void sub_00282D40(); };

class XboxDrive : public ControllerSystemXBox_Base0, public ControllerSystemXBox_Base1
{
public:
    XboxDrive();
    virtual void sub_00282D40();          // the real function; the thunk jumps here
};

XboxDrive::XboxDrive() {}                  // building one is what makes the compiler write its tables and the thunk
}

// ============================================================================
// [VERIFIED] core::XboxDrive::vfunc_03 (0x00282D40, 36 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as core::ControllerSystemXBox::vfunc_03 (0x00248820), which was matched first;
// its addresses and names were swapped for this function's.
// core::XboxDrive::vfunc_03 (0x00282D40, 36 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_00429338;
extern "C" void __cdecl sub_00201990(int, int);
extern "C" void __cdecl sub_00282750(void);

namespace core {

class XboxDrive
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual XboxDrive* vfunc_03(int a1);
};

XboxDrive* XboxDrive::vfunc_03(int a1)
{
    sub_00282750();
    if (a1 & 1) {
        sub_00201990(DAT_00429338, (int)this);
    }
    return this;
}

}

