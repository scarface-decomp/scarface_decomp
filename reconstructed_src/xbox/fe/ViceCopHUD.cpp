// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail Xbox default.xbe, fe/ViceCopHUD.cpp (9 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 9 of 13 functions matched (69.23%). NOT COMPLETE YET.
// The 4 still to do are listed in their place in Original_Binary_Order_Xbox.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] ViceCopHUD::vfunc_45 (0x001AE7A0, 125 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// ViceCopHUD::vfunc_45 (0x001AE7A0, 125 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    virtual void vfunc_00(int);
    void sub_001A7AD0(int);
};

extern "C" char DAT_003BF754[];
extern "C" int DAT_0048C898;
extern "C" void __cdecl sub_000702E0(int, int, int, int, int);
extern "C" bool __stdcall sub_00193D50(int);

class ViceCopHUD
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
    char m_pad04[0x70];
    int m_Field74; // +0x74
    int m_Field78; // +0x78
    char m_pad7C[0x4];
    int m_Field80; // +0x80
    int m_Field84; // +0x84
};

bool ViceCopHUD::vfunc_45(int a1)
{
    int r_ebx, t3, t5;

    if (sub_00193D50(a1)) {
        return true;
    }
    r_ebx = 0;
    ((Object*)DAT_0048C898)->sub_001A7AD0(0);
    *(bool*)(DAT_0048C898 + 356) = false;
    t3 = m_Field84;
    m_Field74 = 0;
    m_Field78 = 0;
    if (m_Field84) {
        ((Object*)t3)->vfunc_00(1);
        m_Field84 = 0;
    }
    t5 = m_Field80;
    if (m_Field80 != r_ebx) {
        ((Object*)t5)->vfunc_00(1);
        m_Field80 = r_ebx;
    }
    sub_000702E0((int)DAT_003BF754, r_ebx, r_ebx, r_ebx, -1);
    return false;
}

// ============================================================================
// [VERIFIED] ViceCopHUD::vfunc_00 (0x001AE870, 29 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// bin: xb
// va: 0x001AE870
// what: 
// tool: the portal's starter code (no AI)

// ViceCopHUD::vfunc_00 (0x001AE870, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02(int, int);
};

extern "C" char DAT_003BF55C[];

class ViceCopHUD
{
public:
    virtual void vfunc_00();
};

void ViceCopHUD::vfunc_00()
{
    int r_ecx;

    r_ecx = (int)this;
    if (!(*(unsigned char*)(r_ecx + -8) & 16)) {
        if (!*(int*)(r_ecx + 24)) goto L_1C;
    }
    r_ecx = *(int*)(r_ecx + 24);
    ((Object*)r_ecx)->vfunc_02(0, (int)DAT_003BF55C);
L_1C:
    ;
}

// ============================================================================
// [VERIFIED] ViceCopHUD::vfunc_01 (0x001AE890, 29 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// bin: xb
// va: 0x001AE890
// what: 
// tool: the portal's starter code (no AI)

// ViceCopHUD::vfunc_01 (0x001AE890, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03(int, int);
};

extern "C" char DAT_003BF55C[];

class ViceCopHUD
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
};

void ViceCopHUD::vfunc_01()
{
    int r_ecx;

    r_ecx = (int)this;
    if (!(*(unsigned char*)(r_ecx + -8) & 16)) {
        if (!*(int*)(r_ecx + 24)) goto L_1C;
    }
    r_ecx = *(int*)(r_ecx + 24);
    ((Object*)r_ecx)->vfunc_03(0, (int)DAT_003BF55C);
L_1C:
    ;
}

// ============================================================================
// [VERIFIED] ViceCopHUD::vfunc_02 (0x001B2250, 11 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// ViceCopHUD::vfunc_02 (0x001B2250, 11 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_001B0920(int);
};

class ViceCopHUD
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
};

void ViceCopHUD::vfunc_02()
{
    ((Object*)(int)this + -104)->sub_001B0920(0);
}

// ============================================================================
// [VERIFIED] ViceCopHUD::vfunc_03 (0x001B2260, 11 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// ViceCopHUD::vfunc_03 (0x001B2260, 11 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_001B0920(int);
};

class ViceCopHUD
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
};

void ViceCopHUD::vfunc_03()
{
    ((Object*)(int)this + -104)->sub_001B0920(1);
}

// ============================================================================
// [VERIFIED] ViceCopHUD::vfunc_00 (0x001C21E0, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// What it does: Returns ViceCopHUD's static class record (ConcreteClassRep<ViceCopHUD>), the object's run-time type.
// ============================================================================
// Same machine code as CollisionBehaviourTypeGroup::vfunc_00 (0x000123B0), which was matched first;
// its addresses and names were swapped for this function's.
// ViceCopHUD::vfunc_00 (0x001C21E0, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_00437F00[];

class ViceCopHUD
{
public:
    virtual void* vfunc_00();
};

void* ViceCopHUD::vfunc_00()
{
    return DAT_00437F00;
}

// ============================================================================
// [VERIFIED] ViceCopHUD::vfunc_29 (0x001C21F0, 29 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// ViceCopHUD::vfunc_29 (0x001C21F0, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int __cdecl sub_00023EC0(int);
extern "C" void __cdecl sub_00193150(void);

class ViceCopHUD
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
    virtual int vfunc_29();
    char m_pad04[0x68];
    int m_Field6C; // +0x6C
    int m_Field70; // +0x70
};

int ViceCopHUD::vfunc_29()
{
    int r_eax;

    sub_00193150();
    r_eax = m_Field70;
    if (r_eax) {
        r_eax = sub_00023EC0(r_eax);
        m_Field6C = r_eax;
    }
    return r_eax;
}

// ============================================================================
// [VERIFIED] ViceCopHUD::vfunc_36 (0x001C22C0, 72 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// ViceCopHUD::vfunc_36 (0x001C22C0, 72 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_00196E60(int);
};

extern "C" int DAT_0048C23C;
extern "C" bool __stdcall sub_00193B40(int, int);

class ViceCopHUD
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
    virtual bool vfunc_36(int a1, int a2);
    char m_pad04[0x78];
    bool m_Field7C; // +0x7C
};

bool ViceCopHUD::vfunc_36(int a1, int a2)
{
    if (sub_00193B40(a1, a2)) {
        return true;
    }
    if ((unsigned char)a1) {
        if (m_Field7C) goto L_41;
        ((Object*)DAT_0048C23C)->sub_00196E60(34);
        return false;
    }
    m_Field7C = false;
L_41:
    return false;
}

// ============================================================================
// [VERIFIED] ViceCopHUD::vfunc_01 (0x001C23B0, 30 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// What it does: ViceCopHUD's deleting destructor: destroys the object, frees its memory when asked (flag bit 0), and returns it.
// ============================================================================
// Same machine code as Collidable::vfunc_03 (0x00011F20), which was matched first;
// its addresses and names were swapped for this function's.
// ViceCopHUD::vfunc_01 (0x001C23B0, 30 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __cdecl sub_001C2180(void);
extern "C" void __cdecl sub_00027600(int);

class ViceCopHUD
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual ViceCopHUD* vfunc_01(int a1);
};

ViceCopHUD* ViceCopHUD::vfunc_01(int a1)
{
    sub_001C2180();
    if (a1 & 1) {
        sub_00027600((int)this);
    }
    return this;
}

