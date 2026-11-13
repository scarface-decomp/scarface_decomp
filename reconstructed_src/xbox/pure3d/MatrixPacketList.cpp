// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail Xbox default.xbe, pure3d/MatrixPacketList.cpp (1 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: COMPLETE. All 1 functions are matched.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] pure3d::pddiExtInstancing::MatrixPacketList::vfunc_00 (0x0026A8E0, 47 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// pure3d::pddiExtInstancing::MatrixPacketList::vfunc_00 (0x0026A8E0, 47 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.
#pragma optimize("y", off)

struct Field04
{
    void sub_00241900();
};

extern "C" char DAT_003D68AC[];
extern "C" void __cdecl sub_00027600(int);
extern "C" void __cdecl sub_002640A0(void);

namespace pure3d { namespace pddiExtInstancing {

class MatrixPacketList
{
public:
    virtual MatrixPacketList* vfunc_00(int a1);
    Field04 m_Field04; // +0x04
};

MatrixPacketList* MatrixPacketList::vfunc_00(int a1)
{
    *(int*)this = (int)DAT_003D68AC;
    sub_002640A0();
    m_Field04.sub_00241900();
    if (a1 & 1) {
        sub_00027600((int)this);
    }
    return this;
}

} }

