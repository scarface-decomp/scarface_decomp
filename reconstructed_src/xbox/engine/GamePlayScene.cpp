// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail Xbox default.xbe, engine/GamePlayScene.cpp (2 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 2 of 6 functions matched (33.33%). NOT COMPLETE YET.
// The 4 still to do are listed in their place in Original_Binary_Order_Xbox.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] renderer::GamePlayScene::vfunc_03 (0x0004D5B0, 16 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as renderer::GamePlayScene::vfunc_03 (Proto 0x00045F00), which was matched first;
// its addresses and names were swapped for this function's.
// bin: proto
// va: 0x0004D5B0
// what: 
// tool: the portal's starter code (no AI)

// renderer::GamePlayScene::vfunc_03 (Proto 0x0004D5B0, 16 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field20
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
};

namespace renderer {

class GamePlayScene
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    char m_pad04[0xC];
    bool m_Field10; // +0x10
    char m_pad11[0xF];
    Field20* m_Field20; // +0x20
};

void GamePlayScene::vfunc_03()
{
    if (m_Field10) {
        m_Field20->vfunc_09();
        return;
    }
}

}

// ============================================================================
// [VERIFIED] renderer::GamePlayScene::vfunc_04 (0x0004D7F0, 111 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// bin: xb
// va: 0x0004D7F0
// what: 
// tool: the portal's starter code (no AI)

// renderer::GamePlayScene::vfunc_04 (0x0004D7F0, 111 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field20
{
    void sub_00043340(int);
};

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
    virtual void vfunc_10();
    void sub_00058990(int);
};

namespace renderer {

class GamePlayScene
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
    char m_pad1C[0x4];
    Field20* m_Field20; // +0x20
};

void GamePlayScene::vfunc_04(int a1)
{
    int r_ebp, r_ebx, r_edi, t2;

    if (!m_Field10) goto L_6B;
    r_ebx = a1;
    r_ebp = m_Field08;
    r_ebp -= m_Field04;
    r_ebp >>= 2;
    r_edi = 0;
    if (r_ebp <= 0) goto L_5F;
L_22:
    if (*(int*)(m_Field04 + (r_edi * 4))) {
        ((Object*)*(int*)(m_Field04 + (r_edi * 4)))->sub_00058990(r_ebx);
        t2 = *(int*)(m_Field04 + (r_edi * 4));
        if (!(*(unsigned char*)(*(int*)(m_Field04 + (r_edi * 4)) + 128) & 16)) goto L_5A;
        if (!(m_Field18 & *(int*)(t2 + 84))) goto L_5A;
        ((Object*)t2)->vfunc_09(r_ebx);
        ((Object*)*(int*)(m_Field04 + (r_edi * 4)))->vfunc_10();
    }
L_5A:
    r_edi += 1;
    if (r_edi < r_ebp) goto L_22;
L_5F:
    m_Field20->sub_00043340(r_ebx);
L_6B:
    ;
}

}

