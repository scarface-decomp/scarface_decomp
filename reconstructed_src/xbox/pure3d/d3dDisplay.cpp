// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail Xbox default.xbe, pure3d/d3dDisplay.cpp (1 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 1 of 16 functions matched (6.25%). NOT COMPLETE YET.
// The 15 still to do are listed in their place in Original_Binary_Order_Xbox.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] pure3d::d3dDisplay::vfunc_03 (0x0029B150, 75 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// pure3d::d3dDisplay::vfunc_03 (0x0029B150, 75 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.
#pragma optimize("y", off)

extern "C" char DAT_003D95F4[];
extern "C" char DAT_003D9674[];
extern "C" void __cdecl sub_00027600(int);
extern "C" void __cdecl sub_00329920(void);
extern "C" void __stdcall sub_0032C6D0(int);

namespace pure3d {

class d3dDisplay
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual d3dDisplay* vfunc_03(int a1);
    void sub_002A06C0();
    char m_pad04[0xC];
    int m_Field10; // +0x10
    char m_pad14[0x484];
    int m_Field498; // +0x498
};

d3dDisplay* d3dDisplay::vfunc_03(int a1)
{
    int t2;

    *(int*)this = (int)DAT_003D9674;
    if (m_Field10) {
        sub_00329920();
    }
    t2 = m_Field498;
    if (m_Field498) {
        sub_0032C6D0(t2);
    }
    *(int*)this = (int)DAT_003D95F4;
    sub_002A06C0();
    if (a1 & 1) {
        sub_00027600((int)this);
    }
    return this;
}

}

