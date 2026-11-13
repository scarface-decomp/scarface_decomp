// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail Xbox default.xbe, pure3d/d3dDevice.cpp (3 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 3 of 8 functions matched (37.50%). NOT COMPLETE YET.
// The 5 still to do are listed in their place in Original_Binary_Order_Xbox.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] pure3d::d3dDevice::vfunc_05 (0x0025D0D0, 13 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// pure3d::d3dDevice::vfunc_05 (0x0025D0D0, 13 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.
#pragma optimize("y", off)

namespace pure3d {

class d3dDevice
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual int vfunc_05(int a1);
    char m_pad04[0x8];
    int m_Field0C; // +0x0C
};

int d3dDevice::vfunc_05(int a1)
{
    m_Field0C = a1;
    return a1;
}

}

// ============================================================================
// [VERIFIED] pure3d::d3dDevice::vfunc_11 (0x002924D0, 25 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// pure3d::d3dDevice::vfunc_11 (0x002924D0, 25 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.
#pragma optimize("y", off)

extern "C" void __cdecl sub_0029A7C0(int, int, int);

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
    virtual void vfunc_11(int a1, int a2);
    char m_pad04[0x8];
    int m_Field0C; // +0x0C
};

void d3dDevice::vfunc_11(int a1, int a2)
{
    sub_0029A7C0(m_Field0C, a1, 0);
}

}

// ============================================================================
// [VERIFIED] pure3d::d3dDevice::vfunc_03 (0x00292520, 49 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// pure3d::d3dDevice::vfunc_03 (0x00292520, 49 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.
#pragma optimize("y", off)

extern "C" char DAT_003D8AD0[];
extern "C" int DAT_004BD3E8;
extern "C" void __cdecl sub_00027600(int);
extern "C" void __cdecl sub_002A06C0(void);

namespace pure3d {

class d3dDevice
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual d3dDevice* vfunc_03(int a1);
};

d3dDevice* d3dDevice::vfunc_03(int a1)
{
    DAT_004BD3E8 = 0;
    *(int*)this = (int)DAT_003D8AD0;
    sub_002A06C0();
    if (a1 & 1) {
        sub_00027600((int)this);
    }
    return this;
}

}

