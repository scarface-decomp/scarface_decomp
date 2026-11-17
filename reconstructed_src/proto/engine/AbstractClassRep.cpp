// ============================================================================
// SCARFACE: THE WORLD IS YOURS — April 2006 prototype game.xbe, engine/AbstractClassRep.cpp (1 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 1 of 2 functions matched (50.00%). NOT COMPLETE YET.
// The 1 still to do are listed in their place in Original_Binary_Order_Proto.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] AbstractClassRep::vfunc_01 (0x002C8D5D, 20 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// AbstractClassRep::vfunc_01 (Proto 0x002C8D5D, 20 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_004916FC;
extern "C" void __cdecl sub_002CCBBA(int);

class AbstractClassRep
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
};

void AbstractClassRep::vfunc_01()
{
    int t1;

    t1 = DAT_004916FC;
    if (DAT_004916FC) {
        ((void (__cdecl*)(void))t1)();
    }
    sub_002CCBBA(25);
}

