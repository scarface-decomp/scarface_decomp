// ============================================================================
// SCARFACE: THE WORLD IS YOURS — April 2006 prototype game.xbe, fe/VehicleSelectionHUD.cpp (3 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 3 of 10 functions matched (30.00%). NOT COMPLETE YET.
// The 7 still to do are listed in their place in Original_Binary_Order_Proto.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] VehicleSelectionHUD::vfunc_00 (0x00178D10, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as CollisionBehaviourTypeGroup::vfunc_00 (0x000123B0), which was matched first;
// its addresses and names were swapped for this function's.
// VehicleSelectionHUD::vfunc_00 (0x00178D10, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_00411028[];

class VehicleSelectionHUD
{
public:
    virtual void* vfunc_00();
};

void* VehicleSelectionHUD::vfunc_00()
{
    return DAT_00411028;
}

// ============================================================================
// [VERIFIED] VehicleSelectionHUD::vfunc_01 (0x00178D20, 40 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// VehicleSelectionHUD::vfunc_01 (Proto 0x00178D20, 40 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field4C
{
    void sub_001B7A10();
};

extern "C" void __cdecl sub_00025160(int);

class VehicleSelectionHUD
{
public:
    virtual void vfunc_00();
    virtual VehicleSelectionHUD* vfunc_01(int a1);
    void sub_0016E130();
    char m_pad04[0x48];
    Field4C m_Field4C; // +0x4C
};

VehicleSelectionHUD* VehicleSelectionHUD::vfunc_01(int a1)
{
    m_Field4C.sub_001B7A10();
    sub_0016E130();
    if (a1 & 1) {
        sub_00025160((int)this);
    }
    return this;
}

// ============================================================================
// [VERIFIED] VehicleSelectionHUD::vfunc_39 (0x001840E0, 227 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// VehicleSelectionHUD::vfunc_39 (Proto 0x001840E0, 227 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    virtual void vfunc_00(int);
    void sub_00024320();
    void sub_000D99E0(int, int, int);
};

extern "C" char DAT_0039BD80[];
extern "C" void __cdecl sub_00025160(int);
extern "C" void __cdecl sub_00065ED0(int, int, int, int, int);
extern "C" int __cdecl sub_000D8FA0(void);
extern "C" bool __stdcall sub_0016E890(int);

class VehicleSelectionHUD
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
    virtual void vfunc_36();
    virtual void vfunc_37();
    virtual void vfunc_38();
    virtual bool vfunc_39(int a1);
};

bool VehicleSelectionHUD::vfunc_39(int a1)
{
    int r_ebp, r_edi, r_esi, t2, t4, t6, t8;

    r_edi = (int)this;
    if (sub_0016E890(a1)) {
        return true;
    }
    r_esi = r_edi + 272;
    r_ebp = 5;
    do {
        t2 = *(int*)r_esi;
        if (*(int*)r_esi) {
            ((Object*)t2)->vfunc_00(1);
            *(int*)r_esi = 0;
        }
        r_esi += 4;
        r_ebp -= 1;
    } while (r_ebp);
    t4 = *(int*)(r_edi + 112);
    if (*(int*)(r_edi + 112)) {
        ((Object*)t4)->vfunc_00(1);
        *(int*)(r_edi + 112) = 0;
    }
    t6 = *(int*)(r_edi + 72);
    if (*(int*)(r_edi + 72)) {
        ((Object*)t6)->vfunc_00(1);
        *(int*)(r_edi + 72) = 0;
    }
    t8 = *(int*)(r_edi + 260);
    if (*(int*)(r_edi + 260)) {
        ((Object*)t8)->vfunc_00(1);
        *(int*)(r_edi + 260) = 0;
    }
    r_edi = *(int*)(r_edi + 256);
    if (r_edi) {
        ((Object*)r_edi)->sub_00024320();
        sub_00025160(r_edi);
    }
    r_esi = sub_000D8FA0();
    ((Object*)r_esi)->sub_000D99E0(119, 0, 0);
    ((Object*)r_esi)->sub_000D99E0(121, 0, 0);
    ((Object*)r_esi)->sub_000D99E0(120, 0, 0);
    sub_00065ED0((int)DAT_0039BD80, 0, 0, 0, -1);
    return false;
}

