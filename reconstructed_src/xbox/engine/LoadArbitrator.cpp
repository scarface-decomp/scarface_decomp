// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail Xbox default.xbe, engine/LoadArbitrator.cpp (2 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: COMPLETE. All 2 functions are matched.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] LoadArbitrator::vfunc_02 (0x0022C100, 37 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// LoadArbitrator::vfunc_02 (0x0022C100, 37 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __cdecl sub_002A9290(...);

class LoadArbitrator
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02(int a1, int a2, int a3);
    char m_pad04[0x4];
    int m_Field08; // +0x08
};

void LoadArbitrator::vfunc_02(int a1, int a2, int a3)
{
    sub_002A9290(2);
    if (m_Field08 == 7) {
        m_Field08 = 0;
    }
    sub_002A9290();
}

// ============================================================================
// [VERIFIED] LoadArbitrator::vfunc_00 (0x0022C130, 53 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// LoadArbitrator::vfunc_00 (0x0022C130, 53 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_003D22A0[];
extern "C" char DAT_003D22A8[];
extern "C" int DAT_00491FD8;
extern "C" void __cdecl sub_00027600(int);
extern "C" void __cdecl sub_000EA330(void);

class LoadArbitrator
{
public:
    virtual LoadArbitrator* vfunc_00(int a1);
    int m_Field04; // +0x04
};

LoadArbitrator* LoadArbitrator::vfunc_00(int a1)
{
    *(int*)this = (int)DAT_003D22A8;
    m_Field04 = (int)DAT_003D22A0;
    DAT_00491FD8 = -0x22222223;
    sub_000EA330();
    if (a1 & 1) {
        sub_00027600((int)this);
    }
    return this;
}

