// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail Xbox default.xbe, world/StatePropWaterCollisionBehaviour.cpp (2 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 2 of 3 functions matched (66.67%). NOT COMPLETE YET.
// The 1 still to do are listed in their place in Original_Binary_Order_Xbox.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] StatePropWaterCollisionBehaviour::vfunc_02 (0x001F2010, 18 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 /arch:SSE
// ============================================================================
// Same machine code as StatePropWaterCollisionBehaviour::vfunc_02 (Proto 0x001B7910), which was matched first;
// its addresses and names were swapped for this function's.
// bin: proto
// va: 0x001F2010
// what: 
// tool: the portal's starter code (no AI)

// StatePropWaterCollisionBehaviour::vfunc_02 (Proto 0x001F2010, 18 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" float DAT_0039D65C;

class StatePropWaterCollisionBehaviour
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    char m_pad04[0x8];
    bool m_Field0C; // +0x0C
    char m_pad0D[0x3];
    float m_Field10; // +0x10
};

void StatePropWaterCollisionBehaviour::vfunc_02()
{
    float t1;

    t1 = DAT_0039D65C;
    m_Field0C = false;
    m_Field10 = t1;
}

// ============================================================================
// [VERIFIED] StatePropWaterCollisionBehaviour::vfunc_00 (0x001F21C0, 36 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// What it does: StatePropWaterCollisionBehaviour's deleting destructor: destroys the object, frees its memory when asked (flag bit 0), and returns it.
// ============================================================================
// Same machine code as CollisionBehaviourTypeGroup::vfunc_01 (0x00013840), which was matched first;
// its addresses and names were swapped for this function's.
// StatePropWaterCollisionBehaviour::vfunc_00 (0x001F21C0, 36 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_003CA098[];
extern "C" void __cdecl sub_00027600(int);
extern "C" void __cdecl sub_00087E70(void);

class StatePropWaterCollisionBehaviour
{
public:
    virtual void vfunc_00();
    virtual StatePropWaterCollisionBehaviour* vfunc_00(int a1);
};

StatePropWaterCollisionBehaviour* StatePropWaterCollisionBehaviour::vfunc_00(int a1)
{
    *(int*)this = (int)DAT_003CA098;
    sub_00087E70();
    if (a1 & 1) {
        sub_00027600((int)this);
    }
    return this;
}

