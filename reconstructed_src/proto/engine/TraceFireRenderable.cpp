// ============================================================================
// SCARFACE: THE WORLD IS YOURS — April 2006 prototype game.xbe, engine/TraceFireRenderable.cpp (2 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 2 of 3 functions matched (66.67%). NOT COMPLETE YET.
// The 1 still to do are listed in their place in Original_Binary_Order_Proto.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] renderer::TraceFireRenderable::vfunc_03 (0x00052C90, 30 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as CollisionManager::CollisionManagerFlowClient::vfunc_00 (0x00016060), which was matched first;
// its addresses and names were swapped for this function's.
// renderer::TraceFireRenderable::vfunc_03 (0x00052C90, 30 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __cdecl sub_00052970(void);
extern "C" void __cdecl sub_001FCF60(int);

namespace renderer {

class TraceFireRenderable
{
public:
    virtual TraceFireRenderable* vfunc_03(int a1);
};

TraceFireRenderable* TraceFireRenderable::vfunc_03(int a1)
{
    sub_00052970();
    if (a1 & 1) {
        sub_001FCF60((int)this);
    }
    return this;
}

}

// ============================================================================
// [VERIFIED] renderer::TraceFireRenderable::vfunc_09 (0x00053030, 84 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 /arch:SSE
// ============================================================================
// bin: proto
// va: 0x00053030
// what: 
// tool: the portal's starter code (no AI)

// renderer::TraceFireRenderable::vfunc_09 (Proto 0x00053030, 84 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" float DAT_0037CE50;

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
    void sub_00052E50(int, int);
    char m_pad04[0x7C];
    int m_Field80; // +0x80
    int m_Field84; // +0x84
};

void TraceFireRenderable::vfunc_09(int a1)
{
    int r_ebp, r_ebx, r_edi, t2, t4;
    float t1;

    r_ebx = 0;
    if (m_Field84 > 0) {
        r_ebp = a1;
        r_edi = 0;
        do {
            t1 = DAT_0037CE50;
            t2 = m_Field80 + r_edi;
            if (t1 > *(float*)(m_Field80 + r_edi + 40)) {
                sub_00052E50(t2, r_ebp);
            }
            t4 = m_Field84;
            r_ebx += 1;
            r_edi += 116;
        } while (r_ebx < t4);
    }
}

}

