// ============================================================================
// SCARFACE: THE WORLD IS YOURS — April 2006 prototype game.xbe, engine/LoadSet.cpp (2 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 2 of 3 functions matched (66.67%). NOT COMPLETE YET.
// The 1 still to do are listed in their place in Original_Binary_Order_Proto.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] LoadSet::vfunc_00 (0x00057170, 4 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as LoadSet::vfunc_00 (0x00061900), which was matched first;
// its addresses and names were swapped for this function's.
// LoadSet::vfunc_00 (0x00057170, 4 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

class LoadSet
{
public:
    virtual void vfunc_00();
    char m_pad04[0x10];
    int m_Field14; // +0x14
};

void LoadSet::vfunc_00()
{
    m_Field14 += 1;
}

// ============================================================================
// [VERIFIED] LoadSet::vfunc_01 (0x00057180, 13 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as LoadSet::vfunc_01 (0x00061910), which was matched first;
// its addresses and names were swapped for this function's.
// LoadSet::vfunc_01 (0x00057180, 13 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

class LoadSet
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03(int);
    char m_pad04[0x10];
    int m_Field14; // +0x14
};

void LoadSet::vfunc_01()
{
    m_Field14 -= 1;
    if (!m_Field14) {
        vfunc_03(1);
    }
}

