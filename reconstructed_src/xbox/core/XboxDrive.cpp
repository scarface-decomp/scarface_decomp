// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail Xbox default.xbe, core/XboxDrive.cpp (13 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 13 of 20 functions matched (65.00%). NOT COMPLETE YET.
// The 7 still to do are listed in their place in Original_Binary_Order_Xbox.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] core::XboxDrive::vfunc_23 (0x002BEB80, 11 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as core::XboxDrive::vfunc_23 (Proto 0x002827F0), which was matched first;
// its addresses and names were swapped for this function's.
// core::XboxDrive::vfunc_23 (Proto 0x002BEB80, 11 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_002CC0A0();
};

namespace core {

class XboxDrive
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
};

void XboxDrive::vfunc_23()
{
    ((Object*)(int)this + 216)->sub_002CC0A0();
}

}

// ============================================================================
// [VERIFIED] core::XboxDrive::vfunc_00 (0x002BEB90, 14 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// core::XboxDrive::vfunc_00 (0x002BEB90, 14 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __cdecl sub_00283B80(int);

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
    sub_00283B80(m_Field1F0);
}

}

// ============================================================================
// [VERIFIED] core::XboxDrive::vfunc_01 (0x002BEBA0, 14 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as core::XboxDrive::vfunc_00 (0x002BEB90), which was matched first;
// its addresses and names were swapped for this function's.
// core::XboxDrive::vfunc_01 (0x002BEBA0, 14 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __cdecl sub_00283B70(int);

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
    sub_00283B70(m_Field1F0);
}

}

// ============================================================================
// [VERIFIED] core::XboxDrive::vfunc_08 (0x002BEBB0, 7 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as core::XboxDrive::vfunc_08 (Proto 0x00282820), which was matched first;
// its addresses and names were swapped for this function's.
// core::XboxDrive::vfunc_08 (Proto 0x002BEBB0, 7 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

namespace core {

class XboxDrive
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
    virtual int vfunc_08();
    char m_pad04[0x1DC];
    int m_Field1E0; // +0x1E0
};

int XboxDrive::vfunc_08()
{
    return m_Field1E0;
}

}

// ============================================================================
// [VERIFIED] core::XboxDrive::vfunc_05 (0x002BEBC0, 7 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as core::XboxDrive::vfunc_05 (Proto 0x00282830), which was matched first;
// its addresses and names were swapped for this function's.
// core::XboxDrive::vfunc_05 (Proto 0x002BEBC0, 7 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

namespace core {

class XboxDrive
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual void* vfunc_05();
    char m_pad04[0x1E4];
    int m_Field1E8; // +0x1E8
};

void* XboxDrive::vfunc_05()
{
    return &m_Field1E8;
}

}

// ============================================================================
// [VERIFIED] core::XboxDrive::vfunc_12 (0x002BEBD0, 28 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as core::XboxDrive::vfunc_12 (Proto 0x00282840), which was matched first;
// its addresses and names were swapped for this function's.
// core::XboxDrive::vfunc_12 (Proto 0x002BEBD0, 28 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __stdcall sub_00233A9F(int);

namespace core {

class XboxDrive
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
    char m_pad04[0x1E0];
    int m_Field1E4; // +0x1E4
};

int XboxDrive::vfunc_12(int a1, int a2)
{
    sub_00233A9F(a1);
    m_Field1E4 -= 1;
    return 1;
}

}

// ============================================================================
// [VERIFIED] core::XboxDrive::vfunc_00 (0x002BEE80, 8 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as core::ControllerSystemXBox::vfunc_00 (0x00248810), which was matched first;
// its addresses and names were swapped for this function's.
// core::XboxDrive::vfunc_00 (0x002BEE80, 8 bytes)
// An adjustor thunk. Nobody wrote this function: the compiler adds it for a class with two base
// classes that both declare the same virtual function. Called through the second base's table, it
// moves `this` back 4 bytes to the start of the object and jumps to the real function at
// 0x002BF0D0. So it is matched by declaring the class that way, not by writing a body.
// The two bases and their names are guesses; the first base is the part of the object in front
// of the second base (4 bytes).

namespace core {
class ControllerSystemXBox_Base0 { public: virtual void sub_002BF0D0(); };
class ControllerSystemXBox_Base1 { public: virtual void sub_002BF0D0(); };

class XboxDrive : public ControllerSystemXBox_Base0, public ControllerSystemXBox_Base1
{
public:
    XboxDrive();
    virtual void sub_002BF0D0();          // the real function; the thunk jumps here
};

XboxDrive::XboxDrive() {}                  // building one is what makes the compiler write its tables and the thunk
}

// ============================================================================
// [VERIFIED] core::XboxDrive::vfunc_02 (0x002BEE90, 8 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as core::Drive::vfunc_02 (Proto 0x0026EEC0), which was matched first;
// its addresses and names were swapped for this function's.
// core::XboxDrive::vfunc_02 (Proto 0x002BEE90, 8 bytes)
// An adjustor thunk. Nobody wrote this function: the compiler adds it for a class with two base
// classes that both declare the same virtual function. Called through the second base's table, it
// moves `this` back 12 bytes to the start of the object and jumps to the real function at
// 0x002BF0D0. So it is matched by declaring the class that way, not by writing a body.
// The two bases and their names are guesses; the first base is the part of the object in front
// of the second base (12 bytes).

namespace core {
class Drive_Base0 { public: virtual void sub_002BF0D0(); char m_pad04[0x8]; };
class Drive_Base1 { public: virtual void sub_002BF0D0(); };

class XboxDrive : public Drive_Base0, public Drive_Base1
{
public:
    XboxDrive();
    virtual void sub_002BF0D0();          // the real function; the thunk jumps here
};

XboxDrive::XboxDrive() {}                  // building one is what makes the compiler write its tables and the thunk
}

// ============================================================================
// [VERIFIED] core::XboxDrive::vfunc_22 (0x002BEEA0, 28 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as core::XboxDrive::vfunc_22 (Proto 0x00282B10), which was matched first;
// its addresses and names were swapped for this function's.
// core::XboxDrive::vfunc_22 (Proto 0x002BEEA0, 28 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __stdcall sub_00233A9F(int);

namespace core {

class XboxDrive
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

int XboxDrive::vfunc_22(int a1)
{
    sub_00233A9F(*(int*)a1);
    *(int*)a1 = -1;
    return 1;
}

}

// ============================================================================
// [VERIFIED] core::XboxDrive::vfunc_03 (0x002BF0D0, 36 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as core::ControllerSystemXBox::vfunc_03 (0x00248820), which was matched first;
// its addresses and names were swapped for this function's.
// core::XboxDrive::vfunc_03 (0x002BF0D0, 36 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_0045894C;
extern "C" void __cdecl sub_002444F0(int, int);
extern "C" void __cdecl sub_002BEAE0(void);

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
    sub_002BEAE0();
    if (a1 & 1) {
        sub_002444F0(DAT_0045894C, (int)this);
    }
    return this;
}

}

// ============================================================================
// [VERIFIED] core::XboxDrive::vfunc_09 (0x002BF100, 25 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as core::XboxDrive::vfunc_09 (Proto 0x00282D70), which was matched first;
// its addresses and names were swapped for this function's.
// core::XboxDrive::vfunc_09 (Proto 0x002BF100, 25 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __cdecl sub_002BEBF0(void);

namespace core {

class XboxDrive
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
    virtual int vfunc_09();
    char m_pad04[0xCC];
    int m_FieldD0; // +0xD0
};

int XboxDrive::vfunc_09()
{
    sub_002BEBF0();
    m_FieldD0 = 0;
    return 1;
}

}

// ============================================================================
// [VERIFIED] core::XboxDrive::vfunc_14 (0x002BF290, 108 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as core::XboxDrive::vfunc_14 (Proto 0x00282F00), which was matched first;
// its addresses and names were swapped for this function's.
// core::XboxDrive::vfunc_14 (Proto 0x002BF290, 108 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int __stdcall sub_002335F6(int, int, int, int, int);
extern "C" int __stdcall sub_0023383D(int, int, int, int);
extern "C" int __cdecl sub_00234B47(void);

namespace core {

class XboxDrive
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
    virtual int vfunc_14(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8);
    int sub_002BED40(int);
    char m_pad04[0xCC];
    int m_FieldD0; // +0xD0
};

int XboxDrive::vfunc_14(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8)
{
    if (sub_0023383D(a1, a4, 0, 0) == a4) {
        if (!sub_002335F6(a1, a5, a6, a7, 0)) goto L_50;
        *(int*)a7 = a6;
        m_FieldD0 = 0;
        return 1;
    }
L_50:
    m_FieldD0 = sub_002BED40(sub_00234B47());
    return 0;
}

}

// ============================================================================
// [VERIFIED] core::XboxDrive::vfunc_16 (0x002BF620, 57 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as core::XboxDrive::vfunc_16 (Proto 0x00283290), which was matched first;
// its addresses and names were swapped for this function's.
// core::XboxDrive::vfunc_16 (Proto 0x002BF620, 57 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int __cdecl sub_00234B47(void);
extern "C" int __cdecl sub_00236817(void);

namespace core {

class XboxDrive
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
    virtual int vfunc_16();
    int sub_002BED40(int);
    char m_pad04[0xCC];
    int m_FieldD0; // +0xD0
    char m_padD4[0x10C];
    int m_Field1E0; // +0x1E0
};

int XboxDrive::vfunc_16()
{
    if (m_Field1E0 & 8) {
        if (sub_00236817()) goto L_28;
        m_FieldD0 = sub_002BED40(sub_00234B47());
    }
L_28:
    m_FieldD0 = 0;
    return 1;
}

}

