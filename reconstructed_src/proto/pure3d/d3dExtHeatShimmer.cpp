// ============================================================================
// SCARFACE: THE WORLD IS YOURS — April 2006 prototype game.xbe, pure3d/d3dExtHeatShimmer.cpp (3 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 3 of 4 functions matched (75.00%). NOT COMPLETE YET.
// The 1 still to do are listed in their place in Original_Binary_Order_Proto.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] pure3d::d3dExtHeatShimmer::vfunc_03 (0x00266B40, 43 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// pure3d::d3dExtHeatShimmer::vfunc_03 (Proto 0x00266B40, 43 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __stdcall sub_003174B0(int);
extern "C" void __stdcall sub_003174F0(int);

namespace pure3d {

class d3dExtHeatShimmer
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03(int a1);
    char m_pad04[0x18];
    int m_Field1C; // +0x1C
};

void d3dExtHeatShimmer::vfunc_03(int a1)
{
    int r_ecx, t1, t3;

    r_ecx = (int)this;
    t1 = m_Field1C;
    if (m_Field1C) {
        sub_003174F0(t1);
        m_Field1C = 0;
    }
    t3 = *(int*)(a1 + 20);
    m_Field1C = *(int*)(a1 + 20);
    a1 = t3;
    sub_003174B0(a1);
}

}

// ============================================================================
// [VERIFIED] pure3d::d3dExtHeatShimmer::vfunc_00 (0x00266B70, 30 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as CollisionManager::CollisionManagerFlowClient::vfunc_00 (0x00016060), which was matched first;
// its addresses and names were swapped for this function's.
// pure3d::d3dExtHeatShimmer::vfunc_00 (0x00266B70, 30 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __cdecl sub_00266670(void);
extern "C" void __cdecl sub_00025160(int);

namespace pure3d {

class d3dExtHeatShimmer
{
public:
    virtual d3dExtHeatShimmer* vfunc_00(int a1);
};

d3dExtHeatShimmer* d3dExtHeatShimmer::vfunc_00(int a1)
{
    sub_00266670();
    if (a1 & 1) {
        sub_00025160((int)this);
    }
    return this;
}

}

// ============================================================================
// [VERIFIED] pure3d::d3dExtHeatShimmer::vfunc_01 (0x00267740, 87 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// pure3d::d3dExtHeatShimmer::vfunc_01 (Proto 0x00267740, 87 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct FieldC0
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
    virtual void vfunc_26(int);
};

namespace pure3d {

class d3dExtHeatShimmer
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01(int a1);
    virtual void vfunc_02(int);
    void sub_002668E0();
    void sub_002669B0();
    void sub_00266B90();
    void sub_00266EF0();
    void sub_002674C0(int);
    char m_pad04[0x75];
    bool m_Field79; // +0x79
    char m_pad7A[0x46];
    FieldC0* m_FieldC0; // +0xC0
};

void d3dExtHeatShimmer::vfunc_01(int a1)
{
    if (!m_Field79) {
        vfunc_02(0);
    }
    sub_002674C0(a1);
    sub_002668E0();
    m_FieldC0->vfunc_26(2);
    sub_00266B90();
    sub_00266EF0();
    m_FieldC0->vfunc_26(0);
    sub_002669B0();
}

}

