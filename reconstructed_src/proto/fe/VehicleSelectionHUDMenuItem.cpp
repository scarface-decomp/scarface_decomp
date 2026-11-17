// ============================================================================
// SCARFACE: THE WORLD IS YOURS — April 2006 prototype game.xbe, fe/VehicleSelectionHUDMenuItem.cpp (3 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 3 of 5 functions matched (60.00%). NOT COMPLETE YET.
// The 2 still to do are listed in their place in Original_Binary_Order_Proto.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] VehicleSelectionHUD::VehicleSelectionHUDMenuItem::vfunc_05 (0x00182570, 55 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// VehicleSelectionHUD::VehicleSelectionHUDMenuItem::vfunc_05 (Proto 0x00182570, 55 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field0C
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
    virtual void vfunc_10();
    virtual void vfunc_11();
    virtual void vfunc_12();
    virtual void vfunc_13();
    virtual void vfunc_14();
    virtual void vfunc_15();
    virtual void vfunc_16();
    virtual void vfunc_17();
    virtual void vfunc_18();
    virtual void vfunc_19();
    virtual void vfunc_20();
    virtual void vfunc_21();
    virtual void vfunc_22();
    virtual void vfunc_23();
    virtual void vfunc_24();
    virtual void vfunc_25();
    virtual void vfunc_26();
    virtual void vfunc_27();
    virtual void vfunc_28();
    virtual void vfunc_29();
    virtual void vfunc_30();
    virtual void vfunc_31();
    virtual void vfunc_32();
    virtual void vfunc_33();
    virtual void vfunc_34();
    virtual void vfunc_35();
    virtual int vfunc_36(int, int, int);
};

extern "C" char DAT_0039B7E8[];
extern "C" int __cdecl sub_00065830(int, int, int);

namespace VehicleSelectionHUD {

class VehicleSelectionHUDMenuItem
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual int vfunc_05(int a1);
    char m_pad04[0x8];
    Field0C* m_Field0C; // +0x0C
};

int VehicleSelectionHUDMenuItem::vfunc_05(int a1)
{
    int r_eax, t1;

    r_eax = *(int*)(a1 + 8);
    t1 = *(int*)(a1 + 12);
    if (m_Field0C) {
        r_eax = sub_00065830((int)DAT_0039B7E8, t1, r_eax);
        r_eax = m_Field0C->vfunc_36(r_eax, 0, 0);
    }
    return r_eax;
}

}

// ============================================================================
// [VERIFIED] VehicleSelectionHUD::VehicleSelectionHUDMenuItem::vfunc_03 (0x001825B0, 42 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// VehicleSelectionHUD::VehicleSelectionHUDMenuItem::vfunc_03 (Proto 0x001825B0, 42 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
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
    virtual void vfunc_10();
    virtual void vfunc_11();
    virtual void vfunc_12();
    virtual void vfunc_13();
    virtual void vfunc_14();
    virtual void vfunc_15();
    virtual void vfunc_16();
    virtual void vfunc_17();
    virtual void vfunc_18(int);
};

namespace VehicleSelectionHUD {

class VehicleSelectionHUDMenuItem
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03(int a1);
    char m_pad04[0x1];
    unsigned char m_Field05; // +0x05
    char m_pad06[0x2];
    int m_Field08; // +0x08
    int m_Field0C; // +0x0C
};

void VehicleSelectionHUDMenuItem::vfunc_03(int a1)
{
    int t1, t3;

    t1 = m_Field0C;
    if (m_Field0C) {
        ((Object*)t1)->vfunc_18(a1);
    }
    t3 = m_Field08;
    if (m_Field08) {
        ((Object*)t3)->vfunc_18(a1);
    }
    m_Field05 = (unsigned char)a1;
}

}

// ============================================================================
// [VERIFIED] VehicleSelectionHUD::VehicleSelectionHUDMenuItem::vfunc_00 (0x001842D0, 36 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as LOSManager::LOSManagerFlowClient::vfunc_00 (0x000179C0), which was matched first;
// its addresses and names were swapped for this function's.
// VehicleSelectionHUD::VehicleSelectionHUDMenuItem::vfunc_00 (0x001842D0, 36 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0039B7D0[];
extern "C" void __cdecl sub_00025160(int);
extern "C" void __cdecl sub_0016FA10(void);

namespace VehicleSelectionHUD {

class VehicleSelectionHUDMenuItem
{
public:
    virtual VehicleSelectionHUDMenuItem* vfunc_00(int a1);
};

VehicleSelectionHUDMenuItem* VehicleSelectionHUDMenuItem::vfunc_00(int a1)
{
    *(int*)this = (int)DAT_0039B7D0;
    sub_0016FA10();
    if (a1 & 1) {
        sub_00025160((int)this);
    }
    return this;
}

}

