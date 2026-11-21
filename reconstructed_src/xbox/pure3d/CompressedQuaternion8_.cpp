// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail Xbox default.xbe, pure3d/CompressedQuaternion8_.cpp (1 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 1 of 3 functions matched (33.33%). NOT COMPLETE YET.
// The 2 still to do are listed in their place in Original_Binary_Order_Xbox.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] pure3d::CompressedQuaternionChannel<math::CompressedQuaternion8>::vfunc_00 (0x0028A410, 46 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// What it does: Deleting destructor: puts back the class's vtable, runs its two destructors, then frees the object when asked to.
// ============================================================================
// bin: xb
// va: 0x0028A410
// what: Deleting destructor: puts back the class's vtable, runs its two destructors, then frees the object when asked to.
// tool: Claude Opus 5.5 (byte copy of the matched 0x0024A800 with its own addresses, examiner A6: ?$CompressedQuaternionChannel@VCompressedQuaternion8@math@@@pure3d::vfunc_00)
#pragma optimize("y", off)

extern "C" char DAT_003D839C[];
extern "C" void __cdecl sub_00027600(int);
extern "C" void __cdecl sub_002884C0(void);

class Class_0028A410
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual Class_0028A410* sub_0028A410(int a1);
    void sub_00288B80();
};

Class_0028A410* Class_0028A410::sub_0028A410(int a1)
{
    *(int*)this = (int)DAT_003D839C;
    sub_002884C0();
    sub_00288B80();
    if (a1 & 1) {
        sub_00027600((int)this);
    }
    return this;
}

