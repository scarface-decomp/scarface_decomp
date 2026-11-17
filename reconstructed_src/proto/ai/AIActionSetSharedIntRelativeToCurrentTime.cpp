// ============================================================================
// SCARFACE: THE WORLD IS YOURS — April 2006 prototype game.xbe, ai/AIActionSetSharedIntRelativeToCurrentTime.cpp (2 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: COMPLETE. All 2 functions are matched.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] AIActionSetSharedIntRelativeToCurrentTime::vfunc_07 (0x00105770, 39 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// AIActionSetSharedIntRelativeToCurrentTime::vfunc_07 (Proto 0x00105770, 39 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field08
{
    void sub_00105250(int);
};

struct Field0A
{
    int sub_00105220();
};

extern "C" int DAT_0045A0EC;

class AIActionSetSharedIntRelativeToCurrentTime
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
    Field08 m_Field08; // +0x08
    char m_pad09[0x1];
    Field0A m_Field0A; // +0x0A
};

int AIActionSetSharedIntRelativeToCurrentTime::vfunc_07()
{
    int t2;

    t2 = *(int*)(DAT_0045A0EC + 44);
    m_Field08.sub_00105250(m_Field0A.sub_00105220() + t2);
    return 1;
}

// ============================================================================
// [VERIFIED] AIActionSetSharedIntRelativeToCurrentTime::vfunc_00 (0x00105EB0, 47 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// AIActionSetSharedIntRelativeToCurrentTime::vfunc_00 (Proto 0x00105EB0, 47 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field0A
{
    void sub_00105140();
};

extern "C" char DAT_0038C664[];
extern "C" void __cdecl sub_00025160(int);

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
    m_Field0A.sub_00105140();
    m_Field08.sub_00105140();
    *(int*)this = (int)DAT_0038C664;
    if (a1 & 1) {
        sub_00025160((int)this);
    }
    return this;
}

