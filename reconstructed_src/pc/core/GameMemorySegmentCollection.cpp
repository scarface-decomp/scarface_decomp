// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail PC Scarface.exe v1.00.2, core/GameMemorySegmentCollection.cpp (2 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 2 of 3 functions matched (66.67%). NOT COMPLETE YET.
// The 1 still to do are listed in their place in Original_Binary_Order_PC_1002.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] GameMemorySegmentCollection::vfunc_02 (0x006E9820, 4 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// GameMemorySegmentCollection::vfunc_02 (PC 0x006E9820, 4 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

class GameMemorySegmentCollection
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual int vfunc_02();
    char m_pad04[0x8];
    int m_Field0C; // +0x0C
};

int GameMemorySegmentCollection::vfunc_02()
{
    return m_Field0C;
}

// ============================================================================
// [VERIFIED] GameMemorySegmentCollection::vfunc_01 (0x007016D0, 8 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as GameMemorySegmentCollection::vfunc_01 (0x00026D90), which was matched first;
// its addresses and names were swapped for this function's.
// GameMemorySegmentCollection::vfunc_01 (0x007016D0, 8 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0043C590();
};

class GameMemorySegmentCollection
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
};

void GameMemorySegmentCollection::vfunc_01()
{
    ((Object*)(int)this + 4)->sub_0043C590();
}

