// ============================================================================
// SCARFACE: THE WORLD IS YOURS — April 2006 prototype game.xbe, engine/OceanPrimitive.cpp (3 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 3 of 4 functions matched (75.00%). NOT COMPLETE YET.
// The 1 still to do are listed in their place in Original_Binary_Order_Proto.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] renderer::OceanPrimitive::vfunc_08 (0x0004C7C0, 13 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// renderer::OceanPrimitive::vfunc_08 (Proto 0x0004C7C0, 13 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0021A460();
};

namespace renderer {

class OceanPrimitive
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
    char m_pad04[0x38];
    int m_Field3C; // +0x3C
};

void OceanPrimitive::vfunc_08()
{
    int t1;

    t1 = m_Field3C;
    if (m_Field3C) {
        ((Object*)t1)->sub_0021A460();
        return;
    }
}

}

// ============================================================================
// [VERIFIED] renderer::OceanPrimitive::vfunc_07 (0x0004C7D0, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as pure3d::TargaHandler::vfunc_07 (0x0004A760), which was matched first;
// its addresses and names were swapped for this function's.
// renderer::OceanPrimitive::vfunc_07 (0x0004C7D0, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_00020000[];

namespace renderer {

class OceanPrimitive
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
};

void* OceanPrimitive::vfunc_07()
{
    return DAT_00020000;
}

}

// ============================================================================
// [VERIFIED] renderer::OceanPrimitive::vfunc_03 (0x0004C970, 30 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as CollisionManager::CollisionManagerFlowClient::vfunc_00 (0x00016060), which was matched first;
// its addresses and names were swapped for this function's.
// renderer::OceanPrimitive::vfunc_03 (0x0004C970, 30 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __cdecl sub_0004C8E0(void);
extern "C" void __cdecl sub_001FCF60(int);

namespace renderer {

class OceanPrimitive
{
public:
    virtual OceanPrimitive* vfunc_03(int a1);
};

OceanPrimitive* OceanPrimitive::vfunc_03(int a1)
{
    sub_0004C8E0();
    if (a1 & 1) {
        sub_001FCF60((int)this);
    }
    return this;
}

}

