// ============================================================================
// SCARFACE: THE WORLD IS YOURS — April 2006 prototype game.xbe, pure3d/CompressedQuaternion6_.cpp (1 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 1 of 3 functions matched (33.33%). NOT COMPLETE YET.
// The 2 still to do are listed in their place in Original_Binary_Order_Proto.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] pure3d::CompressedQuaternionChannel<math::CompressedQuaternion6>::vfunc_00 (0x00246890, 43 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// pure3d::CompressedQuaternionChannel<math::CompressedQuaternion6>::vfunc_00 (Proto 0x00246890, 43 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_003B151C[];
extern "C" void __cdecl sub_00025160(int);
extern "C" void __cdecl sub_00246130(void);

namespace math { class CompressedQuaternion6; }

namespace pure3d { 
template <class T0> class CompressedQuaternionChannel
{
public:
    virtual CompressedQuaternionChannel<math::CompressedQuaternion6>* vfunc_00(int a1);
    void sub_00244E50();
};
}

template <> pure3d::CompressedQuaternionChannel<math::CompressedQuaternion6>* pure3d::CompressedQuaternionChannel<math::CompressedQuaternion6>::vfunc_00(int a1)
{
    *(int*)this = (int)DAT_003B151C;
    sub_00246130();
    sub_00244E50();
    if (a1 & 1) {
        sub_00025160((int)this);
    }
    return this;
}

