// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail Xbox default.xbe, pure3d/d3dExtGammaControl.cpp (2 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: COMPLETE. All 2 functions are matched.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] pure3d::d3dExtGammaControl::vfunc_01 (0x00267E40, 12 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// bin: xb
// va: 0x00267E40
// what: 
// tool: the portal's starter code (no AI)

// pure3d::d3dExtGammaControl::vfunc_01 (0x00267E40, 12 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.
// This function keeps a frame pointer (push ebp; mov ebp, esp), so it is built with them on.
#pragma optimize("y", off)

struct Field04
{
    void sub_0029ACD0(int);
};

namespace pure3d {

class d3dExtGammaControl
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01(int a1);
    Field04* m_Field04; // +0x04
};

void d3dExtGammaControl::vfunc_01(int a1)
{
    m_Field04->sub_0029ACD0(a1);
}

}

// ============================================================================
// [VERIFIED] pure3d::d3dExtGammaControl::vfunc_02 (0x00267E50, 12 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as pure3d::d3dExtGammaControl::vfunc_01 (0x00267E40), which was matched first;
// its addresses and names were swapped for this function's.
// bin: xb
// va: 0x00267E50
// what: 
// tool: the portal's starter code (no AI)

// pure3d::d3dExtGammaControl::vfunc_02 (0x00267E50, 12 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.
// This function keeps a frame pointer (push ebp; mov ebp, esp), so it is built with them on.
#pragma optimize("y", off)

struct Field04
{
    void sub_0029ACA0(int);
};

namespace pure3d {

class d3dExtGammaControl
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02(int a1);
    Field04* m_Field04; // +0x04
};

void d3dExtGammaControl::vfunc_02(int a1)
{
    m_Field04->sub_0029ACA0(a1);
}

}

