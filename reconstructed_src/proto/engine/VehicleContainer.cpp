// ============================================================================
// SCARFACE: THE WORLD IS YOURS — April 2006 prototype game.xbe, engine/VehicleContainer.cpp (5 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 5 of 8 functions matched (62.50%). NOT COMPLETE YET.
// The 3 still to do are listed in their place in Original_Binary_Order_Proto.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] renderer::VehicleContainer::vfunc_23 (0x000531B0, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// What it does: Always returns 0x2000000.
// ============================================================================
// bin: proto
// va: 0x000531B0
// what: Always returns 0x2000000.
// tool: Claude Fable 5.2 (look-alike of xb 0x0005D7C0, names and addresses swapped)
// renderer::VehicleContainer::vfunc_23 (0x000531B0, 6 bytes)
namespace renderer {

class VehicleContainer
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
    virtual int vfunc_23();
};

int VehicleContainer::vfunc_23()
{
    return 0x2000000;
}

}

// ============================================================================
// [VERIFIED] renderer::VehicleContainer::vfunc_17 (0x000535A0, 13 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as renderer::VehicleContainer::vfunc_17 (0x0005DB80), which was matched first;
// its addresses and names were swapped for this function's.
// renderer::VehicleContainer::vfunc_17 (0x000535A0, 13 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

namespace renderer {

class VehicleContainer
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
    virtual bool vfunc_17(bool a1);
    char m_pad04[0xC8];
    bool m_FieldCC; // +0xCC
};

bool VehicleContainer::vfunc_17(bool a1)
{
    m_FieldCC = a1;
    return a1;
}

}

// ============================================================================
// [VERIFIED] renderer::VehicleContainer::vfunc_18 (0x000535B0, 17 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 /arch:SSE
// ============================================================================
// Same machine code as renderer::VehicleContainer::vfunc_18 (0x0005DB90), which was matched first;
// its addresses and names were swapped for this function's.
// bin: xb
// va: 0x000535B0
// what: Stores a number at +0xD0.
// tool: Claude Opus 5.5 (generated from the shape 'set float field', checked on decomp.me preset 266 by example)
class Class_000535B0
{
public:
    void sub_000535B0(float value);
    char m_pad00[0xD0];
    float m_FieldD0; // +0xD0
};

void Class_000535B0::sub_000535B0(float value)
{
    m_FieldD0 = value;
}

// ============================================================================
// [VERIFIED] renderer::VehicleContainer::vfunc_19 (0x000535D0, 7 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as renderer::VehicleContainer::vfunc_19 (0x0005DBB0), which was matched first;
// its addresses and names were swapped for this function's.
// renderer::VehicleContainer::vfunc_19 (0x000535D0, 7 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

namespace renderer {

class VehicleContainer
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
    virtual bool vfunc_19();
    char m_pad04[0xC8];
    bool m_FieldCC; // +0xCC
};

bool VehicleContainer::vfunc_19()
{
    return m_FieldCC;
}

}

// ============================================================================
// [VERIFIED] renderer::VehicleContainer::vfunc_20 (0x000535E0, 7 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as renderer::VehicleContainer::vfunc_20 (0x0005DBC0), which was matched first;
// its addresses and names were swapped for this function's.
// renderer::VehicleContainer::vfunc_20 (0x000535E0, 7 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

namespace renderer {

class VehicleContainer
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
    virtual float vfunc_20();
    char m_pad04[0xCC];
    float m_FieldD0; // +0xD0
};

float VehicleContainer::vfunc_20()
{
    return m_FieldD0;
}

}

