// ============================================================================
// SCARFACE: THE WORLD IS YOURS — April 2006 prototype game.xbe, ai/AIActionRepeatIndefinite.cpp (1 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 1 of 2 functions matched (50.00%). NOT COMPLETE YET.
// The 1 still to do are listed in their place in Original_Binary_Order_Proto.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] AIActionRepeatIndefinite::vfunc_03 (0x00104970, 38 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// bin: proto
// va: 0x00104970
// what: 
// tool: the portal's starter code (no AI)

// AIActionRepeatIndefinite::vfunc_03 (Proto 0x00104970, 38 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field08
{
    void sub_00102F90();
    int sub_00102FB0();
};

class AIActionRepeatIndefinite
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual int vfunc_03();
    char m_pad04[0x4];
    Field08* m_Field08; // +0x08
    bool m_Field0C; // +0x0C
};

int AIActionRepeatIndefinite::vfunc_03()
{
    if (!m_Field0C) {
        if (m_Field08->sub_00102FB0() != 2) goto L_1F;
        m_Field08->sub_00102F90();
    }
L_1F:
    return 1;
}

