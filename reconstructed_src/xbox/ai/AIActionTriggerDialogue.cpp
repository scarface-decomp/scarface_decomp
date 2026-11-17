// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail Xbox default.xbe, ai/AIActionTriggerDialogue.cpp (1 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 1 of 2 functions matched (50.00%). NOT COMPLETE YET.
// The 1 still to do are listed in their place in Original_Binary_Order_Xbox.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] AIActionTriggerDialogue::vfunc_02 (0x00120AE0, 87 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// AIActionTriggerDialogue::vfunc_02 (0x00120AE0, 87 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field34
{
    void sub_00163B00(int);
    void sub_0016DF20(int, int);
    void sub_0016DF70();
};

struct Field38
{
    void sub_00120530(int);
};

struct Object
{
    void sub_001204E0();
};

extern "C" void __cdecl sub_0011E510(int);

class AIActionTriggerDialogue
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    char m_pad04[0x4];
    int m_Field08; // +0x08
    char m_pad0C[0x28];
    Field34* m_Field34; // +0x34
    Field38 m_Field38; // +0x38
    char m_pad39[0x1];
    bool m_Field3A; // +0x3A
};

void AIActionTriggerDialogue::vfunc_02()
{
    int local_4;

    m_Field34->sub_00163B00((int)(&m_Field08));
    sub_0011E510((int)(&local_4));
    m_Field34->sub_0016DF20((int)(&local_4), 2000);
    m_Field38.sub_00120530((int)(&local_4));
    if (m_Field3A) {
        m_Field34->sub_0016DF70();
    }
    ((Object*)(int)(&local_4))->sub_001204E0();
}

