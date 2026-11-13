// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail Xbox default.xbe, engine/SaveGameManagerFlowClient.cpp (2 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: COMPLETE. All 2 functions are matched.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] SaveGameManagerFlowClient::vfunc_02 (0x000C6580, 48 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// SaveGameManagerFlowClient::vfunc_02 (0x000C6580, 48 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_000C9D10(int);
    void sub_0022D590(int);
};

extern "C" int DAT_00486E5C;
extern "C" int DAT_00486E60;
extern "C" void __cdecl sub_002A9290(...);

class SaveGameManagerFlowClient
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02(int a1, int a2, int a3);
};

void SaveGameManagerFlowClient::vfunc_02(int a1, int a2, int a3)
{
    sub_002A9290(6);
    ((Object*)DAT_00486E60)->sub_0022D590(a1);
    ((Object*)DAT_00486E5C)->sub_000C9D10(a1);
    sub_002A9290();
}

// ============================================================================
// [VERIFIED] SaveGameManagerFlowClient::vfunc_00 (0x000C6730, 36 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as CollisionBehaviourTypeGroup::vfunc_01 (0x00013840), which was matched first;
// its addresses and names were swapped for this function's.
// SaveGameManagerFlowClient::vfunc_00 (0x000C6730, 36 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_003A53DC[];
extern "C" void __cdecl sub_00027600(int);
extern "C" void __cdecl sub_000EA330(void);

class SaveGameManagerFlowClient
{
public:
    virtual void vfunc_00();
    virtual SaveGameManagerFlowClient* vfunc_00(int a1);
};

SaveGameManagerFlowClient* SaveGameManagerFlowClient::vfunc_00(int a1)
{
    *(int*)this = (int)DAT_003A53DC;
    sub_000EA330();
    if (a1 & 1) {
        sub_00027600((int)this);
    }
    return this;
}

