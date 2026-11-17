// ============================================================================
// SCARFACE: THE WORLD IS YOURS — April 2006 prototype game.xbe, audio/GlobalVehicleSound.cpp (7 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 7 of 11 functions matched (63.64%). NOT COMPLETE YET.
// The 4 still to do are listed in their place in Original_Binary_Order_Proto.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] GlobalVehicleSound::vfunc_14 (0x0005B4F0, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as GlobalVehicleSound::vfunc_12 (0x00065430), which was matched first;
// its addresses and names were swapped for this function's.
// GlobalVehicleSound::vfunc_14 (0x0005B4F0, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_0044AEA4;

class GlobalVehicleSound
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
    virtual int vfunc_14();
};

int GlobalVehicleSound::vfunc_14()
{
    return DAT_0044AEA4;
}

// ============================================================================
// [VERIFIED] GlobalVehicleSound::vfunc_00 (0x002929B0, 5 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// GlobalVehicleSound::vfunc_00 (Proto 0x002929B0, 5 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

class GlobalVehicleSound
{
public:
    virtual void vfunc_00();
    char m_pad04[0x2C];
    unsigned short m_Field30; // +0x30
};

void GlobalVehicleSound::vfunc_00()
{
    m_Field30 += 1;
}

// ============================================================================
// [VERIFIED] GlobalVehicleSound::vfunc_02 (0x002929E0, 5 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// GlobalVehicleSound::vfunc_02 (Proto 0x002929E0, 5 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

class GlobalVehicleSound
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual int vfunc_02();
    char m_pad04[0x2C];
    short m_Field30; // +0x30
};

int GlobalVehicleSound::vfunc_02()
{
    return m_Field30;
}

// ============================================================================
// [VERIFIED] GlobalVehicleSound::vfunc_05 (0x002929F0, 32 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// GlobalVehicleSound::vfunc_05 (Proto 0x002929F0, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    virtual void vfunc_00();
    virtual void vfunc_01(int, int);
    virtual int vfunc_02();
};

class GlobalVehicleSound
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual void vfunc_05(int a1);
    virtual void vfunc_06();
    virtual void vfunc_07();
    virtual void vfunc_08();
    virtual void vfunc_09();
    virtual void vfunc_10();
    virtual void vfunc_11();
    virtual void vfunc_12();
    virtual void vfunc_13();
    virtual int vfunc_14();
};

void GlobalVehicleSound::vfunc_05(int a1)
{
    ((Object*)((Object*)vfunc_14())->vfunc_02())->vfunc_01(a1, (int)this);
}

// ============================================================================
// [VERIFIED] GlobalVehicleSound::vfunc_06 (0x00292A10, 32 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// GlobalVehicleSound::vfunc_06 (Proto 0x00292A10, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual int vfunc_02();
};

struct Object2
{
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02(int, int);
};

class GlobalVehicleSound
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual void vfunc_05();
    virtual void vfunc_06(int a1);
    virtual void vfunc_07();
    virtual void vfunc_08();
    virtual void vfunc_09();
    virtual void vfunc_10();
    virtual void vfunc_11();
    virtual void vfunc_12();
    virtual void vfunc_13();
    virtual int vfunc_14();
};

void GlobalVehicleSound::vfunc_06(int a1)
{
    ((Object2*)((Object*)vfunc_14())->vfunc_02())->vfunc_02(a1, (int)this);
}

// ============================================================================
// [VERIFIED] GlobalVehicleSound::vfunc_07 (0x00292A30, 32 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// GlobalVehicleSound::vfunc_07 (Proto 0x00292A30, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual int vfunc_02();
    virtual void vfunc_03(int, int);
};

class GlobalVehicleSound
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual void vfunc_05();
    virtual void vfunc_06();
    virtual void vfunc_07(int a1);
    virtual void vfunc_08();
    virtual void vfunc_09();
    virtual void vfunc_10();
    virtual void vfunc_11();
    virtual void vfunc_12();
    virtual void vfunc_13();
    virtual int vfunc_14();
};

void GlobalVehicleSound::vfunc_07(int a1)
{
    ((Object*)((Object*)vfunc_14())->vfunc_02())->vfunc_03(a1, (int)this);
}

// ============================================================================
// [VERIFIED] GlobalVehicleSound::vfunc_09 (0x00292A50, 32 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// GlobalVehicleSound::vfunc_09 (Proto 0x00292A50, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual int vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04(int, int);
};

class GlobalVehicleSound
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
    virtual void vfunc_09(int a1);
    virtual void vfunc_10();
    virtual void vfunc_11();
    virtual void vfunc_12();
    virtual void vfunc_13();
    virtual int vfunc_14();
};

void GlobalVehicleSound::vfunc_09(int a1)
{
    ((Object*)((Object*)vfunc_14())->vfunc_02())->vfunc_04(a1, (int)this);
}

