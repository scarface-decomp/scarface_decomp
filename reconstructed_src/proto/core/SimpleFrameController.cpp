// ============================================================================
// SCARFACE: THE WORLD IS YOURS — April 2006 prototype game.xbe, core/SimpleFrameController.cpp (6 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 6 of 14 functions matched (42.86%). NOT COMPLETE YET.
// The 8 still to do are listed in their place in Original_Binary_Order_Proto.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] pure3d::SimpleFrameController::vfunc_27 (0x000D52E0, 4 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as pure3d::SimpleFrameController::vfunc_27 (0x00061970), which was matched first;
// its addresses and names were swapped for this function's.
// pure3d::SimpleFrameController::vfunc_27 (0x000D52E0, 4 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

namespace pure3d {

class SimpleFrameController
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
    virtual int vfunc_27();
    char m_pad04[0x2C];
    int m_Field30; // +0x30
};

int SimpleFrameController::vfunc_27()
{
    return m_Field30;
}

}

// ============================================================================
// [VERIFIED] pure3d::SimpleFrameController::vfunc_12 (0x00225180, 18 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as pure3d::SimpleFrameController::vfunc_12 (0x00273400), which was matched first;
// its addresses and names were swapped for this function's.
// bin: xb
// va: 0x00225180
// what: Returns the number at +0x10 of the object pointed to at +0x30, or the constant at 0x0037E6C0 when there is none.
// tool: Claude Opus 5.5 (generated from the shape 'float through a pointer or a default', checked on decomp.me preset 266 by example)
extern "C" const float DAT_0037E6C0;

struct Obj_00225180
{
    char m_pad00[0x10];
    float m_Field10; // +0x10
};

class Class_00225180
{
public:
    float sub_00225180();
    char m_pad00[0x30];
    Obj_00225180* m_Field30; // +0x30
};

float Class_00225180::sub_00225180()
{
    if (m_Field30)
        return m_Field30->m_Field10;
    return DAT_0037E6C0;
}

// ============================================================================
// [VERIFIED] pure3d::SimpleFrameController::vfunc_13 (0x002251A0, 18 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as pure3d::SimpleFrameController::vfunc_13 (0x00273420), which was matched first;
// its addresses and names were swapped for this function's.
// bin: xb
// va: 0x002251A0
// what: Returns the number at +0xC of the object pointed to at +0x30, or the constant at 0x0037CD94 when there is none.
// tool: Claude Opus 5.5 (generated from the shape 'float through a pointer or a default', checked on decomp.me preset 266 by example)
extern "C" const float DAT_0037CD94;

struct Obj_002251A0
{
    char m_pad00[0xC];
    float m_FieldC; // +0xC
};

class Class_002251A0
{
public:
    float sub_002251A0();
    char m_pad00[0x30];
    Obj_002251A0* m_Field30; // +0x30
};

float Class_002251A0::sub_002251A0()
{
    if (m_Field30)
        return m_Field30->m_FieldC;
    return DAT_0037CD94;
}

// ============================================================================
// [VERIFIED] pure3d::SimpleFrameController::vfunc_17 (0x002251C0, 21 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// pure3d::SimpleFrameController::vfunc_17 (Proto 0x002251C0, 21 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

namespace pure3d {

class SimpleFrameController
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
    virtual int vfunc_17(int a1, int a2);
    char m_pad04[0x1C];
    int m_Field20; // +0x20
    int m_Field24; // +0x24
};

int SimpleFrameController::vfunc_17(int a1, int a2)
{
    int t1;

    *(int*)a1 = m_Field20;
    t1 = m_Field24;
    *(int*)a2 = m_Field24;
    return t1;
}

}

// ============================================================================
// [VERIFIED] pure3d::SimpleFrameController::vfunc_21 (0x002252A0, 31 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// pure3d::SimpleFrameController::vfunc_21 (Proto 0x002252A0, 31 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

namespace pure3d {

class SimpleFrameController
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
    virtual int vfunc_21();
};

int SimpleFrameController::vfunc_21()
{
    int r_ecx, t1;

    r_ecx = (int)this;
    if (!*(int*)(r_ecx + 20)) {
        t1 = *(int*)(r_ecx + 48);
        if (!*(int*)(r_ecx + 48)) goto L_1B;
        r_ecx = 0;
        r_ecx = !*(bool*)(t1 + 20);
        return r_ecx;
    }
L_1B:
    return *(int*)(r_ecx + 24);
}

}

// ============================================================================
// [VERIFIED] pure3d::SimpleFrameController::vfunc_24 (0x002252C0, 25 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// pure3d::SimpleFrameController::vfunc_24 (Proto 0x002252C0, 25 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" float DAT_003AFAD4;

namespace pure3d {

class SimpleFrameController
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
    char m_pad04[0x18];
    float m_Field1C; // +0x1C
};

int SimpleFrameController::vfunc_24()
{
    if (m_Field1C <= DAT_003AFAD4) {
        return 1;
    }
    return 0;
}

}

