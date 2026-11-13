// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail Xbox default.xbe, engine/Cmd_EnterVehicle.cpp (2 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: COMPLETE. All 2 functions are matched.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] AICommands::Cmd_EnterVehicle::vfunc_04 (0x0012E600, 46 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// AICommands::Cmd_EnterVehicle::vfunc_04 (0x0012E600, 46 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    int sub_00166CE0();
    bool sub_00171D20();
};

namespace AICommands {

class Cmd_EnterVehicle
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual int vfunc_04(int a1, int a2);
};

int Cmd_EnterVehicle::vfunc_04(int a1, int a2)
{
    if (((Object*)a2)->sub_00166CE0()) {
        if (!((Object*)a2 + 744)->sub_00171D20()) goto L_28;
        return 1;
    }
L_28:
    return 0;
}

}

// ============================================================================
// [VERIFIED] AICommands::Cmd_EnterVehicle::vfunc_05 (0x0012E630, 65 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// AICommands::Cmd_EnterVehicle::vfunc_05 (0x0012E630, 65 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0010D3C0(int);
    void sub_0010D4F0(int);
};

extern "C" char DAT_00427AFC[];
extern "C" char DAT_004284E8[];
extern "C" int __cdecl sub_002FC034(int, int, int, int, int);

namespace AICommands {

class Cmd_EnterVehicle
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
    char m_Field0C; // +0x0C
};

bool Cmd_EnterVehicle::vfunc_05(int a1, int a2, int a3)
{
    if (sub_002FC034(a3, 0, (int)DAT_00427AFC, (int)DAT_004284E8, 0)) {
        ((Object*)a3)->sub_0010D4F0(m_Field08);
        ((Object*)a3)->sub_0010D3C0(m_Field0C);
    }
    return true;
}

}

