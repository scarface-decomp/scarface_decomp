// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail Xbox default.xbe, pure3d/FeHardCodedString.cpp (1 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: COMPLETE. All 1 functions are matched.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] pure3d::frontend::FeHardCodedString::vfunc_01 (0x00249350, 53 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// pure3d::frontend::FeHardCodedString::vfunc_01 (0x00249350, 53 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.
#pragma optimize("y", off)

extern "C" char DAT_003D4F70[];
extern "C" char DAT_003D4F7C[];
extern "C" void __cdecl sub_00027600(int);

namespace pure3d { namespace frontend {

class FeHardCodedString
{
public:
    virtual void vfunc_00();
    virtual FeHardCodedString* vfunc_01(bool a1);
    int m_Field04; // +0x04
};

FeHardCodedString* FeHardCodedString::vfunc_01(bool a1)
{
    *(int*)this = (int)DAT_003D4F7C;
    sub_00027600(m_Field04);
    *(int*)this = (int)DAT_003D4F70;
    if (a1 & 1) {
        sub_00027600((int)this);
    }
    return this;
}

} }

