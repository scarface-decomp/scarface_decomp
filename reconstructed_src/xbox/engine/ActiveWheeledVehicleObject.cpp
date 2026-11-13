// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail Xbox default.xbe, engine/ActiveWheeledVehicleObject.cpp (5 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 5 of 17 functions matched (29.41%). NOT COMPLETE YET.
// The 12 still to do are listed in their place in Original_Binary_Order_Xbox.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] ActiveWheeledVehicleObject::vfunc_02 (0x002139B0, 60 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// ActiveWheeledVehicleObject::vfunc_02 (0x002139B0, 60 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field10
{
    void sub_0009D750(int);
};

struct Field67C
{
    void sub_00022710(int);
};

extern "C" void __cdecl sub_00217750(int);
extern "C" void __stdcall sub_00219970(int);

class ActiveWheeledVehicleObject
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02(int a1);
    int sub_000ABC70();
    char m_pad04[0xC];
    Field10* m_Field10; // +0x10
    char m_pad14[0x668];
    Field67C m_Field67C; // +0x67C
};

void ActiveWheeledVehicleObject::vfunc_02(int a1)
{
    sub_00219970(a1);
    m_Field67C.sub_00022710(a1);
    if (m_Field10) {
        m_Field10->sub_0009D750(a1);
    }
    sub_00217750(sub_000ABC70());
}

// ============================================================================
// [VERIFIED] ActiveWheeledVehicleObject::vfunc_19 (0x00213A20, 31 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// ActiveWheeledVehicleObject::vfunc_19 (0x00213A20, 31 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field67C
{
    void sub_000C2440(int);
};

extern "C" void __stdcall sub_00217260(int);

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
    virtual void vfunc_19(int a1);
    char m_pad04[0x678];
    Field67C m_Field67C; // +0x67C
};

void ActiveWheeledVehicleObject::vfunc_19(int a1)
{
    sub_00217260(a1);
    m_Field67C.sub_000C2440(a1);
}

// ============================================================================
// [VERIFIED] ActiveWheeledVehicleObject::vfunc_10 (0x00213BF0, 11 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// ActiveWheeledVehicleObject::vfunc_10 (0x00213BF0, 11 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_000C2AE0();
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
    ((Object*)(int)this + 1668)->sub_000C2AE0();
}

// ============================================================================
// [VERIFIED] ActiveWheeledVehicleObject::vfunc_00 (0x00213F50, 30 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as Collidable::vfunc_03 (0x00011F20), which was matched first;
// its addresses and names were swapped for this function's.
// ActiveWheeledVehicleObject::vfunc_00 (0x00213F50, 30 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __cdecl sub_00213C00(void);
extern "C" void __cdecl sub_00027600(int);

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
    sub_00213C00();
    if (a1 & 1) {
        sub_00027600((int)this);
    }
    return this;
}

// ============================================================================
// [VERIFIED] ActiveWheeledVehicleObject::vfunc_15 (0x0021B8B0, 24 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// ActiveWheeledVehicleObject::vfunc_15 (0x0021B8B0, 24 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int __cdecl sub_0007C640(int, int);

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
    virtual int vfunc_15(int a1);
    char m_pad04[0x14];
    int m_Field18; // +0x18
};

int ActiveWheeledVehicleObject::vfunc_15(int a1)
{
    int r_eax;

    r_eax = m_Field18;
    if (r_eax) {
        r_eax = sub_0007C640(r_eax, a1);
    }
    return r_eax;
}

