// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail Xbox default.xbe, engine/MiniGamePresentationState.cpp (1 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 1 of 9 functions matched (11.11%). NOT COMPLETE YET.
// The 8 still to do are listed in their place in Original_Binary_Order_Xbox.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] MiniGamePresentationState::vfunc_10 (0x0022DDC0, 47 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as MiniGamePresentationState::vfunc_10 (Proto 0x001ED030), which was matched first;
// its addresses and names were swapped for this function's.
// bin: proto
// va: 0x0022DDC0
// what: 
// tool: the portal's starter code (no AI)

// MiniGamePresentationState::vfunc_10 (Proto 0x0022DDC0, 47 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_003D27EC[];
extern "C" void __cdecl sub_000702E0(int, int, int, int, int);

class MiniGamePresentationState
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual void vfunc_05();
    virtual void vfunc_06();
    virtual void vfunc_07();
    virtual void vfunc_08();
    virtual void vfunc_09();
    virtual void vfunc_10();
    int m_Field04; // +0x04
    int m_Field08; // +0x08
    int m_Field0C; // +0x0C
};

void MiniGamePresentationState::vfunc_10()
{
    if (!m_Field0C) {
        sub_000702E0((int)DAT_003D27EC, 0, 0, 0, -1);
    }
    m_Field08 = 8;
    m_Field04 = 4;
}

