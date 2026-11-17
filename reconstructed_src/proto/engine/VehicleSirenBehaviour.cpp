// ============================================================================
// SCARFACE: THE WORLD IS YOURS — April 2006 prototype game.xbe, engine/VehicleSirenBehaviour.cpp (3 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 3 of 5 functions matched (60.00%). NOT COMPLETE YET.
// The 2 still to do are listed in their place in Original_Binary_Order_Proto.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] VehicleSirenBehaviour::vfunc_03 (0x001D2250, 11 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// VehicleSirenBehaviour::vfunc_03 (Proto 0x001D2250, 11 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_000A9260();
};

class VehicleSirenBehaviour
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03(int a1);
};

void VehicleSirenBehaviour::vfunc_03(int a1)
{
    ((Object*)(int)this + 8)->sub_000A9260();
}

// ============================================================================
// [VERIFIED] VehicleSirenBehaviour::vfunc_00 (0x001D28F0, 62 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// VehicleSirenBehaviour::vfunc_00 (Proto 0x001D28F0, 62 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0009F3E0(int);
};

extern "C" char DAT_003A7920[];
extern "C" char DAT_003A792C[];
extern "C" void __cdecl sub_00025160(int);

class VehicleSirenBehaviour
{
public:
    virtual VehicleSirenBehaviour* vfunc_00(int a1);
    void sub_0009EC50();
    int m_Field04; // +0x04
    char m_pad08[0x10];
    int m_Field18; // +0x18
};

VehicleSirenBehaviour* VehicleSirenBehaviour::vfunc_00(int a1)
{
    int t1;

    t1 = m_Field18;
    *(int*)this = (int)DAT_003A792C;
    m_Field04 = (int)DAT_003A7920;
    if (m_Field18) {
        ((Object*)t1 + 72)->sub_0009F3E0(0);
    }
    sub_0009EC50();
    if (a1 & 1) {
        sub_00025160((int)this);
    }
    return this;
}

// ============================================================================
// [VERIFIED] VehicleSirenBehaviour::vfunc_01 (0x001D29C0, 46 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// VehicleSirenBehaviour::vfunc_01 (Proto 0x001D29C0, 46 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_001B5080(int);
};

extern "C" int __cdecl sub_00028120(int);

class VehicleSirenBehaviour
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    char m_pad04[0x14];
    int m_Field18; // +0x18
    bool m_Field1C; // +0x1C
};

void VehicleSirenBehaviour::vfunc_01()
{
    m_Field1C = true;
    if (sub_00028120(m_Field18)) {
        ((Object*)sub_00028120(m_Field18))->sub_001B5080(2);
    }
}

