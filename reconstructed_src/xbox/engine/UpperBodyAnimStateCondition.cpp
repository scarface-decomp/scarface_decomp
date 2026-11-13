// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail Xbox default.xbe, engine/UpperBodyAnimStateCondition.cpp (2 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 2 of 3 functions matched (66.67%). NOT COMPLETE YET.
// The 1 still to do are listed in their place in Original_Binary_Order_Xbox.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] UpperBodyAnimStateCondition::vfunc_08 (0x000DD100, 25 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// UpperBodyAnimStateCondition::vfunc_08 (0x000DD100, 25 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_0042504C[];

class UpperBodyAnimStateCondition
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
};

int UpperBodyAnimStateCondition::vfunc_08(int a1)
{
    int r_eax;

    r_eax = 0;
    if (a1 >= 0) {
        if ((unsigned int)a1 >= (unsigned int)1) goto L_16;
        r_eax = DAT_0042504C[a1];
    }
L_16:
    return r_eax;
}

// ============================================================================
// [VERIFIED] UpperBodyAnimStateCondition::vfunc_03 (0x000DD650, 46 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// UpperBodyAnimStateCondition::vfunc_03 (0x000DD650, 46 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field10
{
    void sub_002A9290();
};

extern "C" char DAT_003A66EC[];
extern "C" void __cdecl sub_0023F7A0(int);

class UpperBodyAnimStateCondition
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual UpperBodyAnimStateCondition* vfunc_03(int a1);
    void sub_00021870();
    char m_pad04[0xC];
    Field10 m_Field10; // +0x10
};

UpperBodyAnimStateCondition* UpperBodyAnimStateCondition::vfunc_03(int a1)
{
    *(int*)this = (int)DAT_003A66EC;
    m_Field10.sub_002A9290();
    sub_00021870();
    if (a1 & 1) {
        sub_0023F7A0((int)this);
    }
    return this;
}

