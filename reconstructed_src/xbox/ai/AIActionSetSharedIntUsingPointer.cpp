// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail Xbox default.xbe, ai/AIActionSetSharedIntUsingPointer.cpp (1 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: COMPLETE. All 1 functions are matched.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] AIActionSetSharedIntUsingPointer::vfunc_06 (0x00120DA0, 20 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as AIActionSetSharedIntUsingPointer::vfunc_07 (Proto 0x00105800), which was matched first;
// its addresses and names were swapped for this function's.
// AIActionSetSharedIntUsingPointer::vfunc_06 (Proto 0x00120DA0, 20 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_001206D0(int);
};

class AIActionSetSharedIntUsingPointer
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual void vfunc_05();
    virtual int vfunc_06();
    char m_pad04[0x8];
    int m_Field0C; // +0x0C
};

int AIActionSetSharedIntUsingPointer::vfunc_06()
{
    ((Object*)(int)this + 8)->sub_001206D0(*(int*)m_Field0C);
    return 1;
}

