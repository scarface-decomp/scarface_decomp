// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail Xbox default.xbe, engine/FilterAnd.cpp (1 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: COMPLETE. All 1 functions are matched.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] FilterAnd::vfunc_00 (0x001161F0, 49 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// FilterAnd::vfunc_00 (0x001161F0, 49 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field04
{
    virtual bool vfunc_00(int);
};

struct Field08
{
    virtual bool vfunc_00(int);
};

class FilterAnd
{
public:
    virtual int vfunc_00(int a1);
    Field04* m_Field04; // +0x04
    Field08* m_Field08; // +0x08
};

int FilterAnd::vfunc_00(int a1)
{
    if (m_Field04->vfunc_00(a1)) {
        if (!m_Field08->vfunc_00(a1)) goto L_2A;
        return 1;
    }
L_2A:
    return 0;
}

