// ============================================================================
// SCARFACE: THE WORLD IS YOURS — April 2006 prototype game.xbe, engine/GenericCharacterCamera.cpp (5 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 5 of 11 functions matched (45.45%). NOT COMPLETE YET.
// The 6 still to do are listed in their place in Original_Binary_Order_Proto.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] GenericCharacterCamera::vfunc_00 (0x001391F0, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as CollisionBehaviourTypeGroup::vfunc_00 (0x000123B0), which was matched first;
// its addresses and names were swapped for this function's.
// GenericCharacterCamera::vfunc_00 (0x001391F0, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_00409ECC[];

class GenericCharacterCamera
{
public:
    virtual void* vfunc_00();
};

void* GenericCharacterCamera::vfunc_00()
{
    return DAT_00409ECC;
}

// ============================================================================
// [VERIFIED] GenericCharacterCamera::vfunc_39 (0x001392A0, 7 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// GenericCharacterCamera::vfunc_39 (Proto 0x001392A0, 7 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

class GenericCharacterCamera
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
    virtual bool vfunc_39();
    char m_pad04[0x2A0];
    bool m_Field2A4; // +0x2A4
};

bool GenericCharacterCamera::vfunc_39()
{
    return m_Field2A4;
}

// ============================================================================
// [VERIFIED] GenericCharacterCamera::vfunc_41 (0x001392B0, 33 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// What it does: Returns a copy of a three-number vector kept in an object.
// ============================================================================
// bin: proto
// va: 0x001392B0
// what: Returns a copy of a three-number vector kept in an object.
// tool: Claude Opus 5.5 (transplanted from xb:0x000E7920, nearest by portal/tools/similar.py)
// sub_001392B0 (0x001392B0, 30 bytes)

struct Struct_001392B0
{
    float m_Field00; // +0x00
    float m_Field04; // +0x04
    float m_Field08; // +0x08
};

class Class_001392B0
{
public:
    Struct_001392B0 sub_001392B0() const;

    char m_pad00[0x27C];
    Struct_001392B0 m_Field27C; // +0x27C
};

// Returns the stored vector by value.
Struct_001392B0 Class_001392B0::sub_001392B0() const
{
    return m_Field27C;
}

// ============================================================================
// [VERIFIED] GenericCharacterCamera::vfunc_01 (0x00139320, 36 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as CollisionBehaviourTypeGroup::vfunc_01 (0x00013840), which was matched first;
// its addresses and names were swapped for this function's.
// GenericCharacterCamera::vfunc_01 (0x00139320, 36 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_00391414[];
extern "C" void __cdecl sub_00025160(int);
extern "C" void __cdecl sub_00135B10(void);

class GenericCharacterCamera
{
public:
    virtual void vfunc_00();
    virtual GenericCharacterCamera* vfunc_01(int a1);
};

GenericCharacterCamera* GenericCharacterCamera::vfunc_01(int a1)
{
    *(int*)this = (int)DAT_00391414;
    sub_00135B10();
    if (a1 & 1) {
        sub_00025160((int)this);
    }
    return this;
}

// ============================================================================
// [VERIFIED] GenericCharacterCamera::vfunc_36 (0x0013A460, 22 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as GenericCharacterCamera::vfunc_38 (0x00155690), which was matched first;
// its addresses and names were swapped for this function's.
// bin: xb
// va: 0x0013A460
// what: Says whether sub_00028120 gives a nonzero result for the value at +0x28C.
// tool: Claude Opus 5.5 (generated from the shape 'call with a field, nonzero', checked on decomp.me preset 266 by example)
extern "C" int __cdecl sub_00028120(int value);

class Class_0013A460
{
public:
    int sub_0013A460();
    char m_pad00[0x28C];
    int m_Field28C; // +0x28C
};

int Class_0013A460::sub_0013A460()
{
    return sub_00028120(m_Field28C) != 0;
}

