// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail Xbox default.xbe, core/PoseAnimationController.cpp (5 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 5 of 8 functions matched (62.50%). NOT COMPLETE YET.
// The 3 still to do are listed in their place in Original_Binary_Order_Xbox.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] pure3d::PoseAnimationController::vfunc_09 (0x002863F0, 5 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as pure3d::PoseAnimationController::vfunc_09 (Proto 0x0012D8D0), which was matched first;
// its addresses and names were swapped for this function's.
// pure3d::PoseAnimationController::vfunc_09 (Proto 0x002863F0, 5 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

namespace pure3d {

class PoseAnimationController
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
};

void PoseAnimationController::vfunc_09()
{
    vfunc_29();
}

}

// ============================================================================
// [VERIFIED] pure3d::PoseAnimationController::vfunc_14 (0x00286400, 9 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as pure3d::d3dExtAntialiasControl::vfunc_03 (0x00267E90), which was matched first;
// its addresses and names were swapped for this function's.
// bin: xb
// va: 0x00286400
// what: 
// tool: the portal's starter code (no AI)

// pure3d::PoseAnimationController::vfunc_14 (0x00286400, 9 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.
// This function keeps a frame pointer (push ebp; mov ebp, esp), so it is built with them on.
#pragma optimize("y", off)

extern "C" void __stdcall sub_00273C80(int);

namespace pure3d {

class PoseAnimationController
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
    virtual void vfunc_14(int a1);
};

void PoseAnimationController::vfunc_14(int a1)
{
    sub_00273C80(a1);
}

}

// ============================================================================
// [VERIFIED] pure3d::PoseAnimationController::vfunc_26 (0x00286CC0, 44 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// pure3d::PoseAnimationController::vfunc_26 (0x00286CC0, 44 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.
#pragma optimize("y", off)

namespace pure3d {

class PoseAnimationController
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
    virtual int vfunc_26(int a1, int a2, int a3);
    void sub_00273C10(int, int, int);
    int sub_00286520();
    char m_pad04[0x30];
    int m_Field34; // +0x34
};

int PoseAnimationController::vfunc_26(int a1, int a2, int a3)
{
    int r_eax;

    r_eax = a3;
    sub_00273C10(a1, a2, a3);
    r_eax = m_Field34;
    if (r_eax) {
        r_eax = sub_00286520();
    }
    return r_eax;
}

}

// ============================================================================
// [VERIFIED] pure3d::PoseAnimationController::vfunc_05 (0x00286F70, 69 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as pure3d::PoseAnimationController::vfunc_05 (Proto 0x002431B0), which was matched first;
// its addresses and names were swapped for this function's.
// pure3d::PoseAnimationController::vfunc_05 (Proto 0x00286F70, 69 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_00273B50(int);
    void sub_00286CF0(int);
};

extern "C" char DAT_003D8184[];
extern "C" int __cdecl sub_0023F760(int);

namespace pure3d {

class PoseAnimationController
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual int vfunc_05();
    char m_pad04[0x30];
    int m_Field34; // +0x34
};

int PoseAnimationController::vfunc_05()
{
    int t1;

    t1 = sub_0023F760(60);
    if (t1) {
        ((Object*)t1)->sub_00273B50((int)this);
        *(int*)t1 = (int)DAT_003D8184;
        *(int*)(t1 + 52) = 0;
        *(int*)(t1 + 56) = 0;
        ((Object*)t1)->sub_00286CF0(m_Field34);
        return t1;
    }
    return 0;
}

}

// ============================================================================
// [VERIFIED] pure3d::PoseAnimationController::vfunc_07 (0x00286FC0, 95 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// bin: xb
// va: 0x00286FC0
// what: 
// tool: the portal's starter code (no AI)

// pure3d::PoseAnimationController::vfunc_07 (0x00286FC0, 95 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.
// This function keeps a frame pointer (push ebp; mov ebp, esp), so it is built with them on.
#pragma optimize("y", off)

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
    virtual int vfunc_13();
};

extern "C" char DAT_00419538[];
extern "C" char DAT_0041CF34[];
extern "C" char DAT_0045AC18[];
extern "C" int __cdecl sub_002FC034(int, int, int, int, int);

namespace pure3d {

class PoseAnimationController
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
    void sub_00286CF0(int);
};

void PoseAnimationController::vfunc_07(int a1)
{
    int r_edi, t1;

    r_edi = a1;
    t1 = sub_002FC034(a1, 0, (int)DAT_00419538, (int)DAT_0041CF34, 0);
    if (t1) {
        sub_00286CF0(((Object*)t1)->vfunc_13());
        return;
    }
    sub_00286CF0(sub_002FC034(r_edi, 0, (int)DAT_00419538, (int)DAT_0045AC18, 0));
}

}

