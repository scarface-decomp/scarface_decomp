// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail Xbox default.xbe, engine/VehiclePropellerBehaviour.cpp (2 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 2 of 3 functions matched (66.67%). NOT COMPLETE YET.
// The 1 still to do are listed in their place in Original_Binary_Order_Xbox.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] VehiclePropellerBehaviour::vfunc_00 (0x000B6900, 57 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// What it does: VehiclePropellerBehaviour's deleting destructor: destroys the object, frees its memory when asked (flag bit 0), and returns it.
// ============================================================================
// VehiclePropellerBehaviour::vfunc_00 (0x000B6900, 57 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field08
{
    void sub_000883A0();
};

extern "C" char DAT_003A5040[];
extern "C" void __cdecl sub_00027600(int);

class VehiclePropellerBehaviour
{
public:
    virtual VehiclePropellerBehaviour* vfunc_00(int a1);
    void sub_000AACC0();
    char m_pad04[0x4];
    Field08 m_Field08; // +0x08
};

VehiclePropellerBehaviour* VehiclePropellerBehaviour::vfunc_00(int a1)
{
    *(int*)this = (int)DAT_003A5040;
    m_Field08.sub_000883A0();
    m_Field08.sub_000883A0();
    sub_000AACC0();
    if (a1 & 1) {
        sub_00027600((int)this);
    }
    return this;
}

// ============================================================================
// [VERIFIED] VehiclePropellerBehaviour::vfunc_02 (0x000B7130, 54 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 /arch:SSE
// ============================================================================
// Same machine code as VehiclePropellerBehaviour::vfunc_02 (Proto 0x000A9800), which was matched first;
// its addresses and names were swapped for this function's.
// bin: proto
// va: 0x000B7130
// what: 
// tool: the portal's starter code (no AI)

// VehiclePropellerBehaviour::vfunc_02 (Proto 0x000B7130, 54 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field08
{
    void sub_000880C0(int);
    void sub_00088420(int);
    void sub_00088C60(int);
};

class VehiclePropellerBehaviour
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    void sub_000B6940();
    char m_pad04[0x4];
    Field08 m_Field08; // +0x08
    char m_pad09[0x1F];
    float m_Field28; // +0x28
};

void VehiclePropellerBehaviour::vfunc_02()
{
    m_Field08.sub_000880C0(1);
    m_Field08.sub_00088420(0);
    m_Field08.sub_00088C60(0x3F800000);
    m_Field28 = 0.0f;
    sub_000B6940();
}

