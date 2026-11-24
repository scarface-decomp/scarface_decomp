// ============================================================================
// SCARFACE: THE WORLD IS YOURS — April 2006 prototype game.xbe, pure3d/PrimGroup.cpp (2 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 2 of 6 functions matched (33.33%). NOT COMPLETE YET.
// The 4 still to do are listed in their place in Original_Binary_Order_Proto.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] pure3d::PrimGroup::vfunc_09 (0x0024F280, 4 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// pure3d::PrimGroup::vfunc_09 (Proto 0x0024F280, 4 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

namespace pure3d {

class PrimGroup
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
    virtual int vfunc_09();
    char m_pad04[0x34];
    int m_Field38; // +0x38
};

int PrimGroup::vfunc_09()
{
    return m_Field38;
}

}

// ============================================================================
// [VERIFIED] pure3d::PrimGroup::vfunc_12 (0x0024F2B0, 19 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as pure3d::PrimGroup::vfunc_12 (0x002929F0), which was matched first;
// its addresses and names were swapped for this function's.
// bin: xb
// va: 0x0024F2B0
// what: Returns bit 2 of the flags byte at +0x16 of the object pointed to by +0x38, or false if null.
// tool: Gemini 4 Neon

struct Field38_0024F2B0
{
    char m_pad00[0x16];
    unsigned char m_Flag0 : 1;
    unsigned char m_Flag1 : 1;
    unsigned char m_Flag2 : 1;
};

namespace pure3d {

class PrimGroup
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
    virtual bool vfunc_12();
    char m_pad04[0x34];
    Field38_0024F2B0* m_Field38; // +0x38
};

bool PrimGroup::vfunc_12()
{
    if (m_Field38) {
        return m_Field38->m_Flag2;
    }
    return false;
}

}

