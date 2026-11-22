// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail PC Scarface.exe v1.00.2, core/ControllerDirectInput.cpp (5 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 5 of 18 functions matched (27.78%). NOT COMPLETE YET.
// The 13 still to do are listed in their place in Original_Binary_Order_PC_1002.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

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

