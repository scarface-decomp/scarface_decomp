// ============================================================================
// SCARFACE: THE WORLD IS YOURS — April 2006 prototype game.xbe, engine/DistanceBubble.cpp (3 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 3 of 8 functions matched (37.50%). NOT COMPLETE YET.
// The 5 still to do are listed in their place in Original_Binary_Order_Proto.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] DistanceBubble::vfunc_27 (0x0018E1A0, 52 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// bin: proto
// va: 0x0018E1A0
// what: 
// tool: the portal's starter code (no AI)

// DistanceBubble::vfunc_27 (Proto 0x0018E1A0, 52 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_003F45D8[];
extern "C" char DAT_003F55F0[];
extern "C" int __cdecl sub_00021D50(int);
extern "C" void __cdecl sub_0016E150(void);
extern "C" int __cdecl sub_002C92F8(int, int, int, int, int);

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
    char m_pad04[0x3C];
    int m_Field40; // +0x40
    int m_Field44; // +0x44
};

void DistanceBubble::vfunc_27()
{
    int t2;

    sub_0016E150();
    t2 = m_Field44;
    if (m_Field44) {
        m_Field40 = sub_002C92F8(sub_00021D50(t2), 0, (int)DAT_003F45D8, (int)DAT_003F55F0, 0);
    }
}

// ============================================================================
// [VERIFIED] DistanceBubble::vfunc_00 (0x0018E370, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as CollisionBehaviourTypeGroup::vfunc_00 (0x000123B0), which was matched first;
// its addresses and names were swapped for this function's.
// DistanceBubble::vfunc_00 (0x0018E370, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_00411D80[];

class DistanceBubble
{
public:
    virtual void* vfunc_00();
};

void* DistanceBubble::vfunc_00()
{
    return DAT_00411D80;
}

// ============================================================================
// [VERIFIED] DistanceBubble::vfunc_29 (0x0018E3D0, 106 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 /arch:SSE
// ============================================================================
// bin: proto
// va: 0x0018E3D0
// what: 
// tool: the portal's starter code (no AI)

// DistanceBubble::vfunc_29 (Proto 0x0018E3D0, 106 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0016E0B0();
};

extern "C" float DAT_0037CE50;
extern "C" char DAT_0039D8B4[];
extern "C" int __cdecl sub_00025140(int, int);

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
    void sub_0016E260();
    char m_pad04[0x28];
    int m_Field2C; // +0x2C
    char m_pad30[0x18];
    int m_Field48; // +0x48
    int m_Field4C; // +0x4C
    int m_Field50; // +0x50
    int m_Field54; // +0x54
};

void DistanceBubble::vfunc_29()
{
    int r_esi;

    r_esi = sub_00025140(24, 7);
    if (r_esi) {
        ((Object*)r_esi)->sub_0016E0B0();
        *(int*)r_esi = (int)DAT_0039D8B4;
        *(float*)(r_esi + 8) = 0.0f;
        *(float*)(r_esi + 12) = 0.0f;
        *(float*)(r_esi + 16) = 0.0f;
        *(float*)(r_esi + 20) = DAT_0037CE50;
    } else {
        r_esi = 0;
    }
    *(int*)(r_esi + 8) = m_Field48;
    *(int*)(r_esi + 12) = m_Field4C;
    *(int*)(r_esi + 16) = m_Field50;
    *(int*)(r_esi + 20) = m_Field54;
    m_Field2C = r_esi;
    sub_0016E260();
}

