// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail Xbox default.xbe, engine/GangMember.cpp (2 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 2 of 3 functions matched (66.67%). NOT COMPLETE YET.
// The 1 still to do are listed in their place in Original_Binary_Order_Xbox.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] GangMember::vfunc_00 (0x0016E290, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// What it does: Returns GangMember's static class record (ConcreteClassRep<GangMember>), the object's run-time type.
// ============================================================================
// Same machine code as CollisionBehaviourTypeGroup::vfunc_00 (0x000123B0), which was matched first;
// its addresses and names were swapped for this function's.
// GangMember::vfunc_00 (0x0016E290, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_00430E4C[];

class GangMember
{
public:
    virtual void* vfunc_00();
};

void* GangMember::vfunc_00()
{
    return DAT_00430E4C;
}

// ============================================================================
// [VERIFIED] GangMember::vfunc_13 (0x0016F410, 692 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// GangMember::vfunc_13 (0x0016F410, 692 bytes)
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
    virtual void vfunc_29(int);
    int sub_00098BB0(int);
    void sub_000F0FB0(int);
    void sub_000F14C0(int, int);
    int sub_000F14E0(int);
    void sub_000F6100(int, int);
    void sub_00114410(int);
    void sub_00114AE0(int);
};

extern "C" char DAT_003B4F0C[];
extern "C" char DAT_003B521C[];
extern "C" char DAT_003B5234[];
extern "C" int DAT_00489828;
extern "C" Object DAT_0048AC54;
extern "C" int DAT_0048AC58;
extern "C" int DAT_0048ACA8;
extern "C" int DAT_0048ACAC;
extern "C" int DAT_0048ACDC;
extern "C" int DAT_0048ACE0;
extern "C" int DAT_0048ACE4;
extern "C" Object DAT_00491E88;
extern "C" int DAT_00491E8C;
extern "C" int __cdecl sub_000700C0(int, int);
extern "C" void __cdecl sub_00169800(void);
extern "C" void __cdecl sub_0016F040(int, int);

class GangMember
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
    int sub_001655C0();
    char m_pad04[0xAC];
    int m_FieldB0; // +0xB0
    char m_padB4[0x37C];
    bool m_Field430; // +0x430
};

void GangMember::vfunc_13()
{
    int r_ebx, r_edi;

    m_FieldB0 = 3;
    sub_00169800();
    ((Object*)DAT_00489828)->sub_00114AE0((int)this);
    r_ebx = sub_001655C0();
    if (!(DAT_0048ACE4 & 1)) {
        *(int*)&DAT_0048ACE4 = *(int*)&DAT_0048ACE4 | 1;
        DAT_0048ACE0 = sub_000700C0((int)DAT_003B5234, 0);
    }
    ((Object*)r_ebx)->sub_000F6100(DAT_0048ACE0, 1);
    if (!(2 & ((unsigned char)DAT_0048ACE4))) {
        *(int*)&DAT_0048ACE4 = *(int*)&DAT_0048ACE4 | 2;
        DAT_0048ACDC = sub_000700C0((int)DAT_003B521C, 0);
    }
    sub_0016F040((int)this, DAT_0048ACDC);
    r_edi = sub_001655C0();
    if (r_edi) {
        if (!(DAT_0048ACAC & 1)) {
            *(int*)&DAT_0048ACAC = *(int*)&DAT_0048ACAC | 1;
            DAT_0048ACA8 = sub_000700C0((int)DAT_003B4F0C, 0);
        }
        ((Object*)r_edi)->sub_000F14C0(DAT_0048ACA8, ((Object*)r_edi)->sub_000F14E0(DAT_0048ACA8) | 1024);
    }
    r_edi = sub_001655C0();
    if (r_edi) {
        if (!(DAT_0048ACAC & 1)) {
            *(int*)&DAT_0048ACAC = *(int*)&DAT_0048ACAC | 1;
            DAT_0048ACA8 = sub_000700C0((int)DAT_003B4F0C, 0);
        }
        ((Object*)r_edi)->sub_000F14C0(DAT_0048ACA8, ((Object*)r_edi)->sub_000F14E0(DAT_0048ACA8) & -513);
    }
    r_edi = sub_001655C0();
    if (r_edi) {
        if (!(DAT_0048ACAC & 1)) {
            *(int*)&DAT_0048ACAC = *(int*)&DAT_0048ACAC | 1;
            DAT_0048ACA8 = sub_000700C0((int)DAT_003B4F0C, 0);
        }
        ((Object*)r_edi)->sub_000F14C0(DAT_0048ACA8, ((Object*)r_edi)->sub_000F14E0(DAT_0048ACA8) & -257);
    }
    r_edi = sub_001655C0();
    if (r_edi) {
        if (!(DAT_0048ACAC & 1)) {
            *(int*)&DAT_0048ACAC = *(int*)&DAT_0048ACAC | 1;
            DAT_0048ACA8 = sub_000700C0((int)DAT_003B4F0C, 0);
        }
        ((Object*)r_edi)->sub_000F14C0(DAT_0048ACA8, ((Object*)r_edi)->sub_000F14E0(DAT_0048ACA8) & -129);
    }
    r_edi = sub_001655C0();
    if (r_edi) {
        if (!(DAT_0048ACAC & 1)) {
            *(int*)&DAT_0048ACAC = *(int*)&DAT_0048ACAC | 1;
            DAT_0048ACA8 = sub_000700C0((int)DAT_003B4F0C, 0);
        }
        ((Object*)r_edi)->sub_000F14C0(DAT_0048ACA8, ((Object*)r_edi)->sub_000F14E0(DAT_0048ACA8) & -65);
    }
    ((Object*)DAT_00489828)->sub_00114410((int)this);
    ((Object*)DAT_0048AC54.sub_00098BB0(DAT_0048AC58))->vfunc_29((int)this);
    ((Object*)r_ebx)->sub_000F0FB0(1);
    ((Object*)DAT_00491E88.sub_00098BB0(DAT_00491E8C))->vfunc_29((int)this);
    m_Field430 = false;
}

