// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail Xbox default.xbe, engine/SkidMarksHandle.cpp (1 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: COMPLETE. All 1 functions are matched.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] renderer::SkidMarksHandle::vfunc_00 (0x00047DF0, 53 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// renderer::SkidMarksHandle::vfunc_00 (0x00047DF0, 53 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field10
{
    void sub_0005AA90();
};

extern "C" char DAT_003A042C[];
extern "C" void __cdecl sub_00027600(int);

namespace renderer {

class SkidMarksHandle
{
public:
    virtual SkidMarksHandle* vfunc_00(int a1);
    void sub_00047D70();
    int m_Field04; // +0x04
    char m_pad08[0x8];
    Field10 m_Field10; // +0x10
};

SkidMarksHandle* SkidMarksHandle::vfunc_00(int a1)
{
    *(int*)this = (int)DAT_003A042C;
    m_Field04 = 0;
    m_Field10.sub_0005AA90();
    sub_00047D70();
    if (a1 & 1) {
        sub_00027600((int)this);
    }
    return this;
}

}

