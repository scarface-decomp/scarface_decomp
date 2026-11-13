// ============================================================================
// SCARFACE: THE WORLD IS YOURS — April 2006 prototype game.xbe, engine/ActiveBoatObject.cpp (1 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 1 of 11 functions matched (9.09%). NOT COMPLETE YET.
// The 10 still to do are listed in their place in Original_Binary_Order_Proto.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] ActiveBoatObject::vfunc_03 (0x001D9730, 5 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as PropAttachToObjectBehaviour::vfunc_01 (0x0008FAF0), which was matched first;
// its addresses and names were swapped for this function's.
// ActiveBoatObject::vfunc_03 (0x001D9730, 5 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __cdecl sub_001DDE70(void);

class ActiveBoatObject
{
public:
    virtual void vfunc_00();
    virtual void vfunc_03();
};

void ActiveBoatObject::vfunc_03()
{
    sub_001DDE70();
}

