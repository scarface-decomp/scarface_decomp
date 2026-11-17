// ============================================================================
// SCARFACE: THE WORLD IS YOURS — April 2006 prototype game.xbe, core/VertexAnimController.cpp (3 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 3 of 5 functions matched (60.00%). NOT COMPLETE YET.
// The 2 still to do are listed in their place in Original_Binary_Order_Proto.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] pure3d::VertexAnimController::vfunc_28 (0x0025B130, 39 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// pure3d::VertexAnimController::vfunc_28 (Proto 0x0025B130, 39 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

namespace pure3d {

class VertexAnimController
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
    virtual bool vfunc_28(int a1);
};

bool VertexAnimController::vfunc_28(int a1)
{
    if (a1) {
        if (*(int*)(a1 + 36) <= 0) goto L_22;
        return *(int*)(a1 + 24) == 0x58545256;
    }
L_22:
    return false;
}

}

// ============================================================================
// [VERIFIED] pure3d::VertexAnimController::vfunc_05 (0x0025B210, 79 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as pure3d::VertexAnimController::vfunc_05 (0x002A6DF0), which was matched first;
// its addresses and names were swapped for this function's.
// pure3d::VertexAnimController::vfunc_05 (0x0025B210, 79 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    virtual void vfunc_00();
    virtual void vfunc_01();
    void sub_00225850(int);
};

extern "C" char DAT_003B2AB4[];
extern "C" int __cdecl sub_001FCF20(int);

namespace pure3d {

class VertexAnimController
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual int vfunc_05();
};

int VertexAnimController::vfunc_05()
{
    int r_edi, r_esi, t4;

    r_edi = (int)this;
    r_esi = sub_001FCF20(56);
    if (r_esi) {
        ((Object*)r_esi)->sub_00225850((int)this);
        *(int*)r_esi = (int)DAT_003B2AB4;
        *(int*)(r_esi + 52) = 0;
        r_edi = *(int*)(r_edi + 52);
        if (r_edi) {
            ((Object*)r_edi)->vfunc_00();
        }
        t4 = *(int*)(r_esi + 52);
        if (*(int*)(r_esi + 52)) {
            ((Object*)t4)->vfunc_01();
        }
        *(int*)(r_esi + 52) = r_edi;
        return r_esi;
    }
    return 0;
}

}

// ============================================================================
// [VERIFIED] pure3d::VertexAnimController::vfunc_07 (0x0025B2D0, 64 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// pure3d::VertexAnimController::vfunc_07 (Proto 0x0025B2D0, 64 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    virtual void vfunc_00();
    virtual void vfunc_01();
};

extern "C" char DAT_003F4548[];
extern "C" char DAT_003F7F20[];
extern "C" int __cdecl sub_002C92F8(int, int, int, int, int);

namespace pure3d {

class VertexAnimController
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
    char m_pad04[0x30];
    int m_Field34; // +0x34
};

void VertexAnimController::vfunc_07(int a1)
{
    int r_esi, t3;

    r_esi = *(int*)(sub_002C92F8(a1, 0, (int)DAT_003F4548, (int)DAT_003F7F20, 0) + 92);
    if (r_esi) {
        ((Object*)r_esi)->vfunc_00();
    }
    t3 = m_Field34;
    if (m_Field34) {
        ((Object*)t3)->vfunc_01();
    }
    m_Field34 = r_esi;
}

}

