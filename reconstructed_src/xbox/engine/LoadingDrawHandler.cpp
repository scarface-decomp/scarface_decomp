// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail Xbox default.xbe, engine/LoadingDrawHandler.cpp (1 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: COMPLETE. All 1 functions are matched.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] FrontEndManager::LoadingDrawHandler::vfunc_00 (0x00023F50, 27 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// FrontEndManager::LoadingDrawHandler::vfunc_00 (0x00023F50, 27 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    int sub_0024E180(int);
};

extern "C" bool DAT_0041A6B0;
extern "C" int DAT_00471768;

namespace FrontEndManager {

class LoadingDrawHandler
{
public:
    virtual void vfunc_00();
};

void LoadingDrawHandler::vfunc_00()
{
    int r_eax;

    r_eax = DAT_0041A6B0;
    if ((unsigned char)r_eax) {
        if (!DAT_00471768) goto L_1A;
        r_eax = ((Object*)DAT_00471768)->sub_0024E180(1);
    }
L_1A:
    return;
}

}

