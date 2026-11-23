// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail PC Scarface.exe v1.00.2, core/Win32Drive.cpp (10 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 10 of 17 functions matched (58.82%). NOT COMPLETE YET.
// The 7 still to do are listed in their place in Original_Binary_Order_PC_1002.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] core::Win32Drive::vfunc_00 (0x006E7480, 14 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// What it does: Passes the drive's block at +0xEC to sub_006DF080.
// ============================================================================
// bin: pc
// va: 0x006E7480
// what: Passes the drive's block at +0xEC to sub_006DF080.
// tool: Claude Opus 5.5 (transplanted from proto:0x00281AE0, nearest by portal/tools/similar.py)
// core::Win32Drive::vfunc_00
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __cdecl sub_006DF080(int);


namespace core {
class Win32Drive
{
public:
    virtual void vfunc_00();
};

void Win32Drive::vfunc_00()
{
    sub_006DF080((int)this + 236);
}
}

// ============================================================================
// [VERIFIED] core::Win32Drive::vfunc_01 (0x006E7490, 14 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as core::Win32Drive::vfunc_00 (PC 0x006E7480), which was matched first;
// its addresses and names were swapped for this function's.
// bin: pc
// va: 0x006E7490
// what: Passes the drive's block at +0xEC to sub_006DF070.
// tool: Claude Opus 5.5 (transplanted from proto:0x00281AE0, nearest by portal/tools/similar.py)
// core::Win32Drive::vfunc_01
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __cdecl sub_006DF070(int);


namespace core {
class Win32Drive
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
};

void Win32Drive::vfunc_01()
{
    sub_006DF070((int)this + 236);
}
}

// ============================================================================
// [VERIFIED] core::Win32Drive::vfunc_05 (0x006E74A0, 7 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// What it does: Returns the address of the block at +0xE0 inside the drive.
// ============================================================================
// bin: pc
// va: 0x006E74A0
// what: Returns the address of the block at +0xE0 inside the drive.
// tool: Claude Opus 5.5 (transplanted from pc:0x006E4260, nearest by portal/tools/similar.py)
// core::Win32Drive::vfunc_05
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.


namespace core {
class Win32Drive
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual void* vfunc_05();
    char m_pad04[0xDC];
    int m_FieldE0; // +0xE0
};

void* Win32Drive::vfunc_05()
{
    return &m_FieldE0;
}
}

// ============================================================================
// [VERIFIED] core::Win32Drive::vfunc_12 (0x006E74B0, 30 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G7 /Gd /GR /EHsc /Zp4
// ============================================================================
// bin: pc
// va: 0x006E74B0
// what: 
// tool: the portal's starter code (no AI)

// core::Win32Drive::vfunc_12 (PC 0x006E74B0, 30 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_0072F04C;

namespace core {

class Win32Drive
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
    char m_pad04[0xD8];
    int m_FieldDC; // +0xDC
};

int Win32Drive::vfunc_12(int a1, int a2)
{
    ((void (__stdcall*)(int))DAT_0072F04C)(a1);
    m_FieldDC += -1;
    return 1;
}

}

// ============================================================================
// [VERIFIED] core::Win32Drive::vfunc_22 (0x006E74D0, 29 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// bin: pc
// va: 0x006E74D0
// what: 
// tool: the portal's starter code (no AI)

// core::Win32Drive::vfunc_22 (PC 0x006E74D0, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_0072F104;

namespace core {

class Win32Drive
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

int Win32Drive::vfunc_22(int a1)
{
    ((void (__stdcall*)(int))DAT_0072F104)(*(int*)a1);
    *(int*)a1 = -1;
    return 1;
}

}

// ============================================================================
// [VERIFIED] core::Win32Drive::vfunc_00 (0x006E77B0, 8 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as core::ControllerSystemXBox::vfunc_00 (0x00248810), which was matched first;
// its addresses and names were swapped for this function's.
// core::Win32Drive::vfunc_00 (0x006E77B0, 8 bytes)
// An adjustor thunk. Nobody wrote this function: the compiler adds it for a class with two base
// classes that both declare the same virtual function. Called through the second base's table, it
// moves `this` back 4 bytes to the start of the object and jumps to the real function at
// 0x006E78B0. So it is matched by declaring the class that way, not by writing a body.
// The two bases and their names are guesses; the first base is the part of the object in front
// of the second base (4 bytes).

namespace core {
class ControllerSystemXBox_Base0 { public: virtual void sub_006E78B0(); };
class ControllerSystemXBox_Base1 { public: virtual void sub_006E78B0(); };

class Win32Drive : public ControllerSystemXBox_Base0, public ControllerSystemXBox_Base1
{
public:
    Win32Drive();
    virtual void sub_006E78B0();          // the real function; the thunk jumps here
};

Win32Drive::Win32Drive() {}                  // building one is what makes the compiler write its tables and the thunk
}

// ============================================================================
// [VERIFIED] core::Win32Drive::vfunc_02 (0x006E77C0, 8 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as core::Drive::vfunc_02 (Proto 0x0026EEC0), which was matched first;
// its addresses and names were swapped for this function's.
// core::Win32Drive::vfunc_02 (Proto 0x006E77C0, 8 bytes)
// An adjustor thunk. Nobody wrote this function: the compiler adds it for a class with two base
// classes that both declare the same virtual function. Called through the second base's table, it
// moves `this` back 12 bytes to the start of the object and jumps to the real function at
// 0x006E78B0. So it is matched by declaring the class that way, not by writing a body.
// The two bases and their names are guesses; the first base is the part of the object in front
// of the second base (12 bytes).

namespace core {
class Drive_Base0 { public: virtual void sub_006E78B0(); char m_pad04[0x8]; };
class Drive_Base1 { public: virtual void sub_006E78B0(); };

class Win32Drive : public Drive_Base0, public Drive_Base1
{
public:
    Win32Drive();
    virtual void sub_006E78B0();          // the real function; the thunk jumps here
};

Win32Drive::Win32Drive() {}                  // building one is what makes the compiler write its tables and the thunk
}

// ============================================================================
// [VERIFIED] core::Win32Drive::vfunc_03 (0x006E78B0, 36 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as core::ControllerSystemXBox::vfunc_03 (0x00248820), which was matched first;
// its addresses and names were swapped for this function's.
// core::Win32Drive::vfunc_03 (0x006E78B0, 36 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_007F5A70;
extern "C" void __cdecl sub_006DC430(int, int);
extern "C" void __cdecl sub_006E7430(void);

namespace core {

class Win32Drive
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual Win32Drive* vfunc_03(int a1);
};

Win32Drive* Win32Drive::vfunc_03(int a1)
{
    sub_006E7430();
    if (a1 & 1) {
        sub_006DC430(DAT_007F5A70, (int)this);
    }
    return this;
}

}

// ============================================================================
// [VERIFIED] core::Win32Drive::vfunc_09 (0x006E78E0, 80 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G7 /Gd /GR /EHsc /Zp4
// ============================================================================
// bin: pc
// va: 0x006E78E0
// what: 
// tool: the portal's starter code (no AI)

// core::Win32Drive::vfunc_09 (PC 0x006E78E0, 80 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int __cdecl sub_006E74F0(void);

namespace core {

class Win32Drive
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
    char m_pad04[0x74];
    int m_Field78; // +0x78
    char m_pad7C[0x50];
    int m_FieldCC; // +0xCC
    char m_padD0[0xC];
    int m_FieldDC; // +0xDC
    char m_padE0[0x14];
    int m_FieldF4; // +0xF4
};

int Win32Drive::vfunc_09()
{
    if (m_FieldDC) {
        if (sub_006E74F0() == m_FieldF4) goto L_43;
        if (m_FieldCC != 4) {
            m_FieldCC = 3;
            m_Field78 = 3;
        }
        return 0;
    }
    sub_006E74F0();
    m_FieldF4 = 0;
L_43:
    return !m_FieldCC;
}

}

// ============================================================================
// [VERIFIED] core::Win32Drive::vfunc_14 (0x006E7A40, 111 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// bin: pc
// va: 0x006E7A40
// what: 
// tool: the portal's starter code (no AI)

// core::Win32Drive::vfunc_14 (PC 0x006E7A40, 111 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_0072F054;
extern "C" int DAT_0072F07C;
extern "C" int DAT_0072F080;

namespace core {

class Win32Drive
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
    int sub_006E7670(int);
    char m_pad04[0xC8];
    int m_FieldCC; // +0xCC
};

int Win32Drive::vfunc_14(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8)
{
    if (((int (__stdcall*)(int, int, int, int))DAT_0072F07C)(a1, a4, 0, 0) == a4) {
        if (!((int (__stdcall*)(int, int, int, int, int))DAT_0072F080)(a1, a5, a6, a7, 0)) goto L_52;
        *(int*)a7 = a6;
        m_FieldCC = 0;
        return 1;
    }
L_52:
    m_FieldCC = sub_006E7670(((int (__cdecl*)(void))DAT_0072F054)());
    return 0;
}

}

