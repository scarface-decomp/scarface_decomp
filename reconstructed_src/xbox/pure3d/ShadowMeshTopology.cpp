// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail Xbox default.xbe, pure3d/ShadowMeshTopology.cpp (1 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: COMPLETE. All 1 functions are matched.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] pure3d::ShadowMeshTopology::vfunc_03 (0x00257B20, 62 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as pure3d::ShadowMeshVertices::vfunc_03 (0x002579C0), which was matched first;
// its addresses and names were swapped for this function's.
// bin: xb
// va: 0x00257B20
// what: 
// tool: the portal's starter code (no AI)

// pure3d::ShadowMeshTopology::vfunc_03 (0x00257B20, 62 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.
// This function keeps a frame pointer (push ebp; mov ebp, esp), so it is built with them on.
#pragma optimize("y", off)

extern "C" char DAT_0039E22C[];
extern "C" char DAT_003D5910[];
extern "C" void __cdecl sub_00027600(int);

namespace pure3d {

class ShadowMeshTopology
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual ShadowMeshTopology* vfunc_03(bool a1);
    char m_pad04[0xC];
    int m_Field10; // +0x10
    int m_Field14; // +0x14
};

ShadowMeshTopology* ShadowMeshTopology::vfunc_03(bool a1)
{
    *(int*)this = (int)DAT_003D5910;
    sub_00027600(m_Field10);
    sub_00027600(m_Field14);
    *(int*)this = (int)DAT_0039E22C;
    if (a1 & 1) {
        sub_00027600((int)this);
    }
    return this;
}

}

