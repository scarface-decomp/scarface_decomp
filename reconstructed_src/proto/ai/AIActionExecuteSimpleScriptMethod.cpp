// ============================================================================
// SCARFACE: THE WORLD IS YOURS — April 2006 prototype game.xbe, ai/AIActionExecuteSimpleScriptMethod.cpp (2 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: COMPLETE. All 2 functions are matched.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] AIActionExecuteSimpleScriptMethod::vfunc_07 (0x00105720, 24 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// AIActionExecuteSimpleScriptMethod::vfunc_07 (Proto 0x00105720, 24 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __cdecl sub_00066030(int, int, int);

class AIActionExecuteSimpleScriptMethod
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual void vfunc_05();
    virtual void vfunc_06();
    virtual int vfunc_07();
    char m_pad04[0x4];
    int m_Field08; // +0x08
    int m_Field0C; // +0x0C
};

int AIActionExecuteSimpleScriptMethod::vfunc_07()
{
    sub_00066030(m_Field08, 1, m_Field0C);
    return 1;
}

// ============================================================================
// [VERIFIED] AIActionExecuteSimpleScriptMethod::vfunc_00 (0x00106050, 44 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// AIActionExecuteSimpleScriptMethod::vfunc_00 (Proto 0x00106050, 44 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0038C664[];
extern "C" void __cdecl sub_00025160(int);

class AIActionExecuteSimpleScriptMethod
{
public:
    virtual AIActionExecuteSimpleScriptMethod* vfunc_00(bool a1);
    char m_pad04[0x8];
    int m_Field0C; // +0x0C
};

AIActionExecuteSimpleScriptMethod* AIActionExecuteSimpleScriptMethod::vfunc_00(bool a1)
{
    sub_00025160(m_Field0C);
    *(int*)this = (int)DAT_0038C664;
    if (a1 & 1) {
        sub_00025160((int)this);
    }
    return this;
}

