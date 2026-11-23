// ============================================================================
// SCARFACE: THE WORLD IS YOURS — April 2006 prototype game.xbe, fe/TeleportHUD.cpp (4 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 4 of 6 functions matched (66.67%). NOT COMPLETE YET.
// The 2 still to do are listed in their place in Original_Binary_Order_Proto.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] TeleportHUD::vfunc_00 (0x0018DB20, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as CollisionBehaviourTypeGroup::vfunc_00 (0x000123B0), which was matched first;
// its addresses and names were swapped for this function's.
// TeleportHUD::vfunc_00 (0x0018DB20, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_00411BD8[];

class TeleportHUD
{
public:
    virtual void* vfunc_00();
};

void* TeleportHUD::vfunc_00()
{
    return DAT_00411BD8;
}

// ============================================================================
// [VERIFIED] TeleportHUD::vfunc_42 (0x0018DBB0, 53 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// TeleportHUD::vfunc_42 (Proto 0x0018DBB0, 53 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0039D6D4[];
extern "C" int DAT_0045E828;
extern "C" void __cdecl sub_00065ED0(int, int, int, int, int);
extern "C" void __cdecl sub_0016E4C0(void);

class TeleportHUD
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
    virtual int vfunc_42();
    void sub_00182E00();
    char m_pad04[0x44];
    int m_Field48; // +0x48
    char m_pad4C[0x18];
    int m_Field64; // +0x64
};

int TeleportHUD::vfunc_42()
{
    int t4;

    sub_0016E4C0();
    sub_00182E00();
    sub_00065ED0((int)DAT_0039D6D4, 0, 0, 0, -1);
    t4 = DAT_0045E828;
    m_Field64 = DAT_0045E828;
    m_Field48 = 1;
    return t4;
}

// ============================================================================
// [VERIFIED] TeleportHUD::vfunc_30 (0x0018DBF0, 84 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// bin: proto
// va: 0x0018DBF0
// what: 
// tool: the portal's starter code (no AI)

// TeleportHUD::vfunc_30 (Proto 0x0018DBF0, 84 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field7C
{
    void sub_00023EB0(int);
};

class TeleportHUD
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
    virtual void vfunc_30(int a1);
    void sub_001819F0();
    void sub_001856F0();
    void sub_001B7A10();
    char m_pad04[0x44];
    int m_Field48; // +0x48
    char m_pad4C[0x18];
    int m_Field64; // +0x64
    char m_pad68[0x10];
    bool m_Field78; // +0x78
    char m_pad79[0x3];
    Field7C* m_Field7C; // +0x7C
};

void TeleportHUD::vfunc_30(int a1)
{
    int t3;

    if (m_Field7C) {
        m_Field7C->sub_00023EB0(0);
    }
    sub_001819F0();
    t3 = m_Field64;
    if (m_Field64) {
        if (*(int*)(t3 + 104)) goto L_50;
        if (*(bool*)(t3 + 208)) goto L_50;
        sub_001856F0();
        sub_001B7A10();
        if (!m_Field78) goto L_50;
        m_Field48 = 2;
        m_Field78 = false;
    }
L_50:
    ;
}

// ============================================================================
// [VERIFIED] TeleportHUD::vfunc_01 (0x0018DD60, 50 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as AICommandSequencer::vfunc_01 (Proto 0x00117EF0), which was matched first;
// its addresses and names were swapped for this function's.
// TeleportHUD::vfunc_01 (Proto 0x0018DD60, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0039D604[];
extern "C" void __cdecl sub_00025160(int);
extern "C" void __cdecl sub_00182C30(void);

class TeleportHUD
{
public:
    virtual void vfunc_00();
    virtual TeleportHUD* vfunc_01(int a1);
    void sub_0016E130();
    void sub_001856B0();
};

TeleportHUD* TeleportHUD::vfunc_01(int a1)
{
    *(int*)this = (int)DAT_0039D604;
    sub_00182C30();
    sub_001856B0();
    sub_0016E130();
    if (a1 & 1) {
        sub_00025160((int)this);
    }
    return this;
}

