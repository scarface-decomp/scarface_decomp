// ============================================================================
// SCARFACE: THE WORLD IS YOURS — April 2006 prototype game.xbe, engine/Cmd.cpp (2 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: COMPLETE. All 2 functions are matched.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] AICommandSequencer::Cmd::vfunc_05 (0x00112570, 5 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// AICommandSequencer::Cmd::vfunc_05 (Proto 0x00112570, 5 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

namespace AICommandSequencer {

class Cmd
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual bool vfunc_05(int a1, int a2, int a3);
};

bool Cmd::vfunc_05(int a1, int a2, int a3)
{
    return true;
}

}

// ============================================================================
// [VERIFIED] AICommandSequencer::Cmd::vfunc_00 (0x00112D40, 31 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as core::BaseObject::vfunc_00 (0x00026BB0), which was matched first;
// its addresses and names were swapped for this function's.
// AICommandSequencer::Cmd::vfunc_00 (0x00112D40, 31 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0038F1E0[];
extern "C" void __cdecl sub_00025160(int);

namespace AICommandSequencer {

class Cmd
{
public:
    virtual Cmd* vfunc_00(int a1);
};

Cmd* Cmd::vfunc_00(int a1)
{
    *(int*)this = (int)DAT_0038F1E0;
    if (a1 & 1) {
        sub_00025160((int)this);
    }
    return this;
}

}

