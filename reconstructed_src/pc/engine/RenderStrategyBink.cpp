// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail PC Scarface.exe v1.00.2, engine/RenderStrategyBink.cpp (2 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 2 of 7 functions matched (28.57%). NOT COMPLETE YET.
// The 5 still to do are listed in their place in Original_Binary_Order_PC_1002.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] movie::RenderStrategyBink::vfunc_04 (0x007016E0, 8 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as movie::RenderStrategyBink::vfunc_04 (0x002E3070), which was matched first;
// its addresses and names were swapped for this function's.
// movie::RenderStrategyBink::vfunc_04 (0x007016E0, 8 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

namespace movie {

class RenderStrategyBink
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    char m_pad04[0x2C];
    int m_Field30; // +0x30
};

void RenderStrategyBink::vfunc_04()
{
    m_Field30 = 0;
}

}

// ============================================================================
// [VERIFIED] movie::RenderStrategyBink::vfunc_03 (0x00701B90, 36 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as core::ControllerSystemXBox::vfunc_03 (0x00248820), which was matched first;
// its addresses and names were swapped for this function's.
// movie::RenderStrategyBink::vfunc_03 (0x00701B90, 36 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_007F5A70;
extern "C" void __cdecl sub_006DC430(int, int);
extern "C" void __cdecl sub_00701660(void);

namespace movie {

class RenderStrategyBink
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual RenderStrategyBink* vfunc_03(int a1);
};

RenderStrategyBink* RenderStrategyBink::vfunc_03(int a1)
{
    sub_00701660();
    if (a1 & 1) {
        sub_006DC430(DAT_007F5A70, (int)this);
    }
    return this;
}

}

