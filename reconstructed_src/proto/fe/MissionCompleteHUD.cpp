// ============================================================================
// SCARFACE: THE WORLD IS YOURS — April 2006 prototype game.xbe, fe/MissionCompleteHUD.cpp (3 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 3 of 6 functions matched (50.00%). NOT COMPLETE YET.
// The 3 still to do are listed in their place in Original_Binary_Order_Proto.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] MissionCompleteHUD::vfunc_00 (0x001726B0, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as CollisionBehaviourTypeGroup::vfunc_00 (0x000123B0), which was matched first;
// its addresses and names were swapped for this function's.
// MissionCompleteHUD::vfunc_00 (0x001726B0, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_00410ABC[];

class MissionCompleteHUD
{
public:
    virtual void* vfunc_00();
};

void* MissionCompleteHUD::vfunc_00()
{
    return DAT_00410ABC;
}

// ============================================================================
// [VERIFIED] MissionCompleteHUD::vfunc_39 (0x001727C0, 177 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// MissionCompleteHUD::vfunc_39 (Proto 0x001727C0, 177 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    virtual void vfunc_00(int);
    void sub_001ECB40(int);
};

extern "C" char DAT_00398E50[];
extern "C" int DAT_00462F98;
extern "C" void __cdecl sub_00065ED0(int, int, int, int, int);
extern "C" bool __stdcall sub_0016E890(int);

class MissionCompleteHUD
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
    char m_pad04[0x3C];
    int m_Field40; // +0x40
    char m_pad44[0x14];
    int m_Field58; // +0x58
    char m_pad5C[0x24];
    int m_Field80; // +0x80
    int m_Field84; // +0x84
    int m_Field88; // +0x88
};

bool MissionCompleteHUD::vfunc_39(int a1)
{
    int r_ebp, r_ebx, r_edi, t2, t4, t6, t8, t10;

    if (sub_0016E890(a1)) {
        return true;
    }
    r_ebp = 0;
    t2 = m_Field58;
    if (m_Field58) {
        ((Object*)t2)->vfunc_00(1);
        m_Field58 = 0;
    }
    t4 = m_Field80;
    if (m_Field80 != r_ebp) {
        ((Object*)t4)->vfunc_00(1);
        m_Field80 = r_ebp;
    }
    t6 = m_Field84;
    if (m_Field84 != r_ebp) {
        ((Object*)t6)->vfunc_00(1);
        m_Field84 = r_ebp;
    }
    r_edi = (int)(&m_Field40);
    r_ebx = 6;
    do {
        t8 = *(int*)r_edi;
        if (*(int*)r_edi != r_ebp) {
            ((Object*)t8)->vfunc_00(1);
        }
        *(int*)r_edi = r_ebp;
        r_edi += 4;
        r_ebx -= 1;
    } while (r_ebx);
    t10 = m_Field88;
    if (m_Field88 != r_ebp) {
        ((Object*)t10)->vfunc_00(1);
        m_Field88 = r_ebp;
    }
    ((Object*)DAT_00462F98)->sub_001ECB40(r_ebp);
    sub_00065ED0((int)DAT_00398E50, r_ebp, r_ebp, r_ebp, -1);
    return false;
}

// ============================================================================
// [VERIFIED] MissionCompleteHUD::vfunc_01 (0x00172BF0, 30 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as Collidable::vfunc_03 (0x00011F20), which was matched first;
// its addresses and names were swapped for this function's.
// MissionCompleteHUD::vfunc_01 (0x00172BF0, 30 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __cdecl sub_001726C0(void);
extern "C" void __cdecl sub_00025160(int);

class MissionCompleteHUD
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual MissionCompleteHUD* vfunc_01(int a1);
};

MissionCompleteHUD* MissionCompleteHUD::vfunc_01(int a1)
{
    sub_001726C0();
    if (a1 & 1) {
        sub_00025160((int)this);
    }
    return this;
}

