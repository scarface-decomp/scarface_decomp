// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail PC Scarface.exe v1.00.2, every function in address order
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 766 of 1,430 functions matched (53.57%). NOT COMPLETE YET.
// The 664 still to do are listed in their place below as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// [TODO] 0x006DDC60 core::ControllerInputPointDirectInput::vfunc_01 (23 B)
// ============================================================================
// [VERIFIED] core::ControllerDirectInput::vfunc_05 (0x006DDC80, 7 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// What it does: Returns the address of the block at +0x144 inside the controller.
// ============================================================================
// bin: pc
// va: 0x006DDC80
// what: Returns the address of the block at +0x144 inside the controller.
// tool: Claude Opus 5.5 (transplanted from pc:0x006E4260, nearest by portal/tools/similar.py)
// core::ControllerDirectInput::vfunc_05
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.


namespace core {
class ControllerDirectInput
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual void* vfunc_05();
    char m_pad04[0x140];
    int m_Field144; // +0x144
};

void* ControllerDirectInput::vfunc_05()
{
    return &m_Field144;
}
}

// [TODO] 0x006DDC90 core::ControllerDirectInput::vfunc_09 (117 B)
// [TODO] 0x006DDD10 core::ControllerDirectInput::vfunc_14 (115 B)
// [TODO] 0x006DDD90 core::ControllerDirectInput::vfunc_11 (67 B)
// [TODO] 0x006DDDE0 core::ControllerDirectInput::vfunc_16 (103 B)
// [TODO] 0x006DDE50 core::ControllerDirectInput::vfunc_10 (115 B)
// [TODO] 0x006DDED0 core::ControllerDirectInput::vfunc_15 (115 B)
// ============================================================================
// [VERIFIED] core::ControllerDirectInput::vfunc_08 (0x006DDF50, 7 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// What it does: Returns the number stored at +0x26C in the controller.
// ============================================================================
// bin: pc
// va: 0x006DDF50
// what: Returns the number stored at +0x26C in the controller.
// tool: Claude Opus 5.5 (transplanted from pc:0x006E1CF0, nearest by portal/tools/similar.py)
// core::ControllerDirectInput::vfunc_08
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.


namespace core {
class ControllerDirectInput
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
    char m_pad04[0x268];
    int m_Field26C; // +0x26C
};

int ControllerDirectInput::vfunc_08()
{
    return m_Field26C;
}
}

// [TODO] 0x006DDF60 core::ControllerDirectInput::vfunc_12 (38 B)
// ============================================================================
// [VERIFIED] core::ControllerDirectInput::vfunc_13 (0x006DDF90, 7 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// What it does: Returns the number stored at +0x278 in the controller.
// ============================================================================
// bin: pc
// va: 0x006DDF90
// what: Returns the number stored at +0x278 in the controller.
// tool: Claude Opus 5.5 (transplanted from pc:0x006E1CF0, nearest by portal/tools/similar.py)
// core::ControllerDirectInput::vfunc_13
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.


namespace core {
class ControllerDirectInput
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
    virtual int vfunc_13();
    char m_pad04[0x274];
    int m_Field278; // +0x278
};

int ControllerDirectInput::vfunc_13()
{
    return m_Field278;
}
}

// [TODO] 0x006DDFA0 core::ControllerDirectInput::vfunc_17 (38 B)
// ============================================================================
// [VERIFIED] core::ControllerDirectInput::vfunc_00 (0x006DDFD0, 8 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as core::ControllerSystemXBox::vfunc_00 (0x00248810), which was matched first;
// its addresses and names were swapped for this function's.
// core::ControllerDirectInput::vfunc_00 (0x006DDFD0, 8 bytes)
// An adjustor thunk. Nobody wrote this function: the compiler adds it for a class with two base
// classes that both declare the same virtual function. Called through the second base's table, it
// moves `this` back 4 bytes to the start of the object and jumps to the real function at
// 0x006DE1D0. So it is matched by declaring the class that way, not by writing a body.
// The two bases and their names are guesses; the first base is the part of the object in front
// of the second base (4 bytes).

namespace core {
class ControllerSystemXBox_Base0 { public: virtual void sub_006DE1D0(); };
class ControllerSystemXBox_Base1 { public: virtual void sub_006DE1D0(); };

class ControllerDirectInput : public ControllerSystemXBox_Base0, public ControllerSystemXBox_Base1
{
public:
    ControllerDirectInput();
    virtual void sub_006DE1D0();          // the real function; the thunk jumps here
};

ControllerDirectInput::ControllerDirectInput() {}                  // building one is what makes the compiler write its tables and the thunk
}

// [TODO] 0x006DDFE0 core::ControllerDirectInput::vfunc_04 (22 B)
// ============================================================================
// [VERIFIED] core::ControllerDirectInput::vfunc_07 (0x006DE000, 21 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// bin: pc
// va: 0x006DE000
// what: 
// tool: the portal's starter code (no AI)

// core::ControllerDirectInput::vfunc_07 (PC 0x006DE000, 21 bytes)
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
    virtual int vfunc_08();
};

extern "C" char DAT_00771830[];

namespace core {

class ControllerDirectInput
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual void vfunc_05();
    virtual void vfunc_06();
    virtual int vfunc_07();
    char m_pad04[0x278];
    int m_Field27C; // +0x27C
};

int ControllerDirectInput::vfunc_07()
{
    int t1;

    t1 = m_Field27C;
    if (m_Field27C) {
        return ((Object*)t1)->vfunc_08();
    }
    return (int)DAT_00771830;
}

}

// [TODO] 0x006DE020 core::ControllerDirectInput::vfunc_21 (74 B)
// [TODO] 0x006DE070 core::ControllerDirectInput::vfunc_19 (256 B)
// [TODO] 0x006DE170 core::ControllerDirectInput::vfunc_20 (94 B)
// ============================================================================
// [VERIFIED] core::ControllerDirectInput::vfunc_03 (0x006DE1D0, 36 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as core::ControllerSystemXBox::vfunc_03 (0x00248820), which was matched first;
// its addresses and names were swapped for this function's.
// core::ControllerDirectInput::vfunc_03 (0x006DE1D0, 36 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_007F5A70;
extern "C" void __cdecl sub_006DC430(int, int);
extern "C" void __cdecl sub_006DE200(void);

namespace core {

class ControllerDirectInput
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual ControllerDirectInput* vfunc_03(int a1);
};

ControllerDirectInput* ControllerDirectInput::vfunc_03(int a1)
{
    sub_006DE200();
    if (a1 & 1) {
        sub_006DC430(DAT_007F5A70, (int)this);
    }
    return this;
}

}

// [TODO] 0x006DE200 sub_006DE200 (272 B)
// [TODO] 0x006DE3C0 sub_006DE3C0 (393 B)
// [TODO] 0x006DE550 core::ControllerSystemDirectInput::vfunc_13 (55 B)
// ============================================================================
// [VERIFIED] core::ControllerSystemDirectInput::vfunc_12 (0x006DE590, 19 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// What it does: Returns the value at +0x20 and clears it if it equals the one passed in.
// ============================================================================
// bin: pc
// va: 0x006DE590
// what: Returns the value at +0x20 and clears it if it equals the one passed in.
// tool: Claude Opus 5.5 (transplanted from proto:0x00205BB0, nearest by portal/tools/similar.py)
// core::ControllerSystemDirectInput::vfunc_12
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.


namespace core {
class ControllerSystemDirectInput
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
    virtual int vfunc_12(int a1);
    char m_pad04[0x1C];
    int m_Field20; // +0x20
};

int ControllerSystemDirectInput::vfunc_12(int a1)
{
    int r_eax;

    r_eax = m_Field20;
    if (r_eax == a1) {
        m_Field20 = 0;
    }
    return r_eax;
}
}

// [TODO] 0x006DE5B0 core::ControllerSystemDirectInput::vfunc_06 (103 B)
// ============================================================================
// [VERIFIED] core::ControllerSystemDirectInput::vfunc_09 (0x006DE620, 44 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// bin: pc
// va: 0x006DE620
// what: 
// tool: the portal's starter code (no AI)

// core::ControllerSystemDirectInput::vfunc_09 (PC 0x006DE620, 44 bytes)
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
    virtual void vfunc_19(int, int);
};

namespace core {

class ControllerSystemDirectInput
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
    virtual void vfunc_09(int a1);
    char m_pad04[0x14];
    int m_Field18; // +0x18
    char m_pad1C[0xC];
    int m_Field28; // +0x28
};

void ControllerSystemDirectInput::vfunc_09(int a1)
{
    int r_ebx, r_esi;

    r_esi = m_Field28;
    if (r_esi) {
        r_ebx = a1;
        do {
            ((Object*)r_esi)->vfunc_19(r_ebx, m_Field18);
            r_esi = *(int*)(r_esi + 640);
        } while (r_esi);
    }
}

}

// [TODO] 0x006DE650 core::ControllerSystemDirectInput::vfunc_05 (38 B)
// ============================================================================
// [VERIFIED] core::ControllerSystemDirectInput::vfunc_00 (0x006DE680, 8 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as core::ControllerSystemXBox::vfunc_00 (0x00248810), which was matched first;
// its addresses and names were swapped for this function's.
// core::ControllerSystemDirectInput::vfunc_00 (0x006DE680, 8 bytes)
// An adjustor thunk. Nobody wrote this function: the compiler adds it for a class with two base
// classes that both declare the same virtual function. Called through the second base's table, it
// moves `this` back 4 bytes to the start of the object and jumps to the real function at
// 0x006DE690. So it is matched by declaring the class that way, not by writing a body.
// The two bases and their names are guesses; the first base is the part of the object in front
// of the second base (4 bytes).

namespace core {
class ControllerSystemXBox_Base0 { public: virtual void sub_006DE690(); };
class ControllerSystemXBox_Base1 { public: virtual void sub_006DE690(); };

class ControllerSystemDirectInput : public ControllerSystemXBox_Base0, public ControllerSystemXBox_Base1
{
public:
    ControllerSystemDirectInput();
    virtual void sub_006DE690();          // the real function; the thunk jumps here
};

ControllerSystemDirectInput::ControllerSystemDirectInput() {}                  // building one is what makes the compiler write its tables and the thunk
}

// ============================================================================
// [VERIFIED] core::ControllerSystemDirectInput::vfunc_03 (0x006DE690, 36 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as core::ControllerSystemXBox::vfunc_03 (0x00248820), which was matched first;
// its addresses and names were swapped for this function's.
// core::ControllerSystemDirectInput::vfunc_03 (0x006DE690, 36 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_007F5A70;
extern "C" void __cdecl sub_006DC430(int, int);
extern "C" void __cdecl sub_006DE6C0(void);

namespace core {

class ControllerSystemDirectInput
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual ControllerSystemDirectInput* vfunc_03(int a1);
};

ControllerSystemDirectInput* ControllerSystemDirectInput::vfunc_03(int a1)
{
    sub_006DE6C0();
    if (a1 & 1) {
        sub_006DC430(DAT_007F5A70, (int)this);
    }
    return this;
}

}

// [TODO] 0x006DE6C0 sub_006DE6C0 (140 B)
// [TODO] 0x006DE7A0 sub_006DE7A0 (123 B)
// [TODO] 0x006DE930 sub_006DE930 (43 B)
// ============================================================================
// [VERIFIED] sub_006DEBB0 (0x006DEBB0, 35 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00250E80 (0x00250E80), which was matched first;
// its addresses and names were swapped for this function's.
// bin: xb
// va: 0x006DEBB0
// what: Rounds a number up to a multiple of a step; a step of zero, or a number already on a multiple, leaves it as it is.
// tool: Claude (from the bytes)

unsigned int __cdecl sub_006DEBB0(unsigned int value, unsigned int step)
{
    if (step != 0)
    {
        unsigned int over = value % step;
        if (over != 0)
        {
            return value - over + step;
        }
    }
    return value;
}

// ============================================================================
// [VERIFIED] sub_006DEBE0 (0x006DEBE0, 20 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00250E60 (0x00250E60), which was matched first;
// its addresses and names were swapped for this function's.
// bin: xb
// va: 0x006DEBE0
// what: Rounds a number down to a multiple of a step; a step of zero leaves it as it is.
// tool: Claude (from the bytes)

unsigned int __cdecl sub_006DEBE0(unsigned int value, unsigned int step)
{
    if (step != 0)
    {
        value = value / step * step;
    }
    return value;
}

// [TODO] 0x006DEC30 sub_006DEC30 (84 B)
// ============================================================================
// [VERIFIED] sub_006DEC90 (0x006DEC90, 24 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_001FFF90 (Proto 0x001FFF90), which was matched first;
// its addresses and names were swapped for this function's.
// sub_006DEC90 (Proto 0x006DEC90, 24 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0085AEB0[];
extern "C" int DAT_0085AEC8;
extern "C" void __cdecl sub_006DF050(int);

void __cdecl sub_006DEC90(void)
{
    sub_006DF050((int)DAT_0085AEB0);
    DAT_0085AEC8 = 0x55555555;
}

// [TODO] 0x006DECB0 sub_006DECB0 (118 B)
// ============================================================================
// [VERIFIED] sub_006DEDF0 (0x006DEDF0, 1 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// sub_006DEDF0 (PC 0x006DEDF0, 1 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

void __cdecl sub_006DEDF0(void)
{
}

// [TODO] 0x006DEF50 sub_006DEF50 (74 B)
// ============================================================================
// [VERIFIED] sub_006DEFA0 (0x006DEFA0, 12 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00283B60 (0x00283B60), which was matched first;
// its addresses and names were swapped for this function's.
// sub_006DEFA0 (0x006DEFA0, 12 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_0072F0D8;

void __cdecl sub_006DEFA0(int a1)
{
    ((void (__stdcall*)(int))DAT_0072F0D8)(a1);
}

// [TODO] 0x006DEFE0 sub_006DEFE0 (34 B)
// [TODO] 0x006DF010 sub_006DF010 (59 B)
// ============================================================================
// [VERIFIED] sub_006DF050 (0x006DF050, 12 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00283B60 (0x00283B60), which was matched first;
// its addresses and names were swapped for this function's.
// sub_006DF050 (0x006DF050, 12 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_0072F0A0;

void __cdecl sub_006DF050(int a1)
{
    ((void (__stdcall*)(int))DAT_0072F0A0)(a1);
}

// ============================================================================
// [VERIFIED] sub_006DF060 (0x006DF060, 12 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00283B60 (0x00283B60), which was matched first;
// its addresses and names were swapped for this function's.
// sub_006DF060 (0x006DF060, 12 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_0072F09C;

void __cdecl sub_006DF060(int a1)
{
    ((void (__stdcall*)(int))DAT_0072F09C)(a1);
}

// ============================================================================
// [VERIFIED] sub_006DF070 (0x006DF070, 12 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00283B60 (0x00283B60), which was matched first;
// its addresses and names were swapped for this function's.
// sub_006DF070 (0x006DF070, 12 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_0072F098;

void __cdecl sub_006DF070(int a1)
{
    ((void (__stdcall*)(int))DAT_0072F098)(a1);
}

// ============================================================================
// [VERIFIED] sub_006DF080 (0x006DF080, 12 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00283B60 (0x00283B60), which was matched first;
// its addresses and names were swapped for this function's.
// sub_006DF080 (0x006DF080, 12 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_0072F094;

void __cdecl sub_006DF080(int a1)
{
    ((void (__stdcall*)(int))DAT_0072F094)(a1);
}

// ============================================================================
// [VERIFIED] sub_006DF0B0 (0x006DF0B0, 14 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// bin: pc
// va: 0x006DF0B0
// what: 
// tool: the portal's starter code (no AI)

// sub_006DF0B0 (PC 0x006DF0B0, 14 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_0072F04C;

void __cdecl sub_006DF0B0(int a1)
{
    ((void (__stdcall*)(int))DAT_0072F04C)(*(int*)a1);
}

// ============================================================================
// [VERIFIED] sub_006DF0C0 (0x006DF0C0, 16 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// bin: pc
// va: 0x006DF0C0
// what: 
// tool: the portal's starter code (no AI)

// sub_006DF0C0 (PC 0x006DF0C0, 16 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_0072F028;

void __cdecl sub_006DF0C0(int a1)
{
    ((void (__stdcall*)(int, int))DAT_0072F028)(*(int*)a1, -1);
}

// ============================================================================
// [VERIFIED] sub_006DF0D0 (0x006DF0D0, 18 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// bin: pc
// va: 0x006DF0D0
// what: 
// tool: the portal's starter code (no AI)

// sub_006DF0D0 (PC 0x006DF0D0, 18 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_0072F038;

void __cdecl sub_006DF0D0(int a1)
{
    ((void (__stdcall*)(int, int, int))DAT_0072F038)(*(int*)a1, 1, 0);
}

// ============================================================================
// [VERIFIED] sub_006DF0F0 (0x006DF0F0, 78 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G7 /Gd /GR /EHsc /Zp4
// ============================================================================
// bin: pc
// va: 0x006DF0F0
// what: 
// tool: the portal's starter code (no AI)

// sub_006DF0F0 (PC 0x006DF0F0, 78 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_0072F094;
extern "C" int DAT_0072F098;
extern "C" int DAT_0085CDB8;
extern "C" int DAT_0085CDBC;
extern "C" char DAT_0085CDC4[];

void __cdecl sub_006DF0F0(int a1)
{
    int r_eax;

    ((void (__stdcall*)(int))DAT_0072F094)((int)DAT_0085CDC4);
    r_eax = a1;
    if (!DAT_0085CDBC) {
        DAT_0085CDBC = a1;
        *(int*)(r_eax + 4) = 0;
    } else {
        *(int*)DAT_0085CDB8 = r_eax;
        *(int*)(r_eax + 4) = DAT_0085CDB8;
    }
    DAT_0085CDB8 = r_eax;
    *(int*)r_eax = 0;
    ((void (__stdcall*)(int))DAT_0072F098)((int)DAT_0085CDC4);
}

// ============================================================================
// [VERIFIED] sub_006DF140 (0x006DF140, 80 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00283C40 (0x00283C40), which was matched first;
// its addresses and names were swapped for this function's.
// bin: xb
// va: 0x006DF140
// what: Takes a thread's record out of the list of all threads, inside the list's lock.
// tool: Claude (from SPEC-018)

struct Thread;

// One fiber of a thread (0x24 bytes).
struct Fiber
{
    int (__cdecl* m_Entry)(void* argument);     // +0x00
    void* m_Argument;       // +0x04
    Thread* m_Owner;        // +0x08
    Fiber* m_Next;          // +0x0C
    Fiber* m_Previous;      // +0x10
    void* m_SystemFiber;    // +0x14
    int m_Field18;          // +0x18
    int m_Field1C;          // +0x1C
    int m_Field20;          // +0x20
};

// A thread's record (0x4C bytes). Its first fiber is part of it.
struct Thread
{
    Thread* m_Next;         // +0x00
    Thread* m_Previous;     // +0x04
    Fiber m_FirstFiber;     // +0x08
    Fiber* m_CurrentFiber;  // +0x2C
    Fiber* m_FiberHead;     // +0x30
    Fiber* m_FiberTail;     // +0x34
    bool m_Running;         // +0x38
    int m_Result;           // +0x3C
    int m_Priority;         // +0x40
    unsigned int m_Id;      // +0x44
    void* m_Handle;         // +0x48
};

extern "C" int DAT_0072F098;        // kernel import: RtlLeaveCriticalSection
extern "C" int DAT_0072F094;        // kernel import: RtlEnterCriticalSection
extern "C" Thread* DAT_0085CDB8;    // the last thread in the list of all threads
extern "C" Thread* DAT_0085CDBC;    // the first
extern "C" char DAT_0085CDC4[];     // the critical section that guards the list

void __cdecl sub_006DF140(Thread* thread)
{
    ((void (__stdcall*)(char*))DAT_0072F094)(DAT_0085CDC4);
    if (thread->m_Previous == 0)
    {
        DAT_0085CDBC = thread->m_Next;
    }
    else
    {
        thread->m_Previous->m_Next = thread->m_Next;
    }
    if (thread->m_Next == 0)
    {
        DAT_0085CDB8 = thread->m_Previous;
    }
    else
    {
        thread->m_Next->m_Previous = thread->m_Previous;
    }
    ((void (__stdcall*)(char*))DAT_0072F098)(DAT_0085CDC4);
}

// [TODO] 0x006DF220 sub_006DF220 (129 B)
// ============================================================================
// [VERIFIED] sub_006DF2B0 (0x006DF2B0, 34 B)
// By: lemiur | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// What it does: Passes its four arguments, the last a 64-bit number, unchanged to another function.
// ============================================================================
// Same machine code as sub_00283FE0 (0x00283FE0), which was matched first;
// its addresses and names were swapped for this function's.
// bin: xb
// va: 0x006DF2B0
// what: Passes its four arguments, the last a 64-bit number, unchanged to another function.
// tool: Claude Opus 5.5 (symcov hint: File_ReadAsyncEx)
// sub_006DF2B0 (0x006DF2B0, 34 bytes)

extern "C" int __cdecl sub_006DF220(int a1, int a2, int a3, __int64 a4);

// Forwards all four arguments. MSVC 7.1 does not turn the call into a jump because of the 64-bit argument.
int __cdecl sub_006DF2B0(int a1, int a2, int a3, __int64 a4)
{
    return sub_006DF220(a1, a2, a3, a4);
}

// [TODO] 0x006DF310 sub_006DF310 (141 B)
// ============================================================================
// [VERIFIED] sub_006DF3E0 (0x006DF3E0, 14 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// What it does: Looks up an object and returns the number at +0x20 in it, or 0 when there is none.
// ============================================================================
// bin: pc
// va: 0x006DF3E0
// what: Looks up an object and returns the number at +0x20 in it, or 0 when there is none.
// tool: Claude Opus 5.5 (transplanted from proto:0x0023F500, nearest by portal/tools/similar.py)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int __cdecl sub_006DF3A0(void);

int __cdecl sub_006DF3E0(void)
{
    int r_eax;

    r_eax = sub_006DF3A0();
    if (!r_eax) {
        return r_eax;
    }
    r_eax = *(int*)(r_eax + 32);
    return r_eax;
}

// ============================================================================
// [VERIFIED] sub_006DF3F0 (0x006DF3F0, 23 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// bin: pc
// va: 0x006DF3F0
// what: 
// tool: the portal's starter code (no AI)

// sub_006DF3F0 (PC 0x006DF3F0, 23 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_0072F0EC;
extern "C" int __cdecl sub_006DF3A0(void);

void __cdecl sub_006DF3F0(int a1)
{
    *(int*)(sub_006DF3A0() + 32) = a1;
    ((void (__stdcall*)(int))DAT_0072F0EC)(*(int*)(a1 + 20));
}

// [TODO] 0x006DF430 sub_006DF430 (81 B)
// ============================================================================
// [VERIFIED] sub_006DF490 (0x006DF490, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_0001E5D0 (0x0001E5D0), which was matched first;
// its addresses and names were swapped for this function's.
// sub_006DF490 (0x006DF490, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_0085AEF4;

int __cdecl sub_006DF490(void)
{
    return DAT_0085AEF4;
}

// ============================================================================
// [VERIFIED] LoadSet::vfunc_00 (0x006DF4A0, 5 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G7 /Gd /GR /EHsc /Zp4
// ============================================================================
// bin: pc
// va: 0x006DF4A0
// what: 
// tool: the portal's starter code (no AI)

// LoadSet::vfunc_00 (PC 0x006DF4A0, 5 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

class LoadSet
{
public:
    virtual void vfunc_00();
    char m_pad04[0x10];
    int m_Field14; // +0x14
};

void LoadSet::vfunc_00()
{
    m_Field14 += 1;
}

// ============================================================================
// [VERIFIED] core::Platform::vfunc_01 (0x006DF4B0, 5 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G7 /Gd /GR /EHsc /Zp4
// ============================================================================
// bin: pc
// va: 0x006DF4B0
// what: 
// tool: the portal's starter code (no AI)

// core::Platform::vfunc_01 (PC 0x006DF4B0, 5 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

namespace core {

class Platform
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    char m_pad04[0x10];
    int m_Field14; // +0x14
};

void Platform::vfunc_01()
{
    m_Field14 += -1;
}

}

// ============================================================================
// [VERIFIED] core::Platform::vfunc_04 (0x006DF4C0, 24 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// bin: pc
// va: 0x006DF4C0
// what: 
// tool: the portal's starter code (no AI)

// core::Platform::vfunc_04 (PC 0x006DF4C0, 24 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_0072F268;
extern "C" int DAT_0072F288;

namespace core {

class Platform
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual int vfunc_04();
    int m_Field04; // +0x04
};

int Platform::vfunc_04()
{
    int r_eax;

    r_eax = m_Field04;
    if (!r_eax) {
        r_eax = ((int (__cdecl*)(void))DAT_0072F288)();
        if (r_eax) goto L_17;
        return ((int (__cdecl*)(void))DAT_0072F268)();
    }
L_17:
    return r_eax;
}

}

// [TODO] 0x006DF4E0 core::Platform::vfunc_07 (68 B)
// ============================================================================
// [VERIFIED] core::Platform::vfunc_06 (0x006DF590, 50 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G7 /Gd /GR /EHsc /Zp4
// ============================================================================
// bin: pc
// va: 0x006DF590
// what: 
// tool: the portal's starter code (no AI)

// core::Platform::vfunc_06 (PC 0x006DF590, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_0072F28C;
extern "C" char sub_006DF530[];

namespace core {

class Platform
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual void vfunc_05();
    virtual int vfunc_06(int a1);
    int m_Field04; // +0x04
    char m_pad08[0x4];
    int m_Field0C; // +0x0C
    int m_Field10; // +0x10
};

int Platform::vfunc_06(int a1)
{
    int t1;

    if (!m_Field10) {
        t1 = m_Field04;
        if (!m_Field04) goto L_21;
        m_Field0C = ((int (__stdcall*)(int, int, int))DAT_0072F28C)(t1, -4, (int)sub_006DF530);
    }
L_21:
    *(int*)(a1 + 4) = m_Field10;
    m_Field10 = a1;
    return a1;
}

}

// ============================================================================
// [VERIFIED] sub_006DF650 (0x006DF650, 5 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00023D40 (0x00023D40), which was matched first;
// its addresses and names were swapped for this function's.
// sub_006DF650 (0x006DF650, 5 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __cdecl sub_006E3460(void);

class Class_006DF650
{
public:
    void sub_006DF650();
};

void Class_006DF650::sub_006DF650()
{
    sub_006E3460();
}

// [TODO] 0x006DF6B0 sub_006DF6B0 (33 B)
// ============================================================================
// [VERIFIED] core::MemorySpaceAsyncRequest_Copy::vfunc_01 (0x006DF710, 5 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G7 /Gd /GR /EHsc /Zp4
// ============================================================================
// bin: pc
// va: 0x006DF710
// what: 
// tool: the portal's starter code (no AI)

// core::MemorySpaceAsyncRequest_Copy::vfunc_01 (PC 0x006DF710, 5 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

namespace core {

class MemorySpaceAsyncRequest_Copy
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    int m_Field04; // +0x04
};

void MemorySpaceAsyncRequest_Copy::vfunc_01()
{
    m_Field04 += -1;
}

}

// ============================================================================
// [VERIFIED] UpperBodyAnimStateCondition::vfunc_13 (0x006DF720, 5 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as CollisionBehaviourTypeGroup::vfunc_20 (Proto 0x0001C290), which was matched first;
// its addresses and names were swapped for this function's.
// UpperBodyAnimStateCondition::vfunc_13 (Proto 0x006DF720, 5 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

class UpperBodyAnimStateCondition
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
    virtual bool vfunc_13(int a1);
};

bool UpperBodyAnimStateCondition::vfunc_13(int a1)
{
    return true;
}

// ============================================================================
// [VERIFIED] core::MemoryAllocatorMalloc::vfunc_04 (0x006DF730, 26 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// bin: pc
// va: 0x006DF730
// what: 
// tool: the portal's starter code (no AI)

// core::MemoryAllocatorMalloc::vfunc_04 (PC 0x006DF730, 26 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_0072F158;

namespace core {

class MemoryAllocatorMalloc
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual int vfunc_04(int a1);
};

int MemoryAllocatorMalloc::vfunc_04(int a1)
{
    int r_eax;

    r_eax = a1;
    if (!a1) {
        r_eax = 1;
    }
    r_eax = ((int (__cdecl*)(int))DAT_0072F158)(r_eax);
    return r_eax;
}

}

// ============================================================================
// [VERIFIED] core::MemoryAllocatorMalloc::vfunc_05 (0x006DF750, 15 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// bin: pc
// va: 0x006DF750
// what: 
// tool: the portal's starter code (no AI)

// core::MemoryAllocatorMalloc::vfunc_05 (PC 0x006DF750, 15 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_0072F15C;

namespace core {

class MemoryAllocatorMalloc
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual void vfunc_05(int a1);
};

void MemoryAllocatorMalloc::vfunc_05(int a1)
{
    ((void (__cdecl*)(int))DAT_0072F15C)(a1);
}

}

// ============================================================================
// [VERIFIED] core::MemoryAllocatorMalloc::vfunc_07 (0x006DF760, 21 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as core::MemoryAllocatorMalloc::vfunc_07 (Proto 0x00248F00), which was matched first;
// its addresses and names were swapped for this function's.
// core::MemoryAllocatorMalloc::vfunc_07 (Proto 0x006DF760, 21 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __cdecl sub_006DF780(int, int);

namespace core {

class MemoryAllocatorMalloc
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual void vfunc_05();
    virtual void vfunc_06();
    virtual void vfunc_07(int a1, int a2);
};

void MemoryAllocatorMalloc::vfunc_07(int a1, int a2)
{
    sub_006DF780(a1, a2);
}

}

// [TODO] 0x006DF780 sub_006DF780 (55 B)
// ============================================================================
// [VERIFIED] core::MemoryAllocatorMalloc::vfunc_08 (0x006DF7C0, 22 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// bin: pc
// va: 0x006DF7C0
// what: 
// tool: the portal's starter code (no AI)

// core::MemoryAllocatorMalloc::vfunc_08 (PC 0x006DF7C0, 22 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_0072F15C;

namespace core {

class MemoryAllocatorMalloc
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
    virtual void vfunc_08(int a1);
};

void MemoryAllocatorMalloc::vfunc_08(int a1)
{
    if (a1) {
        ((void (__cdecl*)(int))DAT_0072F15C)(*(int*)(a1 + -4));
    }
}

}

// ============================================================================
// [VERIFIED] pure3d::pddiDisplay::vfunc_09 (0x006DF7E0, 5 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// bin: pc
// va: 0x006DF7E0
// what: 
// tool: the portal's starter code (no AI)

// pure3d::pddiDisplay::vfunc_09 (PC 0x006DF7E0, 5 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

namespace pure3d {

class pddiDisplay
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
    virtual bool vfunc_09(int a1, int a2, int a3, int a4);
};

bool pddiDisplay::vfunc_09(int a1, int a2, int a3, int a4)
{
    return false;
}

}

// ============================================================================
// [VERIFIED] core::MemoryAllocatorMalloc::vfunc_12 (0x006DF7F0, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as core::MemoryAllocatorMalloc::vfunc_12 (0x0028D100), which was matched first;
// its addresses and names were swapped for this function's.
// core::MemoryAllocatorMalloc::vfunc_12 (0x006DF7F0, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_0085AF08;

namespace core {

class MemoryAllocatorMalloc
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
    virtual int vfunc_12();
};

int MemoryAllocatorMalloc::vfunc_12()
{
    return DAT_0085AF08;
}

}

// ============================================================================
// [VERIFIED] sub_006DF960 (0x006DF960, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_0001E5D0 (0x0001E5D0), which was matched first;
// its addresses and names were swapped for this function's.
// sub_006DF960 (0x006DF960, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_0085CD34;

int __cdecl sub_006DF960(void)
{
    return DAT_0085CD34;
}

// [TODO] 0x006DF9E0 sub_006DF9E0 (191 B)
// [TODO] 0x006DFB40 sub_006DFB40 (370 B)
// [TODO] 0x006DFD00 sub_006DFD00 (322 B)
// [TODO] 0x006DFFC0 sub_006DFFC0 (74 B)
// ============================================================================
// [VERIFIED] GameMemorySegmentCollection::vfunc_00 (0x006E0010, 5 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G7 /Gd /GR /EHsc /Zp4
// ============================================================================
// bin: pc
// va: 0x006E0010
// what: 
// tool: the portal's starter code (no AI)

// GameMemorySegmentCollection::vfunc_00 (PC 0x006E0010, 5 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

class GameMemorySegmentCollection
{
public:
    virtual void vfunc_00();
    char m_pad04[0x8];
    int m_Field0C; // +0x0C
};

void GameMemorySegmentCollection::vfunc_00()
{
    m_Field0C += 1;
}

// [TODO] 0x006E0020 core::String::vfunc_05 (110 B)
// ============================================================================
// [VERIFIED] core::String::vfunc_04 (0x006E0090, 36 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// bin: pc
// va: 0x006E0090
// what: 
// tool: the portal's starter code (no AI)

// core::String::vfunc_04 (PC 0x006E0090, 36 bytes)
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
    virtual int vfunc_08();
};

namespace core {

class String
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual bool vfunc_04(int a1);
    virtual bool vfunc_05(int);
};

bool String::vfunc_04(int a1)
{
    if (a1) {
        return vfunc_05(((Object*)a1)->vfunc_08());
    }
    return false;
}

}

// ============================================================================
// [VERIFIED] core::String::vfunc_24 (0x006E00C0, 9 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// What it does: Returns the number at +0x14 with its top bit cleared.
// ============================================================================
// bin: pc
// va: 0x006E00C0
// what: Returns the number at +0x14 with its top bit cleared.
// tool: Claude Opus 5.5 (transplanted from proto:0x000FAB90, nearest by portal/tools/similar.py)
// sub_006E00C0 (Proto 0x006E00C0, 12 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

class Class_006E00C0
{
public:
    int sub_006E00C0();
    char m_pad00[0x14];
    int m_Field14; // +0x14
};

int Class_006E00C0::sub_006E00C0()
{
    return m_Field14 & 2147483647;
}

// [TODO] 0x006E00D0 core::String::vfunc_23 (100 B)
// [TODO] 0x006E0140 core::String::vfunc_07 (160 B)
// ============================================================================
// [VERIFIED] core::String::vfunc_06 (0x006E01E0, 34 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// bin: pc
// va: 0x006E01E0
// what: 
// tool: the portal's starter code (no AI)

// core::String::vfunc_06 (PC 0x006E01E0, 34 bytes)
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
    virtual int vfunc_08();
};

namespace core {

class String
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual void vfunc_05();
    virtual void vfunc_06(int a1);
    virtual void vfunc_07(int);
};

void String::vfunc_06(int a1)
{
    if (a1) {
        if (a1 == (int)this) goto L_1E;
        vfunc_07(((Object*)a1)->vfunc_08());
    }
L_1E:
    ;
}

}

// [TODO] 0x006E0210 core::String::vfunc_09 (54 B)
// ============================================================================
// [VERIFIED] core::String::vfunc_08 (0x006E0250, 17 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// bin: pc
// va: 0x006E0250
// what: 
// tool: the portal's starter code (no AI)

// core::String::vfunc_08 (PC 0x006E0250, 17 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

namespace core {

class String
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
    char m_pad04[0xC];
    int m_Field10; // +0x10
    int m_Field14; // +0x14
};

int String::vfunc_08()
{
    if (((unsigned char)(((unsigned int)m_Field14) >> 31)) & 1) {
        return 0;
    }
    return m_Field10;
}

}

// [TODO] 0x006E0270 core::String::vfunc_10 (31 B)
// ============================================================================
// [VERIFIED] core::String::vfunc_18 (0x006E0290, 30 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// bin: pc
// va: 0x006E0290
// what: 
// tool: the portal's starter code (no AI)

// core::String::vfunc_18 (PC 0x006E0290, 30 bytes)
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
    virtual int vfunc_08();
};

namespace core {

class String
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
    virtual void vfunc_17(int);
    virtual void vfunc_18(int a1);
};

void String::vfunc_18(int a1)
{
    if (a1) {
        vfunc_17(((Object*)a1)->vfunc_08());
    }
}

}

// [TODO] 0x006E02B0 core::String::vfunc_17 (293 B)
// ============================================================================
// [VERIFIED] core::String::vfunc_16 (0x006E03E0, 5 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// bin: pc
// va: 0x006E03E0
// what: 
// tool: the portal's starter code (no AI)

// core::String::vfunc_16 (PC 0x006E03E0, 5 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

namespace core {

class String
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
};

void String::vfunc_16()
{
    vfunc_15();
}

}

// [TODO] 0x006E03F0 core::String::vfunc_15 (55 B)
// [TODO] 0x006E0430 core::String::vfunc_14 (26 B)
// [TODO] 0x006E0450 core::String::vfunc_12 (54 B)
// [TODO] 0x006E0490 core::String::vfunc_11 (26 B)
// ============================================================================
// [VERIFIED] core::String::vfunc_19 (0x006E04B0, 22 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// bin: pc
// va: 0x006E04B0
// what: 
// tool: the portal's starter code (no AI)

// core::String::vfunc_19 (PC 0x006E04B0, 22 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_0072F23C;

namespace core {

class String
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
    char m_pad04[0xC];
    int m_Field10; // +0x10
    int m_Field14; // +0x14
};

void String::vfunc_19()
{
    if (!(((unsigned char)(((unsigned int)m_Field14) >> 31)) & 1)) {
        ((void (__cdecl*)(int))DAT_0072F23C)(m_Field10);
    }
}

}

// ============================================================================
// [VERIFIED] core::String::vfunc_20 (0x006E04D0, 22 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as core::String::vfunc_19 (PC 0x006E04B0), which was matched first;
// its addresses and names were swapped for this function's.
// bin: pc
// va: 0x006E04D0
// what: 
// tool: the portal's starter code (no AI)

// core::String::vfunc_20 (PC 0x006E04D0, 22 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_0072F238;

namespace core {

class String
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
    char m_pad04[0xC];
    int m_Field10; // +0x10
    int m_Field14; // +0x14
};

void String::vfunc_20()
{
    if (!(((unsigned char)(((unsigned int)m_Field14) >> 31)) & 1)) {
        ((void (__cdecl*)(int))DAT_0072F238)(m_Field10);
    }
}

}

// ============================================================================
// [VERIFIED] core::String::vfunc_22 (0x006E04F0, 20 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// bin: pc
// va: 0x006E04F0
// what: 
// tool: the portal's starter code (no AI)

// core::String::vfunc_22 (PC 0x006E04F0, 20 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __cdecl sub_006DE7A0(int, int);

namespace core {

class String
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
    virtual void vfunc_22(int a1);
    char m_pad04[0xC];
    int m_Field10; // +0x10
};

void String::vfunc_22(int a1)
{
    sub_006DE7A0(m_Field10, a1);
}

}

// ============================================================================
// [VERIFIED] core::String::vfunc_21 (0x006E0510, 36 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// bin: pc
// va: 0x006E0510
// what: 
// tool: the portal's starter code (no AI)

// core::String::vfunc_21 (PC 0x006E0510, 36 bytes)
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
    virtual int vfunc_08();
};

namespace core {

class String
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
    virtual bool vfunc_21(int a1);
    virtual bool vfunc_22(int);
};

bool String::vfunc_21(int a1)
{
    if (a1) {
        return vfunc_22(((Object*)a1)->vfunc_08());
    }
    return false;
}

}

// ============================================================================
// [VERIFIED] core::String::vfunc_03 (0x006E0540, 36 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as core::ControllerSystemXBox::vfunc_03 (0x00248820), which was matched first;
// its addresses and names were swapped for this function's.
// core::String::vfunc_03 (0x006E0540, 36 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_007F5A70;
extern "C" void __cdecl sub_006DC430(int, int);
extern "C" void __cdecl sub_006E0570(void);

namespace core {

class String
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual String* vfunc_03(int a1);
};

String* String::vfunc_03(int a1)
{
    sub_006E0570();
    if (a1 & 1) {
        sub_006DC430(DAT_007F5A70, (int)this);
    }
    return this;
}

}

// ============================================================================
// [VERIFIED] sub_006E0570 (0x006E0570, 67 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// bin: pc
// va: 0x006E0570
// what: 
// tool: the portal's starter code (no AI)

// sub_006E0570 (PC 0x006E0570, 67 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0073523C[];
extern "C" char DAT_00736074[];
extern "C" char DAT_00771A50[];
extern "C" char DAT_00771A5C[];
extern "C" int DAT_007F5A70;
extern "C" void __cdecl sub_006DC430(int, int);

class Class_006E0570
{
public:
    void sub_006E0570();
    int m_Field00; // +0x00
    int m_Field04; // +0x04
    int m_Field08; // +0x08
    char m_pad0C[0x4];
    int m_Field10; // +0x10
};

void Class_006E0570::sub_006E0570()
{
    int t1;

    t1 = m_Field10;
    m_Field00 = (int)DAT_00771A5C;
    m_Field04 = (int)DAT_00771A50;
    if (m_Field10) {
        sub_006DC430(m_Field08, t1);
        m_Field10 = 0;
    }
    DAT_007F5A70 = m_Field08;
    m_Field04 = (int)DAT_00736074;
    m_Field00 = (int)DAT_0073523C;
}

// ============================================================================
// [VERIFIED] core::String::vfunc_00 (0x006E05C0, 8 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as core::ControllerSystemXBox::vfunc_00 (0x00248810), which was matched first;
// its addresses and names were swapped for this function's.
// core::String::vfunc_00 (0x006E05C0, 8 bytes)
// An adjustor thunk. Nobody wrote this function: the compiler adds it for a class with two base
// classes that both declare the same virtual function. Called through the second base's table, it
// moves `this` back 4 bytes to the start of the object and jumps to the real function at
// 0x006E0540. So it is matched by declaring the class that way, not by writing a body.
// The two bases and their names are guesses; the first base is the part of the object in front
// of the second base (4 bytes).

namespace core {
class ControllerSystemXBox_Base0 { public: virtual void sub_006E0540(); };
class ControllerSystemXBox_Base1 { public: virtual void sub_006E0540(); };

class String : public ControllerSystemXBox_Base0, public ControllerSystemXBox_Base1
{
public:
    String();
    virtual void sub_006E0540();          // the real function; the thunk jumps here
};

String::String() {}                  // building one is what makes the compiler write its tables and the thunk
}

// [TODO] 0x006E05D0 sub_006E05D0 (47 B)
// [TODO] 0x006E0780 sub_006E0780 (60 B)
// ============================================================================
// [VERIFIED] core::MemoryDlAllocator::vfunc_00 (0x006E0930, 5 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G7 /Gd /GR /EHsc /Zp4
// ============================================================================
// bin: pc
// va: 0x006E0930
// what: 
// tool: the portal's starter code (no AI)

// core::MemoryDlAllocator::vfunc_00 (PC 0x006E0930, 5 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

namespace core {

class MemoryDlAllocator
{
public:
    virtual void vfunc_00();
    char m_pad04[0x38];
    int m_Field3C; // +0x3C
};

void MemoryDlAllocator::vfunc_00()
{
    m_Field3C += 1;
}

}

// [TODO] 0x006E0940 core::MemoryDlAllocator::vfunc_11 (159 B)
// [TODO] 0x006E09E0 core::MemoryDlAllocator::vfunc_06 (28 B)
// [TODO] 0x006E0A00 core::MemoryDlAllocator::vfunc_10 (86 B)
// ============================================================================
// [VERIFIED] core::MemoryDlAllocator::vfunc_03 (0x006E0A60, 36 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as core::ControllerSystemXBox::vfunc_03 (0x00248820), which was matched first;
// its addresses and names were swapped for this function's.
// core::MemoryDlAllocator::vfunc_03 (0x006E0A60, 36 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_007F5A70;
extern "C" void __cdecl sub_006DC430(int, int);
extern "C" void __cdecl sub_006E0A90(void);

namespace core {

class MemoryDlAllocator
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual MemoryDlAllocator* vfunc_03(int a1);
};

MemoryDlAllocator* MemoryDlAllocator::vfunc_03(int a1)
{
    sub_006E0A90();
    if (a1 & 1) {
        sub_006DC430(DAT_007F5A70, (int)this);
    }
    return this;
}

}

// [TODO] 0x006E0A90 sub_006E0A90 (35 B)
// ============================================================================
// [VERIFIED] core::MemoryDlAllocator::vfunc_00 (0x006E0AC0, 8 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as core::ControllerSystemXBox::vfunc_00 (0x00248810), which was matched first;
// its addresses and names were swapped for this function's.
// core::MemoryDlAllocator::vfunc_00 (0x006E0AC0, 8 bytes)
// An adjustor thunk. Nobody wrote this function: the compiler adds it for a class with two base
// classes that both declare the same virtual function. Called through the second base's table, it
// moves `this` back 4 bytes to the start of the object and jumps to the real function at
// 0x006E0A60. So it is matched by declaring the class that way, not by writing a body.
// The two bases and their names are guesses; the first base is the part of the object in front
// of the second base (4 bytes).

namespace core {
class ControllerSystemXBox_Base0 { public: virtual void sub_006E0A60(); };
class ControllerSystemXBox_Base1 { public: virtual void sub_006E0A60(); };

class MemoryDlAllocator : public ControllerSystemXBox_Base0, public ControllerSystemXBox_Base1
{
public:
    MemoryDlAllocator();
    virtual void sub_006E0A60();          // the real function; the thunk jumps here
};

MemoryDlAllocator::MemoryDlAllocator() {}                  // building one is what makes the compiler write its tables and the thunk
}

// [TODO] 0x006E0BB0 core::MemoryDlAllocator::vfunc_05 (200 B)
// [TODO] 0x006E0C80 core::MemoryDlAllocator::vfunc_04 (133 B)
// ============================================================================
// [VERIFIED] sub_006E0D10 (0x006E0D10, 42 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G7 /Gd /GR /EHsc /Zp4
// What it does: Works out how much usable room a memory block has from the header just before it, or 0 for none.
// ============================================================================
// bin: pc
// va: 0x006E0D10
// what: Works out how much usable room a memory block has from the header just before it, or 0 for none.
// tool: Claude Opus 5.5 (transplanted from proto:0x0024B330, nearest by portal/tools/similar.py)
// sub_006E0D10 (Proto 0x006E0D10, 44 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

int __cdecl sub_006E0D10(int a1)
{
    int r_eax;

    if (a1) {
        r_eax = *(int*)(a1 + -4);
        if (((unsigned char)r_eax) & 2) {
            r_eax &= -4;
            r_eax -= 8;
            return r_eax;
        }
        if (!(*(int*)((r_eax & -2) + a1 + -4) & 1)) goto L_29;
        r_eax &= -4;
        r_eax -= 4;
        return r_eax;
    }
L_29:
    r_eax = 0;
    return r_eax;
}

// [TODO] 0x006E11C0 sub_006E11C0 (493 B)
// [TODO] 0x006E13B0 core::MemoryDlAllocator::vfunc_07 (117 B)
// [TODO] 0x006E1430 sub_006E1430 (331 B)
// [TODO] 0x006E1580 sub_006E1580 (244 B)
// [TODO] 0x006E1680 sub_006E1680 (36 B)
// [TODO] 0x006E16B0 sub_006E16B0 (31 B)
// [TODO] 0x006E16D0 sub_006E16D0 (42 B)
// [TODO] 0x006E1700 sub_006E1700 (35 B)
// [TODO] 0x006E1730 sub_006E1730 (27 B)
// [TODO] 0x006E1750 sub_006E1750 (36 B)
// [TODO] 0x006E1780 sub_006E1780 (25 B)
// [TODO] 0x006E1820 sub_006E1820 (802 B)
// [TODO] 0x006E1B50 sub_006E1B50 (60 B)
// ============================================================================
// [VERIFIED] core::MemoryDlAllocator::vfunc_02 (0x006E1CF0, 4 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// core::MemoryDlAllocator::vfunc_02 (PC 0x006E1CF0, 4 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

namespace core {

class MemoryDlAllocator
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual int vfunc_02();
    char m_pad04[0x38];
    int m_Field3C; // +0x3C
};

int MemoryDlAllocator::vfunc_02()
{
    return m_Field3C;
}

}

// ============================================================================
// [VERIFIED] core::MemorySmallDlAllocator::vfunc_10 (0x006E1D00, 61 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as core::MemorySmallDlAllocator::vfunc_10 (Proto 0x0024C630), which was matched first;
// its addresses and names were swapped for this function's.
// core::MemorySmallDlAllocator::vfunc_10 (Proto 0x006E1D00, 61 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

namespace core {

class MemorySmallDlAllocator
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
    virtual bool vfunc_10(int a1, int a2, int a3, int a4);
};

bool MemorySmallDlAllocator::vfunc_10(int a1, int a2, int a3, int a4)
{
    int r_ecx;

    r_ecx = (int)this;
    if (a1) {
        *(int*)a1 = *(int*)(r_ecx + 24) - *(int*)(r_ecx + 44);
    }
    if (a2) {
        *(int*)a2 = 0;
    }
    if (a3) {
        *(int*)a3 = *(int*)(r_ecx + 40);
    }
    if (a4) {
        r_ecx = *(int*)(r_ecx + 48);
        *(int*)a4 = r_ecx;
    }
    return true;
}

}

// ============================================================================
// [VERIFIED] core::MemorySmallDlAllocator::vfunc_03 (0x006E1D40, 36 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as core::ControllerSystemXBox::vfunc_03 (0x00248820), which was matched first;
// its addresses and names were swapped for this function's.
// core::MemorySmallDlAllocator::vfunc_03 (0x006E1D40, 36 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_007F5A70;
extern "C" void __cdecl sub_006DC430(int, int);
extern "C" void __cdecl sub_006E1D70(void);

namespace core {

class MemorySmallDlAllocator
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual MemorySmallDlAllocator* vfunc_03(int a1);
};

MemorySmallDlAllocator* MemorySmallDlAllocator::vfunc_03(int a1)
{
    sub_006E1D70();
    if (a1 & 1) {
        sub_006DC430(DAT_007F5A70, (int)this);
    }
    return this;
}

}

// [TODO] 0x006E1D70 sub_006E1D70 (35 B)
// ============================================================================
// [VERIFIED] core::MemorySmallDlAllocator::vfunc_00 (0x006E1DA0, 8 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as core::ControllerSystemXBox::vfunc_00 (0x00248810), which was matched first;
// its addresses and names were swapped for this function's.
// core::MemorySmallDlAllocator::vfunc_00 (0x006E1DA0, 8 bytes)
// An adjustor thunk. Nobody wrote this function: the compiler adds it for a class with two base
// classes that both declare the same virtual function. Called through the second base's table, it
// moves `this` back 4 bytes to the start of the object and jumps to the real function at
// 0x006E1D40. So it is matched by declaring the class that way, not by writing a body.
// The two bases and their names are guesses; the first base is the part of the object in front
// of the second base (4 bytes).

namespace core {
class ControllerSystemXBox_Base0 { public: virtual void sub_006E1D40(); };
class ControllerSystemXBox_Base1 { public: virtual void sub_006E1D40(); };

class MemorySmallDlAllocator : public ControllerSystemXBox_Base0, public ControllerSystemXBox_Base1
{
public:
    MemorySmallDlAllocator();
    virtual void sub_006E1D40();          // the real function; the thunk jumps here
};

MemorySmallDlAllocator::MemorySmallDlAllocator() {}                  // building one is what makes the compiler write its tables and the thunk
}

// [TODO] 0x006E1DB0 core::MemoryDlAllocator::vfunc_01 (79 B)
// [TODO] 0x006E1E00 core::MemorySmallDlAllocator::vfunc_05 (229 B)
// [TODO] 0x006E1EF0 sub_006E1EF0 (724 B)
// [TODO] 0x006E21D0 core::MemorySmallDlAllocator::vfunc_04 (167 B)
// [TODO] 0x006E2280 sub_006E2280 (232 B)
// [TODO] 0x006E2DB0 sub_006E2DB0 (673 B)
// [TODO] 0x006E3060 core::MemorySmallDlAllocator::vfunc_07 (151 B)
// [TODO] 0x006E3100 sub_006E3100 (482 B)
// [TODO] 0x006E32F0 sub_006E32F0 (244 B)
// [TODO] 0x006E3630 sub_006E3630 (50 B)
// ============================================================================
// [VERIFIED] core::CompletionEventRequest::vfunc_01 (0x006E36A0, 18 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as core::CompletionEventRequest::vfunc_01 (Proto 0x0026C170), which was matched first;
// its addresses and names were swapped for this function's.
// core::CompletionEventRequest::vfunc_01 (Proto 0x006E36A0, 18 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __cdecl sub_006DF0D0(int);

namespace core {

class CompletionEventRequest
{
public:
    virtual void vfunc_00();
    virtual int vfunc_01();
    char m_pad04[0x4];
    int m_Field08; // +0x08
};

int CompletionEventRequest::vfunc_01()
{
    sub_006DF0D0(m_Field08);
    return 1;
}

}

// ============================================================================
// [VERIFIED] core::CompletionEventRequest::vfunc_06 (0x006E36C0, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// What it does: core::CompletionEventRequest: Always returns 23.
// ============================================================================
// Same machine code as core::CompletionEventRequest::vfunc_06 (0x002A98D0), which was matched first;
// its addresses and names were swapped for this function's.
// core::CompletionEventRequest::vfunc_06 (0x006E36C0, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

namespace core {

class CompletionEventRequest
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual void vfunc_05();
    virtual int vfunc_06();
};

int CompletionEventRequest::vfunc_06()
{
    return 23;
}

}

// [TODO] 0x006E36D0 core::FileCompletionRequest::vfunc_07 (46 B)
// ============================================================================
// [VERIFIED] core::FileCompletionRequest::vfunc_01 (0x006E3700, 18 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as core::FileCompletionRequest::vfunc_01 (Proto 0x0026C1D0), which was matched first;
// its addresses and names were swapped for this function's.
// core::FileCompletionRequest::vfunc_01 (Proto 0x006E3700, 18 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_006E6120(int);
};

namespace core {

class FileCompletionRequest
{
public:
    virtual void vfunc_00();
    virtual int vfunc_01();
    char m_pad04[0x8];
    int m_Field0C; // +0x0C
};

int FileCompletionRequest::vfunc_01()
{
    ((Object*)*(int*)(m_Field0C + 12))->sub_006E6120((int)this);
    return 3;
}

}

// [TODO] 0x006E3720 core::DriveCompletionRequest::vfunc_07 (46 B)
// ============================================================================
// [VERIFIED] core::FileCompletionRequest::vfunc_03 (0x006E3750, 7 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as core::FileCompletionRequest::vfunc_03 (Proto 0x0026C220), which was matched first;
// its addresses and names were swapped for this function's.
// core::FileCompletionRequest::vfunc_03 (Proto 0x006E3750, 7 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

namespace core {

class FileCompletionRequest
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual int vfunc_03();
    char m_pad04[0x8];
    int m_Field0C; // +0x0C
};

int FileCompletionRequest::vfunc_03()
{
    return *(int*)(m_Field0C + 12);
}

}

// ============================================================================
// [VERIFIED] core::DriveCompletionRequest::vfunc_06 (0x006E3760, 6 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// What it does: core::DriveCompletionRequest: Always returns 22.
// ============================================================================
// Same machine code as core::CompletionEventRequest::vfunc_06 (Proto 0x0026C190), which was matched first;
// its addresses and names were swapped for this function's.
// core::DriveCompletionRequest::vfunc_06 (Proto 0x006E3760, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

namespace core {

class DriveCompletionRequest
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual void vfunc_05();
    virtual int vfunc_06();
};

int DriveCompletionRequest::vfunc_06()
{
    return 22;
}

}

// ============================================================================
// [VERIFIED] core::FileRequest::vfunc_02 (0x006E3770, 15 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G7 /Gd /GR /EHsc /Zp4
// ============================================================================
// bin: pc
// va: 0x006E3770
// what: 
// tool: the portal's starter code (no AI)

// core::FileRequest::vfunc_02 (PC 0x006E3770, 15 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

namespace core {

class FileRequest
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual int vfunc_02(int a1);
    char m_pad04[0x4];
    int m_Field08; // +0x08
};

int FileRequest::vfunc_02(int a1)
{
    return a1 == m_Field08;
}

}

// [TODO] 0x006E3780 core::FileRequest::vfunc_04 (63 B)
// ============================================================================
// [VERIFIED] core::FileRequest::vfunc_05 (0x006E37C0, 8 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as core::FileRequest::vfunc_05 (Proto 0x0026C280), which was matched first;
// its addresses and names were swapped for this function's.
// core::FileRequest::vfunc_05 (Proto 0x006E37C0, 8 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field08
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
    virtual void vfunc_23();
    virtual void vfunc_24();
    virtual void vfunc_25();
    virtual void vfunc_26();
};

namespace core {

class FileRequest
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual void vfunc_05();
    char m_pad04[0x4];
    Field08* m_Field08; // +0x08
};

void FileRequest::vfunc_05()
{
    m_Field08->vfunc_26();
}

}

// [TODO] 0x006E37D0 core::FileOpenRequest::vfunc_01 (561 B)
// [TODO] 0x006E3A10 core::FileOpenByKeyRequest::vfunc_01 (195 B)
// [TODO] 0x006E3AE0 core::SaveGameOpenRequest::vfunc_01 (127 B)
// [TODO] 0x006E3B60 core::FileCloseRequest::vfunc_01 (110 B)
// [TODO] 0x006E3BD0 core::FileCommitRequest::vfunc_01 (75 B)
// ============================================================================
// [VERIFIED] fight::ParamString<UpperBodyAnimStateCondition>::vfunc_01 (0x006E3C20, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as fight::ParamString<TimedCharacterFightTrack>::vfunc_01 (0x00022A00), which was matched first;
// its addresses and names were swapped for this function's.
// fight::ParamString<UpperBodyAnimStateCondition>::vfunc_01 (0x006E3C20, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

class UpperBodyAnimStateCondition;

namespace fight { 
template <class T0> class ParamString
{
public:
    virtual void vfunc_00();
    virtual int vfunc_01();
};
}

template <> int fight::ParamString<UpperBodyAnimStateCondition>::vfunc_01()
{
    return 3;
}

// [TODO] 0x006E3C30 core::FileReadRequest::vfunc_01 (266 B)
// [TODO] 0x006E3D40 core::FileWriteRequest::vfunc_01 (144 B)
// ============================================================================
// [VERIFIED] fight::ParamEnumConstList<DirectionalGetHitCondition>::vfunc_01 (0x006E3DD0, 6 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// What it does: fight::ParamEnumConstList<DirectionalGetHitCondition>: Always returns 5.
// ============================================================================
// Same machine code as fight::ParamEnumConstList<DirectionalGetHitCondition>::vfunc_01 (Proto 0x000CB900), which was matched first;
// its addresses and names were swapped for this function's.
// fight::ParamEnumConstList<DirectionalGetHitCondition>::vfunc_01 (Proto 0x006E3DD0, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

class DirectionalGetHitCondition;

namespace fight { 
template <class T0> class ParamEnumConstList
{
public:
    virtual void vfunc_00();
    virtual int vfunc_01();
};
}

template <> int fight::ParamEnumConstList<DirectionalGetHitCondition>::vfunc_01()
{
    return 5;
}

// [TODO] 0x006E3DE0 core::FileSetPositionRequest::vfunc_01 (55 B)
// [TODO] 0x006E3E20 core::FileGetPositionRequest::vfunc_01 (56 B)
// ============================================================================
// [VERIFIED] core::FileGetPositionRequest::vfunc_06 (0x006E3E60, 6 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// What it does: core::FileGetPositionRequest: Always returns 7.
// ============================================================================
// Same machine code as core::FileGetPositionRequest::vfunc_06 (Proto 0x0026C8F0), which was matched first;
// its addresses and names were swapped for this function's.
// core::FileGetPositionRequest::vfunc_06 (Proto 0x006E3E60, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

namespace core {

class FileGetPositionRequest
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual void vfunc_05();
    virtual int vfunc_06();
};

int FileGetPositionRequest::vfunc_06()
{
    return 7;
}

}

// [TODO] 0x006E3E70 core::FileGetSizeRequest::vfunc_01 (56 B)
// ============================================================================
// [VERIFIED] DealerSpawnObject::vfunc_45 (0x006E3EB0, 6 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// What it does: DealerSpawnObject: Always returns 8.
// ============================================================================
// Same machine code as DealerSpawnObject::vfunc_43 (Proto 0x0021E9A0), which was matched first;
// its addresses and names were swapped for this function's.
// DealerSpawnObject::vfunc_45 (Proto 0x006E3EB0, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

class DealerSpawnObject
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
    virtual void vfunc_30();
    virtual void vfunc_31();
    virtual void vfunc_32();
    virtual void vfunc_33();
    virtual void vfunc_34();
    virtual void vfunc_35();
    virtual void vfunc_36();
    virtual void vfunc_37();
    virtual void vfunc_38();
    virtual void vfunc_39();
    virtual void vfunc_40();
    virtual void vfunc_41();
    virtual void vfunc_42();
    virtual void vfunc_43();
    virtual void vfunc_44();
    virtual int vfunc_45();
};

int DealerSpawnObject::vfunc_45()
{
    return 8;
}

// [TODO] 0x006E3EC0 core::FileCancelRequest::vfunc_01 (59 B)
// ============================================================================
// [VERIFIED] fight::ParamBranch<ExitConditionTrack>::vfunc_01 (0x006E3F00, 6 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// What it does: fight::ParamBranch<ExitConditionTrack>: Always returns 9.
// ============================================================================
// Same machine code as fight::ParamBranch<ExitConditionTrack>::vfunc_01 (Proto 0x000D6C80), which was matched first;
// its addresses and names were swapped for this function's.
// fight::ParamBranch<ExitConditionTrack>::vfunc_01 (Proto 0x006E3F00, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

class ExitConditionTrack;

namespace fight { 
template <class T0> class ParamBranch
{
public:
    virtual void vfunc_00();
    virtual int vfunc_01();
};
}

template <> int fight::ParamBranch<ExitConditionTrack>::vfunc_01()
{
    return 9;
}

// ============================================================================
// [VERIFIED] core::FileRequest::vfunc_03 (0x006E3F10, 7 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as core::FileRequest::vfunc_03 (Proto 0x0026C9A0), which was matched first;
// its addresses and names were swapped for this function's.
// core::FileRequest::vfunc_03 (Proto 0x006E3F10, 7 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

namespace core {

class FileRequest
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual int vfunc_03();
    char m_pad04[0x4];
    int m_Field08; // +0x08
};

int FileRequest::vfunc_03()
{
    return *(int*)(m_Field08 + 12);
}

}

// [TODO] 0x006E3F20 core::DriveRequest::vfunc_04 (63 B)
// ============================================================================
// [VERIFIED] core::DriveOpenRequest::vfunc_06 (0x006E3F60, 6 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// What it does: core::DriveOpenRequest: Always returns 11.
// ============================================================================
// Same machine code as core::DriveOpenRequest::vfunc_06 (Proto 0x0026C9F0), which was matched first;
// its addresses and names were swapped for this function's.
// core::DriveOpenRequest::vfunc_06 (Proto 0x006E3F60, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

namespace core {

class DriveOpenRequest
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual void vfunc_05();
    virtual int vfunc_06();
};

int DriveOpenRequest::vfunc_06()
{
    return 11;
}

}

// [TODO] 0x006E3F70 core::DriveMediaRequest::vfunc_01 (78 B)
// ============================================================================
// [VERIFIED] core::DriveMediaRequest::vfunc_06 (0x006E3FC0, 6 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// What it does: core::DriveMediaRequest: Always returns 12.
// ============================================================================
// Same machine code as core::DriveMediaRequest::vfunc_06 (Proto 0x0026CA50), which was matched first;
// its addresses and names were swapped for this function's.
// core::DriveMediaRequest::vfunc_06 (Proto 0x006E3FC0, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

namespace core {

class DriveMediaRequest
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual void vfunc_05();
    virtual int vfunc_06();
};

int DriveMediaRequest::vfunc_06()
{
    return 12;
}

}

// [TODO] 0x006E3FD0 core::DriveFormatRequest::vfunc_01 (63 B)
// ============================================================================
// [VERIFIED] GlanceAtOvertakingPed::vfunc_10 (0x006E4010, 6 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// What it does: GlanceAtOvertakingPed: Always returns 13.
// ============================================================================
// Same machine code as GlanceAtOvertakingPed::vfunc_10 (Proto 0x0026CAA0), which was matched first;
// its addresses and names were swapped for this function's.
// GlanceAtOvertakingPed::vfunc_10 (Proto 0x006E4010, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

class GlanceAtOvertakingPed
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
    virtual int vfunc_10();
};

int GlanceAtOvertakingPed::vfunc_10()
{
    return 13;
}

// [TODO] 0x006E4020 core::DriveCreateDirectoryRequest::vfunc_01 (68 B)
// ============================================================================
// [VERIFIED] core::DriveCreateDirectoryRequest::vfunc_06 (0x006E4070, 6 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// What it does: core::DriveCreateDirectoryRequest: Always returns 14.
// ============================================================================
// Same machine code as core::DriveCreateDirectoryRequest::vfunc_06 (Proto 0x0026CB00), which was matched first;
// its addresses and names were swapped for this function's.
// core::DriveCreateDirectoryRequest::vfunc_06 (Proto 0x006E4070, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

namespace core {

class DriveCreateDirectoryRequest
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual void vfunc_05();
    virtual int vfunc_06();
};

int DriveCreateDirectoryRequest::vfunc_06()
{
    return 14;
}

}

// [TODO] 0x006E4080 core::DriveDestroyDirectoryRequest::vfunc_01 (68 B)
// ============================================================================
// [VERIFIED] core::DriveDestroyDirectoryRequest::vfunc_06 (0x006E40D0, 6 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// What it does: core::DriveDestroyDirectoryRequest: Always returns 15.
// ============================================================================
// Same machine code as core::DriveDestroyDirectoryRequest::vfunc_06 (Proto 0x0026CB60), which was matched first;
// its addresses and names were swapped for this function's.
// core::DriveDestroyDirectoryRequest::vfunc_06 (Proto 0x006E40D0, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

namespace core {

class DriveDestroyDirectoryRequest
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual void vfunc_05();
    virtual int vfunc_06();
};

int DriveDestroyDirectoryRequest::vfunc_06()
{
    return 15;
}

}

// [TODO] 0x006E40E0 core::DriveFindFirstRequest::vfunc_01 (110 B)
// ============================================================================
// [VERIFIED] GangSpawnObject::vfunc_45 (0x006E4150, 6 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// What it does: GangSpawnObject: Always returns 16.
// ============================================================================
// Same machine code as GangSpawnObject::vfunc_43 (Proto 0x00213E60), which was matched first;
// its addresses and names were swapped for this function's.
// GangSpawnObject::vfunc_45 (Proto 0x006E4150, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

class GangSpawnObject
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
    virtual void vfunc_30();
    virtual void vfunc_31();
    virtual void vfunc_32();
    virtual void vfunc_33();
    virtual void vfunc_34();
    virtual void vfunc_35();
    virtual void vfunc_36();
    virtual void vfunc_37();
    virtual void vfunc_38();
    virtual void vfunc_39();
    virtual void vfunc_40();
    virtual void vfunc_41();
    virtual void vfunc_42();
    virtual void vfunc_43();
    virtual void vfunc_44();
    virtual int vfunc_45();
};

int GangSpawnObject::vfunc_45()
{
    return 16;
}

// [TODO] 0x006E4160 core::DriveFindNextRequest::vfunc_01 (72 B)
// ============================================================================
// [VERIFIED] core::DriveFindNextRequest::vfunc_06 (0x006E41B0, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// What it does: core::DriveFindNextRequest: Always returns 17.
// ============================================================================
// Same machine code as core::DriveFindNextRequest::vfunc_06 (0x0006F9A0), which was matched first;
// its addresses and names were swapped for this function's.
// core::DriveFindNextRequest::vfunc_06 (0x006E41B0, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

namespace core {

class DriveFindNextRequest
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual void vfunc_05();
    virtual int vfunc_06();
};

int DriveFindNextRequest::vfunc_06()
{
    return 17;
}

}

// [TODO] 0x006E41C0 core::DriveFindCloseRequest::vfunc_01 (64 B)
// ============================================================================
// [VERIFIED] core::DriveFindCloseRequest::vfunc_06 (0x006E4200, 6 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// What it does: core::DriveFindCloseRequest: Always returns 18.
// ============================================================================
// Same machine code as core::DriveFindCloseRequest::vfunc_06 (Proto 0x0026CC80), which was matched first;
// its addresses and names were swapped for this function's.
// core::DriveFindCloseRequest::vfunc_06 (Proto 0x006E4200, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

namespace core {

class DriveFindCloseRequest
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual void vfunc_05();
    virtual int vfunc_06();
};

int DriveFindCloseRequest::vfunc_06()
{
    return 18;
}

}

// [TODO] 0x006E4210 core::DriveFileDestroyRequest::vfunc_01 (68 B)
// ============================================================================
// [VERIFIED] pure3d::d3dContext::vfunc_22 (0x006E4260, 4 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// pure3d::d3dContext::vfunc_22 (PC 0x006E4260, 4 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

namespace pure3d {

class d3dContext
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
    virtual void* vfunc_22();
    char m_pad04[0x8];
    int m_Field0C; // +0x0C
};

void* d3dContext::vfunc_22()
{
    return &m_Field0C;
}

}

// ============================================================================
// [VERIFIED] core::DriveFileDestroyRequest::vfunc_06 (0x006E4270, 6 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// What it does: core::DriveFileDestroyRequest: Always returns 19.
// ============================================================================
// Same machine code as core::DriveFileDestroyRequest::vfunc_06 (Proto 0x0026CCE0), which was matched first;
// its addresses and names were swapped for this function's.
// core::DriveFileDestroyRequest::vfunc_06 (Proto 0x006E4270, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

namespace core {

class DriveFileDestroyRequest
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual void vfunc_05();
    virtual int vfunc_06();
};

int DriveFileDestroyRequest::vfunc_06()
{
    return 19;
}

}

// [TODO] 0x006E4280 core::DriveCancelRequest::vfunc_01 (59 B)
// ============================================================================
// [VERIFIED] core::DriveCancelRequest::vfunc_06 (0x006E42C0, 6 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// What it does: core::DriveCancelRequest: Always returns 20.
// ============================================================================
// Same machine code as core::DriveCancelRequest::vfunc_06 (Proto 0x0026CD30), which was matched first;
// its addresses and names were swapped for this function's.
// core::DriveCancelRequest::vfunc_06 (Proto 0x006E42C0, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

namespace core {

class DriveCancelRequest
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual void vfunc_05();
    virtual int vfunc_06();
};

int DriveCancelRequest::vfunc_06()
{
    return 20;
}

}

// ============================================================================
// [VERIFIED] core::DriveLockRequest::vfunc_06 (0x006E42D0, 6 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// What it does: core::DriveLockRequest: Always returns 21.
// ============================================================================
// Same machine code as core::DriveCompletionRequest::vfunc_06 (Proto 0x0026C230), which was matched first;
// its addresses and names were swapped for this function's.
// core::DriveLockRequest::vfunc_06 (Proto 0x006E42D0, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

namespace core {

class DriveLockRequest
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual void vfunc_05();
    virtual int vfunc_06();
};

int DriveLockRequest::vfunc_06()
{
    return 21;
}

}

// [TODO] 0x006E42E0 core::DriveLockRequest::vfunc_01 (73 B)
// [TODO] 0x006E4330 sub_006E4330 (77 B)
// ============================================================================
// [VERIFIED] core::Request::vfunc_00 (0x006E4380, 60 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// What it does: core::Request's deleting destructor: destroys the object, frees its memory when asked (flag bit 0), and returns it.
// ============================================================================
// Same machine code as core::Request::vfunc_00 (Proto 0x0026CD90), which was matched first;
// its addresses and names were swapped for this function's.
// core::Request::vfunc_00 (Proto 0x006E4380, 60 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual void vfunc_05(int);
};

extern "C" char DAT_00771C98[];
extern "C" char DAT_0085CDDC[];
extern "C" int DAT_0085CDF4;
extern "C" void __cdecl sub_006DF070(int);
extern "C" void __cdecl sub_006DF080(int);

namespace core {

class Request
{
public:
    virtual Request* vfunc_00(int a1);
};

Request* Request::vfunc_00(int a1)
{
    *(int*)this = (int)DAT_00771C98;
    if (a1 & 1) {
        sub_006DF080((int)DAT_0085CDDC);
        ((Object*)DAT_0085CDF4)->vfunc_05((int)this);
        sub_006DF070((int)DAT_0085CDDC);
    }
    return this;
}

}

// ============================================================================
// [VERIFIED] sub_006E43C0 (0x006E43C0, 59 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_0026CDD0 (Proto 0x0026CDD0), which was matched first;
// its addresses and names were swapped for this function's.
// sub_006E43C0 (Proto 0x006E43C0, 59 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field0C
{
    virtual void vfunc_00();
};

struct Object
{
    void sub_006DEC00();
};

extern "C" char DAT_00771C98[];
extern "C" char DAT_00771CB8[];
extern "C" void __cdecl sub_006DEC00(void);

class Class_006E43C0
{
public:
    Class_006E43C0* sub_006E43C0(int a1, int a2);
    int m_Field00; // +0x00
    int m_Field04; // +0x04
    int m_Field08; // +0x08
    Field0C* m_Field0C; // +0x0C
};

Class_006E43C0* Class_006E43C0::sub_006E43C0(int a1, int a2)
{
    m_Field00 = (int)DAT_00771C98;
    m_Field04 = 0;
    ::sub_006DEC00();
    m_Field00 = (int)DAT_00771CB8;
    m_Field08 = a1;
    m_Field0C = (Field0C*)a2;
    ((Object*)a2)->sub_006DEC00();
    m_Field0C->vfunc_00();
    return this;
}

// ============================================================================
// [VERIFIED] core::CompletionEventRequest::vfunc_00 (0x006E4400, 74 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as core::CompletionEventRequest::vfunc_00 (Proto 0x0026CE10), which was matched first;
// its addresses and names were swapped for this function's.
// core::CompletionEventRequest::vfunc_00 (Proto 0x006E4400, 74 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual void vfunc_05(int);
};

extern "C" char DAT_00771C98[];
extern "C" char DAT_00771CB8[];
extern "C" char DAT_0085CDDC[];
extern "C" int DAT_0085CDF4;
extern "C" void __cdecl sub_006DF070(int);
extern "C" void __cdecl sub_006DF080(int);

namespace core {

class CompletionEventRequest
{
public:
    virtual CompletionEventRequest* vfunc_00(int a1);
    char m_pad04[0x8];
    int m_Field0C; // +0x0C
};

CompletionEventRequest* CompletionEventRequest::vfunc_00(int a1)
{
    int t1;

    t1 = m_Field0C;
    *(int*)this = (int)DAT_00771CB8;
    ((Object*)t1)->vfunc_01();
    *(int*)this = (int)DAT_00771C98;
    if (a1 & 1) {
        sub_006DF080((int)DAT_0085CDDC);
        ((Object*)DAT_0085CDF4)->vfunc_05((int)this);
        sub_006DF070((int)DAT_0085CDDC);
    }
    return this;
}

}

// [TODO] 0x006E4450 sub_006E4450 (120 B)
// ============================================================================
// [VERIFIED] core::FileCompletionRequest::vfunc_00 (0x006E44D0, 82 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as core::FileCompletionRequest::vfunc_00 (0x002AA6D0), which was matched first;
// its addresses and names were swapped for this function's.
// core::FileCompletionRequest::vfunc_00 (0x006E44D0, 82 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field0C
{
    virtual void vfunc_00();
    virtual void vfunc_01();
};

struct Object
{
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual void vfunc_05(int);
};

extern "C" char DAT_00771C98[];
extern "C" char DAT_00771CD8[];
extern "C" char DAT_0085CDDC[];
extern "C" int DAT_0085CDF4;
extern "C" void __cdecl sub_006DF070(int);
extern "C" void __cdecl sub_006DF080(int);

namespace core {

class FileCompletionRequest
{
public:
    virtual FileCompletionRequest* vfunc_00(int a1);
    char m_pad04[0x8];
    Field0C* m_Field0C; // +0x0C
    int m_Field10; // +0x10
};

FileCompletionRequest* FileCompletionRequest::vfunc_00(int a1)
{
    int t1;

    t1 = m_Field10;
    *(int*)this = (int)DAT_00771CD8;
    ((Object*)t1)->vfunc_01();
    m_Field0C->vfunc_01();
    *(int*)this = (int)DAT_00771C98;
    if (a1 & 1) {
        sub_006DF080((int)DAT_0085CDDC);
        ((Object*)DAT_0085CDF4)->vfunc_05((int)this);
        sub_006DF070((int)DAT_0085CDDC);
    }
    return this;
}

}

// [TODO] 0x006E4530 sub_006E4530 (120 B)
// ============================================================================
// [VERIFIED] core::DriveCompletionRequest::vfunc_00 (0x006E45B0, 82 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as core::FileCompletionRequest::vfunc_00 (0x002AA6D0), which was matched first;
// its addresses and names were swapped for this function's.
// core::DriveCompletionRequest::vfunc_00 (0x006E45B0, 82 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field0C
{
    virtual void vfunc_00();
    virtual void vfunc_01();
};

struct Object
{
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual void vfunc_05(int);
};

extern "C" char DAT_00771C98[];
extern "C" char DAT_00771CFC[];
extern "C" char DAT_0085CDDC[];
extern "C" int DAT_0085CDF4;
extern "C" void __cdecl sub_006DF070(int);
extern "C" void __cdecl sub_006DF080(int);

namespace core {

class DriveCompletionRequest
{
public:
    virtual DriveCompletionRequest* vfunc_00(int a1);
    char m_pad04[0x8];
    Field0C* m_Field0C; // +0x0C
    int m_Field10; // +0x10
};

DriveCompletionRequest* DriveCompletionRequest::vfunc_00(int a1)
{
    int t1;

    t1 = m_Field10;
    *(int*)this = (int)DAT_00771CFC;
    ((Object*)t1)->vfunc_01();
    m_Field0C->vfunc_01();
    *(int*)this = (int)DAT_00771C98;
    if (a1 & 1) {
        sub_006DF080((int)DAT_0085CDDC);
        ((Object*)DAT_0085CDF4)->vfunc_05((int)this);
        sub_006DF070((int)DAT_0085CDDC);
    }
    return this;
}

}

// ============================================================================
// [VERIFIED] sub_006E4670 (0x006E4670, 44 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_0026D070 (Proto 0x0026D070), which was matched first;
// its addresses and names were swapped for this function's.
// sub_006E4670 (Proto 0x006E4670, 44 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_006DEC00();
};

extern "C" char DAT_00771DA4[];
extern "C" void __stdcall sub_006E4610(int);

class Class_006E4670
{
public:
    Class_006E4670* sub_006E4670(int a1, int a2, bool a3);
    int m_Field00; // +0x00
    char m_pad04[0x8];
    int m_Field0C; // +0x0C
    bool m_Field10; // +0x10
};

Class_006E4670* Class_006E4670::sub_006E4670(int a1, int a2, bool a3)
{
    sub_006E4610(a1);
    m_Field00 = (int)DAT_00771DA4;
    m_Field0C = a2;
    m_Field10 = a3;
    ((Object*)a2)->sub_006DEC00();
    return this;
}

// ============================================================================
// [VERIFIED] sub_006E46A0 (0x006E46A0, 51 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_002AA890 (0x002AA890), which was matched first;
// its addresses and names were swapped for this function's.
// sub_006E46A0 (0x006E46A0, 51 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field10
{
    virtual void vfunc_00();
};

struct Object
{
    void sub_006DEC00();
};

extern "C" char DAT_00771D40[];
extern "C" void __stdcall sub_006E4610(int);

class Class_006E46A0
{
public:
    Class_006E46A0* sub_006E46A0(int a1, int a2, int a3);
    int m_Field00; // +0x00
    char m_pad04[0x8];
    int m_Field0C; // +0x0C
    Field10* m_Field10; // +0x10
};

Class_006E46A0* Class_006E46A0::sub_006E46A0(int a1, int a2, int a3)
{
    sub_006E4610(a1);
    m_Field00 = (int)DAT_00771D40;
    m_Field0C = a2;
    m_Field10 = (Field10*)a3;
    ((Object*)a2)->sub_006DEC00();
    m_Field10->vfunc_00();
    return this;
}

// [TODO] 0x006E46E0 core::FileOpenByKeyRequest::vfunc_00 (116 B)
// ============================================================================
// [VERIFIED] sub_006E4760 (0x006E4760, 58 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_0026D0D0 (Proto 0x0026D0D0), which was matched first;
// its addresses and names were swapped for this function's.
// sub_006E4760 (Proto 0x006E4760, 58 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_006DEC00();
};

extern "C" char DAT_00771DC4[];
extern "C" void __stdcall sub_006E4610(int);

class Class_006E4760
{
public:
    Class_006E4760* sub_006E4760(int a1, int a2, bool a3, int a4, int a5);
    int m_Field00; // +0x00
    char m_pad04[0x8];
    int m_Field0C; // +0x0C
    bool m_Field10; // +0x10
    char m_pad11[0x3];
    int m_Field14; // +0x14
    int m_Field18; // +0x18
};

Class_006E4760* Class_006E4760::sub_006E4760(int a1, int a2, bool a3, int a4, int a5)
{
    sub_006E4610(a1);
    m_Field0C = a2;
    m_Field00 = (int)DAT_00771DC4;
    m_Field10 = a3;
    m_Field14 = a4;
    m_Field18 = a5;
    ((Object*)a5)->sub_006DEC00();
    return this;
}

// ============================================================================
// [VERIFIED] sub_006E47A0 (0x006E47A0, 30 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_002AA990 (0x002AA990), which was matched first;
// its addresses and names were swapped for this function's.
// sub_006E47A0 (0x006E47A0, 30 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_00771DE4[];
extern "C" void __cdecl sub_006DEC00(void);
extern "C" void __stdcall sub_006E4610(int);

class Class_006E47A0
{
public:
    Class_006E47A0* sub_006E47A0(int a1);
    int m_Field00; // +0x00
};

Class_006E47A0* Class_006E47A0::sub_006E47A0(int a1)
{
    sub_006E4610(a1);
    m_Field00 = (int)DAT_00771DE4;
    sub_006DEC00();
    return this;
}

// ============================================================================
// [VERIFIED] sub_006E47C0 (0x006E47C0, 30 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_002AA990 (0x002AA990), which was matched first;
// its addresses and names were swapped for this function's.
// sub_006E47C0 (0x006E47C0, 30 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_00771E04[];
extern "C" void __cdecl sub_006DEC00(void);
extern "C" void __stdcall sub_006E4610(int);

class Class_006E47C0
{
public:
    Class_006E47C0* sub_006E47C0(int a1);
    int m_Field00; // +0x00
};

Class_006E47C0* Class_006E47C0::sub_006E47C0(int a1)
{
    sub_006E4610(a1);
    m_Field00 = (int)DAT_00771E04;
    sub_006DEC00();
    return this;
}

// ============================================================================
// [VERIFIED] sub_006E47E0 (0x006E47E0, 51 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_002AA9D0 (0x002AA9D0), which was matched first;
// its addresses and names were swapped for this function's.
// sub_006E47E0 (0x006E47E0, 51 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_006DEC00();
};

extern "C" char DAT_00771E24[];
extern "C" void __stdcall sub_006E4610(int);

class Class_006E47E0
{
public:
    Class_006E47E0* sub_006E47E0(int a1, int a2, int a3, int a4);
    int m_Field00; // +0x00
    char m_pad04[0x8];
    int m_Field0C; // +0x0C
    int m_Field10; // +0x10
    int m_Field14; // +0x14
};

Class_006E47E0* Class_006E47E0::sub_006E47E0(int a1, int a2, int a3, int a4)
{
    sub_006E4610(a1);
    m_Field00 = (int)DAT_00771E24;
    m_Field0C = a2;
    m_Field10 = a3;
    m_Field14 = a4;
    ((Object*)a2)->sub_006DEC00();
    return this;
}

// ============================================================================
// [VERIFIED] sub_006E4820 (0x006E4820, 51 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_002AA9D0 (0x002AA9D0), which was matched first;
// its addresses and names were swapped for this function's.
// sub_006E4820 (0x006E4820, 51 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_006DEC00();
};

extern "C" char DAT_00771E44[];
extern "C" void __stdcall sub_006E4610(int);

class Class_006E4820
{
public:
    Class_006E4820* sub_006E4820(int a1, int a2, int a3, int a4);
    int m_Field00; // +0x00
    char m_pad04[0x8];
    int m_Field0C; // +0x0C
    int m_Field10; // +0x10
    int m_Field14; // +0x14
};

Class_006E4820* Class_006E4820::sub_006E4820(int a1, int a2, int a3, int a4)
{
    sub_006E4610(a1);
    m_Field00 = (int)DAT_00771E44;
    m_Field0C = a2;
    m_Field10 = a3;
    m_Field14 = a4;
    ((Object*)a2)->sub_006DEC00();
    return this;
}

// ============================================================================
// [VERIFIED] sub_006E4860 (0x006E4860, 37 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_002AAA50 (0x002AAA50), which was matched first;
// its addresses and names were swapped for this function's.
// sub_006E4860 (0x006E4860, 37 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_006DEC00();
};

extern "C" char DAT_00771E64[];
extern "C" void __stdcall sub_006E4610(int);

class Class_006E4860
{
public:
    Class_006E4860* sub_006E4860(int a1, int a2);
    int m_Field00; // +0x00
    char m_pad04[0x8];
    int m_Field0C; // +0x0C
};

Class_006E4860* Class_006E4860::sub_006E4860(int a1, int a2)
{
    sub_006E4610(a1);
    m_Field00 = (int)DAT_00771E64;
    m_Field0C = a2;
    ((Object*)a2)->sub_006DEC00();
    return this;
}

// ============================================================================
// [VERIFIED] sub_006E4890 (0x006E4890, 37 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_002AAA50 (0x002AAA50), which was matched first;
// its addresses and names were swapped for this function's.
// sub_006E4890 (0x006E4890, 37 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_006DEC00();
};

extern "C" char DAT_00771E84[];
extern "C" void __stdcall sub_006E4610(int);

class Class_006E4890
{
public:
    Class_006E4890* sub_006E4890(int a1, int a2);
    int m_Field00; // +0x00
    char m_pad04[0x8];
    int m_Field0C; // +0x0C
};

Class_006E4890* Class_006E4890::sub_006E4890(int a1, int a2)
{
    sub_006E4610(a1);
    m_Field00 = (int)DAT_00771E84;
    m_Field0C = a2;
    ((Object*)a2)->sub_006DEC00();
    return this;
}

// [TODO] 0x006E48C0 core::FileRequest::vfunc_00 (103 B)
// ============================================================================
// [VERIFIED] sub_006E4930 (0x006E4930, 37 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_002AAA50 (0x002AAA50), which was matched first;
// its addresses and names were swapped for this function's.
// sub_006E4930 (0x006E4930, 37 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_006DEC00();
};

extern "C" char DAT_00771EA4[];
extern "C" void __stdcall sub_006E4610(int);

class Class_006E4930
{
public:
    Class_006E4930* sub_006E4930(int a1, int a2);
    int m_Field00; // +0x00
    char m_pad04[0x8];
    int m_Field0C; // +0x0C
};

Class_006E4930* Class_006E4930::sub_006E4930(int a1, int a2)
{
    sub_006E4610(a1);
    m_Field00 = (int)DAT_00771EA4;
    m_Field0C = a2;
    ((Object*)a2)->sub_006DEC00();
    return this;
}

// ============================================================================
// [VERIFIED] sub_006E4960 (0x006E4960, 30 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_002AA990 (0x002AA990), which was matched first;
// its addresses and names were swapped for this function's.
// sub_006E4960 (0x006E4960, 30 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_00771EC4[];
extern "C" void __cdecl sub_006DEC00(void);
extern "C" void __stdcall sub_006E4610(int);

class Class_006E4960
{
public:
    Class_006E4960* sub_006E4960(int a1);
    int m_Field00; // +0x00
};

Class_006E4960* Class_006E4960::sub_006E4960(int a1)
{
    sub_006E4610(a1);
    m_Field00 = (int)DAT_00771EC4;
    sub_006DEC00();
    return this;
}

// ============================================================================
// [VERIFIED] sub_006E49E0 (0x006E49E0, 30 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_002AA990 (0x002AA990), which was matched first;
// its addresses and names were swapped for this function's.
// sub_006E49E0 (0x006E49E0, 30 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_00771EE4[];
extern "C" void __cdecl sub_006DEC00(void);
extern "C" void __stdcall sub_006E4980(int);

class Class_006E49E0
{
public:
    Class_006E49E0* sub_006E49E0(int a1);
    int m_Field00; // +0x00
};

Class_006E49E0* Class_006E49E0::sub_006E49E0(int a1)
{
    sub_006E4980(a1);
    m_Field00 = (int)DAT_00771EE4;
    sub_006DEC00();
    return this;
}

// ============================================================================
// [VERIFIED] sub_006E4A00 (0x006E4A00, 37 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_002AAA50 (0x002AAA50), which was matched first;
// its addresses and names were swapped for this function's.
// sub_006E4A00 (0x006E4A00, 37 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_006DEC00();
};

extern "C" char DAT_00771F04[];
extern "C" void __stdcall sub_006E4980(int);

class Class_006E4A00
{
public:
    Class_006E4A00* sub_006E4A00(int a1, int a2);
    int m_Field00; // +0x00
    char m_pad04[0x8];
    int m_Field0C; // +0x0C
};

Class_006E4A00* Class_006E4A00::sub_006E4A00(int a1, int a2)
{
    sub_006E4980(a1);
    m_Field00 = (int)DAT_00771F04;
    m_Field0C = a2;
    ((Object*)a2)->sub_006DEC00();
    return this;
}

// [TODO] 0x006E4A30 core::DriveRequest::vfunc_00 (103 B)
// ============================================================================
// [VERIFIED] sub_006E4AA0 (0x006E4AA0, 30 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_002AA990 (0x002AA990), which was matched first;
// its addresses and names were swapped for this function's.
// sub_006E4AA0 (0x006E4AA0, 30 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_00771F24[];
extern "C" void __cdecl sub_006DEC00(void);
extern "C" void __stdcall sub_006E4980(int);

class Class_006E4AA0
{
public:
    Class_006E4AA0* sub_006E4AA0(int a1);
    int m_Field00; // +0x00
};

Class_006E4AA0* Class_006E4AA0::sub_006E4AA0(int a1)
{
    sub_006E4980(a1);
    m_Field00 = (int)DAT_00771F24;
    sub_006DEC00();
    return this;
}

// ============================================================================
// [VERIFIED] sub_006E4AC0 (0x006E4AC0, 54 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// bin: pc
// va: 0x006E4AC0
// what: 
// tool: the portal's starter code (no AI)

// sub_006E4AC0 (PC 0x006E4AC0, 54 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_0072F204;
extern "C" char DAT_00771F44[];
extern "C" void __cdecl sub_006DEC00(void);
extern "C" void __stdcall sub_006E4980(int);

class Class_006E4AC0
{
public:
    Class_006E4AC0* sub_006E4AC0(int a1, int a2);
    int m_Field00; // +0x00
    char m_pad04[0x8];
    int m_Field0C; // +0x0C
    char m_pad10[0xC];
    bool m_Field1C; // +0x1C
};

Class_006E4AC0* Class_006E4AC0::sub_006E4AC0(int a1, int a2)
{
    sub_006E4980(a1);
    m_Field00 = (int)DAT_00771F44;
    sub_006DEC00();
    ((void (__cdecl*)(int, int, int))DAT_0072F204)((int)(&m_Field0C), a2, 16);
    m_Field1C = false;
    return this;
}

// ============================================================================
// [VERIFIED] sub_006E4B00 (0x006E4B00, 54 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_006E4AC0 (PC 0x006E4AC0), which was matched first;
// its addresses and names were swapped for this function's.
// bin: pc
// va: 0x006E4B00
// what: 
// tool: the portal's starter code (no AI)

// sub_006E4B00 (PC 0x006E4B00, 54 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_0072F204;
extern "C" char DAT_00771F64[];
extern "C" void __cdecl sub_006DEC00(void);
extern "C" void __stdcall sub_006E4980(int);

class Class_006E4B00
{
public:
    Class_006E4B00* sub_006E4B00(int a1, int a2);
    int m_Field00; // +0x00
    char m_pad04[0x8];
    int m_Field0C; // +0x0C
    char m_pad10[0xC];
    bool m_Field1C; // +0x1C
};

Class_006E4B00* Class_006E4B00::sub_006E4B00(int a1, int a2)
{
    sub_006E4980(a1);
    m_Field00 = (int)DAT_00771F64;
    sub_006DEC00();
    ((void (__cdecl*)(int, int, int))DAT_0072F204)((int)(&m_Field0C), a2, 16);
    m_Field1C = false;
    return this;
}

// [TODO] 0x006E4B40 sub_006E4B40 (70 B)
// ============================================================================
// [VERIFIED] sub_006E4B90 (0x006E4B90, 37 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_002AAA50 (0x002AAA50), which was matched first;
// its addresses and names were swapped for this function's.
// sub_006E4B90 (0x006E4B90, 37 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_006DEC00();
};

extern "C" char DAT_00771FA4[];
extern "C" void __stdcall sub_006E4980(int);

class Class_006E4B90
{
public:
    Class_006E4B90* sub_006E4B90(int a1, int a2);
    int m_Field00; // +0x00
    char m_pad04[0x8];
    int m_Field0C; // +0x0C
};

Class_006E4B90* Class_006E4B90::sub_006E4B90(int a1, int a2)
{
    sub_006E4980(a1);
    m_Field00 = (int)DAT_00771FA4;
    m_Field0C = a2;
    ((Object*)a2)->sub_006DEC00();
    return this;
}

// ============================================================================
// [VERIFIED] sub_006E4BC0 (0x006E4BC0, 30 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_002AA990 (0x002AA990), which was matched first;
// its addresses and names were swapped for this function's.
// sub_006E4BC0 (0x006E4BC0, 30 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_00771FC4[];
extern "C" void __cdecl sub_006DEC00(void);
extern "C" void __stdcall sub_006E4980(int);

class Class_006E4BC0
{
public:
    Class_006E4BC0* sub_006E4BC0(int a1);
    int m_Field00; // +0x00
};

Class_006E4BC0* Class_006E4BC0::sub_006E4BC0(int a1)
{
    sub_006E4980(a1);
    m_Field00 = (int)DAT_00771FC4;
    sub_006DEC00();
    return this;
}

// ============================================================================
// [VERIFIED] sub_006E4BE0 (0x006E4BE0, 60 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// bin: pc
// va: 0x006E4BE0
// what: 
// tool: the portal's starter code (no AI)

// sub_006E4BE0 (PC 0x006E4BE0, 60 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_0072F204;
extern "C" char DAT_00771FE4[];
extern "C" void __cdecl sub_006DEC00(void);
extern "C" void __stdcall sub_006E4980(int);

class Class_006E4BE0
{
public:
    Class_006E4BE0* sub_006E4BE0(int a1, int a2);
    int m_Field00; // +0x00
    char m_pad04[0x8];
    int m_Field0C; // +0x0C
    char m_pad10[0xFC];
    bool m_Field10C; // +0x10C
};

Class_006E4BE0* Class_006E4BE0::sub_006E4BE0(int a1, int a2)
{
    sub_006E4980(a1);
    m_Field00 = (int)DAT_00771FE4;
    sub_006DEC00();
    ((void (__cdecl*)(int, int, int))DAT_0072F204)((int)(&m_Field0C), a2, 256);
    m_Field10C = false;
    return this;
}

// ============================================================================
// [VERIFIED] sub_006E4C20 (0x006E4C20, 30 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_002AA990 (0x002AA990), which was matched first;
// its addresses and names were swapped for this function's.
// sub_006E4C20 (0x006E4C20, 30 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_00772004[];
extern "C" void __cdecl sub_006DEC00(void);
extern "C" void __stdcall sub_006E4980(int);

class Class_006E4C20
{
public:
    Class_006E4C20* sub_006E4C20(int a1);
    int m_Field00; // +0x00
};

Class_006E4C20* Class_006E4C20::sub_006E4C20(int a1)
{
    sub_006E4980(a1);
    m_Field00 = (int)DAT_00772004;
    sub_006DEC00();
    return this;
}

// ============================================================================
// [VERIFIED] sub_006E4C40 (0x006E4C40, 51 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_002AAE20 (0x002AAE20), which was matched first;
// its addresses and names were swapped for this function's.
// sub_006E4C40 (0x006E4C40, 51 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_006DEC00();
};

extern "C" char DAT_00772024[];
extern "C" void __stdcall sub_006E4980(int);

class Class_006E4C40
{
public:
    Class_006E4C40* sub_006E4C40(int a1, int a2, int a3);
    int m_Field00; // +0x00
    char m_pad04[0x8];
    int m_Field0C; // +0x0C
    int m_Field10; // +0x10
    char m_pad14[0x4];
    int m_Field18; // +0x18
};

Class_006E4C40* Class_006E4C40::sub_006E4C40(int a1, int a2, int a3)
{
    sub_006E4980(a1);
    m_Field00 = (int)DAT_00772024;
    m_Field0C = a2;
    m_Field10 = a3;
    m_Field18 = 0;
    ((Object*)a2)->sub_006DEC00();
    return this;
}

// [TODO] 0x006E4C80 sub_006E4C80 (50 B)
// [TODO] 0x006E4CF0 core::File::vfunc_01 (119 B)
// ============================================================================
// [VERIFIED] core::File::vfunc_00 (0x006E4D70, 12 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as core::File::vfunc_00 (0x002AAF50), which was matched first;
// its addresses and names were swapped for this function's.
// core::File::vfunc_00 (0x006E4D70, 12 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0085CDF8[];
extern "C" void __cdecl sub_006DF080(int);

namespace core {

class File
{
public:
    virtual void vfunc_00();
};

void File::vfunc_00()
{
    sub_006DF080((int)DAT_0085CDF8);
}

}

// ============================================================================
// [VERIFIED] core::File::vfunc_01 (0x006E4D80, 12 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as core::File::vfunc_00 (0x002AAF50), which was matched first;
// its addresses and names were swapped for this function's.
// core::File::vfunc_01 (0x006E4D80, 12 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0085CDF8[];
extern "C" void __cdecl sub_006DF070(int);

namespace core {

class File
{
public:
    virtual void vfunc_01();
};

void File::vfunc_01()
{
    sub_006DF070((int)DAT_0085CDF8);
}

}

// [TODO] 0x006E4D90 core::File::vfunc_09 (60 B)
// [TODO] 0x006E4DD0 core::File::vfunc_04 (79 B)
// [TODO] 0x006E4E20 core::File::vfunc_05 (79 B)
// [TODO] 0x006E4E70 core::File::vfunc_06 (69 B)
// [TODO] 0x006E4EC0 core::File::vfunc_07 (69 B)
// [TODO] 0x006E4F10 core::File::vfunc_08 (69 B)
// ============================================================================
// [VERIFIED] core::File::vfunc_10 (0x006E4F60, 36 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as core::File::vfunc_10 (Proto 0x0026D880), which was matched first;
// its addresses and names were swapped for this function's.
// core::File::vfunc_10 (Proto 0x006E4F60, 36 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

namespace core {

class File
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04(int, int, int);
    virtual void vfunc_05();
    virtual void vfunc_06();
    virtual void vfunc_07();
    virtual void vfunc_08();
    virtual void vfunc_09();
    virtual void vfunc_10(int a1, int a2, int a3);
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

void File::vfunc_10(int a1, int a2, int a3)
{
    vfunc_04(a1, a2, a3);
    vfunc_22();
}

}

// ============================================================================
// [VERIFIED] core::File::vfunc_11 (0x006E4F90, 36 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as core::File::vfunc_11 (Proto 0x0026D8B0), which was matched first;
// its addresses and names were swapped for this function's.
// core::File::vfunc_11 (Proto 0x006E4F90, 36 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

namespace core {

class File
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual void vfunc_05(int, int, int);
    virtual void vfunc_06();
    virtual void vfunc_07();
    virtual void vfunc_08();
    virtual void vfunc_09();
    virtual void vfunc_10();
    virtual void vfunc_11(int a1, int a2, int a3);
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

void File::vfunc_11(int a1, int a2, int a3)
{
    vfunc_05(a1, a2, a3);
    vfunc_22();
}

}

// ============================================================================
// [VERIFIED] core::File::vfunc_12 (0x006E4FC0, 26 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as core::File::vfunc_12 (Proto 0x0026D8E0), which was matched first;
// its addresses and names were swapped for this function's.
// core::File::vfunc_12 (Proto 0x006E4FC0, 26 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

namespace core {

class File
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual void vfunc_05();
    virtual void vfunc_06(int);
    virtual void vfunc_07();
    virtual void vfunc_08();
    virtual void vfunc_09();
    virtual void vfunc_10();
    virtual void vfunc_11();
    virtual void vfunc_12(int a1);
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

void File::vfunc_12(int a1)
{
    vfunc_06(a1);
    vfunc_22();
}

}

// ============================================================================
// [VERIFIED] core::File::vfunc_13 (0x006E4FE0, 26 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as core::File::vfunc_13 (Proto 0x0026D900), which was matched first;
// its addresses and names were swapped for this function's.
// core::File::vfunc_13 (Proto 0x006E4FE0, 26 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

namespace core {

class File
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual void vfunc_05();
    virtual void vfunc_06();
    virtual void vfunc_07(int);
    virtual void vfunc_08();
    virtual void vfunc_09();
    virtual void vfunc_10();
    virtual void vfunc_11();
    virtual void vfunc_12();
    virtual void vfunc_13(int a1);
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

void File::vfunc_13(int a1)
{
    vfunc_07(a1);
    vfunc_22();
}

}

// ============================================================================
// [VERIFIED] core::File::vfunc_14 (0x006E5000, 26 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as core::File::vfunc_14 (Proto 0x0026D920), which was matched first;
// its addresses and names were swapped for this function's.
// core::File::vfunc_14 (Proto 0x006E5000, 26 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

namespace core {

class File
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
    virtual void vfunc_08(int);
    virtual void vfunc_09();
    virtual void vfunc_10();
    virtual void vfunc_11();
    virtual void vfunc_12();
    virtual void vfunc_13();
    virtual void vfunc_14(int a1);
    virtual void vfunc_15();
    virtual void vfunc_16();
    virtual void vfunc_17();
    virtual void vfunc_18();
    virtual void vfunc_19();
    virtual void vfunc_20();
    virtual void vfunc_21();
    virtual void vfunc_22();
};

void File::vfunc_14(int a1)
{
    vfunc_08(a1);
    vfunc_22();
}

}

// ============================================================================
// [VERIFIED] core::File::vfunc_15 (0x006E5020, 16 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as core::File::vfunc_15 (Proto 0x0026D940), which was matched first;
// its addresses and names were swapped for this function's.
// core::File::vfunc_15 (Proto 0x006E5020, 16 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

namespace core {

class File
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
};

void File::vfunc_15()
{
    vfunc_09();
    vfunc_22();
}

}

// ============================================================================
// [VERIFIED] core::File::vfunc_16 (0x006E5030, 7 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as core::File::vfunc_16 (Proto 0x0026D950), which was matched first;
// its addresses and names were swapped for this function's.
// core::File::vfunc_16 (Proto 0x006E5030, 7 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

namespace core {

class File
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
    char m_pad04[0x124];
    int m_Field128; // +0x128
};

int File::vfunc_16()
{
    return m_Field128;
}

}

// [TODO] 0x006E5040 core::File::vfunc_18 (61 B)
// [TODO] 0x006E5080 core::File::vfunc_19 (85 B)
// [TODO] 0x006E50E0 core::File::vfunc_21 (35 B)
// ============================================================================
// [VERIFIED] core::File::vfunc_22 (0x006E5110, 47 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as core::File::vfunc_22 (Proto 0x0026DA30), which was matched first;
// its addresses and names were swapped for this function's.
// core::File::vfunc_22 (Proto 0x006E5110, 47 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field0C
{
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
};

extern "C" void __cdecl sub_006DEFA0(int);

namespace core {

class File
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
    virtual bool vfunc_21();
    virtual void vfunc_22();
    char m_pad04[0x8];
    Field0C* m_Field0C; // +0x0C
};

void File::vfunc_22()
{
    if (!vfunc_21()) {
        do {
            m_Field0C->vfunc_04();
            sub_006DEFA0(0);
        } while (!vfunc_21());
    }
}

}

// [TODO] 0x006E5140 core::File::vfunc_23 (29 B)
// [TODO] 0x006E5160 core::File::vfunc_25 (24 B)
// ============================================================================
// [VERIFIED] core::File::vfunc_26 (0x006E5180, 4 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// core::File::vfunc_26 (PC 0x006E5180, 4 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

namespace core {

class File
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
    virtual void* vfunc_26();
};

void* File::vfunc_26()
{
    return ((char*)this + 0x1E);
}

}

// ============================================================================
// [VERIFIED] core::File::vfunc_27 (0x006E5190, 8 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as core::File::vfunc_27 (Proto 0x0026E730), which was matched first;
// its addresses and names were swapped for this function's.
// core::File::vfunc_27 (Proto 0x006E5190, 8 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field0C
{
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual void vfunc_05();
};

namespace core {

class File
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
    char m_pad04[0x8];
    Field0C* m_Field0C; // +0x0C
};

void File::vfunc_27()
{
    m_Field0C->vfunc_05();
}

}

// ============================================================================
// [VERIFIED] core::File::vfunc_30 (0x006E51A0, 7 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as core::File::vfunc_30 (Proto 0x0026DAD0), which was matched first;
// its addresses and names were swapped for this function's.
// core::File::vfunc_30 (Proto 0x006E51A0, 7 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

namespace core {

class File
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
    virtual bool vfunc_30();
    char m_pad04[0x15C];
    bool m_Field160; // +0x160
};

bool File::vfunc_30()
{
    return m_Field160;
}

}

// ============================================================================
// [VERIFIED] core::File::vfunc_31 (0x006E51C0, 13 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as core::File::vfunc_31 (Proto 0x0026DAF0), which was matched first;
// its addresses and names were swapped for this function's.
// core::File::vfunc_31 (Proto 0x006E51C0, 13 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

namespace core {

class File
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
    virtual void vfunc_30();
    virtual int vfunc_31(int a1);
    char m_pad04[0x11C];
    int m_Field120; // +0x120
};

int File::vfunc_31(int a1)
{
    m_Field120 = a1;
    return a1;
}

}

// ============================================================================
// [VERIFIED] core::File::vfunc_32 (0x006E51D0, 7 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as core::File::vfunc_32 (Proto 0x0026DB00), which was matched first;
// its addresses and names were swapped for this function's.
// core::File::vfunc_32 (Proto 0x006E51D0, 7 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

namespace core {

class File
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
    virtual void vfunc_30();
    virtual void vfunc_31();
    virtual int vfunc_32();
    char m_pad04[0x158];
    int m_Field15C; // +0x15C
};

int File::vfunc_32()
{
    return m_Field15C;
}

}

// ============================================================================
// [VERIFIED] core::File::vfunc_33 (0x006E51E0, 7 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as core::File::vfunc_33 (Proto 0x0026DB10), which was matched first;
// its addresses and names were swapped for this function's.
// core::File::vfunc_33 (Proto 0x006E51E0, 7 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

namespace core {

class File
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
    virtual void vfunc_30();
    virtual void vfunc_31();
    virtual void vfunc_32();
    virtual void* vfunc_33();
    char m_pad04[0x128];
    int m_Field12C; // +0x12C
};

void* File::vfunc_33()
{
    return &m_Field12C;
}

}

// ============================================================================
// [VERIFIED] core::File::vfunc_03 (0x006E51F0, 92 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as core::File::vfunc_03 (Proto 0x0026DB70), which was matched first;
// its addresses and names were swapped for this function's.
// core::File::vfunc_03 (Proto 0x006E51F0, 92 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field12C
{
    void sub_005E1BB0();
};

struct Object
{
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual void vfunc_05(int);
};

extern "C" char DAT_0073523C[];
extern "C" char DAT_00772058[];
extern "C" char DAT_00772064[];
extern "C" char DAT_0085CDF8[];
extern "C" int DAT_0085CE10;
extern "C" void __cdecl sub_006DF070(int);
extern "C" void __cdecl sub_006DF080(int);

namespace core {

class File
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual File* vfunc_03(int a1);
    int m_Field04; // +0x04
    char m_pad08[0x4];
    int m_Field0C; // +0x0C
    char m_pad10[0x11C];
    Field12C m_Field12C; // +0x12C
};

File* File::vfunc_03(int a1)
{
    int t1;

    t1 = m_Field0C;
    *(int*)this = (int)DAT_00772064;
    m_Field04 = (int)DAT_00772058;
    ((Object*)t1)->vfunc_01();
    m_Field12C.sub_005E1BB0();
    *(int*)this = (int)DAT_0073523C;
    if (a1 & 1) {
        sub_006DF080((int)DAT_0085CDF8);
        ((Object*)DAT_0085CE10)->vfunc_05((int)this);
        sub_006DF070((int)DAT_0085CDF8);
    }
    return this;
}

}

// [TODO] 0x006E5250 sub_006E5250 (248 B)
// [TODO] 0x006E5450 sub_006E5450 (47 B)
// ============================================================================
// [VERIFIED] sub_006E5480 (0x006E5480, 44 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_002A9880 (0x002A9880), which was matched first;
// its addresses and names were swapped for this function's.
// sub_006E5480 (0x006E5480, 44 bytes)
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
    virtual int vfunc_16();
};

extern "C" char DAT_0085CE14[];
extern "C" int DAT_0085CE2C;
extern "C" void __cdecl sub_006DF070(int);
extern "C" void __cdecl sub_006DF080(int);

int __cdecl sub_006E5480(void)
{
    int t3;

    sub_006DF080((int)DAT_0085CE14);
    t3 = ((Object*)DAT_0085CE2C)->vfunc_16();
    sub_006DF070((int)DAT_0085CE14);
    return t3;
}

// [TODO] 0x006E54B0 core::File::vfunc_00 (27 B)
// [TODO] 0x006E54D0 core::InstanceDrive::vfunc_01 (123 B)
// ============================================================================
// [VERIFIED] core::InstanceDrive::vfunc_00 (0x006E5550, 12 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as core::File::vfunc_00 (0x002AAF50), which was matched first;
// its addresses and names were swapped for this function's.
// core::InstanceDrive::vfunc_00 (0x006E5550, 12 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0085CE14[];
extern "C" void __cdecl sub_006DF080(int);

namespace core {

class InstanceDrive
{
public:
    virtual void vfunc_00();
};

void InstanceDrive::vfunc_00()
{
    sub_006DF080((int)DAT_0085CE14);
}

}

// ============================================================================
// [VERIFIED] core::InstanceDrive::vfunc_01 (0x006E5560, 12 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as core::File::vfunc_00 (0x002AAF50), which was matched first;
// its addresses and names were swapped for this function's.
// core::InstanceDrive::vfunc_01 (0x006E5560, 12 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0085CE14[];
extern "C" void __cdecl sub_006DF070(int);

namespace core {

class InstanceDrive
{
public:
    virtual void vfunc_01();
};

void InstanceDrive::vfunc_01()
{
    sub_006DF070((int)DAT_0085CE14);
}

}

// ============================================================================
// [VERIFIED] core::InstanceDrive::vfunc_04 (0x006E5570, 8 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as core::InstanceDrive::vfunc_04 (Proto 0x0026DEF0), which was matched first;
// its addresses and names were swapped for this function's.
// core::InstanceDrive::vfunc_04 (Proto 0x006E5570, 8 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field0C
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
};

namespace core {

class InstanceDrive
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    char m_pad04[0x8];
    Field0C* m_Field0C; // +0x0C
};

void InstanceDrive::vfunc_04()
{
    m_Field0C->vfunc_08();
}

}

// [TODO] 0x006E5580 core::InstanceDrive::vfunc_05 (69 B)
// [TODO] 0x006E55D0 core::InstanceDrive::vfunc_06 (60 B)
// [TODO] 0x006E5610 core::InstanceDrive::vfunc_07 (135 B)
// [TODO] 0x006E56A0 core::InstanceDrive::vfunc_08 (135 B)
// [TODO] 0x006E5730 core::InstanceDrive::vfunc_09 (146 B)
// [TODO] 0x006E57D0 core::InstanceDrive::vfunc_10 (69 B)
// [TODO] 0x006E5820 core::InstanceDrive::vfunc_11 (138 B)
// ============================================================================
// [VERIFIED] core::InstanceDrive::vfunc_12 (0x006E58B0, 26 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as core::InstanceDrive::vfunc_12 (Proto 0x0026E230), which was matched first;
// its addresses and names were swapped for this function's.
// core::InstanceDrive::vfunc_12 (Proto 0x006E58B0, 26 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

namespace core {

class InstanceDrive
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual void vfunc_05(int);
    virtual void vfunc_06();
    virtual void vfunc_07();
    virtual void vfunc_08();
    virtual void vfunc_09();
    virtual void vfunc_10();
    virtual void vfunc_11();
    virtual void vfunc_12(int a1);
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

void InstanceDrive::vfunc_12(int a1)
{
    vfunc_05(a1);
    vfunc_23();
}

}

// ============================================================================
// [VERIFIED] core::InstanceDrive::vfunc_13 (0x006E58D0, 16 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as core::InstanceDrive::vfunc_13 (Proto 0x0026E250), which was matched first;
// its addresses and names were swapped for this function's.
// core::InstanceDrive::vfunc_13 (Proto 0x006E58D0, 16 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

namespace core {

class InstanceDrive
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

void InstanceDrive::vfunc_13()
{
    vfunc_06();
    vfunc_23();
}

}

// ============================================================================
// [VERIFIED] core::InstanceDrive::vfunc_14 (0x006E58E0, 26 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as core::InstanceDrive::vfunc_14 (Proto 0x0026E260), which was matched first;
// its addresses and names were swapped for this function's.
// core::InstanceDrive::vfunc_14 (Proto 0x006E58E0, 26 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

namespace core {

class InstanceDrive
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual void vfunc_05();
    virtual void vfunc_06();
    virtual void vfunc_07(int);
    virtual void vfunc_08();
    virtual void vfunc_09();
    virtual void vfunc_10();
    virtual void vfunc_11();
    virtual void vfunc_12();
    virtual void vfunc_13();
    virtual void vfunc_14(int a1);
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

void InstanceDrive::vfunc_14(int a1)
{
    vfunc_07(a1);
    vfunc_23();
}

}

// ============================================================================
// [VERIFIED] core::InstanceDrive::vfunc_15 (0x006E5900, 26 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as core::InstanceDrive::vfunc_15 (Proto 0x0026E280), which was matched first;
// its addresses and names were swapped for this function's.
// core::InstanceDrive::vfunc_15 (Proto 0x006E5900, 26 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

namespace core {

class InstanceDrive
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
    virtual void vfunc_08(int);
    virtual void vfunc_09();
    virtual void vfunc_10();
    virtual void vfunc_11();
    virtual void vfunc_12();
    virtual void vfunc_13();
    virtual void vfunc_14();
    virtual void vfunc_15(int a1);
    virtual void vfunc_16();
    virtual void vfunc_17();
    virtual void vfunc_18();
    virtual void vfunc_19();
    virtual void vfunc_20();
    virtual void vfunc_21();
    virtual void vfunc_22();
    virtual void vfunc_23();
};

void InstanceDrive::vfunc_15(int a1)
{
    vfunc_08(a1);
    vfunc_23();
}

}

// ============================================================================
// [VERIFIED] core::InstanceDrive::vfunc_16 (0x006E5920, 31 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as core::InstanceDrive::vfunc_16 (Proto 0x0026E2A0), which was matched first;
// its addresses and names were swapped for this function's.
// core::InstanceDrive::vfunc_16 (Proto 0x006E5920, 31 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

namespace core {

class InstanceDrive
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
    virtual void vfunc_09(int, int);
    virtual void vfunc_10();
    virtual void vfunc_11();
    virtual void vfunc_12();
    virtual void vfunc_13();
    virtual void vfunc_14();
    virtual void vfunc_15();
    virtual void vfunc_16(int a1, int a2);
    virtual void vfunc_17();
    virtual void vfunc_18();
    virtual void vfunc_19();
    virtual void vfunc_20();
    virtual void vfunc_21();
    virtual void vfunc_22();
    virtual void vfunc_23();
};

void InstanceDrive::vfunc_16(int a1, int a2)
{
    vfunc_09(a1, a2);
    vfunc_23();
}

}

// ============================================================================
// [VERIFIED] core::InstanceDrive::vfunc_17 (0x006E5940, 26 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as core::InstanceDrive::vfunc_17 (Proto 0x0026E2C0), which was matched first;
// its addresses and names were swapped for this function's.
// core::InstanceDrive::vfunc_17 (Proto 0x006E5940, 26 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

namespace core {

class InstanceDrive
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
    virtual void vfunc_10(int);
    virtual void vfunc_11();
    virtual void vfunc_12();
    virtual void vfunc_13();
    virtual void vfunc_14();
    virtual void vfunc_15();
    virtual void vfunc_16();
    virtual void vfunc_17(int a1);
    virtual void vfunc_18();
    virtual void vfunc_19();
    virtual void vfunc_20();
    virtual void vfunc_21();
    virtual void vfunc_22();
    virtual void vfunc_23();
};

void InstanceDrive::vfunc_17(int a1)
{
    vfunc_10(a1);
    vfunc_23();
}

}

// ============================================================================
// [VERIFIED] core::InstanceDrive::vfunc_18 (0x006E5960, 26 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as core::InstanceDrive::vfunc_18 (Proto 0x0026E2E0), which was matched first;
// its addresses and names were swapped for this function's.
// core::InstanceDrive::vfunc_18 (Proto 0x006E5960, 26 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

namespace core {

class InstanceDrive
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
    virtual void vfunc_11(int);
    virtual void vfunc_12();
    virtual void vfunc_13();
    virtual void vfunc_14();
    virtual void vfunc_15();
    virtual void vfunc_16();
    virtual void vfunc_17();
    virtual void vfunc_18(int a1);
    virtual void vfunc_19();
    virtual void vfunc_20();
    virtual void vfunc_21();
    virtual void vfunc_22();
    virtual void vfunc_23();
};

void InstanceDrive::vfunc_18(int a1)
{
    vfunc_11(a1);
    vfunc_23();
}

}

// [TODO] 0x006E5980 core::InstanceDrive::vfunc_19 (61 B)
// [TODO] 0x006E59C0 core::InstanceDrive::vfunc_20 (85 B)
// [TODO] 0x006E5A20 core::File::vfunc_20 (72 B)
// [TODO] 0x006E5A70 core::InstanceDrive::vfunc_22 (35 B)
// ============================================================================
// [VERIFIED] core::InstanceDrive::vfunc_23 (0x006E5AA0, 47 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as core::InstanceDrive::vfunc_23 (Proto 0x0026E420), which was matched first;
// its addresses and names were swapped for this function's.
// core::InstanceDrive::vfunc_23 (Proto 0x006E5AA0, 47 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field0C
{
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
};

extern "C" void __cdecl sub_006DEFA0(int);

namespace core {

class InstanceDrive
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
    virtual bool vfunc_22();
    virtual void vfunc_23();
    char m_pad04[0x8];
    Field0C* m_Field0C; // +0x0C
};

void InstanceDrive::vfunc_23()
{
    if (!vfunc_22()) {
        do {
            m_Field0C->vfunc_04();
            sub_006DEFA0(0);
        } while (!vfunc_22());
    }
}

}

// [TODO] 0x006E5AD0 core::InstanceDrive::vfunc_24 (63 B)
// ============================================================================
// [VERIFIED] core::InstanceDrive::vfunc_25 (0x006E5B10, 8 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as core::InstanceDrive::vfunc_29 (0x002ABD60), which was matched first;
// its addresses and names were swapped for this function's.
// core::InstanceDrive::vfunc_25 (0x006E5B10, 8 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field0C
{
    void sub_006E6160();
};

namespace core {

class InstanceDrive
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
    char m_pad04[0x8];
    Field0C* m_Field0C; // +0x0C
};

void InstanceDrive::vfunc_25()
{
    m_Field0C->sub_006E6160();
}

}

// ============================================================================
// [VERIFIED] core::InstanceDrive::vfunc_26 (0x006E5B20, 8 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as core::InstanceDrive::vfunc_29 (0x002ABD60), which was matched first;
// its addresses and names were swapped for this function's.
// core::InstanceDrive::vfunc_26 (0x006E5B20, 8 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field0C
{
    void sub_006E61A0();
};

namespace core {

class InstanceDrive
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
    char m_pad04[0x8];
    Field0C* m_Field0C; // +0x0C
};

void InstanceDrive::vfunc_26()
{
    m_Field0C->sub_006E61A0();
}

}

// ============================================================================
// [VERIFIED] core::InstanceDrive::vfunc_27 (0x006E5B30, 8 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as core::InstanceDrive::vfunc_29 (0x002ABD60), which was matched first;
// its addresses and names were swapped for this function's.
// core::InstanceDrive::vfunc_27 (0x006E5B30, 8 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field0C
{
    void sub_006E61D0();
};

namespace core {

class InstanceDrive
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
    char m_pad04[0x8];
    Field0C* m_Field0C; // +0x0C
};

void InstanceDrive::vfunc_27()
{
    m_Field0C->sub_006E61D0();
}

}

// ============================================================================
// [VERIFIED] core::InstanceDrive::vfunc_29 (0x006E5B40, 8 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as core::InstanceDrive::vfunc_29 (0x002ABD60), which was matched first;
// its addresses and names were swapped for this function's.
// core::InstanceDrive::vfunc_29 (0x006E5B40, 8 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field0C
{
    void sub_006E6290();
};

namespace core {

class InstanceDrive
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
    char m_pad04[0x8];
    Field0C* m_Field0C; // +0x0C
};

void InstanceDrive::vfunc_29()
{
    m_Field0C->sub_006E6290();
}

}

// ============================================================================
// [VERIFIED] core::InstanceDrive::vfunc_30 (0x006E5B50, 8 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as core::InstanceDrive::vfunc_29 (0x002ABD60), which was matched first;
// its addresses and names were swapped for this function's.
// core::InstanceDrive::vfunc_30 (0x006E5B50, 8 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field0C
{
    void sub_006E6250();
};

namespace core {

class InstanceDrive
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
    virtual void vfunc_30();
    char m_pad04[0x8];
    Field0C* m_Field0C; // +0x0C
};

void InstanceDrive::vfunc_30()
{
    m_Field0C->sub_006E6250();
}

}

// ============================================================================
// [VERIFIED] core::InstanceDrive::vfunc_31 (0x006E5B60, 8 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as core::InstanceDrive::vfunc_29 (0x002ABD60), which was matched first;
// its addresses and names were swapped for this function's.
// core::InstanceDrive::vfunc_31 (0x006E5B60, 8 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field0C
{
    void sub_006E6200();
};

namespace core {

class InstanceDrive
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
    virtual void vfunc_30();
    virtual void vfunc_31();
    char m_pad04[0x8];
    Field0C* m_Field0C; // +0x0C
};

void InstanceDrive::vfunc_31()
{
    m_Field0C->sub_006E6200();
}

}

// ============================================================================
// [VERIFIED] core::InstanceDrive::vfunc_32 (0x006E5B70, 8 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as core::InstanceDrive::vfunc_29 (0x002ABD60), which was matched first;
// its addresses and names were swapped for this function's.
// core::InstanceDrive::vfunc_32 (0x006E5B70, 8 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field0C
{
    void sub_006E6350();
};

namespace core {

class InstanceDrive
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
    virtual void vfunc_30();
    virtual void vfunc_31();
    virtual void vfunc_32();
    char m_pad04[0x8];
    Field0C* m_Field0C; // +0x0C
};

void InstanceDrive::vfunc_32()
{
    m_Field0C->sub_006E6350();
}

}

// ============================================================================
// [VERIFIED] core::InstanceDrive::vfunc_33 (0x006E5B80, 8 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as core::InstanceDrive::vfunc_29 (0x002ABD60), which was matched first;
// its addresses and names were swapped for this function's.
// core::InstanceDrive::vfunc_33 (0x006E5B80, 8 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field0C
{
    void sub_006E62F0();
};

namespace core {

class InstanceDrive
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
    virtual void vfunc_30();
    virtual void vfunc_31();
    virtual void vfunc_32();
    virtual void vfunc_33();
    char m_pad04[0x8];
    Field0C* m_Field0C; // +0x0C
};

void InstanceDrive::vfunc_33()
{
    m_Field0C->sub_006E62F0();
}

}

// [TODO] 0x006E5B90 core::InstanceDrive::vfunc_34 (203 B)
// ============================================================================
// [VERIFIED] core::InstanceDrive::vfunc_35 (0x006E5C60, 64 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as core::InstanceDrive::vfunc_35 (Proto 0x0026E5E0), which was matched first;
// its addresses and names were swapped for this function's.
// core::InstanceDrive::vfunc_35 (Proto 0x006E5C60, 64 bytes)
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

class InstanceDrive
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
    virtual void vfunc_30();
    virtual void vfunc_31();
    virtual void vfunc_32();
    virtual void vfunc_33();
    virtual void vfunc_34(int, int, int, int, int, int, int, int);
    virtual void vfunc_35(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8);
};

void InstanceDrive::vfunc_35(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8)
{
    int t2;

    vfunc_34(a1, a2, a3, a4, a5, a6, a7, a8);
    t2 = *(int*)a1;
    if (*(int*)a1) {
        ((Object*)t2)->vfunc_22();
    }
}

}

// [TODO] 0x006E5CA0 core::InstanceDrive::vfunc_36 (193 B)
// ============================================================================
// [VERIFIED] core::InstanceDrive::vfunc_37 (0x006E5D70, 59 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as core::InstanceDrive::vfunc_37 (Proto 0x0026E6F0), which was matched first;
// its addresses and names were swapped for this function's.
// core::InstanceDrive::vfunc_37 (Proto 0x006E5D70, 59 bytes)
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

class InstanceDrive
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
    virtual void vfunc_30();
    virtual void vfunc_31();
    virtual void vfunc_32();
    virtual void vfunc_33();
    virtual void vfunc_34();
    virtual void vfunc_35();
    virtual void vfunc_36(int, int, int, int, int, int, int);
    virtual void vfunc_37(int a1, int a2, int a3, int a4, int a5, int a6, int a7);
};

void InstanceDrive::vfunc_37(int a1, int a2, int a3, int a4, int a5, int a6, int a7)
{
    int t2;

    vfunc_36(a1, a2, a3, a4, a5, a6, a7);
    t2 = *(int*)a1;
    if (*(int*)a1) {
        ((Object*)t2)->vfunc_22();
    }
}

}

// ============================================================================
// [VERIFIED] core::InstanceDrive::vfunc_41 (0x006E5DB0, 8 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as core::InstanceDrive::vfunc_29 (0x002ABD60), which was matched first;
// its addresses and names were swapped for this function's.
// core::InstanceDrive::vfunc_41 (0x006E5DB0, 8 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field0C
{
    void sub_006E6390();
};

namespace core {

class InstanceDrive
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
    virtual void vfunc_30();
    virtual void vfunc_31();
    virtual void vfunc_32();
    virtual void vfunc_33();
    virtual void vfunc_34();
    virtual void vfunc_35();
    virtual void vfunc_36();
    virtual void vfunc_37();
    virtual void vfunc_38();
    virtual void vfunc_39();
    virtual void vfunc_40();
    virtual void vfunc_41();
    char m_pad04[0x8];
    Field0C* m_Field0C; // +0x0C
};

void InstanceDrive::vfunc_41()
{
    m_Field0C->sub_006E6390();
}

}

// ============================================================================
// [VERIFIED] core::InstanceDrive::vfunc_40 (0x006E5DC0, 8 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as core::InstanceDrive::vfunc_29 (0x002ABD60), which was matched first;
// its addresses and names were swapped for this function's.
// core::InstanceDrive::vfunc_40 (0x006E5DC0, 8 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field0C
{
    void sub_006E63B0();
};

namespace core {

class InstanceDrive
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
    virtual void vfunc_40();
    char m_pad04[0x8];
    Field0C* m_Field0C; // +0x0C
};

void InstanceDrive::vfunc_40()
{
    m_Field0C->sub_006E63B0();
}

}

// ============================================================================
// [VERIFIED] core::InstanceDrive::vfunc_43 (0x006E5DD0, 8 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as core::InstanceDrive::vfunc_29 (0x002ABD60), which was matched first;
// its addresses and names were swapped for this function's.
// core::InstanceDrive::vfunc_43 (0x006E5DD0, 8 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field0C
{
    void sub_006E63C0();
};

namespace core {

class InstanceDrive
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
    virtual void vfunc_30();
    virtual void vfunc_31();
    virtual void vfunc_32();
    virtual void vfunc_33();
    virtual void vfunc_34();
    virtual void vfunc_35();
    virtual void vfunc_36();
    virtual void vfunc_37();
    virtual void vfunc_38();
    virtual void vfunc_39();
    virtual void vfunc_40();
    virtual void vfunc_41();
    virtual void vfunc_42();
    virtual void vfunc_43();
    char m_pad04[0x8];
    Field0C* m_Field0C; // +0x0C
};

void InstanceDrive::vfunc_43()
{
    m_Field0C->sub_006E63C0();
}

}

// ============================================================================
// [VERIFIED] core::InstanceDrive::vfunc_42 (0x006E5DE0, 8 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as core::InstanceDrive::vfunc_29 (0x002ABD60), which was matched first;
// its addresses and names were swapped for this function's.
// core::InstanceDrive::vfunc_42 (0x006E5DE0, 8 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field0C
{
    void sub_006E63E0();
};

namespace core {

class InstanceDrive
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
    virtual void vfunc_42();
    char m_pad04[0x8];
    Field0C* m_Field0C; // +0x0C
};

void InstanceDrive::vfunc_42()
{
    m_Field0C->sub_006E63E0();
}

}

// ============================================================================
// [VERIFIED] core::InstanceDrive::vfunc_44 (0x006E5DF0, 8 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as core::InstanceDrive::vfunc_29 (0x002ABD60), which was matched first;
// its addresses and names were swapped for this function's.
// core::InstanceDrive::vfunc_44 (0x006E5DF0, 8 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field0C
{
    void sub_006E63F0();
};

namespace core {

class InstanceDrive
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
    virtual void vfunc_30();
    virtual void vfunc_31();
    virtual void vfunc_32();
    virtual void vfunc_33();
    virtual void vfunc_34();
    virtual void vfunc_35();
    virtual void vfunc_36();
    virtual void vfunc_37();
    virtual void vfunc_38();
    virtual void vfunc_39();
    virtual void vfunc_40();
    virtual void vfunc_41();
    virtual void vfunc_42();
    virtual void vfunc_43();
    virtual void vfunc_44();
    char m_pad04[0x8];
    Field0C* m_Field0C; // +0x0C
};

void InstanceDrive::vfunc_44()
{
    m_Field0C->sub_006E63F0();
}

}

// ============================================================================
// [VERIFIED] core::InstanceDrive::vfunc_45 (0x006E5E00, 65 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as core::InstanceDrive::vfunc_45 (0x002AC020), which was matched first;
// its addresses and names were swapped for this function's.
// core::InstanceDrive::vfunc_45 (0x006E5E00, 65 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field0C
{
    void sub_006E6370(int, int, int);
};

struct Object
{
    int sub_006E4C40(int, int, int);
};

extern "C" int __cdecl sub_006E3670(int);

namespace core {

class InstanceDrive
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
    virtual void vfunc_30();
    virtual void vfunc_31();
    virtual void vfunc_32();
    virtual void vfunc_33();
    virtual void vfunc_34();
    virtual void vfunc_35();
    virtual void vfunc_36();
    virtual void vfunc_37();
    virtual void vfunc_38();
    virtual void vfunc_39();
    virtual void vfunc_40();
    virtual void vfunc_41();
    virtual void vfunc_42();
    virtual void vfunc_43();
    virtual void vfunc_44();
    virtual int vfunc_45(int a1, int a2, int a3);
    char m_pad04[0x8];
    Field0C* m_Field0C; // +0x0C
};

int InstanceDrive::vfunc_45(int a1, int a2, int a3)
{
    int r_esi, t1;

    t1 = sub_006E3670(28);
    if (t1) {
        r_esi = ((Object*)t1)->sub_006E4C40((int)this, a1, a2);
    } else {
        r_esi = 0;
    }
    m_Field0C->sub_006E6370(r_esi, a3, 0);
    return r_esi;
}

}

// ============================================================================
// [VERIFIED] core::InstanceDrive::vfunc_46 (0x006E5E50, 12 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as core::InstanceDrive::vfunc_46 (0x002AC070), which was matched first;
// its addresses and names were swapped for this function's.
// core::InstanceDrive::vfunc_46 (0x006E5E50, 12 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_006E4330();
};

namespace core {

class InstanceDrive
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
    virtual void vfunc_30();
    virtual void vfunc_31();
    virtual void vfunc_32();
    virtual void vfunc_33();
    virtual void vfunc_34();
    virtual void vfunc_35();
    virtual void vfunc_36();
    virtual void vfunc_37();
    virtual void vfunc_38();
    virtual void vfunc_39();
    virtual void vfunc_40();
    virtual void vfunc_41();
    virtual void vfunc_42();
    virtual void vfunc_43();
    virtual void vfunc_44();
    virtual void vfunc_45();
    virtual void vfunc_46(int a1);
};

void InstanceDrive::vfunc_46(int a1)
{
    ((Object*)a1)->sub_006E4330();
}

}

// ============================================================================
// [VERIFIED] core::InstanceDrive::vfunc_48 (0x006E5E60, 8 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as core::InstanceDrive::vfunc_41 (Proto 0x0026E740), which was matched first;
// its addresses and names were swapped for this function's.
// core::InstanceDrive::vfunc_48 (Proto 0x006E5E60, 8 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field0C
{
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual void vfunc_05();
    virtual void vfunc_06();
};

namespace core {

class InstanceDrive
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
    virtual void vfunc_30();
    virtual void vfunc_31();
    virtual void vfunc_32();
    virtual void vfunc_33();
    virtual void vfunc_34();
    virtual void vfunc_35();
    virtual void vfunc_36();
    virtual void vfunc_37();
    virtual void vfunc_38();
    virtual void vfunc_39();
    virtual void vfunc_40();
    virtual void vfunc_41();
    virtual void vfunc_42();
    virtual void vfunc_43();
    virtual void vfunc_44();
    virtual void vfunc_45();
    virtual void vfunc_46();
    virtual void vfunc_47();
    virtual void vfunc_48();
    char m_pad04[0x8];
    Field0C* m_Field0C; // +0x0C
};

void InstanceDrive::vfunc_48()
{
    m_Field0C->vfunc_06();
}

}

// ============================================================================
// [VERIFIED] fight::SequenceAction::vfunc_04 (0x006E5E70, 8 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as fight::SequenceAction::vfunc_04 (Proto 0x0026E750), which was matched first;
// its addresses and names were swapped for this function's.
// fight::SequenceAction::vfunc_04 (Proto 0x006E5E70, 8 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field0C
{
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual void vfunc_05();
    virtual void vfunc_06();
    virtual void vfunc_07();
};

namespace fight {

class SequenceAction
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    char m_pad04[0x8];
    Field0C* m_Field0C; // +0x0C
};

void SequenceAction::vfunc_04()
{
    m_Field0C->vfunc_07();
}

}

// ============================================================================
// [VERIFIED] core::InstanceDrive::vfunc_03 (0x006E5E80, 81 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as core::InstanceDrive::vfunc_03 (Proto 0x0026E7B0), which was matched first;
// its addresses and names were swapped for this function's.
// core::InstanceDrive::vfunc_03 (Proto 0x006E5E80, 81 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual void vfunc_05(int);
};

extern "C" char DAT_0073523C[];
extern "C" char DAT_00772100[];
extern "C" char DAT_0077210C[];
extern "C" char DAT_0085CE14[];
extern "C" int DAT_0085CE2C;
extern "C" void __cdecl sub_006DF070(int);
extern "C" void __cdecl sub_006DF080(int);

namespace core {

class InstanceDrive
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual InstanceDrive* vfunc_03(int a1);
    int m_Field04; // +0x04
    char m_pad08[0x4];
    int m_Field0C; // +0x0C
};

InstanceDrive* InstanceDrive::vfunc_03(int a1)
{
    int t1;

    t1 = m_Field0C;
    *(int*)this = (int)DAT_0077210C;
    m_Field04 = (int)DAT_00772100;
    ((Object*)t1)->vfunc_01();
    *(int*)this = (int)DAT_0073523C;
    if (a1 & 1) {
        sub_006DF080((int)DAT_0085CE14);
        ((Object*)DAT_0085CE2C)->vfunc_05((int)this);
        sub_006DF070((int)DAT_0085CE14);
    }
    return this;
}

}

// [TODO] 0x006E5EE0 sub_006E5EE0 (114 B)
// [TODO] 0x006E5F60 sub_006E5F60 (66 B)
// [TODO] 0x006E5FB0 sub_006E5FB0 (67 B)
// ============================================================================
// [VERIFIED] sub_006E6000 (0x006E6000, 38 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// bin: pc
// va: 0x006E6000
// what: 
// tool: the portal's starter code (no AI)

// sub_006E6000 (PC 0x006E6000, 38 bytes)
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
    virtual void vfunc_23(int);
};

extern "C" void __cdecl sub_006E7DE0(int, int, int);

void __cdecl sub_006E6000(int a1, int a2, int a3, int a4)
{
    sub_006E7DE0(a1, a2, a3);
    ((Object*)*(int*)a1)->vfunc_23(a4);
}

// [TODO] 0x006E6070 core::Drive::vfunc_00 (23 B)
// [TODO] 0x006E60E0 sub_006E60E0 (36 B)
// ============================================================================
// [VERIFIED] sub_006E6110 (0x006E6110, 4 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// sub_006E6110 (PC 0x006E6110, 4 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

class Class_006E6110
{
public:
    void* sub_006E6110();
    char m_pad00[0x78];
    int m_Field78; // +0x78
};

void* Class_006E6110::sub_006E6110()
{
    return &m_Field78;
}

// [TODO] 0x006E6120 sub_006E6120 (57 B)
// [TODO] 0x006E6230 sub_006E6230 (29 B)
// [TODO] 0x006E6250 sub_006E6250 (50 B)
// [TODO] 0x006E6290 sub_006E6290 (31 B)
// [TODO] 0x006E62B0 sub_006E62B0 (63 B)
// ============================================================================
// [VERIFIED] sub_006E6360 (0x006E6360, 4 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// sub_006E6360 (PC 0x006E6360, 4 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

class Class_006E6360
{
public:
    bool sub_006E6360();
    char m_pad00[0x74];
    bool m_Field74; // +0x74
};

bool Class_006E6360::sub_006E6360()
{
    return m_Field74;
}

// ============================================================================
// [VERIFIED] sub_006E6380 (0x006E6380, 11 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// bin: pc
// va: 0x006E6380
// what: 
// tool: the portal's starter code (no AI)

// sub_006E6380 (PC 0x006E6380, 11 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct FieldD0
{
    void sub_006E7F90();
};

class Class_006E6380
{
public:
    void sub_006E6380();
    char m_pad00[0xD0];
    FieldD0* m_FieldD0; // +0xD0
};

void Class_006E6380::sub_006E6380()
{
    m_FieldD0->sub_006E7F90();
}

// ============================================================================
// [VERIFIED] sub_006E63B0 (0x006E63B0, 11 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_006E6380 (PC 0x006E6380), which was matched first;
// its addresses and names were swapped for this function's.
// bin: pc
// va: 0x006E63B0
// what: 
// tool: the portal's starter code (no AI)

// sub_006E63B0 (PC 0x006E63B0, 11 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct FieldD0
{
    void sub_006E8030();
};

class Class_006E63B0
{
public:
    void sub_006E63B0();
    char m_pad00[0xD0];
    FieldD0* m_FieldD0; // +0xD0
};

void Class_006E63B0::sub_006E63B0()
{
    m_FieldD0->sub_006E8030();
}

// ============================================================================
// [VERIFIED] sub_006E63E0 (0x006E63E0, 11 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_006E6380 (PC 0x006E6380), which was matched first;
// its addresses and names were swapped for this function's.
// bin: pc
// va: 0x006E63E0
// what: 
// tool: the portal's starter code (no AI)

// sub_006E63E0 (PC 0x006E63E0, 11 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct FieldD0
{
    void sub_006E8120();
};

class Class_006E63E0
{
public:
    void sub_006E63E0();
    char m_pad00[0xD0];
    FieldD0* m_FieldD0; // +0xD0
};

void Class_006E63E0::sub_006E63E0()
{
    m_FieldD0->sub_006E8120();
}

// ============================================================================
// [VERIFIED] sub_006E6400 (0x006E6400, 8 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00082DB0 (0x00082DB0), which was matched first;
// its addresses and names were swapped for this function's.
// sub_006E6400 (0x006E6400, 8 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_006E6930();
};

class Class_006E6400
{
public:
    void sub_006E6400();
};

void Class_006E6400::sub_006E6400()
{
    ((Object*)(int)this + 20)->sub_006E6930();
}

// ============================================================================
// [VERIFIED] sub_006E6410 (0x006E6410, 8 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00082DB0 (0x00082DB0), which was matched first;
// its addresses and names were swapped for this function's.
// sub_006E6410 (0x006E6410, 8 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_006E6980();
};

class Class_006E6410
{
public:
    void sub_006E6410();
};

void Class_006E6410::sub_006E6410()
{
    ((Object*)(int)this + 20)->sub_006E6980();
}

// ============================================================================
// [VERIFIED] sub_006E6420 (0x006E6420, 4 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// sub_006E6420 (PC 0x006E6420, 4 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

class Class_006E6420
{
public:
    void* sub_006E6420();
    char m_pad00[0x14];
    int m_Field14; // +0x14
};

void* Class_006E6420::sub_006E6420()
{
    return &m_Field14;
}

// ============================================================================
// [VERIFIED] core::Drive::vfunc_06 (0x006E6430, 7 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as core::Drive::vfunc_06 (Proto 0x0026EE60), which was matched first;
// its addresses and names were swapped for this function's.
// core::Drive::vfunc_06 (Proto 0x006E6430, 7 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

namespace core {

class Drive
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual void vfunc_05();
    virtual int vfunc_06(int a1, int a2);
};

int Drive::vfunc_06(int a1, int a2)
{
    return a2;
}

}

// ============================================================================
// [VERIFIED] core::Drive::vfunc_11 (0x006E6440, 5 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as core::Drive::vfunc_11 (Proto 0x0026EE70), which was matched first;
// its addresses and names were swapped for this function's.
// core::Drive::vfunc_11 (Proto 0x006E6440, 5 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

namespace core {

class Drive
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
    virtual int vfunc_11(int a1, int a2, int a3, int a4, int a5, int a6, int a7);
};

int Drive::vfunc_11(int a1, int a2, int a3, int a4, int a5, int a6, int a7)
{
    return 0;
}

}

// ============================================================================
// [VERIFIED] core::Drive::vfunc_15 (0x006E6450, 5 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as core::Drive::vfunc_15 (Proto 0x0026EE80), which was matched first;
// its addresses and names were swapped for this function's.
// core::Drive::vfunc_15 (Proto 0x006E6450, 5 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

namespace core {

class Drive
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
    virtual int vfunc_15(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9);
};

int Drive::vfunc_15(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9)
{
    return 0;
}

}

// ============================================================================
// [VERIFIED] core::Drive::vfunc_22 (0x006E6460, 8 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// What it does: core::Drive: Always returns 1.
// ============================================================================
// Same machine code as core::Drive::vfunc_22 (Proto 0x0026EEA0), which was matched first;
// its addresses and names were swapped for this function's.
// core::Drive::vfunc_22 (Proto 0x006E6460, 8 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

namespace core {

class Drive
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

int Drive::vfunc_22(int a1)
{
    return 1;
}

}

// ============================================================================
// [VERIFIED] core::Drive::vfunc_00 (0x006E6470, 8 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as core::ControllerSystemXBox::vfunc_00 (0x00248810), which was matched first;
// its addresses and names were swapped for this function's.
// core::Drive::vfunc_00 (0x006E6470, 8 bytes)
// An adjustor thunk. Nobody wrote this function: the compiler adds it for a class with two base
// classes that both declare the same virtual function. Called through the second base's table, it
// moves `this` back 4 bytes to the start of the object and jumps to the real function at
// 0x006E6530. So it is matched by declaring the class that way, not by writing a body.
// The two bases and their names are guesses; the first base is the part of the object in front
// of the second base (4 bytes).

namespace core {
class ControllerSystemXBox_Base0 { public: virtual void sub_006E6530(); };
class ControllerSystemXBox_Base1 { public: virtual void sub_006E6530(); };

class Drive : public ControllerSystemXBox_Base0, public ControllerSystemXBox_Base1
{
public:
    Drive();
    virtual void sub_006E6530();          // the real function; the thunk jumps here
};

Drive::Drive() {}                  // building one is what makes the compiler write its tables and the thunk
}

// ============================================================================
// [VERIFIED] core::Drive::vfunc_02 (0x006E6480, 8 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as core::Drive::vfunc_02 (Proto 0x0026EEC0), which was matched first;
// its addresses and names were swapped for this function's.
// core::Drive::vfunc_02 (Proto 0x006E6480, 8 bytes)
// An adjustor thunk. Nobody wrote this function: the compiler adds it for a class with two base
// classes that both declare the same virtual function. Called through the second base's table, it
// moves `this` back 12 bytes to the start of the object and jumps to the real function at
// 0x006E6530. So it is matched by declaring the class that way, not by writing a body.
// The two bases and their names are guesses; the first base is the part of the object in front
// of the second base (12 bytes).

namespace core {
class Drive_Base0 { public: virtual void sub_006E6530(); char m_pad04[0x8]; };
class Drive_Base1 { public: virtual void sub_006E6530(); };

class Drive : public Drive_Base0, public Drive_Base1
{
public:
    Drive();
    virtual void sub_006E6530();          // the real function; the thunk jumps here
};

Drive::Drive() {}                  // building one is what makes the compiler write its tables and the thunk
}

// ============================================================================
// [VERIFIED] core::SafeRefCount::vfunc_02 (0x006E6490, 31 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as core::BaseObject::vfunc_00 (0x00026BB0), which was matched first;
// its addresses and names were swapped for this function's.
// core::SafeRefCount::vfunc_02 (0x006E6490, 31 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_007721D8[];
extern "C" void __cdecl sub_0043CE70(int);

namespace core {

class SafeRefCount
{
public:
    virtual SafeRefCount* vfunc_02(int a1);
};

SafeRefCount* SafeRefCount::vfunc_02(int a1)
{
    *(int*)this = (int)DAT_007721D8;
    if (a1 & 1) {
        sub_0043CE70((int)this);
    }
    return this;
}

}

// [TODO] 0x006E64B0 sub_006E64B0 (127 B)
// [TODO] 0x006E6530 core::Drive::vfunc_03 (88 B)
// [TODO] 0x006E6590 core::Drive::vfunc_04 (257 B)
// [TODO] 0x006E66A0 sub_006E66A0 (103 B)
// ============================================================================
// [VERIFIED] core::CementLibrary::vfunc_00 (0x006E6710, 11 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as core::CementLibrary::vfunc_00 (0x002ACA40), which was matched first;
// its addresses and names were swapped for this function's.
// bin: xb
// va: 0x006E6710
// what: Calls virtual method slot 0 on the subobject at +0x04 of the pointer at +0x0C.
// tool: Gemini 4 Neon

struct SubObject04
{
    virtual void vfunc_00();
    void Call00() { vfunc_00(); }
};

struct Field0C
{
    int m_Field00;
    SubObject04 m_Field04; // +0x04
};

namespace core {

class CementLibrary
{
public:
    virtual void vfunc_00();
    char m_pad04[0x8];
    Field0C* m_Field0C; // +0x0C
};

void CementLibrary::vfunc_00()
{
    m_Field0C->m_Field04.Call00();
}

}

// ============================================================================
// [VERIFIED] core::CementLibrary::vfunc_01 (0x006E6720, 12 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as core::CementLibrary::vfunc_01 (0x002ACA50), which was matched first;
// its addresses and names were swapped for this function's.
// bin: xb
// va: 0x006E6720
// what: Calls virtual method slot 1 on the subobject at +0x04 of the pointer at +0x0C.
// tool: Gemini 4 Neon

struct SubObject04
{
    virtual void vfunc_00();
    virtual void vfunc_01();
    void Call01() { vfunc_01(); }
};

struct Field0C
{
    int m_Field00;
    SubObject04 m_Field04; // +0x04
};

namespace core {

class CementLibrary
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    char m_pad04[0x8];
    Field0C* m_Field0C; // +0x0C
};

void CementLibrary::vfunc_01()
{
    m_Field0C->m_Field04.Call01();
}

}

// ============================================================================
// [VERIFIED] core::CementLibrary::vfunc_05 (0x006E6730, 39 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G7 /Gd /GR /EHsc /Zp4
// ============================================================================
// bin: pc
// va: 0x006E6730
// what: 
// tool: the portal's starter code (no AI)

// core::CementLibrary::vfunc_05 (PC 0x006E6730, 39 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __cdecl sub_006DCAD0(void);
extern "C" void __cdecl sub_006DEFA0(int);

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
    char m_pad04[0x1C];
    int m_Field20; // +0x20
};

void CementLibrary::vfunc_05()
{
    if (!m_Field20) {
        do {
            sub_006DCAD0();
            sub_006DEFA0(0);
        } while (!m_Field20);
    }
}

}

// ============================================================================
// [VERIFIED] core::CementLibrary::vfunc_07 (0x006E6760, 10 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G7 /Gd /GR /EHsc /Zp4
// ============================================================================
// bin: pc
// va: 0x006E6760
// what: 
// tool: the portal's starter code (no AI)

// core::CementLibrary::vfunc_07 (PC 0x006E6760, 10 bytes)
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
    virtual int vfunc_07();
    char m_pad04[0x1C];
    int m_Field20; // +0x20
};

int CementLibrary::vfunc_07()
{
    return m_Field20 == 1;
}

}

// ============================================================================
// [VERIFIED] core::CementLibrary::vfunc_06 (0x006E6770, 23 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as core::CementLibrary::vfunc_06 (Proto 0x0026F1B0), which was matched first;
// its addresses and names were swapped for this function's.
// core::CementLibrary::vfunc_06 (Proto 0x006E6770, 23 bytes)
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

// [TODO] 0x006E6790 sub_006E6790 (62 B)
// [TODO] 0x006E6810 core::CementLibrary::vfunc_08 (151 B)
// ============================================================================
// [VERIFIED] core::CementLibrary::vfunc_09 (0x006E68B0, 51 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as core::CementLibrary::vfunc_09 (Proto 0x0026F300), which was matched first;
// its addresses and names were swapped for this function's.
// core::CementLibrary::vfunc_09 (Proto 0x006E68B0, 51 bytes)
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

// [TODO] 0x006E68F0 sub_006E68F0 (54 B)
// ============================================================================
// [VERIFIED] sub_006E69F0 (0x006E69F0, 29 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_002ACD30 (0x002ACD30), which was matched first;
// its addresses and names were swapped for this function's.
// sub_006E69F0 (0x006E69F0, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __cdecl sub_006DF080(int);

class Class_006E69F0
{
public:
    void sub_006E69F0(int a1);
    char m_pad00[0x10];
    int m_Field10; // +0x10
    int m_Field14; // +0x14
};

void Class_006E69F0::sub_006E69F0(int a1)
{
    sub_006DF080((int)(&m_Field14));
    m_Field10 = *(int*)((int)this + (a1 * 4));
}

// ============================================================================
// [VERIFIED] sub_006E6A10 (0x006E6A10, 14 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_002ACD50 (0x002ACD50), which was matched first;
// its addresses and names were swapped for this function's.
// sub_006E6A10 (0x006E6A10, 14 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

class Class_006E6A10
{
public:
    int sub_006E6A10();
    char m_pad00[0x10];
    int m_Field10; // +0x10
};

int Class_006E6A10::sub_006E6A10()
{
    int r_eax;

    r_eax = m_Field10;
    if (r_eax) {
        m_Field10 = *(int*)(r_eax + 100);
    }
    return r_eax;
}

// [TODO] 0x006E6A40 sub_006E6A40 (64 B)
// [TODO] 0x006E6A80 sub_006E6A80 (194 B)
// [TODO] 0x006E6B50 core::CementLibrary::vfunc_00 (23 B)
// ============================================================================
// [VERIFIED] core::CementLibrary::vfunc_01 (0x006E6B70, 8 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as core::CementLibrary::vfunc_01 (0x002ACEB0), which was matched first;
// its addresses and names were swapped for this function's.
// core::CementLibrary::vfunc_01 (0x006E6B70, 8 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_006E6090();
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
    ((Object*)(int)this + 16)->sub_006E6090();
}

}

// ============================================================================
// [VERIFIED] core::CementLibrary::vfunc_00 (0x006E6B80, 8 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as core::ControllerSystemXBox::vfunc_00 (0x00248810), which was matched first;
// its addresses and names were swapped for this function's.
// core::CementLibrary::vfunc_00 (0x006E6B80, 8 bytes)
// An adjustor thunk. Nobody wrote this function: the compiler adds it for a class with two base
// classes that both declare the same virtual function. Called through the second base's table, it
// moves `this` back 4 bytes to the start of the object and jumps to the real function at
// 0x006E6B50. So it is matched by declaring the class that way, not by writing a body.
// The two bases and their names are guesses; the first base is the part of the object in front
// of the second base (4 bytes).

namespace core {
class ControllerSystemXBox_Base0 { public: virtual void sub_006E6B50(); };
class ControllerSystemXBox_Base1 { public: virtual void sub_006E6B50(); };

class CementLibrary : public ControllerSystemXBox_Base0, public ControllerSystemXBox_Base1
{
public:
    CementLibrary();
    virtual void sub_006E6B50();          // the real function; the thunk jumps here
};

CementLibrary::CementLibrary() {}                  // building one is what makes the compiler write its tables and the thunk
}

// ============================================================================
// [VERIFIED] core::CementLibrary::vfunc_01 (0x006E6B90, 8 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as core::ControllerSystemXBox::vfunc_00 (0x00248810), which was matched first;
// its addresses and names were swapped for this function's.
// core::CementLibrary::vfunc_01 (0x006E6B90, 8 bytes)
// An adjustor thunk. Nobody wrote this function: the compiler adds it for a class with two base
// classes that both declare the same virtual function. Called through the second base's table, it
// moves `this` back 4 bytes to the start of the object and jumps to the real function at
// 0x006E6B70. So it is matched by declaring the class that way, not by writing a body.
// The two bases and their names are guesses; the first base is the part of the object in front
// of the second base (4 bytes).

namespace core {
class ControllerSystemXBox_Base0 { public: virtual void sub_006E6B70(); };
class ControllerSystemXBox_Base1 { public: virtual void sub_006E6B70(); };

class CementLibrary : public ControllerSystemXBox_Base0, public ControllerSystemXBox_Base1
{
public:
    CementLibrary();
    virtual void sub_006E6B70();          // the real function; the thunk jumps here
};

CementLibrary::CementLibrary() {}                  // building one is what makes the compiler write its tables and the thunk
}

// ============================================================================
// [VERIFIED] core::CementLibrary::vfunc_02 (0x006E6BA0, 8 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as core::ControllerSystemXBox::vfunc_00 (0x00248810), which was matched first;
// its addresses and names were swapped for this function's.
// core::CementLibrary::vfunc_02 (0x006E6BA0, 8 bytes)
// An adjustor thunk. Nobody wrote this function: the compiler adds it for a class with two base
// classes that both declare the same virtual function. Called through the second base's table, it
// moves `this` back 4 bytes to the start of the object and jumps to the real function at
// 0x004979D0. So it is matched by declaring the class that way, not by writing a body.
// The two bases and their names are guesses; the first base is the part of the object in front
// of the second base (4 bytes).

namespace core {
class ControllerSystemXBox_Base0 { public: virtual void sub_004979D0(); };
class ControllerSystemXBox_Base1 { public: virtual void sub_004979D0(); };

class CementLibrary : public ControllerSystemXBox_Base0, public ControllerSystemXBox_Base1
{
public:
    CementLibrary();
    virtual void sub_004979D0();          // the real function; the thunk jumps here
};

CementLibrary::CementLibrary() {}                  // building one is what makes the compiler write its tables and the thunk
}

// ============================================================================
// [VERIFIED] core::CementLibrary::vfunc_03 (0x006E6BB0, 8 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as core::ControllerSystemXBox::vfunc_00 (0x00248810), which was matched first;
// its addresses and names were swapped for this function's.
// core::CementLibrary::vfunc_03 (0x006E6BB0, 8 bytes)
// An adjustor thunk. Nobody wrote this function: the compiler adds it for a class with two base
// classes that both declare the same virtual function. Called through the second base's table, it
// moves `this` back 4 bytes to the start of the object and jumps to the real function at
// 0x006E6F50. So it is matched by declaring the class that way, not by writing a body.
// The two bases and their names are guesses; the first base is the part of the object in front
// of the second base (4 bytes).

namespace core {
class ControllerSystemXBox_Base0 { public: virtual void sub_006E6F50(); };
class ControllerSystemXBox_Base1 { public: virtual void sub_006E6F50(); };

class CementLibrary : public ControllerSystemXBox_Base0, public ControllerSystemXBox_Base1
{
public:
    CementLibrary();
    virtual void sub_006E6F50();          // the real function; the thunk jumps here
};

CementLibrary::CementLibrary() {}                  // building one is what makes the compiler write its tables and the thunk
}

// ============================================================================
// [VERIFIED] core::CementLibrary::vfunc_00 (0x006E6BC0, 8 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as core::CementLibrary::vfunc_00 (Proto 0x0026F620), which was matched first;
// its addresses and names were swapped for this function's.
// core::CementLibrary::vfunc_00 (Proto 0x006E6BC0, 8 bytes)
// An adjustor thunk. Nobody wrote this function: the compiler adds it for a class with two base
// classes that both declare the same virtual function. Called through the second base's table, it
// moves `this` back 8 bytes to the start of the object and jumps to the real function at
// 0x006E6F50. So it is matched by declaring the class that way, not by writing a body.
// The two bases and their names are guesses; the first base is the part of the object in front
// of the second base (8 bytes).

namespace core {
class CementLibrary_Base0 { public: virtual void sub_006E6F50(); char m_pad04[0x4]; };
class CementLibrary_Base1 { public: virtual void sub_006E6F50(); };

class CementLibrary : public CementLibrary_Base0, public CementLibrary_Base1
{
public:
    CementLibrary();
    virtual void sub_006E6F50();          // the real function; the thunk jumps here
};

CementLibrary::CementLibrary() {}                  // building one is what makes the compiler write its tables and the thunk
}

// ============================================================================
// [VERIFIED] core::CementLibrary::vfunc_02 (0x006E6BD0, 8 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as core::CementLibrary::vfunc_02 (Proto 0x0026F630), which was matched first;
// its addresses and names were swapped for this function's.
// core::CementLibrary::vfunc_02 (Proto 0x006E6BD0, 8 bytes)
// An adjustor thunk. Nobody wrote this function: the compiler adds it for a class with two base
// classes that both declare the same virtual function. Called through the second base's table, it
// moves `this` back 16 bytes to the start of the object and jumps to the real function at
// 0x006E6F50. So it is matched by declaring the class that way, not by writing a body.
// The two bases and their names are guesses; the first base is the part of the object in front
// of the second base (16 bytes).

namespace core {
class CementLibrary_Base0 { public: virtual void sub_006E6F50(); char m_pad04[0xC]; };
class CementLibrary_Base1 { public: virtual void sub_006E6F50(); };

class CementLibrary : public CementLibrary_Base0, public CementLibrary_Base1
{
public:
    CementLibrary();
    virtual void sub_006E6F50();          // the real function; the thunk jumps here
};

CementLibrary::CementLibrary() {}                  // building one is what makes the compiler write its tables and the thunk
}

// [TODO] 0x006E6BE0 core::CementLibrary::vfunc_04 (419 B)
// [TODO] 0x006E6C82 sub_006E6C82 (257 B)
// [TODO] 0x006E6D90 sub_006E6D90 (137 B)
// ============================================================================
// [VERIFIED] sub_006E6E20 (0x006E6E20, 54 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// bin: pc
// va: 0x006E6E20
// what: 
// tool: the portal's starter code (no AI)

// sub_006E6E20 (PC 0x006E6E20, 54 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __cdecl sub_006DEC00(void);
extern "C" void __cdecl sub_006DF050(int);

class Class_006E6E20
{
public:
    Class_006E6E20* sub_006E6E20();
    int m_Field00; // +0x00
    int m_Field04; // +0x04
    int m_Field08; // +0x08
    int m_Field0C; // +0x0C
    int m_Field10; // +0x10
    int m_Field14; // +0x14
    char m_pad18[0x14];
    int m_Field2C; // +0x2C
    int m_Field30; // +0x30
    int m_Field34; // +0x34
    int m_Field38; // +0x38
};

Class_006E6E20* Class_006E6E20::sub_006E6E20()
{
    m_Field10 = 0;
    m_Field2C = 0;
    m_Field30 = 0;
    m_Field34 = 0;
    m_Field38 = 0;
    sub_006DEC00();
    m_Field00 = 0;
    m_Field08 = 0;
    m_Field04 = 0;
    m_Field0C = 0;
    sub_006DF050((int)(&m_Field14));
    return this;
}

// [TODO] 0x006E6E60 sub_006E6E60 (227 B)
// ============================================================================
// [VERIFIED] sub_006E6F80 (0x006E6F80, 41 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G7 /Gd /GR /EHsc /Zp4
// ============================================================================
// bin: pc
// va: 0x006E6F80
// what: 
// tool: the portal's starter code (no AI)

// sub_006E6F80 (PC 0x006E6F80, 41 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int __cdecl sub_006DCC70(int);

class Class_006E6F80
{
public:
    void sub_006E6F80(int a1, int a2);
    void sub_006E6D90(int, int);
};

void Class_006E6F80::sub_006E6F80(int a1, int a2)
{
    int r_eax;

    r_eax = a1;
    if (*(unsigned char*)r_eax == 92) {
        r_eax += 1;
    }
    r_eax = sub_006DCC70(r_eax);
    sub_006E6D90(r_eax, a2);
}

// [TODO] 0x006E6FB0 sub_006E6FB0 (135 B)
// ============================================================================
// [VERIFIED] sub_006E7040 (0x006E7040, 37 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_002816D0 (Proto 0x002816D0), which was matched first;
// its addresses and names were swapped for this function's.
// sub_006E7040 (Proto 0x006E7040, 37 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

class Class_006E7040
{
public:
    Class_006E7040* sub_006E7040();
    int m_Field00; // +0x00
    int m_Field04; // +0x04
    int m_Field08; // +0x08
    int m_Field0C; // +0x0C
    int m_Field10; // +0x10
    int m_Field14; // +0x14
    int m_Field18; // +0x18
    int m_Field1C; // +0x1C
    int m_Field20; // +0x20
    int m_Field24; // +0x24
    int m_Field28; // +0x28
};

Class_006E7040* Class_006E7040::sub_006E7040()
{
    m_Field00 = 0;
    m_Field04 = 0;
    m_Field08 = 0;
    m_Field0C = 0;
    m_Field10 = 0;
    m_Field14 = 0;
    m_Field18 = 0;
    m_Field1C = 0;
    m_Field20 = 0;
    m_Field24 = 0;
    m_Field28 = 0;
    return this;
}

// ============================================================================
// [VERIFIED] sub_006E7070 (0x006E7070, 18 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00281710 (Proto 0x00281710), which was matched first;
// its addresses and names were swapped for this function's.
// sub_006E7070 (Proto 0x006E7070, 18 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field00
{
    virtual void vfunc_00();
    virtual void vfunc_01();
};

class Class_006E7070
{
public:
    void sub_006E7070();
    Field00* m_Field00; // +0x00
};

void Class_006E7070::sub_006E7070()
{
    m_Field00->vfunc_01();
    m_Field00 = 0;
}

// [TODO] 0x006E7390 sub_006E7390 (124 B)
// [TODO] 0x006E7410 sub_006E7410 (28 B)
// ============================================================================
// [VERIFIED] sub_006E7430 (0x006E7430, 80 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// bin: pc
// va: 0x006E7430
// what: 
// tool: the portal's starter code (no AI)

// sub_006E7430 (PC 0x006E7430, 80 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    virtual void vfunc_00();
    virtual void vfunc_01();
};

extern "C" int DAT_0072F0FC;
extern "C" char DAT_00772320[];
extern "C" char DAT_00772330[];
extern "C" char DAT_0077233C[];
extern "C" void __cdecl sub_006DF060(int);

class Class_006E7430
{
public:
    void sub_006E7430();
    void sub_006E6030();
    int m_Field00; // +0x00
    int m_Field04; // +0x04
    char m_pad08[0x4];
    int m_Field0C; // +0x0C
    char m_pad10[0xC0];
    int m_FieldD0; // +0xD0
    char m_padD4[0x4];
    int m_FieldD8; // +0xD8
    char m_padDC[0x1C];
    int m_FieldF8; // +0xF8
};

void Class_006E7430::sub_006E7430()
{
    int t1;

    t1 = m_FieldD0;
    m_Field00 = (int)DAT_0077233C;
    m_Field04 = (int)DAT_00772330;
    m_Field0C = (int)DAT_00772320;
    ((Object*)t1)->vfunc_01();
    m_FieldD0 = 0;
    sub_006DF060((int)(&m_FieldF8));
    ((void (__stdcall*)(int))DAT_0072F0FC)(m_FieldD8);
    sub_006E6030();
}

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

// [TODO] 0x006E75D0 sub_006E75D0 (150 B)
// [TODO] 0x006E7730 sub_006E7730 (116 B)
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

// [TODO] 0x006E77D0 sub_006E77D0 (220 B)
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

// [TODO] 0x006E7930 core::Win32Drive::vfunc_10 (265 B)
// [TODO] 0x006E7938 sub_006E7938 (257 B)
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

// [TODO] 0x006E7AB0 core::Win32Drive::vfunc_15 (178 B)
// [TODO] 0x006E7B70 core::Win32Drive::vfunc_20 (137 B)
// [TODO] 0x006E7C00 core::Win32Drive::vfunc_21 (140 B)
// [TODO] 0x006E7C90 core::Win32Drive::vfunc_17 (108 B)
// [TODO] 0x006E7D00 core::Win32Drive::vfunc_18 (106 B)
// [TODO] 0x006E7D70 core::Win32Drive::vfunc_19 (106 B)
// [TODO] 0x006E7DE0 sub_006E7DE0 (60 B)
// [TODO] 0x006E7E20 sub_006E7E20 (107 B)
// ============================================================================
// [VERIFIED] core::Drive::vfunc_01 (0x006E7E90, 8 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as core::Drive::vfunc_01 (0x002C1450), which was matched first;
// its addresses and names were swapped for this function's.
// core::Drive::vfunc_01 (0x006E7E90, 8 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_006E6090();
};

namespace core {

class Drive
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
};

void Drive::vfunc_01()
{
    ((Object*)(int)this + 12)->sub_006E6090();
}

}

// ============================================================================
// [VERIFIED] AnimationRetargetingAction::vfunc_14 (0x006E7EA0, 4 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// AnimationRetargetingAction::vfunc_14 (PC 0x006E7EA0, 4 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

class AnimationRetargetingAction
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
    virtual int vfunc_14();
    char m_pad04[0xC];
    int m_Field10; // +0x10
};

int AnimationRetargetingAction::vfunc_14()
{
    return m_Field10;
}

// ============================================================================
// [VERIFIED] core::DriveThread::vfunc_00 (0x006E7EB0, 11 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as core::DriveThread::vfunc_00 (0x002C1460), which was matched first;
// its addresses and names were swapped for this function's.
// core::DriveThread::vfunc_00 (0x006E7EB0, 11 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __cdecl sub_006DF080(int);

namespace core {

class DriveThread
{
public:
    virtual void vfunc_00();
    char m_pad04[0x4];
    int m_Field08; // +0x08
};

void DriveThread::vfunc_00()
{
    sub_006DF080(m_Field08);
}

}

// ============================================================================
// [VERIFIED] core::DriveThread::vfunc_01 (0x006E7EC0, 11 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as core::DriveThread::vfunc_00 (0x002C1460), which was matched first;
// its addresses and names were swapped for this function's.
// core::DriveThread::vfunc_01 (0x006E7EC0, 11 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __cdecl sub_006DF070(int);

namespace core {

class DriveThread
{
public:
    virtual void vfunc_01();
    char m_pad04[0x4];
    int m_Field08; // +0x08
};

void DriveThread::vfunc_01()
{
    sub_006DF070(m_Field08);
}

}

// [TODO] 0x006E8030 sub_006E8030 (123 B)
// ============================================================================
// [VERIFIED] sub_006E80B0 (0x006E80B0, 103 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G7 /Gd /GR /EHsc /Zp4
// ============================================================================
// bin: pc
// va: 0x006E80B0
// what: 
// tool: the portal's starter code (no AI)

// sub_006E80B0 (PC 0x006E80B0, 103 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __cdecl sub_006DF0D0(int);

class Class_006E80B0
{
public:
    void sub_006E80B0(int a1, int a2);
    char m_pad00[0x5C];
    int m_Field5C; // +0x5C
};

void Class_006E80B0::sub_006E80B0(int a1, int a2)
{
    int r_eax, r_ebx, r_edi, r_esi;

    r_eax = a1;
    r_edi = (a1 << 4) + (int)this;
    if (*(unsigned short*)((a1 << 4) + (int)this + 132) == 1) {
        r_esi = *(int*)((int)this + (r_eax * 4) + 96);
        if (r_esi) {
            r_ebx = (int)(&m_Field5C);
            do {
                sub_006DF0D0(r_ebx);
                r_esi = *(int*)(r_esi + 4);
            } while (r_esi);
            r_eax = a1;
        }
        r_eax += 8;
        r_eax <<= 4;
        *(int*)(r_edi + 124) = 0;
        *(bool*)(r_edi + 134) = false;
        *(int*)(r_eax + (int)this) = -1;
    }
    *(unsigned short*)(r_edi + 132) += 65535;
}

// [TODO] 0x006E8120 sub_006E8120 (43 B)
// ============================================================================
// [VERIFIED] sub_006E8190 (0x006E8190, 36 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// What it does: Passes a value to another object, then runs a step on the part of this object at +0xAC.
// ============================================================================
// bin: pc
// va: 0x006E8190
// what: Passes a value to another object, then runs a step on the part of this object at +0xAC.
// tool: Claude Opus 5.5 (transplanted from proto:0x002851F0, nearest by portal/tools/similar.py)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_006E62B0(int);
};

extern "C" void __cdecl sub_006DF0C0(int);

class Class_006E8190
{
public:
    void sub_006E8190(int a1, int a2);
};

void Class_006E8190::sub_006E8190(int a1, int a2)
{
    ((Object*)a1)->sub_006E62B0(a2);
    sub_006DF0C0((int)this + 172);
}

// ============================================================================
// [VERIFIED] sub_006E81C0 (0x006E81C0, 26 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// What it does: Stores a yes/no value at +0xB0, then runs a step on the part of this object at +0xAC.
// ============================================================================
// bin: pc
// va: 0x006E81C0
// what: Stores a yes/no value at +0xB0, then runs a step on the part of this object at +0xAC.
// tool: Claude Opus 5.5 (transplanted from proto:0x00285220, nearest by portal/tools/similar.py)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __cdecl sub_006DF0D0(int);

class Class_006E81C0
{
public:
    void sub_006E81C0(bool a1);
    char m_pad00[0xB0];
    bool m_FieldB0; // +0xB0
};

void Class_006E81C0::sub_006E81C0(bool a1)
{
    m_FieldB0 = a1;
    sub_006DF0D0((int)this + 172);
}

// [TODO] 0x006E81E0 sub_006E81E0 (154 B)
// ============================================================================
// [VERIFIED] core::DriveThread::vfunc_00 (0x006E82C0, 8 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as core::ControllerSystemXBox::vfunc_00 (0x00248810), which was matched first;
// its addresses and names were swapped for this function's.
// core::DriveThread::vfunc_00 (0x006E82C0, 8 bytes)
// An adjustor thunk. Nobody wrote this function: the compiler adds it for a class with two base
// classes that both declare the same virtual function. Called through the second base's table, it
// moves `this` back 4 bytes to the start of the object and jumps to the real function at
// 0x006E8610. So it is matched by declaring the class that way, not by writing a body.
// The two bases and their names are guesses; the first base is the part of the object in front
// of the second base (4 bytes).

namespace core {
class ControllerSystemXBox_Base0 { public: virtual void sub_006E8610(); };
class ControllerSystemXBox_Base1 { public: virtual void sub_006E8610(); };

class DriveThread : public ControllerSystemXBox_Base0, public ControllerSystemXBox_Base1
{
public:
    DriveThread();
    virtual void sub_006E8610();          // the real function; the thunk jumps here
};

DriveThread::DriveThread() {}                  // building one is what makes the compiler write its tables and the thunk
}

// ============================================================================
// [VERIFIED] core::DriveThread::vfunc_02 (0x006E82D0, 8 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as core::Drive::vfunc_02 (Proto 0x0026EEC0), which was matched first;
// its addresses and names were swapped for this function's.
// core::DriveThread::vfunc_02 (Proto 0x006E82D0, 8 bytes)
// An adjustor thunk. Nobody wrote this function: the compiler adds it for a class with two base
// classes that both declare the same virtual function. Called through the second base's table, it
// moves `this` back 12 bytes to the start of the object and jumps to the real function at
// 0x006E8610. So it is matched by declaring the class that way, not by writing a body.
// The two bases and their names are guesses; the first base is the part of the object in front
// of the second base (12 bytes).

namespace core {
class Drive_Base0 { public: virtual void sub_006E8610(); char m_pad04[0x8]; };
class Drive_Base1 { public: virtual void sub_006E8610(); };

class DriveThread : public Drive_Base0, public Drive_Base1
{
public:
    DriveThread();
    virtual void sub_006E8610();          // the real function; the thunk jumps here
};

DriveThread::DriveThread() {}                  // building one is what makes the compiler write its tables and the thunk
}

// [TODO] 0x006E8530 sub_006E8530 (209 B)
// ============================================================================
// [VERIFIED] core::DriveThread::vfunc_03 (0x006E8610, 36 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as core::ControllerSystemXBox::vfunc_03 (0x00248820), which was matched first;
// its addresses and names were swapped for this function's.
// core::DriveThread::vfunc_03 (0x006E8610, 36 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_007F5A70;
extern "C" void __cdecl sub_006DC430(int, int);
extern "C" void __cdecl sub_006E7E20(void);

namespace core {

class DriveThread
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual DriveThread* vfunc_03(int a1);
};

DriveThread* DriveThread::vfunc_03(int a1)
{
    sub_006E7E20();
    if (a1 & 1) {
        sub_006DC430(DAT_007F5A70, (int)this);
    }
    return this;
}

}

// [TODO] 0x006E8640 sub_006E8640 (692 B)
// ============================================================================
// [VERIFIED] sub_006E8B20 (0x006E8B20, 83 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_001FF040 (Proto 0x001FF040), which was matched first;
// its addresses and names were swapped for this function's.
// sub_006E8B20 (Proto 0x006E8B20, 83 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

class Class_006E8B20
{
public:
    int sub_006E8B20(int a1);
    int m_Field00; // +0x00
    int m_Field04; // +0x04
};

int Class_006E8B20::sub_006E8B20(int a1)
{
    int r_eax, r_edi, r_esi;

    r_eax = *(int*)a1;
    r_esi = *(int*)(r_eax + 4);
    *(int*)a1 = r_esi;
    r_esi = *(int*)(r_eax + 4);
    r_edi = (int)(&m_Field04);
    if (r_esi != ((int)(&m_Field04))) {
        *(int*)(r_esi + 8) = a1;
    }
    r_esi = *(int*)(a1 + 8);
    *(int*)(r_eax + 8) = r_esi;
    r_esi = *(int*)(a1 + 8);
    if (r_esi == r_edi) {
        m_Field00 = r_eax;
        *(int*)(r_eax + 4) = a1;
        *(int*)(a1 + 8) = r_eax;
        return r_eax;
    }
    if (a1 == *(int*)r_esi) {
        *(int*)r_esi = r_eax;
        *(int*)(r_eax + 4) = a1;
        *(int*)(a1 + 8) = r_eax;
        return r_eax;
    }
    *(int*)(r_esi + 4) = r_eax;
    *(int*)(r_eax + 4) = a1;
    *(int*)(a1 + 8) = r_eax;
    return r_eax;
}

// [TODO] 0x006E8B80 sub_006E8B80 (599 B)
// [TODO] 0x006E9160 sub_006E9160 (25 B)
// [TODO] 0x006E9180 sub_006E9180 (42 B)
// [TODO] 0x006E91B0 sub_006E91B0 (194 B)
// ============================================================================
// [VERIFIED] sub_006E9280 (0x006E9280, 22 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_001FF7A0 (Proto 0x001FF7A0), which was matched first;
// its addresses and names were swapped for this function's.
// sub_006E9280 (Proto 0x006E9280, 22 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

class Class_006E9280
{
public:
    Class_006E9280* sub_006E9280(int a1);
    int m_Field00; // +0x00
    int m_Field04; // +0x04
    int m_Field08; // +0x08
    int m_Field0C; // +0x0C
};

Class_006E9280* Class_006E9280::sub_006E9280(int a1)
{
    m_Field00 = a1;
    m_Field04 = 0;
    m_Field08 = 0;
    m_Field0C = 0;
    return this;
}

// [TODO] 0x006E9340 sub_006E9340 (96 B)
// [TODO] 0x006E93A0 sub_006E93A0 (162 B)
// [TODO] 0x006E9450 sub_006E9450 (121 B)
// ============================================================================
// [VERIFIED] sub_006E94F0 (0x006E94F0, 54 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G7 /Gd /GR /EHsc /Zp4
// ============================================================================
// bin: pc
// va: 0x006E94F0
// what: 
// tool: the portal's starter code (no AI)

// sub_006E94F0 (PC 0x006E94F0, 54 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

class Class_006E94F0
{
public:
    int sub_006E94F0();
};

int Class_006E94F0::sub_006E94F0()
{
    int r_eax, r_ecx, r_edx, t1;

    r_ecx = (int)this;
    r_edx = *(int*)r_ecx;
L_04:
    *(int*)(r_ecx + 4) += 1;
    r_eax = *(int*)(r_ecx + 4);
    if ((unsigned int)r_eax < (unsigned int)*(unsigned short*)(r_edx + 12)) {
        t1 = *(int*)(*(int*)r_edx + (r_eax * 4));
        if (!*(int*)(*(int*)r_edx + (r_eax * 4))) goto L_04;
        if (t1 == (r_edx + 8)) goto L_04;
    }
    r_ecx = *(unsigned short*)(r_edx + 12);
    if ((unsigned int)r_eax >= (unsigned int)r_ecx) {
        r_eax = 0;
        return r_eax;
    }
    r_edx = *(int*)r_edx;
    r_eax = *(int*)(r_edx + (r_eax * 4));
    return r_eax;
}

// ============================================================================
// [VERIFIED] sub_006E9530 (0x006E9530, 27 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_001FFA30 (Proto 0x001FFA30), which was matched first;
// its addresses and names were swapped for this function's.
// sub_006E9530 (Proto 0x006E9530, 27 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

class Class_006E9530
{
public:
    int sub_006E9530();
    int m_Field00; // +0x00
    int m_Field04; // +0x04
};

int Class_006E9530::sub_006E9530()
{
    int t1, t2;

    t1 = m_Field04;
    if (m_Field04 >= 0) {
        t2 = m_Field00;
        if ((unsigned int)t1 >= (unsigned int)*(unsigned short*)(m_Field00 + 12)) goto L_18;
        return *(int*)(*(int*)(t2 + 4) + (t1 * 4));
    }
L_18:
    return 0;
}

// ============================================================================
// [VERIFIED] sub_006E9550 (0x006E9550, 68 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G7 /Gd /GR /EHsc /Zp4
// ============================================================================
// bin: pc
// va: 0x006E9550
// what: 
// tool: the portal's starter code (no AI)

// sub_006E9550 (PC 0x006E9550, 68 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

class Class_006E9550
{
public:
    Class_006E9550* sub_006E9550(int a1, int a2, int a3);
    void sub_006E91B0(int);
    int m_Field00; // +0x00
    int m_Field04; // +0x04
    int m_Field08; // +0x08
    unsigned short m_Field0C; // +0x0C
    unsigned short m_Field0E; // +0x0E
    unsigned short m_Field10; // +0x10
    unsigned short m_Field12; // +0x12
    unsigned short m_Field14; // +0x14
    unsigned char m_Field16; // +0x16
};

Class_006E9550* Class_006E9550::sub_006E9550(int a1, int a2, int a3)
{
    m_Field16 &= 254;
    m_Field00 = 0;
    m_Field04 = 0;
    m_Field08 = 0;
    m_Field0C = (unsigned short)a1;
    m_Field0E = 0;
    m_Field10 = 0;
    m_Field12 = (unsigned short)a3;
    m_Field14 = (unsigned short)a2;
    sub_006E91B0((unsigned short)((unsigned short)a1));
    return this;
}

// [TODO] 0x006E95A0 sub_006E95A0 (167 B)
// [TODO] 0x006E9660 sub_006E9660 (234 B)
// ============================================================================
// [VERIFIED] sub_006E97D0 (0x006E97D0, 5 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00023D40 (0x00023D40), which was matched first;
// its addresses and names were swapped for this function's.
// sub_006E97D0 (0x006E97D0, 5 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __cdecl sub_0043CE00(void);

class Class_006E97D0
{
public:
    void sub_006E97D0();
};

void Class_006E97D0::sub_006E97D0()
{
    sub_0043CE00();
}

// [TODO] 0x006E97E0 sub_006E97E0 (40 B)
// ============================================================================
// [VERIFIED] sub_006E9810 (0x006E9810, 5 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00023D40 (0x00023D40), which was matched first;
// its addresses and names were swapped for this function's.
// sub_006E9810 (0x006E9810, 5 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __cdecl sub_0043CE70(void);

class Class_006E9810
{
public:
    void sub_006E9810();
};

void Class_006E9810::sub_006E9810()
{
    sub_0043CE70();
}

// ============================================================================
// [VERIFIED] GameMemorySegmentCollection::vfunc_02 (0x006E9820, 4 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// GameMemorySegmentCollection::vfunc_02 (PC 0x006E9820, 4 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

class GameMemorySegmentCollection
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual int vfunc_02();
    char m_pad04[0x8];
    int m_Field0C; // +0x0C
};

int GameMemorySegmentCollection::vfunc_02()
{
    return m_Field0C;
}

// [TODO] 0x006E9830 sub_006E9830 (17 B)
// [TODO] 0x006E9850 content::LoadInventory::vfunc_04 (126 B)
// ============================================================================
// [VERIFIED] sub_006E9A10 (0x006E9A10, 33 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_001FD160 (Proto 0x001FD160), which was matched first;
// its addresses and names were swapped for this function's.
// sub_006E9A10 (Proto 0x006E9A10, 33 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    virtual void vfunc_00();
    void sub_006E95A0(int, int);
};

class Class_006E9A10
{
public:
    void sub_006E9A10(int a1, int a2);
    char m_pad00[0x8];
    int m_Field08; // +0x08
};

void Class_006E9A10::sub_006E9A10(int a1, int a2)
{
    int t1;

    t1 = m_Field08;
    ((Object*)a2)->vfunc_00();
    ((Object*)t1)->sub_006E95A0(a1, a2);
}

// ============================================================================
// [VERIFIED] content::LoadInventory::vfunc_03 (0x006E9AE0, 81 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// What it does: LoadInventory's deleting destructor: frees its inventory at +0x08, releases the object at +0x0C, then frees itself when asked.
// ============================================================================
// Same machine code as content::LoadInventory::vfunc_03 (Proto 0x001FD230), which was matched first;
// its addresses and names were swapped for this function's.
// content::LoadInventory::vfunc_03 (Proto 0x006E9AE0, 81 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    virtual void vfunc_00();
    virtual void vfunc_01();
    void sub_006EA020();
    void sub_006E9160();
};

extern "C" char DAT_0073523C[];
extern "C" char DAT_007723EC[];
extern "C" void __cdecl sub_0043CE70(int);
extern "C" void __cdecl sub_006E9810(int);

namespace content {

class LoadInventory
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual LoadInventory* vfunc_03(int a1);
    char m_pad04[0x4];
    int m_Field08; // +0x08
    int m_Field0C; // +0x0C
};

LoadInventory* LoadInventory::vfunc_03(int a1)
{
    int t1, t5;

    t1 = m_Field08;
    *(int*)this = (int)DAT_007723EC;
    if (m_Field08) {
        ((Object*)t1)->sub_006EA020();
        ((Object*)t1)->sub_006E9160();
        sub_0043CE70(t1);
    }
    t5 = m_Field0C;
    if (m_Field0C) {
        ((Object*)t5)->vfunc_01();
    }
    *(int*)this = (int)DAT_0073523C;
    if (a1 & 1) {
        sub_006E9810((int)this);
    }
    return this;
}

}

// [TODO] 0x006E9B40 content::P3DFileHandler::vfunc_04 (809 B)
// ============================================================================
// [VERIFIED] NISStreamDataLoader::vfunc_04 (0x006E9E70, 27 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as GameGroupLoader::vfunc_04 (Proto 0x001FE150), which was matched first;
// its addresses and names were swapped for this function's.
// NISStreamDataLoader::vfunc_04 (Proto 0x006E9E70, 27 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

class NISStreamDataLoader
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04(int a1, int a2, int a3, int a4, int a5);
    virtual void vfunc_05();
    virtual void vfunc_06(int, int, int, int);
    char m_pad04[0xC];
    int m_Field10; // +0x10
};

void NISStreamDataLoader::vfunc_04(int a1, int a2, int a3, int a4, int a5)
{
    vfunc_06(a1, a2, m_Field10, a5);
}

// ============================================================================
// [VERIFIED] content::Stats::vfunc_00 (0x006E9E90, 31 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as core::BaseObject::vfunc_00 (0x00026BB0), which was matched first;
// its addresses and names were swapped for this function's.
// content::Stats::vfunc_00 (0x006E9E90, 31 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_00772404[];
extern "C" void __cdecl sub_0043CE70(int);

namespace content {

class Stats
{
public:
    virtual Stats* vfunc_00(int a1);
};

Stats* Stats::vfunc_00(int a1)
{
    *(int*)this = (int)DAT_00772404;
    if (a1 & 1) {
        sub_0043CE70((int)this);
    }
    return this;
}

}

// ============================================================================
// [VERIFIED] sub_006E9EC0 (0x006E9EC0, 86 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_001FE190 (Proto 0x001FE190), which was matched first;
// its addresses and names were swapped for this function's.
// sub_006E9EC0 (Proto 0x006E9EC0, 86 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int __cdecl sub_0043CE00(int);

class Class_006E9EC0
{
public:
    bool sub_006E9EC0(int a1);
    int m_Field00; // +0x00
    int m_Field04; // +0x04
    int m_Field08; // +0x08
    int m_Field0C; // +0x0C
};

bool Class_006E9EC0::sub_006E9EC0(int a1)
{
    int t1;

    if (a1) {
        t1 = sub_0043CE00(a1 * 8);
        m_Field00 = t1;
        if (!t1) goto L_48;
        m_Field0C = (a1 * 8) + t1;
        m_Field04 = t1;
        m_Field08 = t1;
        return true;
    }
    m_Field00 = 0;
    m_Field08 = 0;
    m_Field0C = 0;
L_48:
    m_Field04 = 0;
    return false;
}

// ============================================================================
// [VERIFIED] sub_006E9F50 (0x006E9F50, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// What it does: Always returns 1.
// ============================================================================
// bin: pc
// va: 0x006E9F50
// what: Always returns 1.
// tool: Claude Opus 5.5 (transplanted from pc:0x006E36C0, nearest by portal/tools/similar.py)
// its addresses and names were swapped for this function's.
// sub_006E9F50
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.


class Class_006E9F50
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual void vfunc_05();
    virtual int sub_006E9F50();
};

int Class_006E9F50::sub_006E9F50()
{
    return 1;
}

// [TODO] 0x006EA020 sub_006EA020 (64 B)
// ============================================================================
// [VERIFIED] sub_006EA060 (0x006EA060, 33 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00240E00 (0x00240E00), which was matched first;
// its addresses and names were swapped for this function's.
// sub_006EA060 (0x006EA060, 33 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    virtual void vfunc_00();
    void sub_006E95A0(int, int);
};

class Class_006EA060
{
public:
    void sub_006EA060(int a1, int a2);
    char m_pad00[0x20];
    int m_Field20; // +0x20
};

void Class_006EA060::sub_006EA060(int a1, int a2)
{
    int t1;

    t1 = m_Field20;
    ((Object*)a1)->vfunc_00();
    ((Object*)t1)->sub_006E95A0(a2, a1);
}

// [TODO] 0x006EA150 sub_006EA150 (36 B)
// ============================================================================
// [VERIFIED] sub_006EA1C0 (0x006EA1C0, 15 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_000D3C80 (0x000D3C80), which was matched first;
// its addresses and names were swapped for this function's.
// sub_006EA1C0 (0x006EA1C0, 15 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __stdcall sub_006E9F60(int, int);

void __stdcall sub_006EA1C0(int a1)
{
    sub_006E9F60(a1, 1);
}

// ============================================================================
// [VERIFIED] sub_006EA1D0 (0x006EA1D0, 39 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G7 /Gd /GR /EHsc /Zp4
// ============================================================================
// bin: pc
// va: 0x006EA1D0
// what: 
// tool: the portal's starter code (no AI)

// sub_006EA1D0 (PC 0x006EA1D0, 39 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int __cdecl sub_006DC000(void);

class Class_006EA1D0
{
public:
    int sub_006EA1D0();
    int sub_006E9F60(int, int);
    char m_pad00[0x4];
    int m_Field04; // +0x04
    int m_Field08; // +0x08
    char m_pad0C[0x4];
    int m_Field10; // +0x10
    int m_Field14; // +0x14
};

int Class_006EA1D0::sub_006EA1D0()
{
    int r_eax;

    r_eax = sub_006DC000();
    r_eax -= m_Field08;
    m_Field14 = 0;
    m_Field10 = r_eax;
    if ((unsigned int)r_eax > (unsigned int)m_Field04) {
        r_eax = sub_006E9F60(2, 0);
    }
    return r_eax;
}

// [TODO] 0x006EA4B0 sub_006EA4B0 (162 B)
// [TODO] 0x006EA570 sub_006EA570 (268 B)
// ============================================================================
// [VERIFIED] sub_006EA790 (0x006EA790, 137 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00241560 (0x00241560), which was matched first;
// its addresses and names were swapped for this function's.
// sub_006EA790 (0x006EA790, 137 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_006EA020();
    void sub_006E9160();
};

extern "C" char DAT_0085CE34[];
extern "C" void __cdecl sub_0043CE70(int);
extern "C" void __cdecl sub_006DF010(int);

class Class_006EA790
{
public:
    void sub_006EA790();
    char m_pad00[0x1];
    bool m_Field01; // +0x01
    char m_pad02[0x1A];
    int m_Field1C; // +0x1C
    int m_Field20; // +0x20
    int m_Field24; // +0x24
    int m_Field28; // +0x28
    int m_Field2C; // +0x2C
    char m_pad30[0x8];
    int m_Field38; // +0x38
    int m_Field3C; // +0x3C
    int m_Field40; // +0x40
};

void Class_006EA790::sub_006EA790()
{
    int t1, t5, t10, t12;

    t1 = m_Field1C;
    if (m_Field1C) {
        ((Object*)t1)->sub_006EA020();
        ((Object*)t1)->sub_006E9160();
        sub_0043CE70(t1);
    }
    t5 = m_Field20;
    if (m_Field20) {
        ((Object*)t5)->sub_006EA020();
        ((Object*)t5)->sub_006E9160();
        sub_0043CE70(t5);
    }
    m_Field01 = true;
    sub_006DF010((int)DAT_0085CE34);
    t10 = m_Field40;
    m_Field38 = m_Field40;
    m_Field3C = t10;
    if (m_Field40) {
        sub_0043CE70(t10);
    }
    t12 = m_Field2C;
    m_Field24 = m_Field2C;
    m_Field28 = t12;
    if (m_Field2C) {
        sub_0043CE70(t12);
    }
    sub_0043CE70((int)this);
}

// [TODO] 0x006EA8F0 sub_006EA8F0 (118 B)
// [TODO] 0x006EA970 sub_006EA970 (100 B)
// [TODO] 0x006EA9E0 sub_006EA9E0 (60 B)
// [TODO] 0x006EAA20 sub_006EAA20 (80 B)
// [TODO] 0x006EAA70 sub_006EAA70 (108 B)
// ============================================================================
// [VERIFIED] sub_006EAAE0 (0x006EAAE0, 43 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G7 /Gd /GR /EHsc /Zp4
// ============================================================================
// bin: pc
// va: 0x006EAAE0
// what: 
// tool: the portal's starter code (no AI)

// sub_006EAAE0 (PC 0x006EAAE0, 43 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field08
{
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual void vfunc_05();
    virtual void vfunc_06(int);
};

class Class_006EAAE0
{
public:
    void sub_006EAAE0(int a1);
    void sub_006EA9E0();
    char m_pad00[0x8];
    Field08* m_Field08; // +0x08
    char m_pad0C[0x1];
    unsigned char m_Field0D; // +0x0D
    char m_pad0E[0xA];
    int m_Field18; // +0x18
};

void Class_006EAAE0::sub_006EAAE0(int a1)
{
    m_Field08->vfunc_06(m_Field18 + a1);
    m_Field18 += a1;
    if (m_Field0D) {
        sub_006EA9E0();
    }
}

// ============================================================================
// [VERIFIED] sub_006EAB10 (0x006EAB10, 71 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G7 /Gd /GR /EHsc /Zp4
// ============================================================================
// bin: pc
// va: 0x006EAB10
// what: 
// tool: the portal's starter code (no AI)

// sub_006EAB10 (PC 0x006EAB10, 71 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field08
{
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04(int, int, int);
};

class Class_006EAB10
{
public:
    bool sub_006EAB10(int a1, int a2, int a3, int a4);
    void sub_006EA9E0();
    void sub_006EAA20(int, int, int);
    char m_pad00[0x8];
    Field08* m_Field08; // +0x08
    char m_pad0C[0xC];
    int m_Field18; // +0x18
};

bool Class_006EAB10::sub_006EAB10(int a1, int a2, int a3, int a4)
{
    m_Field08->vfunc_04(a1, a2 * a3, a4);
    m_Field18 += a2 * a3;
    sub_006EA9E0();
    sub_006EAA20(a1, a2, a3);
    return true;
}

// [TODO] 0x006EAB60 sub_006EAB60 (60 B)
// [TODO] 0x006EABA0 sub_006EABA0 (109 B)
// ============================================================================
// [VERIFIED] content::LoadStream::vfunc_03 (0x006EAC60, 70 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// bin: pc
// va: 0x006EAC60
// what: 
// tool: the portal's starter code (no AI)

// content::LoadStream::vfunc_03 (PC 0x006EAC60, 70 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    virtual void vfunc_00();
    virtual void vfunc_01();
};

extern "C" char DAT_0073523C[];
extern "C" char DAT_0077240C[];
extern "C" void __cdecl sub_006DC500(int);
extern "C" void __cdecl sub_006E9810(int);
extern "C" void __cdecl sub_006EA9E0(void);

namespace content {

class LoadStream
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual LoadStream* vfunc_03(int a1);
    char m_pad04[0x4];
    int m_Field08; // +0x08
    char m_pad0C[0x18];
    int m_Field24; // +0x24
};

LoadStream* LoadStream::vfunc_03(int a1)
{
    int t2, t4;

    *(int*)this = (int)DAT_0077240C;
    sub_006EA9E0();
    t2 = m_Field08;
    if (m_Field08) {
        ((Object*)t2)->vfunc_01();
    }
    t4 = m_Field24;
    if (m_Field24) {
        sub_006DC500(t4);
    }
    *(int*)this = (int)DAT_0073523C;
    if (a1 & 1) {
        sub_006E9810((int)this);
    }
    return this;
}

}

// [TODO] 0x006EACB0 sub_006EACB0 (312 B)
// [TODO] 0x006EADF0 sub_006EADF0 (116 B)
// ============================================================================
// [VERIFIED] sub_006EAEE0 (0x006EAEE0, 103 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G7 /Gd /GR /EHsc /Zp4
// ============================================================================
// bin: pc
// va: 0x006EAEE0
// what: 
// tool: the portal's starter code (no AI)

// sub_006EAEE0 (PC 0x006EAEE0, 103 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0077240C[];

class Class_006EAEE0
{
public:
    Class_006EAEE0* sub_006EAEE0(int a1, int a2, int a3);
    void sub_006EADF0(int);
    int m_Field00; // +0x00
    int m_Field04; // +0x04
    int m_Field08; // +0x08
    bool m_Field0C; // +0x0C
    bool m_Field0D; // +0x0D
    bool m_Field0E; // +0x0E
    bool m_Field0F; // +0x0F
    bool m_Field10; // +0x10
    char m_pad11[0x3];
    int m_Field14; // +0x14
    int m_Field18; // +0x18
    int m_Field1C; // +0x1C
    int m_Field20; // +0x20
    int m_Field24; // +0x24
    int m_Field28; // +0x28
    int m_Field2C; // +0x2C
    int m_Field30; // +0x30
    int m_Field34; // +0x34
    int m_Field38; // +0x38
    int m_Field3C; // +0x3C
    int m_Field40; // +0x40
};

Class_006EAEE0* Class_006EAEE0::sub_006EAEE0(int a1, int a2, int a3)
{
    m_Field0D = false;
    m_Field04 = 0;
    m_Field08 = 0;
    m_Field0C = false;
    m_Field0F = false;
    m_Field10 = false;
    m_Field14 = 0;
    m_Field18 = 0;
    m_Field1C = 0;
    m_Field20 = 0;
    m_Field24 = 0;
    m_Field28 = 0;
    m_Field2C = 0;
    m_Field30 = 0;
    m_Field34 = 0;
    m_Field38 = 0;
    m_Field3C = 0;
    m_Field40 = 0;
    m_Field0E = a3 == 1;
    m_Field00 = (int)DAT_0077240C;
    m_Field0D = *(bool*)(a1 + 272);
    sub_006EADF0(a1);
    return this;
}

// ============================================================================
// [VERIFIED] sub_006EAF50 (0x006EAF50, 69 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G7 /Gd /GR /EHsc /Zp4
// ============================================================================
// bin: pc
// va: 0x006EAF50
// what: 
// tool: the portal's starter code (no AI)

// sub_006EAF50 (PC 0x006EAF50, 69 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field08
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
    virtual void vfunc_23();
    virtual bool vfunc_24();
};

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
    virtual void vfunc_23();
    virtual bool vfunc_24();
};

class Class_006EAF50
{
public:
    bool sub_006EAF50();
    void sub_006EA9E0();
    void sub_006EABA0();
    char m_pad00[0x8];
    Field08* m_Field08; // +0x08
    bool m_Field0C; // +0x0C
    char m_pad0D[0x3];
    unsigned char m_Field10; // +0x10
};

bool Class_006EAF50::sub_006EAF50()
{
    Field08* t1;

    if (m_Field10) {
        t1 = m_Field08;
        m_Field10 = 0;
        if (!((Object*)(int)t1)->vfunc_24()) {
            sub_006EA9E0();
        }
        if (m_Field08->vfunc_24()) {
            m_Field0C = true;
            sub_006EABA0();
            return m_Field0C;
        }
        m_Field0C = false;
    }
    return m_Field0C;
}

// [TODO] 0x006EAFA0 sub_006EAFA0 (168 B)
// [TODO] 0x006EB050 sub_006EB050 (141 B)
// ============================================================================
// [VERIFIED] sub_006EB0E0 (0x006EB0E0, 11 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_001FDB20 (Proto 0x001FDB20), which was matched first;
// its addresses and names were swapped for this function's.
// sub_006EB0E0 (Proto 0x006EB0E0, 11 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field284
{
    virtual void vfunc_00();
    virtual void vfunc_01();
};

class Class_006EB0E0
{
public:
    void sub_006EB0E0();
    char m_pad00[0x284];
    Field284* m_Field284; // +0x284
};

void Class_006EB0E0::sub_006EB0E0()
{
    m_Field284->vfunc_01();
}

// ============================================================================
// [VERIFIED] sub_006EB0F0 (0x006EB0F0, 20 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// bin: pc
// va: 0x006EB0F0
// what: 
// tool: the portal's starter code (no AI)

// sub_006EB0F0 (PC 0x006EB0F0, 20 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_0072F204;

class Class_006EB0F0
{
public:
    void sub_006EB0F0(int a1);
};

void Class_006EB0F0::sub_006EB0F0(int a1)
{
    ((void (__cdecl*)(int, int, int))DAT_0072F204)((int)this, a1, 127);
}

// [TODO] 0x006EB150 sub_006EB150 (242 B)
// [TODO] 0x006EB250 sub_006EB250 (162 B)
// ============================================================================
// [VERIFIED] sub_006EB350 (0x006EB350, 16 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_001FDD90 (Proto 0x001FDD90), which was matched first;
// its addresses and names were swapped for this function's.
// sub_006EB350 (Proto 0x006EB350, 16 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

class Class_006EB350
{
public:
    int sub_006EB350();
    char m_pad00[0x280];
    int m_Field280; // +0x280
};

int Class_006EB350::sub_006EB350()
{
    return *(int*)(((m_Field280 + 8) << 4) + (int)this);
}

// [TODO] 0x006EB370 sub_006EB370 (102 B)
// [TODO] 0x006EB490 sub_006EB490 (28 B)
// ============================================================================
// [VERIFIED] sub_006EB4B0 (0x006EB4B0, 38 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_001FEC60 (Proto 0x001FEC60), which was matched first;
// its addresses and names were swapped for this function's.
// sub_006EB4B0 (Proto 0x006EB4B0, 38 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    virtual void vfunc_00();
    virtual void vfunc_01();
};

class Class_006EB4B0
{
public:
    void sub_006EB4B0(int a1);
    char m_pad00[0x18];
    int m_Field18; // +0x18
};

void Class_006EB4B0::sub_006EB4B0(int a1)
{
    int t2;

    if (a1) {
        ((Object*)a1)->vfunc_00();
    }
    t2 = m_Field18;
    if (m_Field18) {
        ((Object*)t2)->vfunc_01();
    }
    m_Field18 = a1;
}

// ============================================================================
// [VERIFIED] sub_006EB4E0 (0x006EB4E0, 38 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_001FEC90 (Proto 0x001FEC90), which was matched first;
// its addresses and names were swapped for this function's.
// sub_006EB4E0 (Proto 0x006EB4E0, 38 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    virtual void vfunc_00();
    virtual void vfunc_01();
};

class Class_006EB4E0
{
public:
    void sub_006EB4E0(int a1);
    char m_pad00[0x1C];
    int m_Field1C; // +0x1C
};

void Class_006EB4E0::sub_006EB4E0(int a1)
{
    int t2;

    if (a1) {
        ((Object*)a1)->vfunc_00();
    }
    t2 = m_Field1C;
    if (m_Field1C) {
        ((Object*)t2)->vfunc_01();
    }
    m_Field1C = a1;
}

// [TODO] 0x006EB510 sub_006EB510 (110 B)
// ============================================================================
// [VERIFIED] content::LoadRequest::vfunc_03 (0x006EB580, 76 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as content::LoadRequest::vfunc_03 (Proto 0x001FED30), which was matched first;
// its addresses and names were swapped for this function's.
// content::LoadRequest::vfunc_03 (Proto 0x006EB580, 76 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    virtual void vfunc_00();
    virtual void vfunc_01();
};

extern "C" char DAT_0073523C[];
extern "C" char DAT_00772428[];
extern "C" void __cdecl sub_006E9810(int);

namespace content {

class LoadRequest
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual LoadRequest* vfunc_03(int a1);
    char m_pad04[0x14];
    int m_Field18; // +0x18
    int m_Field1C; // +0x1C
    char m_pad20[0x104];
    int m_Field124; // +0x124
};

LoadRequest* LoadRequest::vfunc_03(int a1)
{
    int t1, t3, t5;

    t1 = m_Field18;
    *(int*)this = (int)DAT_00772428;
    if (m_Field18) {
        ((Object*)t1)->vfunc_01();
    }
    t3 = m_Field124;
    if (m_Field124) {
        ((Object*)t3)->vfunc_01();
    }
    t5 = m_Field1C;
    if (m_Field1C) {
        ((Object*)t5)->vfunc_01();
    }
    *(int*)this = (int)DAT_0073523C;
    if (a1 & 1) {
        sub_006E9810((int)this);
    }
    return this;
}

}

// ============================================================================
// [VERIFIED] sub_006EB620 (0x006EB620, 5 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00290C80 (Proto 0x00290C80), which was matched first;
// its addresses and names were swapped for this function's.
// sub_006EB620 (Proto 0x006EB620, 5 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

class Class_006EB620
{
public:
    int sub_006EB620();
    char m_pad00[0x8];
    unsigned short m_Field08; // +0x08
};

int Class_006EB620::sub_006EB620()
{
    return m_Field08;
}

// [TODO] 0x006EB630 sub_006EB630 (98 B)
// ============================================================================
// [VERIFIED] sub_006EB6A0 (0x006EB6A0, 34 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G7 /Gd /GR /EHsc /Zp4
// ============================================================================
// bin: pc
// va: 0x006EB6A0
// what: 
// tool: the portal's starter code (no AI)

// sub_006EB6A0 (PC 0x006EB6A0, 34 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_007F6398;

class Class_006EB6A0
{
public:
    Class_006EB6A0* sub_006EB6A0();
    int m_Field00; // +0x00
    unsigned short m_Field04; // +0x04
    char m_pad06[0x2];
    unsigned short m_Field08; // +0x08
};

Class_006EB6A0* Class_006EB6A0::sub_006EB6A0()
{
    m_Field00 = DAT_007F6398;
    *(unsigned short*)(DAT_007F6398 + -4) += 1;
    m_Field08 = 0;
    m_Field04 = 2;
    return this;
}

// ============================================================================
// [VERIFIED] sub_006EB6D0 (0x006EB6D0, 16 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00291030 (Proto 0x00291030), which was matched first;
// its addresses and names were swapped for this function's.
// sub_006EB6D0 (Proto 0x006EB6D0, 16 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0072FC64[];
extern "C" int DAT_007F6398;

class Class_006EB6D0
{
public:
    int sub_006EB6D0();
    int m_Field00; // +0x00
};

int Class_006EB6D0::sub_006EB6D0()
{
    int r_eax;

    r_eax = m_Field00;
    if (r_eax == DAT_007F6398) {
        r_eax = (int)DAT_0072FC64;
    }
    return r_eax;
}

// ============================================================================
// [VERIFIED] sub_006EB6E0 (0x006EB6E0, 12 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// What it does: Stores a 16-bit number at +0x08.
// ============================================================================
// bin: pc
// va: 0x006EB6E0
// what: Stores a 16-bit number at +0x08.
// tool: Claude Opus 5.5 (transplanted from xb:0x000117E0, nearest by portal/tools/similar.py)
// sub_006EB6E0 (0x006EB6E0, 12 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

class Class_006EB6E0
{
public:
    void sub_006EB6E0(int a1);
    char m_pad00[0x8];
    unsigned short m_Field08; // +0x8
};

void Class_006EB6E0::sub_006EB6E0(int a1)
{
    m_Field08 = (unsigned short)a1;
}

// [TODO] 0x006EB6F0 sub_006EB6F0 (82 B)
// [TODO] 0x006EB7A0 sub_006EB7A0 (83 B)
// [TODO] 0x006EB800 sub_006EB800 (69 B)
// [TODO] 0x006EB850 sub_006EB850 (103 B)
// [TODO] 0x006EB940 sub_006EB940 (104 B)
// ============================================================================
// [VERIFIED] sub_006EB9B0 (0x006EB9B0, 19 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_000E42D0 (0x000E42D0), which was matched first;
// its addresses and names were swapped for this function's.
// sub_006EB9B0 (0x006EB9B0, 19 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __stdcall sub_006EB8C0(int);

class Class_006EB9B0
{
public:
    Class_006EB9B0* sub_006EB9B0(int a1);
};

Class_006EB9B0* Class_006EB9B0::sub_006EB9B0(int a1)
{
    sub_006EB8C0(a1);
    return this;
}

// [TODO] 0x006EBA00 sub_006EBA00 (94 B)
// [TODO] 0x006EBA60 sub_006EBA60 (94 B)
// ============================================================================
// [VERIFIED] sub_006EBBD0 (0x006EBBD0, 15 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// bin: pc
// va: 0x006EBBD0
// what: 
// tool: the portal's starter code (no AI)

// sub_006EBBD0 (PC 0x006EBBD0, 15 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field00
{
    void sub_006EB750();
};

class Class_006EBBD0
{
public:
    void sub_006EBBD0();
    Field00* m_Field00; // +0x00
    unsigned short m_Field04; // +0x04
};

void Class_006EBBD0::sub_006EBBD0()
{
    if (m_Field04 == 2) {
        m_Field00->sub_006EB750();
        return;
    }
}

// [TODO] 0x006EBBE0 sub_006EBBE0 (69 B)
// [TODO] 0x006EBCA0 sub_006EBCA0 (70 B)
// ============================================================================
// [VERIFIED] sub_006EBD00 (0x006EBD00, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_0001E670 (0x0001E670), which was matched first;
// its addresses and names were swapped for this function's.
// sub_006EBD00 (0x006EBD00, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" bool DAT_0085CE68;

bool __cdecl sub_006EBD00(void)
{
    return DAT_0085CE68;
}

// [TODO] 0x006EBD20 sub_006EBD20 (51 B)
// [TODO] 0x006EBD60 sub_006EBD60 (51 B)
// [TODO] 0x006EBDA0 sub_006EBDA0 (62 B)
// ============================================================================
// [VERIFIED] sub_006EBDE0 (0x006EBDE0, 13 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_0007F7F0 (0x0007F7F0), which was matched first;
// its addresses and names were swapped for this function's.
// sub_006EBDE0 (0x006EBDE0, 13 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_007F646C[];
extern "C" void __stdcall sub_006EE870(int);

class Class_006EBDE0
{
public:
    void sub_006EBDE0(int a1);
};

void Class_006EBDE0::sub_006EBDE0(int a1)
{
    a1 = (int)DAT_007F646C;
    sub_006EE870(a1);
}

// ============================================================================
// [VERIFIED] audio::OmHalStream::vfunc_10 (0x006EBDF0, 11 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as audio::OmHalStream::vfunc_10 (0x002D5910), which was matched first;
// its addresses and names were swapped for this function's.
// audio::OmHalStream::vfunc_10 (0x006EBDF0, 11 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_006EB6D0();
};

namespace audio {

class OmHalStream
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
};

void OmHalStream::vfunc_10()
{
    ((Object*)(int)this + 448)->sub_006EB6D0();
}

}

// [TODO] 0x006EBE00 audio::OmHalStream::vfunc_07 (177 B)
// [TODO] 0x006EBEC0 audio::OmHalStream::vfunc_06 (219 B)
// ============================================================================
// [VERIFIED] audio::OmHalStream::vfunc_08 (0x006EBFA0, 36 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as audio::OmHalStream::vfunc_08 (0x002D5B00), which was matched first;
// its addresses and names were swapped for this function's.
// audio::OmHalStream::vfunc_08 (0x006EBFA0, 36 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

namespace audio {

class OmHalStream
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
    virtual bool vfunc_08(int a1);
    char m_pad04[0x4];
    int m_Field08; // +0x08
    char m_pad0C[0x1AC];
    int m_Field1B8; // +0x1B8
};

bool OmHalStream::vfunc_08(int a1)
{
    *(int*)a1 = m_Field1B8;
    m_Field08 -= m_Field1B8;
    m_Field1B8 = 0;
    return true;
}

}

// ============================================================================
// [VERIFIED] audio::OmHalStream::vfunc_09 (0x006EBFD0, 17 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as audio::OmHalStream::vfunc_09 (0x002D5B30), which was matched first;
// its addresses and names were swapped for this function's.
// audio::OmHalStream::vfunc_09 (0x006EBFD0, 17 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

namespace audio {

class OmHalStream
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
    virtual int vfunc_09(int a1);
};

int OmHalStream::vfunc_09(int a1)
{
    return (a1 << 4) + (int)this + 184;
}

}

// [TODO] 0x006EBFF0 audio::OmHalStream::vfunc_05 (46 B)
// ============================================================================
// [VERIFIED] audio::OmHalStream::vfunc_03 (0x006EC020, 13 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// bin: pc
// va: 0x006EC020
// what: 
// tool: the portal's starter code (no AI)

// audio::OmHalStream::vfunc_03 (PC 0x006EC020, 13 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int __cdecl sub_006F13A0(int);

namespace audio {

class OmHalStream
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual int vfunc_03();
};

int OmHalStream::vfunc_03()
{
    return sub_006F13A0((int)this + 12);
}

}

// [TODO] 0x006EC030 sub_006EC030 (227 B)
// [TODO] 0x006EC120 sub_006EC120 (185 B)
// [TODO] 0x006EC1E0 sub_006EC1E0 (78 B)
// [TODO] 0x006EC230 sub_006EC230 (76 B)
// [TODO] 0x006EC280 sub_006EC280 (85 B)
// [TODO] 0x006EC2E0 sub_006EC2E0 (361 B)
// ============================================================================
// [VERIFIED] sub_006EC450 (0x006EC450, 24 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_002D5FC0 (0x002D5FC0), which was matched first;
// its addresses and names were swapped for this function's.
// sub_006EC450 (0x006EC450, 24 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __cdecl sub_006EE9B0(void);

int __cdecl sub_006EC450(int a1, int a2)
{
    sub_006EE9B0();
    *(int*)a1 = *(int*)a2;
    *(int*)(a1 + 4) = *(int*)(a2 + 4);
    return a1;
}

// [TODO] 0x006EC470 sub_006EC470 (122 B)
// ============================================================================
// [VERIFIED] sub_006EC4F0 (0x006EC4F0, 70 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_002D6060 (0x002D6060), which was matched first;
// its addresses and names were swapped for this function's.
// sub_006EC4F0 (0x006EC4F0, 70 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" bool __cdecl sub_006EC120(int, int);
extern "C" bool __cdecl sub_006EC280(int, int);
extern "C" bool __cdecl sub_006F33D0(int, int);

class Class_006EC4F0
{
public:
    bool sub_006EC4F0(int a1);
    char m_pad00[0xC];
    int m_Field0C; // +0x0C
};

bool Class_006EC4F0::sub_006EC4F0(int a1)
{
    if (sub_006EC280(a1, (int)this)) {
        if (!sub_006F33D0(a1, (int)(&m_Field0C))) goto L_3F;
        if (!sub_006EC120(a1, (int)this + 8)) goto L_3F;
        return true;
    }
L_3F:
    return false;
}

// [TODO] 0x006EC540 sub_006EC540 (175 B)
// ============================================================================
// [VERIFIED] audio::OmHalStream::vfunc_12 (0x006EC5F0, 40 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as audio::OmHalStream::vfunc_12 (0x002D6170), which was matched first;
// its addresses and names were swapped for this function's.
// audio::OmHalStream::vfunc_12 (0x006EC5F0, 40 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field1C0
{
    void sub_006EBBD0();
};

extern "C" char DAT_007724CC[];
extern "C" char DAT_007F646C[];
extern "C" void __cdecl sub_006EE890(int, int);

namespace audio {

class OmHalStream
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
    char m_pad04[0x1BC];
    Field1C0 m_Field1C0; // +0x1C0
};

void OmHalStream::vfunc_12()
{
    if (this) {
        *(int*)this = (int)DAT_007724CC;
        m_Field1C0.sub_006EBBD0();
        sub_006EE890((int)DAT_007F646C, (int)this);
    }
}

}

// ============================================================================
// [VERIFIED] sub_006EC630 (0x006EC630, 19 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00081980 (0x00081980), which was matched first;
// its addresses and names were swapped for this function's.
// sub_006EC630 (0x006EC630, 19 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_007F6474[];
extern "C" void __cdecl sub_006EE890(int, int);

void __cdecl sub_006EC630(int a1)
{
    sub_006EE890((int)DAT_007F6474, a1);
}

// ============================================================================
// [VERIFIED] sub_006EC650 (0x006EC650, 25 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00291400 (Proto 0x00291400), which was matched first;
// its addresses and names were swapped for this function's.
// sub_006EC650 (Proto 0x006EC650, 25 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_00772544[];

class Class_006EC650
{
public:
    Class_006EC650* sub_006EC650(int a1);
    int m_Field00; // +0x00
    int m_Field04; // +0x04
    int m_Field08; // +0x08
};

Class_006EC650* Class_006EC650::sub_006EC650(int a1)
{
    m_Field04 = 0;
    m_Field00 = (int)DAT_00772544;
    m_Field08 = a1;
    return this;
}

// ============================================================================
// [VERIFIED] om::EntityLoader::vfunc_03 (0x006EC670, 36 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as SoundManager::SoundPlayerHandle::vfunc_00 (0x00077F00), which was matched first;
// its addresses and names were swapped for this function's.
// om::EntityLoader::vfunc_03 (0x006EC670, 36 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0073523C[];
extern "C" char DAT_007F6474[];
extern "C" void __cdecl sub_006EE890(int, int);

namespace om {

class EntityLoader
{
public:
    virtual EntityLoader* vfunc_03(int a1);
};

EntityLoader* EntityLoader::vfunc_03(int a1)
{
    *(int*)this = (int)DAT_0073523C;
    if (a1 & 1) {
        sub_006EE890((int)DAT_007F6474, (int)this);
    }
    return this;
}

}

// [TODO] 0x006EC6A0 om::EntityLoader::vfunc_04 (245 B)
// ============================================================================
// [VERIFIED] sub_006EC7B0 (0x006EC7B0, 19 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00081980 (0x00081980), which was matched first;
// its addresses and names were swapped for this function's.
// sub_006EC7B0 (0x006EC7B0, 19 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_007F64D8[];
extern "C" void __cdecl sub_006EE890(int, int);

void __cdecl sub_006EC7B0(int a1)
{
    sub_006EE890((int)DAT_007F64D8, a1);
}

// [TODO] 0x006EC7D0 sub_006EC7D0 (137 B)
// [TODO] 0x006EC860 om::TRbTree<om::MetaTypeBase, 4>::Comp<om::MetaTypeBase, 4, om::String>::vfunc_00 (45 B)
// [TODO] 0x006EC890 om::MetaType<GlobalVehicleSound>::vfunc_01 (199 B)
// [TODO] 0x006EC960 om::MetaType<GlobalVehicleSound>::vfunc_02 (199 B)
// [TODO] 0x006ECA30 sub_006ECA30 (88 B)
// [TODO] 0x006ECA90 sub_006ECA90 (46 B)
// ============================================================================
// [VERIFIED] sub_006ECB50 (0x006ECB50, 48 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_002CEF70 (0x002CEF70), which was matched first;
// its addresses and names were swapped for this function's.
// sub_006ECB50 (0x006ECB50, 48 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field14
{
    void sub_006ECA90();
};

struct Object
{
    void sub_006F2A40(int);
};

extern "C" char DAT_00772564[];
extern "C" Object DAT_0085CE74;

class Class_006ECB50
{
public:
    void sub_006ECB50();
    int m_Field00; // +0x00
    int m_Field04; // +0x04
    char m_pad08[0xC];
    Field14 m_Field14; // +0x14
    char m_pad15[0x13];
    Field14 m_Field28; // +0x28
    char m_pad29[0x13];
    Field14 m_Field3C; // +0x3C
};

void Class_006ECB50::sub_006ECB50()
{
    m_Field00 = (int)DAT_00772564;
    DAT_0085CE74.sub_006F2A40((int)(&m_Field04));
    m_Field14.sub_006ECA90();
    m_Field3C.sub_006ECA90();
    m_Field28.sub_006ECA90();
}

// ============================================================================
// [VERIFIED] om::MetaTypeBase::vfunc_00 (0x006ECB80, 74 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// What it does: om::MetaTypeBase's deleting destructor: destroys the object, frees its memory when asked (flag bit 0), and returns it.
// ============================================================================
// Same machine code as om::MetaTypeBase::vfunc_00 (0x002CEFA0), which was matched first;
// its addresses and names were swapped for this function's.
// om::MetaTypeBase::vfunc_00 (0x006ECB80, 74 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field14
{
    void sub_006ECA90();
};

struct Object
{
    void sub_006F2A40(int);
};

extern "C" char DAT_00772564[];
extern "C" char DAT_007F64D8[];
extern "C" Object DAT_0085CE74;
extern "C" void __cdecl sub_006EE890(int, int);

namespace om {

class MetaTypeBase
{
public:
    virtual MetaTypeBase* vfunc_00(int a1);
    int m_Field04; // +0x04
    char m_pad08[0xC];
    Field14 m_Field14; // +0x14
    char m_pad15[0x13];
    Field14 m_Field28; // +0x28
    char m_pad29[0x13];
    Field14 m_Field3C; // +0x3C
};

MetaTypeBase* MetaTypeBase::vfunc_00(int a1)
{
    *(int*)this = (int)DAT_00772564;
    DAT_0085CE74.sub_006F2A40((int)(&m_Field04));
    m_Field14.sub_006ECA90();
    m_Field3C.sub_006ECA90();
    m_Field28.sub_006ECA90();
    if (a1 & 1) {
        sub_006EE890((int)DAT_007F64D8, (int)this);
    }
    return this;
}

}

// [TODO] 0x006ECC20 sub_006ECC20 (133 B)
// ============================================================================
// [VERIFIED] GlobalVehicleSound::vfunc_00 (0x006ECCB0, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G7 /Gd /GR /EHsc /Zp4
// ============================================================================
// bin: pc
// va: 0x006ECCB0
// what: 
// tool: the portal's starter code (no AI)

// GlobalVehicleSound::vfunc_00 (PC 0x006ECCB0, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

class GlobalVehicleSound
{
public:
    virtual void vfunc_00();
    char m_pad04[0x1C];
    unsigned short m_Field20; // +0x20
};

void GlobalVehicleSound::vfunc_00()
{
    m_Field20 += 1;
}

// [TODO] 0x006ECCC0 GlobalVehicleSound::vfunc_01 (26 B)
// ============================================================================
// [VERIFIED] GlobalVehicleSound::vfunc_02 (0x006ECCE0, 5 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as GlobalVehicleSound::vfunc_02 (0x002CF100), which was matched first;
// its addresses and names were swapped for this function's.
// GlobalVehicleSound::vfunc_02 (0x006ECCE0, 5 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

class GlobalVehicleSound
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual int vfunc_02();
    char m_pad04[0x1C];
    short m_Field20; // +0x20
};

int GlobalVehicleSound::vfunc_02()
{
    return m_Field20;
}

// ============================================================================
// [VERIFIED] GlobalVehicleSound::vfunc_05 (0x006ECCF0, 32 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as GlobalVehicleSound::vfunc_05 (0x002CF110), which was matched first;
// its addresses and names were swapped for this function's.
// GlobalVehicleSound::vfunc_05 (0x006ECCF0, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    virtual void vfunc_00();
    virtual void vfunc_01(int, int);
    virtual int vfunc_02();
};

class GlobalVehicleSound
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual void vfunc_05(int a1);
    virtual void vfunc_06();
    virtual void vfunc_07();
    virtual void vfunc_08();
    virtual void vfunc_09();
    virtual void vfunc_10();
    virtual void vfunc_11();
    virtual int vfunc_12();
};

void GlobalVehicleSound::vfunc_05(int a1)
{
    ((Object*)((Object*)vfunc_12())->vfunc_02())->vfunc_01(a1, (int)this);
}

// ============================================================================
// [VERIFIED] GlobalVehicleSound::vfunc_07 (0x006ECD10, 32 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as GlobalVehicleSound::vfunc_07 (0x002CF130), which was matched first;
// its addresses and names were swapped for this function's.
// GlobalVehicleSound::vfunc_07 (0x006ECD10, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual int vfunc_02();
};

struct Object2
{
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02(int, int);
};

class GlobalVehicleSound
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual void vfunc_05();
    virtual void vfunc_06();
    virtual void vfunc_07(int a1);
    virtual void vfunc_08();
    virtual void vfunc_09();
    virtual void vfunc_10();
    virtual void vfunc_11();
    virtual int vfunc_12();
};

void GlobalVehicleSound::vfunc_07(int a1)
{
    ((Object2*)((Object*)vfunc_12())->vfunc_02())->vfunc_02(a1, (int)this);
}

// ============================================================================
// [VERIFIED] sub_006ECD30 (0x006ECD30, 71 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00292A70 (Proto 0x00292A70), which was matched first;
// its addresses and names were swapped for this function's.
// sub_006ECD30 (Proto 0x006ECD30, 71 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" bool __cdecl sub_006F33D0(int, int);

int __cdecl sub_006ECD30(int a1, int a2)
{
    if (sub_006F33D0(a1, a2)) {
        if (!sub_006F33D0(a1, a2 + 4)) goto L_42;
        if (!sub_006F33D0(a1, a2 + 8)) goto L_42;
        return 1;
    }
L_42:
    return 0;
}

// [TODO] 0x006ECE00 GlobalVehicleSound::vfunc_08 (488 B)
// [TODO] 0x006ECFF0 sub_006ECFF0 (115 B)
// [TODO] 0x006ED070 om::TRbTree<om::EntityTypeBase, 28>::Comp<om::EntityTypeBase, 28, unsigned int>::vfunc_00 (35 B)
// ============================================================================
// [VERIFIED] sub_006ED0C0 (0x006ED0C0, 31 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_002CF4E0 (0x002CF4E0), which was matched first;
// its addresses and names were swapped for this function's.
// sub_006ED0C0 (0x006ED0C0, 31 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_006F2A40(int);
};

extern "C" char DAT_0073523C[];
extern "C" char DAT_007725C0[];
extern "C" Object DAT_0085CE88;

class Class_006ED0C0
{
public:
    void sub_006ED0C0();
    int m_Field00; // +0x00
    int m_Field04; // +0x04
};

void Class_006ED0C0::sub_006ED0C0()
{
    m_Field00 = (int)DAT_007725C0;
    DAT_0085CE88.sub_006F2A40((int)(&m_Field04));
    m_Field00 = (int)DAT_0073523C;
}

// [TODO] 0x006ED250 sub_006ED250 (175 B)
// [TODO] 0x006ED300 om::TRbTree<om::Entity, 4>::Comp<om::Entity, 4, om::Name<om::CaseSensitive64BitKey>>::vfunc_00 (72 B)
// ============================================================================
// [VERIFIED] om::EntityTypeBase::vfunc_00 (0x006ED3B0, 45 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// What it does: om::EntityTypeBase's deleting destructor: destroys the object, frees its memory when asked (flag bit 0), and returns it.
// ============================================================================
// Same machine code as om::EntityTypeBase::vfunc_00 (0x002CF7D0), which was matched first;
// its addresses and names were swapped for this function's.
// om::EntityTypeBase::vfunc_00 (0x006ED3B0, 45 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_006F2A40(int);
};

extern "C" char DAT_007725AC[];
extern "C" Object DAT_0085CE9C;
extern "C" void __cdecl sub_0043CE70(int);

namespace om {

class EntityTypeBase
{
public:
    virtual EntityTypeBase* vfunc_00(int a1);
    char m_pad04[0x18];
    int m_Field1C; // +0x1C
};

EntityTypeBase* EntityTypeBase::vfunc_00(int a1)
{
    *(int*)this = (int)DAT_007725AC;
    DAT_0085CE9C.sub_006F2A40((int)(&m_Field1C));
    if (a1 & 1) {
        sub_0043CE70((int)this);
    }
    return this;
}

}

// [TODO] 0x006ED3E0 sub_006ED3E0 (89 B)
// ============================================================================
// [VERIFIED] om::Entity::vfunc_03 (0x006ED440, 51 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// What it does: om::Entity's deleting destructor: destroys the object, frees its memory when asked (flag bit 0), and returns it.
// ============================================================================
// Same machine code as om::Entity::vfunc_03 (0x002CF860), which was matched first;
// its addresses and names were swapped for this function's.
// om::Entity::vfunc_03 (0x006ED440, 51 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_006F2A40(int);
};

extern "C" char DAT_0073523C[];
extern "C" char DAT_007725C0[];
extern "C" Object DAT_0085CE88;
extern "C" void __cdecl sub_0043CE70(int);

namespace om {

class Entity
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual Entity* vfunc_03(int a1);
    int m_Field04; // +0x04
};

Entity* Entity::vfunc_03(int a1)
{
    *(int*)this = (int)DAT_007725C0;
    DAT_0085CE88.sub_006F2A40((int)(&m_Field04));
    *(int*)this = (int)DAT_0073523C;
    if (a1 & 1) {
        sub_0043CE70((int)this);
    }
    return this;
}

}

// [TODO] 0x006ED490 GlobalVehicleSound::vfunc_04 (109 B)
// [TODO] 0x006ED500 sub_006ED500 (75 B)
// ============================================================================
// [VERIFIED] audio::Sequence::vfunc_12 (0x006ED590, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as core::MemoryAllocatorMalloc::vfunc_12 (0x0028D100), which was matched first;
// its addresses and names were swapped for this function's.
// audio::Sequence::vfunc_12 (0x006ED590, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_00811D78;

namespace audio {

class Sequence
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
    virtual int vfunc_12();
};

int Sequence::vfunc_12()
{
    return DAT_00811D78;
}

}

// ============================================================================
// [VERIFIED] sub_006ED5A0 (0x006ED5A0, 8 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_002CFB40 (0x002CFB40), which was matched first;
// its addresses and names were swapped for this function's.
// sub_006ED5A0 (0x006ED5A0, 8 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_006F2450();
};

class Class_006ED5A0
{
public:
    void sub_006ED5A0();
};

void Class_006ED5A0::sub_006ED5A0()
{
    ((Object*)(int)this + 68)->sub_006F2450();
}

// [TODO] 0x006ED5B0 sub_006ED5B0 (16 B)
// [TODO] 0x006ED5C0 sub_006ED5C0 (102 B)
// [TODO] 0x006ED630 sub_006ED630 (44 B)
// [TODO] 0x006ED660 om::TRbTree<audio::SeqTrack, 0>::Comp<audio::SeqTrack, 0, om::Name<om::CaseSensitive32BitKey>>::vfunc_00 (29 B)
// [TODO] 0x006ED680 om::TRbTree<audio::SeqBuss, 0>::Comp<audio::SeqBuss, 0, om::Name<om::CaseSensitive32BitKey>>::vfunc_00 (29 B)
// [TODO] 0x006ED6A0 sub_006ED6A0 (62 B)
// ============================================================================
// [VERIFIED] audio::Sequence::vfunc_05 (0x006ED6E0, 32 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as audio::Sequence::vfunc_05 (0x002CFC80), which was matched first;
// its addresses and names were swapped for this function's.
// audio::Sequence::vfunc_05 (0x006ED6E0, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field44
{
    void sub_006ED630();
};

extern "C" void __cdecl sub_006ED6A0(void);

namespace audio {

class Sequence
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual void vfunc_05(int a1);
    virtual void vfunc_06(int);
    char m_pad04[0x40];
    Field44 m_Field44; // +0x44
};

void Sequence::vfunc_05(int a1)
{
    sub_006ED6A0();
    m_Field44.sub_006ED630();
    vfunc_06(a1);
}

}

// [TODO] 0x006ED700 sub_006ED700 (273 B)
// ============================================================================
// [VERIFIED] sub_006ED820 (0x006ED820, 98 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_002CFDC0 (0x002CFDC0), which was matched first;
// its addresses and names were swapped for this function's.
// sub_006ED820 (0x006ED820, 98 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field44
{
    int sub_006F2510();
};

struct Object
{
    int sub_006F2450();
    int sub_006F2470(int);
};

extern "C" bool __cdecl sub_006ECBD0(int, int);
extern "C" int __cdecl sub_006EE9B0(void);
extern "C" bool __cdecl sub_006F33F0(int, int);

class Class_006ED820
{
public:
    bool sub_006ED820(int a1);
    char m_pad00[0x44];
    Field44 m_Field44; // +0x44
};

bool Class_006ED820::sub_006ED820(int a1)
{
    int r_edi, r_esi;
    bool t2;

    r_edi = (int)(&m_Field44);
    t2 = sub_006F33F0(a1, m_Field44.sub_006F2510());
    if (!t2) {
        return t2;
    }
    r_esi = ((Object*)r_edi)->sub_006F2450();
    if (r_esi) {
        do {
            if (!sub_006ECBD0(a1, sub_006EE9B0())) goto L_5A;
            r_esi = ((Object*)r_edi)->sub_006F2470(r_esi);
        } while (r_esi);
    }
    return true;
L_5A:
    return false;
}

// [TODO] 0x006ED890 sub_006ED890 (107 B)
// [TODO] 0x006ED900 audio::Sequence::vfunc_03 (96 B)
// ============================================================================
// [VERIFIED] audio::Sequence::vfunc_07 (0x006ED960, 64 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as audio::Sequence::vfunc_09 (Proto 0x002947D0), which was matched first;
// its addresses and names were swapped for this function's.
// audio::Sequence::vfunc_07 (Proto 0x006ED960, 64 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" bool __cdecl sub_006F33F0(int, int);

namespace audio {

class Sequence
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual void vfunc_05();
    virtual void vfunc_06();
    virtual int vfunc_07(int a1);
    bool sub_006ED5C0(int);
    bool sub_006ED820(int);
};

int Sequence::vfunc_07(int a1)
{
    if (sub_006F33F0(a1, 1)) {
        if (!sub_006ED820(a1)) goto L_39;
        if (!sub_006ED5C0(a1)) goto L_39;
        return 1;
    }
L_39:
    return 0;
}

}

// [TODO] 0x006ED9A0 sub_006ED9A0 (143 B)
// [TODO] 0x006EDA30 audio::Sequence::vfunc_06 (110 B)
// ============================================================================
// [VERIFIED] sub_006EDCB0 (0x006EDCB0, 18 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00293BF0 (Proto 0x00293BF0), which was matched first;
// its addresses and names were swapped for this function's.
// sub_006EDCB0 (Proto 0x006EDCB0, 18 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

class Class_006EDCB0
{
public:
    Class_006EDCB0* sub_006EDCB0(int a1, bool a2);
    int m_Field00; // +0x00
    bool m_Field04; // +0x04
};

Class_006EDCB0* Class_006EDCB0::sub_006EDCB0(int a1, bool a2)
{
    m_Field00 = a1;
    m_Field04 = a2;
    return this;
}

// [TODO] 0x006EDCD0 sub_006EDCD0 (36 B)
// [TODO] 0x006EDD00 sub_006EDD00 (64 B)
// [TODO] 0x006EDD40 sub_006EDD40 (133 B)
// [TODO] 0x006EDDD0 sub_006EDDD0 (22 B)
// [TODO] 0x006EDDF0 sub_006EDDF0 (27 B)
// [TODO] 0x006EDE10 sub_006EDE10 (91 B)
// ============================================================================
// [VERIFIED] om::ContentStream::vfunc_00 (0x006EDE70, 45 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// What it does: om::ContentStream's deleting destructor: destroys the object, frees its memory when asked (flag bit 0), and returns it.
// ============================================================================
// Same machine code as om::ContentStream::vfunc_00 (Proto 0x00293E50), which was matched first;
// its addresses and names were swapped for this function's.
// om::ContentStream::vfunc_00 (Proto 0x006EDE70, 45 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    virtual void vfunc_00();
    virtual void vfunc_01();
};

extern "C" char DAT_0073C2A8[];
extern "C" char DAT_00772678[];
extern "C" void __cdecl sub_0043CE70(int);

namespace om {

class ContentStream
{
public:
    virtual ContentStream* vfunc_00(int a1);
    char m_pad04[0x1C];
    int m_Field20; // +0x20
};

ContentStream* ContentStream::vfunc_00(int a1)
{
    int t1;

    t1 = m_Field20;
    *(int*)this = (int)DAT_00772678;
    ((Object*)t1)->vfunc_01();
    *(int*)this = (int)DAT_0073C2A8;
    if (a1 & 1) {
        sub_0043CE70((int)this);
    }
    return this;
}

}

// ============================================================================
// [VERIFIED] sub_006EDEF0 (0x006EDEF0, 81 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00293ED0 (Proto 0x00293ED0), which was matched first;
// its addresses and names were swapped for this function's.
// sub_006EDEF0 (Proto 0x006EDEF0, 81 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0077269C[];
extern "C" char sub_006EDB80[];
extern "C" char sub_006EDBD0[];
extern "C" char sub_006EDC20[];
extern "C" char sub_006EDC40[];
extern "C" char sub_006EDC60[];
extern "C" char sub_006EDC80[];

class Class_006EDEF0
{
public:
    Class_006EDEF0* sub_006EDEF0(int a1, int a2, bool a3);
    int m_Field00; // +0x00
    int m_Field04; // +0x04
    int m_Field08; // +0x08
    int m_Field0C; // +0x0C
    int m_Field10; // +0x10
    int m_Field14; // +0x14
    int m_Field18; // +0x18
    bool m_Field1C; // +0x1C
    char m_pad1D[0x3];
    int m_Field20; // +0x20
    int m_Field24; // +0x24
    int m_Field28; // +0x28
    bool m_Field2C; // +0x2C
};

Class_006EDEF0* Class_006EDEF0::sub_006EDEF0(int a1, int a2, bool a3)
{
    m_Field20 = a2;
    m_Field04 = (int)sub_006EDB80;
    m_Field08 = (int)sub_006EDBD0;
    m_Field0C = (int)sub_006EDC20;
    m_Field10 = (int)sub_006EDC40;
    m_Field14 = (int)sub_006EDC60;
    m_Field18 = (int)sub_006EDC80;
    m_Field1C = false;
    m_Field00 = (int)DAT_0077269C;
    m_Field24 = a1;
    m_Field28 = a1;
    m_Field2C = a3;
    return this;
}

// ============================================================================
// [VERIFIED] sub_006EDF50 (0x006EDF50, 13 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_0007F7F0 (0x0007F7F0), which was matched first;
// its addresses and names were swapped for this function's.
// sub_006EDF50 (0x006EDF50, 13 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_007F680C[];
extern "C" void __stdcall sub_006EE870(int);

class Class_006EDF50
{
public:
    void sub_006EDF50(int a1);
};

void Class_006EDF50::sub_006EDF50(int a1)
{
    a1 = (int)DAT_007F680C;
    sub_006EE870(a1);
}

// ============================================================================
// [VERIFIED] sub_006EDF60 (0x006EDF60, 19 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00081980 (0x00081980), which was matched first;
// its addresses and names were swapped for this function's.
// sub_006EDF60 (0x006EDF60, 19 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_007F680C[];
extern "C" void __cdecl sub_006EE890(int, int);

void __cdecl sub_006EDF60(int a1)
{
    sub_006EE890((int)DAT_007F680C, a1);
}

// ============================================================================
// [VERIFIED] sub_006EDF80 (0x006EDF80, 13 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_0007F7F0 (0x0007F7F0), which was matched first;
// its addresses and names were swapped for this function's.
// sub_006EDF80 (0x006EDF80, 13 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_007F6814[];
extern "C" void __stdcall sub_006EE870(int);

class Class_006EDF80
{
public:
    void sub_006EDF80(int a1);
};

void Class_006EDF80::sub_006EDF80(int a1)
{
    a1 = (int)DAT_007F6814;
    sub_006EE870(a1);
}

// ============================================================================
// [VERIFIED] sub_006EDFA0 (0x006EDFA0, 19 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00081980 (0x00081980), which was matched first;
// its addresses and names were swapped for this function's.
// sub_006EDFA0 (0x006EDFA0, 19 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_007F681C[];
extern "C" void __cdecl sub_006EE890(int, int);

void __cdecl sub_006EDFA0(int a1)
{
    sub_006EE890((int)DAT_007F681C, a1);
}

// ============================================================================
// [VERIFIED] sub_006EDFC0 (0x006EDFC0, 13 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_0007F7F0 (0x0007F7F0), which was matched first;
// its addresses and names were swapped for this function's.
// sub_006EDFC0 (0x006EDFC0, 13 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_007F6824[];
extern "C" void __stdcall sub_006EE870(int);

class Class_006EDFC0
{
public:
    void sub_006EDFC0(int a1);
};

void Class_006EDFC0::sub_006EDFC0(int a1)
{
    a1 = (int)DAT_007F6824;
    sub_006EE870(a1);
}

// ============================================================================
// [VERIFIED] sub_006EDFD0 (0x006EDFD0, 19 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00081980 (0x00081980), which was matched first;
// its addresses and names were swapped for this function's.
// sub_006EDFD0 (0x006EDFD0, 19 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_007F6824[];
extern "C" void __cdecl sub_006EE890(int, int);

void __cdecl sub_006EDFD0(int a1)
{
    sub_006EE890((int)DAT_007F6824, a1);
}

// ============================================================================
// [VERIFIED] audio::MixerMix::vfunc_00 (0x006EDFF0, 5 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G7 /Gd /GR /EHsc /Zp4
// ============================================================================
// bin: pc
// va: 0x006EDFF0
// what: 
// tool: the portal's starter code (no AI)

// audio::MixerMix::vfunc_00 (PC 0x006EDFF0, 5 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

namespace audio {

class MixerMix
{
public:
    virtual void vfunc_00();
    char m_pad04[0x44];
    int m_Field48; // +0x48
};

void MixerMix::vfunc_00()
{
    m_Field48 += 1;
}

}

// ============================================================================
// [VERIFIED] audio::MixerMix::vfunc_01 (0x006EE000, 23 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G7 /Gd /GR /EHsc /Zp4
// ============================================================================
// bin: pc
// va: 0x006EE000
// what: 
// tool: the portal's starter code (no AI)

// audio::MixerMix::vfunc_01 (PC 0x006EE000, 23 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

namespace audio {

class MixerMix
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
};

void MixerMix::vfunc_01()
{
    int r_eax, r_ecx;

    r_ecx = (int)this;
    r_eax = *(int*)(r_ecx + 72);
    if (r_eax == 1) {
        r_eax = *(int*)r_ecx;
        ((void (__stdcall*)(int))*(int*)(r_eax + 12))(1);
        return;
    }
    r_eax += -1;
    *(int*)(r_ecx + 72) = r_eax;
}

}

// ============================================================================
// [VERIFIED] sub_006EE040 (0x006EE040, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_0001E5D0 (0x0001E5D0), which was matched first;
// its addresses and names were swapped for this function's.
// sub_006EE040 (0x006EE040, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_0085CEB0;

int __cdecl sub_006EE040(void)
{
    return DAT_0085CEB0;
}

// ============================================================================
// [VERIFIED] sub_006EE050 (0x006EE050, 5 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G7 /Gd /GR /EHsc /Zp4
// ============================================================================
// bin: pc
// va: 0x006EE050
// what: 
// tool: the portal's starter code (no AI)

// sub_006EE050 (PC 0x006EE050, 5 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

class Class_006EE050
{
public:
    void sub_006EE050();
    char m_pad00[0x28];
    int m_Field28; // +0x28
};

void Class_006EE050::sub_006EE050()
{
    m_Field28 += 1;
}

// ============================================================================
// [VERIFIED] sub_006EE060 (0x006EE060, 15 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G7 /Gd /GR /EHsc /Zp4
// ============================================================================
// bin: pc
// va: 0x006EE060
// what: 
// tool: the portal's starter code (no AI)

// sub_006EE060 (PC 0x006EE060, 15 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

class Class_006EE060
{
public:
    int sub_006EE060();
    char m_pad00[0x20];
    int m_Field20; // +0x20
    char m_pad24[0x18];
    int m_Field3C; // +0x3C
};

int Class_006EE060::sub_006EE060()
{
    m_Field3C += 1;
    *(int*)(m_Field20 + 72) += 1;
    return 1;
}

// ============================================================================
// [VERIFIED] sub_006EE070 (0x006EE070, 13 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G7 /Gd /GR /EHsc /Zp4
// ============================================================================
// bin: pc
// va: 0x006EE070
// what: 
// tool: the portal's starter code (no AI)

// sub_006EE070 (PC 0x006EE070, 13 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.
// Note: eax is not known here (left as 0).

class Class_006EE070
{
public:
    int sub_006EE070();
    char m_pad00[0x20];
    int m_Field20; // +0x20
    char m_pad24[0x18];
    int m_Field3C; // +0x3C
};

int Class_006EE070::sub_006EE070()
{
    m_Field3C += 0 | -1;
    *(int*)(m_Field20 + 72) += 0 | -1;
    return 0 | -1;
}

// ============================================================================
// [VERIFIED] sub_006EE080 (0x006EE080, 5 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G7 /Gd /GR /EHsc /Zp4
// ============================================================================
// bin: pc
// va: 0x006EE080
// what: 
// tool: the portal's starter code (no AI)

// sub_006EE080 (PC 0x006EE080, 5 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

class Class_006EE080
{
public:
    void sub_006EE080();
    char m_pad00[0x40];
    int m_Field40; // +0x40
};

void Class_006EE080::sub_006EE080()
{
    m_Field40 += 1;
}

// ============================================================================
// [VERIFIED] sub_006EE090 (0x006EE090, 5 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G7 /Gd /GR /EHsc /Zp4
// ============================================================================
// bin: pc
// va: 0x006EE090
// what: 
// tool: the portal's starter code (no AI)

// sub_006EE090 (PC 0x006EE090, 5 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

class Class_006EE090
{
public:
    void sub_006EE090();
    char m_pad00[0x40];
    int m_Field40; // +0x40
};

void Class_006EE090::sub_006EE090()
{
    m_Field40 += -1;
}

// [TODO] 0x006EE0A0 sub_006EE0A0 (115 B)
// [TODO] 0x006EE120 om::TRbTree<audio::MixerMix, 4>::Comp<audio::MixerMix, 4, audio::Mix*>::vfunc_00 (35 B)
// [TODO] 0x006EE150 sub_006EE150 (427 B)
// ============================================================================
// [VERIFIED] sub_006EE310 (0x006EE310, 59 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_002D0890 (0x002D0890), which was matched first;
// its addresses and names were swapped for this function's.
// sub_006EE310 (0x006EE310, 59 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field14
{
    void sub_006F2A20();
};

extern "C" int DAT_0085CEB0;
extern "C" void __cdecl sub_006F2A20(void);

class Class_006EE310
{
public:
    Class_006EE310* sub_006EE310();
    char m_pad00[0x14];
    Field14 m_Field14; // +0x14
    char m_pad15[0x13];
    int m_Field28; // +0x28
    int m_Field2C; // +0x2C
    int m_Field30; // +0x30
    int m_Field34; // +0x34
    char m_pad38[0x8];
    int m_Field40; // +0x40
    int m_Field44; // +0x44
    int m_Field48; // +0x48
    int m_Field4C; // +0x4C
    int m_Field50; // +0x50
};

Class_006EE310* Class_006EE310::sub_006EE310()
{
    ::sub_006F2A20();
    m_Field14.sub_006F2A20();
    m_Field28 = 0;
    m_Field2C = 0;
    m_Field30 = 0;
    m_Field34 = 0;
    DAT_0085CEB0 = (int)this;
    m_Field48 = 0;
    m_Field4C = 0;
    m_Field40 = 0;
    m_Field44 = 0;
    m_Field50 = 0x3F800000;
    return this;
}

// [TODO] 0x006EE350 sub_006EE350 (91 B)
// [TODO] 0x006EE3B0 sub_006EE3B0 (97 B)
// [TODO] 0x006EE420 om::TRbTree<audio::MixerBuss, 0>::Comp<audio::MixerBuss, 0, om::Name<om::CaseSensitive32BitKey>>::vfunc_00 (29 B)
// [TODO] 0x006EE440 sub_006EE440 (88 B)
// [TODO] 0x006EE4A0 sub_006EE4A0 (71 B)
// ============================================================================
// [VERIFIED] sub_006EE4F0 (0x006EE4F0, 60 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G7 /Gd /GR /EHsc /Zp4
// ============================================================================
// bin: pc
// va: 0x006EE4F0
// what: 
// tool: the portal's starter code (no AI)

// sub_006EE4F0 (PC 0x006EE4F0, 60 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field20
{
    void sub_006F2A40(int);
};

struct Object
{
    void sub_006F2C40(int);
};

extern "C" char DAT_007F682C[];
extern "C" int __cdecl sub_006EE890(int, int);

class Class_006EE4F0
{
public:
    int sub_006EE4F0();
    char m_pad00[0x10];
    int m_Field10; // +0x10
    char m_pad14[0xC];
    Field20* m_Field20; // +0x20
    char m_pad24[0x4];
    int m_Field28; // +0x28
};

int Class_006EE4F0::sub_006EE4F0()
{
    int t1;
    Field20* t2;

    t1 = m_Field28;
    if ((unsigned int)m_Field28 > (unsigned int)1) {
        m_Field28 = t1 + -1;
        return t1 + -1;
    }
    t2 = m_Field20;
    m_Field20->sub_006F2A40((int)this);
    ((Object*)(int)t2 + 40)->sub_006F2C40((int)(&m_Field10));
    return sub_006EE890((int)DAT_007F682C, (int)this);
}

// ============================================================================
// [VERIFIED] sub_006EE530 (0x006EE530, 56 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00291AF0 (Proto 0x00291AF0), which was matched first;
// its addresses and names were swapped for this function's.
// sub_006EE530 (Proto 0x006EE530, 56 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    int sub_006EE4A0(int, int);
};

extern "C" char DAT_007F682C[];
extern "C" int __stdcall sub_006EE3B0(int);
extern "C" int __cdecl sub_006EE870(int);

class Class_006EE530
{
public:
    int sub_006EE530(int a1);
};

int Class_006EE530::sub_006EE530(int a1)
{
    int r_eax;

    r_eax = sub_006EE3B0(a1);
    if (!r_eax) {
        r_eax = sub_006EE870((int)DAT_007F682C);
        if (r_eax) {
            r_eax = ((Object*)r_eax)->sub_006EE4A0((int)this, a1);
            return r_eax;
        }
        r_eax = 0;
    }
    return r_eax;
}

// ============================================================================
// [VERIFIED] sub_006EE570 (0x006EE570, 5 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00023D40 (0x00023D40), which was matched first;
// its addresses and names were swapped for this function's.
// sub_006EE570 (0x006EE570, 5 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __cdecl sub_006EE3B0(void);

class Class_006EE570
{
public:
    void sub_006EE570();
};

void Class_006EE570::sub_006EE570()
{
    sub_006EE3B0();
}

// [TODO] 0x006EE600 sub_006EE600 (114 B)
// [TODO] 0x006EE680 sub_006EE680 (99 B)
// [TODO] 0x006EE790 sub_006EE790 (99 B)
// ============================================================================
// [VERIFIED] audio::MixerMix::vfunc_03 (0x006EE800, 35 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as SoundManager::StatePropSoundPlayer::vfunc_00 (0x00082430), which was matched first;
// its addresses and names were swapped for this function's.
// audio::MixerMix::vfunc_03 (0x006EE800, 35 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_007F681C[];
extern "C" void __cdecl sub_006EE790(void);
extern "C" void __cdecl sub_006EE890(int, int);

namespace audio {

class MixerMix
{
public:
    virtual MixerMix* vfunc_03(int a1);
};

MixerMix* MixerMix::vfunc_03(int a1)
{
    sub_006EE790();
    if (a1 & 1) {
        sub_006EE890((int)DAT_007F681C, (int)this);
    }
    return this;
}

}

// ============================================================================
// [VERIFIED] sub_006EE870 (0x006EE870, 18 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_002CF960 (0x002CF960), which was matched first;
// its addresses and names were swapped for this function's.
// sub_006EE870 (0x006EE870, 18 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_007F6834;

void __cdecl sub_006EE870(int a1)
{
    ((void (__cdecl*)(int, int))*(int*)(DAT_007F6834 + 4))(DAT_007F6834, a1);
}

// [TODO] 0x006EE8B0 sub_006EE8B0 (67 B)
// ============================================================================
// [VERIFIED] sub_006EE900 (0x006EE900, 25 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_000B7EE0 (0x000B7EE0), which was matched first;
// its addresses and names were swapped for this function's.
// sub_006EE900 (0x006EE900, 25 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_007726E4[];

class Class_006EE900
{
public:
    Class_006EE900* sub_006EE900(int a1, int a2);
    int m_Field00; // +0x00
    int m_Field04; // +0x04
    int m_Field08; // +0x08
};

Class_006EE900* Class_006EE900::sub_006EE900(int a1, int a2)
{
    m_Field00 = (int)DAT_007726E4;
    m_Field04 = a1;
    m_Field08 = a2;
    return this;
}

// [TODO] 0x006EE930 sub_006EE930 (85 B)
// ============================================================================
// [VERIFIED] om::Allocator::vfunc_00 (0x006EE990, 31 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as core::BaseObject::vfunc_00 (0x00026BB0), which was matched first;
// its addresses and names were swapped for this function's.
// om::Allocator::vfunc_00 (0x006EE990, 31 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_007726E4[];
extern "C" void __cdecl sub_0043CE70(int);

namespace om {

class Allocator
{
public:
    virtual Allocator* vfunc_00(int a1);
};

Allocator* Allocator::vfunc_00(int a1)
{
    *(int*)this = (int)DAT_007726E4;
    if (a1 & 1) {
        sub_0043CE70((int)this);
    }
    return this;
}

}

// ============================================================================
// [VERIFIED] sub_006EE9B0 (0x006EE9B0, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// bin: pc
// va: 0x006EE9B0
// what: 
// tool: the portal's starter code (no AI)

// sub_006EE9B0 (PC 0x006EE9B0, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0085CEC0[];

void* __cdecl sub_006EE9B0(void)
{
    return DAT_0085CEC0;
}

// ============================================================================
// [VERIFIED] sub_006EE9D0 (0x006EE9D0, 19 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00081980 (0x00081980), which was matched first;
// its addresses and names were swapped for this function's.
// sub_006EE9D0 (0x006EE9D0, 19 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_007F69A8[];
extern "C" void __cdecl sub_006EE890(int, int);

void __cdecl sub_006EE9D0(int a1)
{
    sub_006EE890((int)DAT_007F69A8, a1);
}

// ============================================================================
// [VERIFIED] om::MetaType<audio::SeqEvent>::vfunc_00 (0x006EEAC0, 36 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as om::MetaType<audio::SeqEvent>::vfunc_00 (0x002D0EA0), which was matched first;
// its addresses and names were swapped for this function's.
// om::MetaType<audio::SeqEvent>::vfunc_00 (0x006EEAC0, 36 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_00772708[];
extern "C" void __cdecl sub_006EC7B0(int);
extern "C" void __cdecl sub_006ECB50(void);

namespace audio { class SeqEvent; }

namespace om { 
template <class T0> class MetaType
{
public:
    virtual MetaType<audio::SeqEvent>* vfunc_00(int a1);
};
}

template <> om::MetaType<audio::SeqEvent>* om::MetaType<audio::SeqEvent>::vfunc_00(int a1)
{
    *(int*)this = (int)DAT_00772708;
    sub_006ECB50();
    if (a1 & 1) {
        sub_006EC7B0((int)this);
    }
    return this;
}

// ============================================================================
// [VERIFIED] om::MetaType<audio::Mix>::vfunc_00 (0x006EEAF0, 36 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as om::MetaType<audio::SeqEvent>::vfunc_00 (0x002D0EA0), which was matched first;
// its addresses and names were swapped for this function's.
// om::MetaType<audio::Mix>::vfunc_00 (0x006EEAF0, 36 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_00772718[];
extern "C" void __cdecl sub_006EC7B0(int);
extern "C" void __cdecl sub_006ECB50(void);

namespace audio { class Mix; }

namespace om { 
template <class T0> class MetaType
{
public:
    virtual MetaType<audio::Mix>* vfunc_00(int a1);
};
}

template <> om::MetaType<audio::Mix>* om::MetaType<audio::Mix>::vfunc_00(int a1)
{
    *(int*)this = (int)DAT_00772718;
    sub_006ECB50();
    if (a1 & 1) {
        sub_006EC7B0((int)this);
    }
    return this;
}

// ============================================================================
// [VERIFIED] om::MetaType<audio::Clip>::vfunc_00 (0x006EEB20, 36 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as om::MetaType<audio::SeqEvent>::vfunc_00 (0x002D0EA0), which was matched first;
// its addresses and names were swapped for this function's.
// om::MetaType<audio::Clip>::vfunc_00 (0x006EEB20, 36 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_00772728[];
extern "C" void __cdecl sub_006EC7B0(int);
extern "C" void __cdecl sub_006ECB50(void);

namespace audio { class Clip; }

namespace om { 
template <class T0> class MetaType
{
public:
    virtual MetaType<audio::Clip>* vfunc_00(int a1);
};
}

template <> om::MetaType<audio::Clip>* om::MetaType<audio::Clip>::vfunc_00(int a1)
{
    *(int*)this = (int)DAT_00772728;
    sub_006ECB50();
    if (a1 & 1) {
        sub_006EC7B0((int)this);
    }
    return this;
}

// ============================================================================
// [VERIFIED] om::MetaType<audio::Sequence>::vfunc_00 (0x006EEB50, 36 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as om::MetaType<audio::SeqEvent>::vfunc_00 (0x002D0EA0), which was matched first;
// its addresses and names were swapped for this function's.
// om::MetaType<audio::Sequence>::vfunc_00 (0x006EEB50, 36 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_00772738[];
extern "C" void __cdecl sub_006EC7B0(int);
extern "C" void __cdecl sub_006ECB50(void);

namespace audio { class Sequence; }

namespace om { 
template <class T0> class MetaType
{
public:
    virtual MetaType<audio::Sequence>* vfunc_00(int a1);
};
}

template <> om::MetaType<audio::Sequence>* om::MetaType<audio::Sequence>::vfunc_00(int a1)
{
    *(int*)this = (int)DAT_00772738;
    sub_006ECB50();
    if (a1 & 1) {
        sub_006EC7B0((int)this);
    }
    return this;
}

// ============================================================================
// [VERIFIED] sub_006EEB80 (0x006EEB80, 102 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00065340 (0x00065340), which was matched first;
// its addresses and names were swapped for this function's.
// sub_006EEB80 (0x006EEB80, 102 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_006ECAC0(int, int);
};

extern "C" char DAT_00772718[];
extern "C" char DAT_00772748[];
extern "C" int DAT_0085CEDC;
extern "C" int __cdecl sub_006EC7A0(int);

class Class_006EEB80
{
public:
    Class_006EEB80* sub_006EEB80(int a1, int a2, int a3, int a4);
    void sub_006ED350(int, int, int, int);
    int m_Field00; // +0x00
};

Class_006EEB80* Class_006EEB80::sub_006EEB80(int a1, int a2, int a3, int a4)
{
    int t2;

    sub_006ED350(a1, a2, a3, a4);
    m_Field00 = (int)DAT_00772748;
    t2 = sub_006EC7A0(88);
    if (t2) {
        ((Object*)t2)->sub_006ECAC0(a1, 0);
        *(int*)t2 = (int)DAT_00772718;
        DAT_0085CEDC = t2;
        return this;
    }
    DAT_0085CEDC = 0;
    return this;
}

// ============================================================================
// [VERIFIED] om::EntityType<audio::Mix>::vfunc_03 (0x006EEBF0, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as om::EntityType<audio::Mix>::vfunc_03 (0x002D0FD0), which was matched first;
// its addresses and names were swapped for this function's.
// om::EntityType<audio::Mix>::vfunc_03 (0x006EEBF0, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_007C1624[];

namespace audio { class Mix; }

namespace om { 
template <class T0> class EntityType
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void* vfunc_03();
};
}

template <> void* om::EntityType<audio::Mix>::vfunc_03()
{
    return DAT_007C1624;
}

// ============================================================================
// [VERIFIED] om::EntityType<audio::Mix>::vfunc_02 (0x006EEC00, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as om::EntityType<audio::Mix>::vfunc_02 (0x002D0FE0), which was matched first;
// its addresses and names were swapped for this function's.
// om::EntityType<audio::Mix>::vfunc_02 (0x006EEC00, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_0085CEDC;

namespace audio { class Mix; }

namespace om { 
template <class T0> class EntityType
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual int vfunc_02();
};
}

template <> int om::EntityType<audio::Mix>::vfunc_02()
{
    return DAT_0085CEDC;
}

// ============================================================================
// [VERIFIED] om::EntityType<audio::Mix>::vfunc_01 (0x006EEC10, 41 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as om::EntityType<audio::Mix>::vfunc_01 (0x002D0FF0), which was matched first;
// its addresses and names were swapped for this function's.
// om::EntityType<audio::Mix>::vfunc_01 (0x006EEC10, 41 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    int sub_006F6020(int);
};

extern "C" int DAT_00811DA8;
extern "C" int __cdecl sub_006EE870(int);

namespace audio { class Mix; }

namespace om { 
template <class T0> class EntityType
{
public:
    virtual void vfunc_00();
    virtual int vfunc_01(int a1);
};
}

template <> int om::EntityType<audio::Mix>::vfunc_01(int a1)
{
    int r_eax;

    r_eax = DAT_00811DA8;
    if (r_eax) {
        r_eax += 4;
    } else {
        r_eax = 0;
    }
    r_eax = sub_006EE870(r_eax);
    if (r_eax) {
        return ((Object*)r_eax)->sub_006F6020(a1);
    }
    r_eax = 0;
    return r_eax;
}

// ============================================================================
// [VERIFIED] sub_006EEC40 (0x006EEC40, 102 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00065340 (0x00065340), which was matched first;
// its addresses and names were swapped for this function's.
// sub_006EEC40 (0x006EEC40, 102 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_006ECAC0(int, int);
};

extern "C" char DAT_00772728[];
extern "C" char DAT_0077275C[];
extern "C" int DAT_0085CEE0;
extern "C" int __cdecl sub_006EC7A0(int);

class Class_006EEC40
{
public:
    Class_006EEC40* sub_006EEC40(int a1, int a2, int a3, int a4);
    void sub_006ED350(int, int, int, int);
    int m_Field00; // +0x00
};

Class_006EEC40* Class_006EEC40::sub_006EEC40(int a1, int a2, int a3, int a4)
{
    int t2;

    sub_006ED350(a1, a2, a3, a4);
    m_Field00 = (int)DAT_0077275C;
    t2 = sub_006EC7A0(88);
    if (t2) {
        ((Object*)t2)->sub_006ECAC0(a1, 0);
        *(int*)t2 = (int)DAT_00772728;
        DAT_0085CEE0 = t2;
        return this;
    }
    DAT_0085CEE0 = 0;
    return this;
}

// ============================================================================
// [VERIFIED] om::EntityType<audio::Clip>::vfunc_03 (0x006EECB0, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as om::EntityType<audio::Mix>::vfunc_03 (0x002D0FD0), which was matched first;
// its addresses and names were swapped for this function's.
// om::EntityType<audio::Clip>::vfunc_03 (0x006EECB0, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_007C6038[];

namespace audio { class Clip; }

namespace om { 
template <class T0> class EntityType
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void* vfunc_03();
};
}

template <> void* om::EntityType<audio::Clip>::vfunc_03()
{
    return DAT_007C6038;
}

// ============================================================================
// [VERIFIED] om::EntityType<audio::Clip>::vfunc_02 (0x006EECC0, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as om::EntityType<audio::Mix>::vfunc_02 (0x002D0FE0), which was matched first;
// its addresses and names were swapped for this function's.
// om::EntityType<audio::Clip>::vfunc_02 (0x006EECC0, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_0085CEE0;

namespace audio { class Clip; }

namespace om { 
template <class T0> class EntityType
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual int vfunc_02();
};
}

template <> int om::EntityType<audio::Clip>::vfunc_02()
{
    return DAT_0085CEE0;
}

// [TODO] 0x006EECD0 om::EntityType<audio::Clip>::vfunc_01 (69 B)
// ============================================================================
// [VERIFIED] audio::Clip::vfunc_12 (0x006EED20, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as core::MemoryAllocatorMalloc::vfunc_12 (0x0028D100), which was matched first;
// its addresses and names were swapped for this function's.
// audio::Clip::vfunc_12 (0x006EED20, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_0085CED0;

namespace audio {

class Clip
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
    virtual int vfunc_12();
};

int Clip::vfunc_12()
{
    return DAT_0085CED0;
}

}

// [TODO] 0x006EED30 audio::Clip::vfunc_03 (61 B)
// ============================================================================
// [VERIFIED] sub_006EED70 (0x006EED70, 102 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00065340 (0x00065340), which was matched first;
// its addresses and names were swapped for this function's.
// sub_006EED70 (0x006EED70, 102 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_006ECAC0(int, int);
};

extern "C" char DAT_00772738[];
extern "C" char DAT_007727A8[];
extern "C" int DAT_0085CEE4;
extern "C" int __cdecl sub_006EC7A0(int);

class Class_006EED70
{
public:
    Class_006EED70* sub_006EED70(int a1, int a2, int a3, int a4);
    void sub_006ED350(int, int, int, int);
    int m_Field00; // +0x00
};

Class_006EED70* Class_006EED70::sub_006EED70(int a1, int a2, int a3, int a4)
{
    int t2;

    sub_006ED350(a1, a2, a3, a4);
    m_Field00 = (int)DAT_007727A8;
    t2 = sub_006EC7A0(88);
    if (t2) {
        ((Object*)t2)->sub_006ECAC0(a1, 0);
        *(int*)t2 = (int)DAT_00772738;
        DAT_0085CEE4 = t2;
        return this;
    }
    DAT_0085CEE4 = 0;
    return this;
}

// ============================================================================
// [VERIFIED] om::EntityType<audio::Sequence>::vfunc_03 (0x006EEDE0, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as om::EntityType<audio::Mix>::vfunc_03 (0x002D0FD0), which was matched first;
// its addresses and names were swapped for this function's.
// om::EntityType<audio::Sequence>::vfunc_03 (0x006EEDE0, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_007C1604[];

namespace audio { class Sequence; }

namespace om { 
template <class T0> class EntityType
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void* vfunc_03();
};
}

template <> void* om::EntityType<audio::Sequence>::vfunc_03()
{
    return DAT_007C1604;
}

// ============================================================================
// [VERIFIED] om::EntityType<audio::Sequence>::vfunc_02 (0x006EEDF0, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as om::EntityType<audio::Mix>::vfunc_02 (0x002D0FE0), which was matched first;
// its addresses and names were swapped for this function's.
// om::EntityType<audio::Sequence>::vfunc_02 (0x006EEDF0, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_0085CEE4;

namespace audio { class Sequence; }

namespace om { 
template <class T0> class EntityType
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual int vfunc_02();
};
}

template <> int om::EntityType<audio::Sequence>::vfunc_02()
{
    return DAT_0085CEE4;
}

// ============================================================================
// [VERIFIED] om::EntityType<audio::Sequence>::vfunc_01 (0x006EEE00, 41 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as om::EntityType<audio::Mix>::vfunc_01 (0x002D0FF0), which was matched first;
// its addresses and names were swapped for this function's.
// om::EntityType<audio::Sequence>::vfunc_01 (0x006EEE00, 41 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    int sub_006ED550(int);
};

extern "C" int DAT_00811D78;
extern "C" int __cdecl sub_006EE870(int);

namespace audio { class Sequence; }

namespace om { 
template <class T0> class EntityType
{
public:
    virtual void vfunc_00();
    virtual int vfunc_01(int a1);
};
}

template <> int om::EntityType<audio::Sequence>::vfunc_01(int a1)
{
    int r_eax;

    r_eax = DAT_00811D78;
    if (r_eax) {
        r_eax += 4;
    } else {
        r_eax = 0;
    }
    r_eax = sub_006EE870(r_eax);
    if (r_eax) {
        return ((Object*)r_eax)->sub_006ED550(a1);
    }
    r_eax = 0;
    return r_eax;
}

// ============================================================================
// [VERIFIED] sub_006EF160 (0x006EF160, 13 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_0007F7F0 (0x0007F7F0), which was matched first;
// its addresses and names were swapped for this function's.
// sub_006EF160 (0x006EF160, 13 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_007F69B4[];
extern "C" void __stdcall sub_006EE870(int);

class Class_006EF160
{
public:
    void sub_006EF160(int a1);
};

void Class_006EF160::sub_006EF160(int a1)
{
    a1 = (int)DAT_007F69B4;
    sub_006EE870(a1);
}

// ============================================================================
// [VERIFIED] sub_006EF170 (0x006EF170, 19 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00081980 (0x00081980), which was matched first;
// its addresses and names were swapped for this function's.
// sub_006EF170 (0x006EF170, 19 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_007F69B4[];
extern "C" void __cdecl sub_006EE890(int, int);

void __cdecl sub_006EF170(int a1)
{
    sub_006EE890((int)DAT_007F69B4, a1);
}

// [TODO] 0x006EF190 sub_006EF190 (222 B)
// ============================================================================
// [VERIFIED] sub_006EF290 (0x006EF290, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_006EE9B0 (PC 0x006EE9B0), which was matched first;
// its addresses and names were swapped for this function's.
// bin: pc
// va: 0x006EF290
// what: 
// tool: the portal's starter code (no AI)

// sub_006EF290 (PC 0x006EF290, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0085D0F0[];

void* __cdecl sub_006EF290(void)
{
    return DAT_0085D0F0;
}

// ============================================================================
// [VERIFIED] sub_006EF360 (0x006EF360, 10 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00011710 (0x00011710), which was matched first;
// its addresses and names were swapped for this function's.
// sub_006EF360 (0x006EF360, 10 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" bool DAT_0085D12C;

bool __cdecl sub_006EF360(bool a1)
{
    DAT_0085D12C = a1;
    return a1;
}

// [TODO] 0x006EF370 sub_006EF370 (83 B)
// [TODO] 0x006EF3D0 sub_006EF3D0 (157 B)
// [TODO] 0x006EF470 sub_006EF470 (208 B)
// [TODO] 0x006EF540 sub_006EF540 (292 B)
// [TODO] 0x006EF670 sub_006EF670 (539 B)
// ============================================================================
// [VERIFIED] sub_006EF8F0 (0x006EF8F0, 9 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// What it does: Returns the number at +0x24 of a global object.
// ============================================================================
// bin: pc
// va: 0x006EF8F0
// what: Returns the number at +0x24 of a global object.
// tool: Claude Opus 5.5 (transplanted from proto:0x0006D060, nearest by portal/tools/similar.py)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_0085D134;

int __cdecl sub_006EF8F0(void)
{
    return *(int*)(DAT_0085D134 + 36);
}

// [TODO] 0x006EF900 sub_006EF900 (27 B)
// ============================================================================
// [VERIFIED] sub_006EF970 (0x006EF970, 8 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// What it does: Returns the address 12 bytes into a record.
// ============================================================================
// bin: pc
// va: 0x006EF970
// what: Returns the address 12 bytes into a record.
// tool: Claude Opus 5.5 (transplanted from proto:0x0029AFB0, nearest by portal/tools/similar.py)
// sub_006EF970 (Proto 0x006EF970, 8 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

int __cdecl sub_006EF970(int a1)
{
    return a1 + 12;
}

// ============================================================================
// [VERIFIED] sub_006EF980 (0x006EF980, 8 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_0002E0C0 (0x0002E0C0), which was matched first;
// its addresses and names were swapped for this function's.
// sub_006EF980 (0x006EF980, 8 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

int __cdecl sub_006EF980(int a1)
{
    return *(int*)(a1 + 16);
}

// ============================================================================
// [VERIFIED] sub_006EF990 (0x006EF990, 12 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// bin: pc
// va: 0x006EF990
// what: 
// tool: the portal's starter code (no AI)

// sub_006EF990 (PC 0x006EF990, 12 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

int __cdecl sub_006EF990(int a1, int a2)
{
    *(int*)(a1 + 32) = a2;
    return a2;
}

// ============================================================================
// [VERIFIED] sub_006EF9E0 (0x006EF9E0, 35 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// bin: pc
// va: 0x006EF9E0
// what: 
// tool: the portal's starter code (no AI)

// sub_006EF9E0 (PC 0x006EF9E0, 35 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_0085D134;
extern "C" void __cdecl sub_006F4A80(int, int);

bool __cdecl sub_006EF9E0(int a1)
{
    sub_006F4A80(DAT_0085D134, a1);
    *(int*)(a1 + 32) = 0;
    *(int*)(a1 + 28) = 0;
    *(bool*)(a1 + 24) = false;
    return true;
}

// [TODO] 0x006EFA10 sub_006EFA10 (61 B)
// ============================================================================
// [VERIFIED] sub_006EFA50 (0x006EFA50, 12 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// What it does: Stores 3 at +0x18 of a record and returns the record.
// ============================================================================
// bin: pc
// va: 0x006EFA50
// what: Stores 3 at +0x18 of a record and returns the record.
// tool: Claude Opus 5.5 (transplanted from proto:0x002AB460, nearest by portal/tools/similar.py)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

int __cdecl sub_006EFA50(int a1)
{
    *(int*)(a1 + 24) = 3;
    return a1;
}

// [TODO] 0x006EFA60 sub_006EFA60 (256 B)
// ============================================================================
// [VERIFIED] sub_006EFB60 (0x006EFB60, 8 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_0002E0B0 (0x0002E0B0), which was matched first;
// its addresses and names were swapped for this function's.
// sub_006EFB60 (0x006EFB60, 8 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

int __cdecl sub_006EFB60(int a1)
{
    return *(int*)(a1 + 8);
}

// ============================================================================
// [VERIFIED] sub_006EFB70 (0x006EFB70, 12 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// What it does: Stores a decimal number at +0x10 of a record and returns the record.
// ============================================================================
// bin: pc
// va: 0x006EFB70
// what: Stores a decimal number at +0x10 of a record and returns the record.
// tool: Claude Opus 5.5 (transplanted from proto:0x002AB580, nearest by portal/tools/similar.py)
// sub_006EFB70 (Proto 0x006EFB70, 12 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

int __cdecl sub_006EFB70(int a1, float a2)
{
    *(float*)(a1 + 16) = a2;
    return a1;
}

// ============================================================================
// [VERIFIED] sub_006EFB80 (0x006EFB80, 12 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_002AB580 (Proto 0x002AB580), which was matched first;
// its addresses and names were swapped for this function's.
// sub_006EFB80 (Proto 0x006EFB80, 12 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

int __cdecl sub_006EFB80(int a1, float a2)
{
    *(float*)(a1 + 20) = a2;
    return a1;
}

// [TODO] 0x006EFB90 sub_006EFB90 (94 B)
// [TODO] 0x006EFBF0 sub_006EFBF0 (136 B)
// ============================================================================
// [VERIFIED] sub_006EFC80 (0x006EFC80, 13 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// What it does: Returns entry number a2 of the table at +0x5C in the object passed in.
// ============================================================================
// bin: pc
// va: 0x006EFC80
// what: Returns entry number a2 of the table at +0x5C in the object passed in.
// tool: Claude Opus 5.5 (transplanted from proto:0x002AB690, nearest by portal/tools/similar.py)
// sub_006EFC80 (Proto 0x006EFC80, 13 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

int __cdecl sub_006EFC80(int a1, int a2)
{
    return *(int*)(a1 + (a2 * 4) + 92);
}

// [TODO] 0x006EFCB0 sub_006EFCB0 (44 B)
// ============================================================================
// [VERIFIED] sub_006EFCE0 (0x006EFCE0, 8 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// What it does: Returns the value at +0x18 in the object passed in.
// ============================================================================
// bin: pc
// va: 0x006EFCE0
// what: Returns the value at +0x18 in the object passed in.
// tool: Claude Opus 5.5 (transplanted from proto:0x0027AA80, nearest by portal/tools/similar.py)
// sub_006EFCE0 (Proto 0x006EFCE0, 8 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

int __cdecl sub_006EFCE0(int a1)
{
    return *(int*)(a1 + 24);
}

// [TODO] 0x006EFCF0 sub_006EFCF0 (61 B)
// ============================================================================
// [VERIFIED] sub_006EFD30 (0x006EFD30, 12 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// What it does: Stores a yes/no value at +0x0C of a record and returns it.
// ============================================================================
// bin: pc
// va: 0x006EFD30
// what: Stores a yes/no value at +0x0C of a record and returns it.
// tool: Claude Opus 5.5 (transplanted from proto:0x002AB470, nearest by portal/tools/similar.py)
// sub_006EFD30 (Proto 0x006EFD30, 12 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

bool __cdecl sub_006EFD30(int a1, bool a2)
{
    *(bool*)(a1 + 12) = a2;
    return a2;
}

// [TODO] 0x006EFD40 sub_006EFD40 (43 B)
// [TODO] 0x006EFD70 sub_006EFD70 (143 B)
// ============================================================================
// [VERIFIED] sub_006EFF60 (0x006EFF60, 86 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G7 /Gd /GR /EHsc /Zp4
// ============================================================================
// bin: pc
// va: 0x006EFF60
// what: 
// tool: the portal's starter code (no AI)

// sub_006EFF60 (PC 0x006EFF60, 86 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_006EBBD0();
    void sub_006F2C40(int);
};

extern "C" int DAT_0072F058;
extern "C" char DAT_007F69E0[];
extern "C" int DAT_0085D134;
extern "C" void __cdecl sub_006EE890(int, int);
extern "C" void __cdecl sub_006F3C50(int, int);

int __cdecl sub_006EFF60(int a1)
{
    int t6;

    ((Object*)DAT_0085D134 + 8)->sub_006F2C40(a1);
    ((void (__stdcall*)(int, int, int))DAT_0072F058)(*(int*)(a1 + 20), 0, 32768);
    sub_006F3C50(DAT_0085D134, a1);
    ((Object*)a1 + 104)->sub_006EBBD0();
    sub_006EE890((int)DAT_007F69E0, a1);
    t6 = DAT_0085D134;
    *(int*)(DAT_0085D134 + 20) += -1;
    return t6;
}

// [TODO] 0x006F0210 sub_006F0210 (445 B)
// ============================================================================
// [VERIFIED] om::MetaType<audio::LayerTemplate>::vfunc_00 (0x006F03D0, 36 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as om::MetaType<audio::SeqEvent>::vfunc_00 (0x002D0EA0), which was matched first;
// its addresses and names were swapped for this function's.
// om::MetaType<audio::LayerTemplate>::vfunc_00 (0x006F03D0, 36 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_007728D0[];
extern "C" void __cdecl sub_006EC7B0(int);
extern "C" void __cdecl sub_006ECB50(void);

namespace audio { class LayerTemplate; }

namespace om { 
template <class T0> class MetaType
{
public:
    virtual MetaType<audio::LayerTemplate>* vfunc_00(int a1);
};
}

template <> om::MetaType<audio::LayerTemplate>* om::MetaType<audio::LayerTemplate>::vfunc_00(int a1)
{
    *(int*)this = (int)DAT_007728D0;
    sub_006ECB50();
    if (a1 & 1) {
        sub_006EC7B0((int)this);
    }
    return this;
}

// [TODO] 0x006F0400 audio::LayerTemplate::vfunc_06 (45 B)
// ============================================================================
// [VERIFIED] audio::LayerTemplate::vfunc_12 (0x006F04A0, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as core::MemoryAllocatorMalloc::vfunc_12 (0x0028D100), which was matched first;
// its addresses and names were swapped for this function's.
// audio::LayerTemplate::vfunc_12 (0x006F04A0, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_00811D7C;

namespace audio {

class LayerTemplate
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
    virtual int vfunc_12();
};

int LayerTemplate::vfunc_12()
{
    return DAT_00811D7C;
}

}

// [TODO] 0x006F04B0 sub_006F04B0 (58 B)
// ============================================================================
// [VERIFIED] sub_006F04F0 (0x006F04F0, 102 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00065340 (0x00065340), which was matched first;
// its addresses and names were swapped for this function's.
// sub_006F04F0 (0x006F04F0, 102 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_006ECAC0(int, int);
};

extern "C" char DAT_007728D0[];
extern "C" char DAT_00772918[];
extern "C" int DAT_0085D138;
extern "C" int __cdecl sub_006EC7A0(int);

class Class_006F04F0
{
public:
    Class_006F04F0* sub_006F04F0(int a1, int a2, int a3, int a4);
    void sub_006ED350(int, int, int, int);
    int m_Field00; // +0x00
};

Class_006F04F0* Class_006F04F0::sub_006F04F0(int a1, int a2, int a3, int a4)
{
    int t2;

    sub_006ED350(a1, a2, a3, a4);
    m_Field00 = (int)DAT_00772918;
    t2 = sub_006EC7A0(88);
    if (t2) {
        ((Object*)t2)->sub_006ECAC0(a1, 0);
        *(int*)t2 = (int)DAT_007728D0;
        DAT_0085D138 = t2;
        return this;
    }
    DAT_0085D138 = 0;
    return this;
}

// ============================================================================
// [VERIFIED] om::EntityType<audio::LayerTemplate>::vfunc_03 (0x006F0560, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as om::EntityType<audio::Mix>::vfunc_03 (0x002D0FD0), which was matched first;
// its addresses and names were swapped for this function's.
// om::EntityType<audio::LayerTemplate>::vfunc_03 (0x006F0560, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_007F6A1C[];

namespace audio { class LayerTemplate; }

namespace om { 
template <class T0> class EntityType
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void* vfunc_03();
};
}

template <> void* om::EntityType<audio::LayerTemplate>::vfunc_03()
{
    return DAT_007F6A1C;
}

// ============================================================================
// [VERIFIED] om::EntityType<audio::LayerTemplate>::vfunc_02 (0x006F0570, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as om::EntityType<audio::Mix>::vfunc_02 (0x002D0FE0), which was matched first;
// its addresses and names were swapped for this function's.
// om::EntityType<audio::LayerTemplate>::vfunc_02 (0x006F0570, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_0085D138;

namespace audio { class LayerTemplate; }

namespace om { 
template <class T0> class EntityType
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual int vfunc_02();
};
}

template <> int om::EntityType<audio::LayerTemplate>::vfunc_02()
{
    return DAT_0085D138;
}

// ============================================================================
// [VERIFIED] om::EntityType<audio::LayerTemplate>::vfunc_01 (0x006F0580, 41 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as om::EntityType<audio::Mix>::vfunc_01 (0x002D0FF0), which was matched first;
// its addresses and names were swapped for this function's.
// om::EntityType<audio::LayerTemplate>::vfunc_01 (0x006F0580, 41 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    int sub_006F0430(int);
};

extern "C" int DAT_00811D7C;
extern "C" int __cdecl sub_006EE870(int);

namespace audio { class LayerTemplate; }

namespace om { 
template <class T0> class EntityType
{
public:
    virtual void vfunc_00();
    virtual int vfunc_01(int a1);
};
}

template <> int om::EntityType<audio::LayerTemplate>::vfunc_01(int a1)
{
    int r_eax;

    r_eax = DAT_00811D7C;
    if (r_eax) {
        r_eax += 4;
    } else {
        r_eax = 0;
    }
    r_eax = sub_006EE870(r_eax);
    if (r_eax) {
        return ((Object*)r_eax)->sub_006F0430(a1);
    }
    r_eax = 0;
    return r_eax;
}

// [TODO] 0x006F05B0 sub_006F05B0 (92 B)
// [TODO] 0x006F0610 audio::LayerTemplate::vfunc_03 (99 B)
// [TODO] 0x006F0680 sub_006F0680 (766 B)
// ============================================================================
// [VERIFIED] sub_006F0990 (0x006F0990, 19 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00081980 (0x00081980), which was matched first;
// its addresses and names were swapped for this function's.
// sub_006F0990 (0x006F0990, 19 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_007F6BB4[];
extern "C" void __cdecl sub_006EE890(int, int);

void __cdecl sub_006F0990(int a1)
{
    sub_006EE890((int)DAT_007F6BB4, a1);
}

// ============================================================================
// [VERIFIED] audio::StreamPlayerAllocator::vfunc_00 (0x006F09B0, 44 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// bin: pc
// va: 0x006F09B0
// what: 
// tool: the portal's starter code (no AI)

// audio::StreamPlayerAllocator::vfunc_00 (PC 0x006F09B0, 44 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int __cdecl sub_006F2080(int, int, int, int, int, int, int);

namespace audio {

class StreamPlayerAllocator
{
public:
    virtual int vfunc_00(int a1, int a2, int a3, int a4, int a5, int a6);
};

int StreamPlayerAllocator::vfunc_00(int a1, int a2, int a3, int a4, int a5, int a6)
{
    int t1;

    t1 = sub_006F2080(a4, 1, a3, a5, 0, 0, 1);
    *(int*)a6 = 0x20000;
    return t1;
}

}

// ============================================================================
// [VERIFIED] audio::StreamPlayerAllocator::vfunc_01 (0x006F09E0, 14 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as audio::StreamPlayerAllocator::vfunc_01 (Proto 0x002963B0), which was matched first;
// its addresses and names were swapped for this function's.
// audio::StreamPlayerAllocator::vfunc_01 (Proto 0x006F09E0, 14 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __cdecl sub_006F21F0(int);

namespace audio {

class StreamPlayerAllocator
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01(int a1, int a2);
};

void StreamPlayerAllocator::vfunc_01(int a1, int a2)
{
    sub_006F21F0(a2);
}

}

// [TODO] 0x006F0A70 sub_006F0A70 (123 B)
// [TODO] 0x006F0AF0 sub_006F0AF0 (311 B)
// [TODO] 0x006F0C30 sub_006F0C30 (122 B)
// [TODO] 0x006F0D00 sub_006F0D00 (97 B)
// [TODO] 0x006F0D70 sub_006F0D70 (103 B)
// [TODO] 0x006F0DE0 om::TRbTree<audio::SeqPlayerTrack, 0>::Comp<audio::SeqPlayerTrack, 0, om::Name<om::CaseSensitive32BitKey>>::vfunc_00 (34 B)
// [TODO] 0x006F0E10 om::TRbTree<audio::SeqPlayerLayer, 0>::Comp<audio::SeqPlayerLayer, 0, om::Name<om::CaseSensitive32BitKey>>::vfunc_00 (29 B)
// [TODO] 0x006F0FF0 sub_006F0FF0 (128 B)
// ============================================================================
// [VERIFIED] sub_006F1070 (0x006F1070, 34 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_002D2970 (0x002D2970), which was matched first;
// its addresses and names were swapped for this function's.
// sub_006F1070 (0x006F1070, 34 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field2C
{
    int sub_006F0D00(int);
};

class Class_006F1070
{
public:
    void sub_006F1070(int a1);
    void sub_006F0FF0(int);
    char m_pad00[0x2C];
    Field2C m_Field2C; // +0x2C
};

void Class_006F1070::sub_006F1070(int a1)
{
    if (!m_Field2C.sub_006F0D00(a1)) {
        sub_006F0FF0(a1);
    }
}

// [TODO] 0x006F1350 sub_006F1350 (51 B)
// ============================================================================
// [VERIFIED] sub_006F1390 (0x006F1390, 15 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_002985E0 (Proto 0x002985E0), which was matched first;
// its addresses and names were swapped for this function's.
// sub_006F1390 (Proto 0x006F1390, 15 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" bool DAT_007F6BD4;

bool __cdecl sub_006F1390(int a1)
{
    return *(bool*)(((int)&DAT_007F6BD4) + ((a1 + (a1 * 2)) * 8));
}

// ============================================================================
// [VERIFIED] sub_006F13A0 (0x006F13A0, 29 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00298620 (Proto 0x00298620), which was matched first;
// its addresses and names were swapped for this function's.
// sub_006F13A0 (Proto 0x006F13A0, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_007F6BD0;

int __cdecl sub_006F13A0(int a1)
{
    return ((((unsigned int)*(int*)a1) >> 4) & 31) * *(int*)(((int)&DAT_007F6BD0) + (((*(int*)a1 & 15) + ((*(int*)a1 & 15) * 2)) * 8));
}

// ============================================================================
// [VERIFIED] sub_006F13C0 (0x006F13C0, 20 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00298640 (Proto 0x00298640), which was matched first;
// its addresses and names were swapped for this function's.
// sub_006F13C0 (Proto 0x006F13C0, 20 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_007F6BCC;

int __cdecl sub_006F13C0(int a1)
{
    return *(int*)(((int)&DAT_007F6BCC) + (((*(int*)a1 & 15) + ((*(int*)a1 & 15) * 2)) * 8));
}

// ============================================================================
// [VERIFIED] sub_006F13E0 (0x006F13E0, 34 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_002986A0 (Proto 0x002986A0), which was matched first;
// its addresses and names were swapped for this function's.
// sub_006F13E0 (Proto 0x006F13E0, 34 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_007F6BD0;

int __cdecl sub_006F13E0(int a1, int a2)
{
    return ((((unsigned int)*(int*)a1) >> 4) & 31) * *(int*)(((int)&DAT_007F6BD0) + (((*(int*)a1 & 15) + ((*(int*)a1 & 15) * 2)) * 8)) * a2;
}

// [TODO] 0x006F1410 sub_006F1410 (41 B)
// [TODO] 0x006F1490 sub_006F1490 (71 B)
// [TODO] 0x006F1560 sub_006F1560 (111 B)
// [TODO] 0x006F1600 sub_006F1600 (50 B)
// [TODO] 0x006F1640 sub_006F1640 (37 B)
// [TODO] 0x006F1670 sub_006F1670 (72 B)
// ============================================================================
// [VERIFIED] sub_006F16C0 (0x006F16C0, 11 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_0029A110 (Proto 0x0029A110), which was matched first;
// its addresses and names were swapped for this function's.
// sub_006F16C0 (Proto 0x006F16C0, 11 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

int __cdecl sub_006F16C0(int a1)
{
    return *(int*)(a1 + 192);
}

// [TODO] 0x006F16E0 sub_006F16E0 (16 B)
// ============================================================================
// [VERIFIED] sub_006F16F0 (0x006F16F0, 16 B)
// By: lemiur | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_002D37A0 (0x002D37A0), which was matched first;
// its addresses and names were swapped for this function's.
// bin: xb
// va: 0x006F16F0
// what: Passes a value stored inside the given record, with a number, on to another function.
// tool: Claude Opus 5.5 (symcov hint: _HLBApiPresenceExtra, link-order)
// sub_006F16F0 (0x006F16F0, 16 bytes)

struct Struct_006F16F0
{
    int m_Field00; // +0x00
    int m_Field04; // +0x04
    int m_Field08; // +0x08
};

extern "C" int __cdecl sub_006EFB70(int handle, float);

// Calls the function with the record's value at +0x08 in place of the record.
int __cdecl sub_006F16F0(Struct_006F16F0 *record, float value)
{
    return sub_006EFB70(record->m_Field08, value);
}

// ============================================================================
// [VERIFIED] sub_006F1700 (0x006F1700, 16 B)
// By: lemiur | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_002D37B0 (0x002D37B0), which was matched first;
// its addresses and names were swapped for this function's.
// bin: xb
// va: 0x006F1700
// what: Passes a value stored inside the given record, with two more arguments, on to another function.
// tool: Claude Opus 5.5 (symcov hint: _HLBApiPresenceDiff)
// sub_006F1700 (0x006F1700, 16 bytes)

struct Struct_006F1700
{
    int m_Field00; // +0x00
    int m_Field04; // +0x04
    int m_Field08; // +0x08
};

extern "C" void __cdecl sub_006EFB90(int handle, int, unsigned int);

// Calls the function with the record's value at +0x08 in place of the record.
void __cdecl sub_006F1700(Struct_006F1700 *record, int a2, unsigned int count)
{
    sub_006EFB90(record->m_Field08, a2, count);
}

// ============================================================================
// [VERIFIED] sub_006F1710 (0x006F1710, 16 B)
// By: lemiur | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_002D37B0 (0x002D37B0), which was matched first;
// its addresses and names were swapped for this function's.
// bin: xb
// va: 0x006F1710
// what: Passes a value stored inside the given record, with two more arguments, on to another function.
// tool: Claude Opus 5.5 (symcov hint: _HLBApiPresenceDiff)
// sub_006F1710 (0x006F1710, 16 bytes)

struct Struct_006F1710
{
    int m_Field00; // +0x00
    int m_Field04; // +0x04
    int m_Field08; // +0x08
};

extern "C" void __cdecl sub_006EFBF0(int handle, int, unsigned int);

// Calls the function with the record's value at +0x08 in place of the record.
void __cdecl sub_006F1710(Struct_006F1710 *record, int a2, unsigned int count)
{
    sub_006EFBF0(record->m_Field08, a2, count);
}

// ============================================================================
// [VERIFIED] sub_006F1720 (0x006F1720, 16 B)
// By: lemiur | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_002D37A0 (0x002D37A0), which was matched first;
// its addresses and names were swapped for this function's.
// bin: xb
// va: 0x006F1720
// what: Passes a value stored inside the given record, with a number, on to another function.
// tool: Claude Opus 5.5 (symcov hint: _HLBApiPresenceExtra, link-order)
// sub_006F1720 (0x006F1720, 16 bytes)

struct Struct_006F1720
{
    int m_Field00; // +0x00
    int m_Field04; // +0x04
    int m_Field08; // +0x08
};

extern "C" int __cdecl sub_006EFB80(int handle, float);

// Calls the function with the record's value at +0x08 in place of the record.
int __cdecl sub_006F1720(Struct_006F1720 *record, float value)
{
    return sub_006EFB80(record->m_Field08, value);
}

// ============================================================================
// [VERIFIED] sub_006F1730 (0x006F1730, 16 B)
// By: lemiur | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_002D37A0 (0x002D37A0), which was matched first;
// its addresses and names were swapped for this function's.
// bin: xb
// va: 0x006F1730
// what: Passes a value stored inside the given record, with a number, on to another function.
// tool: Claude Opus 5.5 (symcov hint: _HLBApiPresenceExtra, link-order)
// sub_006F1730 (0x006F1730, 16 bytes)

struct Struct_006F1730
{
    int m_Field00; // +0x00
    int m_Field04; // +0x04
    int m_Field08; // +0x08
};

extern "C" int __cdecl sub_006EFC80(int handle, float);

// Calls the function with the record's value at +0x08 in place of the record.
int __cdecl sub_006F1730(Struct_006F1730 *record, float value)
{
    return sub_006EFC80(record->m_Field08, value);
}

// ============================================================================
// [VERIFIED] sub_006F1740 (0x006F1740, 11 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_0029A180 (Proto 0x0029A180), which was matched first;
// its addresses and names were swapped for this function's.
// sub_006F1740 (Proto 0x006F1740, 11 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

int __cdecl sub_006F1740(int a1)
{
    return *(int*)(*(int*)(a1 + 16) + 36);
}

// [TODO] 0x006F1750 sub_006F1750 (139 B)
// [TODO] 0x006F17E0 sub_006F17E0 (22 B)
// ============================================================================
// [VERIFIED] sub_006F1800 (0x006F1800, 12 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_0029A240 (Proto 0x0029A240), which was matched first;
// its addresses and names were swapped for this function's.
// sub_006F1800 (Proto 0x006F1800, 12 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

int __cdecl sub_006F1800(int a1)
{
    return *(unsigned char*)(a1 + 185);
}

// [TODO] 0x006F1810 sub_006F1810 (45 B)
// ============================================================================
// [VERIFIED] sub_006F1840 (0x006F1840, 20 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G7 /Gd /GR /EHsc /Zp4
// ============================================================================
// bin: pc
// va: 0x006F1840
// what: 
// tool: the portal's starter code (no AI)

// sub_006F1840 (PC 0x006F1840, 20 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

class Class_006F1840
{
public:
    int sub_006F1840();
    char m_pad00[0x78];
    unsigned char m_Field78; // +0x78
    unsigned char m_Field79; // +0x79
};

int Class_006F1840::sub_006F1840()
{
    if (!m_Field79) {
        return 0;
    }
    return (int)this + ((m_Field78 + (m_Field78 * 2)) * 4);
}

// [TODO] 0x006F1860 sub_006F1860 (72 B)
// [TODO] 0x006F18B0 sub_006F18B0 (111 B)
// [TODO] 0x006F1DF0 sub_006F1DF0 (85 B)
// [TODO] 0x006F1EF0 sub_006F1EF0 (396 B)
// [TODO] 0x006F2080 sub_006F2080 (357 B)
// [TODO] 0x006F21F0 sub_006F21F0 (127 B)
// [TODO] 0x006F22D0 sub_006F22D0 (58 B)
// [TODO] 0x006F2310 sub_006F2310 (22 B)
// [TODO] 0x006F2330 sub_006F2330 (71 B)
// [TODO] 0x006F2380 sub_006F2380 (34 B)
// [TODO] 0x006F23B0 sub_006F23B0 (51 B)
// [TODO] 0x006F23F0 sub_006F23F0 (62 B)
// ============================================================================
// [VERIFIED] sub_006F2430 (0x006F2430, 21 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00296E70 (Proto 0x00296E70), which was matched first;
// its addresses and names were swapped for this function's.
// sub_006F2430 (Proto 0x006F2430, 21 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

class Class_006F2430
{
public:
    void* sub_006F2430();
    int m_Field00; // +0x00
    int m_Field04; // +0x04
    int m_Field08; // +0x08
    int m_Field0C; // +0x0C
    int m_Field10; // +0x10
};

void* Class_006F2430::sub_006F2430()
{
    m_Field04 = (int)(&m_Field04);
    m_Field08 = (int)(&m_Field04);
    m_Field0C = (int)(&m_Field04);
    m_Field10 = 0;
    m_Field00 = (int)(&m_Field04);
    return &m_Field04;
}

// [TODO] 0x006F2450 sub_006F2450 (27 B)
// [TODO] 0x006F2470 sub_006F2470 (75 B)
// [TODO] 0x006F24C0 sub_006F24C0 (75 B)
// [TODO] 0x006F2510 sub_006F2510 (91 B)
// ============================================================================
// [VERIFIED] sub_006F2570 (0x006F2570, 80 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_002ADF70 (Proto 0x002ADF70), which was matched first;
// its addresses and names were swapped for this function's.
// sub_006F2570 (Proto 0x006F2570, 80 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

class Class_006F2570
{
public:
    int sub_006F2570(int a1);
    int m_Field00; // +0x00
    int m_Field04; // +0x04
};

int Class_006F2570::sub_006F2570(int a1)
{
    int r_eax, r_edi, r_esi;

    r_eax = *(int*)(a1 + 4);
    r_esi = *(int*)r_eax;
    *(int*)(a1 + 4) = r_esi;
    r_esi = *(int*)r_eax;
    r_edi = (int)(&m_Field04);
    if (r_esi != ((int)(&m_Field04))) {
        *(int*)(r_esi + 8) = a1;
    }
    r_esi = *(int*)(a1 + 8);
    *(int*)(r_eax + 8) = r_esi;
    r_esi = *(int*)(a1 + 8);
    if (r_esi == r_edi) {
        m_Field00 = r_eax;
        *(int*)r_eax = a1;
        *(int*)(a1 + 8) = r_eax;
        return r_eax;
    }
    if (a1 == *(int*)r_esi) {
        *(int*)r_esi = r_eax;
        *(int*)r_eax = a1;
        *(int*)(a1 + 8) = r_eax;
        return r_eax;
    }
    *(int*)(r_esi + 4) = r_eax;
    *(int*)r_eax = a1;
    *(int*)(a1 + 8) = r_eax;
    return r_eax;
}

// [TODO] 0x006F25C0 sub_006F25C0 (55 B)
// [TODO] 0x006F2600 sub_006F2600 (603 B)
// [TODO] 0x006F2A40 sub_006F2A40 (168 B)
// ============================================================================
// [VERIFIED] sub_006F2BD0 (0x006F2BD0, 37 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_002D4D20 (0x002D4D20), which was matched first;
// its addresses and names were swapped for this function's.
// sub_006F2BD0 (0x006F2BD0, 37 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

class Class_006F2BD0
{
public:
    int sub_006F2BD0(int a1);
    int m_Field00; // +0x00
    int m_Field04; // +0x04
};

int Class_006F2BD0::sub_006F2BD0(int a1)
{
    int t1;

    *(int*)(a1 + 4) = 0;
    *(int*)a1 = m_Field00;
    t1 = m_Field00;
    if (m_Field00) {
        *(int*)(t1 + 4) = a1;
        m_Field00 = a1;
        return a1;
    }
    m_Field04 = a1;
    m_Field00 = a1;
    return a1;
}

// ============================================================================
// [VERIFIED] sub_006F2C00 (0x006F2C00, 53 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_0029CB70 (Proto 0x0029CB70), which was matched first;
// its addresses and names were swapped for this function's.
// sub_006F2C00 (Proto 0x006F2C00, 53 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

class Class_006F2C00
{
public:
    int sub_006F2C00(int a1);
    int m_Field00; // +0x00
    int m_Field04; // +0x04
};

int Class_006F2C00::sub_006F2C00(int a1)
{
    if (!m_Field00) {
        m_Field00 = a1;
        *(int*)(a1 + 4) = 0;
        m_Field04 = a1;
        *(int*)a1 = 0;
        return a1;
    }
    *(int*)m_Field04 = a1;
    *(int*)(a1 + 4) = m_Field04;
    m_Field04 = a1;
    *(int*)a1 = 0;
    return a1;
}

// [TODO] 0x006F2C40 sub_006F2C40 (47 B)
// ============================================================================
// [VERIFIED] sub_006F2C70 (0x006F2C70, 18 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G7 /Gd /GR /EHsc /Zp4
// ============================================================================
// bin: pc
// va: 0x006F2C70
// what: 
// tool: the portal's starter code (no AI)

// sub_006F2C70 (PC 0x006F2C70, 18 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

class Class_006F2C70
{
public:
    int sub_006F2C70();
};

int Class_006F2C70::sub_006F2C70()
{
    int r_eax, r_ecx;

    r_ecx = (int)this;
    r_ecx = *(int*)r_ecx;
    r_eax = 0;
    if (r_ecx) {
        do {
            r_ecx = *(int*)r_ecx;
            r_eax += 1;
        } while (r_ecx);
    }
    return r_eax;
}

// [TODO] 0x006F2C90 sub_006F2C90 (116 B)
// ============================================================================
// [VERIFIED] om::SparksHeap::vfunc_00 (0x006F2EF0, 14 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as om::SparksHeap::vfunc_00 (Proto 0x0029A0C0), which was matched first;
// its addresses and names were swapped for this function's.
// om::SparksHeap::vfunc_00 (Proto 0x006F2EF0, 14 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __cdecl sub_006F2C90(void);

namespace om {

class SparksHeap
{
public:
    virtual SparksHeap* vfunc_00(int a1);
};

SparksHeap* SparksHeap::vfunc_00(int a1)
{
    sub_006F2C90();
    return this;
}

}

// ============================================================================
// [VERIFIED] sub_006F2F00 (0x006F2F00, 33 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_002D5430 (0x002D5430), which was matched first;
// its addresses and names were swapped for this function's.
// sub_006F2F00 (0x006F2F00, 33 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_00772770[];
extern "C" int __cdecl sub_006EFF60(int);

class Class_006F2F00
{
public:
    void sub_006F2F00();
    void sub_006ED0C0();
    int m_Field00; // +0x00
    char m_pad04[0x24];
    int m_Field28; // +0x28
};

void Class_006F2F00::sub_006F2F00()
{
    int r_eax;

    r_eax = m_Field28;
    m_Field00 = (int)DAT_00772770;
    if (r_eax) {
        r_eax = sub_006EFF60(r_eax);
    }
    sub_006ED0C0();
}

// [TODO] 0x006F2F30 sub_006F2F30 (451 B)
// [TODO] 0x006F3100 audio::Clip::vfunc_06 (143 B)
// [TODO] 0x006F3260 om::TRbTree<om::MetaAttribBase, 4>::Comp<om::MetaAttribBase, 4, const char*>::vfunc_00 (71 B)
// [TODO] 0x006F3300 sub_006F3300 (44 B)
// [TODO] 0x006F3330 sub_006F3330 (31 B)
// [TODO] 0x006F3350 sub_006F3350 (21 B)
// [TODO] 0x006F3370 sub_006F3370 (19 B)
// [TODO] 0x006F33D0 sub_006F33D0 (21 B)
// [TODO] 0x006F33F0 sub_006F33F0 (19 B)
// [TODO] 0x006F3410 sub_006F3410 (19 B)
// [TODO] 0x006F3430 sub_006F3430 (21 B)
// [TODO] 0x006F3460 audio::HalRsdFileStream::vfunc_00 (67 B)
// [TODO] 0x006F34B0 audio::HalRsdFileStream::vfunc_05 (61 B)
// [TODO] 0x006F34F0 audio::HalRsdFileStream::vfunc_01 (68 B)
// ============================================================================
// [VERIFIED] audio::HalRsdFileStream::vfunc_03 (0x006F3540, 41 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as audio::HalRsdFileStream::vfunc_03 (0x002D64B0), which was matched first;
// its addresses and names were swapped for this function's.
// audio::HalRsdFileStream::vfunc_03 (0x006F3540, 41 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" bool __cdecl sub_006F1390(int);
extern "C" int __cdecl sub_006F13A0(int);

namespace audio {

class HalRsdFileStream
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual int vfunc_03();
    char m_pad04[0x24];
    int m_Field28; // +0x28
};

int HalRsdFileStream::vfunc_03()
{
    if (sub_006F1390(m_Field28 & 15)) {
        return sub_006F13A0((int)(&m_Field28));
    }
    return 2048;
}

}

// ============================================================================
// [VERIFIED] audio::HalRsdFileStream::vfunc_09 (0x006F3570, 32 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as audio::HalRsdFileStream::vfunc_09 (Proto 0x002AD670), which was matched first;
// its addresses and names were swapped for this function's.
// audio::HalRsdFileStream::vfunc_09 (Proto 0x006F3570, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_00772AD4[];

namespace audio {

class HalRsdFileStream
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
    virtual int vfunc_09(int a1);
    char m_pad04[0x20];
    int m_Field24; // +0x24
};

int HalRsdFileStream::vfunc_09(int a1)
{
    int r_eax;

    r_eax = m_Field24;
    if (!r_eax) {
        r_eax = (int)DAT_00772AD4;
        return r_eax;
    }
    r_eax = (a1 << 4) + r_eax + 164;
    return r_eax;
}

}

// ============================================================================
// [VERIFIED] audio::HalRsdFileStream::vfunc_10 (0x006F3590, 8 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as core::CementLibrary::vfunc_01 (0x002ACEB0), which was matched first;
// its addresses and names were swapped for this function's.
// audio::HalRsdFileStream::vfunc_10 (0x006F3590, 8 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_006EB6D0();
};

namespace audio {

class HalRsdFileStream
{
public:
    virtual void vfunc_00();
    virtual void vfunc_10();
};

void HalRsdFileStream::vfunc_10()
{
    ((Object*)(int)this + 16)->sub_006EB6D0();
}

}

// [TODO] 0x006F35A0 audio::HalRsdFileStream::vfunc_07 (117 B)
// [TODO] 0x006F3620 audio::HalRsdFileStream::vfunc_06 (79 B)
// ============================================================================
// [VERIFIED] audio::HalRsdFileStream::vfunc_08 (0x006F3670, 32 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// bin: pc
// va: 0x006F3670
// what: 
// tool: the portal's starter code (no AI)

// audio::HalRsdFileStream::vfunc_08 (PC 0x006F3670, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

namespace audio {

class HalRsdFileStream
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
    virtual bool vfunc_08(int a1);
    char m_pad04[0x38];
    int m_Field3C; // +0x3C
    char m_pad40[0x4];
    unsigned short m_Field44; // +0x44
};

bool HalRsdFileStream::vfunc_08(int a1)
{
    if (m_Field44 == 5) {
        return false;
    }
    *(int*)a1 = m_Field3C;
    m_Field44 = 4;
    return true;
}

}

// [TODO] 0x006F36E0 audio::HalRsdFileStream::vfunc_11 (255 B)
// [TODO] 0x006F37E0 sub_006F37E0 (58 B)
// [TODO] 0x006F3820 sub_006F3820 (155 B)
// ============================================================================
// [VERIFIED] audio::HalRsdFileStream::vfunc_15 (0x006F38C0, 45 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G7 /Gd /GR /EHsc /Zp4
// ============================================================================
// bin: pc
// va: 0x006F38C0
// what: 
// tool: the portal's starter code (no AI)

// audio::HalRsdFileStream::vfunc_15 (PC 0x006F38C0, 45 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_0085D360;

namespace audio {

class HalRsdFileStream
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
    virtual int vfunc_15(int a1);
    char m_pad04[0x3D];
    unsigned char m_Field41; // +0x41
    char m_pad42[0x6];
    int m_Field48; // +0x48
};

int HalRsdFileStream::vfunc_15(int a1)
{
    int r_eax;

    r_eax = DAT_0085D360;
    if (r_eax) {
        if (!m_Field41) goto L_29;
        r_eax = ((int (__cdecl*)(int, int, int, int, int))r_eax)((int)(&m_Field48), a1, 0, 0, 0);
        m_Field41 = (unsigned char)r_eax;
    }
L_29:
    return r_eax;
}

}

// [TODO] 0x006F38F0 sub_006F38F0 (154 B)
// ============================================================================
// [VERIFIED] audio::HalRsdFileStream::vfunc_12 (0x006F3990, 77 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G7 /Gd /GR /EHsc /Zp4
// ============================================================================
// bin: pc
// va: 0x006F3990
// what: 
// tool: the portal's starter code (no AI)

// audio::HalRsdFileStream::vfunc_12 (PC 0x006F3990, 77 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field10
{
    void sub_006EBBD0();
};

struct Field20
{
    virtual void vfunc_00();
    virtual void vfunc_01();
};

extern "C" char DAT_007F6D44[];
extern "C" char DAT_007F6D4C[];
extern "C" void __cdecl sub_006EE890(int, int);

namespace audio {

class HalRsdFileStream
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
    virtual void vfunc_15(int);
    Field10 m_Field04; // +0x04
    char m_pad05[0xB];
    Field10 m_Field10; // +0x10
    char m_pad11[0xF];
    Field20* m_Field20; // +0x20
    int m_Field24; // +0x24
};

void HalRsdFileStream::vfunc_12()
{
    int t3;

    if (m_Field20) {
        vfunc_15(4);
        m_Field20->vfunc_01();
    }
    t3 = m_Field24;
    if (m_Field24) {
        sub_006EE890((int)DAT_007F6D44, t3);
    }
    m_Field10.sub_006EBBD0();
    m_Field04.sub_006EBBD0();
    sub_006EE890((int)DAT_007F6D4C, (int)this);
}

}

// ============================================================================
// [VERIFIED] sub_006F39E0 (0x006F39E0, 66 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// bin: pc
// va: 0x006F39E0
// what: 
// tool: the portal's starter code (no AI)

// sub_006F39E0 (PC 0x006F39E0, 66 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" float DAT_0072F990;
extern "C" float DAT_0072F994;
extern "C" float DAT_0074660C;
extern "C" float DAT_00763FFC;
extern "C" float DAT_00764004;
extern "C" float DAT_00764008;

float __cdecl sub_006F39E0(bool a1)
{
    if (a1 & 16) {
        return DAT_0074660C;
    }
    if (a1 & 8) {
        return DAT_0072F990;
    }
    if (a1 & 4) {
        return DAT_00764004;
    }
    if (a1 & 2) {
        return DAT_00764008;
    }
    if (a1 & 1) {
        return DAT_00763FFC;
    }
    return DAT_0072F994;
}

// [TODO] 0x006F3A30 sub_006F3A30 (116 B)
// [TODO] 0x006F3AB0 sub_006F3AB0 (19 B)
// ============================================================================
// [VERIFIED] sub_006F3AD0 (0x006F3AD0, 15 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// bin: pc
// va: 0x006F3AD0
// what: 
// tool: the portal's starter code (no AI)

// sub_006F3AD0 (PC 0x006F3AD0, 15 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

int __cdecl sub_006F3AD0(int a1, int a2)
{
    *(int*)(a2 + 144) = 0;
    return a2;
}

// [TODO] 0x006F3AE0 sub_006F3AE0 (82 B)
// [TODO] 0x006F3B40 sub_006F3B40 (204 B)
// [TODO] 0x006F3C10 sub_006F3C10 (57 B)
// [TODO] 0x006F3C50 sub_006F3C50 (51 B)
// [TODO] 0x006F3C90 sub_006F3C90 (146 B)
// ============================================================================
// [VERIFIED] sub_006F3D30 (0x006F3D30, 61 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// bin: pc
// va: 0x006F3D30
// what: 
// tool: the portal's starter code (no AI)

// sub_006F3D30 (PC 0x006F3D30, 61 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __cdecl sub_006F3C90(int, int, int, int, int);

void __cdecl sub_006F3D30(int a1, int a2, int a3, int a4)
{
    sub_006F3C90(a1 + 12, *(int*)(a1 + 20) + (((((((unsigned int)*(int*)(a1 + 12)) >> 4) & 31) * a3) + a2) * 2), *(int*)(a1 + (a2 * 4) + 40), a3, a4);
}

// [TODO] 0x006F3E30 sub_006F3E30 (181 B)
// [TODO] 0x006F4010 sub_006F4010 (595 B)
// [TODO] 0x006F4270 sub_006F4270 (59 B)
// [TODO] 0x006F42B0 sub_006F42B0 (1156 B)
// [TODO] 0x006F4740 sub_006F4740 (568 B)
// [TODO] 0x006F4980 sub_006F4980 (131 B)
// [TODO] 0x006F4A10 sub_006F4A10 (104 B)
// [TODO] 0x006F4A80 sub_006F4A80 (105 B)
// [TODO] 0x006F4AF0 sub_006F4AF0 (270 B)
// [TODO] 0x006F4C00 sub_006F4C00 (225 B)
// ============================================================================
// [VERIFIED] audio::OggVorbisStream::vfunc_00 (0x006F4D00, 40 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// bin: pc
// va: 0x006F4D00
// what: 
// tool: the portal's starter code (no AI)

// audio::OggVorbisStream::vfunc_00 (PC 0x006F4D00, 40 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field04
{
    virtual void vfunc_00();
    virtual int vfunc_01();
};

namespace audio {

class OggVorbisStream
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
    Field04* m_Field04; // +0x04
    char m_pad08[0x2E4];
    int m_Field2EC; // +0x2EC
};

void OggVorbisStream::vfunc_00()
{
    if (!m_Field04->vfunc_01()) {
        m_Field04->vfunc_00();
    }
    m_Field2EC = 1;
    vfunc_11();
}

}

// ============================================================================
// [VERIFIED] audio::OggVorbisStream::vfunc_12 (0x006F4D30, 12 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as audio::HalRadicalAdpcmDecodeStream::vfunc_12 (0x002E0A30), which was matched first;
// its addresses and names were swapped for this function's.
// audio::OggVorbisStream::vfunc_12 (0x006F4D30, 12 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

namespace audio {

class OggVorbisStream
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
    virtual void vfunc_17(int);
};

void OggVorbisStream::vfunc_12()
{
    if (this) {
        vfunc_17(1);
    }
}

}

// [TODO] 0x006F4D40 audio::OggVorbisStream::vfunc_05 (54 B)
// ============================================================================
// [VERIFIED] audio::OggVorbisStream::vfunc_01 (0x006F4D80, 7 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// What it does: Returns the number stored at +0x2EC in the audio stream.
// ============================================================================
// bin: pc
// va: 0x006F4D80
// what: Returns the number stored at +0x2EC in the audio stream.
// tool: Claude Opus 5.5 (transplanted from pc:0x006E1CF0, nearest by portal/tools/similar.py)
// audio::OggVorbisStream::vfunc_01
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.


namespace audio {
class OggVorbisStream
{
public:
    virtual void vfunc_00();
    virtual int vfunc_01();
    char m_pad04[0x2E8];
    int m_Field2EC; // +0x2EC
};

int OggVorbisStream::vfunc_01()
{
    return m_Field2EC;
}
}

// ============================================================================
// [VERIFIED] audio::OggVorbisStream::vfunc_02 (0x006F4D90, 7 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// What it does: Returns the address of the block at +0x2DC inside the audio stream.
// ============================================================================
// bin: pc
// va: 0x006F4D90
// what: Returns the address of the block at +0x2DC inside the audio stream.
// tool: Claude Opus 5.5 (transplanted from pc:0x006E4260, nearest by portal/tools/similar.py)
// audio::OggVorbisStream::vfunc_02
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.


namespace audio {
class OggVorbisStream
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void* vfunc_02();
    char m_pad04[0x2D8];
    int m_Field2DC; // +0x2DC
};

void* OggVorbisStream::vfunc_02()
{
    return &m_Field2DC;
}
}

// ============================================================================
// [VERIFIED] audio::OggVorbisStream::vfunc_03 (0x006F4DA0, 15 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G7 /Gd /GR /EHsc /Zp4
// ============================================================================
// bin: pc
// va: 0x006F4DA0
// what: 
// tool: the portal's starter code (no AI)

// audio::OggVorbisStream::vfunc_03 (PC 0x006F4DA0, 15 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

namespace audio {

class OggVorbisStream
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual int vfunc_03();
    char m_pad04[0x2D8];
    int m_Field2DC; // +0x2DC
};

int OggVorbisStream::vfunc_03()
{
    return ((((unsigned int)m_Field2DC) >> 4) & 31) + ((((unsigned int)m_Field2DC) >> 4) & 31);
}

}

// ============================================================================
// [VERIFIED] AirplanePlaneCollisionReceiver::vfunc_00 (0x006F4DB0, 8 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// What it does: Airplane-plane collision receiver: forwards to the 10th virtual of its owner at +0x04.
// ============================================================================
// Same machine code as AirplanePlaneCollisionReceiver::vfunc_00 (0x0009B2D0), which was matched first;
// its addresses and names were swapped for this function's.
// AirplanePlaneCollisionReceiver::vfunc_00 (0x006F4DB0, 8 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field04
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
};

class AirplanePlaneCollisionReceiver
{
public:
    virtual void vfunc_00();
    Field04* m_Field04; // +0x04
};

void AirplanePlaneCollisionReceiver::vfunc_00()
{
    m_Field04->vfunc_09();
}

// ============================================================================
// [VERIFIED] audio::OggVorbisStream::vfunc_10 (0x006F4DC0, 8 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as audio::HalRadicalAdpcmDecodeStream::vfunc_10 (Proto 0x002AD200), which was matched first;
// its addresses and names were swapped for this function's.
// audio::OggVorbisStream::vfunc_10 (Proto 0x006F4DC0, 8 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field04
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
};

namespace audio {

class OggVorbisStream
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
    Field04* m_Field04; // +0x04
};

void OggVorbisStream::vfunc_10()
{
    m_Field04->vfunc_10();
}

}

// ============================================================================
// [VERIFIED] audio::OggVorbisStream::vfunc_04 (0x006F4DD0, 13 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// bin: pc
// va: 0x006F4DD0
// what: 
// tool: the portal's starter code (no AI)

// audio::OggVorbisStream::vfunc_04 (PC 0x006F4DD0, 13 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

namespace audio {

class OggVorbisStream
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual int vfunc_04();
    char m_pad04[0x2DC];
    int m_Field2E0; // +0x2E0
    int m_Field2E4; // +0x2E4
};

int OggVorbisStream::vfunc_04()
{
    return m_Field2E0 - m_Field2E4;
}

}

// [TODO] 0x006F4DE0 audio::OggVorbisStream::vfunc_06 (117 B)
// ============================================================================
// [VERIFIED] audio::OggVorbisStream::vfunc_08 (0x006F4E60, 27 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// bin: pc
// va: 0x006F4E60
// what: 
// tool: the portal's starter code (no AI)

// audio::OggVorbisStream::vfunc_08 (PC 0x006F4E60, 27 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

namespace audio {

class OggVorbisStream
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
    virtual bool vfunc_08(int a1);
    char m_pad04[0x2E4];
    int m_Field2E8; // +0x2E8
};

bool OggVorbisStream::vfunc_08(int a1)
{
    *(int*)a1 = m_Field2E8;
    m_Field2E8 = 0;
    return true;
}

}

// ============================================================================
// [VERIFIED] sub_006F4F10 (0x006F4F10, 73 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// bin: pc
// va: 0x006F4F10
// what: 
// tool: the portal's starter code (no AI)

// sub_006F4F10 (PC 0x006F4F10, 73 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field2DC
{
    void sub_006F1340();
};

extern "C" char DAT_00772B5C[];

class Class_006F4F10
{
public:
    Class_006F4F10* sub_006F4F10(int a1);
    int m_Field00; // +0x00
    int m_Field04; // +0x04
    char m_pad08[0x2D0];
    int m_Field2D8; // +0x2D8
    Field2DC m_Field2DC; // +0x2DC
    char m_pad2DD[0x3];
    int m_Field2E0; // +0x2E0
    int m_Field2E4; // +0x2E4
    int m_Field2E8; // +0x2E8
    int m_Field2EC; // +0x2EC
    int m_Field2F0; // +0x2F0
};

Class_006F4F10* Class_006F4F10::sub_006F4F10(int a1)
{
    m_Field00 = (int)DAT_00772B5C;
    m_Field04 = a1;
    m_Field2D8 = 0;
    m_Field2DC.sub_006F1340();
    m_Field2E0 = 0;
    m_Field2E4 = 0;
    m_Field2E8 = 0;
    m_Field2EC = 0;
    m_Field2F0 = 0;
    return this;
}

// ============================================================================
// [VERIFIED] audio::OggVorbisStream::vfunc_17 (0x006F4F60, 95 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G7 /Gd /GR /EHsc /Zp4
// ============================================================================
// bin: pc
// va: 0x006F4F60
// what: 
// tool: the portal's starter code (no AI)

// audio::OggVorbisStream::vfunc_17 (PC 0x006F4F60, 95 bytes)
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
};

extern "C" char DAT_00772B5C[];
extern "C" char DAT_007F6D80[];
extern "C" void __cdecl sub_0043CE70(int);
extern "C" void __cdecl sub_006EE890(int, int);
extern "C" void __cdecl sub_00702724(int);

namespace audio {

class OggVorbisStream
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
    virtual OggVorbisStream* vfunc_17(int a1);
    int m_Field04; // +0x04
    int m_Field08; // +0x08
    char m_pad0C[0x2CC];
    int m_Field2D8; // +0x2D8
    char m_pad2DC[0x14];
    int m_Field2F0; // +0x2F0
};

OggVorbisStream* OggVorbisStream::vfunc_17(int a1)
{
    int t1;

    t1 = m_Field04;
    *(int*)this = (int)DAT_00772B5C;
    ((Object*)t1)->vfunc_12();
    sub_0043CE70(m_Field2F0);
    if (m_Field2D8) {
        sub_00702724((int)(&m_Field08));
    }
    sub_0043CE70(m_Field2D8);
    if (a1 & 1) {
        sub_006EE890((int)DAT_007F6D80, (int)this);
    }
    return this;
}

}

// ============================================================================
// [VERIFIED] sub_006F4FC0 (0x006F4FC0, 53 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// bin: pc
// va: 0x006F4FC0
// what: 
// tool: the portal's starter code (no AI)

// sub_006F4FC0 (PC 0x006F4FC0, 53 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char sub_00652580[];
extern "C" char sub_006EF980[];
extern "C" char sub_006F4E80[];
extern "C" char sub_006F4ED0[];

class Class_006F4FC0
{
public:
    Class_006F4FC0* sub_006F4FC0(int a1, int a2);
    int m_Field00; // +0x00
    int m_Field04; // +0x04
    int m_Field08; // +0x08
    int m_Field0C; // +0x0C
    int m_Field10; // +0x10
    int m_Field14; // +0x14
    int m_Field18; // +0x18
};

Class_006F4FC0* Class_006F4FC0::sub_006F4FC0(int a1, int a2)
{
    m_Field10 = 0;
    m_Field14 = a2;
    m_Field18 = a1;
    m_Field00 = (int)sub_006F4E80;
    m_Field04 = (int)sub_006F4ED0;
    m_Field08 = (int)sub_00652580;
    m_Field0C = (int)sub_006EF980;
    return this;
}

// ============================================================================
// [VERIFIED] sub_006F5000 (0x006F5000, 33 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// bin: pc
// va: 0x006F5000
// what: 
// tool: the portal's starter code (no AI)

// sub_006F5000 (PC 0x006F5000, 33 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    int sub_006F4F10(int);
};

extern "C" char DAT_007F6D80[];
extern "C" int __cdecl sub_006EE870(int);

int __cdecl sub_006F5000(int a1)
{
    int t1;

    t1 = sub_006EE870((int)DAT_007F6D80);
    if (t1) {
        return ((Object*)t1)->sub_006F4F10(a1);
    }
    return 0;
}

// [TODO] 0x006F5030 audio::OggVorbisStream::vfunc_11 (414 B)
// [TODO] 0x006F51D0 sub_006F51D0 (137 B)
// [TODO] 0x006F5260 sub_006F5260 (298 B)
// [TODO] 0x006F5390 audio::HalRadicalAdpcmDecodeStream::vfunc_11 (212 B)
// [TODO] 0x006F5470 audio::HalRadicalAdpcmDecodeStream::vfunc_08 (65 B)
// ============================================================================
// [VERIFIED] audio::HalRadicalAdpcmDecodeStream::vfunc_00 (0x006F54C0, 32 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as audio::HalRadicalAdpcmDecodeStream::vfunc_00 (Proto 0x002AD350), which was matched first;
// its addresses and names were swapped for this function's.
// audio::HalRadicalAdpcmDecodeStream::vfunc_00 (Proto 0x006F54C0, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field04
{
    virtual void vfunc_00();
};

struct Object
{
    virtual void vfunc_00();
    virtual int vfunc_01();
};

namespace audio {

class HalRadicalAdpcmDecodeStream
{
public:
    virtual void vfunc_00();
    Field04* m_Field04; // +0x04
    char m_pad08[0x14];
    int m_Field1C; // +0x1C
};

void HalRadicalAdpcmDecodeStream::vfunc_00()
{
    Field04* t1;

    t1 = m_Field04;
    m_Field1C = 1;
    if (!((Object*)(int)t1)->vfunc_01()) {
        m_Field04->vfunc_00();
        return;
    }
}

}

// [TODO] 0x006F54E0 audio::HalRadicalAdpcmDecodeStream::vfunc_01 (56 B)
// [TODO] 0x006F5520 audio::HalRadicalAdpcmDecodeStream::vfunc_03 (56 B)
// [TODO] 0x006F5560 audio::HalRadicalAdpcmDecodeStream::vfunc_04 (53 B)
// [TODO] 0x006F55A0 audio::HalRadicalAdpcmDecodeStream::vfunc_07 (82 B)
// [TODO] 0x006F5600 audio::HalRadicalAdpcmDecodeStream::vfunc_06 (89 B)
// ============================================================================
// [VERIFIED] audio::HalRadicalAdpcmDecodeStream::vfunc_17 (0x006F5660, 44 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// What it does: audio::HalRadicalAdpcmDecodeStream's deleting destructor: destroys the object, frees its memory when asked (flag bit 0), and returns it.
// ============================================================================
// Same machine code as audio::HalRadicalAdpcmDecodeStream::vfunc_13 (Proto 0x002AD500), which was matched first;
// its addresses and names were swapped for this function's.
// audio::HalRadicalAdpcmDecodeStream::vfunc_17 (Proto 0x006F5660, 44 bytes)
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
};

extern "C" char DAT_00772D64[];
extern "C" char DAT_007F6DBC[];
extern "C" void __cdecl sub_006EE890(int, int);

namespace audio {

class HalRadicalAdpcmDecodeStream
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
    virtual HalRadicalAdpcmDecodeStream* vfunc_17(int a1);
    int m_Field04; // +0x04
};

HalRadicalAdpcmDecodeStream* HalRadicalAdpcmDecodeStream::vfunc_17(int a1)
{
    int t1;

    t1 = m_Field04;
    *(int*)this = (int)DAT_00772D64;
    ((Object*)t1)->vfunc_12();
    if (a1 & 1) {
        sub_006EE890((int)DAT_007F6DBC, (int)this);
    }
    return this;
}

}

// [TODO] 0x006F5690 sub_006F5690 (72 B)
// [TODO] 0x006F56E0 sub_006F56E0 (69 B)
// ============================================================================
// [VERIFIED] audio::SeqEvent::vfunc_00 (0x006F5740, 18 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as audio::SeqEvent::vfunc_00 (0x002D6A00), which was matched first;
// its addresses and names were swapped for this function's.
// audio::SeqEvent::vfunc_00 (0x006F5740, 18 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __cdecl sub_006FF600(int, int);

namespace audio {

class SeqEvent
{
public:
    virtual void vfunc_00(int a1);
};

void SeqEvent::vfunc_00(int a1)
{
    sub_006FF600(a1, 0);
}

}

// [TODO] 0x006F5760 audio::SeqEvent::vfunc_01 (51 B)
// ============================================================================
// [VERIFIED] sub_006F57A0 (0x006F57A0, 15 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_002D6A60 (0x002D6A60), which was matched first;
// its addresses and names were swapped for this function's.
// sub_006F57A0 (0x006F57A0, 15 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

class Class_006F57A0
{
public:
    int sub_006F57A0(int a1, int a2);
    char m_pad00[0xC];
    int m_Field0C; // +0x0C
};

int Class_006F57A0::sub_006F57A0(int a1, int a2)
{
    if (m_Field0C != a1) {
        m_Field0C = a1;
    }
    return a1;
}

// [TODO] 0x006F57B0 audio::SeqActionChannelSendVolumes::vfunc_05 (38 B)
// ============================================================================
// [VERIFIED] audio::SeqActionChannelSendVolumes::vfunc_02 (0x006F57E0, 16 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G7 /Gd /GR /EHsc /Zp4
// ============================================================================
// bin: pc
// va: 0x006F57E0
// what: 
// tool: the portal's starter code (no AI)

// audio::SeqActionChannelSendVolumes::vfunc_02 (PC 0x006F57E0, 16 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

namespace audio {

class SeqActionChannelSendVolumes
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual int vfunc_02(int a1, int a2);
    char m_pad04[0x8];
    int m_Field0C; // +0x0C
};

int SeqActionChannelSendVolumes::vfunc_02(int a1, int a2)
{
    if (m_Field0C != 1) {
        m_Field0C = 1;
    }
    return 1;
}

}

// ============================================================================
// [VERIFIED] audio::SeqActionChannelSendVolumes::vfunc_01 (0x006F57F0, 32 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G7 /Gd /GR /EHsc /Zp4
// ============================================================================
// bin: pc
// va: 0x006F57F0
// what: 
// tool: the portal's starter code (no AI)

// audio::SeqActionChannelSendVolumes::vfunc_01 (PC 0x006F57F0, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

namespace audio {

class SeqActionChannelSendVolumes
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01(int a1);
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual void vfunc_05();
    virtual void vfunc_06(int);
    char m_pad04[0x8];
    int m_Field0C; // +0x0C
};

void SeqActionChannelSendVolumes::vfunc_01(int a1)
{
    vfunc_06(a1);
    if (m_Field0C) {
        m_Field0C = 0;
    }
}

}

// ============================================================================
// [VERIFIED] audio::SeqActionChannelSendVolumes::vfunc_03 (0x006F5810, 16 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G7 /Gd /GR /EHsc /Zp4
// ============================================================================
// bin: pc
// va: 0x006F5810
// what: 
// tool: the portal's starter code (no AI)

// audio::SeqActionChannelSendVolumes::vfunc_03 (PC 0x006F5810, 16 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

namespace audio {

class SeqActionChannelSendVolumes
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual int vfunc_03(int a1);
    char m_pad04[0x8];
    int m_Field0C; // +0x0C
};

int SeqActionChannelSendVolumes::vfunc_03(int a1)
{
    if (m_Field0C != 4) {
        m_Field0C = 4;
    }
    return 4;
}

}

// ============================================================================
// [VERIFIED] audio::SeqActionChannelSendVolumes::vfunc_04 (0x006F5820, 16 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G7 /Gd /GR /EHsc /Zp4
// ============================================================================
// bin: pc
// va: 0x006F5820
// what: 
// tool: the portal's starter code (no AI)

// audio::SeqActionChannelSendVolumes::vfunc_04 (PC 0x006F5820, 16 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

namespace audio {

class SeqActionChannelSendVolumes
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual int vfunc_04(int a1);
    char m_pad04[0x8];
    int m_Field0C; // +0x0C
};

int SeqActionChannelSendVolumes::vfunc_04(int a1)
{
    if (m_Field0C != 5) {
        m_Field0C = 5;
    }
    return 5;
}

}

// ============================================================================
// [VERIFIED] audio::SeqEvent::vfunc_04 (0x006F5830, 31 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as core::BaseObject::vfunc_00 (0x00026BB0), which was matched first;
// its addresses and names were swapped for this function's.
// audio::SeqEvent::vfunc_04 (0x006F5830, 31 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_00772DC8[];
extern "C" void __cdecl sub_0043CE70(int);

namespace audio {

class SeqEvent
{
public:
    virtual SeqEvent* vfunc_04(int a1);
};

SeqEvent* SeqEvent::vfunc_04(int a1)
{
    *(int*)this = (int)DAT_00772DC8;
    if (a1 & 1) {
        sub_0043CE70((int)this);
    }
    return this;
}

}

// ============================================================================
// [VERIFIED] sub_006F5850 (0x006F5850, 9 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00087E60 (0x00087E60), which was matched first;
// its addresses and names were swapped for this function's.
// sub_006F5850 (0x006F5850, 9 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_00772DC8[];

class Class_006F5850
{
public:
    Class_006F5850* sub_006F5850();
    int m_Field00; // +0x00
};

Class_006F5850* Class_006F5850::sub_006F5850()
{
    m_Field00 = (int)DAT_00772DC8;
    return this;
}

// [TODO] 0x006F5860 sub_006F5860 (227 B)
// [TODO] 0x006F5950 om::TRbTree<audio::SeqEventTypeBase, 4>::Comp<audio::SeqEventTypeBase, 4, om::String>::vfunc_00 (86 B)
// ============================================================================
// [VERIFIED] sub_006F59B0 (0x006F59B0, 40 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_0029E9F0 (Proto 0x0029E9F0), which was matched first;
// its addresses and names were swapped for this function's.
// sub_006F59B0 (Proto 0x006F59B0, 40 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field20
{
    void sub_006EBBD0();
};

struct Object
{
    void sub_006F2A40(int);
};

extern "C" char DAT_00772DEC[];
extern "C" Object DAT_0085D4D8;

class Class_006F59B0
{
public:
    void sub_006F59B0();
    int m_Field00; // +0x00
    int m_Field04; // +0x04
    char m_pad08[0xC];
    Field20 m_Field14; // +0x14
    char m_pad15[0xB];
    Field20 m_Field20; // +0x20
};

void Class_006F59B0::sub_006F59B0()
{
    m_Field00 = (int)DAT_00772DEC;
    DAT_0085D4D8.sub_006F2A40((int)(&m_Field04));
    m_Field20.sub_006EBBD0();
    m_Field14.sub_006EBBD0();
}

// [TODO] 0x006F59E0 sub_006F59E0 (119 B)
// [TODO] 0x006F5A60 audio::SeqEventContainer::vfunc_00 (90 B)
// [TODO] 0x006F5AC0 audio::SeqEventContainer::vfunc_01 (173 B)
// [TODO] 0x006F5B70 audio::SeqEventContainer::vfunc_05 (59 B)
// ============================================================================
// [VERIFIED] audio::SeqEventTypeBase::vfunc_00 (0x006F5C10, 61 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// What it does: audio::SeqEventTypeBase's deleting destructor: destroys the object, frees its memory when asked (flag bit 0), and returns it.
// ============================================================================
// Same machine code as audio::SeqEventTypeBase::vfunc_00 (Proto 0x0029EE70), which was matched first;
// its addresses and names were swapped for this function's.
// audio::SeqEventTypeBase::vfunc_00 (Proto 0x006F5C10, 61 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field20
{
    void sub_006EBBD0();
};

struct Object
{
    void sub_006F2A40(int);
};

extern "C" char DAT_00772DEC[];
extern "C" Object DAT_0085D4D8;
extern "C" void __cdecl sub_0043CE70(int);

namespace audio {

class SeqEventTypeBase
{
public:
    virtual SeqEventTypeBase* vfunc_00(int a1);
    int m_Field04; // +0x04
    char m_pad08[0xC];
    Field20 m_Field14; // +0x14
    char m_pad15[0xB];
    Field20 m_Field20; // +0x20
};

SeqEventTypeBase* SeqEventTypeBase::vfunc_00(int a1)
{
    *(int*)this = (int)DAT_00772DEC;
    DAT_0085D4D8.sub_006F2A40((int)(&m_Field04));
    m_Field20.sub_006EBBD0();
    m_Field14.sub_006EBBD0();
    if (a1 & 1) {
        sub_0043CE70((int)this);
    }
    return this;
}

}

// [TODO] 0x006F5C50 sub_006F5C50 (61 B)
// ============================================================================
// [VERIFIED] audio::SeqEventContainer::vfunc_04 (0x006F5C90, 30 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as CollisionManager::CollisionManagerFlowClient::vfunc_00 (0x00016060), which was matched first;
// its addresses and names were swapped for this function's.
// audio::SeqEventContainer::vfunc_04 (0x006F5C90, 30 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __cdecl sub_006F5C50(void);
extern "C" void __cdecl sub_0043CE70(int);

namespace audio {

class SeqEventContainer
{
public:
    virtual SeqEventContainer* vfunc_04(int a1);
};

SeqEventContainer* SeqEventContainer::vfunc_04(int a1)
{
    sub_006F5C50();
    if (a1 & 1) {
        sub_0043CE70((int)this);
    }
    return this;
}

}

// ============================================================================
// [VERIFIED] sub_006F5CB0 (0x006F5CB0, 13 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_0007F7F0 (0x0007F7F0), which was matched first;
// its addresses and names were swapped for this function's.
// sub_006F5CB0 (0x006F5CB0, 13 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_007F6E60[];
extern "C" void __stdcall sub_006EE870(int);

class Class_006F5CB0
{
public:
    void sub_006F5CB0(int a1);
};

void Class_006F5CB0::sub_006F5CB0(int a1)
{
    a1 = (int)DAT_007F6E60;
    sub_006EE870(a1);
}

// ============================================================================
// [VERIFIED] sub_006F5CC0 (0x006F5CC0, 19 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00081980 (0x00081980), which was matched first;
// its addresses and names were swapped for this function's.
// sub_006F5CC0 (0x006F5CC0, 19 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_007F6E60[];
extern "C" void __cdecl sub_006EE890(int, int);

void __cdecl sub_006F5CC0(int a1)
{
    sub_006EE890((int)DAT_007F6E60, a1);
}

// [TODO] 0x006F5CE0 sub_006F5CE0 (130 B)
// [TODO] 0x006F5D70 sub_006F5D70 (291 B)
// [TODO] 0x006F5EA0 sub_006F5EA0 (190 B)
// ============================================================================
// [VERIFIED] sub_006F5F60 (0x006F5F60, 19 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_002D7240 (0x002D7240), which was matched first;
// its addresses and names were swapped for this function's.
// sub_006F5F60 (0x006F5F60, 19 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_006F2C00(int);
};

class Class_006F5F60
{
public:
    void sub_006F5F60(int a1);
};

void Class_006F5F60::sub_006F5F60(int a1)
{
    a1 = a1 + 20;
    ((Object*)(int)this + 40)->sub_006F2C00(a1);
}

// ============================================================================
// [VERIFIED] sub_006F5F80 (0x006F5F80, 19 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_002D7240 (0x002D7240), which was matched first;
// its addresses and names were swapped for this function's.
// sub_006F5F80 (0x006F5F80, 19 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_006F2C40(int);
};

class Class_006F5F80
{
public:
    void sub_006F5F80(int a1);
};

void Class_006F5F80::sub_006F5F80(int a1)
{
    a1 = a1 + 20;
    ((Object*)(int)this + 40)->sub_006F2C40(a1);
}

// ============================================================================
// [VERIFIED] sub_006F5FA0 (0x006F5FA0, 53 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G7 /Gd /GR /EHsc /Zp4
// ============================================================================
// bin: pc
// va: 0x006F5FA0
// what: 
// tool: the portal's starter code (no AI)

// sub_006F5FA0 (PC 0x006F5FA0, 53 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field14
{
    void sub_006F2C00(int);
};

struct Object
{
    void sub_006EE060();
    void sub_006EE080();
};

class Class_006F5FA0
{
public:
    void sub_006F5FA0(int a1);
    char m_pad00[0x14];
    Field14 m_Field14; // +0x14
    char m_pad15[0x1F];
    unsigned char m_Field34; // +0x34
    unsigned char m_Field35; // +0x35
};

void Class_006F5FA0::sub_006F5FA0(int a1)
{
    m_Field14.sub_006F2C00(a1 + 16);
    if (m_Field35) {
        ((Object*)*(int*)(a1 + 32))->sub_006EE060();
    }
    if (m_Field34) {
        ((Object*)*(int*)(a1 + 32))->sub_006EE080();
    }
}

// ============================================================================
// [VERIFIED] sub_006F5FE0 (0x006F5FE0, 53 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G7 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_006F5FA0 (PC 0x006F5FA0), which was matched first;
// its addresses and names were swapped for this function's.
// bin: pc
// va: 0x006F5FE0
// what: 
// tool: the portal's starter code (no AI)

// sub_006F5FE0 (PC 0x006F5FE0, 53 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field14
{
    void sub_006F2C40(int);
};

struct Object
{
    void sub_006EE070();
    void sub_006EE090();
};

class Class_006F5FE0
{
public:
    void sub_006F5FE0(int a1);
    char m_pad00[0x14];
    Field14 m_Field14; // +0x14
    char m_pad15[0x1F];
    unsigned char m_Field34; // +0x34
    unsigned char m_Field35; // +0x35
};

void Class_006F5FE0::sub_006F5FE0(int a1)
{
    m_Field14.sub_006F2C40(a1 + 16);
    if (m_Field35) {
        ((Object*)*(int*)(a1 + 32))->sub_006EE070();
    }
    if (m_Field34) {
        ((Object*)*(int*)(a1 + 32))->sub_006EE090();
    }
}

// ============================================================================
// [VERIFIED] audio::Mix::vfunc_12 (0x006F6060, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as core::MemoryAllocatorMalloc::vfunc_12 (0x0028D100), which was matched first;
// its addresses and names were swapped for this function's.
// audio::Mix::vfunc_12 (0x006F6060, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_00811DA8;

namespace audio {

class Mix
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
    virtual int vfunc_12();
};

int Mix::vfunc_12()
{
    return DAT_00811DA8;
}

}

// ============================================================================
// [VERIFIED] sub_006F6070 (0x006F6070, 38 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_002D7350 (0x002D7350), which was matched first;
// its addresses and names were swapped for this function's.
struct Object
{
    void sub_006EE060();
};

// The links sit 0x10 bytes into each item.
struct Link
{
    Link* next;
};

struct Item
{
    char m_pad00[0x10];
    Link m_link;       // +0x10
    char m_pad14[0xC];
    Object* m_object;  // +0x20
};

static inline Item* ItemOf(Link* link)
{
    return link ? (Item*)((char*)link - 0x10) : 0;
}

class Class_006F6070
{
public:
    void sub_006F6070();

    char m_pad00[0x14];
    Link* m_first; // +0x14
};

// Walks the item list and calls the same method on each item's object.
void Class_006F6070::sub_006F6070()
{
    if (m_first) {
        for (Item* item = (Item*)((char*)m_first - 0x10); item; item = ItemOf(item->m_link.next))
            item->m_object->sub_006EE060();
    }
}

// ============================================================================
// [VERIFIED] sub_006F60A0 (0x006F60A0, 38 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_002D7350 (0x002D7350), which was matched first;
// its addresses and names were swapped for this function's.
struct Object
{
    void sub_006EE070();
};

// The links sit 0x10 bytes into each item.
struct Link
{
    Link* next;
};

struct Item
{
    char m_pad00[0x10];
    Link m_link;       // +0x10
    char m_pad14[0xC];
    Object* m_object;  // +0x20
};

static inline Item* ItemOf(Link* link)
{
    return link ? (Item*)((char*)link - 0x10) : 0;
}

class Class_006F60A0
{
public:
    void sub_006F60A0();

    char m_pad00[0x14];
    Link* m_first; // +0x14
};

// Walks the item list and calls the same method on each item's object.
void Class_006F60A0::sub_006F60A0()
{
    if (m_first) {
        for (Item* item = (Item*)((char*)m_first - 0x10); item; item = ItemOf(item->m_link.next))
            item->m_object->sub_006EE070();
    }
}

// ============================================================================
// [VERIFIED] sub_006F60D0 (0x006F60D0, 38 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_002D7350 (0x002D7350), which was matched first;
// its addresses and names were swapped for this function's.
struct Object
{
    void sub_006EE080();
};

// The links sit 0x10 bytes into each item.
struct Link
{
    Link* next;
};

struct Item
{
    char m_pad00[0x10];
    Link m_link;       // +0x10
    char m_pad14[0xC];
    Object* m_object;  // +0x20
};

static inline Item* ItemOf(Link* link)
{
    return link ? (Item*)((char*)link - 0x10) : 0;
}

class Class_006F60D0
{
public:
    void sub_006F60D0();

    char m_pad00[0x14];
    Link* m_first; // +0x14
};

// Walks the item list and calls the same method on each item's object.
void Class_006F60D0::sub_006F60D0()
{
    if (m_first) {
        for (Item* item = (Item*)((char*)m_first - 0x10); item; item = ItemOf(item->m_link.next))
            item->m_object->sub_006EE080();
    }
}

// ============================================================================
// [VERIFIED] sub_006F6100 (0x006F6100, 38 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_002D7350 (0x002D7350), which was matched first;
// its addresses and names were swapped for this function's.
struct Object
{
    void sub_006EE090();
};

// The links sit 0x10 bytes into each item.
struct Link
{
    Link* next;
};

struct Item
{
    char m_pad00[0x10];
    Link m_link;       // +0x10
    char m_pad14[0xC];
    Object* m_object;  // +0x20
};

static inline Item* ItemOf(Link* link)
{
    return link ? (Item*)((char*)link - 0x10) : 0;
}

class Class_006F6100
{
public:
    void sub_006F6100();

    char m_pad00[0x14];
    Link* m_first; // +0x14
};

// Walks the item list and calls the same method on each item's object.
void Class_006F6100::sub_006F6100()
{
    if (m_first) {
        for (Item* item = (Item*)((char*)m_first - 0x10); item; item = ItemOf(item->m_link.next))
            item->m_object->sub_006EE090();
    }
}

// [TODO] 0x006F6130 sub_006F6130 (66 B)
// [TODO] 0x006F6180 audio::MixStrip::vfunc_01 (143 B)
// [TODO] 0x006F6210 audio::Mix::vfunc_07 (158 B)
// [TODO] 0x006F62B0 om::TRbTree<audio::MixStrip, 4>::Comp<audio::MixStrip, 4, om::Name<om::CaseSensitive32BitKey>>::vfunc_00 (40 B)
// [TODO] 0x006F62E0 sub_006F62E0 (163 B)
// [TODO] 0x006F6390 sub_006F6390 (160 B)
// [TODO] 0x006F6430 sub_006F6430 (44 B)
// [TODO] 0x006F6460 audio::MixStrip::vfunc_00 (283 B)
// [TODO] 0x006F6580 audio::Mix::vfunc_06 (288 B)
// ============================================================================
// [VERIFIED] audio::Mix::vfunc_05 (0x006F66A0, 24 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as audio::Mix::vfunc_05 (0x002D7990), which was matched first;
// its addresses and names were swapped for this function's.
// audio::Mix::vfunc_05 (0x006F66A0, 24 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __cdecl sub_006F6430(void);

namespace audio {

class Mix
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual void vfunc_05(int a1);
    virtual void vfunc_06(int);
};

void Mix::vfunc_05(int a1)
{
    sub_006F6430();
    vfunc_06(a1);
}

}

// [TODO] 0x006F66C0 audio::Mix::vfunc_03 (74 B)
// ============================================================================
// [VERIFIED] om::MetaType<audio::ListenerEffectWin32>::vfunc_00 (0x006F6710, 36 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as om::MetaType<audio::SeqEvent>::vfunc_00 (0x002D0EA0), which was matched first;
// its addresses and names were swapped for this function's.
// om::MetaType<audio::ListenerEffectWin32>::vfunc_00 (0x006F6710, 36 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_00772E90[];
extern "C" void __cdecl sub_006EC7B0(int);
extern "C" void __cdecl sub_006ECB50(void);

namespace audio { class ListenerEffectWin32; }

namespace om { 
template <class T0> class MetaType
{
public:
    virtual MetaType<audio::ListenerEffectWin32>* vfunc_00(int a1);
};
}

template <> om::MetaType<audio::ListenerEffectWin32>* om::MetaType<audio::ListenerEffectWin32>::vfunc_00(int a1)
{
    *(int*)this = (int)DAT_00772E90;
    sub_006ECB50();
    if (a1 & 1) {
        sub_006EC7B0((int)this);
    }
    return this;
}

// ============================================================================
// [VERIFIED] sub_006F6740 (0x006F6740, 102 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00065340 (0x00065340), which was matched first;
// its addresses and names were swapped for this function's.
// sub_006F6740 (0x006F6740, 102 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_006ECAC0(int, int);
};

extern "C" char DAT_00772E90[];
extern "C" char DAT_00772EA0[];
extern "C" int DAT_0085D4EC;
extern "C" int __cdecl sub_006EC7A0(int);

class Class_006F6740
{
public:
    Class_006F6740* sub_006F6740(int a1, int a2, int a3, int a4);
    void sub_006ED350(int, int, int, int);
    int m_Field00; // +0x00
};

Class_006F6740* Class_006F6740::sub_006F6740(int a1, int a2, int a3, int a4)
{
    int t2;

    sub_006ED350(a1, a2, a3, a4);
    m_Field00 = (int)DAT_00772EA0;
    t2 = sub_006EC7A0(88);
    if (t2) {
        ((Object*)t2)->sub_006ECAC0(a1, 0);
        *(int*)t2 = (int)DAT_00772E90;
        DAT_0085D4EC = t2;
        return this;
    }
    DAT_0085D4EC = 0;
    return this;
}

// ============================================================================
// [VERIFIED] om::EntityType<audio::ListenerEffectWin32>::vfunc_03 (0x006F67B0, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as om::EntityType<audio::Mix>::vfunc_03 (0x002D0FD0), which was matched first;
// its addresses and names were swapped for this function's.
// om::EntityType<audio::ListenerEffectWin32>::vfunc_03 (0x006F67B0, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_007C5AF8[];

namespace audio { class ListenerEffectWin32; }

namespace om { 
template <class T0> class EntityType
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void* vfunc_03();
};
}

template <> void* om::EntityType<audio::ListenerEffectWin32>::vfunc_03()
{
    return DAT_007C5AF8;
}

// ============================================================================
// [VERIFIED] om::EntityType<audio::ListenerEffectWin32>::vfunc_02 (0x006F67C0, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as om::EntityType<audio::Mix>::vfunc_02 (0x002D0FE0), which was matched first;
// its addresses and names were swapped for this function's.
// om::EntityType<audio::ListenerEffectWin32>::vfunc_02 (0x006F67C0, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_0085D4EC;

namespace audio { class ListenerEffectWin32; }

namespace om { 
template <class T0> class EntityType
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual int vfunc_02();
};
}

template <> int om::EntityType<audio::ListenerEffectWin32>::vfunc_02()
{
    return DAT_0085D4EC;
}

// ============================================================================
// [VERIFIED] om::EntityType<audio::Mix>::vfunc_00 (0x006F67D0, 30 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as FightTree::FightActionController<fight::EnterExitScriptTrack>::vfunc_03 (0x000227A0), which was matched first;
// its addresses and names were swapped for this function's.
// om::EntityType<audio::Mix>::vfunc_00 (0x006F67D0, 30 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __cdecl sub_006ED0A0(void);
extern "C" void __cdecl sub_0043CE70(int);

namespace audio { class Mix; }

namespace om { 
template <class T0> class EntityType
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual EntityType<audio::Mix>* vfunc_00(int a1);
};
}

template <> om::EntityType<audio::Mix>* om::EntityType<audio::Mix>::vfunc_00(int a1)
{
    sub_006ED0A0();
    if (a1 & 1) {
        sub_0043CE70((int)this);
    }
    return this;
}

// [TODO] 0x006F67F0 om::EntityType<audio::ListenerEffectWin32>::vfunc_01 (62 B)
// ============================================================================
// [VERIFIED] audio::ListenerEffectWin32::vfunc_12 (0x006F6830, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as core::MemoryAllocatorMalloc::vfunc_12 (0x0028D100), which was matched first;
// its addresses and names were swapped for this function's.
// audio::ListenerEffectWin32::vfunc_12 (0x006F6830, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_00811DAC;

namespace audio {

class ListenerEffectWin32
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
    virtual int vfunc_12();
};

int ListenerEffectWin32::vfunc_12()
{
    return DAT_00811DAC;
}

}

// [TODO] 0x006F6840 audio::ListenerEffectWin32::vfunc_03 (61 B)
// [TODO] 0x006F6880 sub_006F6880 (155 B)
// ============================================================================
// [VERIFIED] audio::SeqEventNestTrack::vfunc_00 (0x006F6920, 52 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as audio::SeqEventNestTrack::vfunc_01 (0x002D8D00), which was matched first;
// its addresses and names were swapped for this function's.
// audio::SeqEventNestTrack::vfunc_00 (0x006F6920, 52 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" bool __cdecl sub_006ECC20(int, int);
extern "C" bool __stdcall sub_006F5740(int);

namespace audio {

class SeqEventNestTrack
{
public:
    virtual void vfunc_00();
    virtual int vfunc_00(int a1);
};

int SeqEventNestTrack::vfunc_00(int a1)
{
    if (sub_006F5740(a1)) {
        if (!sub_006ECC20(a1, (int)this + 8)) goto L_2D;
        return 1;
    }
L_2D:
    return 0;
}

}

// ============================================================================
// [VERIFIED] audio::SeqEventNestTrack::vfunc_03 (0x006F6960, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// What it does: Returns a value kept in the game's data.
// ============================================================================
// bin: pc
// va: 0x006F6960
// what: Returns a value kept in the game's data.
// tool: Claude Fable 5.2 (look-alike of pc 0x006DF7F0, names and addresses swapped)
// audio::SeqEventNestTrack::vfunc_03 (0x006F6960, 6 bytes)
extern "C" int DAT_0085D4F0;

namespace audio {

class SeqEventNestTrack
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual int vfunc_03();
};

int SeqEventNestTrack::vfunc_03()
{
    return DAT_0085D4F0;
}

}

// ============================================================================
// [VERIFIED] audio::SeqEventNestTrack::vfunc_04 (0x006F6970, 45 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as audio::SeqEventNestTrack::vfunc_04 (0x002D8D90), which was matched first;
// its addresses and names were swapped for this function's.
// audio::SeqEventNestTrack::vfunc_04 (0x006F6970, 45 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field08
{
    void sub_006EBBD0();
};

extern "C" char DAT_007F6FE8[];
extern "C" void __cdecl sub_006EE890(int, int);

namespace audio {

class SeqEventNestTrack
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual SeqEventNestTrack* vfunc_04(int a1);
    void sub_006F5730();
    char m_pad04[0x4];
    Field08 m_Field08; // +0x08
};

SeqEventNestTrack* SeqEventNestTrack::vfunc_04(int a1)
{
    m_Field08.sub_006EBBD0();
    sub_006F5730();
    if (a1 & 1) {
        sub_006EE890((int)DAT_007F6FE8, (int)this);
    }
    return this;
}

}

// [TODO] 0x006F69A0 audio::SeqEventType<audio::SeqEventNestTrack>::vfunc_01 (88 B)
// ============================================================================
// [VERIFIED] sub_006F6A00 (0x006F6A00, 116 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_002D8E20 (0x002D8E20), which was matched first;
// its addresses and names were swapped for this function's.
struct Name
{
    int data[3];
    void sub_006EB7A0(const char* text, int flags);
    void sub_006EBBD0();
};

struct Object
{
    void sub_006F5BB0(Name* a, Name* b);
};

extern "C" char DAT_00772F2C[];
extern "C" char DAT_00772F50[];
extern "C" char DAT_00772F5C[];
extern "C" Object* DAT_0085D4F0;
extern "C" void* __cdecl sub_0043CE00(unsigned int size);

// Makes the single instance: builds it from two names and keeps it in a global (or null).
void __cdecl sub_006F6A00(void)
{
    Name first, second;

    first.sub_006EB7A0(DAT_00772F5C, 0);
    second.sub_006EB7A0(DAT_00772F50, 0);
    Object* made = (Object*)sub_0043CE00(44);
    if (made) {
        made->sub_006F5BB0(&second, &first);
        *(void**)made = DAT_00772F2C;
        DAT_0085D4F0 = made;
    } else {
        DAT_0085D4F0 = 0;
    }
    second.sub_006EBBD0();
    first.sub_006EBBD0();
}

// [TODO] 0x006F6A80 audio::SeqEventNestTrack::vfunc_02 (130 B)
// ============================================================================
// [VERIFIED] audio::SeqAction::vfunc_00 (0x006F6B10, 31 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as core::BaseObject::vfunc_00 (0x00026BB0), which was matched first;
// its addresses and names were swapped for this function's.
// audio::SeqAction::vfunc_00 (0x006F6B10, 31 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_00772F80[];
extern "C" void __cdecl sub_0043CE70(int);

namespace audio {

class SeqAction
{
public:
    virtual SeqAction* vfunc_00(int a1);
};

SeqAction* SeqAction::vfunc_00(int a1)
{
    *(int*)this = (int)DAT_00772F80;
    if (a1 & 1) {
        sub_0043CE70((int)this);
    }
    return this;
}

}

// ============================================================================
// [VERIFIED] audio::SeqActionChannelSendVolumes::vfunc_00 (0x006F6B30, 36 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as SoundManager::SoundPlayerHandle::vfunc_00 (0x00077F00), which was matched first;
// its addresses and names were swapped for this function's.
// audio::SeqActionChannelSendVolumes::vfunc_00 (0x006F6B30, 36 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_00772F80[];
extern "C" char DAT_007F7144[];
extern "C" void __cdecl sub_006EE890(int, int);

namespace audio {

class SeqActionChannelSendVolumes
{
public:
    virtual SeqActionChannelSendVolumes* vfunc_00(int a1);
};

SeqActionChannelSendVolumes* SeqActionChannelSendVolumes::vfunc_00(int a1)
{
    *(int*)this = (int)DAT_00772F80;
    if (a1 & 1) {
        sub_006EE890((int)DAT_007F7144, (int)this);
    }
    return this;
}

}

// ============================================================================
// [VERIFIED] om::DynBehaviour::vfunc_00 (0x006F6B60, 31 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as core::BaseObject::vfunc_00 (0x00026BB0), which was matched first;
// its addresses and names were swapped for this function's.
// om::DynBehaviour::vfunc_00 (0x006F6B60, 31 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_00772F9C[];
extern "C" void __cdecl sub_0043CE70(int);

namespace om {

class DynBehaviour
{
public:
    virtual DynBehaviour* vfunc_00(int a1);
};

DynBehaviour* DynBehaviour::vfunc_00(int a1)
{
    *(int*)this = (int)DAT_00772F9C;
    if (a1 & 1) {
        sub_0043CE70((int)this);
    }
    return this;
}

}

// ============================================================================
// [VERIFIED] audio::SeqEventChannelSendVolumes::vfunc_02 (0x006F6B80, 67 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as audio::SeqEventChannelSendVolumes::vfunc_02 (0x002D8FA0), which was matched first;
// its addresses and names were swapped for this function's.
#include <stddef.h>

struct Object
{
    void sub_007007A0(int);
};

extern "C" char DAT_00772FB4[];
extern "C" char DAT_007F7144[];
extern "C" int __cdecl sub_006EE870(int);

namespace audio {

class SeqEventChannelSendVolumes;

struct Instance
{
    void* m_vtable;
    SeqEventChannelSendVolumes* m_parent;
    int m_unk8;
    int m_unkC;
    bool m_unk10;

    void* operator new(size_t)
    {
        return (void*)sub_006EE870((int)DAT_007F7144);
    }

    Instance(SeqEventChannelSendVolumes* parent)
    {
        m_unkC = 0;
        m_unk10 = false;
        m_parent = parent;
        m_vtable = DAT_00772FB4;
    }
};

class SeqEventChannelSendVolumes
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02(int a1);
    virtual int vfunc_03();
    virtual SeqEventChannelSendVolumes* vfunc_04(int a1);
};

void SeqEventChannelSendVolumes::vfunc_02(int a1)
{
    ((Object*)a1)->sub_007007A0((int)new Instance(this));
}

}

// ============================================================================
// [VERIFIED] audio::ChannelSendVolumeFadeBehaviour::vfunc_00 (0x006F6BD0, 36 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as SoundManager::SoundPlayerHandle::vfunc_00 (0x00077F00), which was matched first;
// its addresses and names were swapped for this function's.
// audio::ChannelSendVolumeFadeBehaviour::vfunc_00 (0x006F6BD0, 36 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_00772F9C[];
extern "C" char DAT_007F714C[];
extern "C" void __cdecl sub_006EE890(int, int);

namespace audio {

class ChannelSendVolumeFadeBehaviour
{
public:
    virtual ChannelSendVolumeFadeBehaviour* vfunc_00(int a1);
};

ChannelSendVolumeFadeBehaviour* ChannelSendVolumeFadeBehaviour::vfunc_00(int a1)
{
    *(int*)this = (int)DAT_00772F9C;
    if (a1 & 1) {
        sub_006EE890((int)DAT_007F714C, (int)this);
    }
    return this;
}

}

// [TODO] 0x006F6C00 audio::ChannelSendVolumeFadeBehaviour::vfunc_01 (403 B)
// [TODO] 0x006F6DA0 sub_006F6DA0 (58 B)
// ============================================================================
// [VERIFIED] sub_006F6DE0 (0x006F6DE0, 116 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_002D8E20 (0x002D8E20), which was matched first;
// its addresses and names were swapped for this function's.
struct Name
{
    int data[3];
    void sub_006EB7A0(const char* text, int flags);
    void sub_006EBBD0();
};

struct Object
{
    void sub_006F5BB0(Name* a, Name* b);
};

extern "C" char DAT_00772FA8[];
extern "C" char DAT_00772FDC[];
extern "C" char DAT_00772FF0[];
extern "C" Object* DAT_0085D4F4;
extern "C" void* __cdecl sub_0043CE00(unsigned int size);

// Makes the single instance: builds it from two names and keeps it in a global (or null).
void __cdecl sub_006F6DE0(void)
{
    Name first, second;

    first.sub_006EB7A0(DAT_00772FF0, 0);
    second.sub_006EB7A0(DAT_00772FDC, 0);
    Object* made = (Object*)sub_0043CE00(44);
    if (made) {
        made->sub_006F5BB0(&second, &first);
        *(void**)made = DAT_00772FA8;
        DAT_0085D4F4 = made;
    } else {
        DAT_0085D4F4 = 0;
    }
    second.sub_006EBBD0();
    first.sub_006EBBD0();
}

// ============================================================================
// [VERIFIED] audio::SeqEventChannelSendVolumes::vfunc_03 (0x006F6EC0, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as audio::SeqEventNestTrack::vfunc_03 (PC 0x006F6960), which was matched first;
// its addresses and names were swapped for this function's.
// bin: pc
// va: 0x006F6EC0
// what: Returns a value kept in the game's data.
// tool: Claude Fable 5.2 (look-alike of pc 0x006DF7F0, names and addresses swapped)
// audio::SeqEventChannelSendVolumes::vfunc_03 (0x006F6EC0, 6 bytes)
extern "C" int DAT_0085D4F4;

namespace audio {

class SeqEventChannelSendVolumes
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual int vfunc_03();
};

int SeqEventChannelSendVolumes::vfunc_03()
{
    return DAT_0085D4F4;
}

}

// ============================================================================
// [VERIFIED] audio::SeqEventChannelSendVolumes::vfunc_04 (0x006F6ED0, 35 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as SoundManager::StatePropSoundPlayer::vfunc_00 (0x00082430), which was matched first;
// its addresses and names were swapped for this function's.
// audio::SeqEventChannelSendVolumes::vfunc_04 (0x006F6ED0, 35 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_007F713C[];
extern "C" void __cdecl sub_006F5730(void);
extern "C" void __cdecl sub_006EE890(int, int);

namespace audio {

class SeqEventChannelSendVolumes
{
public:
    virtual SeqEventChannelSendVolumes* vfunc_04(int a1);
};

SeqEventChannelSendVolumes* SeqEventChannelSendVolumes::vfunc_04(int a1)
{
    sub_006F5730();
    if (a1 & 1) {
        sub_006EE890((int)DAT_007F713C, (int)this);
    }
    return this;
}

}

// [TODO] 0x006F6F00 audio::SeqActionChannelSendVolumes::vfunc_06 (214 B)
// ============================================================================
// [VERIFIED] audio::SeqEventType<audio::SeqEventChannelSendVolumes>::vfunc_01 (0x006F6FE0, 27 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as audio::SeqEventType<audio::SeqEventChannelSendVolumes>::vfunc_01 (0x002D93F0), which was matched first;
// its addresses and names were swapped for this function's.
// audio::SeqEventType<audio::SeqEventChannelSendVolumes>::vfunc_01 (0x006F6FE0, 27 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    int sub_006F6E60();
};

extern "C" char DAT_007F713C[];
extern "C" int __cdecl sub_006EE870(int);

namespace audio { class SeqEventChannelSendVolumes; }

namespace audio { 
template <class T0> class SeqEventType
{
public:
    virtual void vfunc_00();
    virtual int vfunc_01();
};
}

template <> int audio::SeqEventType<audio::SeqEventChannelSendVolumes>::vfunc_01()
{
    int t1;

    t1 = sub_006EE870((int)DAT_007F713C);
    if (t1) {
        return ((Object*)t1)->sub_006F6E60();
    }
    return 0;
}

// [TODO] 0x006F7000 sub_006F7000 (68 B)
// [TODO] 0x006F7050 sub_006F7050 (68 B)
// [TODO] 0x006F70A0 audio::SeqEventChannelSendVolumes::vfunc_01 (88 B)
// ============================================================================
// [VERIFIED] audio::SeqEventChannelSendVolumes::vfunc_00 (0x006F7100, 86 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as audio::SeqEventChannelSendVolumes::vfunc_00 (0x002D9500), which was matched first;
// its addresses and names were swapped for this function's.
// audio::SeqEventChannelSendVolumes::vfunc_00 (0x006F7100, 86 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" bool __cdecl sub_006ED500(int, int);
extern "C" bool __cdecl sub_006F33D0(int, int);
extern "C" bool __stdcall sub_006F5740(int);
extern "C" bool __cdecl sub_006F7050(int, int);

namespace audio {

class SeqEventChannelSendVolumes
{
public:
    virtual int vfunc_00(int a1);
    char m_pad04[0x44];
    int m_Field48; // +0x48
    int m_Field4C; // +0x4C
};

int SeqEventChannelSendVolumes::vfunc_00(int a1)
{
    if (sub_006F5740(a1)) {
        if (!sub_006F33D0(a1, (int)(&m_Field48))) goto L_4F;
        if (!sub_006ED500(a1, (int)(&m_Field4C))) goto L_4F;
        if (!sub_006F7050(a1, (int)this + 8)) goto L_4F;
        return 1;
    }
L_4F:
    return 0;
}

}

// ============================================================================
// [VERIFIED] audio::SeqActionChannelSends::vfunc_00 (0x006F7160, 36 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as SoundManager::SoundPlayerHandle::vfunc_00 (0x00077F00), which was matched first;
// its addresses and names were swapped for this function's.
// audio::SeqActionChannelSends::vfunc_00 (0x006F7160, 36 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_00772F80[];
extern "C" char DAT_007F7200[];
extern "C" void __cdecl sub_006EE890(int, int);

namespace audio {

class SeqActionChannelSends
{
public:
    virtual SeqActionChannelSends* vfunc_00(int a1);
};

SeqActionChannelSends* SeqActionChannelSends::vfunc_00(int a1)
{
    *(int*)this = (int)DAT_00772F80;
    if (a1 & 1) {
        sub_006EE890((int)DAT_007F7200, (int)this);
    }
    return this;
}

}

// ============================================================================
// [VERIFIED] audio::SeqEventChannelSends::vfunc_03 (0x006F71F0, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as audio::SeqEventNestTrack::vfunc_03 (PC 0x006F6960), which was matched first;
// its addresses and names were swapped for this function's.
// bin: pc
// va: 0x006F71F0
// what: Returns a value kept in the game's data.
// tool: Claude Fable 5.2 (look-alike of pc 0x006DF7F0, names and addresses swapped)
// audio::SeqEventChannelSends::vfunc_03 (0x006F71F0, 6 bytes)
extern "C" int DAT_0085D4FC;

namespace audio {

class SeqEventChannelSends
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual int vfunc_03();
};

int SeqEventChannelSends::vfunc_03()
{
    return DAT_0085D4FC;
}

}

// ============================================================================
// [VERIFIED] audio::SeqEventChannelSends::vfunc_04 (0x006F7200, 35 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as SoundManager::StatePropSoundPlayer::vfunc_00 (0x00082430), which was matched first;
// its addresses and names were swapped for this function's.
// audio::SeqEventChannelSends::vfunc_04 (0x006F7200, 35 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_007F71F8[];
extern "C" void __cdecl sub_006F5730(void);
extern "C" void __cdecl sub_006EE890(int, int);

namespace audio {

class SeqEventChannelSends
{
public:
    virtual SeqEventChannelSends* vfunc_04(int a1);
};

SeqEventChannelSends* SeqEventChannelSends::vfunc_04(int a1)
{
    sub_006F5730();
    if (a1 & 1) {
        sub_006EE890((int)DAT_007F71F8, (int)this);
    }
    return this;
}

}

// ============================================================================
// [VERIFIED] audio::SeqEventChannelSends::vfunc_00 (0x006F7230, 72 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as audio::SeqEventChannelSends::vfunc_00 (0x002D9630), which was matched first;
// its addresses and names were swapped for this function's.
// audio::SeqEventChannelSends::vfunc_00 (0x006F7230, 72 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" bool __cdecl sub_006ED500(int, int);
extern "C" bool __cdecl sub_006EC1E0(int, int);
extern "C" bool __stdcall sub_006F5740(int);

namespace audio {

class SeqEventChannelSends
{
public:
    virtual int vfunc_00(int a1);
    char m_pad04[0x104];
    int m_Field108; // +0x108
};

int SeqEventChannelSends::vfunc_00(int a1)
{
    if (sub_006F5740(a1)) {
        if (!sub_006ED500(a1, (int)(&m_Field108))) goto L_41;
        if (!sub_006EC1E0(a1, (int)this + 8)) goto L_41;
        return 1;
    }
L_41:
    return 0;
}

}

// ============================================================================
// [VERIFIED] audio::SeqEventChannelSends::vfunc_02 (0x006F7280, 67 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as audio::SeqEventChannelSendVolumes::vfunc_02 (0x002D8FA0), which was matched first;
// its addresses and names were swapped for this function's.
#include <stddef.h>

struct Object
{
    void sub_007007A0(int);
};

extern "C" char DAT_00773068[];
extern "C" char DAT_007F7200[];
extern "C" int __cdecl sub_006EE870(int);

namespace audio {

class SeqEventChannelSends;

struct Instance
{
    void* m_vtable;
    SeqEventChannelSends* m_parent;
    int m_unk8;
    int m_unkC;
    bool m_unk10;

    void* operator new(size_t)
    {
        return (void*)sub_006EE870((int)DAT_007F7200);
    }

    Instance(SeqEventChannelSends* parent)
    {
        m_unkC = 0;
        m_unk10 = false;
        m_parent = parent;
        m_vtable = DAT_00773068;
    }
};

class SeqEventChannelSends
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02(int a1);
    virtual int vfunc_03();
    virtual SeqEventChannelSends* vfunc_04(int a1);
};

void SeqEventChannelSends::vfunc_02(int a1)
{
    ((Object*)a1)->sub_007007A0((int)new Instance(this));
}

}

// [TODO] 0x006F72D0 audio::SeqActionChannelSends::vfunc_06 (43 B)
// ============================================================================
// [VERIFIED] audio::SeqEventType<audio::SeqEventChannelSends>::vfunc_01 (0x006F7300, 27 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as audio::SeqEventType<audio::SeqEventChannelSendVolumes>::vfunc_01 (0x002D93F0), which was matched first;
// its addresses and names were swapped for this function's.
// audio::SeqEventType<audio::SeqEventChannelSends>::vfunc_01 (0x006F7300, 27 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    int sub_006F7190();
};

extern "C" char DAT_007F71F8[];
extern "C" int __cdecl sub_006EE870(int);

namespace audio { class SeqEventChannelSends; }

namespace audio { 
template <class T0> class SeqEventType
{
public:
    virtual void vfunc_00();
    virtual int vfunc_01();
};
}

template <> int audio::SeqEventType<audio::SeqEventChannelSends>::vfunc_01()
{
    int t1;

    t1 = sub_006EE870((int)DAT_007F71F8);
    if (t1) {
        return ((Object*)t1)->sub_006F7190();
    }
    return 0;
}

// ============================================================================
// [VERIFIED] sub_006F7320 (0x006F7320, 116 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_002D8E20 (0x002D8E20), which was matched first;
// its addresses and names were swapped for this function's.
struct Name
{
    int data[3];
    void sub_006EB7A0(const char* text, int flags);
    void sub_006EBBD0();
};

struct Object
{
    void sub_006F5BB0(Name* a, Name* b);
};

extern "C" char DAT_0077305C[];
extern "C" char DAT_007730A8[];
extern "C" char DAT_007730B8[];
extern "C" Object* DAT_0085D4FC;
extern "C" void* __cdecl sub_0043CE00(unsigned int size);

// Makes the single instance: builds it from two names and keeps it in a global (or null).
void __cdecl sub_006F7320(void)
{
    Name first, second;

    first.sub_006EB7A0(DAT_007730B8, 0);
    second.sub_006EB7A0(DAT_007730A8, 0);
    Object* made = (Object*)sub_0043CE00(44);
    if (made) {
        made->sub_006F5BB0(&second, &first);
        *(void**)made = DAT_0077305C;
        DAT_0085D4FC = made;
    } else {
        DAT_0085D4FC = 0;
    }
    second.sub_006EBBD0();
    first.sub_006EBBD0();
}

// [TODO] 0x006F73A0 audio::SeqEventChannelSends::vfunc_01 (71 B)
// ============================================================================
// [VERIFIED] audio::SeqCommand::vfunc_01 (0x006F73F0, 31 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as core::BaseObject::vfunc_00 (0x00026BB0), which was matched first;
// its addresses and names were swapped for this function's.
// audio::SeqCommand::vfunc_01 (0x006F73F0, 31 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_007730E0[];
extern "C" void __cdecl sub_0043CE70(int);

namespace audio {

class SeqCommand
{
public:
    virtual SeqCommand* vfunc_01(int a1);
};

SeqCommand* SeqCommand::vfunc_01(int a1)
{
    *(int*)this = (int)DAT_007730E0;
    if (a1 & 1) {
        sub_0043CE70((int)this);
    }
    return this;
}

}

// ============================================================================
// [VERIFIED] audio::SeqEventCondition::vfunc_01 (0x006F7410, 64 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as audio::SeqEventCondition::vfunc_01 (0x002D9810), which was matched first;
// its addresses and names were swapped for this function's.
// audio::SeqEventCondition::vfunc_01 (0x006F7410, 64 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" bool __cdecl sub_006ECBD0(int, int);
extern "C" bool __stdcall sub_006F5760(int);

namespace audio {

class SeqEventCondition
{
public:
    virtual void vfunc_00();
    virtual int vfunc_01(int a1);
    bool sub_006F5AC0(int);
};

int SeqEventCondition::vfunc_01(int a1)
{
    if (sub_006F5760(a1)) {
        if (!sub_006F5AC0(a1)) goto L_39;
        if (!sub_006ECBD0(a1, (int)this + 16)) goto L_39;
        return 1;
    }
L_39:
    return 0;
}

}

// ============================================================================
// [VERIFIED] audio::SeqEventConditionElse::vfunc_01 (0x006F7450, 47 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as audio::SeqEventConditionElse::vfunc_01 (0x002D9850), which was matched first;
// its addresses and names were swapped for this function's.
// audio::SeqEventConditionElse::vfunc_01 (0x006F7450, 47 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" bool __stdcall sub_006F5760(int);

namespace audio {

class SeqEventConditionElse
{
public:
    virtual void vfunc_00();
    virtual int vfunc_01(int a1);
    bool sub_006F5AC0(int);
};

int SeqEventConditionElse::vfunc_01(int a1)
{
    if (sub_006F5760(a1)) {
        if (!sub_006F5AC0(a1)) goto L_28;
        return 1;
    }
L_28:
    return 0;
}

}

// ============================================================================
// [VERIFIED] audio::SeqEventCondition::vfunc_00 (0x006F7480, 64 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as audio::SeqEventCondition::vfunc_01 (0x002D9810), which was matched first;
// its addresses and names were swapped for this function's.
// audio::SeqEventCondition::vfunc_00 (0x006F7480, 64 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" bool __cdecl sub_006ECC20(int, int);
extern "C" bool __stdcall sub_006F5740(int);

namespace audio {

class SeqEventCondition
{
public:
    virtual void vfunc_00();
    virtual int vfunc_00(int a1);
    bool sub_006F5A60(int);
};

int SeqEventCondition::vfunc_00(int a1)
{
    if (sub_006F5740(a1)) {
        if (!sub_006F5A60(a1)) goto L_39;
        if (!sub_006ECC20(a1, (int)this + 16)) goto L_39;
        return 1;
    }
L_39:
    return 0;
}

}

// ============================================================================
// [VERIFIED] audio::SeqEventConditionElse::vfunc_00 (0x006F74C0, 47 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as audio::SeqEventConditionElse::vfunc_01 (0x002D9850), which was matched first;
// its addresses and names were swapped for this function's.
// audio::SeqEventConditionElse::vfunc_00 (0x006F74C0, 47 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" bool __stdcall sub_006F5740(int);

namespace audio {

class SeqEventConditionElse
{
public:
    virtual void vfunc_00();
    virtual int vfunc_00(int a1);
    bool sub_006F5A60(int);
};

int SeqEventConditionElse::vfunc_00(int a1)
{
    if (sub_006F5740(a1)) {
        if (!sub_006F5A60(a1)) goto L_28;
        return 1;
    }
L_28:
    return 0;
}

}

// ============================================================================
// [VERIFIED] audio::SeqEventCondition::vfunc_03 (0x006F74F0, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as audio::SeqEventNestTrack::vfunc_03 (PC 0x006F6960), which was matched first;
// its addresses and names were swapped for this function's.
// bin: pc
// va: 0x006F74F0
// what: Returns a value kept in the game's data.
// tool: Claude Fable 5.2 (look-alike of pc 0x006DF7F0, names and addresses swapped)
// audio::SeqEventCondition::vfunc_03 (0x006F74F0, 6 bytes)
extern "C" int DAT_0085D500;

namespace audio {

class SeqEventCondition
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual int vfunc_03();
};

int SeqEventCondition::vfunc_03()
{
    return DAT_0085D500;
}

}

// ============================================================================
// [VERIFIED] audio::SeqEventCondition::vfunc_04 (0x006F7500, 72 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as audio::SeqEventCondition::vfunc_04 (0x002D9900), which was matched first;
// its addresses and names were swapped for this function's.
// audio::SeqEventCondition::vfunc_04 (0x006F7500, 72 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field10
{
    void sub_006EBBD0();
};

struct Object
{
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04(int);
};

extern "C" char DAT_007730EC[];
extern "C" char DAT_007F732C[];
extern "C" void __cdecl sub_006EE890(int, int);

namespace audio {

class SeqEventCondition
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual SeqEventCondition* vfunc_04(int a1);
    void sub_006F5C50();
    char m_pad04[0xC];
    Field10 m_Field10; // +0x10
    char m_pad11[0xB];
    int m_Field1C; // +0x1C
};

SeqEventCondition* SeqEventCondition::vfunc_04(int a1)
{
    int t1;

    t1 = m_Field1C;
    *(int*)this = (int)DAT_007730EC;
    if (m_Field1C) {
        ((Object*)t1)->vfunc_04(1);
        m_Field1C = 0;
    }
    m_Field10.sub_006EBBD0();
    sub_006F5C50();
    if (a1 & 1) {
        sub_006EE890((int)DAT_007F732C, (int)this);
    }
    return this;
}

}

// ============================================================================
// [VERIFIED] audio::SeqCommandCondition::vfunc_01 (0x006F7550, 36 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as SoundManager::SoundPlayerHandle::vfunc_00 (0x00077F00), which was matched first;
// its addresses and names were swapped for this function's.
// audio::SeqCommandCondition::vfunc_01 (0x006F7550, 36 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_007730E0[];
extern "C" char DAT_007F733C[];
extern "C" void __cdecl sub_006EE890(int, int);

namespace audio {

class SeqCommandCondition
{
public:
    virtual SeqCommandCondition* vfunc_01(int a1);
};

SeqCommandCondition* SeqCommandCondition::vfunc_01(int a1)
{
    *(int*)this = (int)DAT_007730E0;
    if (a1 & 1) {
        sub_006EE890((int)DAT_007F733C, (int)this);
    }
    return this;
}

}

// ============================================================================
// [VERIFIED] sub_006F7580 (0x006F7580, 116 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_002D8E20 (0x002D8E20), which was matched first;
// its addresses and names were swapped for this function's.
struct Name
{
    int data[3];
    void sub_006EB7A0(const char* text, int flags);
    void sub_006EBBD0();
};

struct Object
{
    void sub_006F5BB0(Name* a, Name* b);
};

extern "C" char DAT_00773108[];
extern "C" char DAT_00773128[];
extern "C" char DAT_00773134[];
extern "C" Object* DAT_0085D500;
extern "C" void* __cdecl sub_0043CE00(unsigned int size);

// Makes the single instance: builds it from two names and keeps it in a global (or null).
void __cdecl sub_006F7580(void)
{
    Name first, second;

    first.sub_006EB7A0(DAT_00773134, 0);
    second.sub_006EB7A0(DAT_00773128, 0);
    Object* made = (Object*)sub_0043CE00(44);
    if (made) {
        made->sub_006F5BB0(&second, &first);
        *(void**)made = DAT_00773108;
        DAT_0085D500 = made;
    } else {
        DAT_0085D500 = 0;
    }
    second.sub_006EBBD0();
    first.sub_006EBBD0();
}

// ============================================================================
// [VERIFIED] sub_006F7600 (0x006F7600, 116 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_002D8E20 (0x002D8E20), which was matched first;
// its addresses and names were swapped for this function's.
struct Name
{
    int data[3];
    void sub_006EB7A0(const char* text, int flags);
    void sub_006EBBD0();
};

struct Object
{
    void sub_006F5BB0(Name* a, Name* b);
};

extern "C" char DAT_00773114[];
extern "C" char DAT_00773148[];
extern "C" char DAT_00773150[];
extern "C" Object* DAT_0085D504;
extern "C" void* __cdecl sub_0043CE00(unsigned int size);

// Makes the single instance: builds it from two names and keeps it in a global (or null).
void __cdecl sub_006F7600(void)
{
    Name first, second;

    first.sub_006EB7A0(DAT_00773150, 0);
    second.sub_006EB7A0(DAT_00773148, 0);
    Object* made = (Object*)sub_0043CE00(44);
    if (made) {
        made->sub_006F5BB0(&second, &first);
        *(void**)made = DAT_00773114;
        DAT_0085D504 = made;
    } else {
        DAT_0085D504 = 0;
    }
    second.sub_006EBBD0();
    first.sub_006EBBD0();
}

// ============================================================================
// [VERIFIED] audio::SeqEventConditionElse::vfunc_03 (0x006F7680, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as audio::SeqEventNestTrack::vfunc_03 (PC 0x006F6960), which was matched first;
// its addresses and names were swapped for this function's.
// bin: pc
// va: 0x006F7680
// what: Returns a value kept in the game's data.
// tool: Claude Fable 5.2 (look-alike of pc 0x006DF7F0, names and addresses swapped)
// audio::SeqEventConditionElse::vfunc_03 (0x006F7680, 6 bytes)
extern "C" int DAT_0085D504;

namespace audio {

class SeqEventConditionElse
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual int vfunc_03();
};

int SeqEventConditionElse::vfunc_03()
{
    return DAT_0085D504;
}

}

// ============================================================================
// [VERIFIED] audio::SeqEventConditionElse::vfunc_04 (0x006F7690, 35 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as SoundManager::StatePropSoundPlayer::vfunc_00 (0x00082430), which was matched first;
// its addresses and names were swapped for this function's.
// audio::SeqEventConditionElse::vfunc_04 (0x006F7690, 35 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_007F7334[];
extern "C" void __cdecl sub_006F5C50(void);
extern "C" void __cdecl sub_006EE890(int, int);

namespace audio {

class SeqEventConditionElse
{
public:
    virtual SeqEventConditionElse* vfunc_04(int a1);
};

SeqEventConditionElse* SeqEventConditionElse::vfunc_04(int a1)
{
    sub_006F5C50();
    if (a1 & 1) {
        sub_006EE890((int)DAT_007F7334, (int)this);
    }
    return this;
}

}

// [TODO] 0x006F76C0 audio::SeqEventCondition::vfunc_02 (72 B)
// [TODO] 0x006F7710 audio::SeqCommandCondition::vfunc_00 (213 B)
// ============================================================================
// [VERIFIED] audio::SeqEventType<audio::SeqEventConditionElse>::vfunc_01 (0x006F77F0, 58 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as audio::SeqEventType<audio::SeqEventConditionElse>::vfunc_01 (0x002D9BF0), which was matched first;
// its addresses and names were swapped for this function's.
// audio::SeqEventType<audio::SeqEventConditionElse>::vfunc_01 (0x006F77F0, 58 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_006F5850();
};

extern "C" char DAT_0077316C[];
extern "C" char DAT_007F7334[];
extern "C" int __cdecl sub_006EE870(int);

namespace audio { class SeqEventConditionElse; }

namespace audio { 
template <class T0> class SeqEventType
{
public:
    virtual void vfunc_00();
    virtual int vfunc_01();
};
}

template <> int audio::SeqEventType<audio::SeqEventConditionElse>::vfunc_01()
{
    int t1;

    t1 = sub_006EE870((int)DAT_007F7334);
    if (t1) {
        ((Object*)t1)->sub_006F5850();
        *(int*)(t1 + 8) = 0;
        *(int*)(t1 + 12) = 0;
        *(int*)(t1 + 16) = 0;
        *(int*)(t1 + 20) = 0;
        *(int*)t1 = (int)DAT_0077316C;
        return t1;
    }
    return 0;
}

// ============================================================================
// [VERIFIED] audio::SeqEventType<audio::SeqEventCondition>::vfunc_01 (0x006F78C0, 27 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as audio::SeqEventType<audio::SeqEventChannelSendVolumes>::vfunc_01 (0x002D93F0), which was matched first;
// its addresses and names were swapped for this function's.
// audio::SeqEventType<audio::SeqEventCondition>::vfunc_01 (0x006F78C0, 27 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    int sub_006F7830();
};

extern "C" char DAT_007F732C[];
extern "C" int __cdecl sub_006EE870(int);

namespace audio { class SeqEventCondition; }

namespace audio { 
template <class T0> class SeqEventType
{
public:
    virtual void vfunc_00();
    virtual int vfunc_01();
};
}

template <> int audio::SeqEventType<audio::SeqEventCondition>::vfunc_01()
{
    int t1;

    t1 = sub_006EE870((int)DAT_007F732C);
    if (t1) {
        return ((Object*)t1)->sub_006F7830();
    }
    return 0;
}

// ============================================================================
// [VERIFIED] audio::SeqActionWait::vfunc_02 (0x006F78E0, 21 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as audio::SeqActionWait::vfunc_02 (Proto 0x002A3D90), which was matched first;
// its addresses and names were swapped for this function's.
// audio::SeqActionWait::vfunc_02 (Proto 0x006F78E0, 21 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __stdcall sub_006F57A0(int, int);

namespace audio {

class SeqActionWait
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02(int a1, int a2);
};

void SeqActionWait::vfunc_02(int a1, int a2)
{
    a2 = a1;
    a1 = 1;
    sub_006F57A0(a1, a2);
}

}

// ============================================================================
// [VERIFIED] audio::SeqActionWait::vfunc_01 (0x006F7900, 15 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as audio::SeqActionWait::vfunc_01 (Proto 0x002A3DB0), which was matched first;
// its addresses and names were swapped for this function's.
// audio::SeqActionWait::vfunc_01 (Proto 0x006F7900, 15 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __stdcall sub_006F57A0(int, int);

namespace audio {

class SeqActionWait
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01(int a1);
};

void SeqActionWait::vfunc_01(int a1)
{
    sub_006F57A0(3, a1);
}

}

// ============================================================================
// [VERIFIED] audio::SeqActionWait::vfunc_03 (0x006F7910, 15 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as audio::SeqActionWait::vfunc_03 (Proto 0x002A3DC0), which was matched first;
// its addresses and names were swapped for this function's.
// audio::SeqActionWait::vfunc_03 (Proto 0x006F7910, 15 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __stdcall sub_006F57A0(int, int);

namespace audio {

class SeqActionWait
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03(int a1);
};

void SeqActionWait::vfunc_03(int a1)
{
    sub_006F57A0(4, a1);
}

}

// ============================================================================
// [VERIFIED] audio::SeqActionWait::vfunc_04 (0x006F7920, 15 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as audio::SeqActionWait::vfunc_04 (Proto 0x002A3DD0), which was matched first;
// its addresses and names were swapped for this function's.
// audio::SeqActionWait::vfunc_04 (Proto 0x006F7920, 15 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __stdcall sub_006F57A0(int, int);

namespace audio {

class SeqActionWait
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04(int a1);
};

void SeqActionWait::vfunc_04(int a1)
{
    sub_006F57A0(5, a1);
}

}

// ============================================================================
// [VERIFIED] audio::SeqEventWait::vfunc_03 (0x006F7930, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as audio::SeqEventNestTrack::vfunc_03 (PC 0x006F6960), which was matched first;
// its addresses and names were swapped for this function's.
// bin: pc
// va: 0x006F7930
// what: Returns a value kept in the game's data.
// tool: Claude Fable 5.2 (look-alike of pc 0x006DF7F0, names and addresses swapped)
// audio::SeqEventWait::vfunc_03 (0x006F7930, 6 bytes)
extern "C" int DAT_0085D508;

namespace audio {

class SeqEventWait
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual int vfunc_03();
};

int SeqEventWait::vfunc_03()
{
    return DAT_0085D508;
}

}

// ============================================================================
// [VERIFIED] audio::SeqEventWait::vfunc_04 (0x006F7940, 45 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as audio::SeqEventNestTrack::vfunc_04 (0x002D8D90), which was matched first;
// its addresses and names were swapped for this function's.
// audio::SeqEventWait::vfunc_04 (0x006F7940, 45 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field08
{
    void sub_006EBBD0();
};

extern "C" char DAT_007F73CC[];
extern "C" void __cdecl sub_006EE890(int, int);

namespace audio {

class SeqEventWait
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual SeqEventWait* vfunc_04(int a1);
    void sub_006F5730();
    char m_pad04[0x4];
    Field08 m_Field08; // +0x08
};

SeqEventWait* SeqEventWait::vfunc_04(int a1)
{
    m_Field08.sub_006EBBD0();
    sub_006F5730();
    if (a1 & 1) {
        sub_006EE890((int)DAT_007F73CC, (int)this);
    }
    return this;
}

}

// ============================================================================
// [VERIFIED] audio::SeqActionWait::vfunc_00 (0x006F7970, 36 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as SoundManager::SoundPlayerHandle::vfunc_00 (0x00077F00), which was matched first;
// its addresses and names were swapped for this function's.
// audio::SeqActionWait::vfunc_00 (0x006F7970, 36 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_00772F80[];
extern "C" char DAT_007F73D4[];
extern "C" void __cdecl sub_006EE890(int, int);

namespace audio {

class SeqActionWait
{
public:
    virtual SeqActionWait* vfunc_00(int a1);
};

SeqActionWait* SeqActionWait::vfunc_00(int a1)
{
    *(int*)this = (int)DAT_00772F80;
    if (a1 & 1) {
        sub_006EE890((int)DAT_007F73D4, (int)this);
    }
    return this;
}

}

// [TODO] 0x006F79A0 audio::SeqActionWait::vfunc_05 (232 B)
// [TODO] 0x006F7A90 audio::SeqEventType<audio::SeqEventWait>::vfunc_01 (88 B)
// ============================================================================
// [VERIFIED] sub_006F7AF0 (0x006F7AF0, 116 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_002D8E20 (0x002D8E20), which was matched first;
// its addresses and names were swapped for this function's.
struct Name
{
    int data[3];
    void sub_006EB7A0(const char* text, int flags);
    void sub_006EBBD0();
};

struct Object
{
    void sub_006F5BB0(Name* a, Name* b);
};

extern "C" char DAT_00773198[];
extern "C" char DAT_007731EC[];
extern "C" char DAT_007731F4[];
extern "C" Object* DAT_0085D508;
extern "C" void* __cdecl sub_0043CE00(unsigned int size);

// Makes the single instance: builds it from two names and keeps it in a global (or null).
void __cdecl sub_006F7AF0(void)
{
    Name first, second;

    first.sub_006EB7A0(DAT_007731F4, 0);
    second.sub_006EB7A0(DAT_007731EC, 0);
    Object* made = (Object*)sub_0043CE00(44);
    if (made) {
        made->sub_006F5BB0(&second, &first);
        *(void**)made = DAT_00773198;
        DAT_0085D508 = made;
    } else {
        DAT_0085D508 = 0;
    }
    second.sub_006EBBD0();
    first.sub_006EBBD0();
}

// ============================================================================
// [VERIFIED] audio::SeqEventWait::vfunc_02 (0x006F7B70, 67 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as audio::SeqEventChannelSendVolumes::vfunc_02 (0x002D8FA0), which was matched first;
// its addresses and names were swapped for this function's.
#include <stddef.h>

struct Object
{
    void sub_007007A0(int);
};

extern "C" char DAT_007731D4[];
extern "C" char DAT_007F73D4[];
extern "C" int __cdecl sub_006EE870(int);

namespace audio {

class SeqEventWait;

struct Instance
{
    void* m_vtable;
    SeqEventWait* m_parent;
    int m_unk8;
    int m_unkC;
    bool m_unk10;

    void* operator new(size_t)
    {
        return (void*)sub_006EE870((int)DAT_007F73D4);
    }

    Instance(SeqEventWait* parent)
    {
        m_unkC = 0;
        m_unk10 = false;
        m_parent = parent;
        m_vtable = DAT_007731D4;
    }
};

class SeqEventWait
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02(int a1);
    virtual int vfunc_03();
    virtual SeqEventWait* vfunc_04(int a1);
};

void SeqEventWait::vfunc_02(int a1)
{
    ((Object*)a1)->sub_007007A0((int)new Instance(this));
}

}

// ============================================================================
// [VERIFIED] audio::SeqEventWaitBeat::vfunc_00 (0x006F7BC0, 65 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as audio::SeqEventWaitBeat::vfunc_00 (0x002D9FE0), which was matched first;
// its addresses and names were swapped for this function's.
// audio::SeqEventWaitBeat::vfunc_00 (0x006F7BC0, 65 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field08
{
    bool sub_00700D90(int);
};

extern "C" bool __cdecl sub_006ED500(int, int);
extern "C" bool __stdcall sub_006F5740(int);

namespace audio {

class SeqEventWaitBeat
{
public:
    virtual int vfunc_00(int a1);
    char m_pad04[0x4];
    Field08 m_Field08; // +0x08
    char m_pad09[0x7];
    int m_Field10; // +0x10
};

int SeqEventWaitBeat::vfunc_00(int a1)
{
    if (sub_006F5740(a1)) {
        if (!sub_006ED500(a1, (int)(&m_Field10))) goto L_3A;
        if (!m_Field08.sub_00700D90(a1)) goto L_3A;
        return 1;
    }
L_3A:
    return 0;
}

}

// ============================================================================
// [VERIFIED] audio::SeqActionWaitBeat::vfunc_00 (0x006F7C10, 36 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as SoundManager::SoundPlayerHandle::vfunc_00 (0x00077F00), which was matched first;
// its addresses and names were swapped for this function's.
// audio::SeqActionWaitBeat::vfunc_00 (0x006F7C10, 36 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_00772F80[];
extern "C" char DAT_007F7478[];
extern "C" void __cdecl sub_006EE890(int, int);

namespace audio {

class SeqActionWaitBeat
{
public:
    virtual SeqActionWaitBeat* vfunc_00(int a1);
};

SeqActionWaitBeat* SeqActionWaitBeat::vfunc_00(int a1)
{
    *(int*)this = (int)DAT_00772F80;
    if (a1 & 1) {
        sub_006EE890((int)DAT_007F7478, (int)this);
    }
    return this;
}

}

// [TODO] 0x006F7C40 audio::SeqActionWaitBeat::vfunc_05 (93 B)
// ============================================================================
// [VERIFIED] sub_006F7CA0 (0x006F7CA0, 116 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_002D8E20 (0x002D8E20), which was matched first;
// its addresses and names were swapped for this function's.
struct Name
{
    int data[3];
    void sub_006EB7A0(const char* text, int flags);
    void sub_006EBBD0();
};

struct Object
{
    void sub_006F5BB0(Name* a, Name* b);
};

extern "C" char DAT_00773228[];
extern "C" char DAT_0077324C[];
extern "C" char DAT_00773258[];
extern "C" Object* DAT_0085D510;
extern "C" void* __cdecl sub_0043CE00(unsigned int size);

// Makes the single instance: builds it from two names and keeps it in a global (or null).
void __cdecl sub_006F7CA0(void)
{
    Name first, second;

    first.sub_006EB7A0(DAT_00773258, 0);
    second.sub_006EB7A0(DAT_0077324C, 0);
    Object* made = (Object*)sub_0043CE00(44);
    if (made) {
        made->sub_006F5BB0(&second, &first);
        *(void**)made = DAT_00773228;
        DAT_0085D510 = made;
    } else {
        DAT_0085D510 = 0;
    }
    second.sub_006EBBD0();
    first.sub_006EBBD0();
}

// ============================================================================
// [VERIFIED] audio::SeqEventWaitBeat::vfunc_03 (0x006F7D80, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as audio::SeqEventNestTrack::vfunc_03 (PC 0x006F6960), which was matched first;
// its addresses and names were swapped for this function's.
// bin: pc
// va: 0x006F7D80
// what: Returns a value kept in the game's data.
// tool: Claude Fable 5.2 (look-alike of pc 0x006DF7F0, names and addresses swapped)
// audio::SeqEventWaitBeat::vfunc_03 (0x006F7D80, 6 bytes)
extern "C" int DAT_0085D510;

namespace audio {

class SeqEventWaitBeat
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual int vfunc_03();
};

int SeqEventWaitBeat::vfunc_03()
{
    return DAT_0085D510;
}

}

// ============================================================================
// [VERIFIED] audio::SeqEventWaitBeat::vfunc_04 (0x006F7D90, 45 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as audio::SeqEventNestTrack::vfunc_04 (0x002D8D90), which was matched first;
// its addresses and names were swapped for this function's.
// audio::SeqEventWaitBeat::vfunc_04 (0x006F7D90, 45 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field08
{
    void sub_00700EE0();
};

extern "C" char DAT_007F7470[];
extern "C" void __cdecl sub_006EE890(int, int);

namespace audio {

class SeqEventWaitBeat
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual SeqEventWaitBeat* vfunc_04(int a1);
    void sub_006F5730();
    char m_pad04[0x4];
    Field08 m_Field08; // +0x08
};

SeqEventWaitBeat* SeqEventWaitBeat::vfunc_04(int a1)
{
    m_Field08.sub_00700EE0();
    sub_006F5730();
    if (a1 & 1) {
        sub_006EE890((int)DAT_007F7470, (int)this);
    }
    return this;
}

}

// [TODO] 0x006F7DC0 audio::SeqEventWaitBeat::vfunc_01 (67 B)
// [TODO] 0x006F7E10 audio::SeqEventWaitBeat::vfunc_02 (73 B)
// ============================================================================
// [VERIFIED] audio::SeqEventType<audio::SeqEventWaitBeat>::vfunc_01 (0x006F7E60, 27 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as audio::SeqEventType<audio::SeqEventChannelSendVolumes>::vfunc_01 (0x002D93F0), which was matched first;
// its addresses and names were swapped for this function's.
// audio::SeqEventType<audio::SeqEventWaitBeat>::vfunc_01 (0x006F7E60, 27 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    int sub_006F7D20();
};

extern "C" char DAT_007F7470[];
extern "C" int __cdecl sub_006EE870(int);

namespace audio { class SeqEventWaitBeat; }

namespace audio { 
template <class T0> class SeqEventType
{
public:
    virtual void vfunc_00();
    virtual int vfunc_01();
};
}

template <> int audio::SeqEventType<audio::SeqEventWaitBeat>::vfunc_01()
{
    int t1;

    t1 = sub_006EE870((int)DAT_007F7470);
    if (t1) {
        return ((Object*)t1)->sub_006F7D20();
    }
    return 0;
}

// ============================================================================
// [VERIFIED] audio::SeqActionWaitBeat::vfunc_02 (0x006F7E80, 60 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as audio::SeqActionWaitBeat::vfunc_02 (0x002DA2A0), which was matched first;
// its addresses and names were swapped for this function's.
// audio::SeqActionWaitBeat::vfunc_02 (0x006F7E80, 60 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    int sub_006F0D00(int);
};

namespace audio {

class SeqActionWaitBeat
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02(int a1, int a2);
    void sub_006F57A0(int, int);
    int m_Field04; // +0x04
    char m_pad08[0xC];
    int m_Field14; // +0x14
    int m_Field18; // +0x18
};

void SeqActionWaitBeat::vfunc_02(int a1, int a2)
{
    int t2;

    t2 = ((Object*)*(int*)(*(int*)(*(int*)(a1 + 20) + 36) + 52) + 44)->sub_006F0D00(m_Field04 + 16);
    m_Field18 = t2;
    if (t2) {
        m_Field14 = *(int*)(t2 + 56);
    }
    sub_006F57A0(2, a1);
}

}

// ============================================================================
// [VERIFIED] audio::SeqEventNestTrack::vfunc_01 (0x006F7EC0, 52 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as audio::SeqEventNestTrack::vfunc_01 (0x002D8D00), which was matched first;
// its addresses and names were swapped for this function's.
// audio::SeqEventNestTrack::vfunc_01 (0x006F7EC0, 52 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" bool __cdecl sub_006ECBD0(int, int);
extern "C" bool __stdcall sub_006F5760(int);

namespace audio {

class SeqEventNestTrack
{
public:
    virtual void vfunc_00();
    virtual int vfunc_01(int a1);
};

int SeqEventNestTrack::vfunc_01(int a1)
{
    if (sub_006F5760(a1)) {
        if (!sub_006ECBD0(a1, (int)this + 8)) goto L_2D;
        return 1;
    }
L_2D:
    return 0;
}

}

// ============================================================================
// [VERIFIED] audio::SeqActionExpression::vfunc_00 (0x006F7F00, 36 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as SoundManager::SoundPlayerHandle::vfunc_00 (0x00077F00), which was matched first;
// its addresses and names were swapped for this function's.
// audio::SeqActionExpression::vfunc_00 (0x006F7F00, 36 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_00772F80[];
extern "C" char DAT_007F751C[];
extern "C" void __cdecl sub_006EE890(int, int);

namespace audio {

class SeqActionExpression
{
public:
    virtual SeqActionExpression* vfunc_00(int a1);
};

SeqActionExpression* SeqActionExpression::vfunc_00(int a1)
{
    *(int*)this = (int)DAT_00772F80;
    if (a1 & 1) {
        sub_006EE890((int)DAT_007F751C, (int)this);
    }
    return this;
}

}

// ============================================================================
// [VERIFIED] audio::SeqEventExpression::vfunc_03 (0x006F7F30, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as audio::SeqEventNestTrack::vfunc_03 (PC 0x006F6960), which was matched first;
// its addresses and names were swapped for this function's.
// bin: pc
// va: 0x006F7F30
// what: Returns a value kept in the game's data.
// tool: Claude Fable 5.2 (look-alike of pc 0x006DF7F0, names and addresses swapped)
// audio::SeqEventExpression::vfunc_03 (0x006F7F30, 6 bytes)
extern "C" int DAT_0085D518;

namespace audio {

class SeqEventExpression
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual int vfunc_03();
};

int SeqEventExpression::vfunc_03()
{
    return DAT_0085D518;
}

}

// ============================================================================
// [VERIFIED] audio::SeqEventExpression::vfunc_04 (0x006F7F40, 45 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as audio::SeqEventNestTrack::vfunc_04 (0x002D8D90), which was matched first;
// its addresses and names were swapped for this function's.
// audio::SeqEventExpression::vfunc_04 (0x006F7F40, 45 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field08
{
    void sub_006EBBD0();
};

extern "C" char DAT_007F7514[];
extern "C" void __cdecl sub_006EE890(int, int);

namespace audio {

class SeqEventExpression
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual SeqEventExpression* vfunc_04(int a1);
    void sub_006F5730();
    char m_pad04[0x4];
    Field08 m_Field08; // +0x08
};

SeqEventExpression* SeqEventExpression::vfunc_04(int a1)
{
    m_Field08.sub_006EBBD0();
    sub_006F5730();
    if (a1 & 1) {
        sub_006EE890((int)DAT_007F7514, (int)this);
    }
    return this;
}

}

// ============================================================================
// [VERIFIED] audio::SeqEventExpression::vfunc_02 (0x006F7F70, 67 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as audio::SeqEventChannelSendVolumes::vfunc_02 (0x002D8FA0), which was matched first;
// its addresses and names were swapped for this function's.
#include <stddef.h>

struct Object
{
    void sub_007007A0(int);
};

extern "C" char DAT_007732A4[];
extern "C" char DAT_007F751C[];
extern "C" int __cdecl sub_006EE870(int);

namespace audio {

class SeqEventExpression;

struct Instance
{
    void* m_vtable;
    SeqEventExpression* m_parent;
    int m_unk8;
    int m_unkC;
    bool m_unk10;

    void* operator new(size_t)
    {
        return (void*)sub_006EE870((int)DAT_007F751C);
    }

    Instance(SeqEventExpression* parent)
    {
        m_unkC = 0;
        m_unk10 = false;
        m_parent = parent;
        m_vtable = DAT_007732A4;
    }
};

class SeqEventExpression
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02(int a1);
    virtual int vfunc_03();
    virtual SeqEventExpression* vfunc_04(int a1);
};

void SeqEventExpression::vfunc_02(int a1)
{
    ((Object*)a1)->sub_007007A0((int)new Instance(this));
}

}

// [TODO] 0x006F7FC0 audio::SeqActionExpression::vfunc_06 (68 B)
// [TODO] 0x006F8010 audio::SeqEventType<audio::SeqEventExpression>::vfunc_01 (88 B)
// ============================================================================
// [VERIFIED] sub_006F8070 (0x006F8070, 116 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_002D8E20 (0x002D8E20), which was matched first;
// its addresses and names were swapped for this function's.
struct Name
{
    int data[3];
    void sub_006EB7A0(const char* text, int flags);
    void sub_006EBBD0();
};

struct Object
{
    void sub_006F5BB0(Name* a, Name* b);
};

extern "C" char DAT_00773298[];
extern "C" char DAT_007732EC[];
extern "C" char DAT_007732FC[];
extern "C" Object* DAT_0085D518;
extern "C" void* __cdecl sub_0043CE00(unsigned int size);

// Makes the single instance: builds it from two names and keeps it in a global (or null).
void __cdecl sub_006F8070(void)
{
    Name first, second;

    first.sub_006EB7A0(DAT_007732FC, 0);
    second.sub_006EB7A0(DAT_007732EC, 0);
    Object* made = (Object*)sub_0043CE00(44);
    if (made) {
        made->sub_006F5BB0(&second, &first);
        *(void**)made = DAT_00773298;
        DAT_0085D518 = made;
    } else {
        DAT_0085D518 = 0;
    }
    second.sub_006EBBD0();
    first.sub_006EBBD0();
}

// [TODO] 0x006F8140 audio::SeqEventStopTrack::vfunc_01 (103 B)
// ============================================================================
// [VERIFIED] audio::SeqEventStopTrack::vfunc_00 (0x006F81B0, 103 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as audio::SeqEventStopTrack::vfunc_00 (0x002DA590), which was matched first;
// its addresses and names were swapped for this function's.
// audio::SeqEventStopTrack::vfunc_00 (0x006F81B0, 103 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" bool __cdecl sub_006ECC20(int, int);
extern "C" bool __cdecl sub_006F3300(int, int);
extern "C" bool __cdecl sub_006F33D0(int, int);
extern "C" bool __stdcall sub_006F5740(int);

namespace audio {

class SeqEventStopTrack
{
public:
    virtual int vfunc_00(int a1);
    char m_pad04[0x4];
    int m_Field08; // +0x08
    int m_Field0C; // +0x0C
    int m_Field10; // +0x10
};

int SeqEventStopTrack::vfunc_00(int a1)
{
    if (sub_006F5740(a1)) {
        if (!sub_006F33D0(a1, (int)(&m_Field08))) goto L_60;
        if (!sub_006F33D0(a1, (int)(&m_Field0C))) goto L_60;
        if (!sub_006ECC20(a1, (int)(&m_Field10))) goto L_60;
        if (!sub_006F3300(a1, (int)this + 28)) goto L_60;
        return 1;
    }
L_60:
    return 0;
}

}

// ============================================================================
// [VERIFIED] audio::SeqEventType<audio::SeqEventStopTrack>::vfunc_01 (0x006F8220, 27 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as audio::SeqEventType<audio::SeqEventChannelSendVolumes>::vfunc_01 (0x002D93F0), which was matched first;
// its addresses and names were swapped for this function's.
// audio::SeqEventType<audio::SeqEventStopTrack>::vfunc_01 (0x006F8220, 27 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    int sub_006F80F0();
};

extern "C" char DAT_007F75B8[];
extern "C" int __cdecl sub_006EE870(int);

namespace audio { class SeqEventStopTrack; }

namespace audio { 
template <class T0> class SeqEventType
{
public:
    virtual void vfunc_00();
    virtual int vfunc_01();
};
}

template <> int audio::SeqEventType<audio::SeqEventStopTrack>::vfunc_01()
{
    int t1;

    t1 = sub_006EE870((int)DAT_007F75B8);
    if (t1) {
        return ((Object*)t1)->sub_006F80F0();
    }
    return 0;
}

// ============================================================================
// [VERIFIED] audio::SeqEventStopTrack::vfunc_03 (0x006F8240, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as audio::SeqEventNestTrack::vfunc_03 (PC 0x006F6960), which was matched first;
// its addresses and names were swapped for this function's.
// bin: pc
// va: 0x006F8240
// what: Returns a value kept in the game's data.
// tool: Claude Fable 5.2 (look-alike of pc 0x006DF7F0, names and addresses swapped)
// audio::SeqEventStopTrack::vfunc_03 (0x006F8240, 6 bytes)
extern "C" int DAT_0085D51C;

namespace audio {

class SeqEventStopTrack
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual int vfunc_03();
};

int SeqEventStopTrack::vfunc_03()
{
    return DAT_0085D51C;
}

}

// ============================================================================
// [VERIFIED] audio::SeqActionStopTrack::vfunc_00 (0x006F8250, 36 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as SoundManager::SoundPlayerHandle::vfunc_00 (0x00077F00), which was matched first;
// its addresses and names were swapped for this function's.
// audio::SeqActionStopTrack::vfunc_00 (0x006F8250, 36 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_00772F80[];
extern "C" char DAT_007F75C0[];
extern "C" void __cdecl sub_006EE890(int, int);

namespace audio {

class SeqActionStopTrack
{
public:
    virtual SeqActionStopTrack* vfunc_00(int a1);
};

SeqActionStopTrack* SeqActionStopTrack::vfunc_00(int a1)
{
    *(int*)this = (int)DAT_00772F80;
    if (a1 & 1) {
        sub_006EE890((int)DAT_007F75C0, (int)this);
    }
    return this;
}

}

// ============================================================================
// [VERIFIED] audio::SeqEventStopTrack::vfunc_04 (0x006F8280, 45 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// What it does: audio::SeqEventStopTrack's deleting destructor: destroys the object, frees its memory when asked (flag bit 0), and returns it.
// ============================================================================
// Same machine code as audio::SeqEventStopTrack::vfunc_04 (0x002DA660), which was matched first;
// its addresses and names were swapped for this function's.
// audio::SeqEventStopTrack::vfunc_04 (0x006F8280, 45 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field10
{
    void sub_006EBBD0();
};

extern "C" char DAT_007F75B8[];
extern "C" void __cdecl sub_006EE890(int, int);

namespace audio {

class SeqEventStopTrack
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual SeqEventStopTrack* vfunc_04(int a1);
    void sub_006F5730();
    char m_pad04[0xC];
    Field10 m_Field10; // +0x10
};

SeqEventStopTrack* SeqEventStopTrack::vfunc_04(int a1)
{
    m_Field10.sub_006EBBD0();
    sub_006F5730();
    if (a1 & 1) {
        sub_006EE890((int)DAT_007F75B8, (int)this);
    }
    return this;
}

}

// ============================================================================
// [VERIFIED] audio::SeqEventStopTrack::vfunc_02 (0x006F82B0, 67 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as audio::SeqEventChannelSendVolumes::vfunc_02 (0x002D8FA0), which was matched first;
// its addresses and names were swapped for this function's.
#include <stddef.h>

struct Object
{
    void sub_007007A0(int);
};

extern "C" char DAT_00773348[];
extern "C" char DAT_007F75C0[];
extern "C" int __cdecl sub_006EE870(int);

namespace audio {

class SeqEventStopTrack;

struct Instance
{
    void* m_vtable;
    SeqEventStopTrack* m_parent;
    int m_unk8;
    int m_unkC;
    bool m_unk10;

    void* operator new(size_t)
    {
        return (void*)sub_006EE870((int)DAT_007F75C0);
    }

    Instance(SeqEventStopTrack* parent)
    {
        m_unkC = 0;
        m_unk10 = false;
        m_parent = parent;
        m_vtable = DAT_00773348;
    }
};

class SeqEventStopTrack
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02(int a1);
    virtual int vfunc_03();
    virtual SeqEventStopTrack* vfunc_04(int a1);
};

void SeqEventStopTrack::vfunc_02(int a1)
{
    ((Object*)a1)->sub_007007A0((int)new Instance(this));
}

}

// ============================================================================
// [VERIFIED] audio::SeqEventType<audio::SeqEventNestTrack>::vfunc_00 (0x006F8300, 30 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as FightTree::FightActionController<fight::EnterExitScriptTrack>::vfunc_03 (0x000227A0), which was matched first;
// its addresses and names were swapped for this function's.
// audio::SeqEventType<audio::SeqEventNestTrack>::vfunc_00 (0x006F8300, 30 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __cdecl sub_006F59B0(void);
extern "C" void __cdecl sub_0043CE70(int);

namespace audio { class SeqEventNestTrack; }

namespace audio { 
template <class T0> class SeqEventType
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual SeqEventType<audio::SeqEventNestTrack>* vfunc_00(int a1);
};
}

template <> audio::SeqEventType<audio::SeqEventNestTrack>* audio::SeqEventType<audio::SeqEventNestTrack>::vfunc_00(int a1)
{
    sub_006F59B0();
    if (a1 & 1) {
        sub_0043CE70((int)this);
    }
    return this;
}

// ============================================================================
// [VERIFIED] sub_006F8320 (0x006F8320, 116 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_002D8E20 (0x002D8E20), which was matched first;
// its addresses and names were swapped for this function's.
struct Name
{
    int data[3];
    void sub_006EB7A0(const char* text, int flags);
    void sub_006EBBD0();
};

struct Object
{
    void sub_006F5BB0(Name* a, Name* b);
};

extern "C" char DAT_0077333C[];
extern "C" char DAT_00773364[];
extern "C" char DAT_00773370[];
extern "C" Object* DAT_0085D51C;
extern "C" void* __cdecl sub_0043CE00(unsigned int size);

// Makes the single instance: builds it from two names and keeps it in a global (or null).
void __cdecl sub_006F8320(void)
{
    Name first, second;

    first.sub_006EB7A0(DAT_00773370, 0);
    second.sub_006EB7A0(DAT_00773364, 0);
    Object* made = (Object*)sub_0043CE00(44);
    if (made) {
        made->sub_006F5BB0(&second, &first);
        *(void**)made = DAT_0077333C;
        DAT_0085D51C = made;
    } else {
        DAT_0085D51C = 0;
    }
    second.sub_006EBBD0();
    first.sub_006EBBD0();
}

// [TODO] 0x006F83A0 audio::SeqActionStopTrack::vfunc_06 (335 B)
// [TODO] 0x006F84F0 audio::SeqEventPlayTrack::vfunc_01 (103 B)
// ============================================================================
// [VERIFIED] audio::SeqEventPlayTrack::vfunc_00 (0x006F8560, 103 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as audio::SeqEventPlayTrack::vfunc_00 (0x002DA930), which was matched first;
// its addresses and names were swapped for this function's.
// audio::SeqEventPlayTrack::vfunc_00 (0x006F8560, 103 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" bool __cdecl sub_006ECC20(int, int);
extern "C" bool __cdecl sub_006F3300(int, int);
extern "C" bool __cdecl sub_006F33D0(int, int);
extern "C" bool __stdcall sub_006F5740(int);

namespace audio {

class SeqEventPlayTrack
{
public:
    virtual int vfunc_00(int a1);
    char m_pad04[0x4];
    int m_Field08; // +0x08
    int m_Field0C; // +0x0C
    int m_Field10; // +0x10
};

int SeqEventPlayTrack::vfunc_00(int a1)
{
    if (sub_006F5740(a1)) {
        if (!sub_006F33D0(a1, (int)(&m_Field08))) goto L_60;
        if (!sub_006F33D0(a1, (int)(&m_Field0C))) goto L_60;
        if (!sub_006F3300(a1, (int)(&m_Field10))) goto L_60;
        if (!sub_006ECC20(a1, (int)this + 20)) goto L_60;
        return 1;
    }
L_60:
    return 0;
}

}

// ============================================================================
// [VERIFIED] audio::SeqActionPlayTrack::vfunc_00 (0x006F85D0, 36 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as SoundManager::SoundPlayerHandle::vfunc_00 (0x00077F00), which was matched first;
// its addresses and names were swapped for this function's.
// audio::SeqActionPlayTrack::vfunc_00 (0x006F85D0, 36 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_00772F80[];
extern "C" char DAT_007F7664[];
extern "C" void __cdecl sub_006EE890(int, int);

namespace audio {

class SeqActionPlayTrack
{
public:
    virtual SeqActionPlayTrack* vfunc_00(int a1);
};

SeqActionPlayTrack* SeqActionPlayTrack::vfunc_00(int a1)
{
    *(int*)this = (int)DAT_00772F80;
    if (a1 & 1) {
        sub_006EE890((int)DAT_007F7664, (int)this);
    }
    return this;
}

}

// ============================================================================
// [VERIFIED] audio::SeqEventPlayTrack::vfunc_03 (0x006F8650, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as audio::SeqEventNestTrack::vfunc_03 (PC 0x006F6960), which was matched first;
// its addresses and names were swapped for this function's.
// bin: pc
// va: 0x006F8650
// what: Returns a value kept in the game's data.
// tool: Claude Fable 5.2 (look-alike of pc 0x006DF7F0, names and addresses swapped)
// audio::SeqEventPlayTrack::vfunc_03 (0x006F8650, 6 bytes)
extern "C" int DAT_0085D520;

namespace audio {

class SeqEventPlayTrack
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual int vfunc_03();
};

int SeqEventPlayTrack::vfunc_03()
{
    return DAT_0085D520;
}

}

// ============================================================================
// [VERIFIED] audio::SeqEventPlayTrack::vfunc_04 (0x006F8660, 45 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// What it does: audio::SeqEventPlayTrack's deleting destructor: destroys the object, frees its memory when asked (flag bit 0), and returns it.
// ============================================================================
// Same machine code as audio::SeqEventPlayTrack::vfunc_04 (0x002DAA30), which was matched first;
// its addresses and names were swapped for this function's.
// audio::SeqEventPlayTrack::vfunc_04 (0x006F8660, 45 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field14
{
    void sub_006EBBD0();
};

extern "C" char DAT_007F765C[];
extern "C" void __cdecl sub_006EE890(int, int);

namespace audio {

class SeqEventPlayTrack
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual SeqEventPlayTrack* vfunc_04(int a1);
    void sub_006F5730();
    char m_pad04[0x10];
    Field14 m_Field14; // +0x14
};

SeqEventPlayTrack* SeqEventPlayTrack::vfunc_04(int a1)
{
    m_Field14.sub_006EBBD0();
    sub_006F5730();
    if (a1 & 1) {
        sub_006EE890((int)DAT_007F765C, (int)this);
    }
    return this;
}

}

// ============================================================================
// [VERIFIED] audio::SeqEventPlayTrack::vfunc_02 (0x006F8690, 67 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as audio::SeqEventChannelSendVolumes::vfunc_02 (0x002D8FA0), which was matched first;
// its addresses and names were swapped for this function's.
#include <stddef.h>

struct Object
{
    void sub_007007A0(int);
};

extern "C" char DAT_007733A4[];
extern "C" char DAT_007F7664[];
extern "C" int __cdecl sub_006EE870(int);

namespace audio {

class SeqEventPlayTrack;

struct Instance
{
    void* m_vtable;
    SeqEventPlayTrack* m_parent;
    int m_unk8;
    int m_unkC;
    bool m_unk10;

    void* operator new(size_t)
    {
        return (void*)sub_006EE870((int)DAT_007F7664);
    }

    Instance(SeqEventPlayTrack* parent)
    {
        m_unkC = 0;
        m_unk10 = false;
        m_parent = parent;
        m_vtable = DAT_007733A4;
    }
};

class SeqEventPlayTrack
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02(int a1);
    virtual int vfunc_03();
    virtual SeqEventPlayTrack* vfunc_04(int a1);
};

void SeqEventPlayTrack::vfunc_02(int a1)
{
    ((Object*)a1)->sub_007007A0((int)new Instance(this));
}

}

// [TODO] 0x006F86E0 audio::SeqActionPlayTrack::vfunc_06 (187 B)
// ============================================================================
// [VERIFIED] audio::SeqEventType<audio::SeqEventPlayTrack>::vfunc_01 (0x006F87A0, 27 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as audio::SeqEventType<audio::SeqEventChannelSendVolumes>::vfunc_01 (0x002D93F0), which was matched first;
// its addresses and names were swapped for this function's.
// audio::SeqEventType<audio::SeqEventPlayTrack>::vfunc_01 (0x006F87A0, 27 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    int sub_006F8600();
};

extern "C" char DAT_007F765C[];
extern "C" int __cdecl sub_006EE870(int);

namespace audio { class SeqEventPlayTrack; }

namespace audio { 
template <class T0> class SeqEventType
{
public:
    virtual void vfunc_00();
    virtual int vfunc_01();
};
}

template <> int audio::SeqEventType<audio::SeqEventPlayTrack>::vfunc_01()
{
    int t1;

    t1 = sub_006EE870((int)DAT_007F765C);
    if (t1) {
        return ((Object*)t1)->sub_006F8600();
    }
    return 0;
}

// ============================================================================
// [VERIFIED] sub_006F87C0 (0x006F87C0, 116 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_002D8E20 (0x002D8E20), which was matched first;
// its addresses and names were swapped for this function's.
struct Name
{
    int data[3];
    void sub_006EB7A0(const char* text, int flags);
    void sub_006EBBD0();
};

struct Object
{
    void sub_006F5BB0(Name* a, Name* b);
};

extern "C" char DAT_00773398[];
extern "C" char DAT_007733DC[];
extern "C" char DAT_007733E4[];
extern "C" Object* DAT_0085D520;
extern "C" void* __cdecl sub_0043CE00(unsigned int size);

// Makes the single instance: builds it from two names and keeps it in a global (or null).
void __cdecl sub_006F87C0(void)
{
    Name first, second;

    first.sub_006EB7A0(DAT_007733E4, 0);
    second.sub_006EB7A0(DAT_007733DC, 0);
    Object* made = (Object*)sub_0043CE00(44);
    if (made) {
        made->sub_006F5BB0(&second, &first);
        *(void**)made = DAT_00773398;
        DAT_0085D520 = made;
    } else {
        DAT_0085D520 = 0;
    }
    second.sub_006EBBD0();
    first.sub_006EBBD0();
}

// ============================================================================
// [VERIFIED] audio::SeqActionChannelVolumes::vfunc_00 (0x006F8840, 36 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as SoundManager::SoundPlayerHandle::vfunc_00 (0x00077F00), which was matched first;
// its addresses and names were swapped for this function's.
// audio::SeqActionChannelVolumes::vfunc_00 (0x006F8840, 36 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_00772F80[];
extern "C" char DAT_007F7748[];
extern "C" void __cdecl sub_006EE890(int, int);

namespace audio {

class SeqActionChannelVolumes
{
public:
    virtual SeqActionChannelVolumes* vfunc_00(int a1);
};

SeqActionChannelVolumes* SeqActionChannelVolumes::vfunc_00(int a1)
{
    *(int*)this = (int)DAT_00772F80;
    if (a1 & 1) {
        sub_006EE890((int)DAT_007F7748, (int)this);
    }
    return this;
}

}

// [TODO] 0x006F8870 sub_006F8870 (83 B)
// ============================================================================
// [VERIFIED] audio::SeqEventChannelVolumes::vfunc_03 (0x006F8930, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as audio::SeqEventNestTrack::vfunc_03 (PC 0x006F6960), which was matched first;
// its addresses and names were swapped for this function's.
// bin: pc
// va: 0x006F8930
// what: Returns a value kept in the game's data.
// tool: Claude Fable 5.2 (look-alike of pc 0x006DF7F0, names and addresses swapped)
// audio::SeqEventChannelVolumes::vfunc_03 (0x006F8930, 6 bytes)
extern "C" int DAT_0085D524;

namespace audio {

class SeqEventChannelVolumes
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual int vfunc_03();
};

int SeqEventChannelVolumes::vfunc_03()
{
    return DAT_0085D524;
}

}

// ============================================================================
// [VERIFIED] audio::SeqEventChannelVolumes::vfunc_04 (0x006F8940, 35 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as SoundManager::StatePropSoundPlayer::vfunc_00 (0x00082430), which was matched first;
// its addresses and names were swapped for this function's.
// audio::SeqEventChannelVolumes::vfunc_04 (0x006F8940, 35 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_007F7740[];
extern "C" void __cdecl sub_006F5730(void);
extern "C" void __cdecl sub_006EE890(int, int);

namespace audio {

class SeqEventChannelVolumes
{
public:
    virtual SeqEventChannelVolumes* vfunc_04(int a1);
};

SeqEventChannelVolumes* SeqEventChannelVolumes::vfunc_04(int a1)
{
    sub_006F5730();
    if (a1 & 1) {
        sub_006EE890((int)DAT_007F7740, (int)this);
    }
    return this;
}

}

// ============================================================================
// [VERIFIED] audio::SeqEventChannelVolumes::vfunc_02 (0x006F8970, 67 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as audio::SeqEventChannelSendVolumes::vfunc_02 (0x002D8FA0), which was matched first;
// its addresses and names were swapped for this function's.
#include <stddef.h>

struct Object
{
    void sub_007007A0(int);
};

extern "C" char DAT_00773414[];
extern "C" char DAT_007F7748[];
extern "C" int __cdecl sub_006EE870(int);

namespace audio {

class SeqEventChannelVolumes;

struct Instance
{
    void* m_vtable;
    SeqEventChannelVolumes* m_parent;
    int m_unk8;
    int m_unkC;
    bool m_unk10;

    void* operator new(size_t)
    {
        return (void*)sub_006EE870((int)DAT_007F7748);
    }

    Instance(SeqEventChannelVolumes* parent)
    {
        m_unkC = 0;
        m_unk10 = false;
        m_parent = parent;
        m_vtable = DAT_00773414;
    }
};

class SeqEventChannelVolumes
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02(int a1);
    virtual int vfunc_03();
    virtual SeqEventChannelVolumes* vfunc_04(int a1);
};

void SeqEventChannelVolumes::vfunc_02(int a1)
{
    ((Object*)a1)->sub_007007A0((int)new Instance(this));
}

}

// ============================================================================
// [VERIFIED] audio::ChannelVolumeFadeBehaviour::vfunc_00 (0x006F89C0, 36 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as SoundManager::SoundPlayerHandle::vfunc_00 (0x00077F00), which was matched first;
// its addresses and names were swapped for this function's.
// audio::ChannelVolumeFadeBehaviour::vfunc_00 (0x006F89C0, 36 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_00772F9C[];
extern "C" char DAT_007F7750[];
extern "C" void __cdecl sub_006EE890(int, int);

namespace audio {

class ChannelVolumeFadeBehaviour
{
public:
    virtual ChannelVolumeFadeBehaviour* vfunc_00(int a1);
};

ChannelVolumeFadeBehaviour* ChannelVolumeFadeBehaviour::vfunc_00(int a1)
{
    *(int*)this = (int)DAT_00772F9C;
    if (a1 & 1) {
        sub_006EE890((int)DAT_007F7750, (int)this);
    }
    return this;
}

}

// [TODO] 0x006F89F0 audio::ChannelVolumeFadeBehaviour::vfunc_01 (771 B)
// ============================================================================
// [VERIFIED] audio::SeqEventType<audio::SeqEventChannelVolumes>::vfunc_01 (0x006F8D00, 27 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as audio::SeqEventType<audio::SeqEventChannelSendVolumes>::vfunc_01 (0x002D93F0), which was matched first;
// its addresses and names were swapped for this function's.
// audio::SeqEventType<audio::SeqEventChannelVolumes>::vfunc_01 (0x006F8D00, 27 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    int sub_006F88D0();
};

extern "C" char DAT_007F7740[];
extern "C" int __cdecl sub_006EE870(int);

namespace audio { class SeqEventChannelVolumes; }

namespace audio { 
template <class T0> class SeqEventType
{
public:
    virtual void vfunc_00();
    virtual int vfunc_01();
};
}

template <> int audio::SeqEventType<audio::SeqEventChannelVolumes>::vfunc_01()
{
    int t1;

    t1 = sub_006EE870((int)DAT_007F7740);
    if (t1) {
        return ((Object*)t1)->sub_006F88D0();
    }
    return 0;
}

// [TODO] 0x006F8D20 sub_006F8D20 (53 B)
// [TODO] 0x006F8D60 sub_006F8D60 (53 B)
// ============================================================================
// [VERIFIED] sub_006F8DA0 (0x006F8DA0, 116 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_002D8E20 (0x002D8E20), which was matched first;
// its addresses and names were swapped for this function's.
struct Name
{
    int data[3];
    void sub_006EB7A0(const char* text, int flags);
    void sub_006EBBD0();
};

struct Object
{
    void sub_006F5BB0(Name* a, Name* b);
};

extern "C" char DAT_00773408[];
extern "C" char DAT_00773458[];
extern "C" char DAT_00773468[];
extern "C" Object* DAT_0085D524;
extern "C" void* __cdecl sub_0043CE00(unsigned int size);

// Makes the single instance: builds it from two names and keeps it in a global (or null).
void __cdecl sub_006F8DA0(void)
{
    Name first, second;

    first.sub_006EB7A0(DAT_00773468, 0);
    second.sub_006EB7A0(DAT_00773458, 0);
    Object* made = (Object*)sub_0043CE00(44);
    if (made) {
        made->sub_006F5BB0(&second, &first);
        *(void**)made = DAT_00773408;
        DAT_0085D524 = made;
    } else {
        DAT_0085D524 = 0;
    }
    second.sub_006EBBD0();
    first.sub_006EBBD0();
}

// [TODO] 0x006F8E20 audio::SeqEventChannelVolumes::vfunc_01 (88 B)
// ============================================================================
// [VERIFIED] audio::SeqEventChannelVolumes::vfunc_00 (0x006F8E80, 86 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as audio::SeqEventChannelVolumes::vfunc_00 (0x002DB240), which was matched first;
// its addresses and names were swapped for this function's.
// audio::SeqEventChannelVolumes::vfunc_00 (0x006F8E80, 86 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" bool __cdecl sub_006ED500(int, int);
extern "C" bool __cdecl sub_006F33D0(int, int);
extern "C" bool __stdcall sub_006F5740(int);
extern "C" bool __cdecl sub_006F8D60(int, int);

namespace audio {

class SeqEventChannelVolumes
{
public:
    virtual int vfunc_00(int a1);
    char m_pad04[0x14];
    int m_Field18; // +0x18
    int m_Field1C; // +0x1C
};

int SeqEventChannelVolumes::vfunc_00(int a1)
{
    if (sub_006F5740(a1)) {
        if (!sub_006F33D0(a1, (int)(&m_Field18))) goto L_4F;
        if (!sub_006ED500(a1, (int)(&m_Field1C))) goto L_4F;
        if (!sub_006F8D60(a1, (int)this + 8)) goto L_4F;
        return 1;
    }
L_4F:
    return 0;
}

}

// [TODO] 0x006F8EE0 audio::SeqActionChannelVolumes::vfunc_06 (180 B)
// ============================================================================
// [VERIFIED] audio::SeqEventVarVolumeRand::vfunc_01 (0x006F8FA0, 49 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as audio::SeqEventVarVolumeRand::vfunc_01 (0x002DB360), which was matched first;
// its addresses and names were swapped for this function's.
// audio::SeqEventVarVolumeRand::vfunc_01 (0x006F8FA0, 49 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __cdecl sub_006F33F0(int, int);
extern "C" bool __stdcall sub_006F5760(int);

namespace audio {

class SeqEventVarVolumeRand
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01(int a1);
    char m_pad04[0x4];
    int m_Field08; // +0x08
    int m_Field0C; // +0x0C
};

void SeqEventVarVolumeRand::vfunc_01(int a1)
{
    if (sub_006F5760(a1)) {
        sub_006F33F0(a1, m_Field08);
    }
    sub_006F33F0(a1, m_Field0C);
}

}

// ============================================================================
// [VERIFIED] audio::SeqEventVarVolumeRand::vfunc_00 (0x006F8FE0, 69 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as audio::SeqEventVarVolumeRand::vfunc_00 (0x002DB3A0), which was matched first;
// its addresses and names were swapped for this function's.
// audio::SeqEventVarVolumeRand::vfunc_00 (0x006F8FE0, 69 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" bool __cdecl sub_006F33D0(int, int);
extern "C" bool __stdcall sub_006F5740(int);

namespace audio {

class SeqEventVarVolumeRand
{
public:
    virtual int vfunc_00(int a1);
    char m_pad04[0x4];
    int m_Field08; // +0x08
};

int SeqEventVarVolumeRand::vfunc_00(int a1)
{
    if (sub_006F5740(a1)) {
        if (!sub_006F33D0(a1, (int)(&m_Field08))) goto L_3E;
        if (!sub_006F33D0(a1, (int)this + 12)) goto L_3E;
        return 1;
    }
L_3E:
    return 0;
}

}

// ============================================================================
// [VERIFIED] audio::SeqActionVarVolumeRand::vfunc_00 (0x006F9030, 36 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as SoundManager::SoundPlayerHandle::vfunc_00 (0x00077F00), which was matched first;
// its addresses and names were swapped for this function's.
// audio::SeqActionVarVolumeRand::vfunc_00 (0x006F9030, 36 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_00772F80[];
extern "C" char DAT_007F7800[];
extern "C" void __cdecl sub_006EE890(int, int);

namespace audio {

class SeqActionVarVolumeRand
{
public:
    virtual SeqActionVarVolumeRand* vfunc_00(int a1);
};

SeqActionVarVolumeRand* SeqActionVarVolumeRand::vfunc_00(int a1)
{
    *(int*)this = (int)DAT_00772F80;
    if (a1 & 1) {
        sub_006EE890((int)DAT_007F7800, (int)this);
    }
    return this;
}

}

// ============================================================================
// [VERIFIED] audio::SeqEventVarVolumeRand::vfunc_03 (0x006F9060, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as audio::SeqEventNestTrack::vfunc_03 (PC 0x006F6960), which was matched first;
// its addresses and names were swapped for this function's.
// bin: pc
// va: 0x006F9060
// what: Returns a value kept in the game's data.
// tool: Claude Fable 5.2 (look-alike of pc 0x006DF7F0, names and addresses swapped)
// audio::SeqEventVarVolumeRand::vfunc_03 (0x006F9060, 6 bytes)
extern "C" int DAT_0085D52C;

namespace audio {

class SeqEventVarVolumeRand
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual int vfunc_03();
};

int SeqEventVarVolumeRand::vfunc_03()
{
    return DAT_0085D52C;
}

}

// ============================================================================
// [VERIFIED] audio::SeqEventVarVolumeRand::vfunc_04 (0x006F9070, 35 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as SoundManager::StatePropSoundPlayer::vfunc_00 (0x00082430), which was matched first;
// its addresses and names were swapped for this function's.
// audio::SeqEventVarVolumeRand::vfunc_04 (0x006F9070, 35 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_007F77F8[];
extern "C" void __cdecl sub_006F5730(void);
extern "C" void __cdecl sub_006EE890(int, int);

namespace audio {

class SeqEventVarVolumeRand
{
public:
    virtual SeqEventVarVolumeRand* vfunc_04(int a1);
};

SeqEventVarVolumeRand* SeqEventVarVolumeRand::vfunc_04(int a1)
{
    sub_006F5730();
    if (a1 & 1) {
        sub_006EE890((int)DAT_007F77F8, (int)this);
    }
    return this;
}

}

// ============================================================================
// [VERIFIED] audio::SeqEventVarVolumeRand::vfunc_02 (0x006F90A0, 67 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as audio::SeqEventChannelSendVolumes::vfunc_02 (0x002D8FA0), which was matched first;
// its addresses and names were swapped for this function's.
#include <stddef.h>

struct Object
{
    void sub_007007A0(int);
};

extern "C" char DAT_0077349C[];
extern "C" char DAT_007F7800[];
extern "C" int __cdecl sub_006EE870(int);

namespace audio {

class SeqEventVarVolumeRand;

struct Instance
{
    void* m_vtable;
    SeqEventVarVolumeRand* m_parent;
    int m_unk8;
    int m_unkC;
    bool m_unk10;

    void* operator new(size_t)
    {
        return (void*)sub_006EE870((int)DAT_007F7800);
    }

    Instance(SeqEventVarVolumeRand* parent)
    {
        m_unkC = 0;
        m_unk10 = false;
        m_parent = parent;
        m_vtable = DAT_0077349C;
    }
};

class SeqEventVarVolumeRand
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02(int a1);
    virtual int vfunc_03();
    virtual SeqEventVarVolumeRand* vfunc_04(int a1);
};

void SeqEventVarVolumeRand::vfunc_02(int a1)
{
    ((Object*)a1)->sub_007007A0((int)new Instance(this));
}

}

// [TODO] 0x006F90F0 audio::SeqActionVarVolumeRand::vfunc_06 (51 B)
// ============================================================================
// [VERIFIED] audio::SeqEventType<audio::SeqEventVarVolumeRand>::vfunc_01 (0x006F9130, 55 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as audio::SeqEventType<audio::SeqEventVarVolumeRand>::vfunc_01 (0x002DB4F0), which was matched first;
// its addresses and names were swapped for this function's.
// audio::SeqEventType<audio::SeqEventVarVolumeRand>::vfunc_01 (0x006F9130, 55 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_006F5850();
};

extern "C" char DAT_007734BC[];
extern "C" char DAT_007F77F8[];
extern "C" int __cdecl sub_006EE870(int);

namespace audio { class SeqEventVarVolumeRand; }

namespace audio { 
template <class T0> class SeqEventType
{
public:
    virtual void vfunc_00();
    virtual int vfunc_01();
};
}

template <> int audio::SeqEventType<audio::SeqEventVarVolumeRand>::vfunc_01()
{
    int t1;

    t1 = sub_006EE870((int)DAT_007F77F8);
    if (t1) {
        ((Object*)t1)->sub_006F5850();
        *(int*)t1 = (int)DAT_007734BC;
        *(int*)(t1 + 8) = 0x3F000000;
        *(int*)(t1 + 12) = 0x3F800000;
        return t1;
    }
    return 0;
}

// ============================================================================
// [VERIFIED] sub_006F9170 (0x006F9170, 116 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_002D8E20 (0x002D8E20), which was matched first;
// its addresses and names were swapped for this function's.
struct Name
{
    int data[3];
    void sub_006EB7A0(const char* text, int flags);
    void sub_006EBBD0();
};

struct Object
{
    void sub_006F5BB0(Name* a, Name* b);
};

extern "C" char DAT_00773490[];
extern "C" char DAT_007734D4[];
extern "C" char DAT_007734DC[];
extern "C" Object* DAT_0085D52C;
extern "C" void* __cdecl sub_0043CE00(unsigned int size);

// Makes the single instance: builds it from two names and keeps it in a global (or null).
void __cdecl sub_006F9170(void)
{
    Name first, second;

    first.sub_006EB7A0(DAT_007734DC, 0);
    second.sub_006EB7A0(DAT_007734D4, 0);
    Object* made = (Object*)sub_0043CE00(44);
    if (made) {
        made->sub_006F5BB0(&second, &first);
        *(void**)made = DAT_00773490;
        DAT_0085D52C = made;
    } else {
        DAT_0085D52C = 0;
    }
    second.sub_006EBBD0();
    first.sub_006EBBD0();
}

// ============================================================================
// [VERIFIED] audio::SeqEventVarVolume::vfunc_01 (0x006F91F0, 52 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as audio::SeqEventVarVolume::vfunc_01 (0x002DB5B0), which was matched first;
// its addresses and names were swapped for this function's.
// audio::SeqEventVarVolume::vfunc_01 (0x006F91F0, 52 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" bool __cdecl sub_006F33F0(int, int);
extern "C" bool __stdcall sub_006F5760(int);

namespace audio {

class SeqEventVarVolume
{
public:
    virtual void vfunc_00();
    virtual int vfunc_01(int a1);
    char m_pad04[0x4];
    int m_Field08; // +0x08
};

int SeqEventVarVolume::vfunc_01(int a1)
{
    if (sub_006F5760(a1)) {
        if (!sub_006F33F0(a1, m_Field08)) goto L_2D;
        return 1;
    }
L_2D:
    return 0;
}

}

// ============================================================================
// [VERIFIED] audio::SeqEventVarVolume::vfunc_00 (0x006F9230, 32 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as audio::SeqEventVarVolume::vfunc_00 (0x002DB5F0), which was matched first;
// its addresses and names were swapped for this function's.
// audio::SeqEventVarVolume::vfunc_00 (0x006F9230, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __cdecl sub_006F33D0(int, int);
extern "C" void __stdcall sub_006F5740(int);

namespace audio {

class SeqEventVarVolume
{
public:
    virtual void vfunc_00(int a1);
};

void SeqEventVarVolume::vfunc_00(int a1)
{
    sub_006F5740(a1);
    sub_006F33D0(a1, (int)this + 8);
}

}

// ============================================================================
// [VERIFIED] audio::SeqActionVarVolume::vfunc_00 (0x006F9250, 36 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as SoundManager::SoundPlayerHandle::vfunc_00 (0x00077F00), which was matched first;
// its addresses and names were swapped for this function's.
// audio::SeqActionVarVolume::vfunc_00 (0x006F9250, 36 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_00772F80[];
extern "C" char DAT_007F78A4[];
extern "C" void __cdecl sub_006EE890(int, int);

namespace audio {

class SeqActionVarVolume
{
public:
    virtual SeqActionVarVolume* vfunc_00(int a1);
};

SeqActionVarVolume* SeqActionVarVolume::vfunc_00(int a1)
{
    *(int*)this = (int)DAT_00772F80;
    if (a1 & 1) {
        sub_006EE890((int)DAT_007F78A4, (int)this);
    }
    return this;
}

}

// ============================================================================
// [VERIFIED] audio::SeqEventVarVolume::vfunc_03 (0x006F9280, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as audio::SeqEventNestTrack::vfunc_03 (PC 0x006F6960), which was matched first;
// its addresses and names were swapped for this function's.
// bin: pc
// va: 0x006F9280
// what: Returns a value kept in the game's data.
// tool: Claude Fable 5.2 (look-alike of pc 0x006DF7F0, names and addresses swapped)
// audio::SeqEventVarVolume::vfunc_03 (0x006F9280, 6 bytes)
extern "C" int DAT_0085D530;

namespace audio {

class SeqEventVarVolume
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual int vfunc_03();
};

int SeqEventVarVolume::vfunc_03()
{
    return DAT_0085D530;
}

}

// ============================================================================
// [VERIFIED] audio::SeqEventVarVolume::vfunc_04 (0x006F9290, 35 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as SoundManager::StatePropSoundPlayer::vfunc_00 (0x00082430), which was matched first;
// its addresses and names were swapped for this function's.
// audio::SeqEventVarVolume::vfunc_04 (0x006F9290, 35 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_007F789C[];
extern "C" void __cdecl sub_006F5730(void);
extern "C" void __cdecl sub_006EE890(int, int);

namespace audio {

class SeqEventVarVolume
{
public:
    virtual SeqEventVarVolume* vfunc_04(int a1);
};

SeqEventVarVolume* SeqEventVarVolume::vfunc_04(int a1)
{
    sub_006F5730();
    if (a1 & 1) {
        sub_006EE890((int)DAT_007F789C, (int)this);
    }
    return this;
}

}

// ============================================================================
// [VERIFIED] audio::SeqEventVarVolume::vfunc_02 (0x006F92C0, 67 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as audio::SeqEventChannelSendVolumes::vfunc_02 (0x002D8FA0), which was matched first;
// its addresses and names were swapped for this function's.
#include <stddef.h>

struct Object
{
    void sub_007007A0(int);
};

extern "C" char DAT_00773510[];
extern "C" char DAT_007F78A4[];
extern "C" int __cdecl sub_006EE870(int);

namespace audio {

class SeqEventVarVolume;

struct Instance
{
    void* m_vtable;
    SeqEventVarVolume* m_parent;
    int m_unk8;
    int m_unkC;
    bool m_unk10;

    void* operator new(size_t)
    {
        return (void*)sub_006EE870((int)DAT_007F78A4);
    }

    Instance(SeqEventVarVolume* parent)
    {
        m_unkC = 0;
        m_unk10 = false;
        m_parent = parent;
        m_vtable = DAT_00773510;
    }
};

class SeqEventVarVolume
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02(int a1);
    virtual int vfunc_03();
    virtual SeqEventVarVolume* vfunc_04(int a1);
};

void SeqEventVarVolume::vfunc_02(int a1)
{
    ((Object*)a1)->sub_007007A0((int)new Instance(this));
}

}

// ============================================================================
// [VERIFIED] audio::SeqActionVarVolume::vfunc_06 (0x006F9310, 19 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as audio::SeqActionVarVolume::vfunc_06 (0x002DB6D0), which was matched first;
// its addresses and names were swapped for this function's.
// audio::SeqActionVarVolume::vfunc_06 (0x006F9310, 19 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

namespace audio {

class SeqActionVarVolume
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual void vfunc_05();
    virtual void vfunc_06(int a1);
    int m_Field04; // +0x04
};

void SeqActionVarVolume::vfunc_06(int a1)
{
    int t1;

    t1 = m_Field04 + 8;
    *(int*)(*(int*)(a1 + 4) + 32) = m_Field04 + 8;
}

}

// ============================================================================
// [VERIFIED] audio::SeqEventType<audio::SeqEventVarVolume>::vfunc_01 (0x006F9330, 48 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as audio::SeqEventType<audio::SeqEventVarVolume>::vfunc_01 (0x002DB6F0), which was matched first;
// its addresses and names were swapped for this function's.
// audio::SeqEventType<audio::SeqEventVarVolume>::vfunc_01 (0x006F9330, 48 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_006F5850();
};

extern "C" char DAT_00773530[];
extern "C" char DAT_007F789C[];
extern "C" int __cdecl sub_006EE870(int);

namespace audio { class SeqEventVarVolume; }

namespace audio { 
template <class T0> class SeqEventType
{
public:
    virtual void vfunc_00();
    virtual int vfunc_01();
};
}

template <> int audio::SeqEventType<audio::SeqEventVarVolume>::vfunc_01()
{
    int t1;

    t1 = sub_006EE870((int)DAT_007F789C);
    if (t1) {
        ((Object*)t1)->sub_006F5850();
        *(int*)t1 = (int)DAT_00773530;
        *(int*)(t1 + 8) = 0x3F800000;
        return t1;
    }
    return 0;
}

// ============================================================================
// [VERIFIED] sub_006F9360 (0x006F9360, 116 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_002D8E20 (0x002D8E20), which was matched first;
// its addresses and names were swapped for this function's.
struct Name
{
    int data[3];
    void sub_006EB7A0(const char* text, int flags);
    void sub_006EBBD0();
};

struct Object
{
    void sub_006F5BB0(Name* a, Name* b);
};

extern "C" char DAT_00773504[];
extern "C" char DAT_00773548[];
extern "C" char DAT_00773550[];
extern "C" Object* DAT_0085D530;
extern "C" void* __cdecl sub_0043CE00(unsigned int size);

// Makes the single instance: builds it from two names and keeps it in a global (or null).
void __cdecl sub_006F9360(void)
{
    Name first, second;

    first.sub_006EB7A0(DAT_00773550, 0);
    second.sub_006EB7A0(DAT_00773548, 0);
    Object* made = (Object*)sub_0043CE00(44);
    if (made) {
        made->sub_006F5BB0(&second, &first);
        *(void**)made = DAT_00773504;
        DAT_0085D530 = made;
    } else {
        DAT_0085D530 = 0;
    }
    second.sub_006EBBD0();
    first.sub_006EBBD0();
}

// ============================================================================
// [VERIFIED] audio::SeqEventVarTempo::vfunc_01 (0x006F93E0, 65 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as audio::SeqEventVarTempo::vfunc_01 (0x002DB7A0), which was matched first;
// its addresses and names were swapped for this function's.
// audio::SeqEventVarTempo::vfunc_01 (0x006F93E0, 65 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field08
{
    bool sub_00700CE0(int);
};

extern "C" bool __cdecl sub_006F33F0(int, int);
extern "C" bool __stdcall sub_006F5760(int);

namespace audio {

class SeqEventVarTempo
{
public:
    virtual void vfunc_00();
    virtual int vfunc_01(int a1);
    char m_pad04[0x4];
    Field08 m_Field08; // +0x08
    char m_pad09[0x7];
    int m_Field10; // +0x10
};

int SeqEventVarTempo::vfunc_01(int a1)
{
    if (sub_006F5760(a1)) {
        if (!m_Field08.sub_00700CE0(a1)) goto L_3A;
        if (!sub_006F33F0(a1, m_Field10)) goto L_3A;
        return 1;
    }
L_3A:
    return 0;
}

}

// ============================================================================
// [VERIFIED] audio::SeqEventVarTempo::vfunc_00 (0x006F9430, 65 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as audio::SeqEventVarTempo::vfunc_00 (0x002DB7F0), which was matched first;
// its addresses and names were swapped for this function's.
// audio::SeqEventVarTempo::vfunc_00 (0x006F9430, 65 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field08
{
    bool sub_00700CA0(int);
};

extern "C" bool __cdecl sub_006F33D0(int, int);
extern "C" bool __stdcall sub_006F5740(int);

namespace audio {

class SeqEventVarTempo
{
public:
    virtual int vfunc_00(int a1);
    char m_pad04[0x4];
    Field08 m_Field08; // +0x08
};

int SeqEventVarTempo::vfunc_00(int a1)
{
    if (sub_006F5740(a1)) {
        if (!m_Field08.sub_00700CA0(a1)) goto L_3A;
        if (!sub_006F33D0(a1, (int)this + 16)) goto L_3A;
        return 1;
    }
L_3A:
    return 0;
}

}

// ============================================================================
// [VERIFIED] audio::SeqActionVarTempo::vfunc_00 (0x006F9480, 36 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as SoundManager::SoundPlayerHandle::vfunc_00 (0x00077F00), which was matched first;
// its addresses and names were swapped for this function's.
// audio::SeqActionVarTempo::vfunc_00 (0x006F9480, 36 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_00772F80[];
extern "C" char DAT_007F7948[];
extern "C" void __cdecl sub_006EE890(int, int);

namespace audio {

class SeqActionVarTempo
{
public:
    virtual SeqActionVarTempo* vfunc_00(int a1);
};

SeqActionVarTempo* SeqActionVarTempo::vfunc_00(int a1)
{
    *(int*)this = (int)DAT_00772F80;
    if (a1 & 1) {
        sub_006EE890((int)DAT_007F7948, (int)this);
    }
    return this;
}

}

// ============================================================================
// [VERIFIED] audio::SeqEventVarTempo::vfunc_03 (0x006F94B0, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as audio::SeqEventNestTrack::vfunc_03 (PC 0x006F6960), which was matched first;
// its addresses and names were swapped for this function's.
// bin: pc
// va: 0x006F94B0
// what: Returns a value kept in the game's data.
// tool: Claude Fable 5.2 (look-alike of pc 0x006DF7F0, names and addresses swapped)
// audio::SeqEventVarTempo::vfunc_03 (0x006F94B0, 6 bytes)
extern "C" int DAT_0085D534;

namespace audio {

class SeqEventVarTempo
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual int vfunc_03();
};

int SeqEventVarTempo::vfunc_03()
{
    return DAT_0085D534;
}

}

// ============================================================================
// [VERIFIED] audio::SeqEventVarTempo::vfunc_04 (0x006F94C0, 35 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as SoundManager::StatePropSoundPlayer::vfunc_00 (0x00082430), which was matched first;
// its addresses and names were swapped for this function's.
// audio::SeqEventVarTempo::vfunc_04 (0x006F94C0, 35 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_007F7940[];
extern "C" void __cdecl sub_006F5730(void);
extern "C" void __cdecl sub_006EE890(int, int);

namespace audio {

class SeqEventVarTempo
{
public:
    virtual SeqEventVarTempo* vfunc_04(int a1);
};

SeqEventVarTempo* SeqEventVarTempo::vfunc_04(int a1)
{
    sub_006F5730();
    if (a1 & 1) {
        sub_006EE890((int)DAT_007F7940, (int)this);
    }
    return this;
}

}

// ============================================================================
// [VERIFIED] audio::SeqEventVarTempo::vfunc_02 (0x006F94F0, 67 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as audio::SeqEventChannelSendVolumes::vfunc_02 (0x002D8FA0), which was matched first;
// its addresses and names were swapped for this function's.
#include <stddef.h>

struct Object
{
    void sub_007007A0(int);
};

extern "C" char DAT_00773580[];
extern "C" char DAT_007F7948[];
extern "C" int __cdecl sub_006EE870(int);

namespace audio {

class SeqEventVarTempo;

struct Instance
{
    void* m_vtable;
    SeqEventVarTempo* m_parent;
    int m_unk8;
    int m_unkC;
    bool m_unk10;

    void* operator new(size_t)
    {
        return (void*)sub_006EE870((int)DAT_007F7948);
    }

    Instance(SeqEventVarTempo* parent)
    {
        m_unkC = 0;
        m_unk10 = false;
        m_parent = parent;
        m_vtable = DAT_00773580;
    }
};

class SeqEventVarTempo
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02(int a1);
    virtual int vfunc_03();
    virtual SeqEventVarTempo* vfunc_04(int a1);
};

void SeqEventVarTempo::vfunc_02(int a1)
{
    ((Object*)a1)->sub_007007A0((int)new Instance(this));
}

}

// [TODO] 0x006F9540 audio::SeqActionVarTempo::vfunc_06 (41 B)
// [TODO] 0x006F9570 audio::SeqEventType<audio::SeqEventVarTempo>::vfunc_01 (59 B)
// ============================================================================
// [VERIFIED] sub_006F95B0 (0x006F95B0, 116 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_002D8E20 (0x002D8E20), which was matched first;
// its addresses and names were swapped for this function's.
struct Name
{
    int data[3];
    void sub_006EB7A0(const char* text, int flags);
    void sub_006EBBD0();
};

struct Object
{
    void sub_006F5BB0(Name* a, Name* b);
};

extern "C" char DAT_00773574[];
extern "C" char DAT_007735B8[];
extern "C" char DAT_007735C0[];
extern "C" Object* DAT_0085D534;
extern "C" void* __cdecl sub_0043CE00(unsigned int size);

// Makes the single instance: builds it from two names and keeps it in a global (or null).
void __cdecl sub_006F95B0(void)
{
    Name first, second;

    first.sub_006EB7A0(DAT_007735C0, 0);
    second.sub_006EB7A0(DAT_007735B8, 0);
    Object* made = (Object*)sub_0043CE00(44);
    if (made) {
        made->sub_006F5BB0(&second, &first);
        *(void**)made = DAT_00773574;
        DAT_0085D534 = made;
    } else {
        DAT_0085D534 = 0;
    }
    second.sub_006EBBD0();
    first.sub_006EBBD0();
}

// ============================================================================
// [VERIFIED] audio::SeqEventVarPosDist::vfunc_01 (0x006F9630, 48 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as audio::SeqEventVarPosDist::vfunc_01 (0x002DB9F0), which was matched first;
// its addresses and names were swapped for this function's.
// audio::SeqEventVarPosDist::vfunc_01 (0x006F9630, 48 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field08
{
    bool sub_00700CE0(int);
};

extern "C" bool __stdcall sub_006F5760(int);

namespace audio {

class SeqEventVarPosDist
{
public:
    virtual void vfunc_00();
    virtual int vfunc_01(int a1);
    char m_pad04[0x4];
    Field08 m_Field08; // +0x08
};

int SeqEventVarPosDist::vfunc_01(int a1)
{
    if (sub_006F5760(a1)) {
        if (!m_Field08.sub_00700CE0(a1)) goto L_29;
        return 1;
    }
L_29:
    return 0;
}

}

// ============================================================================
// [VERIFIED] audio::SeqEventVarPosDist::vfunc_00 (0x006F9660, 48 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as audio::SeqEventVarPosDist::vfunc_01 (0x002DB9F0), which was matched first;
// its addresses and names were swapped for this function's.
// audio::SeqEventVarPosDist::vfunc_00 (0x006F9660, 48 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field08
{
    bool sub_00700CA0(int);
};

extern "C" bool __stdcall sub_006F5740(int);

namespace audio {

class SeqEventVarPosDist
{
public:
    virtual void vfunc_00();
    virtual int vfunc_00(int a1);
    char m_pad04[0x4];
    Field08 m_Field08; // +0x08
};

int SeqEventVarPosDist::vfunc_00(int a1)
{
    if (sub_006F5740(a1)) {
        if (!m_Field08.sub_00700CA0(a1)) goto L_29;
        return 1;
    }
L_29:
    return 0;
}

}

// ============================================================================
// [VERIFIED] audio::SeqActionVarPosDist::vfunc_00 (0x006F9690, 36 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as SoundManager::SoundPlayerHandle::vfunc_00 (0x00077F00), which was matched first;
// its addresses and names were swapped for this function's.
// audio::SeqActionVarPosDist::vfunc_00 (0x006F9690, 36 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_00772F80[];
extern "C" char DAT_007F79EC[];
extern "C" void __cdecl sub_006EE890(int, int);

namespace audio {

class SeqActionVarPosDist
{
public:
    virtual SeqActionVarPosDist* vfunc_00(int a1);
};

SeqActionVarPosDist* SeqActionVarPosDist::vfunc_00(int a1)
{
    *(int*)this = (int)DAT_00772F80;
    if (a1 & 1) {
        sub_006EE890((int)DAT_007F79EC, (int)this);
    }
    return this;
}

}

// ============================================================================
// [VERIFIED] audio::SeqEventVarPosDist::vfunc_03 (0x006F96C0, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as audio::SeqEventNestTrack::vfunc_03 (PC 0x006F6960), which was matched first;
// its addresses and names were swapped for this function's.
// bin: pc
// va: 0x006F96C0
// what: Returns a value kept in the game's data.
// tool: Claude Fable 5.2 (look-alike of pc 0x006DF7F0, names and addresses swapped)
// audio::SeqEventVarPosDist::vfunc_03 (0x006F96C0, 6 bytes)
extern "C" int DAT_0085D538;

namespace audio {

class SeqEventVarPosDist
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual int vfunc_03();
};

int SeqEventVarPosDist::vfunc_03()
{
    return DAT_0085D538;
}

}

// ============================================================================
// [VERIFIED] audio::SeqEventVarPosDist::vfunc_04 (0x006F96D0, 35 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as SoundManager::StatePropSoundPlayer::vfunc_00 (0x00082430), which was matched first;
// its addresses and names were swapped for this function's.
// audio::SeqEventVarPosDist::vfunc_04 (0x006F96D0, 35 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_007F79E4[];
extern "C" void __cdecl sub_006F5730(void);
extern "C" void __cdecl sub_006EE890(int, int);

namespace audio {

class SeqEventVarPosDist
{
public:
    virtual SeqEventVarPosDist* vfunc_04(int a1);
};

SeqEventVarPosDist* SeqEventVarPosDist::vfunc_04(int a1)
{
    sub_006F5730();
    if (a1 & 1) {
        sub_006EE890((int)DAT_007F79E4, (int)this);
    }
    return this;
}

}

// ============================================================================
// [VERIFIED] audio::SeqEventVarPosDist::vfunc_02 (0x006F9700, 67 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as audio::SeqEventChannelSendVolumes::vfunc_02 (0x002D8FA0), which was matched first;
// its addresses and names were swapped for this function's.
#include <stddef.h>

struct Object
{
    void sub_007007A0(int);
};

extern "C" char DAT_007735F0[];
extern "C" char DAT_007F79EC[];
extern "C" int __cdecl sub_006EE870(int);

namespace audio {

class SeqEventVarPosDist;

struct Instance
{
    void* m_vtable;
    SeqEventVarPosDist* m_parent;
    int m_unk8;
    int m_unkC;
    bool m_unk10;

    void* operator new(size_t)
    {
        return (void*)sub_006EE870((int)DAT_007F79EC);
    }

    Instance(SeqEventVarPosDist* parent)
    {
        m_unkC = 0;
        m_unk10 = false;
        m_parent = parent;
        m_vtable = DAT_007735F0;
    }
};

class SeqEventVarPosDist
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02(int a1);
    virtual int vfunc_03();
    virtual SeqEventVarPosDist* vfunc_04(int a1);
};

void SeqEventVarPosDist::vfunc_02(int a1)
{
    ((Object*)a1)->sub_007007A0((int)new Instance(this));
}

}

// [TODO] 0x006F9750 audio::SeqActionVarPosDist::vfunc_06 (29 B)
// ============================================================================
// [VERIFIED] audio::SeqEventType<audio::SeqEventVarPosDist>::vfunc_01 (0x006F9770, 55 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as audio::SeqEventType<audio::SeqEventVarPosDist>::vfunc_01 (0x002DBB30), which was matched first;
// its addresses and names were swapped for this function's.
// audio::SeqEventType<audio::SeqEventVarPosDist>::vfunc_01 (0x006F9770, 55 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_006F5850();
};

extern "C" char DAT_00773610[];
extern "C" char DAT_007F79E4[];
extern "C" int __cdecl sub_006EE870(int);

namespace audio { class SeqEventVarPosDist; }

namespace audio { 
template <class T0> class SeqEventType
{
public:
    virtual void vfunc_00();
    virtual int vfunc_01();
};
}

template <> int audio::SeqEventType<audio::SeqEventVarPosDist>::vfunc_01()
{
    int t1;

    t1 = sub_006EE870((int)DAT_007F79E4);
    if (t1) {
        ((Object*)t1)->sub_006F5850();
        *(int*)t1 = (int)DAT_00773610;
        *(int*)(t1 + 8) = 0x3F800000;
        *(int*)(t1 + 12) = 0x42C80000;
        return t1;
    }
    return 0;
}

// ============================================================================
// [VERIFIED] sub_006F97B0 (0x006F97B0, 116 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_002D8E20 (0x002D8E20), which was matched first;
// its addresses and names were swapped for this function's.
struct Name
{
    int data[3];
    void sub_006EB7A0(const char* text, int flags);
    void sub_006EBBD0();
};

struct Object
{
    void sub_006F5BB0(Name* a, Name* b);
};

extern "C" char DAT_007735E4[];
extern "C" char DAT_00773628[];
extern "C" char DAT_00773630[];
extern "C" Object* DAT_0085D538;
extern "C" void* __cdecl sub_0043CE00(unsigned int size);

// Makes the single instance: builds it from two names and keeps it in a global (or null).
void __cdecl sub_006F97B0(void)
{
    Name first, second;

    first.sub_006EB7A0(DAT_00773630, 0);
    second.sub_006EB7A0(DAT_00773628, 0);
    Object* made = (Object*)sub_0043CE00(44);
    if (made) {
        made->sub_006F5BB0(&second, &first);
        *(void**)made = DAT_007735E4;
        DAT_0085D538 = made;
    } else {
        DAT_0085D538 = 0;
    }
    second.sub_006EBBD0();
    first.sub_006EBBD0();
}

// ============================================================================
// [VERIFIED] audio::SeqEventVarPitchRand::vfunc_01 (0x006F9830, 69 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as audio::SeqEventVarPitchRand::vfunc_01 (0x002DBBF0), which was matched first;
// its addresses and names were swapped for this function's.
// audio::SeqEventVarPitchRand::vfunc_01 (0x006F9830, 69 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" bool __cdecl sub_006F33F0(int, int);
extern "C" bool __stdcall sub_006F5760(int);

namespace audio {

class SeqEventVarPitchRand
{
public:
    virtual void vfunc_00();
    virtual int vfunc_01(int a1);
    char m_pad04[0x4];
    int m_Field08; // +0x08
    int m_Field0C; // +0x0C
};

int SeqEventVarPitchRand::vfunc_01(int a1)
{
    if (sub_006F5760(a1)) {
        if (!sub_006F33F0(a1, m_Field08)) goto L_3E;
        if (!sub_006F33F0(a1, m_Field0C)) goto L_3E;
        return 1;
    }
L_3E:
    return 0;
}

}

// ============================================================================
// [VERIFIED] audio::SeqActionVarPitchRand::vfunc_00 (0x006F9880, 36 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as SoundManager::SoundPlayerHandle::vfunc_00 (0x00077F00), which was matched first;
// its addresses and names were swapped for this function's.
// audio::SeqActionVarPitchRand::vfunc_00 (0x006F9880, 36 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_00772F80[];
extern "C" char DAT_007F7AA0[];
extern "C" void __cdecl sub_006EE890(int, int);

namespace audio {

class SeqActionVarPitchRand
{
public:
    virtual SeqActionVarPitchRand* vfunc_00(int a1);
};

SeqActionVarPitchRand* SeqActionVarPitchRand::vfunc_00(int a1)
{
    *(int*)this = (int)DAT_00772F80;
    if (a1 & 1) {
        sub_006EE890((int)DAT_007F7AA0, (int)this);
    }
    return this;
}

}

// ============================================================================
// [VERIFIED] audio::SeqEventVarPitchRand::vfunc_03 (0x006F98B0, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as audio::SeqEventNestTrack::vfunc_03 (PC 0x006F6960), which was matched first;
// its addresses and names were swapped for this function's.
// bin: pc
// va: 0x006F98B0
// what: Returns a value kept in the game's data.
// tool: Claude Fable 5.2 (look-alike of pc 0x006DF7F0, names and addresses swapped)
// audio::SeqEventVarPitchRand::vfunc_03 (0x006F98B0, 6 bytes)
extern "C" int DAT_0085D53C;

namespace audio {

class SeqEventVarPitchRand
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual int vfunc_03();
};

int SeqEventVarPitchRand::vfunc_03()
{
    return DAT_0085D53C;
}

}

// ============================================================================
// [VERIFIED] audio::SeqEventVarPitchRand::vfunc_04 (0x006F98C0, 35 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as SoundManager::StatePropSoundPlayer::vfunc_00 (0x00082430), which was matched first;
// its addresses and names were swapped for this function's.
// audio::SeqEventVarPitchRand::vfunc_04 (0x006F98C0, 35 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_007F7A98[];
extern "C" void __cdecl sub_006F5730(void);
extern "C" void __cdecl sub_006EE890(int, int);

namespace audio {

class SeqEventVarPitchRand
{
public:
    virtual SeqEventVarPitchRand* vfunc_04(int a1);
};

SeqEventVarPitchRand* SeqEventVarPitchRand::vfunc_04(int a1)
{
    sub_006F5730();
    if (a1 & 1) {
        sub_006EE890((int)DAT_007F7A98, (int)this);
    }
    return this;
}

}

// ============================================================================
// [VERIFIED] audio::SeqEventVarPitchRand::vfunc_02 (0x006F98F0, 67 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as audio::SeqEventChannelSendVolumes::vfunc_02 (0x002D8FA0), which was matched first;
// its addresses and names were swapped for this function's.
#include <stddef.h>

struct Object
{
    void sub_007007A0(int);
};

extern "C" char DAT_00773660[];
extern "C" char DAT_007F7AA0[];
extern "C" int __cdecl sub_006EE870(int);

namespace audio {

class SeqEventVarPitchRand;

struct Instance
{
    void* m_vtable;
    SeqEventVarPitchRand* m_parent;
    int m_unk8;
    int m_unkC;
    bool m_unk10;

    void* operator new(size_t)
    {
        return (void*)sub_006EE870((int)DAT_007F7AA0);
    }

    Instance(SeqEventVarPitchRand* parent)
    {
        m_unkC = 0;
        m_unk10 = false;
        m_parent = parent;
        m_vtable = DAT_00773660;
    }
};

class SeqEventVarPitchRand
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02(int a1);
    virtual int vfunc_03();
    virtual SeqEventVarPitchRand* vfunc_04(int a1);
};

void SeqEventVarPitchRand::vfunc_02(int a1)
{
    ((Object*)a1)->sub_007007A0((int)new Instance(this));
}

}

// [TODO] 0x006F9940 audio::SeqActionVarPitchRand::vfunc_06 (51 B)
// ============================================================================
// [VERIFIED] audio::SeqEventType<audio::SeqEventVarPitchRand>::vfunc_01 (0x006F9980, 55 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as audio::SeqEventType<audio::SeqEventVarPitchRand>::vfunc_01 (0x002DBD40), which was matched first;
// its addresses and names were swapped for this function's.
// audio::SeqEventType<audio::SeqEventVarPitchRand>::vfunc_01 (0x006F9980, 55 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_006F5850();
};

extern "C" char DAT_00773680[];
extern "C" char DAT_007F7A98[];
extern "C" int __cdecl sub_006EE870(int);

namespace audio { class SeqEventVarPitchRand; }

namespace audio { 
template <class T0> class SeqEventType
{
public:
    virtual void vfunc_00();
    virtual int vfunc_01();
};
}

template <> int audio::SeqEventType<audio::SeqEventVarPitchRand>::vfunc_01()
{
    int t1;

    t1 = sub_006EE870((int)DAT_007F7A98);
    if (t1) {
        ((Object*)t1)->sub_006F5850();
        *(int*)t1 = (int)DAT_00773680;
        *(int*)(t1 + 8) = 0x3F4CCCCD;
        *(int*)(t1 + 12) = 0x3F99999A;
        return t1;
    }
    return 0;
}

// ============================================================================
// [VERIFIED] sub_006F99C0 (0x006F99C0, 116 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_002D8E20 (0x002D8E20), which was matched first;
// its addresses and names were swapped for this function's.
struct Name
{
    int data[3];
    void sub_006EB7A0(const char* text, int flags);
    void sub_006EBBD0();
};

struct Object
{
    void sub_006F5BB0(Name* a, Name* b);
};

extern "C" char DAT_00773654[];
extern "C" char DAT_00773698[];
extern "C" char DAT_007736A4[];
extern "C" Object* DAT_0085D53C;
extern "C" void* __cdecl sub_0043CE00(unsigned int size);

// Makes the single instance: builds it from two names and keeps it in a global (or null).
void __cdecl sub_006F99C0(void)
{
    Name first, second;

    first.sub_006EB7A0(DAT_007736A4, 0);
    second.sub_006EB7A0(DAT_00773698, 0);
    Object* made = (Object*)sub_0043CE00(44);
    if (made) {
        made->sub_006F5BB0(&second, &first);
        *(void**)made = DAT_00773654;
        DAT_0085D53C = made;
    } else {
        DAT_0085D53C = 0;
    }
    second.sub_006EBBD0();
    first.sub_006EBBD0();
}

// ============================================================================
// [VERIFIED] audio::SeqEventVarPitch::vfunc_00 (0x006F9A40, 52 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as audio::SeqEventNestTrack::vfunc_01 (0x002D8D00), which was matched first;
// its addresses and names were swapped for this function's.
// audio::SeqEventVarPitch::vfunc_00 (0x006F9A40, 52 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" bool __cdecl sub_006F33D0(int, int);
extern "C" bool __stdcall sub_006F5740(int);

namespace audio {

class SeqEventVarPitch
{
public:
    virtual void vfunc_00();
    virtual int vfunc_00(int a1);
};

int SeqEventVarPitch::vfunc_00(int a1)
{
    if (sub_006F5740(a1)) {
        if (!sub_006F33D0(a1, (int)this + 8)) goto L_2D;
        return 1;
    }
L_2D:
    return 0;
}

}

// ============================================================================
// [VERIFIED] audio::SeqActionVarPitch::vfunc_00 (0x006F9A80, 36 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as SoundManager::SoundPlayerHandle::vfunc_00 (0x00077F00), which was matched first;
// its addresses and names were swapped for this function's.
// audio::SeqActionVarPitch::vfunc_00 (0x006F9A80, 36 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_00772F80[];
extern "C" char DAT_007F7B44[];
extern "C" void __cdecl sub_006EE890(int, int);

namespace audio {

class SeqActionVarPitch
{
public:
    virtual SeqActionVarPitch* vfunc_00(int a1);
};

SeqActionVarPitch* SeqActionVarPitch::vfunc_00(int a1)
{
    *(int*)this = (int)DAT_00772F80;
    if (a1 & 1) {
        sub_006EE890((int)DAT_007F7B44, (int)this);
    }
    return this;
}

}

// ============================================================================
// [VERIFIED] audio::SeqEventVarPitch::vfunc_03 (0x006F9AB0, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as audio::SeqEventNestTrack::vfunc_03 (PC 0x006F6960), which was matched first;
// its addresses and names were swapped for this function's.
// bin: pc
// va: 0x006F9AB0
// what: Returns a value kept in the game's data.
// tool: Claude Fable 5.2 (look-alike of pc 0x006DF7F0, names and addresses swapped)
// audio::SeqEventVarPitch::vfunc_03 (0x006F9AB0, 6 bytes)
extern "C" int DAT_0085D540;

namespace audio {

class SeqEventVarPitch
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual int vfunc_03();
};

int SeqEventVarPitch::vfunc_03()
{
    return DAT_0085D540;
}

}

// ============================================================================
// [VERIFIED] audio::SeqEventVarPitch::vfunc_04 (0x006F9AC0, 35 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as SoundManager::StatePropSoundPlayer::vfunc_00 (0x00082430), which was matched first;
// its addresses and names were swapped for this function's.
// audio::SeqEventVarPitch::vfunc_04 (0x006F9AC0, 35 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_007F7B3C[];
extern "C" void __cdecl sub_006F5730(void);
extern "C" void __cdecl sub_006EE890(int, int);

namespace audio {

class SeqEventVarPitch
{
public:
    virtual SeqEventVarPitch* vfunc_04(int a1);
};

SeqEventVarPitch* SeqEventVarPitch::vfunc_04(int a1)
{
    sub_006F5730();
    if (a1 & 1) {
        sub_006EE890((int)DAT_007F7B3C, (int)this);
    }
    return this;
}

}

// ============================================================================
// [VERIFIED] audio::SeqEventVarPitch::vfunc_02 (0x006F9AF0, 67 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as audio::SeqEventChannelSendVolumes::vfunc_02 (0x002D8FA0), which was matched first;
// its addresses and names were swapped for this function's.
#include <stddef.h>

struct Object
{
    void sub_007007A0(int);
};

extern "C" char DAT_007736D8[];
extern "C" char DAT_007F7B44[];
extern "C" int __cdecl sub_006EE870(int);

namespace audio {

class SeqEventVarPitch;

struct Instance
{
    void* m_vtable;
    SeqEventVarPitch* m_parent;
    int m_unk8;
    int m_unkC;
    bool m_unk10;

    void* operator new(size_t)
    {
        return (void*)sub_006EE870((int)DAT_007F7B44);
    }

    Instance(SeqEventVarPitch* parent)
    {
        m_unkC = 0;
        m_unk10 = false;
        m_parent = parent;
        m_vtable = DAT_007736D8;
    }
};

class SeqEventVarPitch
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02(int a1);
    virtual int vfunc_03();
    virtual SeqEventVarPitch* vfunc_04(int a1);
};

void SeqEventVarPitch::vfunc_02(int a1)
{
    ((Object*)a1)->sub_007007A0((int)new Instance(this));
}

}

// ============================================================================
// [VERIFIED] audio::SeqActionVarPitch::vfunc_06 (0x006F9B40, 19 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as audio::SeqActionVarPitch::vfunc_06 (0x002DBF00), which was matched first;
// its addresses and names were swapped for this function's.
// audio::SeqActionVarPitch::vfunc_06 (0x006F9B40, 19 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

namespace audio {

class SeqActionVarPitch
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual void vfunc_05();
    virtual void vfunc_06(int a1);
    int m_Field04; // +0x04
};

void SeqActionVarPitch::vfunc_06(int a1)
{
    int t1;

    t1 = m_Field04 + 8;
    *(int*)(*(int*)(a1 + 4) + 36) = m_Field04 + 8;
}

}

// ============================================================================
// [VERIFIED] audio::SeqEventType<audio::SeqEventVarPitch>::vfunc_01 (0x006F9B60, 48 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as audio::SeqEventType<audio::SeqEventVarVolume>::vfunc_01 (0x002DB6F0), which was matched first;
// its addresses and names were swapped for this function's.
// audio::SeqEventType<audio::SeqEventVarPitch>::vfunc_01 (0x006F9B60, 48 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_006F5850();
};

extern "C" char DAT_007736F8[];
extern "C" char DAT_007F7B3C[];
extern "C" int __cdecl sub_006EE870(int);

namespace audio { class SeqEventVarPitch; }

namespace audio { 
template <class T0> class SeqEventType
{
public:
    virtual void vfunc_00();
    virtual int vfunc_01();
};
}

template <> int audio::SeqEventType<audio::SeqEventVarPitch>::vfunc_01()
{
    int t1;

    t1 = sub_006EE870((int)DAT_007F7B3C);
    if (t1) {
        ((Object*)t1)->sub_006F5850();
        *(int*)t1 = (int)DAT_007736F8;
        *(int*)(t1 + 8) = 0x3F800000;
        return t1;
    }
    return 0;
}

// ============================================================================
// [VERIFIED] sub_006F9B90 (0x006F9B90, 116 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_002D8E20 (0x002D8E20), which was matched first;
// its addresses and names were swapped for this function's.
struct Name
{
    int data[3];
    void sub_006EB7A0(const char* text, int flags);
    void sub_006EBBD0();
};

struct Object
{
    void sub_006F5BB0(Name* a, Name* b);
};

extern "C" char DAT_007736CC[];
extern "C" char DAT_0073C6BC[];
extern "C" char DAT_00773710[];
extern "C" Object* DAT_0085D540;
extern "C" void* __cdecl sub_0043CE00(unsigned int size);

// Makes the single instance: builds it from two names and keeps it in a global (or null).
void __cdecl sub_006F9B90(void)
{
    Name first, second;

    first.sub_006EB7A0(DAT_00773710, 0);
    second.sub_006EB7A0(DAT_0073C6BC, 0);
    Object* made = (Object*)sub_0043CE00(44);
    if (made) {
        made->sub_006F5BB0(&second, &first);
        *(void**)made = DAT_007736CC;
        DAT_0085D540 = made;
    } else {
        DAT_0085D540 = 0;
    }
    second.sub_006EBBD0();
    first.sub_006EBBD0();
}

// ============================================================================
// [VERIFIED] audio::SeqEventStream::vfunc_01 (0x006F9C10, 48 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as audio::SeqEventVarPosDist::vfunc_01 (0x002DB9F0), which was matched first;
// its addresses and names were swapped for this function's.
// audio::SeqEventStream::vfunc_01 (0x006F9C10, 48 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field08
{
    bool sub_00559000(int);
};

extern "C" bool __stdcall sub_006F5760(int);

namespace audio {

class SeqEventStream
{
public:
    virtual void vfunc_00();
    virtual int vfunc_01(int a1);
    char m_pad04[0x4];
    Field08 m_Field08; // +0x08
};

int SeqEventStream::vfunc_01(int a1)
{
    if (sub_006F5760(a1)) {
        if (!m_Field08.sub_00559000(a1)) goto L_29;
        return 1;
    }
L_29:
    return 0;
}

}

// ============================================================================
// [VERIFIED] audio::SeqEventStream::vfunc_00 (0x006F9C40, 48 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as audio::SeqEventVarPosDist::vfunc_01 (0x002DB9F0), which was matched first;
// its addresses and names were swapped for this function's.
// audio::SeqEventStream::vfunc_00 (0x006F9C40, 48 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field08
{
    bool sub_006EC4F0(int);
};

extern "C" bool __stdcall sub_006F5740(int);

namespace audio {

class SeqEventStream
{
public:
    virtual void vfunc_00();
    virtual int vfunc_00(int a1);
    char m_pad04[0x4];
    Field08 m_Field08; // +0x08
};

int SeqEventStream::vfunc_00(int a1)
{
    if (sub_006F5740(a1)) {
        if (!m_Field08.sub_006EC4F0(a1)) goto L_29;
        return 1;
    }
L_29:
    return 0;
}

}

// [TODO] 0x006F9C70 audio::SeqActionStream::vfunc_02 (62 B)
// [TODO] 0x006F9CB0 audio::SeqActionStream::vfunc_03 (52 B)
// [TODO] 0x006F9CF0 sub_006F9CF0 (48 B)
// [TODO] 0x006F9D20 sub_006F9D20 (247 B)
// ============================================================================
// [VERIFIED] audio::SeqEventStream::vfunc_03 (0x006F9E20, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as audio::SeqEventNestTrack::vfunc_03 (PC 0x006F6960), which was matched first;
// its addresses and names were swapped for this function's.
// bin: pc
// va: 0x006F9E20
// what: Returns a value kept in the game's data.
// tool: Claude Fable 5.2 (look-alike of pc 0x006DF7F0, names and addresses swapped)
// audio::SeqEventStream::vfunc_03 (0x006F9E20, 6 bytes)
extern "C" int DAT_0085D544;

namespace audio {

class SeqEventStream
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual int vfunc_03();
};

int SeqEventStream::vfunc_03()
{
    return DAT_0085D544;
}

}

// ============================================================================
// [VERIFIED] audio::SeqEventStream::vfunc_04 (0x006F9E30, 35 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as SoundManager::StatePropSoundPlayer::vfunc_00 (0x00082430), which was matched first;
// its addresses and names were swapped for this function's.
// audio::SeqEventStream::vfunc_04 (0x006F9E30, 35 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_007F7BB0[];
extern "C" void __cdecl sub_006F5730(void);
extern "C" void __cdecl sub_006EE890(int, int);

namespace audio {

class SeqEventStream
{
public:
    virtual SeqEventStream* vfunc_04(int a1);
};

SeqEventStream* SeqEventStream::vfunc_04(int a1)
{
    sub_006F5730();
    if (a1 & 1) {
        sub_006EE890((int)DAT_007F7BB0, (int)this);
    }
    return this;
}

}

// ============================================================================
// [VERIFIED] audio::SeqActionStream::vfunc_00 (0x006F9E60, 36 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as SoundManager::SoundPlayerHandle::vfunc_00 (0x00077F00), which was matched first;
// its addresses and names were swapped for this function's.
// audio::SeqActionStream::vfunc_00 (0x006F9E60, 36 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_00772F80[];
extern "C" char DAT_007F7BB8[];
extern "C" void __cdecl sub_006EE890(int, int);

namespace audio {

class SeqActionStream
{
public:
    virtual SeqActionStream* vfunc_00(int a1);
};

SeqActionStream* SeqActionStream::vfunc_00(int a1)
{
    *(int*)this = (int)DAT_00772F80;
    if (a1 & 1) {
        sub_006EE890((int)DAT_007F7BB8, (int)this);
    }
    return this;
}

}

// [TODO] 0x006F9E90 sub_006F9E90 (119 B)
// ============================================================================
// [VERIFIED] audio::SeqEventType<audio::SeqEventStream>::vfunc_01 (0x006F9F10, 49 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as audio::SeqEventType<audio::SeqEventStream>::vfunc_01 (0x002DC2F0), which was matched first;
// its addresses and names were swapped for this function's.
// audio::SeqEventType<audio::SeqEventStream>::vfunc_01 (0x006F9F10, 49 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_004A1B60();
    void sub_006F5850();
};

extern "C" char DAT_0077374C[];
extern "C" char DAT_007F7BB0[];
extern "C" int __cdecl sub_006EE870(int);

namespace audio { class SeqEventStream; }

namespace audio { 
template <class T0> class SeqEventType
{
public:
    virtual void vfunc_00();
    virtual int vfunc_01();
};
}

template <> int audio::SeqEventType<audio::SeqEventStream>::vfunc_01()
{
    int t1;

    t1 = sub_006EE870((int)DAT_007F7BB0);
    if (t1) {
        ((Object*)t1)->sub_006F5850();
        *(int*)t1 = (int)DAT_0077374C;
        ((Object*)t1 + 8)->sub_004A1B60();
        return t1;
    }
    return 0;
}

// ============================================================================
// [VERIFIED] sub_006F9F50 (0x006F9F50, 116 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_002D8E20 (0x002D8E20), which was matched first;
// its addresses and names were swapped for this function's.
struct Name
{
    int data[3];
    void sub_006EB7A0(const char* text, int flags);
    void sub_006EBBD0();
};

struct Object
{
    void sub_006F5BB0(Name* a, Name* b);
};

extern "C" char DAT_00773740[];
extern "C" char DAT_00773780[];
extern "C" char DAT_00773788[];
extern "C" Object* DAT_0085D544;
extern "C" void* __cdecl sub_0043CE00(unsigned int size);

// Makes the single instance: builds it from two names and keeps it in a global (or null).
void __cdecl sub_006F9F50(void)
{
    Name first, second;

    first.sub_006EB7A0(DAT_00773788, 0);
    second.sub_006EB7A0(DAT_00773780, 0);
    Object* made = (Object*)sub_0043CE00(44);
    if (made) {
        made->sub_006F5BB0(&second, &first);
        *(void**)made = DAT_00773740;
        DAT_0085D544 = made;
    } else {
        DAT_0085D544 = 0;
    }
    second.sub_006EBBD0();
    first.sub_006EBBD0();
}

// [TODO] 0x006F9FD0 audio::SeqEventStream::vfunc_02 (96 B)
// [TODO] 0x006FA030 sub_006FA030 (824 B)
// [TODO] 0x006FA370 audio::SeqActionStream::vfunc_01 (133 B)
// [TODO] 0x006FA400 audio::SeqActionStream::vfunc_05 (580 B)
// [TODO] 0x006FA650 audio::SeqActionSilence::vfunc_02 (33 B)
// ============================================================================
// [VERIFIED] audio::SeqActionSilence::vfunc_01 (0x006FA680, 29 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as audio::SeqActionSilence::vfunc_01 (0x002DCAD0), which was matched first;
// its addresses and names were swapped for this function's.
// audio::SeqActionSilence::vfunc_01 (0x006FA680, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int __cdecl sub_006DC040(void);

namespace audio {

class SeqActionSilence
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01(int a1);
    void sub_006F57A0(int, int);
    char m_pad04[0x18];
    int m_Field1C; // +0x1C
};

void SeqActionSilence::vfunc_01(int a1)
{
    m_Field1C = sub_006DC040();
    sub_006F57A0(3, a1);
}

}

// ============================================================================
// [VERIFIED] audio::SeqActionWaitBeat::vfunc_03 (0x006FA6A0, 15 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as audio::SeqActionWaitBeat::vfunc_03 (Proto 0x002A41A0), which was matched first;
// its addresses and names were swapped for this function's.
// audio::SeqActionWaitBeat::vfunc_03 (Proto 0x006FA6A0, 15 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __stdcall sub_006F57A0(int, int);

namespace audio {

class SeqActionWaitBeat
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03(int a1);
};

void SeqActionWaitBeat::vfunc_03(int a1)
{
    sub_006F57A0(2, a1);
}

}

// ============================================================================
// [VERIFIED] audio::SeqActionWaitBeat::vfunc_04 (0x006FA6B0, 15 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as pure3d::SpriteObject::vfunc_31 (Proto 0x0021E500), which was matched first;
// its addresses and names were swapped for this function's.
// audio::SeqActionWaitBeat::vfunc_04 (Proto 0x006FA6B0, 15 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __stdcall sub_006F57A0(int, int);

namespace audio {

class SeqActionWaitBeat
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04(int a1);
};

void SeqActionWaitBeat::vfunc_04(int a1)
{
    sub_006F57A0(0, a1);
}

}

// [TODO] 0x006FA6C0 audio::SeqActionSilence::vfunc_05 (113 B)
// ============================================================================
// [VERIFIED] audio::SeqEventSilence::vfunc_03 (0x006FA740, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as audio::SeqEventNestTrack::vfunc_03 (PC 0x006F6960), which was matched first;
// its addresses and names were swapped for this function's.
// bin: pc
// va: 0x006FA740
// what: Returns a value kept in the game's data.
// tool: Claude Fable 5.2 (look-alike of pc 0x006DF7F0, names and addresses swapped)
// audio::SeqEventSilence::vfunc_03 (0x006FA740, 6 bytes)
extern "C" int DAT_0085D548;

namespace audio {

class SeqEventSilence
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual int vfunc_03();
};

int SeqEventSilence::vfunc_03()
{
    return DAT_0085D548;
}

}

// ============================================================================
// [VERIFIED] audio::SeqEventSilence::vfunc_04 (0x006FA750, 35 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as SoundManager::StatePropSoundPlayer::vfunc_00 (0x00082430), which was matched first;
// its addresses and names were swapped for this function's.
// audio::SeqEventSilence::vfunc_04 (0x006FA750, 35 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_007F7C4C[];
extern "C" void __cdecl sub_006F5730(void);
extern "C" void __cdecl sub_006EE890(int, int);

namespace audio {

class SeqEventSilence
{
public:
    virtual SeqEventSilence* vfunc_04(int a1);
};

SeqEventSilence* SeqEventSilence::vfunc_04(int a1)
{
    sub_006F5730();
    if (a1 & 1) {
        sub_006EE890((int)DAT_007F7C4C, (int)this);
    }
    return this;
}

}

// ============================================================================
// [VERIFIED] audio::SeqActionSilence::vfunc_00 (0x006FA780, 36 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as SoundManager::SoundPlayerHandle::vfunc_00 (0x00077F00), which was matched first;
// its addresses and names were swapped for this function's.
// audio::SeqActionSilence::vfunc_00 (0x006FA780, 36 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_00772F80[];
extern "C" char DAT_007F7C54[];
extern "C" void __cdecl sub_006EE890(int, int);

namespace audio {

class SeqActionSilence
{
public:
    virtual SeqActionSilence* vfunc_00(int a1);
};

SeqActionSilence* SeqActionSilence::vfunc_00(int a1)
{
    *(int*)this = (int)DAT_00772F80;
    if (a1 & 1) {
        sub_006EE890((int)DAT_007F7C54, (int)this);
    }
    return this;
}

}

// ============================================================================
// [VERIFIED] audio::SeqEventType<audio::SeqEventSilence>::vfunc_01 (0x006FA7B0, 55 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as audio::SeqEventType<audio::SeqEventSilence>::vfunc_01 (0x002DCBC0), which was matched first;
// its addresses and names were swapped for this function's.
// audio::SeqEventType<audio::SeqEventSilence>::vfunc_01 (0x006FA7B0, 55 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_006F5850();
};

extern "C" char DAT_007737B4[];
extern "C" char DAT_007F7C4C[];
extern "C" int __cdecl sub_006EE870(int);

namespace audio { class SeqEventSilence; }

namespace audio { 
template <class T0> class SeqEventType
{
public:
    virtual void vfunc_00();
    virtual int vfunc_01();
};
}

template <> int audio::SeqEventType<audio::SeqEventSilence>::vfunc_01()
{
    int t1;

    t1 = sub_006EE870((int)DAT_007F7C4C);
    if (t1) {
        ((Object*)t1)->sub_006F5850();
        *(int*)t1 = (int)DAT_007737B4;
        *(int*)(t1 + 8) = 500;
        *(int*)(t1 + 12) = 1000;
        return t1;
    }
    return 0;
}

// ============================================================================
// [VERIFIED] sub_006FA7F0 (0x006FA7F0, 116 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_002D8E20 (0x002D8E20), which was matched first;
// its addresses and names were swapped for this function's.
struct Name
{
    int data[3];
    void sub_006EB7A0(const char* text, int flags);
    void sub_006EBBD0();
};

struct Object
{
    void sub_006F5BB0(Name* a, Name* b);
};

extern "C" char DAT_007737A8[];
extern "C" char DAT_007737E8[];
extern "C" char DAT_007737F0[];
extern "C" Object* DAT_0085D548;
extern "C" void* __cdecl sub_0043CE00(unsigned int size);

// Makes the single instance: builds it from two names and keeps it in a global (or null).
void __cdecl sub_006FA7F0(void)
{
    Name first, second;

    first.sub_006EB7A0(DAT_007737F0, 0);
    second.sub_006EB7A0(DAT_007737E8, 0);
    Object* made = (Object*)sub_0043CE00(44);
    if (made) {
        made->sub_006F5BB0(&second, &first);
        *(void**)made = DAT_007737A8;
        DAT_0085D548 = made;
    } else {
        DAT_0085D548 = 0;
    }
    second.sub_006EBBD0();
    first.sub_006EBBD0();
}

// [TODO] 0x006FA870 audio::SeqEventSilence::vfunc_02 (112 B)
// ============================================================================
// [VERIFIED] audio::SeqEventLogicRepeat::vfunc_01 (0x006FA8E0, 109 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// bin: pc
// va: 0x006FA8E0
// what: 
// tool: the portal's starter code (no AI)

// audio::SeqEventLogicRepeat::vfunc_01 (PC 0x006FA8E0, 109 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" bool __cdecl sub_006F33F0(int, int);

namespace audio {

class SeqEventLogicRepeat
{
public:
    virtual void vfunc_00();
    virtual int vfunc_01(int a1);
    bool sub_006F5760(int);
    bool sub_006F5AC0(int);
    char m_pad04[0xC];
    bool m_Field10; // +0x10
    bool m_Field11; // +0x11
};

int SeqEventLogicRepeat::vfunc_01(int a1)
{
    int r_ebp, r_ebx;

    r_ebp = (unsigned char)m_Field10;
    if (m_Field10 == 255) {
        r_ebp |= -1;
    }
    r_ebx = (unsigned char)m_Field11;
    if (m_Field11 == 255) {
        r_ebx |= -1;
    }
    if (sub_006F5760(a1)) {
        if (!sub_006F5AC0(a1)) goto L_64;
        if (!sub_006F33F0(a1, r_ebp)) goto L_64;
        if (!sub_006F33F0(a1, r_ebx)) goto L_64;
        return 1;
    }
L_64:
    return 0;
}

}

// [TODO] 0x006FA950 audio::SeqEventLogicRepeat::vfunc_00 (153 B)
// ============================================================================
// [VERIFIED] sub_006FA9F0 (0x006FA9F0, 116 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_002D8E20 (0x002D8E20), which was matched first;
// its addresses and names were swapped for this function's.
struct Name
{
    int data[3];
    void sub_006EB7A0(const char* text, int flags);
    void sub_006EBBD0();
};

struct Object
{
    void sub_006F5BB0(Name* a, Name* b);
};

extern "C" char DAT_00773810[];
extern "C" char DAT_00773818[];
extern "C" char DAT_0077381C[];
extern "C" Object* DAT_0085D54C;
extern "C" void* __cdecl sub_0043CE00(unsigned int size);

// Makes the single instance: builds it from two names and keeps it in a global (or null).
void __cdecl sub_006FA9F0(void)
{
    Name first, second;

    first.sub_006EB7A0(DAT_0077381C, 0);
    second.sub_006EB7A0(DAT_00773818, 0);
    Object* made = (Object*)sub_0043CE00(44);
    if (made) {
        made->sub_006F5BB0(&second, &first);
        *(void**)made = DAT_00773810;
        DAT_0085D54C = made;
    } else {
        DAT_0085D54C = 0;
    }
    second.sub_006EBBD0();
    first.sub_006EBBD0();
}

// ============================================================================
// [VERIFIED] sub_006FAA70 (0x006FAA70, 34 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_002DCE80 (0x002DCE80), which was matched first;
// its addresses and names were swapped for this function's.
// sub_006FAA70 (0x006FAA70, 34 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_00773834[];
extern "C" void __cdecl sub_006F5850(void);

class Class_006FAA70
{
public:
    Class_006FAA70* sub_006FAA70();
    int m_Field00; // +0x00
    char m_pad04[0x4];
    int m_Field08; // +0x08
    int m_Field0C; // +0x0C
    bool m_Field10; // +0x10
    bool m_Field11; // +0x11
};

Class_006FAA70* Class_006FAA70::sub_006FAA70()
{
    sub_006F5850();
    m_Field08 = 0;
    m_Field0C = 0;
    m_Field10 = true;
    m_Field11 = true;
    m_Field00 = (int)DAT_00773834;
    return this;
}

// ============================================================================
// [VERIFIED] audio::SeqEventLogicRepeat::vfunc_04 (0x006FAAA0, 35 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as SoundManager::StatePropSoundPlayer::vfunc_00 (0x00082430), which was matched first;
// its addresses and names were swapped for this function's.
// audio::SeqEventLogicRepeat::vfunc_04 (0x006FAAA0, 35 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_007F7CF8[];
extern "C" void __cdecl sub_006F5C50(void);
extern "C" void __cdecl sub_006EE890(int, int);

namespace audio {

class SeqEventLogicRepeat
{
public:
    virtual SeqEventLogicRepeat* vfunc_04(int a1);
};

SeqEventLogicRepeat* SeqEventLogicRepeat::vfunc_04(int a1)
{
    sub_006F5C50();
    if (a1 & 1) {
        sub_006EE890((int)DAT_007F7CF8, (int)this);
    }
    return this;
}

}

// ============================================================================
// [VERIFIED] audio::SeqEventLogicRepeat::vfunc_03 (0x006FAAD0, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as audio::SeqEventNestTrack::vfunc_03 (PC 0x006F6960), which was matched first;
// its addresses and names were swapped for this function's.
// bin: pc
// va: 0x006FAAD0
// what: Returns a value kept in the game's data.
// tool: Claude Fable 5.2 (look-alike of pc 0x006DF7F0, names and addresses swapped)
// audio::SeqEventLogicRepeat::vfunc_03 (0x006FAAD0, 6 bytes)
extern "C" int DAT_0085D54C;

namespace audio {

class SeqEventLogicRepeat
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual int vfunc_03();
};

int SeqEventLogicRepeat::vfunc_03()
{
    return DAT_0085D54C;
}

}

// [TODO] 0x006FAAE0 sub_006FAAE0 (116 B)
// ============================================================================
// [VERIFIED] audio::SeqCommandLogicRepeat::vfunc_01 (0x006FAB60, 36 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as SoundManager::SoundPlayerHandle::vfunc_00 (0x00077F00), which was matched first;
// its addresses and names were swapped for this function's.
// audio::SeqCommandLogicRepeat::vfunc_01 (0x006FAB60, 36 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_007730E0[];
extern "C" char DAT_007F7D00[];
extern "C" void __cdecl sub_006EE890(int, int);

namespace audio {

class SeqCommandLogicRepeat
{
public:
    virtual SeqCommandLogicRepeat* vfunc_01(int a1);
};

SeqCommandLogicRepeat* SeqCommandLogicRepeat::vfunc_01(int a1)
{
    *(int*)this = (int)DAT_007730E0;
    if (a1 & 1) {
        sub_006EE890((int)DAT_007F7D00, (int)this);
    }
    return this;
}

}

// [TODO] 0x006FAB90 audio::SeqCommandLogicRepeat::vfunc_00 (114 B)
// [TODO] 0x006FAC10 audio::SeqEventType<audio::SeqEventLogicRepeat>::vfunc_01 (63 B)
// [TODO] 0x006FAC50 audio::SeqEventLogicRepeat::vfunc_02 (58 B)
// ============================================================================
// [VERIFIED] audio::SeqEventLogicOr::vfunc_01 (0x006FAC90, 64 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as audio::SeqEventLogicOr::vfunc_01 (0x002DD0A0), which was matched first;
// its addresses and names were swapped for this function's.
// audio::SeqEventLogicOr::vfunc_01 (0x006FAC90, 64 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" bool __cdecl sub_006F33F0(int, int);
extern "C" bool __stdcall sub_006F5760(int);

namespace audio {

class SeqEventLogicOr
{
public:
    virtual void vfunc_00();
    virtual int vfunc_01(int a1);
    bool sub_006F5AC0(int);
    char m_pad04[0xC];
    int m_Field10; // +0x10
};

int SeqEventLogicOr::vfunc_01(int a1)
{
    if (sub_006F5760(a1)) {
        if (!sub_006F33F0(a1, m_Field10)) goto L_39;
        if (!sub_006F5AC0(a1)) goto L_39;
        return 1;
    }
L_39:
    return 0;
}

}

// ============================================================================
// [VERIFIED] audio::SeqEventLogicOr::vfunc_00 (0x006FACD0, 64 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as audio::SeqEventLogicOr::vfunc_00 (0x002DD0E0), which was matched first;
// its addresses and names were swapped for this function's.
// audio::SeqEventLogicOr::vfunc_00 (0x006FACD0, 64 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" bool __cdecl sub_006F33D0(int, int);
extern "C" bool __stdcall sub_006F5740(int);

namespace audio {

class SeqEventLogicOr
{
public:
    virtual int vfunc_00(int a1);
    bool sub_006F5A60(int);
    char m_pad04[0xC];
    int m_Field10; // +0x10
};

int SeqEventLogicOr::vfunc_00(int a1)
{
    if (sub_006F5740(a1)) {
        if (!sub_006F33D0(a1, (int)(&m_Field10))) goto L_39;
        if (!sub_006F5A60(a1)) goto L_39;
        return 1;
    }
L_39:
    return 0;
}

}

// ============================================================================
// [VERIFIED] audio::SeqCommandLogicOr::vfunc_01 (0x006FAD10, 36 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as SoundManager::SoundPlayerHandle::vfunc_00 (0x00077F00), which was matched first;
// its addresses and names were swapped for this function's.
// audio::SeqCommandLogicOr::vfunc_01 (0x006FAD10, 36 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_007730E0[];
extern "C" char DAT_007F7D9C[];
extern "C" void __cdecl sub_006EE890(int, int);

namespace audio {

class SeqCommandLogicOr
{
public:
    virtual SeqCommandLogicOr* vfunc_01(int a1);
};

SeqCommandLogicOr* SeqCommandLogicOr::vfunc_01(int a1)
{
    *(int*)this = (int)DAT_007730E0;
    if (a1 & 1) {
        sub_006EE890((int)DAT_007F7D9C, (int)this);
    }
    return this;
}

}

// ============================================================================
// [VERIFIED] sub_006FAD40 (0x006FAD40, 116 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_002D8E20 (0x002D8E20), which was matched first;
// its addresses and names were swapped for this function's.
struct Name
{
    int data[3];
    void sub_006EB7A0(const char* text, int flags);
    void sub_006EBBD0();
};

struct Object
{
    void sub_006F5BB0(Name* a, Name* b);
};

extern "C" char DAT_00773868[];
extern "C" char DAT_00771844[];
extern "C" char DAT_0077387C[];
extern "C" Object* DAT_0085D554;
extern "C" void* __cdecl sub_0043CE00(unsigned int size);

// Makes the single instance: builds it from two names and keeps it in a global (or null).
void __cdecl sub_006FAD40(void)
{
    Name first, second;

    first.sub_006EB7A0(DAT_0077387C, 0);
    second.sub_006EB7A0(DAT_00771844, 0);
    Object* made = (Object*)sub_0043CE00(44);
    if (made) {
        made->sub_006F5BB0(&second, &first);
        *(void**)made = DAT_00773868;
        DAT_0085D554 = made;
    } else {
        DAT_0085D554 = 0;
    }
    second.sub_006EBBD0();
    first.sub_006EBBD0();
}

// ============================================================================
// [VERIFIED] audio::SeqEventLogicOr::vfunc_03 (0x006FADC0, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as audio::SeqEventNestTrack::vfunc_03 (PC 0x006F6960), which was matched first;
// its addresses and names were swapped for this function's.
// bin: pc
// va: 0x006FADC0
// what: Returns a value kept in the game's data.
// tool: Claude Fable 5.2 (look-alike of pc 0x006DF7F0, names and addresses swapped)
// audio::SeqEventLogicOr::vfunc_03 (0x006FADC0, 6 bytes)
extern "C" int DAT_0085D554;

namespace audio {

class SeqEventLogicOr
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual int vfunc_03();
};

int SeqEventLogicOr::vfunc_03()
{
    return DAT_0085D554;
}

}

// ============================================================================
// [VERIFIED] audio::SeqEventLogicOr::vfunc_04 (0x006FADD0, 35 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as SoundManager::StatePropSoundPlayer::vfunc_00 (0x00082430), which was matched first;
// its addresses and names were swapped for this function's.
// audio::SeqEventLogicOr::vfunc_04 (0x006FADD0, 35 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_007F7D94[];
extern "C" void __cdecl sub_006F5C50(void);
extern "C" void __cdecl sub_006EE890(int, int);

namespace audio {

class SeqEventLogicOr
{
public:
    virtual SeqEventLogicOr* vfunc_04(int a1);
};

SeqEventLogicOr* SeqEventLogicOr::vfunc_04(int a1)
{
    sub_006F5C50();
    if (a1 & 1) {
        sub_006EE890((int)DAT_007F7D94, (int)this);
    }
    return this;
}

}

// [TODO] 0x006FAE00 audio::SeqEventLogicOr::vfunc_02 (59 B)
// [TODO] 0x006FAE40 audio::SeqCommandLogicOr::vfunc_00 (290 B)
// ============================================================================
// [VERIFIED] audio::SeqEventType<audio::SeqEventLogicOr>::vfunc_01 (0x006FAF70, 62 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as audio::SeqEventType<audio::SeqEventLogicOr>::vfunc_01 (0x002DD360), which was matched first;
// its addresses and names were swapped for this function's.
// audio::SeqEventType<audio::SeqEventLogicOr>::vfunc_01 (0x006FAF70, 62 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_006F5850();
};

extern "C" char DAT_00773890[];
extern "C" char DAT_007F7D94[];
extern "C" int __cdecl sub_006EE870(int);

namespace audio { class SeqEventLogicOr; }

namespace audio { 
template <class T0> class SeqEventType
{
public:
    virtual void vfunc_00();
    virtual int vfunc_01();
};
}

template <> int audio::SeqEventType<audio::SeqEventLogicOr>::vfunc_01()
{
    int t1;

    t1 = sub_006EE870((int)DAT_007F7D94);
    if (t1) {
        ((Object*)t1)->sub_006F5850();
        *(int*)(t1 + 8) = 0;
        *(int*)(t1 + 12) = 0;
        *(int*)t1 = (int)DAT_00773890;
        *(int*)(t1 + 16) = 0x3F000000;
        return t1;
    }
    return 0;
}

// ============================================================================
// [VERIFIED] audio::SeqActionCrossFade::vfunc_04 (0x006FAFB0, 40 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as audio::SeqActionCrossFade::vfunc_04 (0x002DD3A0), which was matched first;
// its addresses and names were swapped for this function's.
// audio::SeqActionCrossFade::vfunc_04 (0x006FAFB0, 40 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field14
{
    void sub_006FDB80();
};

namespace audio {

class SeqActionCrossFade
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04(int a1);
    void sub_006F57A0(int, int);
    char m_pad04[0x10];
    Field14* m_Field14; // +0x14
};

void SeqActionCrossFade::vfunc_04(int a1)
{
    if (m_Field14) {
        m_Field14->sub_006FDB80();
        m_Field14 = 0;
    }
    sub_006F57A0(0, a1);
}

}

// [TODO] 0x006FAFE0 sub_006FAFE0 (86 B)
// ============================================================================
// [VERIFIED] audio::SeqEventCrossFade::vfunc_00 (0x006FB040, 192 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as audio::SeqEventCrossFade::vfunc_00 (0x002DD430), which was matched first;
// its addresses and names were swapped for this function's.
// audio::SeqEventCrossFade::vfunc_00 (0x006FB040, 192 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field2C
{
    bool sub_00700D90(int);
};

extern "C" bool __cdecl sub_006ECC20(int, int);
extern "C" bool __cdecl sub_006ED500(int, int);
extern "C" bool __cdecl sub_006F3300(int, int);
extern "C" bool __cdecl sub_006F33D0(int, int);
extern "C" bool __stdcall sub_006F5740(int);

namespace audio {

class SeqEventCrossFade
{
public:
    virtual int vfunc_00(int a1);
    char m_pad04[0x4];
    int m_Field08; // +0x08
    int m_Field0C; // +0x0C
    int m_Field10; // +0x10
    int m_Field14; // +0x14
    int m_Field18; // +0x18
    int m_Field1C; // +0x1C
    char m_pad20[0x8];
    int m_Field28; // +0x28
    Field2C m_Field2C; // +0x2C
};

int SeqEventCrossFade::vfunc_00(int a1)
{
    if (sub_006F5740(a1)) {
        if (!sub_006F33D0(a1, (int)(&m_Field08))) goto L_B9;
        if (!sub_006F33D0(a1, (int)(&m_Field0C))) goto L_B9;
        if (!sub_006F33D0(a1, (int)(&m_Field10))) goto L_B9;
        if (!sub_006F33D0(a1, (int)(&m_Field14))) goto L_B9;
        if (!sub_006F3300(a1, (int)(&m_Field18))) goto L_B9;
        if (!sub_006F3300(a1, (int)(((char*)this + 0x19)))) goto L_B9;
        if (!sub_006ECC20(a1, (int)(&m_Field1C))) goto L_B9;
        if (!sub_006ED500(a1, (int)(&m_Field28))) goto L_B9;
        if (!m_Field2C.sub_00700D90(a1)) goto L_B9;
        return 1;
    }
L_B9:
    return 0;
}

}

// ============================================================================
// [VERIFIED] audio::SeqActionCrossFade::vfunc_00 (0x006FB100, 36 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as SoundManager::SoundPlayerHandle::vfunc_00 (0x00077F00), which was matched first;
// its addresses and names were swapped for this function's.
// audio::SeqActionCrossFade::vfunc_00 (0x006FB100, 36 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_00772F80[];
extern "C" char DAT_007F7E40[];
extern "C" void __cdecl sub_006EE890(int, int);

namespace audio {

class SeqActionCrossFade
{
public:
    virtual SeqActionCrossFade* vfunc_00(int a1);
};

SeqActionCrossFade* SeqActionCrossFade::vfunc_00(int a1)
{
    *(int*)this = (int)DAT_00772F80;
    if (a1 & 1) {
        sub_006EE890((int)DAT_007F7E40, (int)this);
    }
    return this;
}

}

// ============================================================================
// [VERIFIED] sub_006FB130 (0x006FB130, 116 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_002D8E20 (0x002D8E20), which was matched first;
// its addresses and names were swapped for this function's.
struct Name
{
    int data[3];
    void sub_006EB7A0(const char* text, int flags);
    void sub_006EBBD0();
};

struct Object
{
    void sub_006F5BB0(Name* a, Name* b);
};

extern "C" char DAT_007738BC[];
extern "C" char DAT_007738E0[];
extern "C" char DAT_007738E8[];
extern "C" Object* DAT_0085D558;
extern "C" void* __cdecl sub_0043CE00(unsigned int size);

// Makes the single instance: builds it from two names and keeps it in a global (or null).
void __cdecl sub_006FB130(void)
{
    Name first, second;

    first.sub_006EB7A0(DAT_007738E8, 0);
    second.sub_006EB7A0(DAT_007738E0, 0);
    Object* made = (Object*)sub_0043CE00(44);
    if (made) {
        made->sub_006F5BB0(&second, &first);
        *(void**)made = DAT_007738BC;
        DAT_0085D558 = made;
    } else {
        DAT_0085D558 = 0;
    }
    second.sub_006EBBD0();
    first.sub_006EBBD0();
}

// ============================================================================
// [VERIFIED] audio::SeqEventCrossFade::vfunc_03 (0x006FB240, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as audio::SeqEventNestTrack::vfunc_03 (PC 0x006F6960), which was matched first;
// its addresses and names were swapped for this function's.
// bin: pc
// va: 0x006FB240
// what: Returns a value kept in the game's data.
// tool: Claude Fable 5.2 (look-alike of pc 0x006DF7F0, names and addresses swapped)
// audio::SeqEventCrossFade::vfunc_03 (0x006FB240, 6 bytes)
extern "C" int DAT_0085D558;

namespace audio {

class SeqEventCrossFade
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual int vfunc_03();
};

int SeqEventCrossFade::vfunc_03()
{
    return DAT_0085D558;
}

}

// ============================================================================
// [VERIFIED] audio::SeqEventCrossFade::vfunc_04 (0x006FB250, 53 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// What it does: audio::SeqEventCrossFade's deleting destructor: destroys the object, frees its memory when asked (flag bit 0), and returns it.
// ============================================================================
// Same machine code as audio::SeqEventCrossFade::vfunc_04 (0x002DD640), which was matched first;
// its addresses and names were swapped for this function's.
// audio::SeqEventCrossFade::vfunc_04 (0x006FB250, 53 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field1C
{
    void sub_006EBBD0();
};

struct Field2C
{
    void sub_00700EE0();
};

extern "C" char DAT_007F7E38[];
extern "C" void __cdecl sub_006EE890(int, int);

namespace audio {

class SeqEventCrossFade
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual SeqEventCrossFade* vfunc_04(int a1);
    void sub_006F5730();
    char m_pad04[0x18];
    Field1C m_Field1C; // +0x1C
    char m_pad1D[0xF];
    Field2C m_Field2C; // +0x2C
};

SeqEventCrossFade* SeqEventCrossFade::vfunc_04(int a1)
{
    m_Field2C.sub_00700EE0();
    m_Field1C.sub_006EBBD0();
    sub_006F5730();
    if (a1 & 1) {
        sub_006EE890((int)DAT_007F7E38, (int)this);
    }
    return this;
}

}

// [TODO] 0x006FB290 audio::SeqEventCrossFade::vfunc_01 (194 B)
// [TODO] 0x006FB360 audio::SeqEventCrossFade::vfunc_02 (76 B)
// [TODO] 0x006FB3B0 audio::SeqActionCrossFade::vfunc_05 (181 B)
// [TODO] 0x006FB470 sub_006FB470 (52 B)
// ============================================================================
// [VERIFIED] audio::SeqEventType<audio::SeqEventCrossFade>::vfunc_01 (0x006FB4B0, 27 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as audio::SeqEventType<audio::SeqEventChannelSendVolumes>::vfunc_01 (0x002D93F0), which was matched first;
// its addresses and names were swapped for this function's.
// audio::SeqEventType<audio::SeqEventCrossFade>::vfunc_01 (0x006FB4B0, 27 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    int sub_006FB1B0();
};

extern "C" char DAT_007F7E38[];
extern "C" int __cdecl sub_006EE870(int);

namespace audio { class SeqEventCrossFade; }

namespace audio { 
template <class T0> class SeqEventType
{
public:
    virtual void vfunc_00();
    virtual int vfunc_01();
};
}

template <> int audio::SeqEventType<audio::SeqEventCrossFade>::vfunc_01()
{
    int t1;

    t1 = sub_006EE870((int)DAT_007F7E38);
    if (t1) {
        return ((Object*)t1)->sub_006FB1B0();
    }
    return 0;
}

// [TODO] 0x006FB4D0 audio::SeqActionCrossFade::vfunc_02 (288 B)
// [TODO] 0x006FB5F0 audio::SeqActionCrossFade::vfunc_01 (411 B)
// [TODO] 0x006FB790 audio::SeqEventClip::vfunc_01 (65 B)
// [TODO] 0x006FB7E0 audio::SeqActionClip::vfunc_02 (44 B)
// ============================================================================
// [VERIFIED] audio::SeqActionClip::vfunc_03 (0x006FB810, 54 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as audio::SeqActionClip::vfunc_03 (0x002DDC10), which was matched first;
// its addresses and names were swapped for this function's.
// audio::SeqActionClip::vfunc_03 (0x006FB810, 54 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __cdecl sub_006EFC90(int);
extern "C" int __cdecl sub_006EFCE0(int);

namespace audio {

class SeqActionClip
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03(int a1);
    void sub_006F57A0(int, int);
    char m_pad04[0x18];
    int m_Field1C; // +0x1C
};

void SeqActionClip::vfunc_03(int a1)
{
    int t1;

    t1 = m_Field1C;
    if (m_Field1C) {
        if (sub_006EFCE0(t1) != 1) goto L_24;
        sub_006EFC90(m_Field1C);
    }
L_24:
    sub_006F57A0(4, a1);
}

}

// ============================================================================
// [VERIFIED] audio::SeqActionClip::vfunc_04 (0x006FB850, 54 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as audio::SeqActionClip::vfunc_04 (0x002DDC50), which was matched first;
// its addresses and names were swapped for this function's.
// audio::SeqActionClip::vfunc_04 (0x006FB850, 54 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __cdecl sub_006EFC90(int);
extern "C" int __cdecl sub_006EFCE0(int);

namespace audio {

class SeqActionClip
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04(int a1);
    void sub_006F57A0(int, int);
    char m_pad04[0x18];
    int m_Field1C; // +0x1C
};

void SeqActionClip::vfunc_04(int a1)
{
    int t1;

    t1 = m_Field1C;
    if (m_Field1C) {
        if (sub_006EFCE0(t1) != 1) goto L_24;
        sub_006EFC90(m_Field1C);
    }
L_24:
    sub_006F57A0(5, a1);
}

}

// [TODO] 0x006FB890 sub_006FB890 (217 B)
// ============================================================================
// [VERIFIED] audio::SeqEventClip::vfunc_03 (0x006FB970, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as audio::SeqEventNestTrack::vfunc_03 (PC 0x006F6960), which was matched first;
// its addresses and names were swapped for this function's.
// bin: pc
// va: 0x006FB970
// what: Returns a value kept in the game's data.
// tool: Claude Fable 5.2 (look-alike of pc 0x006DF7F0, names and addresses swapped)
// audio::SeqEventClip::vfunc_03 (0x006FB970, 6 bytes)
extern "C" int DAT_0085D55C;

namespace audio {

class SeqEventClip
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual int vfunc_03();
};

int SeqEventClip::vfunc_03()
{
    return DAT_0085D55C;
}

}

// ============================================================================
// [VERIFIED] audio::SeqEventClip::vfunc_04 (0x006FB980, 35 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as SoundManager::StatePropSoundPlayer::vfunc_00 (0x00082430), which was matched first;
// its addresses and names were swapped for this function's.
// audio::SeqEventClip::vfunc_04 (0x006FB980, 35 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_007F7EAC[];
extern "C" void __cdecl sub_006F5730(void);
extern "C" void __cdecl sub_006EE890(int, int);

namespace audio {

class SeqEventClip
{
public:
    virtual SeqEventClip* vfunc_04(int a1);
};

SeqEventClip* SeqEventClip::vfunc_04(int a1)
{
    sub_006F5730();
    if (a1 & 1) {
        sub_006EE890((int)DAT_007F7EAC, (int)this);
    }
    return this;
}

}

// ============================================================================
// [VERIFIED] audio::SeqActionClip::vfunc_00 (0x006FB9B0, 36 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as SoundManager::SoundPlayerHandle::vfunc_00 (0x00077F00), which was matched first;
// its addresses and names were swapped for this function's.
// audio::SeqActionClip::vfunc_00 (0x006FB9B0, 36 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_00772F80[];
extern "C" char DAT_007F7EB4[];
extern "C" void __cdecl sub_006EE890(int, int);

namespace audio {

class SeqActionClip
{
public:
    virtual SeqActionClip* vfunc_00(int a1);
};

SeqActionClip* SeqActionClip::vfunc_00(int a1)
{
    *(int*)this = (int)DAT_00772F80;
    if (a1 & 1) {
        sub_006EE890((int)DAT_007F7EB4, (int)this);
    }
    return this;
}

}

// [TODO] 0x006FB9E0 sub_006FB9E0 (380 B)
// [TODO] 0x006FBB60 sub_006FBB60 (119 B)
// ============================================================================
// [VERIFIED] audio::SeqEventType<audio::SeqEventClip>::vfunc_01 (0x006FBBE0, 53 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as audio::SeqEventType<audio::SeqEventClip>::vfunc_01 (0x002DE200), which was matched first;
// its addresses and names were swapped for this function's.
// audio::SeqEventType<audio::SeqEventClip>::vfunc_01 (0x006FBBE0, 53 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_004A1B60();
    void sub_006F5850();
};

extern "C" char DAT_0077393C[];
extern "C" char DAT_007F7EAC[];
extern "C" int __cdecl sub_006EE870(int);

namespace audio { class SeqEventClip; }

namespace audio { 
template <class T0> class SeqEventType
{
public:
    virtual void vfunc_00();
    virtual int vfunc_01();
};
}

template <> int audio::SeqEventType<audio::SeqEventClip>::vfunc_01()
{
    int t1;

    t1 = sub_006EE870((int)DAT_007F7EAC);
    if (t1) {
        ((Object*)t1)->sub_006F5850();
        *(int*)t1 = (int)DAT_0077393C;
        *(bool*)(t1 + 12) = false;
        ((Object*)t1 + 16)->sub_004A1B60();
        return t1;
    }
    return 0;
}

// ============================================================================
// [VERIFIED] sub_006FBC20 (0x006FBC20, 116 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_002D8E20 (0x002D8E20), which was matched first;
// its addresses and names were swapped for this function's.
struct Name
{
    int data[3];
    void sub_006EB7A0(const char* text, int flags);
    void sub_006EBBD0();
};

struct Object
{
    void sub_006F5BB0(Name* a, Name* b);
};

extern "C" char DAT_00773930[];
extern "C" char DAT_00756358[];
extern "C" char DAT_00773970[];
extern "C" Object* DAT_0085D55C;
extern "C" void* __cdecl sub_0043CE00(unsigned int size);

// Makes the single instance: builds it from two names and keeps it in a global (or null).
void __cdecl sub_006FBC20(void)
{
    Name first, second;

    first.sub_006EB7A0(DAT_00773970, 0);
    second.sub_006EB7A0(DAT_00756358, 0);
    Object* made = (Object*)sub_0043CE00(44);
    if (made) {
        made->sub_006F5BB0(&second, &first);
        *(void**)made = DAT_00773930;
        DAT_0085D55C = made;
    } else {
        DAT_0085D55C = 0;
    }
    second.sub_006EBBD0();
    first.sub_006EBBD0();
}

// [TODO] 0x006FBCA0 audio::SeqEventClip::vfunc_00 (104 B)
// [TODO] 0x006FBD10 audio::SeqEventClip::vfunc_02 (79 B)
// [TODO] 0x006FBD60 audio::SeqActionClip::vfunc_05 (472 B)
// [TODO] 0x006FBF40 audio::SeqActionClip::vfunc_01 (105 B)
// [TODO] 0x006FBFB0 sub_006FBFB0 (415 B)
// [TODO] 0x006FC150 sub_006FC150 (310 B)
// [TODO] 0x006FC290 sub_006FC290 (106 B)
// [TODO] 0x006FC300 sub_006FC300 (30 B)
// [TODO] 0x006FC320 sub_006FC320 (1486 B)
// ============================================================================
// [VERIFIED] sub_006FC910 (0x006FC910, 26 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G7 /Gd /GR /EHsc /Zp4
// ============================================================================
// bin: pc
// va: 0x006FC910
// what: 
// tool: the portal's starter code (no AI)

// sub_006FC910 (PC 0x006FC910, 26 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

int __cdecl sub_006FC910(int a1)
{
    return (((((unsigned int)*(int*)(*(int*)(a1 + 8) + 12)) >> 4) & 31) * *(int*)(a1 + 136)) + (((((unsigned int)*(int*)(*(int*)(a1 + 8) + 12)) >> 4) & 31) * *(int*)(a1 + 136));
}

// ============================================================================
// [VERIFIED] sub_006FCF70 (0x006FCF70, 31 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// bin: pc
// va: 0x006FCF70
// what: 
// tool: the portal's starter code (no AI)

// sub_006FCF70 (PC 0x006FCF70, 31 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

int __cdecl sub_006FCF70(int a1, int a2)
{
    *(int*)(a2 + 128) = 0;
    *(int*)(a2 + 132) = 0;
    *(int*)(a2 + 136) = 0;
    *(int*)(a2 + 140) = 0;
    return a2;
}

// [TODO] 0x006FCF90 sub_006FCF90 (69 B)
// ============================================================================
// [VERIFIED] sub_006FCFE0 (0x006FCFE0, 45 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// bin: pc
// va: 0x006FCFE0
// what: 
// tool: the portal's starter code (no AI)

// sub_006FCFE0 (PC 0x006FCFE0, 45 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_0072F094;
extern "C" int DAT_0072F098;
extern "C" void __cdecl sub_006FC320(int, int, int);

void __cdecl sub_006FCFE0(int a1, int a2)
{
    ((void (__stdcall*)(int))DAT_0072F094)(a1 + 0x290448);
    sub_006FC320(a1, a2, 0);
    ((void (__stdcall*)(int))DAT_0072F098)(a1 + 0x290448);
}

// [TODO] 0x006FD010 sub_006FD010 (43 B)
// [TODO] 0x006FD040 sub_006FD040 (666 B)
// [TODO] 0x006FD740 sub_006FD740 (237 B)
// ============================================================================
// [VERIFIED] sub_006FD830 (0x006FD830, 13 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_0007F7F0 (0x0007F7F0), which was matched first;
// its addresses and names were swapped for this function's.
// sub_006FD830 (0x006FD830, 13 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_007F7F30[];
extern "C" void __stdcall sub_006EE870(int);

class Class_006FD830
{
public:
    void sub_006FD830(int a1);
};

void Class_006FD830::sub_006FD830(int a1)
{
    a1 = (int)DAT_007F7F30;
    sub_006EE870(a1);
}

// ============================================================================
// [VERIFIED] sub_006FD840 (0x006FD840, 19 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00081980 (0x00081980), which was matched first;
// its addresses and names were swapped for this function's.
// sub_006FD840 (0x006FD840, 19 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_007F7F30[];
extern "C" void __cdecl sub_006EE890(int, int);

void __cdecl sub_006FD840(int a1)
{
    sub_006EE890((int)DAT_007F7F30, a1);
}

// ============================================================================
// [VERIFIED] sub_006FD860 (0x006FD860, 13 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_0007F7F0 (0x0007F7F0), which was matched first;
// its addresses and names were swapped for this function's.
// sub_006FD860 (0x006FD860, 13 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_007F7F38[];
extern "C" void __stdcall sub_006EE870(int);

class Class_006FD860
{
public:
    void sub_006FD860(int a1);
};

void Class_006FD860::sub_006FD860(int a1)
{
    a1 = (int)DAT_007F7F38;
    sub_006EE870(a1);
}

// ============================================================================
// [VERIFIED] sub_006FD870 (0x006FD870, 13 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_0007F7F0 (0x0007F7F0), which was matched first;
// its addresses and names were swapped for this function's.
// sub_006FD870 (0x006FD870, 13 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_007F7F40[];
extern "C" void __stdcall sub_006EE870(int);

class Class_006FD870
{
public:
    void sub_006FD870(int a1);
};

void Class_006FD870::sub_006FD870(int a1)
{
    a1 = (int)DAT_007F7F40;
    sub_006EE870(a1);
}

// [TODO] 0x006FD880 sub_006FD880 (245 B)
// [TODO] 0x006FD980 sub_006FD980 (57 B)
// ============================================================================
// [VERIFIED] sub_006FD9C0 (0x006FD9C0, 13 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_0007F7F0 (0x0007F7F0), which was matched first;
// its addresses and names were swapped for this function's.
// sub_006FD9C0 (0x006FD9C0, 13 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_007F7F4C[];
extern "C" void __stdcall sub_006EE870(int);

class Class_006FD9C0
{
public:
    void sub_006FD9C0(int a1);
};

void Class_006FD9C0::sub_006FD9C0(int a1)
{
    a1 = (int)DAT_007F7F4C;
    sub_006EE870(a1);
}

// ============================================================================
// [VERIFIED] sub_006FD9D0 (0x006FD9D0, 19 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00081980 (0x00081980), which was matched first;
// its addresses and names were swapped for this function's.
// sub_006FD9D0 (0x006FD9D0, 19 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_007F7F4C[];
extern "C" void __cdecl sub_006EE890(int, int);

void __cdecl sub_006FD9D0(int a1)
{
    sub_006EE890((int)DAT_007F7F4C, a1);
}

// ============================================================================
// [VERIFIED] SoundLoadSequence::vfunc_00 (0x006FD9F0, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G7 /Gd /GR /EHsc /Zp4
// ============================================================================
// bin: pc
// va: 0x006FD9F0
// what: 
// tool: the portal's starter code (no AI)

// SoundLoadSequence::vfunc_00 (PC 0x006FD9F0, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

class SoundLoadSequence
{
public:
    virtual void vfunc_00();
    char m_pad04[0x30];
    unsigned short m_Field34; // +0x34
};

void SoundLoadSequence::vfunc_00()
{
    m_Field34 += 1;
}

// ============================================================================
// [VERIFIED] sub_006FDA00 (0x006FDA00, 5 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_002DE790 (0x002DE790), which was matched first;
// its addresses and names were swapped for this function's.
// bin: xb
// va: 0x006FDA00
// what: Returns the 16-bit value at +0x34.
// tool: Claude Opus 5.5 (generated from the shape 'read short field', checked on decomp.me preset 266 by example)
class Class_006FDA00
{
public:
    unsigned short sub_006FDA00();
    char m_pad00[0x34];
    unsigned short m_Field34; // +0x34
};

unsigned short Class_006FDA00::sub_006FDA00()
{
    return m_Field34;
}

// [TODO] 0x006FDA10 sub_006FDA10 (221 B)
// [TODO] 0x006FDB80 sub_006FDB80 (40 B)
// [TODO] 0x006FDBB0 sub_006FDBB0 (179 B)
// [TODO] 0x006FDC70 sub_006FDC70 (336 B)
// [TODO] 0x006FDDC0 sub_006FDDC0 (249 B)
// [TODO] 0x006FDEC0 sub_006FDEC0 (146 B)
// [TODO] 0x006FDF60 sub_006FDF60 (77 B)
// [TODO] 0x006FDFB0 sub_006FDFB0 (115 B)
// ============================================================================
// [VERIFIED] sub_006FE030 (0x006FE030, 114 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// bin: pc
// va: 0x006FE030
// what: 
// tool: the portal's starter code (no AI)

// sub_006FE030 (PC 0x006FE030, 114 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field28
{
    int sub_00700200();
    int sub_007002F0(int);
};

extern "C" void __stdcall sub_006FDBB0(int);

class Class_006FE030
{
public:
    int sub_006FE030(int a1, int a2);
    char m_pad00[0x1C];
    unsigned short m_Field1C; // +0x1C
    unsigned short m_Field1E; // +0x1E
    unsigned short m_Field20; // +0x20
    unsigned short m_Field22; // +0x22
    char m_pad24[0x4];
    Field28* m_Field28; // +0x28
};

int Class_006FE030::sub_006FE030(int a1, int a2)
{
    int r_eax, r_edi;

    sub_006FDBB0(5);
    r_eax = a1;
    if (a1) {
        m_Field1C = *(unsigned short*)r_eax;
        m_Field1E = *(unsigned short*)(r_eax + 4);
    } else {
        m_Field1C = 0;
        m_Field1E = 0;
    }
    r_edi = a2;
    m_Field22 = 0;
    m_Field20 = 0;
    if (!a2) goto L_6C;
    r_eax = m_Field28->sub_00700200();
    if (r_eax != 1) {
        if (r_eax == 2) goto L_63;
        if (r_eax == 3) goto L_63;
        if (r_eax == 4) goto L_63;
        *(int*)r_edi = 0;
        return r_eax;
    }
L_63:
    r_eax = m_Field28->sub_007002F0(r_edi);
L_6C:
    return r_eax;
}

// [TODO] 0x006FE0B0 sub_006FE0B0 (175 B)
// [TODO] 0x006FE160 sub_006FE160 (429 B)
// [TODO] 0x006FE310 sub_006FE310 (140 B)
// ============================================================================
// [VERIFIED] sub_006FE3A0 (0x006FE3A0, 13 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_0007F7F0 (0x0007F7F0), which was matched first;
// its addresses and names were swapped for this function's.
// sub_006FE3A0 (0x006FE3A0, 13 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_007F7F60[];
extern "C" void __stdcall sub_006EE870(int);

class Class_006FE3A0
{
public:
    void sub_006FE3A0(int a1);
};

void Class_006FE3A0::sub_006FE3A0(int a1)
{
    a1 = (int)DAT_007F7F60;
    sub_006EE870(a1);
}

// ============================================================================
// [VERIFIED] sub_006FE3B0 (0x006FE3B0, 19 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00081980 (0x00081980), which was matched first;
// its addresses and names were swapped for this function's.
// sub_006FE3B0 (0x006FE3B0, 19 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_007F7F60[];
extern "C" void __cdecl sub_006EE890(int, int);

void __cdecl sub_006FE3B0(int a1)
{
    sub_006EE890((int)DAT_007F7F60, a1);
}

// ============================================================================
// [VERIFIED] sub_006FE3D0 (0x006FE3D0, 13 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_0007F7F0 (0x0007F7F0), which was matched first;
// its addresses and names were swapped for this function's.
// sub_006FE3D0 (0x006FE3D0, 13 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_007F7F68[];
extern "C" void __stdcall sub_006EE870(int);

class Class_006FE3D0
{
public:
    void sub_006FE3D0(int a1);
};

void Class_006FE3D0::sub_006FE3D0(int a1)
{
    a1 = (int)DAT_007F7F68;
    sub_006EE870(a1);
}

// ============================================================================
// [VERIFIED] sub_006FE3E0 (0x006FE3E0, 19 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00081980 (0x00081980), which was matched first;
// its addresses and names were swapped for this function's.
// sub_006FE3E0 (0x006FE3E0, 19 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_007F7F68[];
extern "C" void __cdecl sub_006EE890(int, int);

void __cdecl sub_006FE3E0(int a1)
{
    sub_006EE890((int)DAT_007F7F68, a1);
}

// [TODO] 0x006FE400 sub_006FE400 (29 B)
// [TODO] 0x006FE420 sub_006FE420 (124 B)
// [TODO] 0x006FE4A0 sub_006FE4A0 (98 B)
// [TODO] 0x006FE510 sub_006FE510 (47 B)
// [TODO] 0x006FE540 sub_006FE540 (230 B)
// [TODO] 0x006FE670 sub_006FE670 (9 B)
// [TODO] 0x006FE680 sub_006FE680 (29 B)
// [TODO] 0x006FE6A0 sub_006FE6A0 (196 B)
// [TODO] 0x006FE770 sub_006FE770 (56 B)
// ============================================================================
// [VERIFIED] sub_006FE7B0 (0x006FE7B0, 24 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G7 /Gd /GR /EHsc /Zp4
// ============================================================================
// bin: pc
// va: 0x006FE7B0
// what: 
// tool: the portal's starter code (no AI)

// sub_006FE7B0 (PC 0x006FE7B0, 24 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

int __cdecl sub_006FE7B0(int a1)
{
    int t1, t2;

    t1 = *(int*)(a1 + 4);
    if (*(int*)(a1 + 4)) {
        t2 = *(int*)t1;
        *(int*)(a1 + 12) += 1;
        *(int*)(a1 + 4) = t2;
        return t1;
    }
    return 0;
}

// ============================================================================
// [VERIFIED] sub_006FE7D0 (0x006FE7D0, 21 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G7 /Gd /GR /EHsc /Zp4
// ============================================================================
// bin: pc
// va: 0x006FE7D0
// what: 
// tool: the portal's starter code (no AI)

// sub_006FE7D0 (PC 0x006FE7D0, 21 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

int __cdecl sub_006FE7D0(int a1, int a2)
{
    *(int*)a2 = *(int*)(a1 + 4);
    *(int*)(a1 + 12) += -1;
    *(int*)(a1 + 4) = a2;
    return a1;
}

// [TODO] 0x006FE7F0 sub_006FE7F0 (62 B)
// [TODO] 0x006FE830 sub_006FE830 (125 B)
// [TODO] 0x006FE8B0 sub_006FE8B0 (711 B)
// [TODO] 0x006FEB80 sub_006FEB80 (79 B)
// [TODO] 0x006FEBD0 sub_006FEBD0 (1986 B)
// ============================================================================
// [VERIFIED] sub_006FF3A0 (0x006FF3A0, 14 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_002AE020 (Proto 0x002AE020), which was matched first;
// its addresses and names were swapped for this function's.
// sub_006FF3A0 (Proto 0x006FF3A0, 14 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

class Class_006FF3A0
{
public:
    Class_006FF3A0* sub_006FF3A0();
    char m_pad00[0x10];
    int m_Field10; // +0x10
    char m_pad14[0x4];
    int m_Field18; // +0x18
    int m_Field1C; // +0x1C
};

Class_006FF3A0* Class_006FF3A0::sub_006FF3A0()
{
    m_Field10 = 0;
    m_Field18 = 0;
    m_Field1C = 0;
    return this;
}

// [TODO] 0x006FF3B0 sub_006FF3B0 (50 B)
// [TODO] 0x006FF3F0 sub_006FF3F0 (154 B)
// [TODO] 0x006FF490 om::TRbTree<om::PointerUid, 0>::Comp<om::PointerUid, 0, unsigned __int64>::vfunc_00 (61 B)
// [TODO] 0x006FF4D0 sub_006FF4D0 (155 B)
// ============================================================================
// [VERIFIED] sub_006FF570 (0x006FF570, 12 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_002E0FA0 (0x002E0FA0), which was matched first;
// its addresses and names were swapped for this function's.
// bin: xb
// va: 0x006FF570
// what: Passes this object to sub_006F2A40 on the global object DAT_0085D568.
// tool: Gemini 4 Neon

struct GlobalObj_0085D568
{
    void sub_006F2A40(void* arg);
};

extern "C" GlobalObj_0085D568 DAT_0085D568;

class Class_006FF570
{
public:
    void sub_006FF570();
};

void Class_006FF570::sub_006FF570()
{
    DAT_0085D568.sub_006F2A40(this);
}

// [TODO] 0x006FF580 sub_006FF580 (118 B)
// [TODO] 0x006FF600 sub_006FF600 (58 B)
// [TODO] 0x006FF700 sub_006FF700 (49 B)
// [TODO] 0x006FF740 sub_006FF740 (98 B)
// [TODO] 0x006FF8A0 sub_006FF8A0 (134 B)
// ============================================================================
// [VERIFIED] sub_007001D0 (0x007001D0, 13 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_0007F7F0 (0x0007F7F0), which was matched first;
// its addresses and names were swapped for this function's.
// sub_007001D0 (0x007001D0, 13 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_007FB3D4[];
extern "C" void __stdcall sub_006EE870(int);

class Class_007001D0
{
public:
    void sub_007001D0(int a1);
};

void Class_007001D0::sub_007001D0(int a1)
{
    a1 = (int)DAT_007FB3D4;
    sub_006EE870(a1);
}

// ============================================================================
// [VERIFIED] sub_007001E0 (0x007001E0, 19 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00081980 (0x00081980), which was matched first;
// its addresses and names were swapped for this function's.
// sub_007001E0 (0x007001E0, 19 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_007FB3D4[];
extern "C" void __cdecl sub_006EE890(int, int);

void __cdecl sub_007001E0(int a1)
{
    sub_006EE890((int)DAT_007FB3D4, a1);
}

// ============================================================================
// [VERIFIED] FETextObject::vfunc_46 (0x00700200, 4 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// FETextObject::vfunc_46 (PC 0x00700200, 4 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

class FETextObject
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
    virtual void vfunc_30();
    virtual void vfunc_31();
    virtual void vfunc_32();
    virtual void vfunc_33();
    virtual void vfunc_34();
    virtual void vfunc_35();
    virtual void vfunc_36();
    virtual void vfunc_37();
    virtual void vfunc_38();
    virtual void vfunc_39();
    virtual void vfunc_40();
    virtual void vfunc_41();
    virtual void vfunc_42();
    virtual void vfunc_43();
    virtual void vfunc_44();
    virtual void vfunc_45();
    virtual int vfunc_46();
    char m_pad04[0x28];
    int m_Field2C; // +0x2C
};

int FETextObject::vfunc_46()
{
    return m_Field2C;
}

// [TODO] 0x00700210 sub_00700210 (223 B)
// ============================================================================
// [VERIFIED] sub_007002F0 (0x007002F0, 77 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G7 /Gd /GR /EHsc /Zp4
// ============================================================================
// bin: pc
// va: 0x007002F0
// what: 
// tool: the portal's starter code (no AI)

// sub_007002F0 (PC 0x007002F0, 77 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int __cdecl sub_006F16C0(int);

class Class_007002F0
{
public:
    int sub_007002F0(int a1);
    char m_pad00[0xC];
    int m_Field0C; // +0x0C
    char m_pad10[0x1C];
    int m_Field2C; // +0x2C
    unsigned char m_Field30; // +0x30
};

int Class_007002F0::sub_007002F0(int a1)
{
    int r_eax;

    if (a1) {
        r_eax = m_Field0C;
        if (r_eax) {
            r_eax = sub_006F16C0(r_eax);
            if (r_eax != 2) goto L_3B;
            if (m_Field30) goto L_3B;
            r_eax = m_Field0C;
            *(int*)a1 = r_eax;
            m_Field0C = 0;
            goto L_3B;
        }
        *(int*)a1 = 0;
    }
L_3B:
    r_eax = 5;
    if (m_Field2C != 5) {
        m_Field2C = 5;
    }
    return r_eax;
}

// ============================================================================
// [VERIFIED] sub_00700340 (0x00700340, 51 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G7 /Gd /GR /EHsc /Zp4
// ============================================================================
// bin: pc
// va: 0x00700340
// what: 
// tool: the portal's starter code (no AI)

// sub_00700340 (PC 0x00700340, 51 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    virtual void vfunc_00();
    virtual void vfunc_01(int);
};

class Class_00700340
{
public:
    void sub_00700340();
    char m_pad00[0x18];
    int m_Field18; // +0x18
    char m_pad1C[0x10];
    int m_Field2C; // +0x2C
};

void Class_00700340::sub_00700340()
{
    int r_ecx, t1, t2;

    r_ecx = (int)this;
    t1 = m_Field18;
    if (m_Field18) {
        r_ecx = t1 + -8;
        if (!r_ecx) goto L_24;
        t2 = *(int*)(r_ecx + 12);
        if (*(int*)(r_ecx + 12) != 2) {
            if (t2 != 4) goto L_24;
        }
        ((Object*)r_ecx)->vfunc_01((int)this);
    }
L_24:
    if (m_Field2C != 3) {
        m_Field2C = 3;
    }
}

// [TODO] 0x00700380 sub_00700380 (44 B)
// ============================================================================
// [VERIFIED] sub_007003B0 (0x007003B0, 42 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G7 /Gd /GR /EHsc /Zp4
// ============================================================================
// bin: pc
// va: 0x007003B0
// what: 
// tool: the portal's starter code (no AI)

// sub_007003B0 (PC 0x007003B0, 42 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

class Class_007003B0
{
public:
    int sub_007003B0();
    char m_pad00[0x20];
    int m_Field20; // +0x20
    char m_pad24[0x4];
    int m_Field28; // +0x28
};

int Class_007003B0::sub_007003B0()
{
    int r_eax, r_edi;

    r_edi = 0;
L_06:
    r_eax = m_Field28;
    if (r_eax) {
        if (!(r_eax + -4)) goto L_27;
        if (m_Field20 == 30) goto L_27;
        r_eax = *(int*)(r_eax + -4);
        r_eax = ((int (__stdcall*)(int))*(int*)r_eax)((int)this);
        r_edi += 1;
        if ((unsigned int)r_edi < (unsigned int)5) goto L_06;
    }
L_27:
    return r_eax;
}

// [TODO] 0x00700660 sub_00700660 (125 B)
// [TODO] 0x007006E0 sub_007006E0 (90 B)
// [TODO] 0x00700740 sub_00700740 (37 B)
// [TODO] 0x00700770 sub_00700770 (42 B)
// [TODO] 0x007007A0 sub_007007A0 (47 B)
// [TODO] 0x007007D0 sub_007007D0 (86 B)
// [TODO] 0x00700A90 sub_00700A90 (53 B)
// [TODO] 0x00700AD0 sub_00700AD0 (114 B)
// [TODO] 0x00700C30 sub_00700C30 (103 B)
// ============================================================================
// [VERIFIED] sub_00700CA0 (0x00700CA0, 56 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_002989A0 (Proto 0x002989A0), which was matched first;
// its addresses and names were swapped for this function's.
// sub_00700CA0 (Proto 0x00700CA0, 56 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" bool __cdecl sub_006F33D0(int, int);

class Class_00700CA0
{
public:
    int sub_00700CA0(int a1);
};

int Class_00700CA0::sub_00700CA0(int a1)
{
    if (sub_006F33D0(a1, (int)this)) {
        if (!sub_006F33D0(a1, (int)this + 4)) goto L_31;
        return 1;
    }
L_31:
    return 0;
}

// ============================================================================
// [VERIFIED] sub_00700CE0 (0x00700CE0, 58 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_002989E0 (Proto 0x002989E0), which was matched first;
// its addresses and names were swapped for this function's.
// sub_00700CE0 (Proto 0x00700CE0, 58 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" bool __cdecl sub_006F33F0(int, int);

class Class_00700CE0
{
public:
    int sub_00700CE0(int a1);
    int m_Field00; // +0x00
    int m_Field04; // +0x04
};

int Class_00700CE0::sub_00700CE0(int a1)
{
    if (sub_006F33F0(a1, m_Field00)) {
        if (!sub_006F33F0(a1, m_Field04)) goto L_33;
        return 1;
    }
L_33:
    return 0;
}

// [TODO] 0x00700D20 sub_00700D20 (104 B)
// [TODO] 0x00700D90 sub_00700D90 (131 B)
// [TODO] 0x00700E20 sub_00700E20 (139 B)
// ============================================================================
// [VERIFIED] sub_00700EE0 (0x00700EE0, 5 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00023D40 (0x00023D40), which was matched first;
// its addresses and names were swapped for this function's.
// sub_00700EE0 (0x00700EE0, 5 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __cdecl sub_00700EB0(void);

class Class_00700EE0
{
public:
    void sub_00700EE0();
};

void Class_00700EE0::sub_00700EE0()
{
    sub_00700EB0();
}

// ============================================================================
// [VERIFIED] sub_00700EF0 (0x00700EF0, 16 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// bin: pc
// va: 0x00700EF0
// what: 
// tool: the portal's starter code (no AI)

// sub_00700EF0 (PC 0x00700EF0, 16 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_0085D580;

int __cdecl sub_00700EF0(void)
{
    int t1;

    t1 = DAT_0085D580;
    if (DAT_0085D580) {
        return t1 + -4;
    }
    return 0;
}

// ============================================================================
// [VERIFIED] sub_00700F00 (0x00700F00, 18 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// bin: pc
// va: 0x00700F00
// what: 
// tool: the portal's starter code (no AI)

// sub_00700F00 (PC 0x00700F00, 18 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

int __cdecl sub_00700F00(int a1)
{
    int t1;

    t1 = *(int*)(a1 + 4);
    if (*(int*)(a1 + 4)) {
        return t1 + -4;
    }
    return 0;
}

// ============================================================================
// [VERIFIED] sub_00700F20 (0x00700F20, 12 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// What it does: Passes the global at 0x0085D588 to sub_006DF080.
// ============================================================================
// bin: pc
// va: 0x00700F20
// what: Passes the global at 0x0085D588 to sub_006DF080.
// tool: Claude Opus 5.5 (transplanted from proto:0x0016FAA0, nearest by portal/tools/similar.py)
// sub_00700F20
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0085D588[];
extern "C" void __cdecl sub_006DF080(int);

class Class_00700F20
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
    virtual void sub_00700F20();
};

void Class_00700F20::sub_00700F20()
{
    sub_006DF080((int)DAT_0085D588);
}

// ============================================================================
// [VERIFIED] sub_00700F30 (0x00700F30, 12 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// What it does: Passes the global at 0x0085D588 to sub_006DF070.
// ============================================================================
// bin: pc
// va: 0x00700F30
// what: Passes the global at 0x0085D588 to sub_006DF070.
// tool: Claude Opus 5.5 (transplanted from proto:0x0016FAA0, nearest by portal/tools/similar.py)
// sub_00700F30
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0085D588[];
extern "C" void __cdecl sub_006DF070(int);

class Class_00700F30
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
    virtual void sub_00700F30();
};

void Class_00700F30::sub_00700F30()
{
    sub_006DF070((int)DAT_0085D588);
}

// [TODO] 0x00700FD0 movie::PlayerBink::vfunc_07 (135 B)
// [TODO] 0x00701060 movie::PlayerBink::vfunc_11 (113 B)
// ============================================================================
// [VERIFIED] movie::PlayerBink::vfunc_14 (0x007010E0, 36 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G7 /Gd /GR /EHsc /Zp4
// ============================================================================
// bin: pc
// va: 0x007010E0
// what: 
// tool: the portal's starter code (no AI)

// movie::PlayerBink::vfunc_14 (PC 0x007010E0, 36 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

namespace movie {

class PlayerBink
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
    virtual bool vfunc_14(int a1);
    char m_pad04[0x18];
    int m_Field1C; // +0x1C
};

bool PlayerBink::vfunc_14(int a1)
{
    if (m_Field1C) {
        *(int*)(a1 + 4) = *(int*)m_Field1C;
        *(int*)a1 = *(int*)(m_Field1C + 4);
        return true;
    }
    return false;
}

}

// [TODO] 0x00701110 movie::PlayerBink::vfunc_15 (54 B)
// ============================================================================
// [VERIFIED] movie::PlayerBink::vfunc_16 (0x00701150, 14 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as movie::PlayerBink::vfunc_16 (Proto 0x002AFEE0), which was matched first;
// its addresses and names were swapped for this function's.
// movie::PlayerBink::vfunc_16 (Proto 0x00701150, 14 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

namespace movie {

class PlayerBink
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
    char m_pad04[0x18];
    int m_Field1C; // +0x1C
};

int PlayerBink::vfunc_16()
{
    int t1;

    t1 = m_Field1C;
    if (m_Field1C) {
        return *(int*)(t1 + 12);
    }
    return 0;
}

}

// [TODO] 0x00701160 sub_00701160 (139 B)
// [TODO] 0x007011F0 sub_007011F0 (34 B)
// ============================================================================
// [VERIFIED] sub_00701220 (0x00701220, 5 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00023D40 (0x00023D40), which was matched first;
// its addresses and names were swapped for this function's.
// sub_00701220 (0x00701220, 5 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __cdecl sub_00701EE0(void);

class Class_00701220
{
public:
    void sub_00701220();
};

void Class_00701220::sub_00701220()
{
    sub_00701EE0();
}

// ============================================================================
// [VERIFIED] movie::PlayerBink::vfunc_04 (0x00701230, 75 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as movie::PlayerBink::vfunc_04 (Proto 0x002AFFC0), which was matched first;
// its addresses and names were swapped for this function's.
// movie::PlayerBink::vfunc_04 (Proto 0x00701230, 75 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    virtual void vfunc_00();
    virtual void vfunc_01();
};

namespace movie {

class PlayerBink
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04(int a1, int a2, int a3);
    char m_pad04[0xC];
    int m_Field10; // +0x10
    int m_Field14; // +0x14
};

void PlayerBink::vfunc_04(int a1, int a2, int a3)
{
    int r_edi;

    r_edi = m_Field10;
    if (r_edi != a1) {
        m_Field10 = a1;
        if (a1) {
            ((Object*)a1)->vfunc_00();
        }
        if (!r_edi) goto L_25;
        ((Object*)r_edi)->vfunc_01();
    }
L_25:
    r_edi = m_Field14;
    if (r_edi != a2) {
        m_Field14 = a2;
        if (a2) {
            ((Object*)a2)->vfunc_00();
        }
        if (!r_edi) goto L_46;
        ((Object*)r_edi)->vfunc_01();
    }
L_46:
    ;
}

}

// ============================================================================
// [VERIFIED] movie::PlayerBink::vfunc_05 (0x00701280, 12 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as movie::PlayerBink::vfunc_05 (Proto 0x002B0010), which was matched first;
// its addresses and names were swapped for this function's.
// movie::PlayerBink::vfunc_05 (Proto 0x00701280, 12 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field14
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
};

namespace movie {

class PlayerBink
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual void vfunc_05();
    char m_pad04[0x10];
    Field14* m_Field14; // +0x14
    char m_pad18[0xC];
    bool m_Field24; // +0x24
};

void PlayerBink::vfunc_05()
{
    m_Field24 = false;
    m_Field14->vfunc_09();
}

}

// [TODO] 0x00701290 movie::PlayerBink::vfunc_06 (196 B)
// ============================================================================
// [VERIFIED] movie::PlayerBink::vfunc_08 (0x00701360, 35 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G7 /Gd /GR /EHsc /Zp4
// ============================================================================
// bin: pc
// va: 0x00701360
// what: 
// tool: the portal's starter code (no AI)

// movie::PlayerBink::vfunc_08 (PC 0x00701360, 35 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_0072F2FC;

namespace movie {

class PlayerBink
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
    char m_pad04[0x14];
    int m_Field18; // +0x18
    int m_Field1C; // +0x1C
};

void PlayerBink::vfunc_08()
{
    if (m_Field18) {
        ((void (__stdcall*)(int))DAT_0072F2FC)(m_Field1C);
        m_Field1C = 0;
        m_Field18 = 0;
    }
}

}

// ============================================================================
// [VERIFIED] movie::PlayerBink::vfunc_09 (0x00701390, 46 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// bin: pc
// va: 0x00701390
// what: 
// tool: the portal's starter code (no AI)

// movie::PlayerBink::vfunc_09 (PC 0x00701390, 46 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_0072F2E0;

namespace movie {

class PlayerBink
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
    char m_pad04[0x14];
    int m_Field18; // +0x18
    int m_Field1C; // +0x1C
};

int PlayerBink::vfunc_09()
{
    int r_eax;

    r_eax = m_Field18;
    if (r_eax == 3) {
        r_eax = m_Field1C;
        r_eax = ((int (__stdcall*)(int, int))DAT_0072F2E0)(r_eax, 0);
        m_Field18 = 4;
        return r_eax;
    }
    if (r_eax == 1) {
        m_Field18 = 2;
    }
    return r_eax;
}

}

// ============================================================================
// [VERIFIED] movie::PlayerBink::vfunc_10 (0x007013C0, 46 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// bin: pc
// va: 0x007013C0
// what: 
// tool: the portal's starter code (no AI)

// movie::PlayerBink::vfunc_10 (PC 0x007013C0, 46 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_0072F2E0;

namespace movie {

class PlayerBink
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
    virtual int vfunc_10();
    char m_pad04[0x14];
    int m_Field18; // +0x18
    int m_Field1C; // +0x1C
};

int PlayerBink::vfunc_10()
{
    int r_eax;

    r_eax = m_Field18;
    if (r_eax == 4) {
        r_eax = m_Field1C;
        r_eax = ((int (__stdcall*)(int, int))DAT_0072F2E0)(r_eax, 1);
        m_Field18 = 3;
        return r_eax;
    }
    if (r_eax == 2) {
        m_Field18 = 1;
    }
    return r_eax;
}

}

// ============================================================================
// [VERIFIED] movie::PlayerBink::vfunc_00 (0x00701580, 8 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as core::ControllerSystemXBox::vfunc_00 (0x00248810), which was matched first;
// its addresses and names were swapped for this function's.
// movie::PlayerBink::vfunc_00 (0x00701580, 8 bytes)
// An adjustor thunk. Nobody wrote this function: the compiler adds it for a class with two base
// classes that both declare the same virtual function. Called through the second base's table, it
// moves `this` back 4 bytes to the start of the object and jumps to the real function at
// 0x00701630. So it is matched by declaring the class that way, not by writing a body.
// The two bases and their names are guesses; the first base is the part of the object in front
// of the second base (4 bytes).

namespace movie {
class ControllerSystemXBox_Base0 { public: virtual void sub_00701630(); };
class ControllerSystemXBox_Base1 { public: virtual void sub_00701630(); };

class PlayerBink : public ControllerSystemXBox_Base0, public ControllerSystemXBox_Base1
{
public:
    PlayerBink();
    virtual void sub_00701630();          // the real function; the thunk jumps here
};

PlayerBink::PlayerBink() {}                  // building one is what makes the compiler write its tables and the thunk
}

// [TODO] 0x00701590 sub_00701590 (101 B)
// ============================================================================
// [VERIFIED] movie::PlayerBink::vfunc_03 (0x00701630, 36 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as core::ControllerSystemXBox::vfunc_03 (0x00248820), which was matched first;
// its addresses and names were swapped for this function's.
// movie::PlayerBink::vfunc_03 (0x00701630, 36 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_007F5A70;
extern "C" void __cdecl sub_006DC430(int, int);
extern "C" void __cdecl sub_00701590(void);

namespace movie {

class PlayerBink
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual PlayerBink* vfunc_03(int a1);
};

PlayerBink* PlayerBink::vfunc_03(int a1)
{
    sub_00701590();
    if (a1 & 1) {
        sub_006DC430(DAT_007F5A70, (int)this);
    }
    return this;
}

}

// [TODO] 0x00701660 sub_00701660 (98 B)
// ============================================================================
// [VERIFIED] GameMemorySegmentCollection::vfunc_01 (0x007016D0, 8 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as GameMemorySegmentCollection::vfunc_01 (0x00026D90), which was matched first;
// its addresses and names were swapped for this function's.
// GameMemorySegmentCollection::vfunc_01 (0x007016D0, 8 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0043C590();
};

class GameMemorySegmentCollection
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
};

void GameMemorySegmentCollection::vfunc_01()
{
    ((Object*)(int)this + 4)->sub_0043C590();
}

// ============================================================================
// [VERIFIED] movie::RenderStrategyBink::vfunc_04 (0x007016E0, 8 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as movie::RenderStrategyBink::vfunc_04 (0x002E3070), which was matched first;
// its addresses and names were swapped for this function's.
// movie::RenderStrategyBink::vfunc_04 (0x007016E0, 8 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

namespace movie {

class RenderStrategyBink
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    char m_pad04[0x2C];
    int m_Field30; // +0x30
};

void RenderStrategyBink::vfunc_04()
{
    m_Field30 = 0;
}

}

// [TODO] 0x007016F0 movie::RenderStrategyBink::vfunc_05 (136 B)
// [TODO] 0x00701780 movie::RenderStrategyBink::vfunc_06 (36 B)
// [TODO] 0x007017B0 movie::RenderStrategyBink::vfunc_09 (802 B)
// ============================================================================
// [VERIFIED] movie::RenderStrategyBink::vfunc_00 (0x00701AE0, 8 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as core::ControllerSystemXBox::vfunc_00 (0x00248810), which was matched first;
// its addresses and names were swapped for this function's.
// movie::RenderStrategyBink::vfunc_00 (0x00701AE0, 8 bytes)
// An adjustor thunk. Nobody wrote this function: the compiler adds it for a class with two base
// classes that both declare the same virtual function. Called through the second base's table, it
// moves `this` back 4 bytes to the start of the object and jumps to the real function at
// 0x00701B90. So it is matched by declaring the class that way, not by writing a body.
// The two bases and their names are guesses; the first base is the part of the object in front
// of the second base (4 bytes).

namespace movie {
class ControllerSystemXBox_Base0 { public: virtual void sub_00701B90(); };
class ControllerSystemXBox_Base1 { public: virtual void sub_00701B90(); };

class RenderStrategyBink : public ControllerSystemXBox_Base0, public ControllerSystemXBox_Base1
{
public:
    RenderStrategyBink();
    virtual void sub_00701B90();          // the real function; the thunk jumps here
};

RenderStrategyBink::RenderStrategyBink() {}                  // building one is what makes the compiler write its tables and the thunk
}

// ============================================================================
// [VERIFIED] movie::RenderStrategyBink::vfunc_03 (0x00701B90, 36 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as core::ControllerSystemXBox::vfunc_03 (0x00248820), which was matched first;
// its addresses and names were swapped for this function's.
// movie::RenderStrategyBink::vfunc_03 (0x00701B90, 36 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_007F5A70;
extern "C" void __cdecl sub_006DC430(int, int);
extern "C" void __cdecl sub_00701660(void);

namespace movie {

class RenderStrategyBink
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual RenderStrategyBink* vfunc_03(int a1);
};

RenderStrategyBink* RenderStrategyBink::vfunc_03(int a1)
{
    sub_00701660();
    if (a1 & 1) {
        sub_006DC430(DAT_007F5A70, (int)this);
    }
    return this;
}

}

// [TODO] 0x00701BC0 movie::RenderStrategyBink::vfunc_07 (746 B)
// [TODO] 0x007021C0 sub_007021C0 (35 B)
// [TODO] 0x007025A0 movie::BinkCallback::vfunc_04 (218 B)
// ============================================================================
// [VERIFIED] movie::BinkCallback::vfunc_03 (0x00702680, 8 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as core::CementLibrary::vfunc_00 (Proto 0x0026F620), which was matched first;
// its addresses and names were swapped for this function's.
// movie::BinkCallback::vfunc_03 (Proto 0x00702680, 8 bytes)
// An adjustor thunk. Nobody wrote this function: the compiler adds it for a class with two base
// classes that both declare the same virtual function. Called through the second base's table, it
// moves `this` back 8 bytes to the start of the object and jumps to the real function at
// 0x00702690. So it is matched by declaring the class that way, not by writing a body.
// The two bases and their names are guesses; the first base is the part of the object in front
// of the second base (8 bytes).

namespace movie {
class CementLibrary_Base0 { public: virtual void sub_00702690(); char m_pad04[0x4]; };
class CementLibrary_Base1 { public: virtual void sub_00702690(); };

class BinkCallback : public CementLibrary_Base0, public CementLibrary_Base1
{
public:
    BinkCallback();
    virtual void sub_00702690();          // the real function; the thunk jumps here
};

BinkCallback::BinkCallback() {}                  // building one is what makes the compiler write its tables and the thunk
}

// ============================================================================
// [VERIFIED] movie::BinkCallback::vfunc_00 (0x00702690, 63 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G7 /Gd /GR /EHsc /Zp4
// ============================================================================
// bin: pc
// va: 0x00702690
// what: 
// tool: the portal's starter code (no AI)

// movie::BinkCallback::vfunc_00 (PC 0x00702690, 63 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0073523C[];
extern "C" char DAT_00736074[];
extern "C" int DAT_007F5A70;
extern "C" void __cdecl sub_006DC430(int, int);

namespace movie {

class BinkCallback
{
public:
    virtual int vfunc_00(int a1);
    int m_Field04; // +0x04
    int m_Field08; // +0x08
};

int BinkCallback::vfunc_00(int a1)
{
    int r_eax;

    if (this) {
        r_eax = (int)(&m_Field08);
    } else {
        r_eax = 0;
    }
    *(int*)r_eax = (int)DAT_0073523C;
    r_eax = m_Field04;
    DAT_007F5A70 = r_eax;
    *(int*)this = (int)DAT_00736074;
    if (a1 & 1) {
        sub_006DC430(DAT_007F5A70, (int)this);
    }
    r_eax = (int)this;
    return r_eax;
}

}

// ============================================================================
// [VERIFIED] sub_0070271E (0x0070271E, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00012130 (0x00012130), which was matched first;
// its addresses and names were swapped for this function's.
// sub_0070271E (0x0070271E, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_0072F2F4;

class Class_0070271E
{
public:
    void sub_0070271E();
};

void Class_0070271E::sub_0070271E()
{
    ((void (__cdecl*)(void))DAT_0072F2F4)();
}

// ============================================================================
// [VERIFIED] sub_00702724 (0x00702724, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00012130 (0x00012130), which was matched first;
// its addresses and names were swapped for this function's.
// sub_00702724 (0x00702724, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_0072F340;

class Class_00702724
{
public:
    void sub_00702724();
};

void Class_00702724::sub_00702724()
{
    ((void (__cdecl*)(void))DAT_0072F340)();
}

// ============================================================================
// [VERIFIED] sub_0070272A (0x0070272A, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00012130 (0x00012130), which was matched first;
// its addresses and names were swapped for this function's.
// sub_0070272A (0x0070272A, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_0072F33C;

class Class_0070272A
{
public:
    void sub_0070272A();
};

void Class_0070272A::sub_0070272A()
{
    ((void (__cdecl*)(void))DAT_0072F33C)();
}

// ============================================================================
// [VERIFIED] sub_00702730 (0x00702730, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00012130 (0x00012130), which was matched first;
// its addresses and names were swapped for this function's.
// sub_00702730 (0x00702730, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_0072F344;

class Class_00702730
{
public:
    void sub_00702730();
};

void Class_00702730::sub_00702730()
{
    ((void (__cdecl*)(void))DAT_0072F344)();
}

// ============================================================================
// [VERIFIED] sub_00702736 (0x00702736, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00012130 (0x00012130), which was matched first;
// its addresses and names were swapped for this function's.
// sub_00702736 (0x00702736, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_0072F338;

class Class_00702736
{
public:
    void sub_00702736();
};

void Class_00702736::sub_00702736()
{
    ((void (__cdecl*)(void))DAT_0072F338)();
}

// ============================================================================
// [VERIFIED] sub_0070273C (0x0070273C, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00012130 (0x00012130), which was matched first;
// its addresses and names were swapped for this function's.
// sub_0070273C (0x0070273C, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_0072F334;

class Class_0070273C
{
public:
    void sub_0070273C();
};

void Class_0070273C::sub_0070273C()
{
    ((void (__cdecl*)(void))DAT_0072F334)();
}

// ============================================================================
// [VERIFIED] sub_00702742 (0x00702742, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00012130 (0x00012130), which was matched first;
// its addresses and names were swapped for this function's.
// sub_00702742 (0x00702742, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_0072F330;

class Class_00702742
{
public:
    void sub_00702742();
};

void Class_00702742::sub_00702742()
{
    ((void (__cdecl*)(void))DAT_0072F330)();
}

// [TODO] 0x00702748 sub_00702748 (38 B)
// [TODO] 0x0070276E sub_0070276E (18 B)
// [TODO] 0x00702780 type_info::vfunc_00 (75 B)
// ============================================================================
// [VERIFIED] sub_007027CC (0x007027CC, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00012130 (0x00012130), which was matched first;
// its addresses and names were swapped for this function's.
// sub_007027CC (0x007027CC, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_0072F220;

class Class_007027CC
{
public:
    void sub_007027CC();
};

void Class_007027CC::sub_007027CC()
{
    ((void (__cdecl*)(void))DAT_0072F220)();
}

// ============================================================================
// [VERIFIED] fight::ConditionFactory::vfunc_07 (0x007027E6, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as core::File::vfunc_17 (PC 0x006E51B0), which was matched first;
// its addresses and names were swapped for this function's.
// bin: pc
// va: 0x007027E6
// what: Calls the function whose address is kept in a global.
// tool: Claude Opus 5.5 (transplanted from pc:0x006DED30, nearest by portal/tools/similar.py)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_0072F214;

class Class_007027E6
{
public:
    void sub_007027E6();
};

void Class_007027E6::sub_007027E6()
{
    ((void (__cdecl*)(void))DAT_0072F214)();
}

// [TODO] 0x0070284D sub_0070284D (74 B)
// [TODO] 0x00702897 sub_00702897 (24 B)
// [TODO] 0x007028AF sub_007028AF (47 B)
// [TODO] 0x0070290D sub_0070290D (72 B)
// [TODO] 0x00702955 sub_00702955 (24 B)
// [TODO] 0x0070297C sub_0070297C (117 B)
// [TODO] 0x00702A00 sub_00702A00 (31 B)
// ============================================================================
// [VERIFIED] sub_00702A20 (0x00702A20, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00012130 (0x00012130), which was matched first;
// its addresses and names were swapped for this function's.
// sub_00702A20 (0x00702A20, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_0072F1B0;

class Class_00702A20
{
public:
    void sub_00702A20();
};

void Class_00702A20::sub_00702A20()
{
    ((void (__cdecl*)(void))DAT_0072F1B0)();
}

// ============================================================================
// [VERIFIED] sub_00702A26 (0x00702A26, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00012130 (0x00012130), which was matched first;
// its addresses and names were swapped for this function's.
// sub_00702A26 (0x00702A26, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_0072F120;

class Class_00702A26
{
public:
    void sub_00702A26();
};

void Class_00702A26::sub_00702A26()
{
    ((void (__cdecl*)(void))DAT_0072F120)();
}

// [TODO] 0x00702CB0 sub_00702CB0 (52 B)
// [TODO] 0x00702D90 sub_00702D90 (117 B)
// ============================================================================
// [VERIFIED] sub_00702E06 (0x00702E06, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00012130 (0x00012130), which was matched first;
// its addresses and names were swapped for this function's.
// sub_00702E06 (0x00702E06, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_0072F164;

class Class_00702E06
{
public:
    void sub_00702E06();
};

void Class_00702E06::sub_00702E06()
{
    ((void (__cdecl*)(void))DAT_0072F164)();
}

// ============================================================================
// [VERIFIED] sub_00702E0C (0x00702E0C, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00012130 (0x00012130), which was matched first;
// its addresses and names were swapped for this function's.
// sub_00702E0C (0x00702E0C, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_0072F16C;

class Class_00702E0C
{
public:
    void sub_00702E0C();
};

void Class_00702E0C::sub_00702E0C()
{
    ((void (__cdecl*)(void))DAT_0072F16C)();
}

// [TODO] 0x00702E4F sub_00702E4F (17 B)
// ============================================================================
// [VERIFIED] sub_00702E66 (0x00702E66, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00012130 (0x00012130), which was matched first;
// its addresses and names were swapped for this function's.
// sub_00702E66 (0x00702E66, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_0072F174;

class Class_00702E66
{
public:
    void sub_00702E66();
};

void Class_00702E66::sub_00702E66()
{
    ((void (__cdecl*)(void))DAT_0072F174)();
}

// ============================================================================
// [VERIFIED] sub_00702E6C (0x00702E6C, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00012130 (0x00012130), which was matched first;
// its addresses and names were swapped for this function's.
// sub_00702E6C (0x00702E6C, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_0072F17C;

class Class_00702E6C
{
public:
    void sub_00702E6C();
};

void Class_00702E6C::sub_00702E6C()
{
    ((void (__cdecl*)(void))DAT_0072F17C)();
}

// ============================================================================
// [VERIFIED] sub_00702E72 (0x00702E72, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00012130 (0x00012130), which was matched first;
// its addresses and names were swapped for this function's.
// sub_00702E72 (0x00702E72, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_0072F18C;

class Class_00702E72
{
public:
    void sub_00702E72();
};

void Class_00702E72::sub_00702E72()
{
    ((void (__cdecl*)(void))DAT_0072F18C)();
}

// [TODO] 0x00702E78 sub_00702E78 (68 B)
// ============================================================================
// [VERIFIED] sub_00702F00 (0x00702F00, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00012130 (0x00012130), which was matched first;
// its addresses and names were swapped for this function's.
// sub_00702F00 (0x00702F00, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_0072F194;

class Class_00702F00
{
public:
    void sub_00702F00();
};

void Class_00702F00::sub_00702F00()
{
    ((void (__cdecl*)(void))DAT_0072F194)();
}

// [TODO] 0x00702F06 sub_00702F06 (18 B)
// ============================================================================
// [VERIFIED] sub_00702F18 (0x00702F18, 3 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// sub_00702F18 (PC 0x00702F18, 3 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

int __cdecl sub_00702F18(void)
{
    return 0;
}

// ============================================================================
// [VERIFIED] sub_00702F1C (0x00702F1C, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00012130 (0x00012130), which was matched first;
// its addresses and names were swapped for this function's.
// sub_00702F1C (0x00702F1C, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_0072F1AC;

class Class_00702F1C
{
public:
    void sub_00702F1C();
};

void Class_00702F1C::sub_00702F1C()
{
    ((void (__cdecl*)(void))DAT_0072F1AC)();
}

// ============================================================================
// [VERIFIED] pure3d::pddiDevice::vfunc_03 (0x00702F40, 36 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as LOSManager::LOSManagerFlowClient::vfunc_00 (0x000179C0), which was matched first;
// its addresses and names were swapped for this function's.
// pure3d::pddiDevice::vfunc_03 (0x00702F40, 36 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_007747AC[];
extern "C" void __cdecl sub_0043CE70(int);
extern "C" void __cdecl sub_0065C9D0(void);

namespace pure3d {

class pddiDevice
{
public:
    virtual pddiDevice* vfunc_03(int a1);
};

pddiDevice* pddiDevice::vfunc_03(int a1)
{
    *(int*)this = (int)DAT_007747AC;
    sub_0065C9D0();
    if (a1 & 1) {
        sub_0043CE70((int)this);
    }
    return this;
}

}

// [TODO] 0x00702F70 sub_00702F70 (107 B)
// [TODO] 0x00702FE0 pure3d::d3dDevice::vfunc_05 (63 B)
// [TODO] 0x00703020 pure3d::d3dDevice::vfunc_04 (728 B)
// ============================================================================
// [VERIFIED] pure3d::d3dDevice::vfunc_06 (0x00703300, 10 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as pure3d::d3dDevice::vfunc_05 (Proto 0x0024EC50), which was matched first;
// its addresses and names were swapped for this function's.
// pure3d::d3dDevice::vfunc_06 (Proto 0x00703300, 10 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

namespace pure3d {

class d3dDevice
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual void vfunc_05();
    virtual int vfunc_06(int a1);
    char m_pad04[0x8];
    int m_Field0C; // +0x0C
};

int d3dDevice::vfunc_06(int a1)
{
    m_Field0C = a1;
    return a1;
}

}

// ============================================================================
// [VERIFIED] pure3d::d3dDevice::vfunc_08 (0x00703310, 78 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G7 /Gd /GR /EHsc /Zp4
// ============================================================================
// bin: pc
// va: 0x00703310
// what: 
// tool: the portal's starter code (no AI)

// pure3d::d3dDevice::vfunc_08 (PC 0x00703310, 78 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    int sub_00654130(int, int);
};

extern "C" int __cdecl sub_0043CE00(int);

namespace pure3d {

class d3dDevice
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04(int);
    virtual void vfunc_05();
    virtual void vfunc_06();
    virtual void vfunc_07();
    virtual int vfunc_08(int a1);
    char m_pad04[0x10];
    int m_Field14; // +0x14
    int m_Field18; // +0x18
};

int d3dDevice::vfunc_08(int a1)
{
    int local_4, t2;

    vfunc_04((int)(&local_4));
    t2 = sub_0043CE00(564);
    if (t2) {
        return ((Object*)t2)->sub_00654130(m_Field14 + (((a1 + (a1 * 8) + a1 + (a1 * 8) + a1 + (a1 * 8) + a1 + (a1 * 8) + a1 + (a1 * 8) + a1 + (a1 * 8) + a1 + (a1 * 8) + a1 + (a1 * 8)) - a1) * 4), m_Field18);
    }
    return 0;
}

}

// [TODO] 0x00703360 pure3d::d3dDevice::vfunc_09 (63 B)
// [TODO] 0x007033A0 pure3d::d3dDevice::vfunc_10 (183 B)
// ============================================================================
// [VERIFIED] pure3d::d3dDevice::vfunc_11 (0x00703460, 109 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// bin: pc
// va: 0x00703460
// what: 
// tool: the portal's starter code (no AI)

// pure3d::d3dDevice::vfunc_11 (PC 0x00703460, 109 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual int vfunc_02();
    virtual void vfunc_03(int);
    int sub_00703F80(int);
    void sub_00703FF0(int, int, int, int, int, int, int);
};

extern "C" int __cdecl sub_0043CE00(int);

namespace pure3d {

class d3dDevice
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
    virtual int vfunc_11(int a1);
    char m_pad04[0x4];
    int m_Field08; // +0x08
    int m_Field0C; // +0x0C
};

int d3dDevice::vfunc_11(int a1)
{
    int r_esi, t1, t5;

    t1 = sub_0043CE00(76);
    if (t1) {
        r_esi = ((Object*)t1)->sub_00703F80(m_Field0C);
    } else {
        r_esi = 0;
    }
    ((Object*)r_esi)->sub_00703FF0(*(char*)(a1 + 68), *(int*)(a1 + 48), 0, *(int*)(a1 + 52), *(int*)(a1 + 56), *(int*)(a1 + 60), 0);
    t5 = ((Object*)r_esi)->vfunc_02();
    m_Field08 = t5;
    if (t5 != 1) {
        ((Object*)r_esi)->vfunc_03(1);
        return 0;
    }
    return r_esi;
}

}

// ============================================================================
// [VERIFIED] pure3d::d3dDevice::vfunc_15 (0x007034D0, 112 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// bin: pc
// va: 0x007034D0
// what: 
// tool: the portal's starter code (no AI)

// pure3d::d3dDevice::vfunc_15 (PC 0x007034D0, 112 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual int vfunc_02();
    virtual void vfunc_03(int);
    int sub_00703F80(int);
    void sub_00703FF0(int, int, int, int, int, int, int);
};

extern "C" int __cdecl sub_0043CE00(int);

namespace pure3d {

class d3dDevice
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
    virtual int vfunc_15(int a1, int a2);
    char m_pad04[0x4];
    int m_Field08; // +0x08
    int m_Field0C; // +0x0C
};

int d3dDevice::vfunc_15(int a1, int a2)
{
    int r_esi, t1, t4;

    t1 = sub_0043CE00(76);
    if (t1) {
        r_esi = ((Object*)t1)->sub_00703F80(m_Field0C);
    } else {
        r_esi = 0;
    }
    ((Object*)r_esi)->sub_00703FF0(*(char*)(a1 + 68), *(int*)(a1 + 48), 0, *(int*)(a1 + 52), *(int*)(a1 + 56), *(int*)(a1 + 60), a2);
    t4 = ((Object*)r_esi)->vfunc_02();
    m_Field08 = t4;
    if (t4 != 1) {
        ((Object*)r_esi)->vfunc_03(1);
        return 0;
    }
    return r_esi;
}

}

// ============================================================================
// [VERIFIED] pure3d::d3dDevice::vfunc_12 (0x00703540, 22 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as pure3d::d3dDevice::vfunc_11 (Proto 0x0024EE00), which was matched first;
// its addresses and names were swapped for this function's.
// pure3d::d3dDevice::vfunc_12 (Proto 0x00703540, 22 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __cdecl sub_00652AB0(int, int, int);

namespace pure3d {

class d3dDevice
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
    virtual void vfunc_12(int a1, int a2);
    char m_pad04[0x8];
    int m_Field0C; // +0x0C
};

void d3dDevice::vfunc_12(int a1, int a2)
{
    sub_00652AB0(m_Field0C, a1, 0);
}

}

// ============================================================================
// [VERIFIED] sub_00703560 (0x00703560, 47 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// bin: pc
// va: 0x00703560
// what: 
// tool: the portal's starter code (no AI)

// sub_00703560 (PC 0x00703560, 47 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_007747EC[];
extern "C" void __cdecl sub_0065C9B0(void);
extern "C" void __cdecl sub_00704770(int);

class Class_00703560
{
public:
    Class_00703560* sub_00703560(int a1);
    int m_Field00; // +0x00
    char m_pad04[0x8];
    int m_Field0C; // +0x0C
    int m_Field10; // +0x10
    int m_Field14; // +0x14
    int m_Field18; // +0x18
};

Class_00703560* Class_00703560::sub_00703560(int a1)
{
    sub_0065C9B0();
    m_Field00 = (int)DAT_007747EC;
    m_Field18 = a1;
    m_Field0C = 0;
    m_Field10 = 0;
    m_Field14 = 0;
    sub_00704770(a1);
    return this;
}

// ============================================================================
// [VERIFIED] pure3d::d3dDevice::vfunc_03 (0x00703590, 30 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as CollisionManager::CollisionManagerFlowClient::vfunc_00 (0x00016060), which was matched first;
// its addresses and names were swapped for this function's.
// pure3d::d3dDevice::vfunc_03 (0x00703590, 30 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __cdecl sub_00702F70(void);
extern "C" void __cdecl sub_0043CE70(int);

namespace pure3d {

class d3dDevice
{
public:
    virtual d3dDevice* vfunc_03(int a1);
};

d3dDevice* d3dDevice::vfunc_03(int a1)
{
    sub_00702F70();
    if (a1 & 1) {
        sub_0043CE70((int)this);
    }
    return this;
}

}

// ============================================================================
// [VERIFIED] pure3d::pddiPrimBuffer::vfunc_03 (0x00703610, 36 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as LOSManager::LOSManagerFlowClient::vfunc_00 (0x000179C0), which was matched first;
// its addresses and names were swapped for this function's.
// pure3d::pddiPrimBuffer::vfunc_03 (0x00703610, 36 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0077484C[];
extern "C" void __cdecl sub_0043CE70(int);
extern "C" void __cdecl sub_0065C9D0(void);

namespace pure3d {

class pddiPrimBuffer
{
public:
    virtual pddiPrimBuffer* vfunc_03(int a1);
};

pddiPrimBuffer* pddiPrimBuffer::vfunc_03(int a1)
{
    *(int*)this = (int)DAT_0077484C;
    sub_0065C9D0();
    if (a1 & 1) {
        sub_0043CE70((int)this);
    }
    return this;
}

}

// [TODO] 0x00703640 sub_00703640 (72 B)
// [TODO] 0x00703690 sub_00703690 (276 B)
// [TODO] 0x007037B0 sub_007037B0 (159 B)
// [TODO] 0x00703850 sub_00703850 (117 B)
// [TODO] 0x007038D0 sub_007038D0 (161 B)
// [TODO] 0x00703980 sub_00703980 (128 B)
// [TODO] 0x00703A00 pure3d::d3dPrimBuffer::vfunc_04 (138 B)
// [TODO] 0x00703A90 pure3d::d3dPrimBuffer::vfunc_05 (70 B)
// [TODO] 0x00703AE0 pure3d::d3dPrimBuffer::vfunc_07 (48 B)
// [TODO] 0x00703B10 pure3d::d3dPrimBuffer::vfunc_08 (27 B)
// ============================================================================
// [VERIFIED] pure3d::d3dPrimBuffer::vfunc_10 (0x00703B30, 16 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G7 /Gd /GR /EHsc /Zp4
// ============================================================================
// bin: pc
// va: 0x00703B30
// what: 
// tool: the portal's starter code (no AI)

// pure3d::d3dPrimBuffer::vfunc_10 (PC 0x00703B30, 16 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

namespace pure3d {

class d3dPrimBuffer
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
};

int d3dPrimBuffer::vfunc_10(int a1)
{
    return a1 == 0x20001;
}

}

// [TODO] 0x00703B40 pure3d::d3dPrimBuffer::vfunc_11 (62 B)
// [TODO] 0x00703B80 pure3d::d3dPrimBuffer::vfunc_12 (61 B)
// [TODO] 0x00703BC0 pure3d::d3dPrimBuffer::vfunc_09 (85 B)
// [TODO] 0x00703C20 sub_00703C20 (64 B)
// [TODO] 0x00703C60 pure3d::d3dPrimBuffer::vfunc_15 (322 B)
// ============================================================================
// [VERIFIED] pure3d::d3dContext::vfunc_13 (0x00703DB0, 3 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as pure3d::d3dContext::vfunc_13 (0x0029D5D0), which was matched first;
// its addresses and names were swapped for this function's.
// pure3d::d3dContext::vfunc_13 (0x00703DB0, 3 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

namespace pure3d {

class d3dContext
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
    virtual void vfunc_13(int a1, int a2, int a3, int a4);
};

void d3dContext::vfunc_13(int a1, int a2, int a3, int a4)
{
}

}

// ============================================================================
// [VERIFIED] pure3d::d3dPrimBufferStream::vfunc_15 (0x00703DC0, 3 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// pure3d::d3dPrimBufferStream::vfunc_15 (PC 0x00703DC0, 3 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

namespace pure3d {

class d3dPrimBufferStream
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
    virtual void vfunc_15(int a1, int a2, int a3, int a4, int a5);
};

void d3dPrimBufferStream::vfunc_15(int a1, int a2, int a3, int a4, int a5)
{
}

}

// ============================================================================
// [VERIFIED] pure3d::d3dPrimBufferStream::vfunc_24 (0x00703DD0, 5 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as renderer::InstanceRenderable::vfunc_10 (0x00054F90), which was matched first;
// its addresses and names were swapped for this function's.
// pure3d::d3dPrimBufferStream::vfunc_24 (0x00703DD0, 5 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __cdecl sub_007037B0(void);

namespace pure3d {

class d3dPrimBufferStream
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
    virtual void vfunc_24();
};

void d3dPrimBufferStream::vfunc_24()
{
    sub_007037B0();
}

}

// ============================================================================
// [VERIFIED] sub_00703F80 (0x00703F80, 77 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// bin: pc
// va: 0x00703F80
// what: 
// tool: the portal's starter code (no AI)

// sub_00703F80 (PC 0x00703F80, 77 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_00774894[];
extern "C" void __cdecl sub_0065C9B0(void);

class Class_00703F80
{
public:
    Class_00703F80* sub_00703F80(int a1);
    int m_Field00; // +0x00
    char m_pad04[0x8];
    int m_Field0C; // +0x0C
    char m_pad10[0x8];
    int m_Field18; // +0x18
    int m_Field1C; // +0x1C
    int m_Field20; // +0x20
    int m_Field24; // +0x24
    int m_Field28; // +0x28
    int m_Field2C; // +0x2C
    int m_Field30; // +0x30
    bool m_Field34; // +0x34
    bool m_Field35; // +0x35
    bool m_Field36; // +0x36
    char m_pad37[0x1];
    int m_Field38; // +0x38
    char m_pad3C[0x8];
    int m_Field44; // +0x44
    int m_Field48; // +0x48
};

Class_00703F80* Class_00703F80::sub_00703F80(int a1)
{
    sub_0065C9B0();
    m_Field18 = 0;
    m_Field1C = 0;
    m_Field20 = 0;
    m_Field24 = 0;
    m_Field28 = 0;
    m_Field2C = 0;
    m_Field30 = 0;
    m_Field34 = false;
    m_Field35 = false;
    m_Field36 = false;
    m_Field44 = 0;
    m_Field48 = 0;
    m_Field38 = a1;
    m_Field00 = (int)DAT_00774894;
    m_Field0C = *(int*)(*(int*)(a1 + 540) + 16);
    return this;
}

// ============================================================================
// [VERIFIED] pure3d::d3dPrimBuffer::vfunc_03 (0x00703FD0, 30 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as CollisionManager::CollisionManagerFlowClient::vfunc_00 (0x00016060), which was matched first;
// its addresses and names were swapped for this function's.
// pure3d::d3dPrimBuffer::vfunc_03 (0x00703FD0, 30 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __cdecl sub_00703850(void);
extern "C" void __cdecl sub_0043CE70(int);

namespace pure3d {

class d3dPrimBuffer
{
public:
    virtual d3dPrimBuffer* vfunc_03(int a1);
};

d3dPrimBuffer* d3dPrimBuffer::vfunc_03(int a1)
{
    sub_00703850();
    if (a1 & 1) {
        sub_0043CE70((int)this);
    }
    return this;
}

}

// [TODO] 0x00703FF0 sub_00703FF0 (119 B)
// ============================================================================
// [VERIFIED] pure3d::d3dPrimBufferStream::vfunc_00 (0x00704070, 48 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// bin: pc
// va: 0x00704070
// what: 
// tool: the portal's starter code (no AI)

// pure3d::d3dPrimBufferStream::vfunc_00 (PC 0x00704070, 48 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __cdecl sub_00703DE0(void);

namespace pure3d {

class d3dPrimBufferStream
{
public:
    virtual void vfunc_00(int a1, int a2, int a3);
    void sub_007037B0();
    char m_pad04[0x20];
    int m_Field24; // +0x24
};

void d3dPrimBufferStream::vfunc_00(int a1, int a2, int a3)
{
    sub_00703DE0();
    *(int*)m_Field24 = a1;
    *(int*)(m_Field24 + 4) = a2;
    *(int*)(m_Field24 + 8) = a3;
    sub_007037B0();
}

}

// [TODO] 0x007040A0 pure3d::d3dPrimBufferStream::vfunc_01 (263 B)
// ============================================================================
// [VERIFIED] pure3d::d3dPrimBufferStream::vfunc_11 (0x007041B0, 42 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// bin: pc
// va: 0x007041B0
// what: 
// tool: the portal's starter code (no AI)

// pure3d::d3dPrimBufferStream::vfunc_11 (PC 0x007041B0, 42 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __cdecl sub_00703DE0(void);

namespace pure3d {

class d3dPrimBufferStream
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
    virtual int vfunc_11(int a1, int a2);
    char m_pad04[0x2C];
    int m_Field30; // +0x30
    char m_pad34[0x10];
    int m_Field44; // +0x44
};

int d3dPrimBufferStream::vfunc_11(int a1, int a2)
{
    int r_eax, r_edx;

    sub_00703DE0();
    r_eax = a2;
    r_edx = a1;
    if (a2 < 2) {
        *(int*)(m_Field30 + (r_eax * 4)) = a1;
        return r_eax;
    }
    *(int*)(m_Field44 + (r_eax * 4) + -8) = r_edx;
    return r_eax;
}

}

// ============================================================================
// [VERIFIED] pure3d::d3dPrimBufferStream::vfunc_13 (0x007041E0, 37 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// bin: pc
// va: 0x007041E0
// what: 
// tool: the portal's starter code (no AI)

// pure3d::d3dPrimBufferStream::vfunc_13 (PC 0x007041E0, 37 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __cdecl sub_00703DE0(void);

namespace pure3d {

class d3dPrimBufferStream
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
    virtual int vfunc_13(float a1, float a2, int a3);
    char m_pad04[0x34];
    int m_Field38; // +0x38
};

int d3dPrimBufferStream::vfunc_13(float a1, float a2, int a3)
{
    sub_00703DE0();
    *(float*)(m_Field38 + (a3 * 8)) = a1;
    *(float*)(m_Field38 + (a3 * 8) + 4) = a2;
    return a3;
}

}

// ============================================================================
// [VERIFIED] pure3d::d3dPrimBufferStream::vfunc_16 (0x00704210, 21 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// bin: pc
// va: 0x00704210
// what: 
// tool: the portal's starter code (no AI)

// pure3d::d3dPrimBufferStream::vfunc_16 (PC 0x00704210, 21 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __cdecl sub_00703DE0(void);

namespace pure3d {

class d3dPrimBufferStream
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
    virtual int vfunc_16(int a1);
    char m_pad04[0x30];
    int m_Field34; // +0x34
};

int d3dPrimBufferStream::vfunc_16(int a1)
{
    int t2;

    sub_00703DE0();
    t2 = m_Field34;
    *(int*)m_Field34 = a1;
    return t2;
}

}

// ============================================================================
// [VERIFIED] pure3d::d3dPrimBufferStream::vfunc_09 (0x00704230, 41 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// bin: pc
// va: 0x00704230
// what: 
// tool: the portal's starter code (no AI)

// pure3d::d3dPrimBufferStream::vfunc_09 (PC 0x00704230, 41 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __cdecl sub_00703DE0(void);

namespace pure3d {

class d3dPrimBufferStream
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
    virtual int vfunc_09(int a1, int a2, int a3);
    char m_pad04[0x38];
    int m_Field3C; // +0x3C
};

int d3dPrimBufferStream::vfunc_09(int a1, int a2, int a3)
{
    sub_00703DE0();
    *(int*)m_Field3C = a1;
    *(int*)(m_Field3C + 4) = a2;
    *(int*)(m_Field3C + 8) = a3;
    return a2;
}

}

// ============================================================================
// [VERIFIED] pure3d::d3dPrimBufferStream::vfunc_10 (0x00704260, 41 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// bin: pc
// va: 0x00704260
// what: 
// tool: the portal's starter code (no AI)

// pure3d::d3dPrimBufferStream::vfunc_10 (PC 0x00704260, 41 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __cdecl sub_00703DE0(void);

namespace pure3d {

class d3dPrimBufferStream
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
    virtual int vfunc_10(int a1, int a2, int a3);
    char m_pad04[0x3C];
    int m_Field40; // +0x40
};

int d3dPrimBufferStream::vfunc_10(int a1, int a2, int a3)
{
    sub_00703DE0();
    *(int*)m_Field40 = a1;
    *(int*)(m_Field40 + 4) = a2;
    *(int*)(m_Field40 + 8) = a3;
    return a2;
}

}

// ============================================================================
// [VERIFIED] pure3d::d3dPrimBufferStream::vfunc_07 (0x00704290, 41 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// bin: pc
// va: 0x00704290
// what: 
// tool: the portal's starter code (no AI)

// pure3d::d3dPrimBufferStream::vfunc_07 (PC 0x00704290, 41 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __cdecl sub_00703DE0(void);

namespace pure3d {

class d3dPrimBufferStream
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual void vfunc_05();
    virtual void vfunc_06();
    virtual int vfunc_07(int a1, int a2, int a3);
    char m_pad04[0x44];
    int m_Field48; // +0x48
};

int d3dPrimBufferStream::vfunc_07(int a1, int a2, int a3)
{
    sub_00703DE0();
    *(int*)m_Field48 = a1;
    *(int*)(m_Field48 + 4) = a2;
    *(int*)(m_Field48 + 8) = a3;
    return a2;
}

}

// ============================================================================
// [VERIFIED] pure3d::d3dPrimBufferStream::vfunc_08 (0x007042C0, 41 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// bin: pc
// va: 0x007042C0
// what: 
// tool: the portal's starter code (no AI)

// pure3d::d3dPrimBufferStream::vfunc_08 (PC 0x007042C0, 41 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __cdecl sub_00703DE0(void);

namespace pure3d {

class d3dPrimBufferStream
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
    virtual int vfunc_08(int a1, int a2, int a3);
    char m_pad04[0x48];
    int m_Field4C; // +0x4C
};

int d3dPrimBufferStream::vfunc_08(int a1, int a2, int a3)
{
    sub_00703DE0();
    *(int*)m_Field4C = a1;
    *(int*)(m_Field4C + 4) = a2;
    *(int*)(m_Field4C + 8) = a3;
    return a2;
}

}

// [TODO] 0x007042F0 pure3d::d3dPrimBufferStream::vfunc_17 (61 B)
// ============================================================================
// [VERIFIED] pure3d::d3dPrimBufferStream::vfunc_18 (0x00704330, 41 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// bin: pc
// va: 0x00704330
// what: 
// tool: the portal's starter code (no AI)

// pure3d::d3dPrimBufferStream::vfunc_18 (PC 0x00704330, 41 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __cdecl sub_00703DE0(void);

namespace pure3d {

class d3dPrimBufferStream
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
    virtual int vfunc_18(int a1, int a2, int a3);
    char m_pad04[0x50];
    int m_Field54; // +0x54
};

int d3dPrimBufferStream::vfunc_18(int a1, int a2, int a3)
{
    sub_00703DE0();
    *(int*)m_Field54 = a1;
    *(int*)(m_Field54 + 4) = a2;
    *(int*)(m_Field54 + 8) = a3;
    return a2;
}

}

// ============================================================================
// [VERIFIED] pure3d::d3dPrimBufferStream::vfunc_23 (0x00704360, 51 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// bin: pc
// va: 0x00704360
// what: 
// tool: the portal's starter code (no AI)

// pure3d::d3dPrimBufferStream::vfunc_23 (PC 0x00704360, 51 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __cdecl sub_00703DE0(void);

namespace pure3d {

class d3dPrimBufferStream
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
    virtual void vfunc_23(int a1, int a2);
    void sub_007037B0();
    char m_pad04[0x20];
    int m_Field24; // +0x24
    char m_pad28[0x8];
    int m_Field30; // +0x30
};

void d3dPrimBufferStream::vfunc_23(int a1, int a2)
{
    int t2;

    sub_00703DE0();
    t2 = m_Field24;
    *(int*)m_Field24 = *(int*)a1;
    *(int*)(t2 + 4) = *(int*)(a1 + 4);
    *(int*)(t2 + 8) = *(int*)(a1 + 8);
    *(int*)m_Field30 = a2;
    sub_007037B0();
}

}

// ============================================================================
// [VERIFIED] pure3d::d3dPrimBufferStream::vfunc_22 (0x007043A0, 64 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// bin: pc
// va: 0x007043A0
// what: 
// tool: the portal's starter code (no AI)

// pure3d::d3dPrimBufferStream::vfunc_22 (PC 0x007043A0, 64 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __cdecl sub_00703DE0(void);

namespace pure3d {

class d3dPrimBufferStream
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01(int, int, int);
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
    virtual void vfunc_22(int a1, int a2);
    void sub_007037B0();
    char m_pad04[0x20];
    int m_Field24; // +0x24
};

void d3dPrimBufferStream::vfunc_22(int a1, int a2)
{
    int t2;

    sub_00703DE0();
    t2 = m_Field24;
    *(int*)m_Field24 = *(int*)a1;
    *(int*)(t2 + 4) = *(int*)(a1 + 4);
    *(int*)(t2 + 8) = *(int*)(a1 + 8);
    vfunc_01(*(int*)a2, *(int*)(a2 + 4), *(int*)(a2 + 8));
    sub_007037B0();
}

}

// [TODO] 0x007043E0 pure3d::d3dPrimBufferStream::vfunc_21 (59 B)
// [TODO] 0x00704420 pure3d::d3dPrimBufferStream::vfunc_20 (68 B)
// [TODO] 0x00704470 pure3d::d3dPrimBufferStream::vfunc_19 (81 B)
// [TODO] 0x00704770 sub_00704770 (346 B)
// ============================================================================
// [VERIFIED] pure3d::d3dErrorShader::vfunc_04 (0x007048D0, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as pure3d::d3dVehicleShader::vfunc_04 (0x002829C0), which was matched first;
// its addresses and names were swapped for this function's.
// bin: xb
// va: 0x007048D0
// what: Returns the address of a fixed block in the game's data.
// tool: Claude Fable 5.2 (look-alike of 0x0004A760, names and addresses swapped)
// pure3d::d3dErrorShader::vfunc_04 (0x007048D0, 6 bytes)
extern "C" char DAT_007FB648[];

namespace pure3d {

class d3dErrorShader
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void* vfunc_04();
};

void* d3dErrorShader::vfunc_04()
{
    return DAT_007FB648;
}

}

// ============================================================================
// [VERIFIED] sub_007048E0 (0x007048E0, 50 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_002856B0 (Proto 0x002856B0), which was matched first;
// its addresses and names were swapped for this function's.
// sub_007048E0 (Proto 0x007048E0, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_00774994[];
extern "C" void __stdcall sub_006524F0(int);

class Class_007048E0
{
public:
    Class_007048E0* sub_007048E0(int a1);
    int m_Field00; // +0x00
    char m_pad04[0x44];
    bool m_Field48; // +0x48
    char m_pad49[0x7];
    int m_Field50; // +0x50
    int m_Field54; // +0x54
    int m_Field58; // +0x58
    int m_Field5C; // +0x5C
};

Class_007048E0* Class_007048E0::sub_007048E0(int a1)
{
    sub_006524F0(a1);
    m_Field58 = -0x1000000;
    m_Field50 = -0x1000000;
    m_Field54 = -0x1000000;
    m_Field00 = (int)DAT_00774994;
    m_Field48 = true;
    m_Field5C = -32513;
    return this;
}

// [TODO] 0x00704920 pure3d::d3dErrorShader::vfunc_15 (226 B)
// ============================================================================
// [VERIFIED] sub_00704A10 (0x00704A10, 36 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// bin: pc
// va: 0x00704A10
// what: 
// tool: the portal's starter code (no AI)

// sub_00704A10 (PC 0x00704A10, 36 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field04
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
    virtual void vfunc_23();
    virtual void vfunc_24();
    virtual void vfunc_25();
    virtual void vfunc_26();
    virtual void vfunc_27();
    virtual void vfunc_28();
    virtual void vfunc_29();
    virtual void vfunc_30();
    virtual void vfunc_31();
    virtual void vfunc_32();
    virtual void vfunc_33();
    virtual void vfunc_34();
    virtual void vfunc_35();
    virtual void vfunc_36();
    virtual void vfunc_37();
    virtual void vfunc_38();
    virtual void vfunc_39();
    virtual void vfunc_40();
    virtual void vfunc_41();
    virtual void vfunc_42();
    virtual void vfunc_43();
    virtual void vfunc_44();
    virtual void vfunc_45();
    virtual void vfunc_46();
    virtual void vfunc_47();
    virtual void vfunc_48();
    virtual void vfunc_49();
    virtual void vfunc_50();
    virtual void vfunc_51();
    virtual void vfunc_52();
    virtual void vfunc_53();
    virtual void vfunc_54();
    virtual void vfunc_55();
    virtual void vfunc_56();
    virtual int vfunc_57(int, int, int);
};

class Class_00704A10
{
public:
    int sub_00704A10(int a1);
    char m_pad00[0x4];
    Field04* m_Field04; // +0x04
    char m_pad08[0x10C];
    int m_Field114; // +0x114
};

int Class_00704A10::sub_00704A10(int a1)
{
    int r_eax;

    r_eax = a1;
    if (a1 != m_Field114) {
        m_Field114 = a1;
        r_eax = m_Field04->vfunc_57((int)m_Field04, 60, a1);
    }
    return r_eax;
}

// ============================================================================
// [VERIFIED] pure3d::d3dReflShader::vfunc_16 (0x00704A40, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as pure3d::TargaHandler::vfunc_07 (0x0004A760), which was matched first;
// its addresses and names were swapped for this function's.
// pure3d::d3dReflShader::vfunc_16 (0x00704A40, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_007FB7F0[];

namespace pure3d {

class d3dReflShader
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual void vfunc_05();
    virtual void vfunc_06();
    virtual void* vfunc_16();
};

void* d3dReflShader::vfunc_16()
{
    return DAT_007FB7F0;
}

}

// ============================================================================
// [VERIFIED] pure3d::d3dReflShader::vfunc_17 (0x00704A50, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as pure3d::TargaHandler::vfunc_07 (0x0004A760), which was matched first;
// its addresses and names were swapped for this function's.
// pure3d::d3dReflShader::vfunc_17 (0x00704A50, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_007FB718[];

namespace pure3d {

class d3dReflShader
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual void vfunc_05();
    virtual void vfunc_06();
    virtual void* vfunc_17();
};

void* d3dReflShader::vfunc_17()
{
    return DAT_007FB718;
}

}

// ============================================================================
// [VERIFIED] pure3d::d3dReflShader::vfunc_18 (0x00704A60, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as pure3d::TargaHandler::vfunc_07 (0x0004A760), which was matched first;
// its addresses and names were swapped for this function's.
// pure3d::d3dReflShader::vfunc_18 (0x00704A60, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_007FB6D0[];

namespace pure3d {

class d3dReflShader
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual void vfunc_05();
    virtual void vfunc_06();
    virtual void* vfunc_18();
};

void* d3dReflShader::vfunc_18()
{
    return DAT_007FB6D0;
}

}

// ============================================================================
// [VERIFIED] pure3d::d3dReflShader::vfunc_19 (0x00704A70, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as pure3d::TargaHandler::vfunc_07 (0x0004A760), which was matched first;
// its addresses and names were swapped for this function's.
// pure3d::d3dReflShader::vfunc_19 (0x00704A70, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_007FB838[];

namespace pure3d {

class d3dReflShader
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual void vfunc_05();
    virtual void vfunc_06();
    virtual void* vfunc_19();
};

void* d3dReflShader::vfunc_19()
{
    return DAT_007FB838;
}

}

// ============================================================================
// [VERIFIED] pure3d::d3dReflShader::vfunc_04 (0x00704A80, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as pure3d::d3dVehicleShader::vfunc_04 (0x002829C0), which was matched first;
// its addresses and names were swapped for this function's.
// bin: xb
// va: 0x00704A80
// what: Returns the address of a fixed block in the game's data.
// tool: Claude Fable 5.2 (look-alike of 0x0004A760, names and addresses swapped)
// pure3d::d3dReflShader::vfunc_04 (0x00704A80, 6 bytes)
extern "C" char DAT_007FB6AC[];

namespace pure3d {

class d3dReflShader
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void* vfunc_04();
};

void* d3dReflShader::vfunc_04()
{
    return DAT_007FB6AC;
}

}

// [TODO] 0x00704A90 pure3d::d3dReflShader::vfunc_13 (164 B)
// [TODO] 0x00704B40 pure3d::d3dReflShader::vfunc_14 (156 B)
// ============================================================================
// [VERIFIED] sub_00704BE0 (0x00704BE0, 49 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00285AD0 (Proto 0x00285AD0), which was matched first;
// its addresses and names were swapped for this function's.
// sub_00704BE0 (Proto 0x00704BE0, 49 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_00774A24[];
extern "C" void __stdcall sub_006524F0(int);

class Class_00704BE0
{
public:
    Class_00704BE0* sub_00704BE0(int a1);
    int m_Field00; // +0x00
    char m_pad04[0x7C];
    int m_Field80; // +0x80
    int m_Field84; // +0x84
    int m_Field88; // +0x88
};

Class_00704BE0* Class_00704BE0::sub_00704BE0(int a1)
{
    sub_006524F0(a1);
    m_Field80 = 0;
    m_Field84 = 0;
    m_Field00 = (int)DAT_00774A24;
    m_Field88 = -0x7F7F7F80;
    return this;
}

// ============================================================================
// [VERIFIED] pure3d::d3dReflShader::vfunc_03 (0x00704C20, 68 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as pure3d::d3dReflShader::vfunc_03 (Proto 0x00285B10), which was matched first;
// its addresses and names were swapped for this function's.
// pure3d::d3dReflShader::vfunc_03 (Proto 0x00704C20, 68 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    virtual void vfunc_00();
    virtual void vfunc_01();
};

extern "C" char DAT_00774A24[];
extern "C" void __cdecl sub_0043CE70(int);

namespace pure3d {

class d3dReflShader
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual d3dReflShader* vfunc_03(int a1);
    void sub_006527F0();
    char m_pad04[0x7C];
    int m_Field80; // +0x80
    int m_Field84; // +0x84
};

d3dReflShader* d3dReflShader::vfunc_03(int a1)
{
    int t1, t3;

    t1 = m_Field80;
    *(int*)this = (int)DAT_00774A24;
    if (m_Field80) {
        ((Object*)t1)->vfunc_01();
    }
    t3 = m_Field84;
    if (m_Field84) {
        ((Object*)t3)->vfunc_01();
    }
    sub_006527F0();
    if (a1 & 1) {
        sub_0043CE70((int)this);
    }
    return this;
}

}

// [TODO] 0x00704C70 pure3d::d3dReflShader::vfunc_15 (977 B)
// ============================================================================
// [VERIFIED] pure3d::d3dPointSpriteShader::vfunc_16 (0x00705050, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as pure3d::TargaHandler::vfunc_07 (0x0004A760), which was matched first;
// its addresses and names were swapped for this function's.
// pure3d::d3dPointSpriteShader::vfunc_16 (0x00705050, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_007FB9D8[];

namespace pure3d {

class d3dPointSpriteShader
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual void vfunc_05();
    virtual void vfunc_06();
    virtual void* vfunc_16();
};

void* d3dPointSpriteShader::vfunc_16()
{
    return DAT_007FB9D8;
}

}

// ============================================================================
// [VERIFIED] pure3d::d3dPointSpriteShader::vfunc_17 (0x00705060, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as pure3d::TargaHandler::vfunc_07 (0x0004A760), which was matched first;
// its addresses and names were swapped for this function's.
// pure3d::d3dPointSpriteShader::vfunc_17 (0x00705060, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_007FBA08[];

namespace pure3d {

class d3dPointSpriteShader
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual void vfunc_05();
    virtual void vfunc_06();
    virtual void* vfunc_17();
};

void* d3dPointSpriteShader::vfunc_17()
{
    return DAT_007FBA08;
}

}

// ============================================================================
// [VERIFIED] pure3d::d3dPointSpriteShader::vfunc_18 (0x00705070, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as pure3d::TargaHandler::vfunc_07 (0x0004A760), which was matched first;
// its addresses and names were swapped for this function's.
// pure3d::d3dPointSpriteShader::vfunc_18 (0x00705070, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_007FB918[];

namespace pure3d {

class d3dPointSpriteShader
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual void vfunc_05();
    virtual void vfunc_06();
    virtual void* vfunc_18();
};

void* d3dPointSpriteShader::vfunc_18()
{
    return DAT_007FB918;
}

}

// ============================================================================
// [VERIFIED] pure3d::d3dPointSpriteShader::vfunc_04 (0x00705080, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as pure3d::d3dVehicleShader::vfunc_04 (0x002829C0), which was matched first;
// its addresses and names were swapped for this function's.
// bin: xb
// va: 0x00705080
// what: Returns the address of a fixed block in the game's data.
// tool: Claude Fable 5.2 (look-alike of 0x0004A760, names and addresses swapped)
// pure3d::d3dPointSpriteShader::vfunc_04 (0x00705080, 6 bytes)
extern "C" char DAT_007FB8F4[];

namespace pure3d {

class d3dPointSpriteShader
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void* vfunc_04();
};

void* d3dPointSpriteShader::vfunc_04()
{
    return DAT_007FB8F4;
}

}

// [TODO] 0x00705090 pure3d::d3dPointSpriteShader::vfunc_14 (54 B)
// [TODO] 0x007050F0 sub_007050F0 (102 B)
// ============================================================================
// [VERIFIED] pure3d::d3dPointSpriteShader::vfunc_03 (0x00705160, 53 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as pure3d::d3dSimpleShader::vfunc_03 (Proto 0x00263DB0), which was matched first;
// its addresses and names were swapped for this function's.
// pure3d::d3dPointSpriteShader::vfunc_03 (Proto 0x00705160, 53 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    virtual void vfunc_00();
    virtual void vfunc_01();
};

extern "C" char DAT_00774AAC[];
extern "C" void __cdecl sub_0043CE70(int);

namespace pure3d {

class d3dPointSpriteShader
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual d3dPointSpriteShader* vfunc_03(int a1);
    void sub_006527F0();
    char m_pad04[0x7C];
    int m_Field80; // +0x80
};

d3dPointSpriteShader* d3dPointSpriteShader::vfunc_03(int a1)
{
    int t1;

    t1 = m_Field80;
    *(int*)this = (int)DAT_00774AAC;
    if (m_Field80) {
        ((Object*)t1)->vfunc_01();
    }
    sub_006527F0();
    if (a1 & 1) {
        sub_0043CE70((int)this);
    }
    return this;
}

}

// [TODO] 0x007051A0 pure3d::d3dPointSpriteShader::vfunc_15 (446 B)
// [TODO] 0x00705360 sub_00705360 (111 B)
// ============================================================================
// [VERIFIED] pure3d::d3dLayeredShader::vfunc_16 (0x007053D0, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as pure3d::TargaHandler::vfunc_07 (0x0004A760), which was matched first;
// its addresses and names were swapped for this function's.
// pure3d::d3dLayeredShader::vfunc_16 (0x007053D0, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_007FBC28[];

namespace pure3d {

class d3dLayeredShader
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual void vfunc_05();
    virtual void vfunc_06();
    virtual void* vfunc_16();
};

void* d3dLayeredShader::vfunc_16()
{
    return DAT_007FBC28;
}

}

// ============================================================================
// [VERIFIED] pure3d::d3dLayeredShader::vfunc_17 (0x007053E0, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as pure3d::TargaHandler::vfunc_07 (0x0004A760), which was matched first;
// its addresses and names were swapped for this function's.
// pure3d::d3dLayeredShader::vfunc_17 (0x007053E0, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_007FBC70[];

namespace pure3d {

class d3dLayeredShader
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual void vfunc_05();
    virtual void vfunc_06();
    virtual void* vfunc_17();
};

void* d3dLayeredShader::vfunc_17()
{
    return DAT_007FBC70;
}

}

// ============================================================================
// [VERIFIED] pure3d::d3dLayeredShader::vfunc_18 (0x007053F0, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as pure3d::TargaHandler::vfunc_07 (0x0004A760), which was matched first;
// its addresses and names were swapped for this function's.
// pure3d::d3dLayeredShader::vfunc_18 (0x007053F0, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_007FBB50[];

namespace pure3d {

class d3dLayeredShader
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual void vfunc_05();
    virtual void vfunc_06();
    virtual void* vfunc_18();
};

void* d3dLayeredShader::vfunc_18()
{
    return DAT_007FBB50;
}

}

// ============================================================================
// [VERIFIED] pure3d::d3dLayeredShader::vfunc_19 (0x00705400, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as pure3d::TargaHandler::vfunc_07 (0x0004A760), which was matched first;
// its addresses and names were swapped for this function's.
// pure3d::d3dLayeredShader::vfunc_19 (0x00705400, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_007FBBB0[];

namespace pure3d {

class d3dLayeredShader
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual void vfunc_05();
    virtual void vfunc_06();
    virtual void* vfunc_19();
};

void* d3dLayeredShader::vfunc_19()
{
    return DAT_007FBBB0;
}

}

// ============================================================================
// [VERIFIED] pure3d::d3dLayeredShader::vfunc_04 (0x00705410, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as pure3d::d3dVehicleShader::vfunc_04 (0x002829C0), which was matched first;
// its addresses and names were swapped for this function's.
// bin: xb
// va: 0x00705410
// what: Returns the address of a fixed block in the game's data.
// tool: Claude Fable 5.2 (look-alike of 0x0004A760, names and addresses swapped)
// pure3d::d3dLayeredShader::vfunc_04 (0x00705410, 6 bytes)
extern "C" char DAT_00769BD0[];

namespace pure3d {

class d3dLayeredShader
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void* vfunc_04();
};

void* d3dLayeredShader::vfunc_04()
{
    return DAT_00769BD0;
}

}

// [TODO] 0x00705420 pure3d::d3dLayeredShader::vfunc_24 (16 B)
// ============================================================================
// [VERIFIED] sub_00705430 (0x00705430, 1 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_006DEDF0 (PC 0x006DEDF0), which was matched first;
// its addresses and names were swapped for this function's.
// sub_00705430 (PC 0x00705430, 1 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

void __cdecl sub_00705430(void)
{
}

// [TODO] 0x007054B0 sub_007054B0 (109 B)
// [TODO] 0x00705520 sub_00705520 (1337 B)
// [TODO] 0x00705A60 pure3d::d3dLayeredShader::vfunc_13 (89 B)
// [TODO] 0x00705AC0 pure3d::d3dLayeredShader::vfunc_14 (66 B)
// [TODO] 0x00705B10 sub_00705B10 (155 B)
// ============================================================================
// [VERIFIED] pure3d::d3dLayeredShader::vfunc_03 (0x00705BB0, 68 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as pure3d::d3dReflShader::vfunc_03 (Proto 0x00285B10), which was matched first;
// its addresses and names were swapped for this function's.
// pure3d::d3dLayeredShader::vfunc_03 (Proto 0x00705BB0, 68 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    virtual void vfunc_00();
    virtual void vfunc_01();
};

extern "C" char DAT_00774B34[];
extern "C" void __cdecl sub_0043CE70(int);

namespace pure3d {

class d3dLayeredShader
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual d3dLayeredShader* vfunc_03(int a1);
    void sub_006527F0();
    char m_pad04[0x7C];
    int m_Field80; // +0x80
    int m_Field84; // +0x84
};

d3dLayeredShader* d3dLayeredShader::vfunc_03(int a1)
{
    int t1, t3;

    t1 = m_Field80;
    *(int*)this = (int)DAT_00774B34;
    if (m_Field80) {
        ((Object*)t1)->vfunc_01();
    }
    t3 = m_Field84;
    if (m_Field84) {
        ((Object*)t3)->vfunc_01();
    }
    sub_006527F0();
    if (a1 & 1) {
        sub_0043CE70((int)this);
    }
    return this;
}

}

// [TODO] 0x00705C00 pure3d::d3dLayeredShader::vfunc_15 (844 B)
// [TODO] 0x00705FA0 sub_00705FA0 (927 B)
// [TODO] 0x00706340 pure3d::d3dLayeredShader::vfunc_25 (743 B)
// ============================================================================
// [VERIFIED] pure3d::d3dSpecularShader::vfunc_24 (0x00706680, 20 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G7 /Gd /GR /EHsc /Zp4
// ============================================================================
// bin: pc
// va: 0x00706680
// what: 
// tool: the portal's starter code (no AI)

// pure3d::d3dSpecularShader::vfunc_24 (PC 0x00706680, 20 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_007376F4[];
extern "C" char DAT_007680D8[];
extern "C" unsigned char DAT_00830A19;

namespace pure3d {

class d3dSpecularShader
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
    virtual int vfunc_24();
};

int d3dSpecularShader::vfunc_24()
{
    int r_eax;

    r_eax = (int)DAT_007376F4;
    if (!DAT_00830A19) {
        r_eax = (int)DAT_007680D8;
    }
    return r_eax;
}

}

// ============================================================================
// [VERIFIED] pure3d::d3dSpecularShader::vfunc_04 (0x007066A0, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as pure3d::d3dVehicleShader::vfunc_04 (0x002829C0), which was matched first;
// its addresses and names were swapped for this function's.
// bin: xb
// va: 0x007066A0
// what: Returns the address of a fixed block in the game's data.
// tool: Claude Fable 5.2 (look-alike of 0x0004A760, names and addresses swapped)
// pure3d::d3dSpecularShader::vfunc_04 (0x007066A0, 6 bytes)
extern "C" char DAT_007FBFE8[];

namespace pure3d {

class d3dSpecularShader
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void* vfunc_04();
};

void* d3dSpecularShader::vfunc_04()
{
    return DAT_007FBFE8;
}

}

// [TODO] 0x007066B0 sub_007066B0 (1058 B)
// [TODO] 0x00706AE0 sub_00706AE0 (147 B)
// ============================================================================
// [VERIFIED] pure3d::d3dSpecularShader::vfunc_16 (0x00706B80, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as pure3d::TargaHandler::vfunc_07 (0x0004A760), which was matched first;
// its addresses and names were swapped for this function's.
// pure3d::d3dSpecularShader::vfunc_16 (0x00706B80, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_007FBFA0[];

namespace pure3d {

class d3dSpecularShader
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual void vfunc_05();
    virtual void vfunc_06();
    virtual void* vfunc_16();
};

void* d3dSpecularShader::vfunc_16()
{
    return DAT_007FBFA0;
}

}

// ============================================================================
// [VERIFIED] pure3d::d3dSpecularShader::vfunc_17 (0x00706B90, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as pure3d::TargaHandler::vfunc_07 (0x0004A760), which was matched first;
// its addresses and names were swapped for this function's.
// pure3d::d3dSpecularShader::vfunc_17 (0x00706B90, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_007FBE98[];

namespace pure3d {

class d3dSpecularShader
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual void vfunc_05();
    virtual void vfunc_06();
    virtual void* vfunc_17();
};

void* d3dSpecularShader::vfunc_17()
{
    return DAT_007FBE98;
}

}

// ============================================================================
// [VERIFIED] pure3d::d3dSpecularShader::vfunc_18 (0x00706BA0, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as pure3d::TargaHandler::vfunc_07 (0x0004A760), which was matched first;
// its addresses and names were swapped for this function's.
// pure3d::d3dSpecularShader::vfunc_18 (0x00706BA0, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_007FBE50[];

namespace pure3d {

class d3dSpecularShader
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual void vfunc_05();
    virtual void vfunc_06();
    virtual void* vfunc_18();
};

void* d3dSpecularShader::vfunc_18()
{
    return DAT_007FBE50;
}

}

// ============================================================================
// [VERIFIED] pure3d::d3dSpecularShader::vfunc_19 (0x00706BB0, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as pure3d::TargaHandler::vfunc_07 (0x0004A760), which was matched first;
// its addresses and names were swapped for this function's.
// pure3d::d3dSpecularShader::vfunc_19 (0x00706BB0, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_007FBF40[];

namespace pure3d {

class d3dSpecularShader
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual void vfunc_05();
    virtual void vfunc_06();
    virtual void* vfunc_19();
};

void* d3dSpecularShader::vfunc_19()
{
    return DAT_007FBF40;
}

}

// ============================================================================
// [VERIFIED] pure3d::d3dSpecularShader::vfunc_03 (0x00706BC0, 30 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as CollisionManager::CollisionManagerFlowClient::vfunc_00 (0x00016060), which was matched first;
// its addresses and names were swapped for this function's.
// pure3d::d3dSpecularShader::vfunc_03 (0x00706BC0, 30 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __cdecl sub_0065B580(void);
extern "C" void __cdecl sub_0043CE70(int);

namespace pure3d {

class d3dSpecularShader
{
public:
    virtual d3dSpecularShader* vfunc_03(int a1);
};

d3dSpecularShader* d3dSpecularShader::vfunc_03(int a1)
{
    sub_0065B580();
    if (a1 & 1) {
        sub_0043CE70((int)this);
    }
    return this;
}

}

// [TODO] 0x00706BE0 pure3d::d3dSpecularShader::vfunc_15 (385 B)
// [TODO] 0x00706D62 pure3d::BMPHandler::vfunc_17 (297 B)
// [TODO] 0x00706E90 sub_00706E90 (1067 B)
// [TODO] 0x007072C0 pure3d::d3dSpecularShader::vfunc_25 (77 B)
// ============================================================================
// [VERIFIED] pure3d::d3dCharacterShader::vfunc_16 (0x00707310, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as pure3d::TargaHandler::vfunc_07 (0x0004A760), which was matched first;
// its addresses and names were swapped for this function's.
// pure3d::d3dCharacterShader::vfunc_16 (0x00707310, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_007FC198[];

namespace pure3d {

class d3dCharacterShader
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual void vfunc_05();
    virtual void vfunc_06();
    virtual void* vfunc_16();
};

void* d3dCharacterShader::vfunc_16()
{
    return DAT_007FC198;
}

}

// ============================================================================
// [VERIFIED] pure3d::d3dCharacterShader::vfunc_17 (0x00707320, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as pure3d::TargaHandler::vfunc_07 (0x0004A760), which was matched first;
// its addresses and names were swapped for this function's.
// pure3d::d3dCharacterShader::vfunc_17 (0x00707320, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_007FC0C0[];

namespace pure3d {

class d3dCharacterShader
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual void vfunc_05();
    virtual void vfunc_06();
    virtual void* vfunc_17();
};

void* d3dCharacterShader::vfunc_17()
{
    return DAT_007FC0C0;
}

}

// ============================================================================
// [VERIFIED] pure3d::d3dCharacterShader::vfunc_18 (0x00707330, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as pure3d::TargaHandler::vfunc_07 (0x0004A760), which was matched first;
// its addresses and names were swapped for this function's.
// pure3d::d3dCharacterShader::vfunc_18 (0x00707330, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_007FC078[];

namespace pure3d {

class d3dCharacterShader
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual void vfunc_05();
    virtual void vfunc_06();
    virtual void* vfunc_18();
};

void* d3dCharacterShader::vfunc_18()
{
    return DAT_007FC078;
}

}

// ============================================================================
// [VERIFIED] pure3d::d3dCharacterShader::vfunc_19 (0x00707340, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as pure3d::TargaHandler::vfunc_07 (0x0004A760), which was matched first;
// its addresses and names were swapped for this function's.
// pure3d::d3dCharacterShader::vfunc_19 (0x00707340, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0085D760[];

namespace pure3d {

class d3dCharacterShader
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual void vfunc_05();
    virtual void vfunc_06();
    virtual void* vfunc_19();
};

void* d3dCharacterShader::vfunc_19()
{
    return DAT_0085D760;
}

}

// ============================================================================
// [VERIFIED] pure3d::d3dCharacterShader::vfunc_04 (0x00707350, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as pure3d::d3dVehicleShader::vfunc_04 (0x002829C0), which was matched first;
// its addresses and names were swapped for this function's.
// bin: xb
// va: 0x00707350
// what: Returns the address of a fixed block in the game's data.
// tool: Claude Fable 5.2 (look-alike of 0x0004A760, names and addresses swapped)
// pure3d::d3dCharacterShader::vfunc_04 (0x00707350, 6 bytes)
extern "C" char DAT_0073E280[];

namespace pure3d {

class d3dCharacterShader
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void* vfunc_04();
};

void* d3dCharacterShader::vfunc_04()
{
    return DAT_0073E280;
}

}

// [TODO] 0x00707360 pure3d::d3dShader::vfunc_22 (38 B)
// [TODO] 0x00707390 pure3d::d3dCharacterShader::vfunc_24 (16 B)
// ============================================================================
// [VERIFIED] sub_007073A0 (0x007073A0, 1 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_006DEDF0 (PC 0x006DEDF0), which was matched first;
// its addresses and names were swapped for this function's.
// sub_007073A0 (PC 0x007073A0, 1 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

void __cdecl sub_007073A0(void)
{
}

// [TODO] 0x007073B0 sub_007073B0 (1319 B)
// [TODO] 0x007078E0 sub_007078E0 (77 B)
// ============================================================================
// [VERIFIED] pure3d::d3dCharacterShader::vfunc_03 (0x00707930, 68 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as pure3d::d3dReflShader::vfunc_03 (Proto 0x00285B10), which was matched first;
// its addresses and names were swapped for this function's.
// pure3d::d3dCharacterShader::vfunc_03 (Proto 0x00707930, 68 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    virtual void vfunc_00();
    virtual void vfunc_01();
};

extern "C" char DAT_00774C4C[];
extern "C" void __cdecl sub_0043CE70(int);

namespace pure3d {

class d3dCharacterShader
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual d3dCharacterShader* vfunc_03(int a1);
    void sub_006527F0();
    char m_pad04[0x7C];
    int m_Field80; // +0x80
    int m_Field84; // +0x84
};

d3dCharacterShader* d3dCharacterShader::vfunc_03(int a1)
{
    int t1, t3;

    t1 = m_Field80;
    *(int*)this = (int)DAT_00774C4C;
    if (m_Field80) {
        ((Object*)t1)->vfunc_01();
    }
    t3 = m_Field84;
    if (m_Field84) {
        ((Object*)t3)->vfunc_01();
    }
    sub_006527F0();
    if (a1 & 1) {
        sub_0043CE70((int)this);
    }
    return this;
}

}

// [TODO] 0x00707980 pure3d::d3dCharacterShader::vfunc_15 (417 B)
// [TODO] 0x00707B30 sub_00707B30 (593 B)
// ============================================================================
// [VERIFIED] sub_00707D80 (0x00707D80, 1 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_006DEDF0 (PC 0x006DEDF0), which was matched first;
// its addresses and names were swapped for this function's.
// sub_00707D80 (PC 0x00707D80, 1 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

void __cdecl sub_00707D80(void)
{
}

// [TODO] 0x00707D90 pure3d::d3dCharacterShader::vfunc_25 (58 B)
// [TODO] 0x00707E60 sub_00707E60 (57 B)
// ============================================================================
// [VERIFIED] pure3d::d3dVehicleShader::vfunc_04 (0x00707EA0, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as pure3d::d3dVehicleShader::vfunc_04 (0x002829C0), which was matched first;
// its addresses and names were swapped for this function's.
// bin: xb
// va: 0x00707EA0
// what: Returns the address of a fixed block in the game's data.
// tool: Claude Fable 5.2 (look-alike of 0x0004A760, names and addresses swapped)
// pure3d::d3dVehicleShader::vfunc_04 (0x00707EA0, 6 bytes)
extern "C" char DAT_007331B0[];

namespace pure3d {

class d3dVehicleShader
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void* vfunc_04();
};

void* d3dVehicleShader::vfunc_04()
{
    return DAT_007331B0;
}

}

// [TODO] 0x00707EB0 pure3d::d3dVehicleShader::vfunc_36 (35 B)
// ============================================================================
// [VERIFIED] pure3d::d3dVehicleShader::vfunc_37 (0x00707EE0, 15 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// bin: pc
// va: 0x00707EE0
// what: 
// tool: the portal's starter code (no AI)

// pure3d::d3dVehicleShader::vfunc_37 (PC 0x00707EE0, 15 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_00830A50;

namespace pure3d {

class d3dVehicleShader
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
    virtual void vfunc_30();
    virtual void vfunc_31();
    virtual void vfunc_32();
    virtual void vfunc_33();
    virtual void vfunc_34();
    virtual void vfunc_35();
    virtual void vfunc_36();
    virtual int vfunc_37(int a1);
};

int d3dVehicleShader::vfunc_37(int a1)
{
    *(int*)a1 = DAT_00830A50;
    return a1;
}

}

// ============================================================================
// [VERIFIED] pure3d::d3dVehicleShader::vfunc_16 (0x00707EF0, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as pure3d::TargaHandler::vfunc_07 (0x0004A760), which was matched first;
// its addresses and names were swapped for this function's.
// pure3d::d3dVehicleShader::vfunc_16 (0x00707EF0, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_007FC550[];

namespace pure3d {

class d3dVehicleShader
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual void vfunc_05();
    virtual void vfunc_06();
    virtual void* vfunc_16();
};

void* d3dVehicleShader::vfunc_16()
{
    return DAT_007FC550;
}

}

// ============================================================================
// [VERIFIED] pure3d::d3dVehicleShader::vfunc_17 (0x00707F00, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as pure3d::TargaHandler::vfunc_07 (0x0004A760), which was matched first;
// its addresses and names were swapped for this function's.
// pure3d::d3dVehicleShader::vfunc_17 (0x00707F00, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_007FC4C0[];

namespace pure3d {

class d3dVehicleShader
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual void vfunc_05();
    virtual void vfunc_06();
    virtual void* vfunc_17();
};

void* d3dVehicleShader::vfunc_17()
{
    return DAT_007FC4C0;
}

}

// ============================================================================
// [VERIFIED] pure3d::d3dVehicleShader::vfunc_18 (0x00707F10, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as pure3d::TargaHandler::vfunc_07 (0x0004A760), which was matched first;
// its addresses and names were swapped for this function's.
// pure3d::d3dVehicleShader::vfunc_18 (0x00707F10, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_007FC418[];

namespace pure3d {

class d3dVehicleShader
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual void vfunc_05();
    virtual void vfunc_06();
    virtual void* vfunc_18();
};

void* d3dVehicleShader::vfunc_18()
{
    return DAT_007FC418;
}

}

// ============================================================================
// [VERIFIED] pure3d::d3dVehicleShader::vfunc_19 (0x00707F20, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as pure3d::TargaHandler::vfunc_07 (0x0004A760), which was matched first;
// its addresses and names were swapped for this function's.
// pure3d::d3dVehicleShader::vfunc_19 (0x00707F20, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_007FC508[];

namespace pure3d {

class d3dVehicleShader
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual void vfunc_05();
    virtual void vfunc_06();
    virtual void* vfunc_19();
};

void* d3dVehicleShader::vfunc_19()
{
    return DAT_007FC508;
}

}

// [TODO] 0x00707F30 pure3d::d3dVehicleShader::vfunc_26 (463 B)
// ============================================================================
// [VERIFIED] pure3d::d3dVehicleShader::vfunc_31 (0x00708100, 13 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// What it does: Stores a number at +0x94 and returns it.
// ============================================================================
// bin: pc
// va: 0x00708100
// what: Stores a number at +0x94 and returns it.
// tool: Claude Opus 5.5 (transplanted from proto:0x0007DD30, nearest by portal/tools/similar.py)
// sub_00708100 (Proto 0x00708100, 13 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

class Class_00708100
{
public:
    int sub_00708100(int a1);
    char m_pad00[0x94];
    int m_Field94; // +0x94
};

int Class_00708100::sub_00708100(int a1)
{
    m_Field94 = a1;
    return a1;
}

// ============================================================================
// [VERIFIED] pure3d::d3dVehicleShader::vfunc_30 (0x00708110, 13 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// What it does: Stores a number at +0x98 and returns it.
// ============================================================================
// bin: pc
// va: 0x00708110
// what: Stores a number at +0x98 and returns it.
// tool: Claude Opus 5.5 (transplanted from proto:0x0007DD30, nearest by portal/tools/similar.py)
// sub_00708110 (Proto 0x00708110, 13 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

class Class_00708110
{
public:
    int sub_00708110(int a1);
    char m_pad00[0x98];
    int m_Field98; // +0x98
};

int Class_00708110::sub_00708110(int a1)
{
    m_Field98 = a1;
    return a1;
}

// ============================================================================
// [VERIFIED] pure3d::d3dVehicleShader::vfunc_28 (0x00708120, 13 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// What it does: Stores a number at +0x88 and returns it.
// ============================================================================
// bin: pc
// va: 0x00708120
// what: Stores a number at +0x88 and returns it.
// tool: Claude Opus 5.5 (transplanted from proto:0x0007DD30, nearest by portal/tools/similar.py)
// sub_00708120 (Proto 0x00708120, 13 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

class Class_00708120
{
public:
    int sub_00708120(int a1);
    char m_pad00[0x88];
    int m_Field88; // +0x88
};

int Class_00708120::sub_00708120(int a1)
{
    m_Field88 = a1;
    return a1;
}

// [TODO] 0x00708130 pure3d::d3dVehicleShader::vfunc_32 (115 B)
// [TODO] 0x007081B0 pure3d::d3dVehicleShader::vfunc_33 (92 B)
// [TODO] 0x00708210 pure3d::d3dVehicleShader::vfunc_34 (92 B)
// [TODO] 0x00708270 sub_00708270 (104 B)
// [TODO] 0x007082E0 pure3d::d3dVehicleShader::vfunc_35 (104 B)
// [TODO] 0x00708350 sub_00708350 (1058 B)
// [TODO] 0x007087B0 sub_007087B0 (255 B)
// ============================================================================
// [VERIFIED] pure3d::d3dVehicleShader::vfunc_03 (0x007088B0, 30 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as CollisionManager::CollisionManagerFlowClient::vfunc_00 (0x00016060), which was matched first;
// its addresses and names were swapped for this function's.
// pure3d::d3dVehicleShader::vfunc_03 (0x007088B0, 30 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __cdecl sub_00707E60(void);
extern "C" void __cdecl sub_0043CE70(int);

namespace pure3d {

class d3dVehicleShader
{
public:
    virtual d3dVehicleShader* vfunc_03(int a1);
};

d3dVehicleShader* d3dVehicleShader::vfunc_03(int a1)
{
    sub_00707E60();
    if (a1 & 1) {
        sub_0043CE70((int)this);
    }
    return this;
}

}

// [TODO] 0x007088D0 pure3d::d3dVehicleShader::vfunc_15 (292 B)
// [TODO] 0x00708A00 pure3d::d3dVehicleShader::vfunc_25 (1058 B)
// ============================================================================
// [VERIFIED] pure3d::d3dShadowShader::vfunc_16 (0x00708F50, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as pure3d::TargaHandler::vfunc_07 (0x0004A760), which was matched first;
// its addresses and names were swapped for this function's.
// pure3d::d3dShadowShader::vfunc_16 (0x00708F50, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_007FC7E0[];

namespace pure3d {

class d3dShadowShader
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual void vfunc_05();
    virtual void vfunc_06();
    virtual void* vfunc_16();
};

void* d3dShadowShader::vfunc_16()
{
    return DAT_007FC7E0;
}

}

// ============================================================================
// [VERIFIED] pure3d::d3dShadowShader::vfunc_17 (0x00708F60, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as pure3d::TargaHandler::vfunc_07 (0x0004A760), which was matched first;
// its addresses and names were swapped for this function's.
// pure3d::d3dShadowShader::vfunc_17 (0x00708F60, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_007FC690[];

namespace pure3d {

class d3dShadowShader
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual void vfunc_05();
    virtual void vfunc_06();
    virtual void* vfunc_17();
};

void* d3dShadowShader::vfunc_17()
{
    return DAT_007FC690;
}

}

// ============================================================================
// [VERIFIED] pure3d::d3dShadowShader::vfunc_18 (0x00708F70, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as pure3d::TargaHandler::vfunc_07 (0x0004A760), which was matched first;
// its addresses and names were swapped for this function's.
// pure3d::d3dShadowShader::vfunc_18 (0x00708F70, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_007FC648[];

namespace pure3d {

class d3dShadowShader
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual void vfunc_05();
    virtual void vfunc_06();
    virtual void* vfunc_18();
};

void* d3dShadowShader::vfunc_18()
{
    return DAT_007FC648;
}

}

// ============================================================================
// [VERIFIED] pure3d::d3dShadowShader::vfunc_19 (0x00708F80, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as pure3d::TargaHandler::vfunc_07 (0x0004A760), which was matched first;
// its addresses and names were swapped for this function's.
// pure3d::d3dShadowShader::vfunc_19 (0x00708F80, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_007FC768[];

namespace pure3d {

class d3dShadowShader
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual void vfunc_05();
    virtual void vfunc_06();
    virtual void* vfunc_19();
};

void* d3dShadowShader::vfunc_19()
{
    return DAT_007FC768;
}

}

// ============================================================================
// [VERIFIED] pure3d::d3dShadowShader::vfunc_04 (0x00708F90, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as pure3d::d3dVehicleShader::vfunc_04 (0x002829C0), which was matched first;
// its addresses and names were swapped for this function's.
// bin: xb
// va: 0x00708F90
// what: Returns the address of a fixed block in the game's data.
// tool: Claude Fable 5.2 (look-alike of 0x0004A760, names and addresses swapped)
// pure3d::d3dShadowShader::vfunc_04 (0x00708F90, 6 bytes)
extern "C" char DAT_0072F5B0[];

namespace pure3d {

class d3dShadowShader
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void* vfunc_04();
};

void* d3dShadowShader::vfunc_04()
{
    return DAT_0072F5B0;
}

}

// [TODO] 0x00708FA0 pure3d::d3dShadowShader::vfunc_15 (136 B)
// ============================================================================
// [VERIFIED] sub_00709030 (0x00709030, 44 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_002875F0 (Proto 0x002875F0), which was matched first;
// its addresses and names were swapped for this function's.
// sub_00709030 (Proto 0x00709030, 44 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_00774D94[];
extern "C" void __stdcall sub_006524F0(int);

class Class_00709030
{
public:
    Class_00709030* sub_00709030(int a1);
    void sub_00517CE0(int);
    int m_Field00; // +0x00
    char m_pad04[0x7C];
    int m_Field80; // +0x80
};

Class_00709030* Class_00709030::sub_00709030(int a1)
{
    sub_006524F0(a1);
    m_Field00 = (int)DAT_00774D94;
    m_Field80 = 0;
    sub_00517CE0(0);
    return this;
}

// ============================================================================
// [VERIFIED] pure3d::d3dShadowShader::vfunc_03 (0x00709060, 53 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as pure3d::d3dSimpleShader::vfunc_03 (Proto 0x00263DB0), which was matched first;
// its addresses and names were swapped for this function's.
// pure3d::d3dShadowShader::vfunc_03 (Proto 0x00709060, 53 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    virtual void vfunc_00();
    virtual void vfunc_01();
};

extern "C" char DAT_00774D94[];
extern "C" void __cdecl sub_0043CE70(int);

namespace pure3d {

class d3dShadowShader
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual d3dShadowShader* vfunc_03(int a1);
    void sub_006527F0();
    char m_pad04[0x7C];
    int m_Field80; // +0x80
};

d3dShadowShader* d3dShadowShader::vfunc_03(int a1)
{
    int t1;

    t1 = m_Field80;
    *(int*)this = (int)DAT_00774D94;
    if (m_Field80) {
        ((Object*)t1)->vfunc_01();
    }
    sub_006527F0();
    if (a1 & 1) {
        sub_0043CE70((int)this);
    }
    return this;
}

}

// ============================================================================
// [VERIFIED] pure3d::d3dShadowDecalShader::vfunc_16 (0x007090A0, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as pure3d::TargaHandler::vfunc_07 (0x0004A760), which was matched first;
// its addresses and names were swapped for this function's.
// pure3d::d3dShadowDecalShader::vfunc_16 (0x007090A0, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_007FC968[];

namespace pure3d {

class d3dShadowDecalShader
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual void vfunc_05();
    virtual void vfunc_06();
    virtual void* vfunc_16();
};

void* d3dShadowDecalShader::vfunc_16()
{
    return DAT_007FC968;
}

}

// ============================================================================
// [VERIFIED] pure3d::d3dShadowDecalShader::vfunc_17 (0x007090B0, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as pure3d::TargaHandler::vfunc_07 (0x0004A760), which was matched first;
// its addresses and names were swapped for this function's.
// pure3d::d3dShadowDecalShader::vfunc_17 (0x007090B0, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_007FC890[];

namespace pure3d {

class d3dShadowDecalShader
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual void vfunc_05();
    virtual void vfunc_06();
    virtual void* vfunc_17();
};

void* d3dShadowDecalShader::vfunc_17()
{
    return DAT_007FC890;
}

}

// ============================================================================
// [VERIFIED] pure3d::d3dShadowDecalShader::vfunc_18 (0x007090C0, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as pure3d::TargaHandler::vfunc_07 (0x0004A760), which was matched first;
// its addresses and names were swapped for this function's.
// pure3d::d3dShadowDecalShader::vfunc_18 (0x007090C0, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_007FC848[];

namespace pure3d {

class d3dShadowDecalShader
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual void vfunc_05();
    virtual void vfunc_06();
    virtual void* vfunc_18();
};

void* d3dShadowDecalShader::vfunc_18()
{
    return DAT_007FC848;
}

}

// ============================================================================
// [VERIFIED] pure3d::d3dShadowDecalShader::vfunc_19 (0x007090D0, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as pure3d::TargaHandler::vfunc_07 (0x0004A760), which was matched first;
// its addresses and names were swapped for this function's.
// pure3d::d3dShadowDecalShader::vfunc_19 (0x007090D0, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0085D788[];

namespace pure3d {

class d3dShadowDecalShader
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual void vfunc_05();
    virtual void vfunc_06();
    virtual void* vfunc_19();
};

void* d3dShadowDecalShader::vfunc_19()
{
    return DAT_0085D788;
}

}

// ============================================================================
// [VERIFIED] pure3d::d3dShadowDecalShader::vfunc_04 (0x007090E0, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as pure3d::d3dVehicleShader::vfunc_04 (0x002829C0), which was matched first;
// its addresses and names were swapped for this function's.
// bin: xb
// va: 0x007090E0
// what: Returns the address of a fixed block in the game's data.
// tool: Claude Fable 5.2 (look-alike of 0x0004A760, names and addresses swapped)
// pure3d::d3dShadowDecalShader::vfunc_04 (0x007090E0, 6 bytes)
extern "C" char DAT_00769C04[];

namespace pure3d {

class d3dShadowDecalShader
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void* vfunc_04();
};

void* d3dShadowDecalShader::vfunc_04()
{
    return DAT_00769C04;
}

}

// ============================================================================
// [VERIFIED] pure3d::d3dShadowDecalShader::vfunc_14 (0x007090F0, 23 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// bin: pc
// va: 0x007090F0
// what: 
// tool: the portal's starter code (no AI)

// pure3d::d3dShadowDecalShader::vfunc_14 (PC 0x007090F0, 23 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field10
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
    virtual void vfunc_23();
    virtual void vfunc_24();
    virtual void vfunc_25();
    virtual void vfunc_26();
    virtual void vfunc_27();
    virtual void vfunc_28();
    virtual void vfunc_29();
    virtual void vfunc_30();
    virtual void vfunc_31();
    virtual void vfunc_32();
    virtual void vfunc_33();
    virtual void vfunc_34();
    virtual void vfunc_35();
    virtual void vfunc_36();
    virtual void vfunc_37();
    virtual void vfunc_38();
    virtual void vfunc_39();
    virtual void vfunc_40();
    virtual void vfunc_41();
    virtual void vfunc_42();
    virtual void vfunc_43();
    virtual void vfunc_44();
    virtual void vfunc_45();
    virtual void vfunc_46();
    virtual void vfunc_47();
    virtual void vfunc_48();
    virtual void vfunc_49();
    virtual void vfunc_50();
    virtual void vfunc_51();
    virtual void vfunc_52();
    virtual void vfunc_53();
    virtual void vfunc_54();
    virtual void vfunc_55();
    virtual void vfunc_56();
    virtual void vfunc_57();
    virtual void vfunc_58();
    virtual void vfunc_59();
    virtual void vfunc_60();
    virtual void vfunc_61();
    virtual void vfunc_62();
    virtual void vfunc_63();
    virtual void vfunc_64();
    virtual void vfunc_65();
    virtual void vfunc_66();
    virtual void vfunc_67();
    virtual void vfunc_68();
    virtual void vfunc_69();
    virtual void vfunc_70(int);
};

extern "C" void __cdecl sub_005E1BB0(void);

namespace pure3d {

class d3dShadowDecalShader
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
    char m_pad04[0xC];
    Field10* m_Field10; // +0x10
};

void d3dShadowDecalShader::vfunc_14()
{
    sub_005E1BB0();
    m_Field10->vfunc_70(1);
}

}

// [TODO] 0x00709110 sub_00709110 (83 B)
// ============================================================================
// [VERIFIED] pure3d::d3dShadowDecalShader::vfunc_03 (0x00709170, 53 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as pure3d::d3dSimpleShader::vfunc_03 (Proto 0x00263DB0), which was matched first;
// its addresses and names were swapped for this function's.
// pure3d::d3dShadowDecalShader::vfunc_03 (Proto 0x00709170, 53 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    virtual void vfunc_00();
    virtual void vfunc_01();
};

extern "C" char DAT_00774E1C[];
extern "C" void __cdecl sub_0043CE70(int);

namespace pure3d {

class d3dShadowDecalShader
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual d3dShadowDecalShader* vfunc_03(int a1);
    void sub_006527F0();
    char m_pad04[0x7C];
    int m_Field80; // +0x80
};

d3dShadowDecalShader* d3dShadowDecalShader::vfunc_03(int a1)
{
    int t1;

    t1 = m_Field80;
    *(int*)this = (int)DAT_00774E1C;
    if (m_Field80) {
        ((Object*)t1)->vfunc_01();
    }
    sub_006527F0();
    if (a1 & 1) {
        sub_0043CE70((int)this);
    }
    return this;
}

}

// [TODO] 0x007091B0 pure3d::d3dShadowDecalShader::vfunc_15 (408 B)
// ============================================================================
// [VERIFIED] sub_00709350 (0x00709350, 25 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_0020DAB0 (Proto 0x0020DAB0), which was matched first;
// its addresses and names were swapped for this function's.
// sub_00709350 (Proto 0x00709350, 25 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_00774EA4[];
extern "C" void __stdcall sub_0065BD30(int);

class Class_00709350
{
public:
    Class_00709350* sub_00709350(int a1);
    int m_Field00; // +0x00
};

Class_00709350* Class_00709350::sub_00709350(int a1)
{
    sub_0065BD30(a1);
    m_Field00 = (int)DAT_00774EA4;
    return this;
}

// ============================================================================
// [VERIFIED] pure3d::d3dDecalShader::vfunc_04 (0x00709370, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as pure3d::d3dVehicleShader::vfunc_04 (0x002829C0), which was matched first;
// its addresses and names were swapped for this function's.
// bin: xb
// va: 0x00709370
// what: Returns the address of a fixed block in the game's data.
// tool: Claude Fable 5.2 (look-alike of 0x0004A760, names and addresses swapped)
// pure3d::d3dDecalShader::vfunc_04 (0x00709370, 6 bytes)
extern "C" char DAT_00769C24[];

namespace pure3d {

class d3dDecalShader
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void* vfunc_04();
};

void* d3dDecalShader::vfunc_04()
{
    return DAT_00769C24;
}

}

// [TODO] 0x00709380 pure3d::d3dDecalShader::vfunc_15 (171 B)
// ============================================================================
// [VERIFIED] pure3d::d3dDecalShader::vfunc_14 (0x00709430, 5 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as renderer::InstanceRenderable::vfunc_10 (0x00054F90), which was matched first;
// its addresses and names were swapped for this function's.
// pure3d::d3dDecalShader::vfunc_14 (0x00709430, 5 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __cdecl sub_0065BC10(void);

namespace pure3d {

class d3dDecalShader
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
    virtual void vfunc_14();
};

void d3dDecalShader::vfunc_14()
{
    sub_0065BC10();
}

}

// ============================================================================
// [VERIFIED] pure3d::d3dDecalShader::vfunc_03 (0x00709440, 36 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as LOSManager::LOSManagerFlowClient::vfunc_00 (0x000179C0), which was matched first;
// its addresses and names were swapped for this function's.
// pure3d::d3dDecalShader::vfunc_03 (0x00709440, 36 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_00774EA4[];
extern "C" void __cdecl sub_0043CE70(int);
extern "C" void __cdecl sub_0065B580(void);

namespace pure3d {

class d3dDecalShader
{
public:
    virtual d3dDecalShader* vfunc_03(int a1);
};

d3dDecalShader* d3dDecalShader::vfunc_03(int a1)
{
    *(int*)this = (int)DAT_00774EA4;
    sub_0065B580();
    if (a1 & 1) {
        sub_0043CE70((int)this);
    }
    return this;
}

}

// ============================================================================
// [VERIFIED] pure3d::d3dVertexFadeShader::vfunc_04 (0x00709470, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as pure3d::d3dVehicleShader::vfunc_04 (0x002829C0), which was matched first;
// its addresses and names were swapped for this function's.
// bin: xb
// va: 0x00709470
// what: Returns the address of a fixed block in the game's data.
// tool: Claude Fable 5.2 (look-alike of 0x0004A760, names and addresses swapped)
// pure3d::d3dVertexFadeShader::vfunc_04 (0x00709470, 6 bytes)
extern "C" char DAT_007FC9FC[];

namespace pure3d {

class d3dVertexFadeShader
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void* vfunc_04();
};

void* d3dVertexFadeShader::vfunc_04()
{
    return DAT_007FC9FC;
}

}

// ============================================================================
// [VERIFIED] pure3d::ParticleEmitter::vfunc_33 (0x00709480, 44 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as pure3d::ParticleEmitter::vfunc_32 (Proto 0x00286310), which was matched first;
// its addresses and names were swapped for this function's.
// pure3d::ParticleEmitter::vfunc_33 (Proto 0x00709480, 44 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    virtual void vfunc_00();
    virtual void vfunc_01();
};

namespace pure3d {

class ParticleEmitter
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
    virtual void vfunc_30();
    virtual void vfunc_31();
    virtual void vfunc_32();
    virtual void vfunc_33(int a1);
    char m_pad04[0x7C];
    int m_Field80; // +0x80
};

void ParticleEmitter::vfunc_33(int a1)
{
    int t2;

    if (a1) {
        ((Object*)a1)->vfunc_00();
    }
    t2 = m_Field80;
    if (m_Field80) {
        ((Object*)t2)->vfunc_01();
    }
    m_Field80 = a1;
}

}

// ============================================================================
// [VERIFIED] pure3d::d3dVertexFadeShader::vfunc_24 (0x007094B0, 20 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G7 /Gd /GR /EHsc /Zp4
// ============================================================================
// bin: pc
// va: 0x007094B0
// what: 
// tool: the portal's starter code (no AI)

// pure3d::d3dVertexFadeShader::vfunc_24 (PC 0x007094B0, 20 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_007680A8[];
extern "C" char DAT_007680BC[];

namespace pure3d {

class d3dVertexFadeShader
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
    virtual int vfunc_24();
    char m_pad04[0x7C];
    int m_Field80; // +0x80
};

int d3dVertexFadeShader::vfunc_24()
{
    int r_eax;

    r_eax = (int)DAT_007680A8;
    if (!m_Field80) {
        r_eax = (int)DAT_007680BC;
    }
    return r_eax;
}

}

// [TODO] 0x007094D0 sub_007094D0 (1239 B)
// [TODO] 0x007099B0 sub_007099B0 (63 B)
// ============================================================================
// [VERIFIED] pure3d::d3dVertexFadeShader::vfunc_16 (0x007099F0, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as pure3d::TargaHandler::vfunc_07 (0x0004A760), which was matched first;
// its addresses and names were swapped for this function's.
// pure3d::d3dVertexFadeShader::vfunc_16 (0x007099F0, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_007FCAF8[];

namespace pure3d {

class d3dVertexFadeShader
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual void vfunc_05();
    virtual void vfunc_06();
    virtual void* vfunc_16();
};

void* d3dVertexFadeShader::vfunc_16()
{
    return DAT_007FCAF8;
}

}

// ============================================================================
// [VERIFIED] pure3d::d3dVertexFadeShader::vfunc_17 (0x00709A00, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as pure3d::TargaHandler::vfunc_07 (0x0004A760), which was matched first;
// its addresses and names were swapped for this function's.
// pure3d::d3dVertexFadeShader::vfunc_17 (0x00709A00, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_007FCA50[];

namespace pure3d {

class d3dVertexFadeShader
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual void vfunc_05();
    virtual void vfunc_06();
    virtual void* vfunc_17();
};

void* d3dVertexFadeShader::vfunc_17()
{
    return DAT_007FCA50;
}

}

// ============================================================================
// [VERIFIED] pure3d::d3dVertexFadeShader::vfunc_18 (0x00709A10, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as pure3d::TargaHandler::vfunc_07 (0x0004A760), which was matched first;
// its addresses and names were swapped for this function's.
// pure3d::d3dVertexFadeShader::vfunc_18 (0x00709A10, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_007FCB70[];

namespace pure3d {

class d3dVertexFadeShader
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual void vfunc_05();
    virtual void vfunc_06();
    virtual void* vfunc_18();
};

void* d3dVertexFadeShader::vfunc_18()
{
    return DAT_007FCB70;
}

}

// ============================================================================
// [VERIFIED] pure3d::d3dVertexFadeShader::vfunc_19 (0x00709A20, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as pure3d::TargaHandler::vfunc_07 (0x0004A760), which was matched first;
// its addresses and names were swapped for this function's.
// pure3d::d3dVertexFadeShader::vfunc_19 (0x00709A20, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_007FCB28[];

namespace pure3d {

class d3dVertexFadeShader
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual void vfunc_05();
    virtual void vfunc_06();
    virtual void* vfunc_19();
};

void* d3dVertexFadeShader::vfunc_19()
{
    return DAT_007FCB28;
}

}

// [TODO] 0x00709A30 pure3d::d3dVertexFadeShader::vfunc_15 (629 B)
// [TODO] 0x00709CB0 sub_00709CB0 (740 B)
// [TODO] 0x00709FA0 pure3d::d3dVertexFadeShader::vfunc_25 (66 B)
// ============================================================================
// [VERIFIED] sub_00709FE2 (0x00709FE2, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00012130 (0x00012130), which was matched first;
// its addresses and names were swapped for this function's.
// sub_00709FE2 (0x00709FE2, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_0072F308;

class Class_00709FE2
{
public:
    void sub_00709FE2();
};

void Class_00709FE2::sub_00709FE2()
{
    ((void (__cdecl*)(void))DAT_0072F308)();
}

// ============================================================================
// [VERIFIED] sub_0072C940 (0x0072C940, 1 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_006DEDF0 (PC 0x006DEDF0), which was matched first;
// its addresses and names were swapped for this function's.
// sub_0072C940 (PC 0x0072C940, 1 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

void __cdecl sub_0072C940(void)
{
}

// ============================================================================
// [VERIFIED] sub_0072CC00 (0x0072CC00, 1 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_006DEDF0 (PC 0x006DEDF0), which was matched first;
// its addresses and names were swapped for this function's.
// sub_0072CC00 (PC 0x0072CC00, 1 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

void __cdecl sub_0072CC00(void)
{
}

// ============================================================================
// [VERIFIED] sub_0072CC10 (0x0072CC10, 1 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_006DEDF0 (PC 0x006DEDF0), which was matched first;
// its addresses and names were swapped for this function's.
// sub_0072CC10 (PC 0x0072CC10, 1 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

void __cdecl sub_0072CC10(void)
{
}

// ============================================================================
// [VERIFIED] sub_0072CD30 (0x0072CD30, 1 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_006DEDF0 (PC 0x006DEDF0), which was matched first;
// its addresses and names were swapped for this function's.
// sub_0072CD30 (PC 0x0072CD30, 1 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

void __cdecl sub_0072CD30(void)
{
}

