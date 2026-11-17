// ============================================================================
// SCARFACE: THE WORLD IS YOURS — April 2006 prototype game.xbe, core/XboxDrive.cpp (13 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 13 of 20 functions matched (65.00%). NOT COMPLETE YET.
// The 7 still to do are listed in their place in Original_Binary_Order_Proto.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] core::XboxDrive::vfunc_23 (0x002827F0, 11 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// core::XboxDrive::vfunc_23 (Proto 0x002827F0, 11 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0028EA80();
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
    ((Object*)(int)this + 216)->sub_0028EA80();
}

}

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
// [VERIFIED] core::XboxDrive::vfunc_08 (0x00282820, 7 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// core::XboxDrive::vfunc_08 (Proto 0x00282820, 7 bytes)
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
// [VERIFIED] core::XboxDrive::vfunc_05 (0x00282830, 7 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// core::XboxDrive::vfunc_05 (Proto 0x00282830, 7 bytes)
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
// [VERIFIED] core::XboxDrive::vfunc_12 (0x00282840, 28 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// core::XboxDrive::vfunc_12 (Proto 0x00282840, 28 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __stdcall sub_001F1640(int);

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
    sub_001F1640(a1);
    m_Field1E4 -= 1;
    return 1;
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
// [VERIFIED] core::XboxDrive::vfunc_02 (0x00282B00, 8 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// core::XboxDrive::vfunc_02 (Proto 0x00282B00, 8 bytes)
// An adjustor thunk. Nobody wrote this function: the compiler adds it for a class with two base
// classes that both declare the same virtual function. Called through the second base's table, it
// moves `this` back 12 bytes to the start of the object and jumps to the real function at
// 0x00282D40. So it is matched by declaring the class that way, not by writing a body.
// The two bases and their names are guesses; the first base is the part of the object in front
// of the second base (12 bytes).

namespace core {
class XboxDrive_Base0 { public: virtual void sub_00282D40(); char m_pad04[0x8]; };
class XboxDrive_Base1 { public: virtual void sub_00282D40(); };

class XboxDrive : public XboxDrive_Base0, public XboxDrive_Base1
{
public:
    XboxDrive();
    virtual void sub_00282D40();          // the real function; the thunk jumps here
};

XboxDrive::XboxDrive() {}                  // building one is what makes the compiler write its tables and the thunk
}

// ============================================================================
// [VERIFIED] core::XboxDrive::vfunc_22 (0x00282B10, 28 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// core::XboxDrive::vfunc_22 (Proto 0x00282B10, 28 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __stdcall sub_001F1640(int);

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
    sub_001F1640(*(int*)a1);
    *(int*)a1 = -1;
    return 1;
}

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

// ============================================================================
// [VERIFIED] core::XboxDrive::vfunc_09 (0x00282D70, 25 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// core::XboxDrive::vfunc_09 (Proto 0x00282D70, 25 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __cdecl sub_00282860(void);

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
    sub_00282860();
    m_FieldD0 = 0;
    return 1;
}

}

// ============================================================================
// [VERIFIED] core::XboxDrive::vfunc_14 (0x00282F00, 108 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// core::XboxDrive::vfunc_14 (Proto 0x00282F00, 108 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int __stdcall sub_001F1197(int, int, int, int, int);
extern "C" int __stdcall sub_001F13DE(int, int, int, int);
extern "C" int __cdecl sub_001F23D4(void);

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
    int sub_002829B0(int);
    char m_pad04[0xCC];
    int m_FieldD0; // +0xD0
};

int XboxDrive::vfunc_14(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8)
{
    if (sub_001F13DE(a1, a4, 0, 0) == a4) {
        if (!sub_001F1197(a1, a5, a6, a7, 0)) goto L_50;
        *(int*)a7 = a6;
        m_FieldD0 = 0;
        return 1;
    }
L_50:
    m_FieldD0 = sub_002829B0(sub_001F23D4());
    return 0;
}

}

// ============================================================================
// [VERIFIED] core::XboxDrive::vfunc_16 (0x00283290, 57 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// core::XboxDrive::vfunc_16 (Proto 0x00283290, 57 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int __cdecl sub_001F23D4(void);
extern "C" int __cdecl sub_001F4291(void);

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
    int sub_002829B0(int);
    char m_pad04[0xCC];
    int m_FieldD0; // +0xD0
    char m_padD4[0x10C];
    int m_Field1E0; // +0x1E0
};

int XboxDrive::vfunc_16()
{
    if (m_Field1E0 & 8) {
        if (sub_001F4291()) goto L_28;
        m_FieldD0 = sub_002829B0(sub_001F23D4());
    }
L_28:
    m_FieldD0 = 0;
    return 1;
}

}

