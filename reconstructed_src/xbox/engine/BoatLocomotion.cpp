// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail Xbox default.xbe, engine/BoatLocomotion.cpp (4 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 4 of 7 functions matched (57.14%). NOT COMPLETE YET.
// The 3 still to do are listed in their place in Original_Binary_Order_Xbox.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] BoatLocomotion::vfunc_03 (0x000A1210, 66 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as BoatLocomotion::vfunc_05 (Proto 0x00095560), which was matched first;
// its addresses and names were swapped for this function's.
// bin: proto
// va: 0x000A1210
// what: 
// tool: the portal's starter code (no AI)

// BoatLocomotion::vfunc_03 (Proto 0x000A1210, 66 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field08
{
    int sub_000A0CD0();
    int sub_000A0D80();
};

struct Field0C
{
    void sub_000BB290(int, int, int);
};

extern "C" void __cdecl sub_002A9290(void);

class BoatLocomotion
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    int m_Field04; // +0x04
    Field08* m_Field08; // +0x08
    Field0C m_Field0C; // +0x0C
};

void BoatLocomotion::vfunc_03()
{
    int t3, t4;

    sub_002A9290();
    if (!m_Field04) goto L_40;
    if (!m_Field08) goto L_40;
    t3 = m_Field08->sub_000A0CD0();
    t4 = m_Field08->sub_000A0D80();
    if (t3) {
        if (!t4) goto L_3F;
        m_Field0C.sub_000BB290(t3, t4, m_Field04 + 52);
    }
L_3F:
L_40:
    ;
}

// ============================================================================
// [VERIFIED] BoatLocomotion::vfunc_05 (0x000A1260, 15 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// BoatLocomotion::vfunc_05 (0x000A1260, 15 bytes)
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
    virtual bool vfunc_05(int a1);
    char m_pad04[0xC];
    bool m_Field10; // +0x10
};

bool BoatLocomotion::vfunc_05(int a1)
{
    m_Field10 = a1;
    return a1;
}

// ============================================================================
// [VERIFIED] BoatLocomotion::vfunc_00 (0x000A1310, 46 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// What it does: BoatLocomotion's deleting destructor: destroys the object, frees its memory when asked (flag bit 0), and returns it.
// ============================================================================
// BoatLocomotion::vfunc_00 (0x000A1310, 46 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field0C
{
    void sub_000BA410();
};

extern "C" char DAT_003A4A50[];
extern "C" void __cdecl sub_00027600(int);

class BoatLocomotion
{
public:
    virtual BoatLocomotion* vfunc_00(int a1);
    void sub_000B1CA0();
    char m_pad04[0x8];
    Field0C m_Field0C; // +0x0C
};

BoatLocomotion* BoatLocomotion::vfunc_00(int a1)
{
    *(int*)this = (int)DAT_003A4A50;
    m_Field0C.sub_000BA410();
    sub_000B1CA0();
    if (a1 & 1) {
        sub_00027600((int)this);
    }
    return this;
}

// ============================================================================
// [VERIFIED] BoatLocomotion::vfunc_04 (0x000A13A0, 41 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// BoatLocomotion::vfunc_04 (0x000A13A0, 41 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field08
{
    void sub_000A0C60();
};

struct Field0C
{
    int sub_000B8DB0(int);
};

extern "C" void __cdecl sub_002A9290(void);

class BoatLocomotion
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual int vfunc_04();
    int m_Field04; // +0x04
    Field08* m_Field08; // +0x08
    Field0C m_Field0C; // +0x0C
};

int BoatLocomotion::vfunc_04()
{
    int r_eax;

    sub_002A9290();
    if (m_Field08) {
        m_Field08->sub_000A0C60();
    }
    r_eax = m_Field04;
    if (r_eax) {
        r_eax += 100;
        r_eax = m_Field0C.sub_000B8DB0(r_eax);
    }
    return r_eax;
}

