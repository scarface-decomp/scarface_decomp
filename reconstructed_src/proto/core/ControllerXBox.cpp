// ============================================================================
// SCARFACE: THE WORLD IS YOURS — April 2006 prototype game.xbe, core/ControllerXBox.cpp (9 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 9 of 19 functions matched (47.37%). NOT COMPLETE YET.
// The 10 still to do are listed in their place in Original_Binary_Order_Proto.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] core::ControllerXBox::vfunc_22 (0x00204F70, 38 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// bin: proto
// va: 0x00204F70
// what: 
// tool: the portal's starter code (no AI)

// core::ControllerXBox::vfunc_22 (Proto 0x00204F70, 38 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __stdcall sub_00375968(int);

namespace core {

class ControllerXBox
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
    virtual void vfunc_22(int a1);
    char m_pad04[0x4];
    int m_Field08; // +0x08
};

void ControllerXBox::vfunc_22(int a1)
{
    int t1;

    t1 = m_Field08;
    if (m_Field08) {
        sub_00375968(t1);
        m_Field08 = a1;
        return;
    }
    m_Field08 = a1;
}

}

// ============================================================================
// [VERIFIED] core::ControllerXBox::vfunc_04 (0x00204FA0, 11 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// What it does: Says whether the pointer at +0x8 is set.
// ============================================================================
// Same machine code as core::ControllerXBox::vfunc_04 (0x00247C00), which was matched first;
// its addresses and names were swapped for this function's.
// bin: xb
// va: 0x00204FA0
// what: Says whether the pointer at +0x8 is set.
// tool: Claude Opus 5.5 (generated from the shape 'field is set', checked on decomp.me preset 266 by example)
class Class_00204FA0
{
public:
    int sub_00204FA0();
    char m_pad00[0x8];
    void* m_Field8; // +0x8
};

int Class_00204FA0::sub_00204FA0()
{
    return m_Field8 != 0;
}

// ============================================================================
// [VERIFIED] core::ControllerXBox::vfunc_05 (0x00204FB0, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as core::ControllerXBox::vfunc_05 (0x00247C10), which was matched first;
// its addresses and names were swapped for this function's.
// core::ControllerXBox::vfunc_05 (0x00204FB0, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_003AE068[];

namespace core {

class ControllerXBox
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual void* vfunc_05();
};

void* ControllerXBox::vfunc_05()
{
    return DAT_003AE068;
}

}

// ============================================================================
// [VERIFIED] core::ControllerXBox::vfunc_06 (0x00204FC0, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as core::ControllerXBox::vfunc_05 (0x00247C10), which was matched first;
// its addresses and names were swapped for this function's.
// core::ControllerXBox::vfunc_06 (0x00204FC0, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_003AE078[];

namespace core {

class ControllerXBox
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual void* vfunc_06();
};

void* ControllerXBox::vfunc_06()
{
    return DAT_003AE078;
}

}

// ============================================================================
// [VERIFIED] core::ControllerXBox::vfunc_07 (0x002052F0, 7 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// core::ControllerXBox::vfunc_07 (Proto 0x002052F0, 7 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

namespace core {

class ControllerXBox
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual void vfunc_05();
    virtual void vfunc_06();
    virtual void* vfunc_07();
    char m_pad04[0x444];
    int m_Field448; // +0x448
};

void* ControllerXBox::vfunc_07()
{
    return &m_Field448;
}

}

// ============================================================================
// [VERIFIED] core::ControllerXBox::vfunc_12 (0x00205300, 24 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// core::ControllerXBox::vfunc_12 (Proto 0x00205300, 24 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

namespace core {

class ControllerXBox
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
    virtual int vfunc_12(int a1);
    char m_pad04[0x10];
    int m_Field14; // +0x14
};

int ControllerXBox::vfunc_12(int a1)
{
    if ((unsigned int)a1 < (unsigned int)m_Field14) {
        return (a1 * 52) + (int)this + 24;
    }
    return 0;
}

}

// ============================================================================
// [VERIFIED] core::ControllerXBox::vfunc_17 (0x00205330, 27 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// core::ControllerXBox::vfunc_17 (Proto 0x00205330, 27 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

namespace core {

class ControllerXBox
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
    virtual int vfunc_17(int a1);
};

int ControllerXBox::vfunc_17(int a1)
{
    if ((unsigned int)a1 < (unsigned int)2) {
        return (a1 << 4) + (int)this + 1064;
    }
    return 0;
}

}

// ============================================================================
// [VERIFIED] core::ControllerXBox::vfunc_03 (0x00205350, 30 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as CollisionManager::CollisionManagerFlowClient::vfunc_00 (0x00016060), which was matched first;
// its addresses and names were swapped for this function's.
// core::ControllerXBox::vfunc_03 (0x00205350, 30 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __cdecl sub_00204D30(void);
extern "C" void __cdecl sub_00025160(int);

namespace core {

class ControllerXBox
{
public:
    virtual ControllerXBox* vfunc_03(int a1);
};

ControllerXBox* ControllerXBox::vfunc_03(int a1)
{
    sub_00204D30();
    if (a1 & 1) {
        sub_00025160((int)this);
    }
    return this;
}

}

// ============================================================================
// [VERIFIED] core::ControllerXBox::vfunc_01 (0x00240900, 4 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// core::ControllerXBox::vfunc_01 (Proto 0x00240900, 4 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

namespace core {

class ControllerXBox
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    int m_Field04; // +0x04
};

void ControllerXBox::vfunc_01()
{
    m_Field04 -= 1;
}

}

