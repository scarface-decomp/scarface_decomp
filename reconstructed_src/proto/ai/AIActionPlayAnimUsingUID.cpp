// ============================================================================
// SCARFACE: THE WORLD IS YOURS — April 2006 prototype game.xbe, ai/AIActionPlayAnimUsingUID.cpp (2 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: COMPLETE. All 2 functions are matched.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] AIActionPlayAnimUsingUID::vfunc_02 (0x00105650, 19 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// AIActionPlayAnimUsingUID::vfunc_02 (Proto 0x00105650, 19 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field08
{
    void sub_0014C030(int, int, int);
};

class AIActionPlayAnimUsingUID
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

void AIActionPlayAnimUsingUID::vfunc_02()
{
    m_Field08->sub_0014C030((int)(&m_Field10), m_Field0C, 0);
}

// ============================================================================
// [VERIFIED] AIActionPlayAnimUsingUID::vfunc_00 (0x00105C50, 39 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as AIActionPlayAnimUsingUID::vfunc_00 (0x00121240), which was matched first;
// its addresses and names were swapped for this function's.
// AIActionPlayAnimUsingUID::vfunc_00 (0x00105C50, 39 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field10
{
    void sub_001B7A10();
};

extern "C" char DAT_0038C664[];
extern "C" void __cdecl sub_00025160(int);

class AIActionPlayAnimUsingUID
{
public:
    virtual AIActionPlayAnimUsingUID* vfunc_00(int a1);
    char m_pad04[0xC];
    Field10 m_Field10; // +0x10
};

AIActionPlayAnimUsingUID* AIActionPlayAnimUsingUID::vfunc_00(int a1)
{
    m_Field10.sub_001B7A10();
    *(int*)this = (int)DAT_0038C664;
    if (a1 & 1) {
        sub_00025160((int)this);
    }
    return this;
}

