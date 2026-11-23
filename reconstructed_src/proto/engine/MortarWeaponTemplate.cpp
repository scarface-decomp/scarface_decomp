// ============================================================================
// SCARFACE: THE WORLD IS YOURS — April 2006 prototype game.xbe, engine/MortarWeaponTemplate.cpp (3 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: COMPLETE. All 3 functions are matched.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] MortarWeaponTemplate::vfunc_00 (0x001C4700, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as CollisionBehaviourTypeGroup::vfunc_00 (0x000123B0), which was matched first;
// its addresses and names were swapped for this function's.
// MortarWeaponTemplate::vfunc_00 (0x001C4700, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0041A97C[];

class MortarWeaponTemplate
{
public:
    virtual void* vfunc_00();
};

void* MortarWeaponTemplate::vfunc_00()
{
    return DAT_0041A97C;
}

// ============================================================================
// [VERIFIED] MortarWeaponTemplate::vfunc_05 (0x001C4710, 102 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 /arch:SSE
// ============================================================================
// bin: proto
// va: 0x001C4710
// what: 
// tool: the portal's starter code (no AI)

// MortarWeaponTemplate::vfunc_05 (Proto 0x001C4710, 102 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_004616C0[];
extern "C" void __stdcall sub_00028C40(int);
extern "C" int __cdecl sub_00028CF0(int, int);

class MortarWeaponTemplate
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual void vfunc_05(int a1);
    char m_pad04[0x20];
    int m_Field24; // +0x24
    char m_pad28[0x68];
    int m_Field90; // +0x90
    float m_Field94; // +0x94
    char m_pad98[0x40];
    int m_FieldD8; // +0xD8
    char m_padDC[0x4];
    int m_FieldE0; // +0xE0
};

void MortarWeaponTemplate::vfunc_05(int a1)
{
    int t3, t4;

    sub_00028C40(a1);
    DAT_004616C0[m_Field24] = (int)this;
    if (0.0f > m_Field94) {
        *(int*)((char*)this + 0x94) = m_Field90;
    }
    t3 = sub_00028CF0(m_FieldD8, 0);
    if (t3) {
        t4 = sub_00028CF0(*(int*)(t3 + 416), 0);
        if (!t4) goto L_62;
        m_FieldE0 = *(int*)(t4 + 48);
    }
L_62:
    ;
}

// ============================================================================
// [VERIFIED] MortarWeaponTemplate::vfunc_27 (0x001C4780, 78 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// MortarWeaponTemplate::vfunc_27 (Proto 0x001C4780, 78 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_00024AB0(int);
    void sub_00024AD0();
    int sub_001B33A0(int, int);
};

extern "C" char DAT_0037CD30[];
extern "C" int __cdecl sub_00025140(int, int);

class MortarWeaponTemplate
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
    virtual int vfunc_27();
    void sub_001C4370(int);
};

int MortarWeaponTemplate::vfunc_27()
{
    int local_4, r_esi, t2;

    ((Object*)(int)(&local_4))->sub_00024AB0(9);
    t2 = sub_00025140(320, 9);
    if (t2) {
        r_esi = ((Object*)t2)->sub_001B33A0((int)DAT_0037CD30, 9);
    } else {
        r_esi = 0;
    }
    sub_001C4370(r_esi);
    ((Object*)(int)(&local_4))->sub_00024AD0();
    return r_esi;
}

