// ============================================================================
// SCARFACE: THE WORLD IS YOURS — April 2006 prototype game.xbe, engine/VehicleRenderMaskTemplate.cpp (5 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 5 of 6 functions matched (83.33%). NOT COMPLETE YET.
// The 1 still to do are listed in their place in Original_Binary_Order_Proto.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] VehicleRenderMaskTemplate::vfunc_00 (0x001D21F0, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as CollisionBehaviourTypeGroup::vfunc_00 (0x000123B0), which was matched first;
// its addresses and names were swapped for this function's.
// VehicleRenderMaskTemplate::vfunc_00 (0x001D21F0, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_00421194[];

class VehicleRenderMaskTemplate
{
public:
    virtual void* vfunc_00();
};

void* VehicleRenderMaskTemplate::vfunc_00()
{
    return DAT_00421194;
}

// ============================================================================
// [VERIFIED] VehicleRenderMaskTemplate::vfunc_01 (0x001D2810, 36 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as CollisionBehaviourTypeGroup::vfunc_01 (0x00013840), which was matched first;
// its addresses and names were swapped for this function's.
// VehicleRenderMaskTemplate::vfunc_01 (0x001D2810, 36 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_003A7894[];
extern "C" void __cdecl sub_00025160(int);
extern "C" void __cdecl sub_001D1AC0(void);

class VehicleRenderMaskTemplate
{
public:
    virtual void vfunc_00();
    virtual VehicleRenderMaskTemplate* vfunc_01(int a1);
};

VehicleRenderMaskTemplate* VehicleRenderMaskTemplate::vfunc_01(int a1)
{
    *(int*)this = (int)DAT_003A7894;
    sub_001D1AC0();
    if (a1 & 1) {
        sub_00025160((int)this);
    }
    return this;
}

// ============================================================================
// [VERIFIED] VehicleRenderMaskTemplate::vfunc_12 (0x001D2840, 30 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// bin: proto
// va: 0x001D2840
// what: 
// tool: the portal's starter code (no AI)

// VehicleRenderMaskTemplate::vfunc_12 (Proto 0x001D2840, 30 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __cdecl sub_001D1760(void);

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
    virtual void vfunc_12();
    char m_pad04[0x1E];
    bool m_Field22; // +0x22
    char m_pad23[0x9];
    unsigned short m_Field2C; // +0x2C
    char m_pad2E[0x2];
    int m_Field30; // +0x30
};

void VehicleRenderMaskTemplate::vfunc_12()
{
    if (m_Field22) {
        sub_001D1760();
        m_Field2C = 65535;
        m_Field30 = 0;
    }
}

// ============================================================================
// [VERIFIED] VehicleRenderMaskTemplate::vfunc_05 (0x001D3620, 57 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// bin: proto
// va: 0x001D3620
// what: 
// tool: the portal's starter code (no AI)

// VehicleRenderMaskTemplate::vfunc_05 (Proto 0x001D3620, 57 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __stdcall sub_001D16C0(int);

class VehicleRenderMaskTemplate
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual void vfunc_05(int a1);
    char m_pad04[0x1C];
    unsigned short m_Field20; // +0x20
    bool m_Field22; // +0x22
    char m_pad23[0x9];
    unsigned short m_Field2C; // +0x2C
    char m_pad2E[0x2];
    int m_Field30; // +0x30
    char m_pad34[0x4];
    int m_Field38; // +0x38
};

void VehicleRenderMaskTemplate::vfunc_05(int a1)
{
    int t2;

    sub_001D16C0(0);
    if (m_Field22) {
        t2 = m_Field38;
        m_Field2C = 65535;
        m_Field30 = 0;
        if (!m_Field38) goto L_35;
        if (!*(unsigned char*)t2) goto L_35;
        m_Field2C = m_Field20;
        m_Field30 = t2;
    }
L_35:
    ;
}

// ============================================================================
// [VERIFIED] VehicleRenderMaskTemplate::vfunc_11 (0x001D3660, 40 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// bin: proto
// va: 0x001D3660
// what: 
// tool: the portal's starter code (no AI)

// VehicleRenderMaskTemplate::vfunc_11 (Proto 0x001D3660, 40 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __cdecl sub_001D1720(void);

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
    char m_pad04[0x1C];
    unsigned short m_Field20; // +0x20
    bool m_Field22; // +0x22
    char m_pad23[0x9];
    unsigned short m_Field2C; // +0x2C
    char m_pad2E[0x2];
    int m_Field30; // +0x30
    char m_pad34[0x4];
    int m_Field38; // +0x38
};

void VehicleRenderMaskTemplate::vfunc_11()
{
    int t2;

    if (!m_Field22) {
        sub_001D1720();
        t2 = m_Field38;
        if (!m_Field38) goto L_26;
        if (!*(unsigned char*)t2) goto L_26;
        m_Field2C = m_Field20;
        m_Field30 = t2;
    }
L_26:
    ;
}

