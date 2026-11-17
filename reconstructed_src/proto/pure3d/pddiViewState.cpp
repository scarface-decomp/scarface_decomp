// ============================================================================
// SCARFACE: THE WORLD IS YOURS — April 2006 prototype game.xbe, pure3d/pddiViewState.cpp (1 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: COMPLETE. All 1 functions are matched.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] pure3d::pddiViewState::vfunc_00 (0x00260AD0, 103 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// pure3d::pddiViewState::vfunc_00 (Proto 0x00260AD0, 103 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual void vfunc_05();
    virtual void vfunc_06(int);
    virtual void vfunc_07();
    virtual void vfunc_08(int);
    virtual void vfunc_09();
    virtual void vfunc_10(int);
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
    virtual void vfunc_26(int);
    virtual void vfunc_27();
    virtual void vfunc_28(int, int, int, int);
    virtual void vfunc_29();
    virtual void vfunc_30(int, int, int, int);
};

namespace pure3d {

class pddiViewState
{
public:
    virtual void vfunc_00(int a1);
    int m_Field04; // +0x04
    int m_Field08; // +0x08
    int m_Field0C; // +0x0C
    int m_Field10; // +0x10
    int m_Field14; // +0x14
    int m_Field18; // +0x18
    int m_Field1C; // +0x1C
    int m_Field20; // +0x20
    int m_Field24; // +0x24
    int m_Field28; // +0x28
    int m_Field2C; // +0x2C
    int m_Field30; // +0x30
};

void pddiViewState::vfunc_00(int a1)
{
    ((Object*)a1)->vfunc_06(m_Field04);
    ((Object*)a1)->vfunc_08(m_Field08);
    ((Object*)a1)->vfunc_10(m_Field0C);
    ((Object*)a1)->vfunc_26(m_Field10);
    ((Object*)a1)->vfunc_28(m_Field14, m_Field18, m_Field1C, m_Field20);
    ((Object*)a1)->vfunc_30(m_Field24, m_Field28, m_Field2C, m_Field30);
}

}

