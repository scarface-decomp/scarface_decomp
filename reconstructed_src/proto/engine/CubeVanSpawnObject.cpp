// ============================================================================
// SCARFACE: THE WORLD IS YOURS — April 2006 prototype game.xbe, engine/CubeVanSpawnObject.cpp (5 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 5 of 8 functions matched (62.50%). NOT COMPLETE YET.
// The 3 still to do are listed in their place in Original_Binary_Order_Proto.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] CubeVanSpawnObject::vfunc_00 (0x001A55B0, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as CollisionBehaviourTypeGroup::vfunc_00 (0x000123B0), which was matched first;
// its addresses and names were swapped for this function's.
// CubeVanSpawnObject::vfunc_00 (0x001A55B0, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_004172BC[];

class CubeVanSpawnObject
{
public:
    virtual void* vfunc_00();
};

void* CubeVanSpawnObject::vfunc_00()
{
    return DAT_004172BC;
}

// ============================================================================
// [VERIFIED] CubeVanSpawnObject::vfunc_05 (0x001A55C0, 45 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// CubeVanSpawnObject::vfunc_05 (Proto 0x001A55C0, 45 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    int sub_001AF720(int, int);
};

extern "C" int DAT_00460C24;

class CubeVanSpawnObject
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual void vfunc_05(int a1);
    void sub_001B0CD0(int);
    char m_pad04[0x7C];
    int m_Field80; // +0x80
    char m_pad84[0x60];
    int m_FieldE4; // +0xE4
};

void CubeVanSpawnObject::vfunc_05(int a1)
{
    m_Field80 = ((Object*)DAT_00460C24)->sub_001AF720(m_FieldE4, 2);
    sub_001B0CD0(a1);
}

// ============================================================================
// [VERIFIED] CubeVanSpawnObject::vfunc_38 (0x001A5630, 20 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// CubeVanSpawnObject::vfunc_38 (Proto 0x001A5630, 20 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

class CubeVanSpawnObject
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
    virtual void vfunc_38(int a1, int a2);
    char m_pad04[0xB8];
    int m_FieldBC; // +0xBC
};

void CubeVanSpawnObject::vfunc_38(int a1, int a2)
{
    if (a2 == 1) {
        m_FieldBC = 0;
    }
}

// ============================================================================
// [VERIFIED] CubeVanSpawnObject::vfunc_35 (0x001A57E0, 80 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// bin: proto
// va: 0x001A57E0
// what: 
// tool: the portal's starter code (no AI)

// CubeVanSpawnObject::vfunc_35 (Proto 0x001A57E0, 80 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field80
{
    void sub_001A6530(int);
};

struct Object
{
    void sub_001A6530(int);
};

class CubeVanSpawnObject
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
    char m_pad04[0x7C];
    Field80* m_Field80; // +0x80
    int m_Field84; // +0x84
    char m_pad88[0x2C];
    int m_FieldB4; // +0xB4
    char m_padB8[0x8];
    bool m_FieldC0; // +0xC0
};

void CubeVanSpawnObject::vfunc_35()
{
    int r_ebx, r_edi, t2;

    if (m_FieldC0) {
        r_edi = 0;
        if (m_FieldB4 > 0) {
            r_ebx = (int)(&m_Field84);
            do {
                ((Object*)*(int*)r_ebx)->sub_001A6530(64);
                t2 = m_FieldB4;
                r_edi += 1;
                r_ebx += 4;
            } while (r_edi < t2);
        }
        m_Field80->sub_001A6530(64);
        m_FieldC0 = false;
    }
}

// ============================================================================
// [VERIFIED] CubeVanSpawnObject::vfunc_01 (0x001A5F30, 30 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as Collidable::vfunc_03 (0x00011F20), which was matched first;
// its addresses and names were swapped for this function's.
// CubeVanSpawnObject::vfunc_01 (0x001A5F30, 30 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __cdecl sub_001A5780(void);
extern "C" void __cdecl sub_00025160(int);

class CubeVanSpawnObject
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual CubeVanSpawnObject* vfunc_01(int a1);
};

CubeVanSpawnObject* CubeVanSpawnObject::vfunc_01(int a1)
{
    sub_001A5780();
    if (a1 & 1) {
        sub_00025160((int)this);
    }
    return this;
}

