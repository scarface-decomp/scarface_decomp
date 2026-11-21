// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail Xbox default.xbe, engine/EnterExitScriptTrack_.cpp (1 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 1 of 2 functions matched (50.00%). NOT COMPLETE YET.
// The 1 still to do are listed in their place in Original_Binary_Order_Xbox.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] fight::ParamString<fight::EnterExitScriptTrack>::vfunc_00 (0x0023E8B0, 33 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// What it does: Deleting destructor: runs the destructor, then frees the object when asked to.
// ============================================================================
// bin: xb
// va: 0x0023E8B0
// what: Deleting destructor: runs the destructor, then frees the object when asked to.
// tool: Claude Opus 5.5 (byte copy of the matched 0x0023B160 with its own addresses, examiner A6: ?$ParamString@VEnterExitScriptTrack@fight@@@fight::vfunc_00)

extern "C" void __cdecl sub_00027600(void* p);

class Class_0023E8B0
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual Class_0023E8B0* sub_0023E8B0(unsigned int flags);
    void sub_0023EA70();
};

#pragma optimize("y", off)
Class_0023E8B0* Class_0023E8B0::sub_0023E8B0(unsigned int flags)
{
    sub_0023EA70();
    if (flags & 1)
        sub_00027600(this);
    return this;
}
#pragma optimize("", on)

