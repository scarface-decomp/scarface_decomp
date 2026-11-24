// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail Xbox default.xbe, pure3d/BoneMatrixList.cpp (1 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: COMPLETE. All 1 functions are matched.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] pure3d::BoneMatrixList::vfunc_03 (0x00292CF0, 80 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// bin: xb
// va: 0x00292CF0
// what: 
// tool: the portal's starter code (no AI)

// pure3d::BoneMatrixList::vfunc_03 (0x00292CF0, 80 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.
// This function keeps a frame pointer (push ebp; mov ebp, esp), so it is built with them on.
#pragma optimize("y", off)

extern "C" char DAT_0039E22C[];
extern "C" char DAT_003D8D3C[];
extern "C" void __cdecl sub_00027600(int);

namespace pure3d {

class BoneMatrixList
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual BoneMatrixList* vfunc_03(bool a1);
    char m_pad04[0x8];
    int m_Field0C; // +0x0C
    int m_Field10; // +0x10
    int m_Field14; // +0x14
    int m_Field18; // +0x18
};

BoneMatrixList* BoneMatrixList::vfunc_03(bool a1)
{
    *(int*)this = (int)DAT_003D8D3C;
    sub_00027600(m_Field0C);
    sub_00027600(m_Field10);
    sub_00027600(m_Field14);
    sub_00027600(m_Field18);
    *(int*)this = (int)DAT_0039E22C;
    if (a1 & 1) {
        sub_00027600((int)this);
    }
    return this;
}

}

