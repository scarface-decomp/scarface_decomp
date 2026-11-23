// ============================================================================
// SCARFACE: THE WORLD IS YOURS — April 2006 prototype game.xbe, ai/AIActionPlayAnim.cpp (2 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: COMPLETE. All 2 functions are matched.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] AIActionPlayAnim::vfunc_02 (0x00105620, 48 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// AIActionPlayAnim::vfunc_02 (Proto 0x00105620, 48 bytes)
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

class AIActionPlayAnim
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    char m_pad04[0x4];
    Field08* m_Field08; // +0x08
    int m_Field0C; // +0x0C
    int m_Field10; // +0x10
};

void AIActionPlayAnim::vfunc_02()
{
    int local_4;

    ((Object*)(int)(&local_4))->sub_00200310(m_Field10);
    m_Field08->sub_0014C030((int)(&local_4), m_Field0C, 0);
    ((Object*)(int)(&local_4))->sub_001B7A10();
}

// ============================================================================
// [VERIFIED] AIActionPlayAnim::vfunc_00 (0x00105BD0, 44 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// What it does: AIActionPlayAnim's deleting destructor: destroys the object, frees its memory when asked (flag bit 0), and returns it.
// ============================================================================
// AIActionPlayAnim::vfunc_00 (Proto 0x00105BD0, 44 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0038C664[];
extern "C" void __cdecl sub_00025160(int);

class AIActionPlayAnim
{
public:
    virtual AIActionPlayAnim* vfunc_00(bool a1);
    char m_pad04[0xC];
    int m_Field10; // +0x10
};

AIActionPlayAnim* AIActionPlayAnim::vfunc_00(bool a1)
{
    sub_00025160(m_Field10);
    *(int*)this = (int)DAT_0038C664;
    if (a1 & 1) {
        sub_00025160((int)this);
    }
    return this;
}

