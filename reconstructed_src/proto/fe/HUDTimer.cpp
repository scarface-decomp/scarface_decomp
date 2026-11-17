// ============================================================================
// SCARFACE: THE WORLD IS YOURS — April 2006 prototype game.xbe, fe/HUDTimer.cpp (6 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 6 of 8 functions matched (75.00%). NOT COMPLETE YET.
// The 2 still to do are listed in their place in Original_Binary_Order_Proto.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] HUDTimer::vfunc_00 (0x00177AC0, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as CollisionBehaviourTypeGroup::vfunc_00 (0x000123B0), which was matched first;
// its addresses and names were swapped for this function's.
// HUDTimer::vfunc_00 (0x00177AC0, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_00410DE4[];

class HUDTimer
{
public:
    virtual void* vfunc_00();
};

void* HUDTimer::vfunc_00()
{
    return DAT_00410DE4;
}

// ============================================================================
// [VERIFIED] HUDTimer::vfunc_28 (0x00177B00, 48 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// HUDTimer::vfunc_28 (Proto 0x00177B00, 48 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __stdcall sub_0016E200(int);

class HUDTimer
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
    virtual void vfunc_28(int a1);
    char m_pad04[0x44];
    bool m_Field48; // +0x48
    char m_pad49[0x3];
    int m_Field4C; // +0x4C
    int m_Field50; // +0x50
    int m_Field54; // +0x54
    int m_Field58; // +0x58
};

void HUDTimer::vfunc_28(int a1)
{
    int t1;

    t1 = *(int*)(a1 + 4);
    m_Field4C = *(int*)(*(int*)(a1 + 4) + 8);
    m_Field54 = *(int*)(t1 + 16);
    m_Field50 = *(int*)(t1 + 12);
    m_Field58 = *(int*)(t1 + 20);
    m_Field48 = *(bool*)(t1 + 24);
    a1 = a1;
    sub_0016E200(a1);
}

// ============================================================================
// [VERIFIED] HUDTimer::vfunc_29 (0x00177B30, 100 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// HUDTimer::vfunc_29 (Proto 0x00177B30, 100 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0016E0B0();
};

extern "C" char DAT_00399720[];
extern "C" int __cdecl sub_00025140(int, int);

class HUDTimer
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
    void sub_0016E260();
    char m_pad04[0x28];
    int m_Field2C; // +0x2C
    char m_pad30[0x18];
    bool m_Field48; // +0x48
    char m_pad49[0x3];
    int m_Field4C; // +0x4C
    int m_Field50; // +0x50
    int m_Field54; // +0x54
    int m_Field58; // +0x58
};

void HUDTimer::vfunc_29()
{
    int r_esi;

    r_esi = sub_00025140(28, 7);
    if (r_esi) {
        ((Object*)r_esi)->sub_0016E0B0();
        *(int*)r_esi = (int)DAT_00399720;
        *(int*)(r_esi + 8) = 0;
        *(int*)(r_esi + 12) = 0;
        *(int*)(r_esi + 16) = 0;
        *(int*)(r_esi + 20) = 0;
        *(bool*)(r_esi + 24) = false;
    } else {
        r_esi = 0;
    }
    *(int*)(r_esi + 8) = m_Field4C;
    *(int*)(r_esi + 16) = m_Field54;
    *(int*)(r_esi + 12) = m_Field50;
    *(int*)(r_esi + 20) = m_Field58;
    *(bool*)(r_esi + 24) = m_Field48;
    m_Field2C = r_esi;
    sub_0016E260();
}

// ============================================================================
// [VERIFIED] HUDTimer::vfunc_33 (0x00177BA0, 46 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// HUDTimer::vfunc_33 (Proto 0x00177BA0, 46 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" bool __stdcall sub_0016E540(int, int);

class HUDTimer
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
    virtual bool vfunc_33(int a1, int a2);
    void sub_0016E5E0(int, int);
    char m_pad04[0x3C];
    int m_Field40; // +0x40
};

bool HUDTimer::vfunc_33(int a1, int a2)
{
    if (sub_0016E540(a1, 0)) {
        return true;
    }
    sub_0016E5E0(m_Field40, a1);
    return false;
}

// ============================================================================
// [VERIFIED] HUDTimer::vfunc_38 (0x00177BD0, 41 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// HUDTimer::vfunc_38 (Proto 0x00177BD0, 41 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_0045A0EC;
extern "C" bool __stdcall sub_0016E830(int);

class HUDTimer
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
    virtual bool vfunc_38(int a1);
    char m_pad04[0x48];
    int m_Field4C; // +0x4C
};

bool HUDTimer::vfunc_38(int a1)
{
    if (sub_0016E830(a1)) {
        return true;
    }
    m_Field4C = *(int*)(DAT_0045A0EC + 44);
    return false;
}

// ============================================================================
// [VERIFIED] HUDTimer::vfunc_01 (0x00177CE0, 36 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as CollisionBehaviourTypeGroup::vfunc_01 (0x00013840), which was matched first;
// its addresses and names were swapped for this function's.
// HUDTimer::vfunc_01 (0x00177CE0, 36 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0039972C[];
extern "C" void __cdecl sub_00025160(int);
extern "C" void __cdecl sub_0016E130(void);

class HUDTimer
{
public:
    virtual void vfunc_00();
    virtual HUDTimer* vfunc_01(int a1);
};

HUDTimer* HUDTimer::vfunc_01(int a1)
{
    *(int*)this = (int)DAT_0039972C;
    sub_0016E130();
    if (a1 & 1) {
        sub_00025160((int)this);
    }
    return this;
}

