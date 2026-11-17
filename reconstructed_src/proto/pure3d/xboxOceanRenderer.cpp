// ============================================================================
// SCARFACE: THE WORLD IS YOURS — April 2006 prototype game.xbe, pure3d/xboxOceanRenderer.cpp (7 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 7 of 11 functions matched (63.64%). NOT COMPLETE YET.
// The 4 still to do are listed in their place in Original_Binary_Order_Proto.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] pure3d::xboxOceanRenderer::vfunc_10 (0x000A4C10, 10 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// pure3d::xboxOceanRenderer::vfunc_10 (Proto 0x000A4C10, 10 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

namespace pure3d {

class xboxOceanRenderer
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
    int m_Field04; // +0x04
};

int xboxOceanRenderer::vfunc_10(int a1)
{
    m_Field04 = a1;
    return a1;
}

}

// ============================================================================
// [VERIFIED] pure3d::xboxOceanRenderer::vfunc_03 (0x00252DF0, 27 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// pure3d::xboxOceanRenderer::vfunc_03 (Proto 0x00252DF0, 27 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

namespace pure3d {

class xboxOceanRenderer
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual int vfunc_03(int a1, int a2, int a3);
};

int xboxOceanRenderer::vfunc_03(int a1, int a2, int a3)
{
    *(int*)a3 = 0;
    *(int*)(a3 + 4) = 0x3F800000;
    *(int*)(a3 + 8) = 0;
    return a3;
}

}

// ============================================================================
// [VERIFIED] pure3d::xboxOceanRenderer::vfunc_08 (0x00253910, 13 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// pure3d::xboxOceanRenderer::vfunc_08 (Proto 0x00253910, 13 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

namespace pure3d {

class xboxOceanRenderer
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
    virtual bool vfunc_08(bool a1);
    char m_pad04[0x450];
    bool m_Field454; // +0x454
};

bool xboxOceanRenderer::vfunc_08(bool a1)
{
    m_Field454 = a1;
    return a1;
}

}

// ============================================================================
// [VERIFIED] pure3d::xboxOceanRenderer::vfunc_09 (0x00253920, 7 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// pure3d::xboxOceanRenderer::vfunc_09 (Proto 0x00253920, 7 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

namespace pure3d {

class xboxOceanRenderer
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
    virtual bool vfunc_09();
    char m_pad04[0x450];
    bool m_Field454; // +0x454
};

bool xboxOceanRenderer::vfunc_09()
{
    return m_Field454;
}

}

// ============================================================================
// [VERIFIED] pure3d::xboxOceanRenderer::vfunc_04 (0x00253C00, 104 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// pure3d::xboxOceanRenderer::vfunc_04 (Proto 0x00253C00, 104 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    virtual void vfunc_00();
    virtual void vfunc_01();
};

namespace pure3d {

class xboxOceanRenderer
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04(int a1, int a2, int a3);
    char m_pad04[0x21C];
    int m_Field220; // +0x220
    int m_Field224; // +0x224
    int m_Field228; // +0x228
};

void xboxOceanRenderer::vfunc_04(int a1, int a2, int a3)
{
    int t1, t4, t7;

    t1 = m_Field220;
    if (m_Field220) {
        ((Object*)t1)->vfunc_01();
        m_Field220 = 0;
    }
    m_Field220 = a1;
    ((Object*)a1)->vfunc_00();
    t4 = m_Field224;
    if (m_Field224) {
        ((Object*)t4)->vfunc_01();
    }
    m_Field224 = a2;
    ((Object*)a2)->vfunc_00();
    t7 = m_Field228;
    if (m_Field228) {
        ((Object*)t7)->vfunc_01();
    }
    m_Field228 = a3;
    ((Object*)a3)->vfunc_00();
}

}

// ============================================================================
// [VERIFIED] pure3d::xboxOceanRenderer::vfunc_01 (0x00253C70, 71 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// pure3d::xboxOceanRenderer::vfunc_01 (Proto 0x00253C70, 71 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0027A020();
};

extern "C" int DAT_0042CB30;
extern "C" void __cdecl sub_00252BD0(void);

namespace pure3d {

class xboxOceanRenderer
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    void sub_00252C80();
    void sub_00252E10(int);
    void sub_00253120();
    int m_Field04; // +0x04
};

void xboxOceanRenderer::vfunc_01()
{
    int r_eax, r_edi;

    sub_00252BD0();
    sub_00253120();
    r_eax = DAT_0042CB30;
    r_edi = 0;
    if (r_eax > 0) {
        do {
            sub_00252E10(r_edi);
            r_eax = m_Field04;
            ((Object*)*(int*)((int)this + (r_eax * 4) + 8))->sub_0027A020();
            r_eax = DAT_0042CB30;
            r_edi += 1;
        } while (r_edi < r_eax);
    }
    sub_00252C80();
}

}

// ============================================================================
// [VERIFIED] pure3d::xboxOceanRenderer::vfunc_00 (0x00253D10, 30 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as CollisionManager::CollisionManagerFlowClient::vfunc_00 (0x00016060), which was matched first;
// its addresses and names were swapped for this function's.
// pure3d::xboxOceanRenderer::vfunc_00 (0x00253D10, 30 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __cdecl sub_00253B50(void);
extern "C" void __cdecl sub_00025160(int);

namespace pure3d {

class xboxOceanRenderer
{
public:
    virtual xboxOceanRenderer* vfunc_00(int a1);
};

xboxOceanRenderer* xboxOceanRenderer::vfunc_00(int a1)
{
    sub_00253B50();
    if (a1 & 1) {
        sub_00025160((int)this);
    }
    return this;
}

}

