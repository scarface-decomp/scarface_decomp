// ============================================================================
// SCARFACE: THE WORLD IS YOURS — April 2006 prototype game.xbe, engine/NISSequencePlayAction.cpp (3 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 3 of 6 functions matched (50.00%). NOT COMPLETE YET.
// The 3 still to do are listed in their place in Original_Binary_Order_Proto.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] NISSequencePlayAction::vfunc_04 (0x0015E330, 4 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// NISSequencePlayAction::vfunc_04 (Proto 0x0015E330, 4 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

class NISSequencePlayAction
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual bool vfunc_04();
    char m_pad04[0x10];
    bool m_Field14; // +0x14
};

bool NISSequencePlayAction::vfunc_04()
{
    return m_Field14;
}

// ============================================================================
// [VERIFIED] NISSequencePlayAction::vfunc_07 (0x0015E340, 38 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// NISSequencePlayAction::vfunc_07 (Proto 0x0015E340, 38 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    int sub_00133790();
};

extern "C" int __cdecl sub_00133750(void);

class NISSequencePlayAction
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual void vfunc_05();
    virtual void vfunc_06();
    virtual int vfunc_07();
    char m_pad04[0xC];
    int m_Field10; // +0x10
};

int NISSequencePlayAction::vfunc_07()
{
    int r_eax;

    r_eax = sub_00133750();
    r_eax = ((Object*)r_eax)->sub_00133790();
    *(int*)(r_eax + 508) = 0;
    r_eax = m_Field10;
    if (r_eax) {
        *(int*)(r_eax + 36) -= 1;
        m_Field10 = 0;
    }
    return r_eax;
}

// ============================================================================
// [VERIFIED] NISSequencePlayAction::vfunc_03 (0x0015F860, 70 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// NISSequencePlayAction::vfunc_03 (Proto 0x0015F860, 70 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    virtual void vfunc_00();
    virtual void vfunc_01();
};

extern "C" char DAT_00393F14[];
extern "C" char DAT_00393F1C[];
extern "C" void __cdecl sub_00025160(int);

class NISSequencePlayAction
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual NISSequencePlayAction* vfunc_03(int a1);
    void sub_0001F600();
    char m_pad04[0x4];
    int m_Field08; // +0x08
    int m_Field0C; // +0x0C
    int m_Field10; // +0x10
};

NISSequencePlayAction* NISSequencePlayAction::vfunc_03(int a1)
{
    int t1, t3;

    t1 = m_Field0C;
    *(int*)this = (int)DAT_00393F1C;
    m_Field08 = (int)DAT_00393F14;
    ((Object*)t1)->vfunc_01();
    t3 = m_Field10;
    if (m_Field10) {
        *(int*)(t3 + 36) -= 1;
        m_Field10 = 0;
    }
    sub_0001F600();
    if (a1 & 1) {
        sub_00025160((int)this);
    }
    return this;
}

