// ============================================================================
// SCARFACE: THE WORLD IS YOURS — April 2006 prototype game.xbe, engine/NISRenderable.cpp (2 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 2 of 3 functions matched (66.67%). NOT COMPLETE YET.
// The 1 still to do are listed in their place in Original_Binary_Order_Proto.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] renderer::NISRenderable::vfunc_13 (0x0004C600, 33 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// What it does: Returns a copy of a three-number vector kept in an object.
// ============================================================================
// bin: proto
// va: 0x0004C600
// what: Returns a copy of a three-number vector kept in an object.
// tool: Claude Opus 5.5 (transplanted from xb:0x000E7920, nearest by portal/tools/similar.py)
// sub_0004C600 (0x0004C600, 30 bytes)

struct Struct_0004C600
{
    float m_Field00; // +0x00
    float m_Field04; // +0x04
    float m_Field08; // +0x08
};

class Class_0004C600
{
public:
    Struct_0004C600 sub_0004C600() const;

    char m_pad00[0x80];
    Struct_0004C600 m_Field80; // +0x80
};

// Returns the stored vector by value.
Struct_0004C600 Class_0004C600::sub_0004C600() const
{
    return m_Field80;
}

// ============================================================================
// [VERIFIED] renderer::NISRenderable::vfunc_03 (0x0004C6A0, 36 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as LOSManager::LOSManagerFlowClient::vfunc_00 (0x000179C0), which was matched first;
// its addresses and names were swapped for this function's.
// renderer::NISRenderable::vfunc_03 (0x0004C6A0, 36 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0037FE6C[];
extern "C" void __cdecl sub_001FCF60(int);
extern "C" void __cdecl sub_0004F610(void);

namespace renderer {

class NISRenderable
{
public:
    virtual NISRenderable* vfunc_03(int a1);
};

NISRenderable* NISRenderable::vfunc_03(int a1)
{
    *(int*)this = (int)DAT_0037FE6C;
    sub_0004F610();
    if (a1 & 1) {
        sub_001FCF60((int)this);
    }
    return this;
}

}

