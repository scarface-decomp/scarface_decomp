// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail Xbox default.xbe, engine/AirplaneLocomotion.cpp (6 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 6 of 8 functions matched (75.00%). NOT COMPLETE YET.
// The 2 still to do are listed in their place in Original_Binary_Order_Xbox.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] AirplaneLocomotion::vfunc_03 (0x0009B300, 94 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as AirplaneLocomotion::vfunc_05 (Proto 0x0008FBC0), which was matched first;
// its addresses and names were swapped for this function's.
// bin: proto
// va: 0x0009B300
// what: 
// tool: the portal's starter code (no AI)

// AirplaneLocomotion::vfunc_03 (Proto 0x0009B300, 94 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field08
{
    int sub_0009B100();
    int sub_0009B1B0();
    int sub_0009B240();
};

struct Field18
{
    void sub_000B2F80();
};

struct Field24
{
    void sub_000BB290(int, int, int);
};

extern "C" void __cdecl sub_002A9290(void);

class AirplaneLocomotion
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    int m_Field04; // +0x04
    Field08* m_Field08; // +0x08
    Field18 m_Field0C; // +0x0C
    char m_pad0D[0xB];
    Field18 m_Field18; // +0x18
    char m_pad19[0xB];
    Field24 m_Field24; // +0x24
};

void AirplaneLocomotion::vfunc_03()
{
    int t6, t7;

    sub_002A9290();
    if (m_Field08->sub_0009B1B0()) {
        m_Field18.sub_000B2F80();
    }
    m_Field0C.sub_000B2F80();
    if (!m_Field04) goto L_5C;
    if (!m_Field08) goto L_5C;
    t6 = m_Field08->sub_0009B100();
    t7 = m_Field08->sub_0009B240();
    if (t6) {
        if (!t7) goto L_5B;
        m_Field24.sub_000BB290(t6, t7, m_Field04 + 52);
    }
L_5B:
L_5C:
    ;
}

// ============================================================================
// [VERIFIED] AirplaneLocomotion::vfunc_09 (0x0009B380, 7 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// AirplaneLocomotion::vfunc_09 (0x0009B380, 7 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

class AirplaneLocomotion
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
    virtual int vfunc_09();
    int m_Field04; // +0x04
};

int AirplaneLocomotion::vfunc_09()
{
    return *(int*)(m_Field04 + 32);
}

// ============================================================================
// [VERIFIED] AirplaneLocomotion::vfunc_05 (0x0009B390, 15 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// AirplaneLocomotion::vfunc_05 (0x0009B390, 15 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

class AirplaneLocomotion
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual bool vfunc_05(int a1);
    char m_pad04[0x58];
    bool m_Field5C; // +0x5C
};

bool AirplaneLocomotion::vfunc_05(int a1)
{
    m_Field5C = a1;
    return a1;
}

// ============================================================================
// [VERIFIED] AirplaneLocomotion::vfunc_04 (0x0009B630, 41 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// AirplaneLocomotion::vfunc_04 (0x0009B630, 41 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field08
{
    void sub_0009B0A0();
};

struct Field24
{
    int sub_000B8DB0(int);
};

extern "C" void __cdecl sub_002A9290(void);

class AirplaneLocomotion
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual int vfunc_04();
    int m_Field04; // +0x04
    Field08* m_Field08; // +0x08
    char m_pad0C[0x18];
    Field24 m_Field24; // +0x24
};

int AirplaneLocomotion::vfunc_04()
{
    int r_eax;

    sub_002A9290();
    if (m_Field08) {
        m_Field08->sub_0009B0A0();
    }
    r_eax = m_Field04;
    if (r_eax) {
        r_eax += 100;
        r_eax = m_Field24.sub_000B8DB0(r_eax);
    }
    return r_eax;
}

// ============================================================================
// [VERIFIED] AirplaneLocomotion::vfunc_10 (0x0009BF40, 91 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 /arch:SSE
// ============================================================================
// bin: xb
// va: 0x0009BF40
// what: 
// tool: the portal's starter code (no AI)

// AirplaneLocomotion::vfunc_10 (0x0009BF40, 91 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field08
{
    int sub_0009B180();
};

struct Object
{
    void sub_000A76D0(float);
};

extern "C" float DAT_003A4980;

class AirplaneLocomotion
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
    virtual bool vfunc_10();
    int m_Field04; // +0x04
    Field08* m_Field08; // +0x08
    char m_pad0C[0x44];
    bool m_Field50; // +0x50
};

bool AirplaneLocomotion::vfunc_10()
{
    int t1, t3, t4, t5;

    if (m_Field08) {
        t1 = m_Field04;
        if (!m_Field04) goto L_56;
        if (!*(bool*)(t1 + 1466)) goto L_56;
        if (!m_Field50) goto L_56;
        t3 = m_Field08->sub_0009B180();
        t4 = *(int*)(m_Field04 + 40);
        if (!t3) goto L_56;
        if (!t4) goto L_56;
        t5 = *(int*)(t3 + 16);
        if (!*(int*)(t3 + 16)) goto L_56;
        ((Object*)t5)->sub_000A76D0(*(float*)(t4 + 80) * DAT_003A4980);
    }
L_56:
    return m_Field50;
}

// ============================================================================
// [VERIFIED] AirplaneLocomotion::vfunc_00 (0x0009C0C0, 30 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as Collidable::vfunc_03 (0x00011F20), which was matched first;
// its addresses and names were swapped for this function's.
// AirplaneLocomotion::vfunc_00 (0x0009C0C0, 30 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __cdecl sub_0009B5D0(void);
extern "C" void __cdecl sub_00027600(int);

class AirplaneLocomotion
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual AirplaneLocomotion* vfunc_00(int a1);
};

AirplaneLocomotion* AirplaneLocomotion::vfunc_00(int a1)
{
    sub_0009B5D0();
    if (a1 & 1) {
        sub_00027600((int)this);
    }
    return this;
}

