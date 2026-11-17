// ============================================================================
// SCARFACE: THE WORLD IS YOURS — April 2006 prototype game.xbe, engine/MortarObject.cpp (4 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 4 of 8 functions matched (50.00%). NOT COMPLETE YET.
// The 4 still to do are listed in their place in Original_Binary_Order_Proto.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] MortarObject::vfunc_00 (0x001B2A50, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as CollisionBehaviourTypeGroup::vfunc_00 (0x000123B0), which was matched first;
// its addresses and names were swapped for this function's.
// MortarObject::vfunc_00 (0x001B2A50, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_00417C70[];

class MortarObject
{
public:
    virtual void* vfunc_00();
};

void* MortarObject::vfunc_00()
{
    return DAT_00417C70;
}

// ============================================================================
// [VERIFIED] MortarObject::vfunc_48 (0x001B2AD0, 5 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as SoundEntityLoader::vfunc_04 (0x00064FA0), which was matched first;
// its addresses and names were swapped for this function's.
// MortarObject::vfunc_48 (0x001B2AD0, 5 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __cdecl sub_001B5210(void);

class MortarObject
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_48();
};

void MortarObject::vfunc_48()
{
    sub_001B5210();
}

// ============================================================================
// [VERIFIED] MortarObject::vfunc_01 (0x001B2AE0, 46 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// MortarObject::vfunc_01 (Proto 0x001B2AE0, 46 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_003A3204[];
extern "C" char DAT_003A3224[];
extern "C" void __cdecl sub_00025160(int);
extern "C" void __cdecl sub_001B6560(void);

class MortarObject
{
public:
    virtual void vfunc_00();
    virtual MortarObject* vfunc_01(int a1);
    char m_pad04[0x9C];
    int m_FieldA0; // +0xA0
};

MortarObject* MortarObject::vfunc_01(int a1)
{
    *(int*)this = (int)DAT_003A3224;
    m_FieldA0 = (int)DAT_003A3204;
    sub_001B6560();
    if (a1 & 1) {
        sub_00025160((int)this);
    }
    return this;
}

// ============================================================================
// [VERIFIED] MortarObject::vfunc_30 (0x001B5B00, 36 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// MortarObject::vfunc_30 (Proto 0x001B5B00, 36 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct FieldC0
{
    void sub_0007EB10(int);
};

extern "C" void __stdcall sub_00026F40(int);

class MortarObject
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
    char m_pad04[0xBC];
    FieldC0* m_FieldC0; // +0xC0
};

void MortarObject::vfunc_30(int a1)
{
    sub_00026F40(a1);
    if (m_FieldC0) {
        m_FieldC0->sub_0007EB10((int)this + 48);
    }
}

