// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail Xbox default.xbe, engine/WorldGeoRenderable.cpp (3 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 3 of 5 functions matched (60.00%). NOT COMPLETE YET.
// The 2 still to do are listed in their place in Original_Binary_Order_Xbox.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] renderer::WorldGeoRenderable::vfunc_14 (0x00055D30, 56 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// renderer::WorldGeoRenderable::vfunc_14 (0x00055D30, 56 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_000401E0();
};

namespace renderer {

class WorldGeoRenderable
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
    void sub_00058580();
    char m_pad04[0x90];
    int m_Field94; // +0x94
    char m_pad98[0x4];
    int m_Field9C; // +0x9C
};

void WorldGeoRenderable::vfunc_14()
{
    int r_eax, r_ebx, r_edi;

    r_eax = m_Field9C;
    r_edi = 0;
    if (r_eax > 0) {
        r_ebx = 0;
        do {
            ((Object*)m_Field94 + r_ebx)->sub_000401E0();
            r_eax = m_Field9C;
            r_edi += 1;
            r_ebx += 32;
        } while (r_edi < r_eax);
    }
    sub_00058580();
}

}

// ============================================================================
// [VERIFIED] renderer::WorldGeoRenderable::vfunc_08 (0x00055D90, 67 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// renderer::WorldGeoRenderable::vfunc_08 (0x00055D90, 67 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_00040200(int);
};

extern "C" void __stdcall sub_00058520(int);

namespace renderer {

class WorldGeoRenderable
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
    virtual int vfunc_08(int a1);
    char m_pad04[0x90];
    int m_Field94; // +0x94
    char m_pad98[0x4];
    int m_Field9C; // +0x9C
};

int WorldGeoRenderable::vfunc_08(int a1)
{
    int r_eax, r_ebx, r_edi;

    sub_00058520(a1);
    r_eax = m_Field9C;
    r_edi = 0;
    if (r_eax > 0) {
        r_ebx = 0;
        do {
            ((Object*)m_Field94 + r_ebx)->sub_00040200(a1);
            r_eax = m_Field9C;
            r_edi += 1;
            r_ebx += 32;
        } while (r_edi < r_eax);
    }
    return r_eax;
}

}

// ============================================================================
// [VERIFIED] renderer::WorldGeoRenderable::vfunc_03 (0x00056200, 30 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as CollisionManager::CollisionManagerFlowClient::vfunc_00 (0x00016060), which was matched first;
// its addresses and names were swapped for this function's.
// renderer::WorldGeoRenderable::vfunc_03 (0x00056200, 30 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __cdecl sub_00055EB0(void);
extern "C" void __cdecl sub_0023F7A0(int);

namespace renderer {

class WorldGeoRenderable
{
public:
    virtual WorldGeoRenderable* vfunc_03(int a1);
};

WorldGeoRenderable* WorldGeoRenderable::vfunc_03(int a1)
{
    sub_00055EB0();
    if (a1 & 1) {
        sub_0023F7A0((int)this);
    }
    return this;
}

}

