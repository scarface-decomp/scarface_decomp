// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail Xbox default.xbe, engine/VehicleRenderMaskBehaviour.cpp (1 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 1 of 3 functions matched (33.33%). NOT COMPLETE YET.
// The 2 still to do are listed in their place in Original_Binary_Order_Xbox.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] VehicleRenderMaskBehaviour::vfunc_00 (0x000B6E70, 65 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// VehicleRenderMaskBehaviour::vfunc_00 (0x000B6E70, 65 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_003A5080[];
extern "C" void __cdecl sub_00027600(int);
extern "C" void __cdecl sub_00048680(int);

class VehicleRenderMaskBehaviour
{
public:
    virtual VehicleRenderMaskBehaviour* vfunc_00(int a1);
    void sub_000AACC0();
    char m_pad04[0x8];
    int m_Field0C; // +0x0C
};

VehicleRenderMaskBehaviour* VehicleRenderMaskBehaviour::vfunc_00(int a1)
{
    *(int*)this = (int)DAT_003A5080;
    if (m_Field0C) {
        sub_00048680((int)(&m_Field0C));
        m_Field0C = 0;
    }
    sub_000AACC0();
    if (a1 & 1) {
        sub_00027600((int)this);
    }
    return this;
}

