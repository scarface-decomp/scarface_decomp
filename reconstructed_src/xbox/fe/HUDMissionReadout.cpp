// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail Xbox default.xbe, fe/HUDMissionReadout.cpp (3 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 3 of 9 functions matched (33.33%). NOT COMPLETE YET.
// The 6 still to do are listed in their place in Original_Binary_Order_Xbox.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] HUDMissionReadout::vfunc_00 (0x001A32C0, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// What it does: Returns HUDMissionReadout's static class record (ConcreteClassRep<HUDMissionReadout>), the object's run-time type.
// ============================================================================
// Same machine code as CollisionBehaviourTypeGroup::vfunc_00 (0x000123B0), which was matched first;
// its addresses and names were swapped for this function's.
// HUDMissionReadout::vfunc_00 (0x001A32C0, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_00437288[];

class HUDMissionReadout
{
public:
    virtual void* vfunc_00();
};

void* HUDMissionReadout::vfunc_00()
{
    return DAT_00437288;
}

// ============================================================================
// [VERIFIED] HUDMissionReadout::vfunc_29 (0x001A32F0, 59 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// HUDMissionReadout::vfunc_29 (0x001A32F0, 59 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_003BDAB8[];
extern "C" char DAT_003BDAD0[];
extern "C" int __cdecl sub_00023EC0(int);
extern "C" void __cdecl sub_001A2FC0(void);

class HUDMissionReadout
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
    char m_pad04[0x7C];
    int m_Field80; // +0x80
    char m_pad84[0x1C];
    int m_FieldA0; // +0xA0
};

void HUDMissionReadout::vfunc_29()
{
    sub_001A2FC0();
    if (m_Field80 == 1) {
        m_FieldA0 = sub_00023EC0((int)DAT_003BDAD0);
        return;
    }
    m_FieldA0 = sub_00023EC0((int)DAT_003BDAB8);
}

// ============================================================================
// [VERIFIED] HUDMissionReadout::vfunc_00 (0x001A3330, 101 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// HUDMissionReadout::vfunc_00 (0x001A3330, 101 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct FieldM64
{
    int sub_001A2D90(int);
};

struct Object
{
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual int vfunc_03(int);
};

class HUDMissionReadout
{
public:
    virtual int vfunc_00(int a1, int a2);
    int m_Field04; // +0x04
    char m_pad08[0x14];
    int m_Field1C; // +0x1C
    int m_Field20; // +0x20
    char m_pad24[0x8];
    int m_Field2C; // +0x2C
};

int HUDMissionReadout::vfunc_00(int a1, int a2)
{
    int r_eax, t1;

    r_eax = a1;
    if (a1 != 24) {
        if (a1 != 27) {
            if (a1 != m_Field2C) goto L_61;
            r_eax = a2;
            r_eax = *(int*)(r_eax + 8);
            t1 = m_Field20;
            m_Field04 = r_eax;
            r_eax = ((Object*)t1)->vfunc_03(r_eax);
            *(unsigned char*)((char*)this - 0x4) |= 1;
            return r_eax;
        }
        if (m_Field1C != 2) goto L_61;
        r_eax = a2;
        r_eax = ((FieldM64*)(int)(((char*)this - 0x64)))->sub_001A2D90(*(int*)(r_eax + 8));
        return r_eax;
    }
    if (m_Field1C == 1) {
        r_eax = *(int*)(a2 + 8);
        r_eax = ((FieldM64*)(int)(((char*)this - 0x64)))->sub_001A2D90(r_eax);
    }
L_61:
    return r_eax;
}

