// ============================================================================
// SCARFACE: THE WORLD IS YOURS — April 2006 prototype game.xbe, engine/AIConditionGameTimeIsAtLeast.cpp (2 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: COMPLETE. All 2 functions are matched.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] AIConditionGameTimeIsAtLeast::vfunc_04 (0x001062A0, 28 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// AIConditionGameTimeIsAtLeast::vfunc_04 (Proto 0x001062A0, 28 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    int sub_00105220();
};

extern "C" int DAT_0045A0EC;

class AIConditionGameTimeIsAtLeast
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual bool vfunc_04();
};

bool AIConditionGameTimeIsAtLeast::vfunc_04()
{
    int t2;

    t2 = *(int*)(DAT_0045A0EC + 44);
    return t2 >= ((Object*)(int)this + 8)->sub_00105220();
}

// ============================================================================
// [VERIFIED] AIConditionGameTimeIsAtLeast::vfunc_03 (0x00106850, 39 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as AIActionSetSharedIntToRandom::vfunc_00 (0x00121540), which was matched first;
// its addresses and names were swapped for this function's.
// AIConditionGameTimeIsAtLeast::vfunc_03 (0x00106850, 39 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field08
{
    void sub_00105140();
};

extern "C" char DAT_0037D85C[];
extern "C" void __cdecl sub_00025160(int);

class AIConditionGameTimeIsAtLeast
{
public:
    virtual AIConditionGameTimeIsAtLeast* vfunc_03(int a1);
    char m_pad04[0x4];
    Field08 m_Field08; // +0x08
};

AIConditionGameTimeIsAtLeast* AIConditionGameTimeIsAtLeast::vfunc_03(int a1)
{
    m_Field08.sub_00105140();
    *(int*)this = (int)DAT_0037D85C;
    if (a1 & 1) {
        sub_00025160((int)this);
    }
    return this;
}

