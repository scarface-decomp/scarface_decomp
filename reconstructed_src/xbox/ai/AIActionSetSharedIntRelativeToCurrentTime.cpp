// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail Xbox default.xbe, ai/AIActionSetSharedIntRelativeToCurrentTime.cpp (2 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: COMPLETE. All 2 functions are matched.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] AIActionSetSharedIntRelativeToCurrentTime::vfunc_06 (0x00120D10, 39 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as AIActionSetSharedIntRelativeToCurrentTime::vfunc_07 (Proto 0x00105770), which was matched first;
// its addresses and names were swapped for this function's.
// AIActionSetSharedIntRelativeToCurrentTime::vfunc_06 (Proto 0x00120D10, 39 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field08
{
    void sub_001206D0(int);
};

struct Field0A
{
    int sub_00120670();
};

extern "C" int DAT_004879E8;

class AIActionSetSharedIntRelativeToCurrentTime
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
    Field08 m_Field08; // +0x08
    char m_pad09[0x1];
    Field0A m_Field0A; // +0x0A
};

int AIActionSetSharedIntRelativeToCurrentTime::vfunc_06()
{
    int t2;

    t2 = *(int*)(DAT_004879E8 + 44);
    m_Field08.sub_001206D0(m_Field0A.sub_00120670() + t2);
    return 1;
}

// ============================================================================
// [VERIFIED] AIActionSetSharedIntRelativeToCurrentTime::vfunc_00 (0x001214D0, 47 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// What it does: AIActionSetSharedIntRelativeToCurrentTime's deleting destructor: destroys the object, frees its memory when asked (flag bit 0), and returns it.
// ============================================================================
// Same machine code as AIActionSetSharedIntRelativeToCurrentTime::vfunc_00 (Proto 0x00105EB0), which was matched first;
// its addresses and names were swapped for this function's.
// AIActionSetSharedIntRelativeToCurrentTime::vfunc_00 (Proto 0x001214D0, 47 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field0A
{
    void sub_001204E0();
};

extern "C" char DAT_003AAAC8[];
extern "C" void __cdecl sub_00027600(int);

class AIActionSetSharedIntRelativeToCurrentTime
{
public:
    virtual AIActionSetSharedIntRelativeToCurrentTime* vfunc_00(int a1);
    char m_pad04[0x4];
    Field0A m_Field08; // +0x08
    char m_pad09[0x1];
    Field0A m_Field0A; // +0x0A
};

AIActionSetSharedIntRelativeToCurrentTime* AIActionSetSharedIntRelativeToCurrentTime::vfunc_00(int a1)
{
    m_Field0A.sub_001204E0();
    m_Field08.sub_001204E0();
    *(int*)this = (int)DAT_003AAAC8;
    if (a1 & 1) {
        sub_00027600((int)this);
    }
    return this;
}

