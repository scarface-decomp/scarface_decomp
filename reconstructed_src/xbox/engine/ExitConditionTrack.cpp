// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail Xbox default.xbe, engine/ExitConditionTrack.cpp (8 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 8 of 9 functions matched (88.89%). NOT COMPLETE YET.
// The 1 still to do are listed in their place in Original_Binary_Order_Xbox.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] ExitConditionTrack::vfunc_26 (0x000E80A0, 16 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 /arch:SSE
// What it does: Stores a number at +0x20 and returns true.
// ============================================================================
// bin: xb
// va: 0x000E80A0
// what: Stores a number at +0x20 and returns true.
// tool: Claude Opus 5.5 (generated from the shape 'set float field, return true', checked on decomp.me preset 266 by example)
class Class_000E80A0
{
public:
    bool sub_000E80A0(float value);
    char m_pad00[0x20];
    float m_Field20; // +0x20
};

bool Class_000E80A0::sub_000E80A0(float value)
{
    m_Field20 = value;
    return true;
}

// ============================================================================
// [VERIFIED] ExitConditionTrack::vfunc_08 (0x000E91B0, 16 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as SpeedCondition::vfunc_08 (0x000DD280), which was matched first;
// its addresses and names were swapped for this function's.
// ExitConditionTrack::vfunc_08 (0x000E91B0, 16 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_004878BC;

class ExitConditionTrack
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
    virtual int vfunc_08(int a1);
};

int ExitConditionTrack::vfunc_08(int a1)
{
    return *(int*)(DAT_004878BC + (a1 * 4));
}

// ============================================================================
// [VERIFIED] ExitConditionTrack::vfunc_23 (0x000E9210, 4 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as ExitConditionTrack::vfunc_23 (Proto 0x000D5B30), which was matched first;
// its addresses and names were swapped for this function's.
// ExitConditionTrack::vfunc_23 (Proto 0x000E9210, 4 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

class ExitConditionTrack
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
    virtual float vfunc_23();
    char m_pad04[0x18];
    float m_Field1C; // +0x1C
};

float ExitConditionTrack::vfunc_23()
{
    return m_Field1C;
}

// ============================================================================
// [VERIFIED] ExitConditionTrack::vfunc_24 (0x000E9220, 16 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 /arch:SSE
// What it does: Stores a number at +0x1C and returns true.
// ============================================================================
// bin: xb
// va: 0x000E9220
// what: Stores a number at +0x1C and returns true.
// tool: Claude Opus 5.5 (generated from the shape 'set float field, return true', checked on decomp.me preset 266 by example)
class Class_000E9220
{
public:
    bool sub_000E9220(float value);
    char m_pad00[0x1C];
    float m_Field1C; // +0x1C
};

bool Class_000E9220::sub_000E9220(float value)
{
    m_Field1C = value;
    return true;
}

// ============================================================================
// [VERIFIED] ExitConditionTrack::vfunc_25 (0x000E9230, 4 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as ExitConditionTrack::vfunc_25 (Proto 0x000D5B40), which was matched first;
// its addresses and names were swapped for this function's.
// ExitConditionTrack::vfunc_25 (Proto 0x000E9230, 4 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

class ExitConditionTrack
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
    virtual float vfunc_25();
    char m_pad04[0x1C];
    float m_Field20; // +0x20
};

float ExitConditionTrack::vfunc_25()
{
    return m_Field20;
}

// ============================================================================
// [VERIFIED] ExitConditionTrack::vfunc_33 (0x000E9240, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as GlobalVehicleSound::vfunc_12 (0x00065430), which was matched first;
// its addresses and names were swapped for this function's.
// ExitConditionTrack::vfunc_33 (0x000E9240, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_004878C4;

class ExitConditionTrack
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
    virtual int vfunc_33();
};

int ExitConditionTrack::vfunc_33()
{
    return DAT_004878C4;
}

// ============================================================================
// [VERIFIED] ExitConditionTrack::vfunc_17 (0x000E9250, 43 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 /arch:SSE
// ============================================================================
// Same machine code as ExitConditionTrack::vfunc_17 (Proto 0x000D6C00), which was matched first;
// its addresses and names were swapped for this function's.
// bin: proto
// va: 0x000E9250
// what: 
// tool: the portal's starter code (no AI)

// ExitConditionTrack::vfunc_17 (Proto 0x000E9250, 43 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" float DAT_0039D65C;

class ExitConditionTrack
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
    virtual float vfunc_17();
    char m_pad04[0x18];
    float m_Field1C; // +0x1C
    float m_Field20; // +0x20
    char m_pad24[0x8];
    float m_Field2C; // +0x2C
};

float ExitConditionTrack::vfunc_17()
{
    if (m_Field1C > m_Field20) {
        return DAT_0039D65C;
    }
    if (m_Field2C > m_Field20) {
        return m_Field2C - m_Field1C;
    }
    return m_Field20 - m_Field1C;
}

// ============================================================================
// [VERIFIED] ExitConditionTrack::vfunc_03 (0x000E92C0, 54 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// What it does: ExitConditionTrack's deleting destructor: destroys the object, frees its memory when asked (flag bit 0), and returns it.
// ============================================================================
// Same machine code as ExitConditionTrack::vfunc_03 (Proto 0x000D6C40), which was matched first;
// its addresses and names were swapped for this function's.
// ExitConditionTrack::vfunc_03 (Proto 0x000E92C0, 54 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field30
{
    void sub_0023F4F0();
};

struct Field3C
{
    void sub_0023F2F0();
};

extern "C" char DAT_003A89B4[];
extern "C" void __cdecl sub_0023F7A0(int);

class ExitConditionTrack
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual ExitConditionTrack* vfunc_03(int a1);
    void sub_00022970();
    char m_pad04[0x2C];
    Field30 m_Field30; // +0x30
    char m_pad31[0xB];
    Field3C m_Field3C; // +0x3C
};

ExitConditionTrack* ExitConditionTrack::vfunc_03(int a1)
{
    *(int*)this = (int)DAT_003A89B4;
    m_Field3C.sub_0023F2F0();
    m_Field30.sub_0023F4F0();
    sub_00022970();
    if (a1 & 1) {
        sub_0023F7A0((int)this);
    }
    return this;
}

