// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail Xbox default.xbe, engine/Branch.cpp (1 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 1 of 5 functions matched (20.00%). NOT COMPLETE YET.
// The 4 still to do are listed in their place in Original_Binary_Order_Xbox.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] fight::Branch::vfunc_03 (0x0023B160, 33 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// What it does: Deleting destructor: destroys the branch, frees it when asked, and returns it.
// ============================================================================
extern "C" void __cdecl sub_0023F7A0(void* p);

namespace fight {

class Branch
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual Branch* vfunc_03(unsigned int flags);
    void sub_0023AD60();
};

#pragma optimize("y", off)
Branch* Branch::vfunc_03(unsigned int flags)
{
    sub_0023AD60();
    if (flags & 1)
        sub_0023F7A0(this);
    return this;
}
#pragma optimize("", on)

}

