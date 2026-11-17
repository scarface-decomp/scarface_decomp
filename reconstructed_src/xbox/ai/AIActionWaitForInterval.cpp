// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail Xbox default.xbe, ai/AIActionWaitForInterval.cpp (2 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: COMPLETE. All 2 functions are matched.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] AIActionWaitForInterval::vfunc_05 (0x00120C30, 36 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as AIActionWaitForInterval::vfunc_06 (Proto 0x00105690), which was matched first;
// its addresses and names were swapped for this function's.
// AIActionWaitForInterval::vfunc_05 (Proto 0x00120C30, 36 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_004879E8;
extern "C" bool __cdecl sub_0011E190(void);

class AIActionWaitForInterval
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual int vfunc_05();
    char m_pad04[0x4];
    int m_Field08; // +0x08
};

int AIActionWaitForInterval::vfunc_05()
{
    if (sub_0011E190()) {
        if (*(int*)(DAT_004879E8 + 44) < m_Field08) goto L_20;
        return 1;
    }
L_20:
    return 0;
}

// ============================================================================
// [VERIFIED] AIActionWaitForInterval::vfunc_02 (0x00120C60, 15 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as AIActionWaitForInterval::vfunc_02 (Proto 0x001056C0), which was matched first;
// its addresses and names were swapped for this function's.
// AIActionWaitForInterval::vfunc_02 (Proto 0x00120C60, 15 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_004879E8;

class AIActionWaitForInterval
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual int vfunc_02();
    char m_pad04[0x4];
    int m_Field08; // +0x08
    int m_Field0C; // +0x0C
};

int AIActionWaitForInterval::vfunc_02()
{
    int t1;

    t1 = DAT_004879E8;
    m_Field08 = *(int*)(DAT_004879E8 + 44) + m_Field0C;
    return t1;
}

