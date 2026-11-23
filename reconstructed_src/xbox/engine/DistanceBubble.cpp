// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail Xbox default.xbe, engine/DistanceBubble.cpp (3 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 3 of 8 functions matched (37.50%). NOT COMPLETE YET.
// The 5 still to do are listed in their place in Original_Binary_Order_Xbox.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] DistanceBubble::vfunc_29 (0x001C25F0, 52 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// bin: xb
// va: 0x001C25F0
// what: 
// tool: the portal's starter code (no AI)

// DistanceBubble::vfunc_29 (0x001C25F0, 52 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_004195CC[];
extern "C" char DAT_0041A5BC[];
extern "C" int __cdecl sub_00023EC0(int);
extern "C" void __cdecl sub_00193150(void);
extern "C" int __cdecl sub_002FC034(int, int, int, int, int);

class DistanceBubble
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
    char m_pad04[0x60];
    int m_Field64; // +0x64
    int m_Field68; // +0x68
};

void DistanceBubble::vfunc_29()
{
    int t2;

    sub_00193150();
    t2 = m_Field68;
    if (m_Field68) {
        m_Field64 = sub_002FC034(sub_00023EC0(t2), 0, (int)DAT_004195CC, (int)DAT_0041A5BC, 0);
    }
}

// ============================================================================
// [VERIFIED] DistanceBubble::vfunc_00 (0x001C27B0, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// What it does: Returns DistanceBubble's static class record (ConcreteClassRep<DistanceBubble>), the object's run-time type.
// ============================================================================
// Same machine code as CollisionBehaviourTypeGroup::vfunc_00 (0x000123B0), which was matched first;
// its addresses and names were swapped for this function's.
// DistanceBubble::vfunc_00 (0x001C27B0, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0043800C[];

class DistanceBubble
{
public:
    virtual void* vfunc_00();
};

void* DistanceBubble::vfunc_00()
{
    return DAT_0043800C;
}

// ============================================================================
// [VERIFIED] DistanceBubble::vfunc_31 (0x001C2860, 106 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 /arch:SSE
// ============================================================================
// bin: xb
// va: 0x001C2860
// what: 
// tool: the portal's starter code (no AI)

// DistanceBubble::vfunc_31 (0x001C2860, 106 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_001930A0();
};

extern "C" float DAT_0039D664;
extern "C" char DAT_003C2CE0[];
extern "C" int __cdecl sub_000275B0(int, int);

class DistanceBubble
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
    void sub_00193910();
    char m_pad04[0x48];
    int m_Field4C; // +0x4C
    char m_pad50[0x1C];
    int m_Field6C; // +0x6C
    int m_Field70; // +0x70
    int m_Field74; // +0x74
    int m_Field78; // +0x78
};

void DistanceBubble::vfunc_31()
{
    int r_esi;

    r_esi = sub_000275B0(24, 7);
    if (r_esi) {
        ((Object*)r_esi)->sub_001930A0();
        *(int*)r_esi = (int)DAT_003C2CE0;
        *(float*)(r_esi + 8) = 0.0f;
        *(float*)(r_esi + 12) = 0.0f;
        *(float*)(r_esi + 16) = 0.0f;
        *(float*)(r_esi + 20) = DAT_0039D664;
    } else {
        r_esi = 0;
    }
    *(int*)(r_esi + 8) = m_Field6C;
    *(int*)(r_esi + 12) = m_Field70;
    *(int*)(r_esi + 16) = m_Field74;
    *(int*)(r_esi + 20) = m_Field78;
    m_Field4C = r_esi;
    sub_00193910();
}

