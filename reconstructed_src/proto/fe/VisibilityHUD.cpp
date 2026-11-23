// ============================================================================
// SCARFACE: THE WORLD IS YOURS — April 2006 prototype game.xbe, fe/VisibilityHUD.cpp (6 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 6 of 7 functions matched (85.71%). NOT COMPLETE YET.
// The 1 still to do are listed in their place in Original_Binary_Order_Proto.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] VisibilityHUD::vfunc_00 (0x0018DFB0, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as CollisionBehaviourTypeGroup::vfunc_00 (0x000123B0), which was matched first;
// its addresses and names were swapped for this function's.
// VisibilityHUD::vfunc_00 (0x0018DFB0, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_00411D54[];

class VisibilityHUD
{
public:
    virtual void* vfunc_00();
};

void* VisibilityHUD::vfunc_00()
{
    return DAT_00411D54;
}

// ============================================================================
// [VERIFIED] VisibilityHUD::vfunc_27 (0x0018DFC0, 88 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// VisibilityHUD::vfunc_27 (Proto 0x0018DFC0, 88 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0039D884[];
extern "C" char DAT_0039D89C[];
extern "C" char DAT_003F45D8[];
extern "C" char DAT_003F55F0[];
extern "C" char DAT_003F56C0[];
extern "C" int __cdecl sub_00021D50(int);
extern "C" void __cdecl sub_0016E150(void);
extern "C" int __cdecl sub_002C92F8(int, int, int, int, int);

class VisibilityHUD
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
    char m_pad04[0x3C];
    int m_Field40; // +0x40
    int m_Field44; // +0x44
};

void VisibilityHUD::vfunc_27()
{
    sub_0016E150();
    m_Field40 = sub_002C92F8(sub_00021D50((int)DAT_0039D89C), 0, (int)DAT_003F45D8, (int)DAT_003F56C0, 0);
    m_Field44 = sub_002C92F8(sub_00021D50((int)DAT_0039D884), 0, (int)DAT_003F45D8, (int)DAT_003F55F0, 0);
}

// ============================================================================
// [VERIFIED] VisibilityHUD::vfunc_05 (0x0018E020, 46 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// VisibilityHUD::vfunc_05 (Proto 0x0018E020, 46 bytes)
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
    virtual void vfunc_14(int);
};

extern "C" void __stdcall sub_0016E190(int);

class VisibilityHUD
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
    char m_pad04[0x40];
    int m_Field44; // +0x44
    int m_Field48; // +0x48
};

void VisibilityHUD::vfunc_05(int a1)
{
    int t4;

    sub_0016E190(a1);
    vfunc_27();
    t4 = *(int*)(*(int*)(m_Field44 + 40) + 56);
    m_Field48 = *(int*)(*(int*)(m_Field44 + 40) + 56);
    a1 = 0;
    ((Object*)t4)->vfunc_14(a1);
}

// ============================================================================
// [VERIFIED] VisibilityHUD::vfunc_29 (0x0018E090, 89 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// VisibilityHUD::vfunc_29 (Proto 0x0018E090, 89 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field40
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

struct Object
{
    void sub_0016E0B0();
};

extern "C" char DAT_0039D7C8[];
extern "C" int __cdecl sub_00025140(int, int);

class VisibilityHUD
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
    char m_pad30[0x10];
    Field40* m_Field40; // +0x40
    char m_pad44[0x8];
    int m_Field4C; // +0x4C
    unsigned short m_Field50; // +0x50
};

void VisibilityHUD::vfunc_29()
{
    int r_esi;

    r_esi = sub_00025140(16, 7);
    if (r_esi) {
        ((Object*)r_esi)->sub_0016E0B0();
        *(int*)r_esi = (int)DAT_0039D7C8;
        *(unsigned short*)(r_esi + 8) = 0;
        *(int*)(r_esi + 12) = 0;
    } else {
        r_esi = 0;
    }
    *(unsigned short*)(r_esi + 8) = m_Field50;
    *(int*)(r_esi + 12) = m_Field4C;
    m_Field2C = r_esi;
    sub_0016E260();
    m_Field40->vfunc_18(0);
}

// ============================================================================
// [VERIFIED] VisibilityHUD::vfunc_30 (0x0018E0F0, 17 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// bin: proto
// va: 0x0018E0F0
// what: 
// tool: the portal's starter code (no AI)

// VisibilityHUD::vfunc_30 (Proto 0x0018E0F0, 17 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field48
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
};

class VisibilityHUD
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
    char m_pad04[0x38];
    unsigned char m_Field3C; // +0x3C
    char m_pad3D[0xB];
    Field48* m_Field48; // +0x48
};

void VisibilityHUD::vfunc_30(int a1)
{
    if (m_Field3C & 1) {
        m_Field48->vfunc_09();
    }
}

// ============================================================================
// [VERIFIED] VisibilityHUD::vfunc_38 (0x0018E2D0, 75 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 /arch:SSE
// ============================================================================
// bin: proto
// va: 0x0018E2D0
// what: 
// tool: the portal's starter code (no AI)

// VisibilityHUD::vfunc_38 (Proto 0x0018E2D0, 75 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field48
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
    virtual void vfunc_14(float);
};

extern "C" float DAT_00393980;
extern "C" bool __stdcall sub_0016E830(int);

class VisibilityHUD
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
    char m_pad04[0x44];
    Field48* m_Field48; // +0x48
    int m_Field4C; // +0x4C
    short m_Field50; // +0x50
};

bool VisibilityHUD::vfunc_38(int a1)
{
    int t2;

    if (sub_0016E830(a1)) {
        return true;
    }
    t2 = m_Field4C;
    m_Field48->vfunc_14(((float)m_Field4C) / (((float)m_Field50) * DAT_00393980));
    m_Field4C = t2;
    return false;
}

