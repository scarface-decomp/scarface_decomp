// ============================================================================
// SCARFACE: THE WORLD IS YOURS — April 2006 prototype game.xbe, engine/SkidMarksHandle.cpp (1 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: COMPLETE. All 1 functions are matched.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] renderer::SkidMarksHandle::vfunc_00 (0x00040C50, 53 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as renderer::SkidMarksHandle::vfunc_00 (0x00047DF0), which was matched first;
// its addresses and names were swapped for this function's.
// renderer::SkidMarksHandle::vfunc_00 (0x00040C50, 53 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field10
{
    void sub_000504C0();
};

extern "C" char DAT_0037F738[];
extern "C" void __cdecl sub_00025160(int);

namespace renderer {

class SkidMarksHandle
{
public:
    virtual SkidMarksHandle* vfunc_00(int a1);
    void sub_00040B80();
    int m_Field04; // +0x04
    char m_pad08[0x8];
    Field10 m_Field10; // +0x10
};

SkidMarksHandle* SkidMarksHandle::vfunc_00(int a1)
{
    *(int*)this = (int)DAT_0037F738;
    m_Field04 = 0;
    m_Field10.sub_000504C0();
    sub_00040B80();
    if (a1 & 1) {
        sub_00025160((int)this);
    }
    return this;
}

}

