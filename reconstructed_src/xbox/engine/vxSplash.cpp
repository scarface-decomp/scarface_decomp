// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail Xbox default.xbe, engine/vxSplash.cpp (1 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: COMPLETE. All 1 functions are matched.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] vxSplash::vfunc_00 (0x002332C0, 73 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// vxSplash::vfunc_00 (0x002332C0, 73 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    virtual void vfunc_00();
    virtual void vfunc_01();
};

extern "C" char DAT_003D348C[];
extern "C" void __cdecl sub_00027600(int);

class vxSplash
{
public:
    virtual vxSplash* vfunc_00(int a1);
    int m_Field04; // +0x04
    char m_pad08[0x4];
    int m_Field0C; // +0x0C
};

vxSplash* vxSplash::vfunc_00(int a1)
{
    int t1, t3;

    t1 = m_Field04;
    *(int*)this = (int)DAT_003D348C;
    if (m_Field04) {
        sub_00027600(t1);
        m_Field04 = 0;
    }
    t3 = m_Field0C;
    if (m_Field0C) {
        ((Object*)t3)->vfunc_01();
        m_Field0C = 0;
    }
    if (a1 & 1) {
        sub_00027600((int)this);
    }
    return this;
}

