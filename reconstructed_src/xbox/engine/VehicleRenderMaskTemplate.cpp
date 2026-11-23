// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail Xbox default.xbe, engine/VehicleRenderMaskTemplate.cpp (5 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 5 of 6 functions matched (83.33%). NOT COMPLETE YET.
// The 1 still to do are listed in their place in Original_Binary_Order_Xbox.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] VehicleRenderMaskTemplate::vfunc_00 (0x0020D460, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as CollisionBehaviourTypeGroup::vfunc_00 (0x000123B0), which was matched first;
// its addresses and names were swapped for this function's.
// VehicleRenderMaskTemplate::vfunc_00 (0x0020D460, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_004477F4[];

class VehicleRenderMaskTemplate
{
public:
    virtual void* vfunc_00();
};

void* VehicleRenderMaskTemplate::vfunc_00()
{
    return DAT_004477F4;
}

// ============================================================================
// [VERIFIED] VehicleRenderMaskTemplate::vfunc_01 (0x0020DAC0, 36 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as CollisionBehaviourTypeGroup::vfunc_01 (0x00013840), which was matched first;
// its addresses and names were swapped for this function's.
// VehicleRenderMaskTemplate::vfunc_01 (0x0020DAC0, 36 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_003CDA8C[];
extern "C" void __cdecl sub_00027600(int);
extern "C" void __cdecl sub_0020C490(void);

class VehicleRenderMaskTemplate
{
public:
    virtual void vfunc_00();
    virtual VehicleRenderMaskTemplate* vfunc_01(int a1);
};

VehicleRenderMaskTemplate* VehicleRenderMaskTemplate::vfunc_01(int a1)
{
    *(int*)this = (int)DAT_003CDA8C;
    sub_0020C490();
    if (a1 & 1) {
        sub_00027600((int)this);
    }
    return this;
}

// ============================================================================
// [VERIFIED] VehicleRenderMaskTemplate::vfunc_11 (0x0020DAF0, 22 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// VehicleRenderMaskTemplate::vfunc_11 (0x0020DAF0, 22 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

class VehicleRenderMaskTemplate
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
    char m_pad04[0x1E];
    bool m_Field22; // +0x22
    char m_pad23[0x1];
    unsigned short m_Field24; // +0x24
    char m_pad26[0x2];
    int m_Field28; // +0x28
};

void VehicleRenderMaskTemplate::vfunc_11()
{
    if (m_Field22) {
        m_Field22 = false;
        m_Field24 = 65535;
        m_Field28 = 0;
    }
}

// ============================================================================
// [VERIFIED] VehicleRenderMaskTemplate::vfunc_04 (0x0020E6F0, 57 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// bin: xb
// va: 0x0020E6F0
// what: 
// tool: the portal's starter code (no AI)

// VehicleRenderMaskTemplate::vfunc_04 (0x0020E6F0, 57 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __stdcall sub_0002B700(int);

class VehicleRenderMaskTemplate
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04(int a1);
    char m_pad04[0x1C];
    unsigned short m_Field20; // +0x20
    bool m_Field22; // +0x22
    char m_pad23[0x1];
    unsigned short m_Field24; // +0x24
    char m_pad26[0x2];
    int m_Field28; // +0x28
    char m_pad2C[0x4];
    int m_Field30; // +0x30
};

void VehicleRenderMaskTemplate::vfunc_04(int a1)
{
    int t2;

    sub_0002B700(0);
    if (m_Field22) {
        t2 = m_Field30;
        m_Field24 = 65535;
        m_Field28 = 0;
        if (!m_Field30) goto L_35;
        if (!*(unsigned char*)t2) goto L_35;
        m_Field24 = m_Field20;
        m_Field28 = t2;
    }
L_35:
    ;
}

// ============================================================================
// [VERIFIED] VehicleRenderMaskTemplate::vfunc_10 (0x0020E730, 35 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// bin: xb
// va: 0x0020E730
// what: 
// tool: the portal's starter code (no AI)

// VehicleRenderMaskTemplate::vfunc_10 (0x0020E730, 35 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

class VehicleRenderMaskTemplate
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
    char m_pad04[0x1C];
    unsigned short m_Field20; // +0x20
    bool m_Field22; // +0x22
    char m_pad23[0x1];
    unsigned short m_Field24; // +0x24
    char m_pad26[0x2];
    int m_Field28; // +0x28
    char m_pad2C[0x4];
    int m_Field30; // +0x30
};

void VehicleRenderMaskTemplate::vfunc_10()
{
    int t1;

    if (!m_Field22) {
        t1 = m_Field30;
        m_Field22 = true;
        if (!m_Field30) goto L_22;
        if (!*(unsigned char*)t1) goto L_22;
        m_Field24 = m_Field20;
        m_Field28 = t1;
    }
L_22:
    ;
}

