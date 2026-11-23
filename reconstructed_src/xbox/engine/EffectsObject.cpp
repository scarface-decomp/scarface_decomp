// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail Xbox default.xbe, engine/EffectsObject.cpp (2 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 2 of 4 functions matched (50.00%). NOT COMPLETE YET.
// The 2 still to do are listed in their place in Original_Binary_Order_Xbox.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] EffectsObject::vfunc_00 (0x001CF120, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// What it does: Returns EffectsObject's static class record (ConcreteClassRep<EffectsObject>), the object's run-time type.
// ============================================================================
// Same machine code as CollisionBehaviourTypeGroup::vfunc_00 (0x000123B0), which was matched first;
// its addresses and names were swapped for this function's.
// EffectsObject::vfunc_00 (0x001CF120, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0043A54C[];

class EffectsObject
{
public:
    virtual void* vfunc_00();
};

void* EffectsObject::vfunc_00()
{
    return DAT_0043A54C;
}

// ============================================================================
// [VERIFIED] EffectsObject::vfunc_01 (0x001CF310, 78 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// What it does: EffectsObject's deleting destructor: destroys the object, frees its memory when asked (flag bit 0), and returns it.
// ============================================================================
// EffectsObject::vfunc_01 (0x001CF310, 78 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_003C5A1C[];
extern "C" void __cdecl sub_00027600(int);
extern "C" void __cdecl sub_00048680(int);

class EffectsObject
{
public:
    virtual void vfunc_00();
    virtual EffectsObject* vfunc_01(int a1);
    void sub_0002A3A0();
    char m_pad04[0xA8];
    int m_FieldAC; // +0xAC
    char m_padB0[0x38];
    int m_FieldE8; // +0xE8
};

EffectsObject* EffectsObject::vfunc_01(int a1)
{
    *(int*)this = (int)DAT_003C5A1C;
    sub_00027600(m_FieldAC);
    if (m_FieldE8) {
        sub_00048680((int)(&m_FieldE8));
    }
    sub_0002A3A0();
    if (a1 & 1) {
        sub_00027600((int)this);
    }
    return this;
}

