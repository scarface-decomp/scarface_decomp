// ============================================================================
// SCARFACE: THE WORLD IS YOURS — April 2006 prototype game.xbe, engine/Cmd_Skull.cpp (3 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: COMPLETE. All 3 functions are matched.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] AICommands::Cmd_Skull::vfunc_04 (0x00112D00, 6 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// AICommands::Cmd_Skull::vfunc_04 (Proto 0x00112D00, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

namespace AICommands {

class Cmd_Skull
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual bool vfunc_04(int a1, int a2);
    char m_pad04[0x4];
    bool m_Field08; // +0x08
};

bool Cmd_Skull::vfunc_04(int a1, int a2)
{
    return m_Field08;
}

}

// ============================================================================
// [VERIFIED] AICommands::Cmd_Skull::vfunc_01 (0x00112D10, 7 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// AICommands::Cmd_Skull::vfunc_01 (Proto 0x00112D10, 7 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

namespace AICommands {

class Cmd_Skull
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01(int a1, int a2);
    char m_pad04[0x4];
    bool m_Field08; // +0x08
};

void Cmd_Skull::vfunc_01(int a1, int a2)
{
    m_Field08 = false;
}

}

// ============================================================================
// [VERIFIED] AICommands::Cmd_Skull::vfunc_08 (0x00112D20, 26 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// AICommands::Cmd_Skull::vfunc_08 (Proto 0x00112D20, 26 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    bool sub_000EE970(int);
};

namespace AICommands {

class Cmd_Skull
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
    virtual void vfunc_08(int a1, int a2, int a3);
    char m_pad04[0x4];
    bool m_Field08; // +0x08
};

void Cmd_Skull::vfunc_08(int a1, int a2, int a3)
{
    if (!((Object*)a3)->sub_000EE970(0)) {
        m_Field08 = true;
    }
}

}

