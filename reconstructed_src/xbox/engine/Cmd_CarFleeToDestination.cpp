// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail Xbox default.xbe, engine/Cmd_CarFleeToDestination.cpp (1 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 1 of 2 functions matched (50.00%). NOT COMPLETE YET.
// The 1 still to do are listed in their place in Original_Binary_Order_Xbox.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] AICommands::Cmd_CarFleeToDestination::vfunc_04 (0x0012E420, 50 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as AICommands::Cmd_CarFleeToDestination::vfunc_04 (Proto 0x001125B0), which was matched first;
// its addresses and names were swapped for this function's.
// AICommands::Cmd_CarFleeToDestination::vfunc_04 (Proto 0x0012E420, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    int sub_00166D30();
};

extern "C" int __cdecl sub_00133D00(int, int);

namespace AICommands {

class Cmd_CarFleeToDestination
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual bool vfunc_04(int a1, int a2);
};

bool Cmd_CarFleeToDestination::vfunc_04(int a1, int a2)
{
    if (((Object*)a2)->sub_00166D30() != 1) {
        return true;
    }
    return !*(bool*)(sub_00133D00(a2, 1) + 124);
}

}

