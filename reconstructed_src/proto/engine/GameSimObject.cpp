// ============================================================================
// SCARFACE: THE WORLD IS YOURS — April 2006 prototype game.xbe, engine/GameSimObject.cpp (5 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 5 of 12 functions matched (41.67%). NOT COMPLETE YET.
// The 7 still to do are listed in their place in Original_Binary_Order_Proto.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] GameSimObject::vfunc_42 (0x00027A30, 12 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// What it does: Reads flag bit 2 of the byte at +0x9C.
// ============================================================================
// bin: proto
// va: 0x00027A30
// what: Reads flag bit 2 of the byte at +0x9C.
// tool: Claude Opus 5.5 (transplanted from xb:0x00012A20, nearest by portal/tools/similar.py)
class Class_00027A30
{
public:
    bool sub_00027A30();
    char m_pad00[0x9C];
    unsigned char m_Flag0 : 1;
    unsigned char m_Flag1 : 1;
    unsigned char m_Flag2 : 1;
};

bool Class_00027A30::sub_00027A30()
{
    return m_Flag2;
}

// ============================================================================
// [VERIFIED] GameSimObject::vfunc_00 (0x00027AC0, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as CollisionBehaviourTypeGroup::vfunc_00 (0x000123B0), which was matched first;
// its addresses and names were swapped for this function's.
// GameSimObject::vfunc_00 (0x00027AC0, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_003F6A40[];

class GameSimObject
{
public:
    virtual void* vfunc_00();
};

void* GameSimObject::vfunc_00()
{
    return DAT_003F6A40;
}

// ============================================================================
// [VERIFIED] GameSimObject::vfunc_40 (0x00027AD0, 11 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// What it does: Reads flag bit 1 of the byte at +0x9C.
// ============================================================================
// bin: proto
// va: 0x00027AD0
// what: Reads flag bit 1 of the byte at +0x9C.
// tool: Claude Opus 5.5 (transplanted from xb:0x0002A330, nearest by portal/tools/similar.py)
class Class_00027AD0
{
public:
    bool sub_00027AD0();
    char m_pad00[0x9C];
    unsigned char m_Flag0 : 1;
    unsigned char m_Flag1 : 1;
};

bool Class_00027AD0::sub_00027AD0()
{
    return m_Flag1;
}

// ============================================================================
// [VERIFIED] GameSimObject::vfunc_01 (0x00027CE0, 30 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as Collidable::vfunc_03 (0x00011F20), which was matched first;
// its addresses and names were swapped for this function's.
// GameSimObject::vfunc_01 (0x00027CE0, 30 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __cdecl sub_00027AE0(void);
extern "C" void __cdecl sub_00025160(int);

class GameSimObject
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual GameSimObject* vfunc_01(int a1);
};

GameSimObject* GameSimObject::vfunc_01(int a1)
{
    sub_00027AE0();
    if (a1 & 1) {
        sub_00025160((int)this);
    }
    return this;
}

// ============================================================================
// [VERIFIED] GameSimObject::vfunc_43 (0x000431F0, 5 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as GameSimObject::vfunc_55 (0x0004A770), which was matched first;
// its addresses and names were swapped for this function's.
// GameSimObject::vfunc_43 (0x000431F0, 5 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

class GameSimObject
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
    virtual void vfunc_45();
    virtual void vfunc_46();
    virtual void vfunc_47();
    virtual void vfunc_48();
    virtual void vfunc_49();
    virtual void vfunc_50();
    virtual void vfunc_51();
    virtual void vfunc_52();
    virtual void vfunc_53();
    virtual void vfunc_54();
    virtual bool vfunc_43(int a1, int a2);
};

bool GameSimObject::vfunc_43(int a1, int a2)
{
    return 0;
}

