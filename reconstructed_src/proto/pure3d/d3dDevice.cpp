// ============================================================================
// SCARFACE: THE WORLD IS YOURS — April 2006 prototype game.xbe, pure3d/d3dDevice.cpp (5 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 5 of 8 functions matched (62.50%). NOT COMPLETE YET.
// The 3 still to do are listed in their place in Original_Binary_Order_Proto.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] pure3d::d3dDevice::vfunc_05 (0x0024EC50, 10 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// pure3d::d3dDevice::vfunc_05 (Proto 0x0024EC50, 10 bytes)
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
// [VERIFIED] pure3d::d3dDevice::vfunc_07 (0x0024EC60, 41 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// pure3d::d3dDevice::vfunc_07 (Proto 0x0024EC60, 41 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    int sub_0025E440(int);
};

extern "C" int __cdecl sub_00025120(int);

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
    virtual int vfunc_07(int a1);
    char m_pad04[0xC];
    int m_Field10; // +0x10
};

int d3dDevice::vfunc_07(int a1)
{
    int t1;

    t1 = sub_00025120(1208);
    if (t1) {
        a1 = m_Field10;
        return ((Object*)t1)->sub_0025E440(a1);
    }
    return 0;
}

}

// ============================================================================
// [VERIFIED] pure3d::d3dDevice::vfunc_10 (0x0024ED90, 107 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// pure3d::d3dDevice::vfunc_10 (Proto 0x0024ED90, 107 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual int vfunc_02();
    virtual void vfunc_03(int);
    int sub_00270360(int);
    void sub_00270410(int, int, int, int, int, int);
};

extern "C" int __cdecl sub_00025120(int);

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

    t1 = sub_00025120(64);
    if (t1) {
        r_esi = ((Object*)t1)->sub_00270360(m_Field0C);
    } else {
        r_esi = 0;
    }
    ((Object*)r_esi)->sub_00270410(*(char*)(a1 + 68), *(int*)(a1 + 48), 0, *(int*)(a1 + 52), *(int*)(a1 + 56), *(int*)(a1 + 60));
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
// [VERIFIED] pure3d::d3dDevice::vfunc_11 (0x0024EE00, 22 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// pure3d::d3dDevice::vfunc_11 (Proto 0x0024EE00, 22 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __cdecl sub_0025DD00(int, int, int);

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
    sub_0025DD00(m_Field0C, a1, 0);
}

}

// ============================================================================
// [VERIFIED] pure3d::d3dDevice::vfunc_03 (0x0024EE50, 46 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// pure3d::d3dDevice::vfunc_03 (Proto 0x0024EE50, 46 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_003B1D88[];
extern "C" int DAT_0048E038;
extern "C" void __cdecl sub_00025160(int);
extern "C" void __cdecl sub_00264490(void);

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
    DAT_0048E038 = 0;
    *(int*)this = (int)DAT_003B1D88;
    sub_00264490();
    if (a1 & 1) {
        sub_00025160((int)this);
    }
    return this;
}

}

