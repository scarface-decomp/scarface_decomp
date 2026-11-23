// ============================================================================
// SCARFACE: THE WORLD IS YOURS — April 2006 prototype game.xbe, engine/GameSetIteratorFunctionFilter_CharacterObject_.cpp (1 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: COMPLETE. All 1 functions are matched.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] GameSetIteratorFunctionFilter<CharacterObject>::vfunc_00 (0x000F3240, 14 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// bin: proto
// va: 0x000F3240
// what: 
// tool: the portal's starter code (no AI)

// GameSetIteratorFunctionFilter<CharacterObject>::vfunc_00 (Proto 0x000F3240, 14 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

class CharacterObject;

template <class T0> class GameSetIteratorFunctionFilter
{
public:
    virtual int vfunc_00(int a1);
    int m_Field04; // +0x04
};

template <> int GameSetIteratorFunctionFilter<CharacterObject>::vfunc_00(int a1)
{
    return ((int (__cdecl*)(int))m_Field04)(a1);
}

