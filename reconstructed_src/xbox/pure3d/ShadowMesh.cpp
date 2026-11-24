// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail Xbox default.xbe, pure3d/ShadowMesh.cpp (4 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: COMPLETE. All 4 functions are matched.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] pure3d::ShadowMesh::vfunc_05 (0x00292630, 55 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// pure3d::ShadowMesh::vfunc_05 (0x00292630, 55 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0025AE10(int);
};

extern "C" char DAT_003D8BF4[];
extern "C" int __cdecl sub_0023F760(int);

namespace pure3d {

class ShadowMesh
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual int vfunc_05();
};

int ShadowMesh::vfunc_05()
{
    int t1;

    t1 = sub_0023F760(88);
    if (t1) {
        ((Object*)t1)->sub_0025AE10((int)this);
        *(bool*)(t1 + 80) = false;
        *(int*)(t1 + 84) = 0;
        *(int*)t1 = (int)DAT_003D8BF4;
        return t1;
    }
    return 0;
}

}

// ============================================================================
// [VERIFIED] pure3d::ShadowMesh::vfunc_31 (0x00292740, 38 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// pure3d::ShadowMesh::vfunc_31 (0x00292740, 38 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.
#pragma optimize("y", off)

namespace pure3d {

class ShadowMesh
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
    virtual int vfunc_31(bool a1, int a2);
    char m_pad04[0x40];
    int m_Field44; // +0x44
};

int ShadowMesh::vfunc_31(bool a1, int a2)
{
    int t1;

    t1 = *(int*)m_Field44;
    *(bool*)(*(int*)m_Field44 + 76) = a1;
    *(int*)(t1 + 92) = *(int*)a2;
    *(int*)(t1 + 96) = *(int*)(a2 + 4);
    *(int*)(t1 + 100) = *(int*)(a2 + 8);
    return t1;
}

}

// ============================================================================
// [VERIFIED] pure3d::ShadowMesh::vfunc_34 (0x00292770, 18 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// pure3d::ShadowMesh::vfunc_34 (0x00292770, 18 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.
#pragma optimize("y", off)

namespace pure3d {

class ShadowMesh
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
    virtual int vfunc_34(int a1);
    char m_pad04[0x40];
    int m_Field44; // +0x44
};

int ShadowMesh::vfunc_34(int a1)
{
    int t1;

    t1 = m_Field44;
    *(int*)(*(int*)m_Field44 + 72) = a1;
    return t1;
}

}

// ============================================================================
// [VERIFIED] pure3d::ShadowMesh::vfunc_30 (0x002927A0, 14 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// What it does: Forwards two parameters to sub_001E0B70 on the object doubly referenced at +0x44.
// ============================================================================
// bin: xb
// va: 0x002927A0
// what: Forwards two parameters to sub_001E0B70 on the object doubly referenced at +0x44.
// tool: Gemini 4 Neon

#pragma optimize("y", off)

struct Object_002927A0
{
    void sub_001E0B70(int a1, int a2);
};

namespace pure3d {

class ShadowMesh
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
    virtual void vfunc_30(int a1, int a2);
    char m_pad04[0x40];
    int m_Field44; // +0x44
};

void ShadowMesh::vfunc_30(int a1, int a2)
{
    ((Object_002927A0*)*(int*)m_Field44)->sub_001E0B70(a1, a2);
}

}

