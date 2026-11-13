// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail Xbox default.xbe, pure3d/Partition.cpp (1 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: COMPLETE. All 1 functions are matched.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] pure3d::Skeleton::Partition::vfunc_00 (0x002788A0, 50 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// pure3d::Skeleton::Partition::vfunc_00 (0x002788A0, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.
#pragma optimize("y", off)

extern "C" char DAT_003D7758[];
extern "C" void __cdecl sub_00027600(int);

namespace pure3d { namespace Skeleton {

class Partition
{
public:
    virtual Partition* vfunc_00(int a1);
    char m_pad04[0x4];
    int m_Field08; // +0x08
};

Partition* Partition::vfunc_00(int a1)
{
    int t1;

    t1 = m_Field08;
    *(int*)this = (int)DAT_003D7758;
    if (m_Field08) {
        sub_00027600(t1);
    }
    if (a1 & 1) {
        sub_00027600((int)this);
    }
    return this;
}

} }

