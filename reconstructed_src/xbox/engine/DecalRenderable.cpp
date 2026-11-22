// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail Xbox default.xbe, engine/DecalRenderable.cpp (2 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 2 of 5 functions matched (40.00%). NOT COMPLETE YET.
// The 3 still to do are listed in their place in Original_Binary_Order_Xbox.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] renderer::DecalRenderable::vfunc_11 (0x00051810, 16 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// renderer::DecalRenderable::vfunc_11 (0x00051810, 16 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field84
{
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual void vfunc_05();
    virtual void vfunc_06();
    virtual void vfunc_07();
    virtual void vfunc_08();
    virtual void vfunc_09();
    virtual void vfunc_10(int, int);
};

namespace renderer {

class DecalRenderable
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual void vfunc_05();
    virtual void vfunc_06();
    virtual void vfunc_07();
    virtual void vfunc_08();
    virtual void vfunc_09();
    virtual void vfunc_10();
    virtual void vfunc_11();
    char m_pad04[0x80];
    Field84* m_Field84; // +0x84
};

void DecalRenderable::vfunc_11()
{
    m_Field84->vfunc_10(0, 0);
}

}

// ============================================================================
// [VERIFIED] renderer::DecalRenderable::vfunc_13 (0x00058500, 30 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as renderer::DecalRenderable::vfunc_13 (Proto 0x0004EA60), which was matched first;
// its addresses and names were swapped for this function's.
// bin: proto
// va: 0x00058500
// what: Returns a copy of a three-number vector kept in an object.
// tool: Claude Opus 5.5 (transplanted from xb:0x000E7920, nearest by portal/tools/similar.py)
// sub_00058500 (0x00058500, 30 bytes)

struct Struct_00058500
{
    float m_Field00; // +0x00
    float m_Field04; // +0x04
    float m_Field08; // +0x08
};

class Class_00058500
{
public:
    Struct_00058500 sub_00058500() const;

    char m_pad00[0x44];
    Struct_00058500 m_Field44; // +0x44
};

// Returns the stored vector by value.
Struct_00058500 Class_00058500::sub_00058500() const
{
    return m_Field44;
}

