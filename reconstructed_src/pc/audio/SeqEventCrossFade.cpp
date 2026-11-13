// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail PC Scarface.exe v1.00.2, audio/SeqEventCrossFade.cpp (1 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 1 of 5 functions matched (20.00%). NOT COMPLETE YET.
// The 4 still to do are listed in their place in Original_Binary_Order_PC_1002.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] audio::SeqEventCrossFade::vfunc_04 (0x006FB250, 53 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as audio::SeqEventCrossFade::vfunc_04 (0x002DD640), which was matched first;
// its addresses and names were swapped for this function's.
// audio::SeqEventCrossFade::vfunc_04 (0x006FB250, 53 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field1C
{
    void sub_006EBBD0();
};

struct Field2C
{
    void sub_00700EE0();
};

extern "C" char DAT_007F7E38[];
extern "C" void __cdecl sub_006EE890(int, int);

namespace audio {

class SeqEventCrossFade
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual SeqEventCrossFade* vfunc_04(int a1);
    void sub_006F5730();
    char m_pad04[0x18];
    Field1C m_Field1C; // +0x1C
    char m_pad1D[0xF];
    Field2C m_Field2C; // +0x2C
};

SeqEventCrossFade* SeqEventCrossFade::vfunc_04(int a1)
{
    m_Field2C.sub_00700EE0();
    m_Field1C.sub_006EBBD0();
    sub_006F5730();
    if (a1 & 1) {
        sub_006EE890((int)DAT_007F7E38, (int)this);
    }
    return this;
}

}

