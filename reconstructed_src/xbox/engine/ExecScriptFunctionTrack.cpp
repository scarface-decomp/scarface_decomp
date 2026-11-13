// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail Xbox default.xbe, engine/ExecScriptFunctionTrack.cpp (2 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 2 of 3 functions matched (66.67%). NOT COMPLETE YET.
// The 1 still to do are listed in their place in Original_Binary_Order_Xbox.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] ExecScriptFunctionTrack::vfunc_20 (0x000E9BE0, 46 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// ExecScriptFunctionTrack::vfunc_20 (0x000E9BE0, 46 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    int sub_000E6080(int, int);
};

extern "C" int DAT_0041A400;
extern "C" int __cdecl sub_000275B0(int, int);

class ExecScriptFunctionTrack
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
    virtual void vfunc_11();
    virtual void vfunc_12();
    virtual void vfunc_13();
    virtual void vfunc_14();
    virtual void vfunc_15();
    virtual void vfunc_16();
    virtual void vfunc_17();
    virtual void vfunc_18();
    virtual void vfunc_19();
    virtual int vfunc_20(int a1);
};

int ExecScriptFunctionTrack::vfunc_20(int a1)
{
    int t2;

    t2 = sub_000275B0(24, DAT_0041A400);
    if (t2) {
        return ((Object*)t2)->sub_000E6080((int)this, a1);
    }
    return 0;
}

// ============================================================================
// [VERIFIED] ExecScriptFunctionTrack::vfunc_03 (0x000E9C30, 36 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as CollisionBehaviourTypeGroup::vfunc_01 (0x00013840), which was matched first;
// its addresses and names were swapped for this function's.
// ExecScriptFunctionTrack::vfunc_03 (0x000E9C30, 36 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_003A8EEC[];
extern "C" void __cdecl sub_0023F7A0(int);
extern "C" void __cdecl sub_00022970(void);

class ExecScriptFunctionTrack
{
public:
    virtual void vfunc_00();
    virtual ExecScriptFunctionTrack* vfunc_03(int a1);
};

ExecScriptFunctionTrack* ExecScriptFunctionTrack::vfunc_03(int a1)
{
    *(int*)this = (int)DAT_003A8EEC;
    sub_00022970();
    if (a1 & 1) {
        sub_0023F7A0((int)this);
    }
    return this;
}

