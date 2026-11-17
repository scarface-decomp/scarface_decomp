// ============================================================================
// SCARFACE: THE WORLD IS YOURS — April 2006 prototype game.xbe, fe/ViceCopHUD.cpp (6 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 6 of 12 functions matched (50.00%). NOT COMPLETE YET.
// The 6 still to do are listed in their place in Original_Binary_Order_Proto.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] ViceCopHUD::vfunc_39 (0x00182030, 92 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// ViceCopHUD::vfunc_39 (Proto 0x00182030, 92 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    virtual void vfunc_00(int);
};

extern "C" char DAT_0039B668[];
extern "C" void __cdecl sub_00065ED0(int, int, int, int, int);
extern "C" bool __stdcall sub_0016E890(int);

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
    virtual bool vfunc_39(int a1);
    char m_pad04[0x4C];
    int m_Field50; // +0x50
    int m_Field54; // +0x54
    bool m_Field58; // +0x58
    char m_pad59[0x3];
    int m_Field5C; // +0x5C
    int m_Field60; // +0x60
};

bool ViceCopHUD::vfunc_39(int a1)
{
    int r_ebx, t2, t4;

    if (sub_0016E890(a1)) {
        return true;
    }
    r_ebx = 0;
    t2 = m_Field60;
    m_Field50 = 0;
    m_Field54 = 0;
    m_Field58 = false;
    if (m_Field60) {
        ((Object*)t2)->vfunc_00(1);
        m_Field60 = 0;
    }
    t4 = m_Field5C;
    if (m_Field5C != r_ebx) {
        ((Object*)t4)->vfunc_00(1);
        m_Field5C = r_ebx;
    }
    sub_00065ED0((int)DAT_0039B668, r_ebx, r_ebx, r_ebx, -1);
    return false;
}

// ============================================================================
// [VERIFIED] ViceCopHUD::vfunc_02 (0x00185150, 11 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// ViceCopHUD::vfunc_02 (Proto 0x00185150, 11 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_001839A0(int);
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
    ((Object*)(int)this + -68)->sub_001839A0(0);
}

// ============================================================================
// [VERIFIED] ViceCopHUD::vfunc_03 (0x00185160, 11 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// ViceCopHUD::vfunc_03 (Proto 0x00185160, 11 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_001839A0(int);
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
    ((Object*)(int)this + -68)->sub_001839A0(1);
}

// ============================================================================
// [VERIFIED] ViceCopHUD::vfunc_00 (0x0018DDA0, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as CollisionBehaviourTypeGroup::vfunc_00 (0x000123B0), which was matched first;
// its addresses and names were swapped for this function's.
// ViceCopHUD::vfunc_00 (0x0018DDA0, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_00411C74[];

class ViceCopHUD
{
public:
    virtual void* vfunc_00();
};

void* ViceCopHUD::vfunc_00()
{
    return DAT_00411C74;
}

// ============================================================================
// [VERIFIED] ViceCopHUD::vfunc_27 (0x0018DDB0, 29 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// ViceCopHUD::vfunc_27 (Proto 0x0018DDB0, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int __cdecl sub_00021D50(int);
extern "C" void __cdecl sub_0016E150(void);

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
    virtual int vfunc_27();
    char m_pad04[0x44];
    int m_Field48; // +0x48
    int m_Field4C; // +0x4C
};

int ViceCopHUD::vfunc_27()
{
    int r_eax;

    sub_0016E150();
    r_eax = m_Field4C;
    if (r_eax) {
        r_eax = sub_00021D50(r_eax);
        m_Field48 = r_eax;
    }
    return r_eax;
}

// ============================================================================
// [VERIFIED] ViceCopHUD::vfunc_01 (0x0018DF20, 92 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// ViceCopHUD::vfunc_01 (Proto 0x0018DF20, 92 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    virtual void vfunc_00(int);
};

extern "C" char DAT_0039D6F4[];
extern "C" char DAT_0039D708[];
extern "C" char DAT_0039D714[];
extern "C" void __cdecl sub_00025160(int);

class ViceCopHUD
{
public:
    virtual void vfunc_00();
    virtual ViceCopHUD* vfunc_01(int a1);
    void sub_0016E130();
    char m_pad04[0x3C];
    int m_Field40; // +0x40
    int m_Field44; // +0x44
    char m_pad48[0x14];
    int m_Field5C; // +0x5C
    int m_Field60; // +0x60
};

ViceCopHUD* ViceCopHUD::vfunc_01(int a1)
{
    int t1, t3;

    t1 = m_Field60;
    *(int*)this = (int)DAT_0039D714;
    m_Field40 = (int)DAT_0039D708;
    m_Field44 = (int)DAT_0039D6F4;
    if (m_Field60) {
        ((Object*)t1)->vfunc_00(1);
        m_Field60 = 0;
    }
    t3 = m_Field5C;
    if (m_Field5C) {
        ((Object*)t3)->vfunc_00(1);
        m_Field5C = 0;
    }
    sub_0016E130();
    if (a1 & 1) {
        sub_00025160((int)this);
    }
    return this;
}

