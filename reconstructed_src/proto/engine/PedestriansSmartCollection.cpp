// ============================================================================
// SCARFACE: THE WORLD IS YOURS — April 2006 prototype game.xbe, engine/PedestriansSmartCollection.cpp (2 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: COMPLETE. All 2 functions are matched.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] PedestriansSmartCollection::vfunc_01 (0x000DC550, 17 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// bin: proto
// va: 0x000DC550
// what: 
// tool: the portal's starter code (no AI)

// PedestriansSmartCollection::vfunc_01 (Proto 0x000DC550, 17 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    int sub_0014A290();
};

class PedestriansSmartCollection
{
public:
    virtual void vfunc_00();
    virtual int vfunc_01(int a1);
};

int PedestriansSmartCollection::vfunc_01(int a1)
{
    return !((Object*)a1)->sub_0014A290();
}

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

