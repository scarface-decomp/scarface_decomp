// ============================================================================
// SCARFACE: THE WORLD IS YOURS — April 2006 prototype game.xbe, engine/CharacterRenderable.cpp (3 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 3 of 7 functions matched (42.86%). NOT COMPLETE YET.
// The 4 still to do are listed in their place in Original_Binary_Order_Proto.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] renderer::CharacterRenderable::vfunc_13 (0x00049060, 33 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// What it does: Returns a copy of a three-number vector kept in an object.
// ============================================================================
// bin: proto
// va: 0x00049060
// what: Returns a copy of a three-number vector kept in an object.
// tool: Claude Opus 5.5 (transplanted from xb:0x000E7920, nearest by portal/tools/similar.py)
// sub_00049060 (0x00049060, 30 bytes)

struct Struct_00049060
{
    float m_Field00; // +0x00
    float m_Field04; // +0x04
    float m_Field08; // +0x08
};

class Class_00049060
{
public:
    Struct_00049060 sub_00049060() const;

    char m_pad00[0xAC];
    Struct_00049060 m_FieldAC; // +0xAC
};

// Returns the stored vector by value.
Struct_00049060 Class_00049060::sub_00049060() const
{
    return m_FieldAC;
}

// ============================================================================
// [VERIFIED] renderer::CharacterRenderable::vfunc_10 (0x00049090, 16 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// What it does: Calls sub_0004EF40 when the value at +0x80 is set.
// ============================================================================
// bin: proto
// va: 0x00049090
// what: Calls sub_0004EF40 when the value at +0x80 is set.
// tool: Claude Opus 5.5 (transplanted from xb:0x00050DA0, nearest by portal/tools/similar.py)
// renderer::CharacterRenderable::vfunc_10
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int __cdecl sub_0004EF40(void);


namespace renderer {
class CharacterRenderable
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
    char m_pad04[0x7C];
    int m_Field80; // +0x80
};

void CharacterRenderable::vfunc_10()
{
    int r_eax;

    r_eax = m_Field80;
    if (r_eax) {
        sub_0004EF40();
    }
}
}

// ============================================================================
// [VERIFIED] renderer::CharacterRenderable::vfunc_03 (0x00049470, 30 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as CollisionManager::CollisionManagerFlowClient::vfunc_00 (0x00016060), which was matched first;
// its addresses and names were swapped for this function's.
// renderer::CharacterRenderable::vfunc_03 (0x00049470, 30 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __cdecl sub_00049290(void);
extern "C" void __cdecl sub_001FCF60(int);

namespace renderer {

class CharacterRenderable
{
public:
    virtual CharacterRenderable* vfunc_03(int a1);
};

CharacterRenderable* CharacterRenderable::vfunc_03(int a1)
{
    sub_00049290();
    if (a1 & 1) {
        sub_001FCF60((int)this);
    }
    return this;
}

}

