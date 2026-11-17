// ============================================================================
// SCARFACE: THE WORLD IS YOURS — April 2006 prototype game.xbe, fe/HUDMissionReadout.cpp (3 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 3 of 8 functions matched (37.50%). NOT COMPLETE YET.
// The 5 still to do are listed in their place in Original_Binary_Order_Proto.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] HUDMissionReadout::vfunc_27 (0x00178220, 80 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// HUDMissionReadout::vfunc_27 (Proto 0x00178220, 80 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    int sub_00173470();
};

extern "C" char DAT_003999D0[];
extern "C" int __cdecl sub_00021D50(int);
extern "C" int __cdecl sub_00025120(int);
extern "C" void __cdecl sub_0016E150(void);

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
    char m_pad04[0x4C];
    int m_Field50; // +0x50
    int m_Field54; // +0x54
    int m_Field58; // +0x58
    char m_pad5C[0x10];
    int m_Field6C; // +0x6C
};

void HUDMissionReadout::vfunc_27()
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
        } else {
            r_eax = 0;
        }
        m_Field58 = r_eax;
    }
    r_eax = sub_00021D50((int)DAT_003999D0);
    m_Field6C = r_eax;
}

// ============================================================================
// [VERIFIED] HUDMissionReadout::vfunc_00 (0x00178980, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as CollisionBehaviourTypeGroup::vfunc_00 (0x000123B0), which was matched first;
// its addresses and names were swapped for this function's.
// HUDMissionReadout::vfunc_00 (0x00178980, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_00410EDC[];

class HUDMissionReadout
{
public:
    virtual void* vfunc_00();
};

void* HUDMissionReadout::vfunc_00()
{
    return DAT_00410EDC;
}

// ============================================================================
// [VERIFIED] HUDMissionReadout::vfunc_00 (0x00178990, 64 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// HUDMissionReadout::vfunc_00 (Proto 0x00178990, 64 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct FieldM40
{
    int sub_001783C0(int);
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
    char m_pad08[0x10];
    int m_Field18; // +0x18
    int m_Field1C; // +0x1C
};

int HUDMissionReadout::vfunc_00(int a1, int a2)
{
    int r_eax, t1;

    r_eax = a1;
    if (a1 != 21) {
        if (a1 != m_Field1C) goto L_3C;
        r_eax = a2;
        r_eax = *(int*)(r_eax + 8);
        t1 = m_Field18;
        m_Field04 = r_eax;
        r_eax = ((Object*)t1)->vfunc_03(r_eax);
        *(unsigned char*)((char*)this - 0x4) |= 1;
        return r_eax;
    }
    r_eax = a2;
    r_eax = ((FieldM40*)(int)(((char*)this - 0x40)))->sub_001783C0(*(int*)(r_eax + 8));
L_3C:
    return r_eax;
}

