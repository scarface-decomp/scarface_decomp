// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail Xbox default.xbe, core/Request.cpp (1 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: COMPLETE. All 1 functions are matched.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] core::Request::vfunc_00 (0x002AA610, 60 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as core::Request::vfunc_00 (Proto 0x0026CD90), which was matched first;
// its addresses and names were swapped for this function's.
// core::Request::vfunc_00 (Proto 0x002AA610, 60 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual void vfunc_05(int);
};

extern "C" char DAT_003DA6C8[];
extern "C" char DAT_004BDD44[];
extern "C" int DAT_004BDD60;
extern "C" void __cdecl sub_00283B70(int);
extern "C" void __cdecl sub_00283B80(int);

namespace core {

class Request
{
public:
    virtual Request* vfunc_00(int a1);
};

Request* Request::vfunc_00(int a1)
{
    *(int*)this = (int)DAT_003DA6C8;
    if (a1 & 1) {
        sub_00283B80((int)DAT_004BDD44);
        ((Object*)DAT_004BDD60)->vfunc_05((int)this);
        sub_00283B70((int)DAT_004BDD44);
    }
    return this;
}

}

