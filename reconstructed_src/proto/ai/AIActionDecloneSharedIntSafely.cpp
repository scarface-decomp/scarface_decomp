// ============================================================================
// SCARFACE: THE WORLD IS YOURS — April 2006 prototype game.xbe, ai/AIActionDecloneSharedIntSafely.cpp (2 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: COMPLETE. All 2 functions are matched.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] AIActionDecloneSharedIntSafely::vfunc_07 (0x00105820, 48 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// AIActionDecloneSharedIntSafely::vfunc_07 (Proto 0x00105820, 48 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field08
{
    int sub_00148D30();
};

struct Field0C
{
    void sub_001051D0();
    bool sub_00105320();
};

struct Object
{
    void sub_000DDE30();
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
    virtual void vfunc_06();
    virtual int vfunc_07();
    char m_pad04[0x4];
    Field08* m_Field08; // +0x08
    Field0C m_Field0C; // +0x0C
};

int AIActionDecloneSharedIntSafely::vfunc_07()
{
    if (m_Field0C.sub_00105320()) {
        ((Object*)m_Field08->sub_00148D30())->sub_000DDE30();
        m_Field0C.sub_001051D0();
    }
    return 1;
}

// ============================================================================
// [VERIFIED] AIActionDecloneSharedIntSafely::vfunc_00 (0x00105F80, 39 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// AIActionDecloneSharedIntSafely::vfunc_00 (Proto 0x00105F80, 39 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field0C
{
    void sub_00105140();
};

extern "C" char DAT_0038C664[];
extern "C" void __cdecl sub_00025160(int);

class AIActionDecloneSharedIntSafely
{
public:
    virtual AIActionDecloneSharedIntSafely* vfunc_00(int a1);
    char m_pad04[0x8];
    Field0C m_Field0C; // +0x0C
};

AIActionDecloneSharedIntSafely* AIActionDecloneSharedIntSafely::vfunc_00(int a1)
{
    m_Field0C.sub_00105140();
    *(int*)this = (int)DAT_0038C664;
    if (a1 & 1) {
        sub_00025160((int)this);
    }
    return this;
}

