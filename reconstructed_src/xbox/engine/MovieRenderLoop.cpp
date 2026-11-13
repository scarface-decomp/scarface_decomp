// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail Xbox default.xbe, engine/MovieRenderLoop.cpp (3 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: COMPLETE. All 3 functions are matched.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] MovieRenderLoop::vfunc_01 (0x000288A0, 13 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// MovieRenderLoop::vfunc_01 (0x000288A0, 13 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

class MovieRenderLoop
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03(int);
    char m_pad04[0x4];
    int m_Field08; // +0x08
};

void MovieRenderLoop::vfunc_01()
{
    m_Field08 -= 1;
    if (!m_Field08) {
        vfunc_03(1);
    }
}

// ============================================================================
// [VERIFIED] MovieRenderLoop::vfunc_04 (0x000288B0, 19 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// MovieRenderLoop::vfunc_04 (0x000288B0, 19 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual bool vfunc_05();
};

class MovieRenderLoop
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04(int a1);
    unsigned char m_Field04; // +0x04
};

void MovieRenderLoop::vfunc_04(int a1)
{
    m_Field04 = ((Object*)a1)->vfunc_05();
}

// ============================================================================
// [VERIFIED] MovieRenderLoop::vfunc_00 (0x000CE960, 4 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// MovieRenderLoop::vfunc_00 (0x000CE960, 4 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

class MovieRenderLoop
{
public:
    virtual void vfunc_00();
    char m_pad04[0x4];
    int m_Field08; // +0x08
};

void MovieRenderLoop::vfunc_00()
{
    m_Field08 += 1;
}

