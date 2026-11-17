// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail Xbox default.xbe, engine/GameSetFilteredIterator.cpp (1 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: COMPLETE. All 1 functions are matched.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] GameSetFilteredIterator::vfunc_00 (0x0010A020, 34 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as GameSetFilteredIterator::vfunc_00 (Proto 0x000F3250), which was matched first;
// its addresses and names were swapped for this function's.
// GameSetFilteredIterator::vfunc_00 (Proto 0x0010A020, 34 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field04
{
    virtual int vfunc_00();
};

struct Field08
{
    virtual bool vfunc_00(int);
};

class GameSetFilteredIterator
{
public:
    virtual int vfunc_00();
    Field04* m_Field04; // +0x04
    Field08* m_Field08; // +0x08
};

int GameSetFilteredIterator::vfunc_00()
{
    int r_esi;

L_04:
    r_esi = m_Field04->vfunc_00();
    if (r_esi) {
        if (!m_Field08->vfunc_00(r_esi)) goto L_04;
    }
    return r_esi;
}

