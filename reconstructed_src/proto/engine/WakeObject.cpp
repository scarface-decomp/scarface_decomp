// ============================================================================
// SCARFACE: THE WORLD IS YOURS — April 2006 prototype game.xbe, engine/WakeObject.cpp (3 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 3 of 4 functions matched (75.00%). NOT COMPLETE YET.
// The 1 still to do are listed in their place in Original_Binary_Order_Proto.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] WakeObject::vfunc_00 (0x001E13F0, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as CollisionBehaviourTypeGroup::vfunc_00 (0x000123B0), which was matched first;
// its addresses and names were swapped for this function's.
// WakeObject::vfunc_00 (0x001E13F0, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_00426F84[];

class WakeObject
{
public:
    virtual void* vfunc_00();
};

void* WakeObject::vfunc_00()
{
    return DAT_00426F84;
}

// ============================================================================
// [VERIFIED] WakeObject::vfunc_27 (0x001E1400, 40 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// WakeObject::vfunc_27 (Proto 0x001E1400, 40 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __stdcall sub_00027E20(int);
extern "C" int __cdecl sub_000413C0(int, int);

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
    virtual int vfunc_27(int a1);
    char m_pad04[0x9C];
    int m_FieldA0; // +0xA0
};

int WakeObject::vfunc_27(int a1)
{
    int r_eax;

    r_eax = a1;
    sub_00027E20(a1);
    r_eax = m_FieldA0;
    if (r_eax) {
        r_eax = sub_000413C0(r_eax, (int)this + 48);
    }
    return r_eax;
}

// ============================================================================
// [VERIFIED] WakeObject::vfunc_01 (0x001E1430, 36 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as CollisionBehaviourTypeGroup::vfunc_01 (0x00013840), which was matched first;
// its addresses and names were swapped for this function's.
// WakeObject::vfunc_01 (0x001E1430, 36 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_003AA2CC[];
extern "C" void __cdecl sub_00025160(int);
extern "C" void __cdecl sub_00027D00(void);

class WakeObject
{
public:
    virtual void vfunc_00();
    virtual WakeObject* vfunc_01(int a1);
};

WakeObject* WakeObject::vfunc_01(int a1)
{
    *(int*)this = (int)DAT_003AA2CC;
    sub_00027D00();
    if (a1 & 1) {
        sub_00025160((int)this);
    }
    return this;
}

