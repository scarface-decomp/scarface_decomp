// ============================================================================
// SCARFACE: THE WORLD IS YOURS — April 2006 prototype game.xbe, engine/Graph.cpp (2 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: COMPLETE. All 2 functions are matched.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] Graph::vfunc_00 (0x00024380, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as CollisionBehaviourTypeGroup::vfunc_00 (0x000123B0), which was matched first;
// its addresses and names were swapped for this function's.
// Graph::vfunc_00 (0x00024380, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_003F6104[];

class Graph
{
public:
    virtual void* vfunc_00();
};

void* Graph::vfunc_00()
{
    return DAT_003F6104;
}

// ============================================================================
// [VERIFIED] Graph::vfunc_01 (0x000243D0, 54 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as Graph::vfunc_01 (0x00026760), which was matched first;
// its addresses and names were swapped for this function's.
// Graph::vfunc_01 (0x000243D0, 54 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0037E654[];
extern "C" void __cdecl sub_00025160(int);

class Graph
{
public:
    virtual void vfunc_00();
    virtual Graph* vfunc_01(int a1);
    void sub_000277E0();
    char m_pad04[0x34];
    int m_Field38; // +0x38
};

Graph* Graph::vfunc_01(int a1)
{
    int t1;

    t1 = m_Field38;
    *(int*)this = (int)DAT_0037E654;
    if (m_Field38) {
        sub_00025160(t1);
    }
    sub_000277E0();
    if (a1 & 1) {
        sub_00025160((int)this);
    }
    return this;
}

