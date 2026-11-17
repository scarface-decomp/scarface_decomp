// ============================================================================
// SCARFACE: THE WORLD IS YOURS — April 2006 prototype game.xbe, engine/SaveGameManagerFlowClient.cpp (2 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: COMPLETE. All 2 functions are matched.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] SaveGameManagerFlowClient::vfunc_02 (0x000B8A10, 14 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// SaveGameManagerFlowClient::vfunc_02 (Proto 0x000B8A10, 14 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_000BA9A0();
};

extern "C" int DAT_0045950C;

class SaveGameManagerFlowClient
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02(int a1, int a2, int a3);
};

void SaveGameManagerFlowClient::vfunc_02(int a1, int a2, int a3)
{
    ((Object*)DAT_0045950C)->sub_000BA9A0();
}

// ============================================================================
// [VERIFIED] SaveGameManagerFlowClient::vfunc_00 (0x000B8B10, 36 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as CollisionBehaviourTypeGroup::vfunc_01 (0x00013840), which was matched first;
// its addresses and names were swapped for this function's.
// SaveGameManagerFlowClient::vfunc_00 (0x000B8B10, 36 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_003847CC[];
extern "C" void __cdecl sub_00025160(int);
extern "C" void __cdecl sub_000D7D00(void);

class SaveGameManagerFlowClient
{
public:
    virtual void vfunc_00();
    virtual SaveGameManagerFlowClient* vfunc_00(int a1);
};

SaveGameManagerFlowClient* SaveGameManagerFlowClient::vfunc_00(int a1)
{
    *(int*)this = (int)DAT_003847CC;
    sub_000D7D00();
    if (a1 & 1) {
        sub_00025160((int)this);
    }
    return this;
}

