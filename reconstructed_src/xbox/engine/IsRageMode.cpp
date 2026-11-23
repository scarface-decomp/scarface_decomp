// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail Xbox default.xbe, engine/IsRageMode.cpp (2 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: COMPLETE. All 2 functions are matched.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] IsRageMode::vfunc_15 (0x000DD590, 40 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as IsRageMode::vfunc_15 (Proto 0x000CB840), which was matched first;
// its addresses and names were swapped for this function's.
// IsRageMode::vfunc_15 (Proto 0x000DD590, 40 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" bool __cdecl sub_00177540(void);
extern "C" bool __cdecl sub_00177560(void);
extern "C" bool __cdecl sub_00177580(void);

class IsRageMode
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
    virtual int vfunc_15(int a1, int a2);
};

int IsRageMode::vfunc_15(int a1, int a2)
{
    if (sub_00177540()) {
        if (sub_00177560()) goto L_23;
        if (sub_00177580()) goto L_23;
        return 1;
    }
L_23:
    return 0;
}

// ============================================================================
// [VERIFIED] IsRageMode::vfunc_03 (0x000DDCE0, 36 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// What it does: IsRageMode's deleting destructor: destroys the object, frees its memory when asked (flag bit 0), and returns it.
// ============================================================================
// Same machine code as CollisionBehaviourTypeGroup::vfunc_01 (0x00013840), which was matched first;
// its addresses and names were swapped for this function's.
// IsRageMode::vfunc_03 (0x000DDCE0, 36 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_003A6B6C[];
extern "C" void __cdecl sub_0023F7A0(int);
extern "C" void __cdecl sub_00021870(void);

class IsRageMode
{
public:
    virtual void vfunc_00();
    virtual IsRageMode* vfunc_03(int a1);
};

IsRageMode* IsRageMode::vfunc_03(int a1)
{
    *(int*)this = (int)DAT_003A6B6C;
    sub_00021870();
    if (a1 & 1) {
        sub_0023F7A0((int)this);
    }
    return this;
}

