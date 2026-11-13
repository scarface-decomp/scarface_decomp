// ============================================================================
// SCARFACE: THE WORLD IS YOURS — April 2006 prototype game.xbe, engine/VisibilityTriggerObject.cpp (2 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 2 of 3 functions matched (66.67%). NOT COMPLETE YET.
// The 1 still to do are listed in their place in Original_Binary_Order_Proto.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] VisibilityTriggerObject::vfunc_00 (0x001E5E00, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as CollisionBehaviourTypeGroup::vfunc_00 (0x000123B0), which was matched first;
// its addresses and names were swapped for this function's.
// VisibilityTriggerObject::vfunc_00 (0x001E5E00, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_004276B8[];

class VisibilityTriggerObject
{
public:
    virtual void* vfunc_00();
};

void* VisibilityTriggerObject::vfunc_00()
{
    return DAT_004276B8;
}

// ============================================================================
// [VERIFIED] VisibilityTriggerObject::vfunc_01 (0x001E5E20, 61 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as RoomTriggerObject::vfunc_01 (0x002127D0), which was matched first;
// its addresses and names were swapped for this function's.
// VisibilityTriggerObject::vfunc_01 (0x001E5E20, 61 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_003AB114[];
extern "C" void __cdecl sub_00025160(int);
extern "C" void __cdecl sub_0008B950(int);

class VisibilityTriggerObject
{
public:
    virtual void vfunc_00();
    virtual VisibilityTriggerObject* vfunc_01(int a1);
    void sub_00029C00();
    char m_pad04[0x1C];
    int m_Field20; // +0x20
};

VisibilityTriggerObject* VisibilityTriggerObject::vfunc_01(int a1)
{
    int t1;

    t1 = m_Field20;
    *(int*)this = (int)DAT_003AB114;
    if (m_Field20) {
        sub_0008B950(t1);
        m_Field20 = 0;
    }
    sub_00029C00();
    if (a1 & 1) {
        sub_00025160((int)this);
    }
    return this;
}

