// ============================================================================
// SCARFACE: THE WORLD IS YOURS — April 2006 prototype game.xbe, engine/ExplosionObject.cpp (6 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: COMPLETE. All 6 functions are matched.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] ExplosionObject::vfunc_09 (0x001B1CC0, 42 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// What it does: Passes a value to the part at +0x78, then tells a global manager about this object unless a flag says not to.
// ============================================================================
// bin: proto
// va: 0x001B1CC0
// what: Passes a value to the part at +0x78, then tells a global manager about this object unless a flag says not to.
// tool: Claude Opus 5.5 (transplanted from xb:0x001EB940, nearest by portal/tools/similar.py)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field74
{
    void sub_0001F0C0(int);
};

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
    virtual int vfunc_30(int);
};

extern "C" int DAT_00462F6C;

class ExplosionObject
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
    virtual void vfunc_08(int a1);
    char m_pad04[0x74];
    Field74 m_Field78; // +0x78
    bool m_Field79; // +0x79
};

void ExplosionObject::vfunc_08(int a1)
{
    int r_eax;

    r_eax = a1;
    m_Field78.sub_0001F0C0(a1);
    r_eax = m_Field79;
    if (!((unsigned char)r_eax)) {
        r_eax = ((Object*)*(int*)(DAT_00462F6C + 12))->vfunc_30((int)this);
    }
}

// ============================================================================
// [VERIFIED] ExplosionObject::vfunc_00 (0x001B1D90, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as CollisionBehaviourTypeGroup::vfunc_00 (0x000123B0), which was matched first;
// its addresses and names were swapped for this function's.
// ExplosionObject::vfunc_00 (0x001B1D90, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_00417798[];

class ExplosionObject
{
public:
    virtual void* vfunc_00();
};

void* ExplosionObject::vfunc_00()
{
    return DAT_00417798;
}

// ============================================================================
// [VERIFIED] ExplosionObject::vfunc_27 (0x001B1E00, 36 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// ExplosionObject::vfunc_27 (Proto 0x001B1E00, 36 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0001EA10(int);
};

class ExplosionObject
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
    virtual void vfunc_27(int a1);
    char m_pad04[0x2C];
    int m_Field30; // +0x30
    char m_pad34[0x2C];
    int m_Field60; // +0x60
    int m_Field64; // +0x64
    int m_Field68; // +0x68
};

void ExplosionObject::vfunc_27(int a1)
{
    m_Field60 = *(int*)a1;
    m_Field64 = *(int*)(a1 + 4);
    m_Field68 = *(int*)(a1 + 8);
    a1 = (int)(&m_Field30);
    ((Object*)(int)this + 120)->sub_0001EA10(a1);
}

// ============================================================================
// [VERIFIED] ExplosionObject::vfunc_28 (0x001B1E30, 29 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// ExplosionObject::vfunc_28 (Proto 0x001B1E30, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field78
{
    void sub_0001EA10(int);
};

extern "C" void __stdcall sub_00026F90(int);

class ExplosionObject
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
    virtual void vfunc_28(int a1);
    char m_pad04[0x2C];
    int m_Field30; // +0x30
    char m_pad34[0x44];
    Field78 m_Field78; // +0x78
};

void ExplosionObject::vfunc_28(int a1)
{
    sub_00026F90(a1);
    m_Field78.sub_0001EA10((int)(&m_Field30));
}

// ============================================================================
// [VERIFIED] ExplosionObject::vfunc_30 (0x001B1E50, 29 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// ExplosionObject::vfunc_30 (Proto 0x001B1E50, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field78
{
    void sub_0001EA10(int);
};

extern "C" void __stdcall sub_00026F40(int);

class ExplosionObject
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
    char m_pad04[0x2C];
    int m_Field30; // +0x30
    char m_pad34[0x44];
    Field78 m_Field78; // +0x78
};

void ExplosionObject::vfunc_30(int a1)
{
    sub_00026F40(a1);
    m_Field78.sub_0001EA10((int)(&m_Field30));
}

// ============================================================================
// [VERIFIED] ExplosionObject::vfunc_01 (0x001B1F50, 30 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as Collidable::vfunc_03 (0x00011F20), which was matched first;
// its addresses and names were swapped for this function's.
// ExplosionObject::vfunc_01 (0x001B1F50, 30 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __cdecl sub_001B1DA0(void);
extern "C" void __cdecl sub_00025160(int);

class ExplosionObject
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual ExplosionObject* vfunc_01(int a1);
};

ExplosionObject* ExplosionObject::vfunc_01(int a1)
{
    sub_001B1DA0();
    if (a1 & 1) {
        sub_00025160((int)this);
    }
    return this;
}

