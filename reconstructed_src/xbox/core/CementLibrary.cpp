// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail Xbox default.xbe, core/CementLibrary.cpp (12 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 12 of 17 functions matched (70.59%). NOT COMPLETE YET.
// The 5 still to do are listed in their place in Original_Binary_Order_Xbox.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] core::CementLibrary::vfunc_05 (0x002ACA60, 40 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as core::CementLibrary::vfunc_05 (Proto 0x0026F170), which was matched first;
// its addresses and names were swapped for this function's.
// core::CementLibrary::vfunc_05 (Proto 0x002ACA60, 40 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __cdecl sub_002511A0(void);
extern "C" void __cdecl sub_00283AE0(int);

namespace core {

class CementLibrary
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual int vfunc_05();
    char m_pad04[0x1C];
    int m_Field20; // +0x20
};

int CementLibrary::vfunc_05()
{
    int r_eax;

    r_eax = m_Field20;
    if (!r_eax) {
        do {
            sub_002511A0();
            sub_00283AE0(0);
            r_eax = m_Field20;
        } while (!r_eax);
    }
    return r_eax;
}

}

// ============================================================================
// [VERIFIED] core::CementLibrary::vfunc_07 (0x002ACA90, 12 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as core::CementLibrary::vfunc_07 (Proto 0x0026F1A0), which was matched first;
// its addresses and names were swapped for this function's.
// core::CementLibrary::vfunc_07 (Proto 0x002ACA90, 12 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

namespace core {

class CementLibrary
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual void vfunc_05();
    virtual void vfunc_06();
    virtual bool vfunc_07();
    char m_pad04[0x1C];
    int m_Field20; // +0x20
};

bool CementLibrary::vfunc_07()
{
    return m_Field20 == 1;
}

}

// ============================================================================
// [VERIFIED] core::CementLibrary::vfunc_06 (0x002ACAA0, 23 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as core::CementLibrary::vfunc_06 (Proto 0x0026F1B0), which was matched first;
// its addresses and names were swapped for this function's.
// core::CementLibrary::vfunc_06 (Proto 0x002ACAA0, 23 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    virtual void vfunc_00();
};

namespace core {

class CementLibrary
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual void vfunc_05();
    virtual void vfunc_06(int a1, int a2);
    char m_pad04[0x68];
    int m_Field6C; // +0x6C
    int m_Field70; // +0x70
};

void CementLibrary::vfunc_06(int a1, int a2)
{
    m_Field6C = a1;
    m_Field70 = a2;
    ((Object*)a1)->vfunc_00();
}

}

// ============================================================================
// [VERIFIED] core::CementLibrary::vfunc_09 (0x002ACBF0, 51 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as core::CementLibrary::vfunc_09 (Proto 0x0026F300), which was matched first;
// its addresses and names were swapped for this function's.
// core::CementLibrary::vfunc_09 (Proto 0x002ACBF0, 51 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
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
    virtual void vfunc_17();
    virtual void vfunc_18();
    virtual void vfunc_19();
    virtual void vfunc_20();
    virtual void vfunc_21();
    virtual void vfunc_22();
};

namespace core {

class CementLibrary
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
    virtual void vfunc_08(int, int, int, int, int, int);
    virtual void vfunc_09(int a1, int a2, int a3, int a4, int a5, int a6);
};

void CementLibrary::vfunc_09(int a1, int a2, int a3, int a4, int a5, int a6)
{
    int t2;

    vfunc_08(a1, a2, a3, a4, a5, a6);
    t2 = *(int*)a1;
    if (*(int*)a1) {
        ((Object*)t2)->vfunc_22();
    }
}

}

// ============================================================================
// [VERIFIED] core::CementLibrary::vfunc_01 (0x002ACEB0, 8 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// core::CementLibrary::vfunc_01 (0x002ACEB0, 8 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_002AC3B0();
};

namespace core {

class CementLibrary
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
};

void CementLibrary::vfunc_01()
{
    ((Object*)(int)this + 16)->sub_002AC3B0();
}

}

// ============================================================================
// [VERIFIED] core::CementLibrary::vfunc_00 (0x002ACEC0, 8 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as core::ControllerSystemXBox::vfunc_00 (0x00248810), which was matched first;
// its addresses and names were swapped for this function's.
// core::CementLibrary::vfunc_00 (0x002ACEC0, 8 bytes)
// An adjustor thunk. Nobody wrote this function: the compiler adds it for a class with two base
// classes that both declare the same virtual function. Called through the second base's table, it
// moves `this` back 4 bytes to the start of the object and jumps to the real function at
// 0x002ACE90. So it is matched by declaring the class that way, not by writing a body.
// The two bases and their names are guesses; the first base is the part of the object in front
// of the second base (4 bytes).

namespace core {
class ControllerSystemXBox_Base0 { public: virtual void sub_002ACE90(); };
class ControllerSystemXBox_Base1 { public: virtual void sub_002ACE90(); };

class CementLibrary : public ControllerSystemXBox_Base0, public ControllerSystemXBox_Base1
{
public:
    CementLibrary();
    virtual void sub_002ACE90();          // the real function; the thunk jumps here
};

CementLibrary::CementLibrary() {}                  // building one is what makes the compiler write its tables and the thunk
}

// ============================================================================
// [VERIFIED] core::CementLibrary::vfunc_01 (0x002ACED0, 8 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as core::ControllerSystemXBox::vfunc_00 (0x00248810), which was matched first;
// its addresses and names were swapped for this function's.
// core::CementLibrary::vfunc_01 (0x002ACED0, 8 bytes)
// An adjustor thunk. Nobody wrote this function: the compiler adds it for a class with two base
// classes that both declare the same virtual function. Called through the second base's table, it
// moves `this` back 4 bytes to the start of the object and jumps to the real function at
// 0x002ACEB0. So it is matched by declaring the class that way, not by writing a body.
// The two bases and their names are guesses; the first base is the part of the object in front
// of the second base (4 bytes).

namespace core {
class ControllerSystemXBox_Base0 { public: virtual void sub_002ACEB0(); };
class ControllerSystemXBox_Base1 { public: virtual void sub_002ACEB0(); };

class CementLibrary : public ControllerSystemXBox_Base0, public ControllerSystemXBox_Base1
{
public:
    CementLibrary();
    virtual void sub_002ACEB0();          // the real function; the thunk jumps here
};

CementLibrary::CementLibrary() {}                  // building one is what makes the compiler write its tables and the thunk
}

// ============================================================================
// [VERIFIED] core::CementLibrary::vfunc_02 (0x002ACEE0, 8 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as core::ControllerSystemXBox::vfunc_00 (0x00248810), which was matched first;
// its addresses and names were swapped for this function's.
// core::CementLibrary::vfunc_02 (0x002ACEE0, 8 bytes)
// An adjustor thunk. Nobody wrote this function: the compiler adds it for a class with two base
// classes that both declare the same virtual function. Called through the second base's table, it
// moves `this` back 4 bytes to the start of the object and jumps to the real function at
// 0x00075710. So it is matched by declaring the class that way, not by writing a body.
// The two bases and their names are guesses; the first base is the part of the object in front
// of the second base (4 bytes).

namespace core {
class ControllerSystemXBox_Base0 { public: virtual void sub_00075710(); };
class ControllerSystemXBox_Base1 { public: virtual void sub_00075710(); };

class CementLibrary : public ControllerSystemXBox_Base0, public ControllerSystemXBox_Base1
{
public:
    CementLibrary();
    virtual void sub_00075710();          // the real function; the thunk jumps here
};

CementLibrary::CementLibrary() {}                  // building one is what makes the compiler write its tables and the thunk
}

// ============================================================================
// [VERIFIED] core::CementLibrary::vfunc_03 (0x002ACEF0, 8 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as core::ControllerSystemXBox::vfunc_00 (0x00248810), which was matched first;
// its addresses and names were swapped for this function's.
// core::CementLibrary::vfunc_03 (0x002ACEF0, 8 bytes)
// An adjustor thunk. Nobody wrote this function: the compiler adds it for a class with two base
// classes that both declare the same virtual function. Called through the second base's table, it
// moves `this` back 4 bytes to the start of the object and jumps to the real function at
// 0x002AD290. So it is matched by declaring the class that way, not by writing a body.
// The two bases and their names are guesses; the first base is the part of the object in front
// of the second base (4 bytes).

namespace core {
class ControllerSystemXBox_Base0 { public: virtual void sub_002AD290(); };
class ControllerSystemXBox_Base1 { public: virtual void sub_002AD290(); };

class CementLibrary : public ControllerSystemXBox_Base0, public ControllerSystemXBox_Base1
{
public:
    CementLibrary();
    virtual void sub_002AD290();          // the real function; the thunk jumps here
};

CementLibrary::CementLibrary() {}                  // building one is what makes the compiler write its tables and the thunk
}

// ============================================================================
// [VERIFIED] core::CementLibrary::vfunc_00 (0x002ACF00, 8 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as core::CementLibrary::vfunc_00 (Proto 0x0026F620), which was matched first;
// its addresses and names were swapped for this function's.
// core::CementLibrary::vfunc_00 (Proto 0x002ACF00, 8 bytes)
// An adjustor thunk. Nobody wrote this function: the compiler adds it for a class with two base
// classes that both declare the same virtual function. Called through the second base's table, it
// moves `this` back 8 bytes to the start of the object and jumps to the real function at
// 0x002AD290. So it is matched by declaring the class that way, not by writing a body.
// The two bases and their names are guesses; the first base is the part of the object in front
// of the second base (8 bytes).

namespace core {
class CementLibrary_Base0 { public: virtual void sub_002AD290(); char m_pad04[0x4]; };
class CementLibrary_Base1 { public: virtual void sub_002AD290(); };

class CementLibrary : public CementLibrary_Base0, public CementLibrary_Base1
{
public:
    CementLibrary();
    virtual void sub_002AD290();          // the real function; the thunk jumps here
};

CementLibrary::CementLibrary() {}                  // building one is what makes the compiler write its tables and the thunk
}

// ============================================================================
// [VERIFIED] core::CementLibrary::vfunc_02 (0x002ACF10, 8 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as core::CementLibrary::vfunc_02 (Proto 0x0026F630), which was matched first;
// its addresses and names were swapped for this function's.
// core::CementLibrary::vfunc_02 (Proto 0x002ACF10, 8 bytes)
// An adjustor thunk. Nobody wrote this function: the compiler adds it for a class with two base
// classes that both declare the same virtual function. Called through the second base's table, it
// moves `this` back 16 bytes to the start of the object and jumps to the real function at
// 0x002AD290. So it is matched by declaring the class that way, not by writing a body.
// The two bases and their names are guesses; the first base is the part of the object in front
// of the second base (16 bytes).

namespace core {
class CementLibrary_Base0 { public: virtual void sub_002AD290(); char m_pad04[0xC]; };
class CementLibrary_Base1 { public: virtual void sub_002AD290(); };

class CementLibrary : public CementLibrary_Base0, public CementLibrary_Base1
{
public:
    CementLibrary();
    virtual void sub_002AD290();          // the real function; the thunk jumps here
};

CementLibrary::CementLibrary() {}                  // building one is what makes the compiler write its tables and the thunk
}

// ============================================================================
// [VERIFIED] core::CementLibrary::vfunc_03 (0x002AD290, 36 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// What it does: core::CementLibrary's deleting destructor: destroys the object, frees its memory when asked (flag bit 0), and returns it.
// ============================================================================
// Same machine code as core::ControllerSystemXBox::vfunc_03 (0x00248820), which was matched first;
// its addresses and names were swapped for this function's.
// core::CementLibrary::vfunc_03 (0x002AD290, 36 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_0045894C;
extern "C" void __cdecl sub_002444F0(int, int);
extern "C" void __cdecl sub_002ACDC0(void);

namespace core {

class CementLibrary
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual CementLibrary* vfunc_03(int a1);
};

CementLibrary* CementLibrary::vfunc_03(int a1)
{
    sub_002ACDC0();
    if (a1 & 1) {
        sub_002444F0(DAT_0045894C, (int)this);
    }
    return this;
}

}

