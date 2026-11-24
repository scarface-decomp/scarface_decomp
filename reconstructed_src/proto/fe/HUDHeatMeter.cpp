// ============================================================================
// SCARFACE: THE WORLD IS YOURS — April 2006 prototype game.xbe, fe/HUDHeatMeter.cpp (6 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 6 of 7 functions matched (85.71%). NOT COMPLETE YET.
// The 1 still to do are listed in their place in Original_Binary_Order_Proto.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] HUDHeatMeter::vfunc_27 (0x001714A0, 5 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as SoundEntityLoader::vfunc_04 (0x00064FA0), which was matched first;
// its addresses and names were swapped for this function's.
// HUDHeatMeter::vfunc_27 (0x001714A0, 5 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __cdecl sub_00170E20(void);

class HUDHeatMeter
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_27();
};

void HUDHeatMeter::vfunc_27()
{
    sub_00170E20();
}

// ============================================================================
// [VERIFIED] HUDHeatMeter::vfunc_30 (0x001714B0, 112 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 /arch:SSE
// ============================================================================
// bin: proto
// va: 0x001714B0
// what: 
// tool: the portal's starter code (no AI)

// HUDHeatMeter::vfunc_30 (Proto 0x001714B0, 112 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field44
{
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual void vfunc_05();
    virtual void vfunc_06(int);
    virtual bool vfunc_07();
};

extern "C" void __stdcall sub_0021AF00(int);

class HUDHeatMeter
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
    virtual void vfunc_31();
    virtual void vfunc_32();
    virtual void vfunc_33(int, int);
    char m_pad04[0x38];
    unsigned char m_Field3C; // +0x3C
    char m_pad3D[0x7];
    Field44* m_Field44; // +0x44
    char m_pad48[0x2C];
    float m_Field74; // +0x74
    float m_Field78; // +0x78
};

void HUDHeatMeter::vfunc_30(int a1)
{
    int r_edi;

    if (m_Field3C & 1) {
        r_edi = a1;
        sub_0021AF00(a1);
        if (m_Field44->vfunc_07()) {
            m_Field44->vfunc_06(a1);
            return;
        }
        if (m_Field78 >= m_Field74) {
            m_Field3C = (unsigned char)(m_Field3C & 254);
            m_Field78 = 0.0f;
            vfunc_33(0, 0);
            return;
        }
        m_Field78 = *(float*)(r_edi + 8) + m_Field78;
    }
}

// ============================================================================
// [VERIFIED] HUDHeatMeter::vfunc_38 (0x00171540, 42 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 /arch:SSE
// ============================================================================
// bin: proto
// va: 0x00171540
// what: 
// tool: the portal's starter code (no AI)

// HUDHeatMeter::vfunc_38 (Proto 0x00171540, 42 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" bool __stdcall sub_00170F00(int);

class HUDHeatMeter
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
    char m_pad04[0x38];
    unsigned char m_Field3C; // +0x3C
    char m_pad3D[0x3B];
    float m_Field78; // +0x78
};

bool HUDHeatMeter::vfunc_38(int a1)
{
    if (sub_00170F00(0)) {
        return true;
    }
    m_Field3C = (unsigned char)(m_Field3C & 254);
    m_Field78 = 0.0f;
    return false;
}

// ============================================================================
// [VERIFIED] HUDHeatMeter::vfunc_45 (0x00171570, 42 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// HUDHeatMeter::vfunc_45 (Proto 0x00171570, 42 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field44
{
    virtual void vfunc_00();
    virtual void vfunc_01(int);
};

class HUDHeatMeter
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
    virtual void vfunc_33(int, int);
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
    virtual void vfunc_45(int a1, int a2);
    char m_pad04[0x38];
    unsigned char m_Field3C; // +0x3C
    char m_pad3D[0x7];
    Field44* m_Field44; // +0x44
};

void HUDHeatMeter::vfunc_45(int a1, int a2)
{
    m_Field44->vfunc_01(a1);
    m_Field3C = (unsigned char)(m_Field3C | 1);
    vfunc_33(1, 0);
}

// ============================================================================
// [VERIFIED] HUDHeatMeter::vfunc_32 (0x00171600, 20 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as HUDTrackable::vfunc_37 (0x001A2BA0), which was matched first;
// its addresses and names were swapped for this function's.
// bin: xb
// va: 0x00171600
// what: Calls sub_0016E3C0(a1, 0) on this trackable HUD element and returns whether the result is non-zero.
// tool: Gemini 4 Neon

class HUDHeatMeter
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
    virtual unsigned char vfunc_32(int a1, int);
    unsigned char sub_0016E3C0(int a1, int a2);
};

unsigned char HUDHeatMeter::vfunc_32(int a1, int)
{
    return sub_0016E3C0(a1, 0) != 0;
}

// ============================================================================
// [VERIFIED] HUDHeatMeter::vfunc_00 (0x00172010, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as CollisionBehaviourTypeGroup::vfunc_00 (0x000123B0), which was matched first;
// its addresses and names were swapped for this function's.
// HUDHeatMeter::vfunc_00 (0x00172010, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_00410814[];

class HUDHeatMeter
{
public:
    virtual void* vfunc_00();
};

void* HUDHeatMeter::vfunc_00()
{
    return DAT_00410814;
}

