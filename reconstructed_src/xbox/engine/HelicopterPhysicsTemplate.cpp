// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail Xbox default.xbe, engine/HelicopterPhysicsTemplate.cpp (3 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: COMPLETE. All 3 functions are matched.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] HelicopterPhysicsTemplate::vfunc_00 (0x002017F0, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as CollisionBehaviourTypeGroup::vfunc_00 (0x000123B0), which was matched first;
// its addresses and names were swapped for this function's.
// HelicopterPhysicsTemplate::vfunc_00 (0x002017F0, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_00444020[];

class HelicopterPhysicsTemplate
{
public:
    virtual void* vfunc_00();
};

void* HelicopterPhysicsTemplate::vfunc_00()
{
    return DAT_00444020;
}

// ============================================================================
// [VERIFIED] HelicopterPhysicsTemplate::vfunc_04 (0x00201800, 36 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// HelicopterPhysicsTemplate::vfunc_04 (0x00201800, 36 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field100
{
    void sub_000A4900();
};

struct Field78
{
    void sub_000A4820();
};

extern "C" void __stdcall sub_0020D120(int);

class HelicopterPhysicsTemplate
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04(int a1);
    char m_pad04[0x74];
    Field78 m_Field78; // +0x78
    char m_pad79[0x87];
    Field100 m_Field100; // +0x100
};

void HelicopterPhysicsTemplate::vfunc_04(int a1)
{
    sub_0020D120(a1);
    m_Field78.sub_000A4820();
    m_Field100.sub_000A4900();
}

// ============================================================================
// [VERIFIED] HelicopterPhysicsTemplate::vfunc_01 (0x00201830, 36 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as CollisionBehaviourTypeGroup::vfunc_01 (0x00013840), which was matched first;
// its addresses and names were swapped for this function's.
// HelicopterPhysicsTemplate::vfunc_01 (0x00201830, 36 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_003CBFEC[];
extern "C" void __cdecl sub_00027600(int);
extern "C" void __cdecl sub_0020C490(void);

class HelicopterPhysicsTemplate
{
public:
    virtual void vfunc_00();
    virtual HelicopterPhysicsTemplate* vfunc_01(int a1);
};

HelicopterPhysicsTemplate* HelicopterPhysicsTemplate::vfunc_01(int a1)
{
    *(int*)this = (int)DAT_003CBFEC;
    sub_0020C490();
    if (a1 & 1) {
        sub_00027600((int)this);
    }
    return this;
}

