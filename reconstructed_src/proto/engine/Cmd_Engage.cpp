// ============================================================================
// SCARFACE: THE WORLD IS YOURS — April 2006 prototype game.xbe, engine/Cmd_Engage.cpp (2 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 2 of 4 functions matched (50.00%). NOT COMPLETE YET.
// The 2 still to do are listed in their place in Original_Binary_Order_Proto.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] AICommands::Cmd_Engage::vfunc_06 (0x00112610, 47 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// AICommands::Cmd_Engage::vfunc_06 (Proto 0x00112610, 47 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_00402654[];
extern "C" char DAT_00402ECC[];
extern "C" int __cdecl sub_002C92F8(int, int, int, int, int);

namespace AICommands {

class Cmd_Engage
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual void vfunc_05();
    virtual void vfunc_06(int a1, int a2, int a3);
    char m_pad04[0x4];
    int m_Field08; // +0x08
};

void Cmd_Engage::vfunc_06(int a1, int a2, int a3)
{
    int t1;

    if (m_Field08 != -1) {
        t1 = sub_002C92F8(a3, 0, (int)DAT_00402654, (int)DAT_00402ECC, 0);
        if (!t1) goto L_2C;
        *(bool*)(t1 + 212) = false;
    }
L_2C:
    ;
}

}

// ============================================================================
// [VERIFIED] AICommands::Cmd_Engage::vfunc_07 (0x00112F50, 17 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// AICommands::Cmd_Engage::vfunc_07 (Proto 0x00112F50, 17 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __stdcall sub_00112640(int, int);

namespace AICommands {

class Cmd_Engage
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual void vfunc_05();
    virtual void vfunc_06();
    virtual bool vfunc_07(int a1, int a2, int a3);
};

bool Cmd_Engage::vfunc_07(int a1, int a2, int a3)
{
    sub_00112640(a2, 1);
    return true;
}

}

