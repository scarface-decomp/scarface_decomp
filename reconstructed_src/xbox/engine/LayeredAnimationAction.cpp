// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail Xbox default.xbe, engine/LayeredAnimationAction.cpp (3 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 3 of 4 functions matched (75.00%). NOT COMPLETE YET.
// The 1 still to do are listed in their place in Original_Binary_Order_Xbox.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] LayeredAnimationAction::vfunc_04 (0x000E5280, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// What it does: Reads flag bit 0 of the byte at +0x10.
// ============================================================================
// bin: xb
// va: 0x000E5280
// what: Reads flag bit 0 of the byte at +0x10.
// tool: Claude Opus 5.5 (generated from the shape 'read one flag bit', checked on decomp.me preset 266 by example)
class Class_000E5280
{
public:
    bool sub_000E5280();
    char m_pad00[0x10];
    unsigned char m_Flag0 : 1;
};

bool Class_000E5280::sub_000E5280()
{
    return m_Flag0;
}

// ============================================================================
// [VERIFIED] LayeredAnimationAction::vfunc_08 (0x000E52F0, 8 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as LayeredAnimationAction::vfunc_07 (Proto 0x000D30E0), which was matched first;
// its addresses and names were swapped for this function's.
// LayeredAnimationAction::vfunc_08 (Proto 0x000E52F0, 8 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field0C
{
    void sub_000D8550();
};

class LayeredAnimationAction
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
    char m_pad04[0x8];
    Field0C* m_Field0C; // +0x0C
};

void LayeredAnimationAction::vfunc_08()
{
    m_Field0C->sub_000D8550();
}

// ============================================================================
// [VERIFIED] LayeredAnimationAction::vfunc_03 (0x000E5350, 57 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as BlendAction::vfunc_03 (0x000E3ED0), which was matched first;
// its addresses and names were swapped for this function's.
struct Child
{
    virtual void vfunc_00();
    virtual void vfunc_01();
};

extern "C" char DAT_003A79DC[];
extern "C" void __cdecl sub_00027600(void* p);

class LayeredAnimationAction
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual LayeredAnimationAction* vfunc_03(unsigned int flags);
    void sub_000217F0();

    void* m_vtable_unused;
    Child* m_child; // +0x08
};

// Deleting destructor: releases the child it owns, runs the base destructor, frees itself when asked.
// The volatile accesses keep the vtable store ahead of the read, as the compiler does in a real destructor.
LayeredAnimationAction* LayeredAnimationAction::vfunc_03(unsigned int flags)
{
    *(void* volatile*)this = DAT_003A79DC;
    Child* child = *(Child* volatile*)&m_child;
    if (child) {
        child->vfunc_01();
        m_child = 0;
    }
    sub_000217F0();
    if (flags & 1)
        sub_00027600(this);
    return this;
}

