// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail PC Scarface.exe v1.00.2, core/ControllerSystemDirectInput.cpp (4 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 4 of 7 functions matched (57.14%). NOT COMPLETE YET.
// The 3 still to do are listed in their place in Original_Binary_Order_PC_1002.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

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

