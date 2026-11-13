// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail Xbox default.xbe, engine/ColliderTracker_ScriptObjectPointer_GameObject____2_.cpp (1 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 1 of 2 functions matched (50.00%). NOT COMPLETE YET.
// The 1 still to do are listed in their place in Original_Binary_Order_Xbox.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] ColliderTracker<ScriptObjectPointer<GameObject*>, 2>::vfunc_01 (0x00089630, 21 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// ColliderTracker<ScriptObjectPointer<GameObject*>, 2>::vfunc_01 (0x00089630, 21 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_00098B90(int);
};

class ColliderTracker_ScriptObjectPointer_GameObject____2_
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01(int a1, int a2);
};

void ColliderTracker_ScriptObjectPointer_GameObject____2_::vfunc_01(int a1, int a2)
{
    ((Object*)(int)this + (a1 * 4) + 16)->sub_00098B90(a2);
}

