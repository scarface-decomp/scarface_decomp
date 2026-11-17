// ============================================================================
// SCARFACE: THE WORLD IS YOURS — April 2006 prototype game.xbe, engine/Animation360Action.cpp (1 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 1 of 4 functions matched (25.00%). NOT COMPLETE YET.
// The 3 still to do are listed in their place in Original_Binary_Order_Proto.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] Animation360Action::vfunc_07 (0x000CF1C0, 80 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Animation360Action::vfunc_07 (Proto 0x000CF1C0, 80 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field10
{
    void sub_000C6970();
    void sub_000C6A50(int);
};

struct Object
{
    void sub_001489F0(int);
};

extern "C" int DAT_00462DD4;
extern "C" int __cdecl sub_00028120(int);

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
    char m_pad04[0x8];
    int m_Field0C; // +0x0C
    Field10* m_Field10; // +0x10
};

void Animation360Action::vfunc_07()
{
    int t4;

    m_Field10->sub_000C6970();
    m_Field10->sub_000C6A50(0);
    t4 = sub_00028120(m_Field0C);
    if (*(int*)(t4 + 16) == DAT_00462DD4) {
        ((Object*)t4)->sub_001489F0(16);
        return;
    }
    ((Object*)sub_00028120(m_Field0C))->sub_001489F0(21);
}

