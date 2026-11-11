// ============================================================================
// SCARFACE: THE WORLD IS YOURS — April 2006 prototype game.xbe, engine/PropAttachToObjectBehaviour.cpp (1 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 1 of 4 functions matched (25.00%). NOT COMPLETE YET.
// The 3 still to do are listed in their place in Original_Binary_Order_Proto.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] PropAttachToObjectBehaviour::vfunc_00 (0x00084880, 36 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as CollisionBehaviourTypeGroup::vfunc_01 (0x00013840), which was matched first;
// its addresses and names were swapped for this function's.
// PropAttachToObjectBehaviour::vfunc_00 (0x00084880, 36 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_00383824[];
extern "C" void __cdecl sub_00025160(int);
extern "C" void __cdecl sub_0007DA30(void);

class PropAttachToObjectBehaviour
{
public:
    virtual void vfunc_00();
    virtual PropAttachToObjectBehaviour* vfunc_00(int a1);
};

PropAttachToObjectBehaviour* PropAttachToObjectBehaviour::vfunc_00(int a1)
{
    *(int*)this = (int)DAT_00383824;
    sub_0007DA30();
    if (a1 & 1) {
        sub_00025160((int)this);
    }
    return this;
}

