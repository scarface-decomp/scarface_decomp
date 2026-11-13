// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail Xbox default.xbe, engine/WheeledLocomotion.cpp (5 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 5 of 9 functions matched (55.56%). NOT COMPLETE YET.
// The 4 still to do are listed in their place in Original_Binary_Order_Xbox.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] WheeledLocomotion::vfunc_05 (0x0009CE20, 14 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// WheeledLocomotion::vfunc_05 (0x0009CE20, 14 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

class WheeledLocomotion
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual void vfunc_05(int a1);
    char m_pad04[0x15];
    bool m_Field19; // +0x19
};

void WheeledLocomotion::vfunc_05(int a1)
{
    m_Field19 = a1 == 1;
    a1 == 1;
}

// ============================================================================
// [VERIFIED] WheeledLocomotion::vfunc_06 (0x0009CE30, 53 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// WheeledLocomotion::vfunc_06 (0x0009CE30, 53 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_000BCA00(int);
};

class WheeledLocomotion
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual void vfunc_05();
    virtual int vfunc_06(int a1);
    char m_pad04[0x8];
    int m_Field0C; // +0x0C
    int m_Field10; // +0x10
};

int WheeledLocomotion::vfunc_06(int a1)
{
    int r_eax, r_ebp, r_ebx, r_edi;

    r_eax = m_Field0C;
    r_edi = 0;
    if (r_eax > 0) {
        r_ebp = a1;
        r_ebx = 0;
        do {
            ((Object*)m_Field10 + r_ebx)->sub_000BCA00(r_ebp);
            r_eax = m_Field0C;
            r_edi += 1;
            r_ebx += 548;
        } while (r_edi < r_eax);
    }
    return r_eax;
}

// ============================================================================
// [VERIFIED] WheeledLocomotion::vfunc_07 (0x0009CF40, 53 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as WheeledLocomotion::vfunc_06 (0x0009CE30), which was matched first;
// its addresses and names were swapped for this function's.
// WheeledLocomotion::vfunc_07 (0x0009CF40, 53 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_000BE290(int);
};

class WheeledLocomotion
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual void vfunc_05();
    virtual int vfunc_07(int a1);
    char m_pad04[0x8];
    int m_Field0C; // +0x0C
    int m_Field10; // +0x10
};

int WheeledLocomotion::vfunc_07(int a1)
{
    int r_eax, r_ebp, r_ebx, r_edi;

    r_eax = m_Field0C;
    r_edi = 0;
    if (r_eax > 0) {
        r_ebp = a1;
        r_ebx = 0;
        do {
            ((Object*)m_Field10 + r_ebx)->sub_000BE290(r_ebp);
            r_eax = m_Field0C;
            r_edi += 1;
            r_ebx += 548;
        } while (r_edi < r_eax);
    }
    return r_eax;
}

// ============================================================================
// [VERIFIED] WheeledLocomotion::vfunc_08 (0x0009CF80, 44 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// WheeledLocomotion::vfunc_08 (0x0009CF80, 44 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_000BE3B0();
};

class WheeledLocomotion
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
    virtual int vfunc_08();
    char m_pad04[0x8];
    int m_Field0C; // +0x0C
    int m_Field10; // +0x10
};

int WheeledLocomotion::vfunc_08()
{
    int r_eax, r_ebx, r_edi;

    r_eax = m_Field0C;
    r_edi = 0;
    if (r_eax > 0) {
        r_ebx = 0;
        do {
            ((Object*)m_Field10 + r_ebx)->sub_000BE3B0();
            r_eax = m_Field0C;
            r_edi += 1;
            r_ebx += 548;
        } while (r_edi < r_eax);
    }
    return r_eax;
}

// ============================================================================
// [VERIFIED] WheeledLocomotion::vfunc_00 (0x0009D970, 43 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as GameGroup::vfunc_01 (0x000290E0), which was matched first;
// its addresses and names were swapped for this function's.
// WheeledLocomotion::vfunc_00 (0x0009D970, 43 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_003A49B0[];
extern "C" void __cdecl sub_00027600(int);
extern "C" void __cdecl sub_0009D5E0(void);

class WheeledLocomotion
{
public:
    virtual void vfunc_00();
    virtual WheeledLocomotion* vfunc_00(int a1);
    void sub_000B1CA0();
};

WheeledLocomotion* WheeledLocomotion::vfunc_00(int a1)
{
    *(int*)this = (int)DAT_003A49B0;
    sub_0009D5E0();
    sub_000B1CA0();
    if (a1 & 1) {
        sub_00027600((int)this);
    }
    return this;
}

