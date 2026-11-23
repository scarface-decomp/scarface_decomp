// ============================================================================
// SCARFACE: THE WORLD IS YOURS — April 2006 prototype game.xbe, engine/NISSequenceBranchAction.cpp (3 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: COMPLETE. All 3 functions are matched.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] NISSequenceBranchAction::vfunc_03 (0x0015F900, 46 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as NISSequenceCueAction::vfunc_03 (0x00180C30), which was matched first;
// its addresses and names were swapped for this function's.
// NISSequenceBranchAction::vfunc_03 (0x0015F900, 46 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    virtual void vfunc_00();
    virtual void vfunc_01();
};

extern "C" char DAT_00393F58[];
extern "C" void __cdecl sub_00025160(int);

class NISSequenceBranchAction
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual NISSequenceBranchAction* vfunc_03(int a1);
    void sub_0001F600();
    char m_pad04[0x4];
    int m_Field08; // +0x08
};

NISSequenceBranchAction* NISSequenceBranchAction::vfunc_03(int a1)
{
    int t1;

    t1 = m_Field08;
    *(int*)this = (int)DAT_00393F58;
    ((Object*)t1)->vfunc_01();
    sub_0001F600();
    if (a1 & 1) {
        sub_00025160((int)this);
    }
    return this;
}

// ============================================================================
// [VERIFIED] NISSequenceBranchAction::vfunc_06 (0x0015FB90, 36 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// bin: proto
// va: 0x0015FB90
// what: 
// tool: the portal's starter code (no AI)

// NISSequenceBranchAction::vfunc_06 (Proto 0x0015FB90, 36 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field08
{
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual void vfunc_05();
    virtual void vfunc_06();
    virtual void vfunc_07();
    virtual void vfunc_08();
    virtual void vfunc_09();
    virtual void vfunc_10();
    virtual void vfunc_11();
    virtual void vfunc_12();
    virtual void vfunc_13();
    virtual void vfunc_14();
    virtual void vfunc_15();
    virtual void vfunc_16();
    virtual void vfunc_17();
    virtual void vfunc_18();
    virtual void vfunc_19();
    virtual void vfunc_20();
    virtual void vfunc_21();
    virtual void vfunc_22();
    virtual float vfunc_23();
};

extern "C" float DAT_00384DBC;

class NISSequenceBranchAction
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual void vfunc_05();
    virtual int vfunc_06(int a1);
    bool sub_0015F930();
    char m_pad04[0x4];
    Field08* m_Field08; // +0x08
    char m_pad0C[0x4];
    float m_Field10; // +0x10
};

int NISSequenceBranchAction::vfunc_06(int a1)
{
    m_Field10 = m_Field08->vfunc_23() * DAT_00384DBC;
    return !sub_0015F930();
}

// ============================================================================
// [VERIFIED] NISSequenceBranchAction::vfunc_11 (0x0015FBC0, 13 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// bin: proto
// va: 0x0015FBC0
// what: 
// tool: the portal's starter code (no AI)

// NISSequenceBranchAction::vfunc_11 (Proto 0x0015FBC0, 13 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" bool __cdecl sub_0015F930(void);

class NISSequenceBranchAction
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual void vfunc_05();
    virtual void vfunc_06();
    virtual void vfunc_07();
    virtual void vfunc_08();
    virtual void vfunc_09();
    virtual void vfunc_10();
    virtual int vfunc_11(int a1);
};

int NISSequenceBranchAction::vfunc_11(int a1)
{
    return !sub_0015F930();
}

