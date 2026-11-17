// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail Xbox default.xbe, engine/Cmd_Engage.cpp (3 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 3 of 5 functions matched (60.00%). NOT COMPLETE YET.
// The 2 still to do are listed in their place in Original_Binary_Order_Xbox.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] AICommands::Cmd_Engage::vfunc_06 (0x0012E480, 80 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// AICommands::Cmd_Engage::vfunc_06 (0x0012E480, 80 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_00427AFC[];
extern "C" char DAT_00428314[];
extern "C" char DAT_00428394[];
extern "C" int __cdecl sub_002FC034(int, int, int, int, int);

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
    int r_esi, t1, t2;

    if (m_Field08 != -1) {
        r_esi = a3;
        t1 = sub_002FC034(a3, 0, (int)DAT_00427AFC, (int)DAT_00428314, 0);
        if (t1) {
            *(bool*)(t1 + 212) = false;
        }
        t2 = sub_002FC034(r_esi, 0, (int)DAT_00427AFC, (int)DAT_00428394, 0);
        if (!t2) goto L_4D;
        *(bool*)(t2 + 84) = false;
    }
L_4D:
    ;
}

}

// ============================================================================
// [VERIFIED] AICommands::Cmd_Engage::vfunc_08 (0x0012E4D0, 80 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// AICommands::Cmd_Engage::vfunc_08 (0x0012E4D0, 80 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_00427AFC[];
extern "C" char DAT_00428314[];
extern "C" char DAT_00428394[];
extern "C" int __cdecl sub_002FC034(int, int, int, int, int);

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
    virtual void vfunc_07();
    virtual void vfunc_08(int a1, int a2, int a3);
    char m_pad04[0x4];
    int m_Field08; // +0x08
};

void Cmd_Engage::vfunc_08(int a1, int a2, int a3)
{
    int r_esi, t1, t2;

    if (m_Field08 != -1) {
        r_esi = a3;
        t1 = sub_002FC034(a3, 0, (int)DAT_00427AFC, (int)DAT_00428314, 0);
        if (t1) {
            *(bool*)(t1 + 212) = true;
        }
        t2 = sub_002FC034(r_esi, 0, (int)DAT_00427AFC, (int)DAT_00428394, 0);
        if (!t2) goto L_4D;
        *(bool*)(t2 + 84) = true;
    }
L_4D:
    ;
}

}

// ============================================================================
// [VERIFIED] AICommands::Cmd_Engage::vfunc_07 (0x0012EE00, 17 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as AICommands::Cmd_Engage::vfunc_07 (Proto 0x00112F50), which was matched first;
// its addresses and names were swapped for this function's.
// AICommands::Cmd_Engage::vfunc_07 (Proto 0x0012EE00, 17 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __stdcall sub_0012E520(int, int);

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
    sub_0012E520(a2, 1);
    return true;
}

}

