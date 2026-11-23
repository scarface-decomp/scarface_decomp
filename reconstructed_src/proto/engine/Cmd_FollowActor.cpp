// ============================================================================
// SCARFACE: THE WORLD IS YOURS — April 2006 prototype game.xbe, engine/Cmd_FollowActor.cpp (2 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 2 of 3 functions matched (66.67%). NOT COMPLETE YET.
// The 1 still to do are listed in their place in Original_Binary_Order_Proto.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] AICommands::Cmd_FollowActor::vfunc_05 (0x00112AB0, 61 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// AICommands::Cmd_FollowActor::vfunc_05 (Proto 0x00112AB0, 61 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0010A150(int, int, int);
};

extern "C" char DAT_00402654[];
extern "C" char DAT_0040693C[];
extern "C" int __cdecl sub_002C92F8(int, int, int, int, int);

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
    if (sub_002C92F8(a3, 0, (int)DAT_00402654, (int)DAT_0040693C, 0)) {
        ((Object*)a3)->sub_0010A150(m_Field08, m_Field0C, m_Field10);
    }
    return true;
}

}

// ============================================================================
// [VERIFIED] AICommands::Cmd_FollowActor::vfunc_07 (0x00112AF0, 21 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// bin: proto
// va: 0x00112AF0
// what: 
// tool: the portal's starter code (no AI)

// AICommands::Cmd_FollowActor::vfunc_07 (Proto 0x00112AF0, 21 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int __cdecl sub_00028120(int);

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
    return sub_00028120(m_Field08) != 0;
}

}

