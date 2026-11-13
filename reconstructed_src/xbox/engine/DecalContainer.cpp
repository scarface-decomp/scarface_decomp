// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail Xbox default.xbe, engine/DecalContainer.cpp (4 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 4 of 14 functions matched (28.57%). NOT COMPLETE YET.
// The 10 still to do are listed in their place in Original_Binary_Order_Xbox.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] renderer::DecalContainer::vfunc_21 (0x000518E0, 7 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// renderer::DecalContainer::vfunc_21 (0x000518E0, 7 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" float DAT_0039D664;

namespace renderer {

class DecalContainer
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
    virtual void vfunc_15();
    virtual void vfunc_16();
    virtual void vfunc_17();
    virtual void vfunc_18();
    virtual void vfunc_19();
    virtual void vfunc_20();
    virtual float vfunc_21();
};

float DecalContainer::vfunc_21()
{
    return DAT_0039D664;
}

}

// ============================================================================
// [VERIFIED] renderer::DecalContainer::vfunc_03 (0x000523B0, 36 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as LOSManager::LOSManagerFlowClient::vfunc_00 (0x000179C0), which was matched first;
// its addresses and names were swapped for this function's.
// renderer::DecalContainer::vfunc_03 (0x000523B0, 36 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_003A07DC[];
extern "C" void __cdecl sub_0023F7A0(int);
extern "C" void __cdecl sub_0025AFE0(void);

namespace renderer {

class DecalContainer
{
public:
    virtual DecalContainer* vfunc_03(int a1);
};

DecalContainer* DecalContainer::vfunc_03(int a1)
{
    *(int*)this = (int)DAT_003A07DC;
    sub_0025AFE0();
    if (a1 & 1) {
        sub_0023F7A0((int)this);
    }
    return this;
}

}

// ============================================================================
// [VERIFIED] renderer::DecalContainer::vfunc_23 (0x0025A490, 28 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// renderer::DecalContainer::vfunc_23 (0x0025A490, 28 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.
#pragma optimize("y", off)

struct Object
{
    int sub_00022710(int);
};

namespace renderer {

class DecalContainer
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
    virtual void vfunc_15();
    virtual void vfunc_16();
    virtual void vfunc_17();
    virtual void vfunc_18();
    virtual void vfunc_19();
    virtual void vfunc_20();
    virtual void vfunc_21();
    virtual void vfunc_22();
    virtual int vfunc_23(int a1);
};

int DecalContainer::vfunc_23(int a1)
{
    int r_eax;

    r_eax = (int)this;
    if (a1) {
        if (!(*(int*)(r_eax + 56) & 1)) goto L_18;
        r_eax = ((Object*)a1)->sub_00022710((int)this);
    }
L_18:
    return r_eax;
}

}

// ============================================================================
// [VERIFIED] renderer::DecalContainer::vfunc_15 (0x00280700, 41 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// renderer::DecalContainer::vfunc_15 (0x00280700, 41 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.
#pragma optimize("y", off)

struct Object
{
    virtual void vfunc_00();
    virtual void vfunc_01();
};

namespace renderer {

class DecalContainer
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
    virtual void vfunc_15(int a1);
    char m_pad04[0x8];
    int m_Field0C; // +0x0C
};

void DecalContainer::vfunc_15(int a1)
{
    int r_edi, t2;

    r_edi = a1;
    if (a1) {
        ((Object*)r_edi)->vfunc_00();
    }
    t2 = m_Field0C;
    if (m_Field0C) {
        ((Object*)t2)->vfunc_01();
    }
    m_Field0C = r_edi;
}

}

