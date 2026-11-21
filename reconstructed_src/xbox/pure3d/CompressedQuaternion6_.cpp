// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail Xbox default.xbe, pure3d/CompressedQuaternion6_.cpp (1 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 1 of 3 functions matched (33.33%). NOT COMPLETE YET.
// The 2 still to do are listed in their place in Original_Binary_Order_Xbox.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] pure3d::CompressedQuaternionChannel<math::CompressedQuaternion6>::vfunc_00 (0x0028A440, 46 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as pure3d::CompressedQuaternionChannel<math::CompressedQuaternion8>::vfunc_00 (0x0028A410), which was matched first;
// its addresses and names were swapped for this function's.
// bin: xb
// va: 0x0028A440
// what: Deleting destructor: puts back the class's vtable, runs its two destructors, then frees the object when asked to.
// tool: Claude Opus 5.5 (byte copy of the matched 0x0024A800 with its own addresses, examiner A6: ?$CompressedQuaternionChannel@VCompressedQuaternion8@math@@@pure3d::vfunc_00)
#pragma optimize("y", off)

extern "C" char DAT_003D83BC[];
extern "C" void __cdecl sub_00027600(int);
extern "C" void __cdecl sub_002884C0(void);

class Class_0028A440
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual Class_0028A440* sub_0028A440(int a1);
    void sub_00288B80();
};

Class_0028A440* Class_0028A440::sub_0028A440(int a1)
{
    *(int*)this = (int)DAT_003D83BC;
    sub_002884C0();
    sub_00288B80();
    if (a1 & 1) {
        sub_00027600((int)this);
    }
    return this;
}

