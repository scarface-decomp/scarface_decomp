// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail Xbox default.xbe, fe/VehicleSelectionHUD.cpp (3 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 3 of 11 functions matched (27.27%). NOT COMPLETE YET.
// The 8 still to do are listed in their place in Original_Binary_Order_Xbox.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] VehicleSelectionHUD::vfunc_00 (0x001A3760, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// What it does: Returns VehicleSelectionHUD's static class record (ConcreteClassRep<VehicleSelectionHUD>), the object's run-time type.
// ============================================================================
// Same machine code as CollisionBehaviourTypeGroup::vfunc_00 (0x000123B0), which was matched first;
// its addresses and names were swapped for this function's.
// VehicleSelectionHUD::vfunc_00 (0x001A3760, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_004373E8[];

class VehicleSelectionHUD
{
public:
    virtual void* vfunc_00();
};

void* VehicleSelectionHUD::vfunc_00()
{
    return DAT_004373E8;
}

// ============================================================================
// [VERIFIED] VehicleSelectionHUD::vfunc_01 (0x001A3770, 40 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// What it does: VehicleSelectionHUD's deleting destructor: destroys the object, frees its memory when asked (flag bit 0), and returns it.
// ============================================================================
// Same machine code as AITask_AvoidIncomingCar::vfunc_01 (0x00123370), which was matched first;
// its addresses and names were swapped for this function's.
// VehicleSelectionHUD::vfunc_01 (0x001A3770, 40 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field70
{
    void sub_002A9290();
};

extern "C" void __cdecl sub_00027600(int);

class VehicleSelectionHUD
{
public:
    virtual void vfunc_00();
    virtual VehicleSelectionHUD* vfunc_01(int a1);
    void sub_00193F80();
    char m_pad04[0x6C];
    Field70 m_Field70; // +0x70
};

VehicleSelectionHUD* VehicleSelectionHUD::vfunc_01(int a1)
{
    m_Field70.sub_002A9290();
    sub_00193F80();
    if (a1 & 1) {
        sub_00027600((int)this);
    }
    return this;
}

// ============================================================================
// [VERIFIED] VehicleSelectionHUD::vfunc_45 (0x001B10D0, 221 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// VehicleSelectionHUD::vfunc_45 (0x001B10D0, 221 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    virtual void vfunc_00(int);
    void sub_000266B0();
    void sub_000EC0F0(int, int, int);
};

extern "C" char DAT_003C01E4[];
extern "C" void __cdecl sub_00027600(int);
extern "C" void __cdecl sub_000702E0(int, int, int, int, int);
extern "C" int __cdecl sub_000EB680(void);
extern "C" bool __stdcall sub_00193D50(int);

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
    virtual void vfunc_39();
    virtual void vfunc_40();
    virtual void vfunc_41();
    virtual void vfunc_42();
    virtual void vfunc_43();
    virtual void vfunc_44();
    virtual bool vfunc_45(int a1);
    char m_pad04[0x58];
    int m_Field5C; // +0x5C
    char m_pad60[0xC];
    int m_Field6C; // +0x6C
    char m_pad70[0x28];
    int m_Field98; // +0x98
    char m_pad9C[0x8C];
    int m_Field128; // +0x128
    char m_pad12C[0xC];
    int m_Field138; // +0x138
};

bool VehicleSelectionHUD::vfunc_45(int a1)
{
    int r_ebp, r_ebx, r_esi, t2, t4, t6, t8;

    if (sub_00193D50(a1)) {
        return true;
    }
    r_esi = (int)(&m_Field138);
    r_ebp = 5;
    r_ebx = 0;
    do {
        t2 = *(int*)r_esi;
        if (*(int*)r_esi != r_ebx) {
            ((Object*)t2)->vfunc_00(1);
            *(int*)r_esi = r_ebx;
        }
        r_esi += 4;
        r_ebp -= 1;
    } while (r_ebp);
    t4 = m_Field98;
    if (m_Field98 != r_ebx) {
        ((Object*)t4)->vfunc_00(1);
        m_Field98 = r_ebx;
    }
    t6 = m_Field6C;
    if (m_Field6C != r_ebx) {
        ((Object*)t6)->vfunc_00(1);
        m_Field6C = r_ebx;
    }
    t8 = m_Field128;
    if (m_Field128 != r_ebx) {
        ((Object*)t8)->vfunc_00(1);
        m_Field128 = r_ebx;
    }
    r_esi = m_Field5C;
    if (r_esi != r_ebx) {
        ((Object*)r_esi)->sub_000266B0();
        sub_00027600(r_esi);
        m_Field5C = r_ebx;
    }
    r_esi = sub_000EB680();
    ((Object*)r_esi)->sub_000EC0F0(150, r_ebx, r_ebx);
    ((Object*)r_esi)->sub_000EC0F0(152, r_ebx, r_ebx);
    ((Object*)r_esi)->sub_000EC0F0(151, r_ebx, r_ebx);
    sub_000702E0((int)DAT_003C01E4, r_ebx, r_ebx, r_ebx, -1);
    return false;
}

