// ============================================================================
// SCARFACE: THE WORLD IS YOURS — April 2006 prototype game.xbe, fe/BusinessHUD.cpp (3 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 3 of 9 functions matched (33.33%). NOT COMPLETE YET.
// The 6 still to do are listed in their place in Original_Binary_Order_Proto.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] BusinessHUD::vfunc_32 (0x0016C080, 72 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// BusinessHUD::vfunc_32 (Proto 0x0016C080, 72 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_000D99E0();
};

extern "C" int __stdcall sub_000D8FA0(int, int, int);
extern "C" bool __stdcall sub_0016E3C0(int, int);

class BusinessHUD
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
    virtual bool vfunc_32(int a1, int a2);
    char m_pad04[0x50];
    unsigned char m_Field54; // +0x54
};

bool BusinessHUD::vfunc_32(int a1, int a2)
{
    if (sub_0016E3C0(a1, a2)) {
        return true;
    }
    if (!((unsigned char)a1)) {
        if (!m_Field54) goto L_41;
        ((Object*)sub_000D8FA0(133, 0, 0))->sub_000D99E0();
        m_Field54 = (unsigned char)a1;
    }
L_41:
    return false;
}

// ============================================================================
// [VERIFIED] BusinessHUD::vfunc_00 (0x0016C2A0, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as CollisionBehaviourTypeGroup::vfunc_00 (0x000123B0), which was matched first;
// its addresses and names were swapped for this function's.
// BusinessHUD::vfunc_00 (0x0016C2A0, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_004101E8[];

class BusinessHUD
{
public:
    virtual void* vfunc_00();
};

void* BusinessHUD::vfunc_00()
{
    return DAT_004101E8;
}

// ============================================================================
// [VERIFIED] BusinessHUD::vfunc_39 (0x001825E0, 136 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// BusinessHUD::vfunc_39 (Proto 0x001825E0, 136 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    virtual void vfunc_00(int);
};

extern "C" char DAT_0039B820[];
extern "C" char DAT_0039B83C[];
extern "C" int DAT_0045E07C;
extern "C" void __cdecl sub_00065ED0(int, int, int, int, int);

class BusinessHUD
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
    bool sub_0016E890(int);
    char m_pad04[0x44];
    int m_Field48; // +0x48
    int m_Field4C; // +0x4C
    char m_pad50[0x4];
    bool m_Field54; // +0x54
};

bool BusinessHUD::vfunc_39(int a1)
{
    int t2, t4;

    if (!m_Field54) {
        *(unsigned char*)(DAT_0045E07C + 77) &= 253;
    }
    if (sub_0016E890(a1)) {
        return true;
    }
    t2 = m_Field48;
    if (m_Field48) {
        ((Object*)t2)->vfunc_00(1);
        m_Field48 = 0;
    }
    t4 = m_Field4C;
    if (m_Field4C) {
        ((Object*)t4)->vfunc_00(1);
        m_Field4C = 0;
    }
    sub_00065ED0((int)DAT_0039B83C, 0, 0, 0, -1);
    if (!m_Field54) {
        sub_00065ED0((int)DAT_0039B820, 0, 0, 0, -1);
    }
    return false;
}

