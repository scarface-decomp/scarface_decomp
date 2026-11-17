// ============================================================================
// SCARFACE: THE WORLD IS YOURS — April 2006 prototype game.xbe, ai/AIActionPlayAnimAbstract.cpp (3 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 3 of 4 functions matched (75.00%). NOT COMPLETE YET.
// The 1 still to do are listed in their place in Original_Binary_Order_Proto.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] AIActionPlayAnimAbstract::vfunc_06 (0x001055A0, 39 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// AIActionPlayAnimAbstract::vfunc_06 (Proto 0x001055A0, 39 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field08
{
    int sub_00147B00();
};

extern "C" int DAT_0040AA2C;
extern "C" bool __cdecl sub_000BAEB0(void);

class AIActionPlayAnimAbstract
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual void vfunc_05();
    virtual int vfunc_06();
    char m_pad04[0x4];
    Field08* m_Field08; // +0x08
};

int AIActionPlayAnimAbstract::vfunc_06()
{
    if (sub_000BAEB0()) {
        if (m_Field08->sub_00147B00() != DAT_0040AA2C) goto L_23;
        return 1;
    }
L_23:
    return 0;
}

// ============================================================================
// [VERIFIED] AIActionPlayAnimAbstract::vfunc_09 (0x001055D0, 25 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// AIActionPlayAnimAbstract::vfunc_09 (Proto 0x001055D0, 25 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field08
{
    int sub_00147B00();
};

class AIActionPlayAnimAbstract
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
    virtual bool vfunc_09();
    char m_pad04[0x4];
    Field08* m_Field08; // +0x08
    int m_Field0C; // +0x0C
};

bool AIActionPlayAnimAbstract::vfunc_09()
{
    return m_Field08->sub_00147B00() >= m_Field0C;
}

// ============================================================================
// [VERIFIED] AIActionPlayAnimAbstract::vfunc_04 (0x00105610, 11 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// AIActionPlayAnimAbstract::vfunc_04 (Proto 0x00105610, 11 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field08
{
    void sub_00149570(int);
};

class AIActionPlayAnimAbstract
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    char m_pad04[0x4];
    Field08* m_Field08; // +0x08
};

void AIActionPlayAnimAbstract::vfunc_04()
{
    m_Field08->sub_00149570(0);
}

