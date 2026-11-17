// ============================================================================
// SCARFACE: THE WORLD IS YOURS — April 2006 prototype game.xbe, om/Rpc.cpp (1 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: COMPLETE. All 1 functions are matched.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] om::Rpc::vfunc_00 (0x0029DF50, 46 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// om::Rpc::vfunc_00 (Proto 0x0029DF50, 46 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_00297380(int);
};

extern "C" char DAT_003B99E8[];
extern "C" void __cdecl sub_00025160(int);

namespace om {

class Rpc
{
public:
    virtual Rpc* vfunc_00(int a1);
    int m_Field04; // +0x04
    char m_pad08[0x10];
    int m_Field18; // +0x18
};

Rpc* Rpc::vfunc_00(int a1)
{
    *(int*)this = (int)DAT_003B99E8;
    ((Object*)m_Field18 + 4)->sub_00297380((int)(&m_Field04));
    if (a1 & 1) {
        sub_00025160((int)this);
    }
    return this;
}

}

