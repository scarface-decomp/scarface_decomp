// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail Xbox default.xbe, engine/OceanPrimitive.cpp (4 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: COMPLETE. All 4 functions are matched.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] renderer::OceanPrimitive::vfunc_08 (0x000551E0, 13 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// renderer::OceanPrimitive::vfunc_08 (0x000551E0, 13 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_00260E50();
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
    char m_pad04[0x34];
    int m_Field38; // +0x38
};

void OceanPrimitive::vfunc_08()
{
    int t1;

    t1 = m_Field38;
    if (m_Field38) {
        ((Object*)t1)->sub_00260E50();
        return;
    }
}

}

// ============================================================================
// [VERIFIED] renderer::OceanPrimitive::vfunc_07 (0x000551F0, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as pure3d::TargaHandler::vfunc_07 (0x0004A760), which was matched first;
// its addresses and names were swapped for this function's.
// renderer::OceanPrimitive::vfunc_07 (0x000551F0, 6 bytes)
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
// [VERIFIED] renderer::OceanPrimitive::vfunc_13 (0x00055200, 38 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 /arch:SSE
// ============================================================================
// bin: xb
// va: 0x00055200
// what: 
// tool: the portal's starter code (no AI)

// renderer::OceanPrimitive::vfunc_13 (0x00055200, 38 bytes)
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
    virtual void vfunc_24(int);
};

extern "C" float DAT_003A0C34;
extern "C" int __cdecl sub_00047E70(void);

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
    virtual void vfunc_09();
    virtual void vfunc_10();
    virtual void vfunc_11();
    virtual void vfunc_12();
    virtual void vfunc_13();
    char m_pad04[0x24];
    int m_Field28; // +0x28
    char m_pad2C[0x8];
    float m_Field34; // +0x34
};

void OceanPrimitive::vfunc_13()
{
    int t1;

    t1 = sub_00047E70();
    if (t1) {
        ((Object*)t1)->vfunc_24((int)(&m_Field28));
        m_Field34 = DAT_003A0C34;
    }
}

}

// ============================================================================
// [VERIFIED] renderer::OceanPrimitive::vfunc_03 (0x00055380, 30 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// What it does: renderer::OceanPrimitive's deleting destructor: destroys the object, frees its memory when asked (flag bit 0), and returns it.
// ============================================================================
// Same machine code as CollisionManager::CollisionManagerFlowClient::vfunc_00 (0x00016060), which was matched first;
// its addresses and names were swapped for this function's.
// renderer::OceanPrimitive::vfunc_03 (0x00055380, 30 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __cdecl sub_000552F0(void);
extern "C" void __cdecl sub_0023F7A0(int);

namespace renderer {

class OceanPrimitive
{
public:
    virtual OceanPrimitive* vfunc_03(int a1);
};

OceanPrimitive* OceanPrimitive::vfunc_03(int a1)
{
    sub_000552F0();
    if (a1 & 1) {
        sub_0023F7A0((int)this);
    }
    return this;
}

}

