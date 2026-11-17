// ============================================================================
// SCARFACE: THE WORLD IS YOURS — April 2006 prototype game.xbe, ai/AIActionTriggerPhysicalState.cpp (1 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: COMPLETE. All 1 functions are matched.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] AIActionTriggerPhysicalState::vfunc_07 (0x00105920, 56 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// AIActionTriggerPhysicalState::vfunc_07 (Proto 0x00105920, 56 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field08
{
    void sub_0014C030(int, int, int);
};

struct Object
{
    void sub_001B7A10();
    void sub_00200310(int);
};

extern "C" int DAT_0040AA24;

class AIActionTriggerPhysicalState
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
    Field08* m_Field08; // +0x08
    int m_Field0C; // +0x0C
};

int AIActionTriggerPhysicalState::vfunc_07()
{
    int local_4;

    ((Object*)(int)(&local_4))->sub_00200310(m_Field0C);
    m_Field08->sub_0014C030((int)(&local_4), DAT_0040AA24, 0);
    ((Object*)(int)(&local_4))->sub_001B7A10();
    return 1;
}

