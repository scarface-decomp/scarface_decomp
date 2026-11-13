// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail Xbox default.xbe, engine/WakeObject.cpp (3 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 3 of 7 functions matched (42.86%). NOT COMPLETE YET.
// The 4 still to do are listed in their place in Original_Binary_Order_Xbox.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] WakeObject::vfunc_00 (0x0021D780, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as CollisionBehaviourTypeGroup::vfunc_00 (0x000123B0), which was matched first;
// its addresses and names were swapped for this function's.
// WakeObject::vfunc_00 (0x0021D780, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0044D584[];

class WakeObject
{
public:
    virtual void* vfunc_00();
};

void* WakeObject::vfunc_00()
{
    return DAT_0044D584;
}

// ============================================================================
// [VERIFIED] WakeObject::vfunc_01 (0x0021D790, 36 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as CollisionBehaviourTypeGroup::vfunc_01 (0x00013840), which was matched first;
// its addresses and names were swapped for this function's.
// WakeObject::vfunc_01 (0x0021D790, 36 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_003D0A4C[];
extern "C" void __cdecl sub_00027600(int);
extern "C" void __cdecl sub_0002A770(void);

class WakeObject
{
public:
    virtual void vfunc_00();
    virtual WakeObject* vfunc_01(int a1);
};

WakeObject* WakeObject::vfunc_01(int a1)
{
    *(int*)this = (int)DAT_003D0A4C;
    sub_0002A770();
    if (a1 & 1) {
        sub_00027600((int)this);
    }
    return this;
}

// ============================================================================
// [VERIFIED] WakeObject::vfunc_29 (0x0021D7C0, 40 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// WakeObject::vfunc_29 (0x0021D7C0, 40 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __stdcall sub_0002A880(int);
extern "C" int __cdecl sub_000486B0(int, int);

class WakeObject
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
    virtual int vfunc_29(int a1);
    char m_pad04[0xA4];
    int m_FieldA8; // +0xA8
};

int WakeObject::vfunc_29(int a1)
{
    int r_eax;

    r_eax = a1;
    sub_0002A880(a1);
    r_eax = m_FieldA8;
    if (r_eax) {
        r_eax = sub_000486B0(r_eax, (int)this + 52);
    }
    return r_eax;
}

