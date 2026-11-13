// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail Xbox default.xbe, engine/AirplaneLocomotion.cpp (4 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 4 of 8 functions matched (50.00%). NOT COMPLETE YET.
// The 4 still to do are listed in their place in Original_Binary_Order_Xbox.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

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

