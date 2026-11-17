// ============================================================================
// SCARFACE: THE WORLD IS YOURS — April 2006 prototype game.xbe, engine/NISScriptFunctionCallAction.cpp (2 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: COMPLETE. All 2 functions are matched.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] NISScriptFunctionCallAction::vfunc_06 (0x0015E230, 45 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// NISScriptFunctionCallAction::vfunc_06 (Proto 0x0015E230, 45 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __cdecl sub_00065ED0(int, int, int, int, int);

class NISScriptFunctionCallAction
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual void vfunc_05();
    virtual bool vfunc_06(int a1);
    char m_pad04[0x4];
    int m_Field08; // +0x08
    bool m_Field0C; // +0x0C
};

bool NISScriptFunctionCallAction::vfunc_06(int a1)
{
    int t1;

    t1 = m_Field08;
    if (m_Field08) {
        sub_00065ED0(t1 + 20, 0, 0, 0, -1);
        m_Field0C = true;
        return true;
    }
    return true;
}

// ============================================================================
// [VERIFIED] NISScriptFunctionCallAction::vfunc_03 (0x0015FAB0, 57 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as BlendAction::vfunc_03 (0x000E3ED0), which was matched first;
// its addresses and names were swapped for this function's.
struct Child
{
    virtual void vfunc_00();
    virtual void vfunc_01();
};

extern "C" char DAT_00394028[];
extern "C" void __cdecl sub_00025160(void* p);

class NISScriptFunctionCallAction
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual NISScriptFunctionCallAction* vfunc_03(unsigned int flags);
    void sub_0001F600();

    void* m_vtable_unused;
    Child* m_child; // +0x08
};

// Deleting destructor: releases the child it owns, runs the base destructor, frees itself when asked.
// The volatile accesses keep the vtable store ahead of the read, as the compiler does in a real destructor.
NISScriptFunctionCallAction* NISScriptFunctionCallAction::vfunc_03(unsigned int flags)
{
    *(void* volatile*)this = DAT_00394028;
    Child* child = *(Child* volatile*)&m_child;
    if (child) {
        child->vfunc_01();
        m_child = 0;
    }
    sub_0001F600();
    if (flags & 1)
        sub_00025160(this);
    return this;
}

