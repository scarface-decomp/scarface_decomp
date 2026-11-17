// ============================================================================
// SCARFACE: THE WORLD IS YOURS — April 2006 prototype game.xbe, om/RpcConnection.cpp (1 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: COMPLETE. All 1 functions are matched.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] om::RpcConnection::vfunc_00 (0x0029DEC0, 39 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// om::RpcConnection::vfunc_00 (Proto 0x0029DEC0, 39 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field04
{
    void sub_001B7A10();
};

extern "C" char DAT_003B99DC[];
extern "C" void __cdecl sub_00025160(int);

namespace om {

class RpcConnection
{
public:
    virtual RpcConnection* vfunc_00(int a1);
    Field04 m_Field04; // +0x04
};

RpcConnection* RpcConnection::vfunc_00(int a1)
{
    *(int*)this = (int)DAT_003B99DC;
    m_Field04.sub_001B7A10();
    if (a1 & 1) {
        sub_00025160((int)this);
    }
    return this;
}

}

