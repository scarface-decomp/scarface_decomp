// ============================================================================
// SCARFACE: THE WORLD IS YOURS — April 2006 prototype game.xbe, om/SocketRpcConnection.cpp (1 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 1 of 2 functions matched (50.00%). NOT COMPLETE YET.
// The 1 still to do are listed in their place in Original_Binary_Order_Proto.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] om::SocketRpcConnection::vfunc_00 (0x0029FD10, 41 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// om::SocketRpcConnection::vfunc_00 (Proto 0x0029FD10, 41 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_003B9B44[];
extern "C" char DAT_00490EC4[];
extern "C" void __cdecl sub_002935D0(int, int);
extern "C" void __cdecl sub_0029DD70(void);

namespace om {

class SocketRpcConnection
{
public:
    virtual SocketRpcConnection* vfunc_00(int a1);
};

SocketRpcConnection* SocketRpcConnection::vfunc_00(int a1)
{
    *(int*)this = (int)DAT_003B9B44;
    sub_0029DD70();
    if (a1 & 1) {
        sub_002935D0((int)DAT_00490EC4, (int)this);
    }
    return this;
}

}

