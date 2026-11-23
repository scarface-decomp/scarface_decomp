// ============================================================================
// SCARFACE: THE WORLD IS YOURS — April 2006 prototype game.xbe, engine/WheeledLocomotion.cpp (9 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 9 of 11 functions matched (81.82%). NOT COMPLETE YET.
// The 2 still to do are listed in their place in Original_Binary_Order_Proto.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] WheeledLocomotion::vfunc_06 (0x000914A0, 93 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 /arch:SSE
// ============================================================================
// bin: proto
// va: 0x000914A0
// what: 
// tool: the portal's starter code (no AI)

// WheeledLocomotion::vfunc_06 (Proto 0x000914A0, 93 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field04
{
    void sub_0009F2B0(int);
};

struct Field08
{
    void sub_000B48B0();
};

struct Object
{
    void sub_000B0990();
};

extern "C" float DAT_0037CE60;
extern "C" void __cdecl sub_001B7A10(void);

class WheeledLocomotion
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual void vfunc_05();
    virtual int vfunc_06();
    Field04* m_Field04; // +0x04
    Field08* m_Field08; // +0x08
    int m_Field0C; // +0x0C
    int m_Field10; // +0x10
    float m_Field14; // +0x14
    bool m_Field18; // +0x18
};

int WheeledLocomotion::vfunc_06()
{
    int r_eax, r_ebx, r_edi;
    float t5;

    sub_001B7A10();
    if (m_Field04) {
        m_Field04->sub_0009F2B0(0);
    }
    if (m_Field08) {
        m_Field08->sub_000B48B0();
    }
    r_eax = m_Field0C;
    r_edi = 0;
    if (r_eax > 0) {
        r_ebx = 0;
        do {
            ((Object*)m_Field10 + r_ebx)->sub_000B0990();
            r_eax = m_Field0C;
            r_edi += 1;
            r_ebx += 592;
        } while (r_edi < r_eax);
    }
    t5 = DAT_0037CE60;
    m_Field18 = false;
    m_Field14 = t5;
    return r_eax;
}

// ============================================================================
// [VERIFIED] WheeledLocomotion::vfunc_02 (0x00091500, 85 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// bin: proto
// va: 0x00091500
// what: 
// tool: the portal's starter code (no AI)

// WheeledLocomotion::vfunc_02 (Proto 0x00091500, 85 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field08
{
    int sub_000B49E0();
};

struct Object
{
    void sub_000AFA10(int, int);
};

extern "C" void __stdcall sub_0021AF00(int);

class WheeledLocomotion
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02(int a1);
    char m_pad04[0x4];
    Field08* m_Field08; // +0x08
    int m_Field0C; // +0x0C
    int m_Field10; // +0x10
};

void WheeledLocomotion::vfunc_02(int a1)
{
    int r_ebp, r_ebx, r_edi, t4;

    sub_0021AF00(a1);
    r_ebp = m_Field08->sub_000B49E0();
    if (r_ebp) {
        r_edi = 0;
        if (m_Field0C > 0) {
            r_ebx = 0;
            do {
                ((Object*)m_Field10 + r_ebx)->sub_000AFA10(a1, r_ebp);
                t4 = m_Field0C;
                r_edi += 1;
                r_ebx += 592;
            } while (r_edi < t4);
        }
    }
}

// ============================================================================
// [VERIFIED] WheeledLocomotion::vfunc_03 (0x000915A0, 53 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// WheeledLocomotion::vfunc_03 (Proto 0x000915A0, 53 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_000AF2F0(int);
};

class WheeledLocomotion
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual int vfunc_03(int a1);
    char m_pad04[0x8];
    int m_Field0C; // +0x0C
    int m_Field10; // +0x10
};

int WheeledLocomotion::vfunc_03(int a1)
{
    int r_eax, r_ebp, r_ebx, r_edi;

    r_eax = m_Field0C;
    r_edi = 0;
    if (r_eax > 0) {
        r_ebp = a1;
        r_ebx = 0;
        do {
            ((Object*)m_Field10 + r_ebx)->sub_000AF2F0(r_ebp);
            r_eax = m_Field0C;
            r_edi += 1;
            r_ebx += 592;
        } while (r_edi < r_eax);
    }
    return r_eax;
}

// ============================================================================
// [VERIFIED] WheeledLocomotion::vfunc_04 (0x000915E0, 69 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// WheeledLocomotion::vfunc_04 (Proto 0x000915E0, 69 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field08
{
    int sub_000B49E0();
};

struct Object
{
    void sub_000AFA50(int, int);
};

class WheeledLocomotion
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual int vfunc_04(int a1);
    char m_pad04[0x4];
    Field08* m_Field08; // +0x08
    int m_Field0C; // +0x0C
    int m_Field10; // +0x10
};

int WheeledLocomotion::vfunc_04(int a1)
{
    int r_eax, r_ebp, r_ebx, r_edi;

    r_eax = m_Field08->sub_000B49E0();
    r_ebp = r_eax;
    r_eax = m_Field0C;
    r_edi = 0;
    if (r_eax > 0) {
        r_ebx = 0;
        do {
            r_eax = a1;
            ((Object*)m_Field10 + r_ebx)->sub_000AFA50(a1, r_ebp);
            r_eax = m_Field0C;
            r_edi += 1;
            r_ebx += 592;
        } while (r_edi < r_eax);
    }
    return r_eax;
}

// ============================================================================
// [VERIFIED] WheeledLocomotion::vfunc_07 (0x000917B0, 25 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// bin: proto
// va: 0x000917B0
// what: 
// tool: the portal's starter code (no AI)

// WheeledLocomotion::vfunc_07 (Proto 0x000917B0, 25 bytes)
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
    virtual void vfunc_05();
    virtual void vfunc_06();
    virtual void vfunc_07(int a1);
    char m_pad04[0x15];
    bool m_Field19; // +0x19
    bool m_Field1A; // +0x1A
};

void WheeledLocomotion::vfunc_07(int a1)
{
    m_Field19 = a1 == 1;
    m_Field1A = a1 == 2;
}

// ============================================================================
// [VERIFIED] WheeledLocomotion::vfunc_08 (0x000917D0, 53 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// WheeledLocomotion::vfunc_08 (Proto 0x000917D0, 53 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_000AF2B0(int);
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
    virtual int vfunc_08(int a1);
    char m_pad04[0x8];
    int m_Field0C; // +0x0C
    int m_Field10; // +0x10
};

int WheeledLocomotion::vfunc_08(int a1)
{
    int r_eax, r_ebp, r_ebx, r_edi;

    r_eax = m_Field0C;
    r_edi = 0;
    if (r_eax > 0) {
        r_ebp = a1;
        r_ebx = 0;
        do {
            ((Object*)m_Field10 + r_ebx)->sub_000AF2B0(r_ebp);
            r_eax = m_Field0C;
            r_edi += 1;
            r_ebx += 592;
        } while (r_edi < r_eax);
    }
    return r_eax;
}

// ============================================================================
// [VERIFIED] WheeledLocomotion::vfunc_09 (0x000918A0, 53 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// WheeledLocomotion::vfunc_09 (Proto 0x000918A0, 53 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_000B0CB0(int);
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
    virtual void vfunc_08();
    virtual int vfunc_09(int a1);
    char m_pad04[0x8];
    int m_Field0C; // +0x0C
    int m_Field10; // +0x10
};

int WheeledLocomotion::vfunc_09(int a1)
{
    int r_eax, r_ebp, r_ebx, r_edi;

    r_eax = m_Field0C;
    r_edi = 0;
    if (r_eax > 0) {
        r_ebp = a1;
        r_ebx = 0;
        do {
            ((Object*)m_Field10 + r_ebx)->sub_000B0CB0(r_ebp);
            r_eax = m_Field0C;
            r_edi += 1;
            r_ebx += 592;
        } while (r_edi < r_eax);
    }
    return r_eax;
}

// ============================================================================
// [VERIFIED] WheeledLocomotion::vfunc_10 (0x000918E0, 44 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// WheeledLocomotion::vfunc_10 (Proto 0x000918E0, 44 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_000B0DE0();
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
    virtual void vfunc_08();
    virtual void vfunc_09();
    virtual int vfunc_10();
    char m_pad04[0x8];
    int m_Field0C; // +0x0C
    int m_Field10; // +0x10
};

int WheeledLocomotion::vfunc_10()
{
    int r_eax, r_ebx, r_edi;

    r_eax = m_Field0C;
    r_edi = 0;
    if (r_eax > 0) {
        r_ebx = 0;
        do {
            ((Object*)m_Field10 + r_ebx)->sub_000B0DE0();
            r_eax = m_Field0C;
            r_edi += 1;
            r_ebx += 592;
        } while (r_edi < r_eax);
    }
    return r_eax;
}

// ============================================================================
// [VERIFIED] WheeledLocomotion::vfunc_00 (0x00091F70, 43 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as GameGroup::vfunc_01 (0x000290E0), which was matched first;
// its addresses and names were swapped for this function's.
// WheeledLocomotion::vfunc_00 (0x00091F70, 43 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_00383F00[];
extern "C" void __cdecl sub_00025160(int);
extern "C" void __cdecl sub_00091E00(void);

class WheeledLocomotion
{
public:
    virtual void vfunc_00();
    virtual WheeledLocomotion* vfunc_00(int a1);
    void sub_000A47C0();
};

WheeledLocomotion* WheeledLocomotion::vfunc_00(int a1)
{
    *(int*)this = (int)DAT_00383F00;
    sub_00091E00();
    sub_000A47C0();
    if (a1 & 1) {
        sub_00025160((int)this);
    }
    return this;
}

