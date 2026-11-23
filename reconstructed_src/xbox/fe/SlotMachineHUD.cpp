// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail Xbox default.xbe, fe/SlotMachineHUD.cpp (2 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 2 of 4 functions matched (50.00%). NOT COMPLETE YET.
// The 2 still to do are listed in their place in Original_Binary_Order_Xbox.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] SlotMachineHUD::vfunc_00 (0x001BFEA0, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// What it does: Returns SlotMachineHUD's static class record (ConcreteClassRep<SlotMachineHUD>), the object's run-time type.
// ============================================================================
// Same machine code as CollisionBehaviourTypeGroup::vfunc_00 (0x000123B0), which was matched first;
// its addresses and names were swapped for this function's.
// SlotMachineHUD::vfunc_00 (0x001BFEA0, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_00437D30[];

class SlotMachineHUD
{
public:
    virtual void* vfunc_00();
};

void* SlotMachineHUD::vfunc_00()
{
    return DAT_00437D30;
}

// ============================================================================
// [VERIFIED] SlotMachineHUD::vfunc_01 (0x001C00B0, 89 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// SlotMachineHUD::vfunc_01 (0x001C00B0, 89 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    virtual void vfunc_00(int);
};

extern "C" char DAT_003B8D2C[];
extern "C" char DAT_003C240C[];
extern "C" void __cdecl sub_00027600(int);
extern "C" void __cdecl sub_000782B0(int, int, int, int);
extern "C" int __cdecl sub_00078800(int);

class SlotMachineHUD
{
public:
    virtual void vfunc_00();
    virtual SlotMachineHUD* vfunc_01(int a1);
    void sub_001ACE00();
    char m_pad04[0x48];
    int m_Field4C; // +0x4C
};

SlotMachineHUD* SlotMachineHUD::vfunc_01(int a1)
{
    int t1;

    t1 = m_Field4C;
    *(int*)this = (int)DAT_003C240C;
    if (m_Field4C) {
        ((Object*)t1)->vfunc_00(1);
        m_Field4C = 0;
    }
    sub_000782B0(sub_00078800((int)DAT_003B8D2C), 500, 0, 0);
    sub_001ACE00();
    if (a1 & 1) {
        sub_00027600((int)this);
    }
    return this;
}

