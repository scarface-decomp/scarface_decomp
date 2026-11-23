// ============================================================================
// SCARFACE: THE WORLD IS YOURS — April 2006 prototype game.xbe, engine/DrawHandler.cpp (1 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: COMPLETE. All 1 functions are matched.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] FrontEndManager::DrawHandler::vfunc_00 (0x00022050, 35 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// bin: proto
// va: 0x00022050
// what: 
// tool: the portal's starter code (no AI)

// FrontEndManager::DrawHandler::vfunc_00 (Proto 0x00022050, 35 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_00021F90();
    int sub_0020BC60();
};

extern "C" bool DAT_003F56B0;
extern "C" Object DAT_003F56B8;
extern "C" int DAT_00446A90;

namespace FrontEndManager {

class DrawHandler
{
public:
    virtual void vfunc_00();
};

void DrawHandler::vfunc_00()
{
    int r_eax;

    r_eax = DAT_003F56B0;
    if ((unsigned char)r_eax) {
        if (DAT_00446A90) {
            r_eax = ((Object*)DAT_00446A90)->sub_0020BC60();
        }
        DAT_003F56B8.sub_00021F90();
        return;
    }
}

}

