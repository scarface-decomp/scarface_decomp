// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail Xbox default.xbe, engine/Cmd_PlayAnimation.cpp (4 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 4 of 5 functions matched (80.00%). NOT COMPLETE YET.
// The 1 still to do are listed in their place in Original_Binary_Order_Xbox.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] AICommands::Cmd_PlayAnimation::vfunc_01 (0x0012EAE0, 11 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as AICommands::Cmd_PlayAnimation::vfunc_01 (Proto 0x00112BE0), which was matched first;
// its addresses and names were swapped for this function's.
// bin: proto
// va: 0x0012EAE0
// what: 
// tool: the portal's starter code (no AI)

// AICommands::Cmd_PlayAnimation::vfunc_01 (Proto 0x0012EAE0, 11 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

namespace AICommands {

class Cmd_PlayAnimation
{
public:
    virtual void vfunc_00();
    virtual unsigned short vfunc_01(int a1, int a2);
    char m_pad04[0x10];
    unsigned short m_Field14; // +0x14
    unsigned short m_Field16; // +0x16
};

unsigned short Cmd_PlayAnimation::vfunc_01(int a1, int a2)
{
    unsigned short t1;

    t1 = m_Field14;
    m_Field16 = m_Field14;
    return t1;
}

}

// ============================================================================
// [VERIFIED] AICommands::Cmd_PlayAnimation::vfunc_04 (0x0012EAF0, 12 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as AICommands::Cmd_PlayAnimation::vfunc_04 (Proto 0x00112BF0), which was matched first;
// its addresses and names were swapped for this function's.
// bin: proto
// va: 0x0012EAF0
// what: 
// tool: the portal's starter code (no AI)

// AICommands::Cmd_PlayAnimation::vfunc_04 (Proto 0x0012EAF0, 12 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

namespace AICommands {

class Cmd_PlayAnimation
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual int vfunc_04(int a1, int a2);
    char m_pad04[0x12];
    unsigned short m_Field16; // +0x16
};

int Cmd_PlayAnimation::vfunc_04(int a1, int a2)
{
    return !m_Field16;
}

}

// ============================================================================
// [VERIFIED] AICommands::Cmd_PlayAnimation::vfunc_06 (0x0012EB00, 54 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as AICommands::Cmd_PlayAnimation::vfunc_06 (Proto 0x00112C00), which was matched first;
// its addresses and names were swapped for this function's.
// AICommands::Cmd_PlayAnimation::vfunc_06 (Proto 0x0012EB00, 54 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    int sub_00168B80(int, int, int);
    void sub_002A9290();
    void sub_00242D00(int);
};

namespace AICommands {

class Cmd_PlayAnimation
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual void vfunc_05();
    virtual void vfunc_06(int a1, int a2, int a3);
    char m_pad04[0x4];
    int m_Field08; // +0x08
    int m_Field0C; // +0x0C
    int m_Field10; // +0x10
};

void Cmd_PlayAnimation::vfunc_06(int a1, int a2, int a3)
{
    int local_4;

    ((Object*)(int)(&local_4))->sub_00242D00(m_Field08);
    m_Field10 = ((Object*)a2)->sub_00168B80((int)(&local_4), m_Field0C, 0);
    ((Object*)(int)(&local_4))->sub_002A9290();
}

}

// ============================================================================
// [VERIFIED] AICommands::Cmd_PlayAnimation::vfunc_08 (0x0012EBB0, 41 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// AICommands::Cmd_PlayAnimation::vfunc_08 (0x0012EBB0, 41 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    int sub_00163D50();
    int sub_00166020(int);
};

namespace AICommands {

class Cmd_PlayAnimation
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
    virtual int vfunc_08(int a1, int a2, int a3);
    char m_pad04[0x8];
    int m_Field0C; // +0x0C
    int m_Field10; // +0x10
};

int Cmd_PlayAnimation::vfunc_08(int a1, int a2, int a3)
{
    int r_eax;

    r_eax = m_Field10;
    if (r_eax) {
        r_eax = ((Object*)a2)->sub_00163D50();
        if (r_eax == m_Field0C) {
            r_eax = ((Object*)a2)->sub_00166020(0);
        }
    }
    return r_eax;
}

}

