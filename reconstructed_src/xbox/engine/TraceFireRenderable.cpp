// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail Xbox default.xbe, engine/TraceFireRenderable.cpp (2 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 2 of 3 functions matched (66.67%). NOT COMPLETE YET.
// The 1 still to do are listed in their place in Original_Binary_Order_Xbox.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] renderer::TraceFireRenderable::vfunc_09 (0x0005D0D0, 94 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 /arch:SSE
// ============================================================================
// bin: xb
// va: 0x0005D0D0
// what: 
// tool: the portal's starter code (no AI)

// renderer::TraceFireRenderable::vfunc_09 (0x0005D0D0, 94 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" float DAT_0039D664;
extern "C" float DAT_0041DB40;

namespace renderer {

class TraceFireRenderable
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
    virtual void vfunc_09(int a1);
    char m_pad04[0x80];
    int m_Field84; // +0x84
    int m_Field88; // +0x88
};

void TraceFireRenderable::vfunc_09(int a1)
{
    int r_edi, r_edx, r_esi, t3, t6;
    float t1, t2;

    r_esi = 0;
    if (m_Field88 <= 0) goto L_5A;
    t1 = DAT_0041DB40;
    t2 = DAT_0039D664;
    r_edi = a1;
    r_edx = 0;
L_24:
    t3 = m_Field84 + r_edx;
    if (t2 > *(float*)(m_Field84 + r_edx)) {
        if (*(float*)t3 >= t2) goto L_4B;
        *(float*)t3 = (*(float*)(r_edi + 8) / t1) + *(float*)t3;
    }
L_4B:
    t6 = m_Field88;
    r_esi += 1;
    r_edx += 76;
    if (r_esi < t6) goto L_24;
L_5A:
    ;
}

}

// ============================================================================
// [VERIFIED] renderer::TraceFireRenderable::vfunc_03 (0x0005D1B0, 30 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// What it does: renderer::TraceFireRenderable's deleting destructor: destroys the object, frees its memory when asked (flag bit 0), and returns it.
// ============================================================================
// Same machine code as CollisionManager::CollisionManagerFlowClient::vfunc_00 (0x00016060), which was matched first;
// its addresses and names were swapped for this function's.
// renderer::TraceFireRenderable::vfunc_03 (0x0005D1B0, 30 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __cdecl sub_0005D070(void);
extern "C" void __cdecl sub_0023F7A0(int);

namespace renderer {

class TraceFireRenderable
{
public:
    virtual TraceFireRenderable* vfunc_03(int a1);
};

TraceFireRenderable* TraceFireRenderable::vfunc_03(int a1)
{
    sub_0005D070();
    if (a1 & 1) {
        sub_0023F7A0((int)this);
    }
    return this;
}

}

