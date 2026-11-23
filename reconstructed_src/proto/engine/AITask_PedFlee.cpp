// ============================================================================
// SCARFACE: THE WORLD IS YOURS — April 2006 prototype game.xbe, engine/AITask_PedFlee.cpp (5 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 5 of 10 functions matched (50.00%). NOT COMPLETE YET.
// The 5 still to do are listed in their place in Original_Binary_Order_Proto.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] AITask_PedFlee::vfunc_00 (0x000F1EB0, 23 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// AITask_PedFlee::vfunc_00 (Proto 0x000F1EB0, 23 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_0045A0EC;

class AITask_PedFlee
{
public:
    virtual bool vfunc_00();
    char m_pad04[0x70];
    int m_Field74; // +0x74
};

bool AITask_PedFlee::vfunc_00()
{
    return (*(int*)(DAT_0045A0EC + 44) - m_Field74) > 500;
}

// ============================================================================
// [VERIFIED] AITask_PedFlee::vfunc_01 (0x000F1ED0, 8 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// AITask_PedFlee::vfunc_01 (Proto 0x000F1ED0, 8 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_000EEAA0();
};

class AITask_PedFlee
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
};

void AITask_PedFlee::vfunc_01()
{
    ((Object*)(int)this + -76)->sub_000EEAA0();
}

// ============================================================================
// [VERIFIED] AITask_PedFlee::vfunc_00 (0x000F2860, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as CollisionBehaviourTypeGroup::vfunc_00 (0x000123B0), which was matched first;
// its addresses and names were swapped for this function's.
// AITask_PedFlee::vfunc_00 (0x000F2860, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_00404164[];

class AITask_PedFlee
{
public:
    virtual void* vfunc_00();
};

void* AITask_PedFlee::vfunc_00()
{
    return DAT_00404164;
}

// ============================================================================
// [VERIFIED] AITask_PedFlee::vfunc_03 (0x000F2870, 7 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as AITask_PedFlee::vfunc_03 (0x001095B0), which was matched first;
// its addresses and names were swapped for this function's.
// bin: xb
// va: 0x000F2870
// what: Returns a fixed number kept in the game's data.
// tool: Claude Fable 5.2 (look-alike of 0x000EFD20, names and addresses swapped)
// AITask_PedFlee::vfunc_03 (0x000F2870, 7 bytes)
extern "C" float DAT_00384614;

class AITask_PedFlee
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual float vfunc_03();
};

float AITask_PedFlee::vfunc_03()
{
    return DAT_00384614;
}

// ============================================================================
// [VERIFIED] AITask_PedFlee::vfunc_01 (0x000F2940, 51 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// What it does: AITask_PedFlee's deleting destructor: destroys the object, frees its memory when asked (flag bit 0), and returns it.
// ============================================================================
// AITask_PedFlee::vfunc_01 (Proto 0x000F2940, 51 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field50
{
    void sub_000DBE80();
};

struct FieldAC
{
    void sub_00102BA0();
};

extern "C" void __cdecl sub_00025160(int);

class AITask_PedFlee
{
public:
    virtual void vfunc_00();
    virtual AITask_PedFlee* vfunc_01(int a1);
    void sub_000DC430();
    char m_pad04[0x4C];
    Field50 m_Field50; // +0x50
    char m_pad51[0x5B];
    FieldAC m_FieldAC; // +0xAC
};

AITask_PedFlee* AITask_PedFlee::vfunc_01(int a1)
{
    m_FieldAC.sub_00102BA0();
    m_Field50.sub_000DBE80();
    sub_000DC430();
    if (a1 & 1) {
        sub_00025160((int)this);
    }
    return this;
}

