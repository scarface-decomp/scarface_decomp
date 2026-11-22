// ============================================================================
// SCARFACE: THE WORLD IS YOURS — April 2006 prototype game.xbe, engine/NISCamera.cpp (4 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 4 of 5 functions matched (80.00%). NOT COMPLETE YET.
// The 1 still to do are listed in their place in Original_Binary_Order_Proto.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] NISCamera::vfunc_41 (0x0013F230, 33 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// What it does: Returns a copy of a three-number vector kept in an object.
// ============================================================================
// bin: proto
// va: 0x0013F230
// what: Returns a copy of a three-number vector kept in an object.
// tool: Claude Opus 5.5 (transplanted from xb:0x000E7920, nearest by portal/tools/similar.py)
// sub_0013F230 (0x0013F230, 30 bytes)

struct Struct_0013F230
{
    float m_Field00; // +0x00
    float m_Field04; // +0x04
    float m_Field08; // +0x08
};

class Class_0013F230
{
public:
    Struct_0013F230 sub_0013F230() const;

    char m_pad00[0xC0];
    Struct_0013F230 m_FieldC0; // +0xC0
};

// Returns the stored vector by value.
Struct_0013F230 Class_0013F230::sub_0013F230() const
{
    return m_FieldC0;
}

// ============================================================================
// [VERIFIED] NISCamera::vfunc_00 (0x0013F530, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as CollisionBehaviourTypeGroup::vfunc_00 (0x000123B0), which was matched first;
// its addresses and names were swapped for this function's.
// NISCamera::vfunc_00 (0x0013F530, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0040A5DC[];

class NISCamera
{
public:
    virtual void* vfunc_00();
};

void* NISCamera::vfunc_00()
{
    return DAT_0040A5DC;
}

// ============================================================================
// [VERIFIED] NISCamera::vfunc_39 (0x0013F540, 7 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// NISCamera::vfunc_39 (Proto 0x0013F540, 7 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

class NISCamera
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
    char m_pad04[0xB7];
    bool m_FieldBB; // +0xBB
};

bool NISCamera::vfunc_39()
{
    return m_FieldBB;
}

// ============================================================================
// [VERIFIED] NISCamera::vfunc_01 (0x0013FDD0, 30 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as Collidable::vfunc_03 (0x00011F20), which was matched first;
// its addresses and names were swapped for this function's.
// NISCamera::vfunc_01 (0x0013FDD0, 30 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __cdecl sub_0013F4D0(void);
extern "C" void __cdecl sub_00025160(int);

class NISCamera
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual NISCamera* vfunc_01(int a1);
};

NISCamera* NISCamera::vfunc_01(int a1)
{
    sub_0013F4D0();
    if (a1 & 1) {
        sub_00025160((int)this);
    }
    return this;
}

