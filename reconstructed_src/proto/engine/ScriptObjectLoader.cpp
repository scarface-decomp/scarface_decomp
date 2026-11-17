// ============================================================================
// SCARFACE: THE WORLD IS YOURS — April 2006 prototype game.xbe, engine/ScriptObjectLoader.cpp (2 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: COMPLETE. All 2 functions are matched.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] ScriptObjectLoader::vfunc_03 (0x0002A0A0, 58 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// ScriptObjectLoader::vfunc_03 (Proto 0x0002A0A0, 58 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_00029460();
};

extern "C" char DAT_0037D85C[];
extern "C" char DAT_0037F0AC[];
extern "C" int DAT_00449518;
extern "C" void __cdecl sub_001FCF60(int);

class ScriptObjectLoader
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual ScriptObjectLoader* vfunc_03(int a1);
};

ScriptObjectLoader* ScriptObjectLoader::vfunc_03(int a1)
{
    *(int*)this = (int)DAT_0037F0AC;
    ((Object*)DAT_00449518)->sub_00029460();
    DAT_00449518 = 0;
    *(int*)this = (int)DAT_0037D85C;
    if (a1 & 1) {
        sub_001FCF60((int)this);
    }
    return this;
}

// ============================================================================
// [VERIFIED] ScriptObjectLoader::vfunc_06 (0x0002A320, 34 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as ScriptObjectLoader::vfunc_06 (0x0002CE10), which was matched first;
// its addresses and names were swapped for this function's.
// ScriptObjectLoader::vfunc_06 (0x0002A320, 34 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_00449518;
extern "C" void __cdecl sub_0002A0E0(int, int, int, int, int);

class ScriptObjectLoader
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual void vfunc_05();
    virtual void vfunc_06(int a1, int a2, int a3, int a4);
};

void ScriptObjectLoader::vfunc_06(int a1, int a2, int a3, int a4)
{
    sub_0002A0E0(a1, a2, a3, DAT_00449518, 0);
}

