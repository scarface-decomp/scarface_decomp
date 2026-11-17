// ============================================================================
// SCARFACE: THE WORLD IS YOURS — April 2006 prototype game.xbe, fe/HUDTrackable.cpp (4 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 4 of 10 functions matched (40.00%). NOT COMPLETE YET.
// The 6 still to do are listed in their place in Original_Binary_Order_Proto.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] HUDTrackable::vfunc_00 (0x00177E30, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as CollisionBehaviourTypeGroup::vfunc_00 (0x000123B0), which was matched first;
// its addresses and names were swapped for this function's.
// HUDTrackable::vfunc_00 (0x00177E30, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_00410E58[];

class HUDTrackable
{
public:
    virtual void* vfunc_00();
};

void* HUDTrackable::vfunc_00()
{
    return DAT_00410E58;
}

// ============================================================================
// [VERIFIED] HUDTrackable::vfunc_27 (0x00177E40, 67 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// HUDTrackable::vfunc_27 (Proto 0x00177E40, 67 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    int sub_00173470();
};

extern "C" int __cdecl sub_00021D50(int);
extern "C" int __cdecl sub_00025120(int);
extern "C" void __cdecl sub_0016E150(void);

class HUDTrackable
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
    char m_pad04[0x4C];
    int m_Field50; // +0x50
    int m_Field54; // +0x54
    int m_Field58; // +0x58
};

int HUDTrackable::vfunc_27()
{
    int r_eax;

    sub_0016E150();
    r_eax = m_Field54;
    if (r_eax) {
        r_eax = sub_00021D50(r_eax);
        m_Field50 = r_eax;
    }
    r_eax = m_Field58;
    if (!r_eax) {
        r_eax = sub_00025120(96);
        if (r_eax) {
            r_eax = ((Object*)r_eax)->sub_00173470();
            m_Field58 = r_eax;
            return r_eax;
        }
        r_eax = 0;
        m_Field58 = 0;
    }
    return r_eax;
}

// ============================================================================
// [VERIFIED] HUDTrackable::vfunc_05 (0x00177E90, 68 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// HUDTrackable::vfunc_05 (Proto 0x00177E90, 68 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field58
{
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual void vfunc_05();
    virtual void vfunc_06(int, int, int);
};

extern "C" void __stdcall sub_0016E190(int);

class HUDTrackable
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual void vfunc_05(int a1);
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
    virtual void vfunc_44(int);
    virtual void vfunc_45();
    char m_pad04[0x44];
    int m_Field48; // +0x48
    int m_Field4C; // +0x4C
    char m_pad50[0x4];
    int m_Field54; // +0x54
    Field58* m_Field58; // +0x58
    char m_pad5C[0x8];
    int m_Field64; // +0x64
};

void HUDTrackable::vfunc_05(int a1)
{
    sub_0016E190(a1);
    vfunc_27();
    vfunc_44(m_Field64);
    vfunc_45();
    m_Field58->vfunc_06(m_Field54, (int)(&m_Field48), (int)(&m_Field4C));
}

// ============================================================================
// [VERIFIED] HUDTrackable::vfunc_01 (0x001785C0, 65 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// HUDTrackable::vfunc_01 (Proto 0x001785C0, 65 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    virtual void vfunc_00(int);
};

extern "C" char DAT_00399824[];
extern "C" char DAT_0039982C[];
extern "C" void __cdecl sub_00025160(int);

class HUDTrackable
{
public:
    virtual void vfunc_00();
    virtual HUDTrackable* vfunc_01(int a1);
    void sub_0016E130();
    char m_pad04[0x3C];
    int m_Field40; // +0x40
    char m_pad44[0x14];
    int m_Field58; // +0x58
};

HUDTrackable* HUDTrackable::vfunc_01(int a1)
{
    int t1;

    t1 = m_Field58;
    *(int*)this = (int)DAT_0039982C;
    m_Field40 = (int)DAT_00399824;
    if (m_Field58) {
        ((Object*)t1)->vfunc_00(1);
        m_Field58 = 0;
    }
    sub_0016E130();
    if (a1 & 1) {
        sub_00025160((int)this);
    }
    return this;
}

