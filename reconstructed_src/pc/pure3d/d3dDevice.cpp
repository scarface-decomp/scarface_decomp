// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail PC Scarface.exe v1.00.2, pure3d/d3dDevice.cpp (6 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 6 of 10 functions matched (60.00%). NOT COMPLETE YET.
// The 4 still to do are listed in their place in Original_Binary_Order_PC_1002.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

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

