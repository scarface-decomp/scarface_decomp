// ============================================================================
// SCARFACE: THE WORLD IS YOURS — April 2006 prototype game.xbe, engine/LocomotionAction.cpp (2 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 2 of 5 functions matched (40.00%). NOT COMPLETE YET.
// The 3 still to do are listed in their place in Original_Binary_Order_Proto.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] LocomotionAction::vfunc_07 (0x000D31E0, 73 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// LocomotionAction::vfunc_07 (Proto 0x000D31E0, 73 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field0C
{
    bool sub_000D7360();
};

struct Field10
{
    void sub_000C6950();
    void sub_000C6A50(int);
    void sub_000C6AB0(int);
};

struct Object
{
    void sub_00241390(int, int);
};

class LocomotionAction
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
    Field0C* m_Field0C; // +0x0C
    Field10* m_Field10; // +0x10
};

void LocomotionAction::vfunc_07()
{
    int t1, t2;

    t1 = *(int*)((int)m_Field10 + 12);
    if (*(int*)((int)m_Field10 + 12)) {
        t2 = *(int*)(t1 + 16);
        if (!*(int*)(t1 + 16)) goto L_1F;
        ((Object*)t2)->sub_00241390(0, 0);
    }
L_1F:
    m_Field10->sub_000C6AB0(0);
    m_Field10->sub_000C6950();
    if (m_Field0C->sub_000D7360()) {
        m_Field10->sub_000C6A50(0);
    }
}

// ============================================================================
// [VERIFIED] LocomotionAction::vfunc_03 (0x000D32E0, 86 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// LocomotionAction::vfunc_03 (Proto 0x000D32E0, 86 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field10
{
    void sub_000C7130(int);
};

struct Object
{
    virtual void vfunc_00();
    virtual void vfunc_01();
};

extern "C" char DAT_00386968[];
extern "C" void __cdecl sub_00025160(int);

class LocomotionAction
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual LocomotionAction* vfunc_03(int a1);
    void sub_0001F600();
    char m_pad04[0x4];
    int m_Field08; // +0x08
    int m_Field0C; // +0x0C
    Field10* m_Field10; // +0x10
};

LocomotionAction* LocomotionAction::vfunc_03(int a1)
{
    int t2, t4;

    *(int*)this = (int)DAT_00386968;
    m_Field10->sub_000C7130(0);
    t2 = m_Field0C;
    if (m_Field0C) {
        ((Object*)t2)->vfunc_01();
        m_Field0C = 0;
    }
    t4 = m_Field08;
    if (m_Field08) {
        ((Object*)t4)->vfunc_01();
        m_Field08 = 0;
    }
    sub_0001F600();
    if (a1 & 1) {
        sub_00025160((int)this);
    }
    return this;
}

