// ============================================================================
// SCARFACE: THE WORLD IS YOURS — April 2006 prototype game.xbe, fe/HUDImageDisplay.cpp (6 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 6 of 10 functions matched (60.00%). NOT COMPLETE YET.
// The 4 still to do are listed in their place in Original_Binary_Order_Proto.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] HUDImageDisplay::vfunc_30 (0x0016E9B0, 30 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// HUDImageDisplay::vfunc_30 (Proto 0x0016E9B0, 30 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __stdcall sub_0021AF00(int);

class HUDImageDisplay
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
    virtual void vfunc_33();
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
    virtual void vfunc_45(int);
};

void HUDImageDisplay::vfunc_30(int a1)
{
    sub_0021AF00(a1);
    vfunc_45(a1);
}

// ============================================================================
// [VERIFIED] HUDImageDisplay::vfunc_44 (0x0016E9D0, 73 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// bin: proto
// va: 0x0016E9D0
// what: 
// tool: the portal's starter code (no AI)

// HUDImageDisplay::vfunc_44 (Proto 0x0016E9D0, 73 bytes)
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
    virtual void vfunc_14();
    virtual void vfunc_15();
    virtual void vfunc_16();
    virtual void vfunc_17();
    virtual void vfunc_18(int);
};

class HUDImageDisplay
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
    virtual void vfunc_42();
    virtual void vfunc_43();
    virtual void vfunc_44(int a1, int a2);
    virtual void vfunc_45();
    virtual int vfunc_46(int);
    char m_pad04[0x40];
    int m_Field44; // +0x44
    char m_pad48[0x8];
    int m_Field50; // +0x50
    int m_Field54; // +0x54
    int m_Field58; // +0x58
};

void HUDImageDisplay::vfunc_44(int a1, int a2)
{
    int t1, t3;

    if (m_Field58 != -1) {
        t1 = m_Field44;
        if (!m_Field44) goto L_18;
        ((Object*)t1)->vfunc_18(0);
    }
L_18:
    t3 = vfunc_46(a1);
    m_Field44 = t3;
    if (t3) {
        ((Object*)t3)->vfunc_18(1);
        m_Field58 = a1;
        m_Field54 = a2;
        m_Field50 = a2;
    }
}

// ============================================================================
// [VERIFIED] HUDImageDisplay::vfunc_45 (0x0016EA20, 102 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// bin: proto
// va: 0x0016EA20
// what: 
// tool: the portal's starter code (no AI)

// HUDImageDisplay::vfunc_45 (Proto 0x0016EA20, 102 bytes)
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
    virtual void vfunc_14();
    virtual void vfunc_15();
    virtual void vfunc_16();
    virtual void vfunc_17();
    virtual void vfunc_18(int);
};

class HUDImageDisplay
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
    virtual void vfunc_42();
    virtual void vfunc_43();
    virtual void vfunc_44();
    virtual void vfunc_45(int a1);
};

void HUDImageDisplay::vfunc_45(int a1)
{
    int r_eax, r_ecx, t1;

    r_ecx = (int)this;
    r_eax = (int)this;
    if (*(int*)(r_eax + 88) == -1) goto L_63;
    r_ecx = *(int*)(r_eax + 84);
    if (r_ecx < *(int*)(r_eax + 80)) {
        *(int*)(r_eax + 80) = r_ecx;
    }
    if (r_ecx > 0) {
        r_ecx = a1;
        *(int*)(r_eax + 80) -= *(int*)(r_ecx + 4);
    }
    r_ecx = *(int*)(r_eax + 68);
    if (!r_ecx) goto L_63;
    t1 = *(int*)(r_eax + 80);
    if (*(int*)(r_eax + 80) <= 0) {
        if (t1 == -1) goto L_56;
        *(int*)(r_eax + 88) = -1;
        *(int*)(r_eax + 80) = 0;
        *(int*)(r_eax + 84) = 0;
        r_eax = *(int*)r_ecx;
        a1 = 0;
        ((void (__stdcall*)(int))*(int*)(r_eax + 72))(a1);
        return;
    }
L_56:
    a1 = 1;
    ((Object*)r_ecx)->vfunc_18(a1);
    return;
L_63:
    ;
}

// ============================================================================
// [VERIFIED] HUDImageDisplay::vfunc_38 (0x0016EB20, 69 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// HUDImageDisplay::vfunc_38 (Proto 0x0016EB20, 69 bytes)
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
    virtual void vfunc_14();
    virtual void vfunc_15();
    virtual void vfunc_16();
    virtual void vfunc_17();
    virtual void vfunc_18(int);
};

extern "C" bool __stdcall sub_0016E830(int);

class HUDImageDisplay
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
    virtual void vfunc_39();
    virtual void vfunc_40();
    virtual void vfunc_41();
    virtual void vfunc_42();
    virtual void vfunc_43();
    virtual void vfunc_44();
    virtual void vfunc_45();
    virtual int vfunc_46(int);
};

bool HUDImageDisplay::vfunc_38(int a1)
{
    int r_ebx, r_esi, t2;

    r_ebx = 0;
    if (sub_0016E830(a1)) {
        return true;
    }
    r_esi = 0;
    do {
        t2 = vfunc_46(r_esi);
        if (t2) {
            ((Object*)t2)->vfunc_18(0);
        }
        r_esi += 1;
    } while (r_esi < 4);
    return false;
}

// ============================================================================
// [VERIFIED] HUDImageDisplay::vfunc_00 (0x0016EC10, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as CollisionBehaviourTypeGroup::vfunc_00 (0x000123B0), which was matched first;
// its addresses and names were swapped for this function's.
// HUDImageDisplay::vfunc_00 (0x0016EC10, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_004105CC[];

class HUDImageDisplay
{
public:
    virtual void* vfunc_00();
};

void* HUDImageDisplay::vfunc_00()
{
    return DAT_004105CC;
}

// ============================================================================
// [VERIFIED] HUDImageDisplay::vfunc_01 (0x0016EC20, 86 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// HUDImageDisplay::vfunc_01 (Proto 0x0016EC20, 86 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_001902E0();
};

extern "C" char DAT_00397EDC[];
extern "C" char DAT_00397EE4[];
extern "C" void __cdecl sub_00025160(int);

class HUDImageDisplay
{
public:
    virtual void vfunc_00();
    virtual HUDImageDisplay* vfunc_01(int a1);
    void sub_0016E130();
    char m_pad04[0x3C];
    int m_Field40; // +0x40
    char m_pad44[0x4];
    int m_Field48; // +0x48
    int m_Field4C; // +0x4C
};

HUDImageDisplay* HUDImageDisplay::vfunc_01(int a1)
{
    int t1, t3;

    t1 = m_Field4C;
    *(int*)this = (int)DAT_00397EE4;
    m_Field40 = (int)DAT_00397EDC;
    if (m_Field4C) {
        sub_00025160(t1);
    }
    t3 = m_Field48;
    if (m_Field48) {
        ((Object*)t3)->sub_001902E0();
        sub_00025160(t3);
    }
    sub_0016E130();
    if (a1 & 1) {
        sub_00025160((int)this);
    }
    return this;
}

