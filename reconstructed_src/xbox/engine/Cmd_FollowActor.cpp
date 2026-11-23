// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail Xbox default.xbe, engine/Cmd_FollowActor.cpp (2 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 2 of 3 functions matched (66.67%). NOT COMPLETE YET.
// The 1 still to do are listed in their place in Original_Binary_Order_Xbox.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] AICommands::Cmd_FollowActor::vfunc_05 (0x0012E960, 63 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// AICommands::Cmd_FollowActor::vfunc_05 (0x0012E960, 63 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_00125940(int, int, int, int);
};

extern "C" char DAT_00427AFC[];
extern "C" char DAT_0042BDD4[];
extern "C" int __cdecl sub_002FC034(int, int, int, int, int);

namespace AICommands {

class Cmd_FollowActor
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual bool vfunc_05(int a1, int a2, int a3);
    char m_pad04[0x4];
    int m_Field08; // +0x08
    int m_Field0C; // +0x0C
    int m_Field10; // +0x10
};

bool Cmd_FollowActor::vfunc_05(int a1, int a2, int a3)
{
    if (sub_002FC034(a3, 0, (int)DAT_00427AFC, (int)DAT_0042BDD4, 0)) {
        ((Object*)a3)->sub_00125940(m_Field08, m_Field0C, m_Field10, 0);
    }
    return true;
}

}

// ============================================================================
// [VERIFIED] AICommands::Cmd_FollowActor::vfunc_07 (0x0012E9A0, 21 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as AICommands::Cmd_FollowActor::vfunc_07 (Proto 0x00112AF0), which was matched first;
// its addresses and names were swapped for this function's.
// bin: proto
// va: 0x0012E9A0
// what: 
// tool: the portal's starter code (no AI)

// AICommands::Cmd_FollowActor::vfunc_07 (Proto 0x0012E9A0, 21 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int __cdecl sub_0002AC90(int);

namespace AICommands {

class Cmd_FollowActor
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual void vfunc_05();
    virtual void vfunc_06();
    virtual int vfunc_07(int a1, int a2, int a3);
    char m_pad04[0x4];
    int m_Field08; // +0x08
};

int Cmd_FollowActor::vfunc_07(int a1, int a2, int a3)
{
    return sub_0002AC90(m_Field08) != 0;
}

}

