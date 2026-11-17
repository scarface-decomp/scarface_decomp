// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail Xbox default.xbe, ai/AIActionDecloneSharedIntSafely.cpp (2 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: COMPLETE. All 2 functions are matched.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] AIActionDecloneSharedIntSafely::vfunc_06 (0x00120DC0, 48 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as AIActionDecloneSharedIntSafely::vfunc_07 (Proto 0x00105820), which was matched first;
// its addresses and names were swapped for this function's.
// AIActionDecloneSharedIntSafely::vfunc_06 (Proto 0x00120DC0, 48 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field08
{
    int sub_001655C0();
};

struct Field0C
{
    void sub_00120600();
    bool sub_00120860();
};

struct Object
{
    void sub_000F15A0();
};

class AIActionDecloneSharedIntSafely
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
    Field0C m_Field0C; // +0x0C
};

int AIActionDecloneSharedIntSafely::vfunc_06()
{
    if (m_Field0C.sub_00120860()) {
        ((Object*)m_Field08->sub_001655C0())->sub_000F15A0();
        m_Field0C.sub_00120600();
    }
    return 1;
}

// ============================================================================
// [VERIFIED] AIActionDecloneSharedIntSafely::vfunc_00 (0x001215A0, 39 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as AIActionDecloneSharedIntSafely::vfunc_00 (Proto 0x00105F80), which was matched first;
// its addresses and names were swapped for this function's.
// AIActionDecloneSharedIntSafely::vfunc_00 (Proto 0x001215A0, 39 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field0C
{
    void sub_001204E0();
};

extern "C" char DAT_003AAAC8[];
extern "C" void __cdecl sub_00027600(int);

class AIActionDecloneSharedIntSafely
{
public:
    virtual AIActionDecloneSharedIntSafely* vfunc_00(int a1);
    char m_pad04[0x8];
    Field0C m_Field0C; // +0x0C
};

AIActionDecloneSharedIntSafely* AIActionDecloneSharedIntSafely::vfunc_00(int a1)
{
    m_Field0C.sub_001204E0();
    *(int*)this = (int)DAT_003AAAC8;
    if (a1 & 1) {
        sub_00027600((int)this);
    }
    return this;
}

