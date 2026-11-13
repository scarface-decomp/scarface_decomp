// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail Xbox default.xbe, engine/FightContext.cpp (5 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 5 of 9 functions matched (55.56%). NOT COMPLETE YET.
// The 4 still to do are listed in their place in Original_Binary_Order_Xbox.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] FightContext::vfunc_05 (0x00021930, 15 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// FightContext::vfunc_05 (0x00021930, 15 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field10
{
    void sub_000D8580(int);
};

class FightContext
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual void vfunc_05();
    char m_pad04[0xC];
    Field10* m_Field10; // +0x10
};

void FightContext::vfunc_05()
{
    if (m_Field10) {
        m_Field10->sub_000D8580(0);
    }
}

// ============================================================================
// [VERIFIED] FightContext::vfunc_06 (0x00021940, 57 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// FightContext::vfunc_06 (0x00021940, 57 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field14
{
    void sub_00239FC0(int, int);
    void sub_00239FD0();
    void sub_0023A190(int, int);
};

class FightContext
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual void vfunc_05();
    virtual void vfunc_06(int a1);
    char m_pad04[0x10];
    Field14* m_Field14; // +0x14
};

void FightContext::vfunc_06(int a1)
{
    if (m_Field14) {
        m_Field14->sub_0023A190(a1, (int)this);
        m_Field14->sub_00239FC0(0, a1);
        m_Field14->sub_00239FC0(1, a1);
        m_Field14->sub_00239FD0();
    }
}

// ============================================================================
// [VERIFIED] FightContext::vfunc_10 (0x00021A60, 75 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// FightContext::vfunc_10 (0x00021A60, 75 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    int sub_000E8920();
};

extern "C" char DAT_0039E278[];
extern "C" int __cdecl sub_0028E510(int);

class FightContext
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
    virtual int vfunc_08(int);
    virtual void vfunc_09(int);
    virtual void vfunc_10(int a1);
};

void FightContext::vfunc_10(int a1)
{
    int r_edi, t2, t6;

    r_edi = a1;
    t2 = vfunc_08(a1);
    if (t2) {
        vfunc_09(((Object*)t2)->sub_000E8920());
    }
    r_edi = *(int*)(r_edi + 12);
    if (r_edi) {
        t6 = *(int*)(r_edi + 8);
        if (t6 == sub_0028E510((int)DAT_0039E278)) goto L_45;
        vfunc_10(r_edi);
    }
L_45:
    ;
}

// ============================================================================
// [VERIFIED] FightContext::vfunc_11 (0x00021AB0, 79 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// FightContext::vfunc_11 (0x00021AB0, 79 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    int sub_0017E6E0();
};

extern "C" char DAT_0039E278[];
extern "C" int __cdecl sub_0028E510(int);

class FightContext
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
    virtual int vfunc_08(int);
    virtual void vfunc_09(int);
    virtual void vfunc_10();
    virtual void vfunc_11(int a1);
};

void FightContext::vfunc_11(int a1)
{
    int t1, t2, t5;

    t1 = *(int*)(a1 + 12);
    if (*(int*)(a1 + 12)) {
        t2 = *(int*)(t1 + 8);
        if (t2 == sub_0028E510((int)DAT_0039E278)) goto L_2E;
        vfunc_11(t1);
    }
L_2E:
    t5 = vfunc_08(a1);
    if (t5) {
        vfunc_09(((Object*)t5)->sub_0017E6E0());
    }
}

// ============================================================================
// [VERIFIED] FightContext::vfunc_03 (0x00021B20, 86 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// FightContext::vfunc_03 (0x00021B20, 86 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0023A380();
};

extern "C" char DAT_0039E248[];
extern "C" void __cdecl sub_00027600(int);

class FightContext
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual FightContext* vfunc_03(int a1);
    void sub_002A6940();
    char m_pad04[0x10];
    int m_Field14; // +0x14
    int m_Field18; // +0x18
};

FightContext* FightContext::vfunc_03(int a1)
{
    int t1, t4;

    t1 = m_Field14;
    *(int*)this = (int)DAT_0039E248;
    if (m_Field14) {
        ((Object*)t1)->sub_0023A380();
        sub_00027600(t1);
    }
    t4 = m_Field18;
    if (m_Field18) {
        ((Object*)t4)->sub_0023A380();
        sub_00027600(t4);
    }
    sub_002A6940();
    if (a1 & 1) {
        sub_00027600((int)this);
    }
    return this;
}

