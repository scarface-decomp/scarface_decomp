// ============================================================================
// SCARFACE: THE WORLD IS YOURS — April 2006 prototype game.xbe, engine/BoatLocomotion.cpp (3 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 3 of 7 functions matched (42.86%). NOT COMPLETE YET.
// The 4 still to do are listed in their place in Original_Binary_Order_Proto.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] BoatLocomotion::vfunc_07 (0x000955B0, 15 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as BoatLocomotion::vfunc_05 (0x000A1260), which was matched first;
// its addresses and names were swapped for this function's.
// BoatLocomotion::vfunc_07 (0x000955B0, 15 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

class BoatLocomotion
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual bool vfunc_07(int a1);
    char m_pad04[0xC];
    bool m_Field10; // +0x10
};

bool BoatLocomotion::vfunc_07(int a1)
{
    m_Field10 = a1;
    return a1;
}

// ============================================================================
// [VERIFIED] BoatLocomotion::vfunc_00 (0x000955C0, 46 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as BoatLocomotion::vfunc_00 (0x000A1310), which was matched first;
// its addresses and names were swapped for this function's.
// BoatLocomotion::vfunc_00 (0x000955C0, 46 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field0C
{
    void sub_000ACD60();
};

extern "C" char DAT_00383F84[];
extern "C" void __cdecl sub_00025160(int);

class BoatLocomotion
{
public:
    virtual BoatLocomotion* vfunc_00(int a1);
    void sub_000A47C0();
    char m_pad04[0x8];
    Field0C m_Field0C; // +0x0C
};

BoatLocomotion* BoatLocomotion::vfunc_00(int a1)
{
    *(int*)this = (int)DAT_00383F84;
    m_Field0C.sub_000ACD60();
    sub_000A47C0();
    if (a1 & 1) {
        sub_00025160((int)this);
    }
    return this;
}

// ============================================================================
// [VERIFIED] BoatLocomotion::vfunc_06 (0x00095650, 41 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as BoatLocomotion::vfunc_04 (0x000A13A0), which was matched first;
// its addresses and names were swapped for this function's.
// BoatLocomotion::vfunc_06 (0x00095650, 41 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field08
{
    void sub_00094E70();
};

struct Field0C
{
    int sub_000AB670(int);
};

extern "C" void __cdecl sub_001B7A10(void);

class BoatLocomotion
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual int vfunc_06();
    int m_Field04; // +0x04
    Field08* m_Field08; // +0x08
    Field0C m_Field0C; // +0x0C
};

int BoatLocomotion::vfunc_06()
{
    int r_eax;

    sub_001B7A10();
    if (m_Field08) {
        m_Field08->sub_00094E70();
    }
    r_eax = m_Field04;
    if (r_eax) {
        r_eax += 100;
        r_eax = m_Field0C.sub_000AB670(r_eax);
    }
    return r_eax;
}

