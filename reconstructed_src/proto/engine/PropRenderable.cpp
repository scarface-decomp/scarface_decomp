// ============================================================================
// SCARFACE: THE WORLD IS YOURS — April 2006 prototype game.xbe, engine/PropRenderable.cpp (3 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: COMPLETE. All 3 functions are matched.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] renderer::PropRenderable::vfunc_09 (0x0004D280, 31 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as renderer::PropRenderable::vfunc_09 (0x00055D10), which was matched first;
// its addresses and names were swapped for this function's.
// renderer::PropRenderable::vfunc_09 (0x0004D280, 31 bytes)
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
    virtual void vfunc_08(int, int);
};

extern "C" int __stdcall sub_0004EEB0(int);

namespace renderer {

class PropRenderable
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
};

void PropRenderable::vfunc_09(int a1)
{
    int t1;

    t1 = sub_0004EEB0(0);
    if (t1) {
        ((Object*)t1)->vfunc_08(*(int*)(a1 + 8), 0);
    }
}

}

// ============================================================================
// [VERIFIED] renderer::PropRenderable::vfunc_15 (0x0004D330, 39 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// renderer::PropRenderable::vfunc_15 (Proto 0x0004D330, 39 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

namespace renderer {

class PropRenderable
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
    virtual bool vfunc_15(int a1);
    char m_pad04[0x7C];
    int m_Field80; // +0x80
    int m_Field84; // +0x84
    int m_Field88; // +0x88
    bool m_Field8C; // +0x8C
};

bool PropRenderable::vfunc_15(int a1)
{
    *(int*)a1 = m_Field80;
    *(int*)(a1 + 4) = m_Field84;
    *(int*)(a1 + 8) = m_Field88;
    return m_Field8C;
}

}

// ============================================================================
// [VERIFIED] renderer::PropRenderable::vfunc_03 (0x0004D5B0, 75 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// renderer::PropRenderable::vfunc_03 (Proto 0x0004D5B0, 75 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_00048B30(int);
};

extern "C" char DAT_0038004C[];
extern "C" int DAT_0044A368;
extern "C" int DAT_0044A54C;
extern "C" int __stdcall sub_0004EEB0(int);
extern "C" void __cdecl sub_001FCF60(int);

namespace renderer {

class PropRenderable
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual PropRenderable* vfunc_03(int a1);
    void sub_0004F610();
};

PropRenderable* PropRenderable::vfunc_03(int a1)
{
    int t1;

    *(int*)this = (int)DAT_0038004C;
    t1 = sub_0004EEB0(0);
    if (t1) {
        if (*(int*)(t1 + 8) != DAT_0044A54C) goto L_2E;
        ((Object*)*(int*)(DAT_0044A368 + 44))->sub_00048B30((int)this);
    }
L_2E:
    sub_0004F610();
    if (a1 & 1) {
        sub_001FCF60((int)this);
    }
    return this;
}

}

