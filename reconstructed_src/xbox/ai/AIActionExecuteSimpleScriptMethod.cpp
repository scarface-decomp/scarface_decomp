// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail Xbox default.xbe, ai/AIActionExecuteSimpleScriptMethod.cpp (2 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: COMPLETE. All 2 functions are matched.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] AIActionExecuteSimpleScriptMethod::vfunc_06 (0x00120CC0, 24 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as AIActionExecuteSimpleScriptMethod::vfunc_07 (Proto 0x00105720), which was matched first;
// its addresses and names were swapped for this function's.
// AIActionExecuteSimpleScriptMethod::vfunc_06 (Proto 0x00120CC0, 24 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __cdecl sub_00070470(int, int, int);

class AIActionExecuteSimpleScriptMethod
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
    int m_Field08; // +0x08
    int m_Field0C; // +0x0C
};

int AIActionExecuteSimpleScriptMethod::vfunc_06()
{
    sub_00070470(m_Field08, 1, m_Field0C);
    return 1;
}

// ============================================================================
// [VERIFIED] AIActionExecuteSimpleScriptMethod::vfunc_00 (0x001214A0, 44 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// What it does: AIActionExecuteSimpleScriptMethod's deleting destructor: destroys the object, frees its memory when asked (flag bit 0), and returns it.
// ============================================================================
// Same machine code as AIActionExecuteSimpleScriptMethod::vfunc_00 (Proto 0x00106050), which was matched first;
// its addresses and names were swapped for this function's.
// AIActionExecuteSimpleScriptMethod::vfunc_00 (Proto 0x001214A0, 44 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_003AAAC8[];
extern "C" void __cdecl sub_00027600(int);

class AIActionExecuteSimpleScriptMethod
{
public:
    virtual AIActionExecuteSimpleScriptMethod* vfunc_00(bool a1);
    char m_pad04[0x8];
    int m_Field0C; // +0x0C
};

AIActionExecuteSimpleScriptMethod* AIActionExecuteSimpleScriptMethod::vfunc_00(bool a1)
{
    sub_00027600(m_Field0C);
    *(int*)this = (int)DAT_003AAAC8;
    if (a1 & 1) {
        sub_00027600((int)this);
    }
    return this;
}

