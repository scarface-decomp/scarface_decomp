// ============================================================================
// SCARFACE: THE WORLD IS YOURS — April 2006 prototype game.xbe, fe/SlotMachineHUD.cpp (3 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 3 of 5 functions matched (60.00%). NOT COMPLETE YET.
// The 2 still to do are listed in their place in Original_Binary_Order_Proto.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] SlotMachineHUD::vfunc_00 (0x0018C560, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as CollisionBehaviourTypeGroup::vfunc_00 (0x000123B0), which was matched first;
// its addresses and names were swapped for this function's.
// SlotMachineHUD::vfunc_00 (0x0018C560, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_00411AC4[];

class SlotMachineHUD
{
public:
    virtual void* vfunc_00();
};

void* SlotMachineHUD::vfunc_00()
{
    return DAT_00411AC4;
}

// ============================================================================
// [VERIFIED] SlotMachineHUD::vfunc_01 (0x0018C850, 65 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// SlotMachineHUD::vfunc_01 (Proto 0x0018C850, 65 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    virtual void vfunc_00(int);
};

extern "C" char DAT_0039D37C[];
extern "C" char DAT_0039D384[];
extern "C" void __cdecl sub_00025160(int);

class SlotMachineHUD
{
public:
    virtual void vfunc_00();
    virtual SlotMachineHUD* vfunc_01(int a1);
    void sub_00181390();
    char m_pad04[0x30];
    int m_Field34; // +0x34
    char m_pad38[0x20];
    int m_Field58; // +0x58
};

SlotMachineHUD* SlotMachineHUD::vfunc_01(int a1)
{
    int t1;

    t1 = m_Field58;
    *(int*)this = (int)DAT_0039D384;
    m_Field34 = (int)DAT_0039D37C;
    if (m_Field58) {
        ((Object*)t1)->vfunc_00(1);
        m_Field58 = 0;
    }
    sub_00181390();
    if (a1 & 1) {
        sub_00025160((int)this);
    }
    return this;
}

// ============================================================================
// [VERIFIED] SlotMachineHUD::vfunc_00 (0x0018C8A0, 18 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// SlotMachineHUD::vfunc_00 (Proto 0x0018C8A0, 18 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0018C6F0();
};

class SlotMachineHUD
{
public:
    virtual void vfunc_00(int a1, int a2);
};

void SlotMachineHUD::vfunc_00(int a1, int a2)
{
    if (a1 == 31) {
        ((Object*)(int)this + -52)->sub_0018C6F0();
    }
}

