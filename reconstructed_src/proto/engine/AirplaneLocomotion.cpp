// ============================================================================
// SCARFACE: THE WORLD IS YOURS — April 2006 prototype game.xbe, engine/AirplaneLocomotion.cpp (6 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 6 of 8 functions matched (75.00%). NOT COMPLETE YET.
// The 2 still to do are listed in their place in Original_Binary_Order_Proto.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] AirplaneLocomotion::vfunc_05 (0x0008FBC0, 94 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// bin: proto
// va: 0x0008FBC0
// what: 
// tool: the portal's starter code (no AI)

// AirplaneLocomotion::vfunc_05 (Proto 0x0008FBC0, 94 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field08
{
    int sub_0008F930();
    int sub_0008FA10();
    int sub_0008FAD0();
};

struct Field18
{
    void sub_000A5AA0();
};

struct Field24
{
    void sub_000ADC00(int, int, int);
};

extern "C" void __cdecl sub_001B7A10(void);

class AirplaneLocomotion
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual void vfunc_05();
    int m_Field04; // +0x04
    Field08* m_Field08; // +0x08
    Field18 m_Field0C; // +0x0C
    char m_pad0D[0xB];
    Field18 m_Field18; // +0x18
    char m_pad19[0xB];
    Field24 m_Field24; // +0x24
};

void AirplaneLocomotion::vfunc_05()
{
    int t6, t7;

    sub_001B7A10();
    if (m_Field08->sub_0008FA10()) {
        m_Field18.sub_000A5AA0();
    }
    m_Field0C.sub_000A5AA0();
    if (!m_Field04) goto L_5C;
    if (!m_Field08) goto L_5C;
    t6 = m_Field08->sub_0008F930();
    t7 = m_Field08->sub_0008FAD0();
    if (t6) {
        if (!t7) goto L_5B;
        m_Field24.sub_000ADC00(t6, t7, m_Field04 + 52);
    }
L_5B:
L_5C:
    ;
}

// ============================================================================
// [VERIFIED] AirplaneLocomotion::vfunc_11 (0x0008FC40, 7 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as AirplaneLocomotion::vfunc_09 (0x0009B380), which was matched first;
// its addresses and names were swapped for this function's.
// AirplaneLocomotion::vfunc_11 (0x0008FC40, 7 bytes)
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
    virtual int vfunc_11();
    int m_Field04; // +0x04
};

int AirplaneLocomotion::vfunc_11()
{
    return *(int*)(m_Field04 + 32);
}

// ============================================================================
// [VERIFIED] AirplaneLocomotion::vfunc_07 (0x0008FC50, 15 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as AirplaneLocomotion::vfunc_05 (0x0009B390), which was matched first;
// its addresses and names were swapped for this function's.
// AirplaneLocomotion::vfunc_07 (0x0008FC50, 15 bytes)
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
    virtual bool vfunc_07(int a1);
    char m_pad04[0x58];
    bool m_Field5C; // +0x5C
};

bool AirplaneLocomotion::vfunc_07(int a1)
{
    m_Field5C = a1;
    return a1;
}

// ============================================================================
// [VERIFIED] AirplaneLocomotion::vfunc_06 (0x0008FEF0, 41 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as AirplaneLocomotion::vfunc_04 (0x0009B630), which was matched first;
// its addresses and names were swapped for this function's.
// AirplaneLocomotion::vfunc_06 (0x0008FEF0, 41 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field08
{
    void sub_0008F8D0();
};

struct Field24
{
    int sub_000AB670(int);
};

extern "C" void __cdecl sub_001B7A10(void);

class AirplaneLocomotion
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual int vfunc_06();
    int m_Field04; // +0x04
    Field08* m_Field08; // +0x08
    char m_pad0C[0x18];
    Field24 m_Field24; // +0x24
};

int AirplaneLocomotion::vfunc_06()
{
    int r_eax;

    sub_001B7A10();
    if (m_Field08) {
        m_Field08->sub_0008F8D0();
    }
    r_eax = m_Field04;
    if (r_eax) {
        r_eax += 100;
        r_eax = m_Field24.sub_000AB670(r_eax);
    }
    return r_eax;
}

// ============================================================================
// [VERIFIED] AirplaneLocomotion::vfunc_12 (0x00090810, 93 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 /arch:SSE
// ============================================================================
// bin: proto
// va: 0x00090810
// what: 
// tool: the portal's starter code (no AI)

// AirplaneLocomotion::vfunc_12 (Proto 0x00090810, 93 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field04
{
    bool sub_0009FE50();
};

struct Field08
{
    int sub_0008F9D0();
};

struct Object
{
    void sub_0009B800(float);
};

extern "C" float DAT_00383ED4;

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
    virtual void vfunc_10();
    virtual void vfunc_11();
    virtual bool vfunc_12();
    Field04* m_Field04; // +0x04
    Field08* m_Field08; // +0x08
    char m_pad0C[0x44];
    bool m_Field50; // +0x50
};

bool AirplaneLocomotion::vfunc_12()
{
    int t4, t5, t6;

    if (m_Field08) {
        if (!m_Field04) goto L_58;
        if (!m_Field04->sub_0009FE50()) goto L_58;
        if (!m_Field50) goto L_58;
        t4 = m_Field08->sub_0008F9D0();
        t5 = *(int*)((int)m_Field04 + 40);
        if (!t4) goto L_58;
        if (!t5) goto L_58;
        t6 = *(int*)(t4 + 16);
        if (!*(int*)(t4 + 16)) goto L_58;
        ((Object*)t6)->sub_0009B800(*(float*)(t5 + 80) * DAT_00383ED4);
    }
L_58:
    return m_Field50;
}

// ============================================================================
// [VERIFIED] AirplaneLocomotion::vfunc_00 (0x00090990, 30 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as Collidable::vfunc_03 (0x00011F20), which was matched first;
// its addresses and names were swapped for this function's.
// AirplaneLocomotion::vfunc_00 (0x00090990, 30 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __cdecl sub_0008FE90(void);
extern "C" void __cdecl sub_00025160(int);

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
    sub_0008FE90();
    if (a1 & 1) {
        sub_00025160((int)this);
    }
    return this;
}

