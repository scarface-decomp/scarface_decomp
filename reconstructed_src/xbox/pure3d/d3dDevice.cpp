// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail Xbox default.xbe, pure3d/d3dDevice.cpp (4 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 4 of 8 functions matched (50.00%). NOT COMPLETE YET.
// The 4 still to do are listed in their place in Original_Binary_Order_Xbox.cpp as "// [TODO] address name (size)"
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
// [VERIFIED] pure3d::d3dDevice::vfunc_10 (0x00292460, 111 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// bin: xb
// va: 0x00292460
// what: 
// tool: the portal's starter code (no AI)

// pure3d::d3dDevice::vfunc_10 (0x00292460, 111 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.
// This function keeps a frame pointer (push ebp; mov ebp, esp), so it is built with them on.
#pragma optimize("y", off)

struct Object
{
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual int vfunc_02();
    virtual void vfunc_03(int);
    int sub_002ADC50(int);
    void sub_002ADD10(int, int, int, int, int, int);
};

extern "C" int __cdecl sub_00027590(int);

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
    virtual int vfunc_10(int a1);
    char m_pad04[0x4];
    int m_Field08; // +0x08
    int m_Field0C; // +0x0C
};

int d3dDevice::vfunc_10(int a1)
{
    int r_esi, t1, t5;

    t1 = sub_00027590(64);
    if (t1) {
        r_esi = ((Object*)t1)->sub_002ADC50(m_Field0C);
    } else {
        r_esi = 0;
    }
    ((Object*)r_esi)->sub_002ADD10(*(char*)(a1 + 68), *(int*)(a1 + 48), 0, *(int*)(a1 + 52), *(int*)(a1 + 56), *(int*)(a1 + 60));
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

