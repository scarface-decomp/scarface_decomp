// ============================================================================
// SCARFACE: THE WORLD IS YOURS — April 2006 prototype game.xbe, core/TargetSocket.cpp (1 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: COMPLETE. All 1 functions are matched.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] core::TargetSocket::vfunc_00 (0x0026AD10, 37 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// core::TargetSocket::vfunc_00 (Proto 0x0026AD10, 37 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_003B3ADC[];
extern "C" int DAT_0048E96C;
extern "C" void __cdecl sub_00201990(int, int);

namespace core {

class TargetSocket
{
public:
    virtual TargetSocket* vfunc_00(int a1);
};

TargetSocket* TargetSocket::vfunc_00(int a1)
{
    *(int*)this = (int)DAT_003B3ADC;
    if (a1 & 1) {
        sub_00201990(DAT_0048E96C, (int)this);
    }
    return this;
}

}

