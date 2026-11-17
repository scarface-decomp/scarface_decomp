// ============================================================================
// SCARFACE: THE WORLD IS YOURS — April 2006 prototype game.xbe, engine/DismemberAction.cpp (2 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 2 of 4 functions matched (50.00%). NOT COMPLETE YET.
// The 2 still to do are listed in their place in Original_Binary_Order_Proto.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] DismemberAction::vfunc_07 (0x000D2770, 34 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// DismemberAction::vfunc_07 (Proto 0x000D2770, 34 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
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
    virtual void vfunc_11();
    virtual void vfunc_12();
    virtual void vfunc_13();
    virtual void vfunc_14();
    virtual void vfunc_15();
    virtual void vfunc_16();
    virtual void vfunc_17();
    virtual void vfunc_18();
    virtual void vfunc_19();
    virtual void vfunc_20();
    virtual void vfunc_21();
    virtual void vfunc_22();
    virtual void vfunc_23();
    virtual void vfunc_24();
    virtual void vfunc_25();
    virtual void vfunc_26();
    virtual void vfunc_27();
    virtual void vfunc_28();
    virtual void vfunc_29();
    virtual void vfunc_30();
    virtual void vfunc_31();
    virtual void vfunc_32();
    virtual void vfunc_33();
    virtual void vfunc_34();
    virtual int vfunc_35();
};

extern "C" int __cdecl sub_00028120(int);
extern "C" void __cdecl sub_00041B50(int);

class DismemberAction
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
    char m_pad04[0x10];
    int m_Field14; // +0x14
};

void DismemberAction::vfunc_07()
{
    int t3;

    t3 = ((Object*)sub_00028120(m_Field14))->vfunc_35();
    if (t3) {
        sub_00041B50(t3);
    }
}

// ============================================================================
// [VERIFIED] DismemberAction::vfunc_03 (0x000D29E0, 57 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as BlendAction::vfunc_03 (0x000E3ED0), which was matched first;
// its addresses and names were swapped for this function's.
struct Child
{
    virtual void vfunc_00();
    virtual void vfunc_01();
};

extern "C" char DAT_0038684C[];
extern "C" void __cdecl sub_00025160(void* p);

class DismemberAction
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual DismemberAction* vfunc_03(unsigned int flags);
    void sub_0001F600();

    void* m_vtable_unused;
    Child* m_child; // +0x08
};

// Deleting destructor: releases the child it owns, runs the base destructor, frees itself when asked.
// The volatile accesses keep the vtable store ahead of the read, as the compiler does in a real destructor.
DismemberAction* DismemberAction::vfunc_03(unsigned int flags)
{
    *(void* volatile*)this = DAT_0038684C;
    Child* child = *(Child* volatile*)&m_child;
    if (child) {
        child->vfunc_01();
        m_child = 0;
    }
    sub_0001F600();
    if (flags & 1)
        sub_00025160(this);
    return this;
}

