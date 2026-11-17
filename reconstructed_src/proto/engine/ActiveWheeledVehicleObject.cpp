// ============================================================================
// SCARFACE: THE WORLD IS YOURS — April 2006 prototype game.xbe, engine/ActiveWheeledVehicleObject.cpp (6 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 6 of 18 functions matched (33.33%). NOT COMPLETE YET.
// The 12 still to do are listed in their place in Original_Binary_Order_Proto.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] ActiveWheeledVehicleObject::vfunc_02 (0x001D8670, 60 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// ActiveWheeledVehicleObject::vfunc_02 (Proto 0x001D8670, 60 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field0C
{
    void sub_00091560(int);
};

struct Field65C
{
    void sub_000B4900(int);
};

extern "C" void __cdecl sub_001DBBB0(int);
extern "C" void __stdcall sub_001DDCD0(int);

class ActiveWheeledVehicleObject
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02(int a1);
    int sub_0015B240();
    char m_pad04[0x8];
    Field0C* m_Field0C; // +0x0C
    char m_pad10[0x64C];
    Field65C m_Field65C; // +0x65C
};

void ActiveWheeledVehicleObject::vfunc_02(int a1)
{
    sub_001DDCD0(a1);
    m_Field65C.sub_000B4900(a1);
    if (m_Field0C) {
        m_Field0C->sub_00091560(a1);
    }
    sub_001DBBB0(sub_0015B240());
}

// ============================================================================
// [VERIFIED] ActiveWheeledVehicleObject::vfunc_11 (0x001D86B0, 11 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// ActiveWheeledVehicleObject::vfunc_11 (Proto 0x001D86B0, 11 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_000B4CF0();
};

class ActiveWheeledVehicleObject
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
};

void ActiveWheeledVehicleObject::vfunc_11()
{
    ((Object*)(int)this + 1628)->sub_000B4CF0();
}

// ============================================================================
// [VERIFIED] ActiveWheeledVehicleObject::vfunc_20 (0x001D86F0, 31 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// ActiveWheeledVehicleObject::vfunc_20 (Proto 0x001D86F0, 31 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field65C
{
    void sub_000B4A80(int);
};

extern "C" void __stdcall sub_001DB750(int);

class ActiveWheeledVehicleObject
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
    virtual void vfunc_20(int a1);
    char m_pad04[0x658];
    Field65C m_Field65C; // +0x65C
};

void ActiveWheeledVehicleObject::vfunc_20(int a1)
{
    sub_001DB750(a1);
    m_Field65C.sub_000B4A80(a1);
}

// ============================================================================
// [VERIFIED] ActiveWheeledVehicleObject::vfunc_10 (0x001D88C0, 11 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// ActiveWheeledVehicleObject::vfunc_10 (Proto 0x001D88C0, 11 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_000B5200();
};

class ActiveWheeledVehicleObject
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
};

void ActiveWheeledVehicleObject::vfunc_10()
{
    ((Object*)(int)this + 1636)->sub_000B5200();
}

// ============================================================================
// [VERIFIED] ActiveWheeledVehicleObject::vfunc_00 (0x001D8BF0, 30 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as Collidable::vfunc_03 (0x00011F20), which was matched first;
// its addresses and names were swapped for this function's.
// ActiveWheeledVehicleObject::vfunc_00 (0x001D8BF0, 30 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __cdecl sub_001D88D0(void);
extern "C" void __cdecl sub_00025160(int);

class ActiveWheeledVehicleObject
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual ActiveWheeledVehicleObject* vfunc_00(int a1);
};

ActiveWheeledVehicleObject* ActiveWheeledVehicleObject::vfunc_00(int a1)
{
    sub_001D88D0();
    if (a1 & 1) {
        sub_00025160((int)this);
    }
    return this;
}

// ============================================================================
// [VERIFIED] ActiveWheeledVehicleObject::vfunc_16 (0x001DF740, 24 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// ActiveWheeledVehicleObject::vfunc_16 (Proto 0x001DF740, 24 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int __cdecl sub_000706B0(int, int);

class ActiveWheeledVehicleObject
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
    virtual int vfunc_16(int a1);
    char m_pad04[0x10];
    int m_Field14; // +0x14
};

int ActiveWheeledVehicleObject::vfunc_16(int a1)
{
    int r_eax;

    r_eax = m_Field14;
    if (r_eax) {
        r_eax = sub_000706B0(r_eax, a1);
    }
    return r_eax;
}

