// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail Xbox default.xbe, engine/BlendAction.cpp (1 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 1 of 2 functions matched (50.00%). NOT COMPLETE YET.
// The 1 still to do are listed in their place in Original_Binary_Order_Xbox.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] BlendAction::vfunc_03 (0x000E3ED0, 57 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// What it does: Deleting destructor: releases the child action, runs the base destructor, frees the object when asked.
// ============================================================================
struct Child
{
    virtual void vfunc_00();
    virtual void vfunc_01();
};

extern "C" char DAT_003A7804[];
extern "C" void __cdecl sub_00027600(void* p);

class BlendAction
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual BlendAction* vfunc_03(unsigned int flags);
    void sub_000217F0();

    void* m_vtable_unused;
    Child* m_child; // +0x08
};

// Deleting destructor: releases the child it owns, runs the base destructor, frees itself when asked.
// The volatile accesses keep the vtable store ahead of the read, as the compiler does in a real destructor.
BlendAction* BlendAction::vfunc_03(unsigned int flags)
{
    *(void* volatile*)this = DAT_003A7804;
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

