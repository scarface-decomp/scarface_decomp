// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail Xbox default.xbe, engine/NISScriptFunctionCallAction.cpp (2 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: COMPLETE. All 2 functions are matched.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] NISScriptFunctionCallAction::vfunc_07 (0x001808C0, 8 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as CollisionBehaviourTypeGroup::vfunc_04 (0x0002B700), which was matched first;
// its addresses and names were swapped for this function's.
// NISScriptFunctionCallAction::vfunc_07 (0x001808C0, 8 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __cdecl sub_0017EC90(void);

class NISScriptFunctionCallAction
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_07(int a1);
};

void NISScriptFunctionCallAction::vfunc_07(int a1)
{
    sub_0017EC90();
}

// ============================================================================
// [VERIFIED] NISScriptFunctionCallAction::vfunc_03 (0x001812D0, 57 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as BlendAction::vfunc_03 (0x000E3ED0), which was matched first;
// its addresses and names were swapped for this function's.
struct Child
{
    virtual void vfunc_00();
    virtual void vfunc_01();
};

extern "C" char DAT_003B6474[];
extern "C" void __cdecl sub_00027600(void* p);

class NISScriptFunctionCallAction
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual NISScriptFunctionCallAction* vfunc_03(unsigned int flags);
    void sub_000217F0();

    void* m_vtable_unused;
    Child* m_child; // +0x08
};

// Deleting destructor: releases the child it owns, runs the base destructor, frees itself when asked.
// The volatile accesses keep the vtable store ahead of the read, as the compiler does in a real destructor.
NISScriptFunctionCallAction* NISScriptFunctionCallAction::vfunc_03(unsigned int flags)
{
    *(void* volatile*)this = DAT_003B6474;
    Child* child = *(Child* volatile*)&m_child;
    if (child) {
        child->vfunc_01();
        m_child = 0;
    }
    sub_000217F0();
    if (flags & 1)
        sub_00027600(this);
    return this;
}

