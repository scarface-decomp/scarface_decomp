// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail Xbox default.xbe, engine/Scene.cpp (2 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 2 of 5 functions matched (40.00%). NOT COMPLETE YET.
// The 3 still to do are listed in their place in Original_Binary_Order_Xbox.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] renderer::Scene::vfunc_04 (0x0004D700, 79 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// bin: xb
// va: 0x0004D700
// what: 
// tool: the portal's starter code (no AI)

// renderer::Scene::vfunc_04 (0x0004D700, 79 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

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
    virtual void vfunc_09(int);
};

namespace renderer {

class Scene
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04(int a1);
    int m_Field04; // +0x04
    int m_Field08; // +0x08
    char m_pad0C[0x4];
    bool m_Field10; // +0x10
    char m_pad11[0x7];
    int m_Field18; // +0x18
};

void Scene::vfunc_04(int a1)
{
    int r_ebp, r_ebx, r_esi, t1;

    if (!m_Field10) goto L_4B;
    r_esi = m_Field08;
    r_esi -= m_Field04;
    r_esi >>= 2;
    r_ebp = 0;
    if (r_esi <= 0) goto L_49;
    r_ebx = a1;
L_22:
    t1 = *(int*)(m_Field04 + (r_ebp * 4));
    if (*(int*)(m_Field04 + (r_ebp * 4))) {
        if (!(*(unsigned char*)(t1 + 128) & 16)) goto L_43;
        if (!(m_Field18 & *(int*)(t1 + 84))) goto L_43;
        ((Object*)t1)->vfunc_09(r_ebx);
    }
L_43:
    r_ebp += 1;
    if (r_ebp < r_esi) goto L_22;
L_49:
L_4B:
    ;
}

}

// ============================================================================
// [VERIFIED] renderer::Scene::vfunc_00 (0x0004D9C0, 30 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as CollisionManager::CollisionManagerFlowClient::vfunc_00 (0x00016060), which was matched first;
// its addresses and names were swapped for this function's.
// renderer::Scene::vfunc_00 (0x0004D9C0, 30 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __cdecl sub_0004D900(void);
extern "C" void __cdecl sub_00027600(int);

namespace renderer {

class Scene
{
public:
    virtual Scene* vfunc_00(int a1);
};

Scene* Scene::vfunc_00(int a1)
{
    sub_0004D900();
    if (a1 & 1) {
        sub_00027600((int)this);
    }
    return this;
}

}

