// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail Xbox default.xbe, engine/Animation360Action.cpp (1 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 1 of 4 functions matched (25.00%). NOT COMPLETE YET.
// The 3 still to do are listed in their place in Original_Binary_Order_Xbox.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] Animation360Action::vfunc_08 (0x000E1050, 81 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Animation360Action::vfunc_08 (0x000E1050, 81 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field10
{
    void sub_000D8530();
    void sub_000D8580(int);
};

struct Object
{
    void sub_00167E80(int);
};

extern "C" int DAT_0048A9D8;
extern "C" int __cdecl sub_0002AC90(int);

class Animation360Action
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
    char m_pad04[0x8];
    int m_Field0C; // +0x0C
    Field10* m_Field10; // +0x10
};

void Animation360Action::vfunc_08()
{
    int t4, t5;

    m_Field10->sub_000D8530();
    m_Field10->sub_000D8580(0);
    t4 = sub_0002AC90(m_Field0C);
    t5 = DAT_0048A9D8;
    if (DAT_0048A9D8) {
        if (t4 != t5) goto L_3A;
        ((Object*)t4)->sub_00167E80(16);
        return;
    }
L_3A:
    ((Object*)sub_0002AC90(m_Field0C))->sub_00167E80(21);
}

