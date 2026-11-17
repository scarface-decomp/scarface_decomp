// ============================================================================
// SCARFACE: THE WORLD IS YOURS — April 2006 prototype game.xbe, engine/Cmd_PlayAnimation.cpp (2 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 2 of 5 functions matched (40.00%). NOT COMPLETE YET.
// The 3 still to do are listed in their place in Original_Binary_Order_Proto.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] AICommands::Cmd_PlayAnimation::vfunc_06 (0x00112C00, 54 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// AICommands::Cmd_PlayAnimation::vfunc_06 (Proto 0x00112C00, 54 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    int sub_0014C030(int, int, int);
    void sub_001B7A10();
    void sub_002AEB30(int);
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

    ((Object*)(int)(&local_4))->sub_002AEB30(m_Field08);
    m_Field10 = ((Object*)a2)->sub_0014C030((int)(&local_4), m_Field0C, 0);
    ((Object*)(int)(&local_4))->sub_001B7A10();
}

}

// ============================================================================
// [VERIFIED] AICommands::Cmd_PlayAnimation::vfunc_08 (0x00112CB0, 41 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// AICommands::Cmd_PlayAnimation::vfunc_08 (Proto 0x00112CB0, 41 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    int sub_00147B20();
    int sub_00149570(int);
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
    char m_pad04[0xC];
    int m_Field10; // +0x10
};

int Cmd_PlayAnimation::vfunc_08(int a1, int a2, int a3)
{
    int r_eax;

    r_eax = m_Field10;
    if (r_eax) {
        r_eax = ((Object*)a2)->sub_00147B20();
        if (r_eax == m_Field10) {
            r_eax = ((Object*)a2)->sub_00149570(0);
        }
    }
    return r_eax;
}

}

