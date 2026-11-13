// ============================================================================
// SCARFACE: THE WORLD IS YOURS — April 2006 prototype game.xbe, engine/PedestriansSmartCollection.cpp (1 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 1 of 2 functions matched (50.00%). NOT COMPLETE YET.
// The 1 still to do are listed in their place in Original_Binary_Order_Proto.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] PedestriansSmartCollection::vfunc_00 (0x000DD320, 7 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as DriversSmartCollection::vfunc_00 (0x00125060), which was matched first;
// its addresses and names were swapped for this function's.
// bin: xb
// va: 0x000DD320
// what: Returns a fixed number kept in the game's data.
// tool: Claude Fable 5.2 (look-alike of 0x000EFD20, names and addresses swapped)
// PedestriansSmartCollection::vfunc_00 (0x000DD320, 7 bytes)
extern "C" float DAT_003A968C;

class PedestriansSmartCollection
{
public:
    virtual float vfunc_00();
};

float PedestriansSmartCollection::vfunc_00()
{
    return DAT_003A968C;
}

