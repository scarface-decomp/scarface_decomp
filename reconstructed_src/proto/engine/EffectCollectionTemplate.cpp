// ============================================================================
// SCARFACE: THE WORLD IS YOURS — April 2006 prototype game.xbe, engine/EffectCollectionTemplate.cpp (3 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 3 of 4 functions matched (75.00%). NOT COMPLETE YET.
// The 1 still to do are listed in their place in Original_Binary_Order_Proto.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] EffectCollectionTemplate::vfunc_00 (0x001D7080, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as CollisionBehaviourTypeGroup::vfunc_00 (0x000123B0), which was matched first;
// its addresses and names were swapped for this function's.
// EffectCollectionTemplate::vfunc_00 (0x001D7080, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_00425470[];

class EffectCollectionTemplate
{
public:
    virtual void* vfunc_00();
};

void* EffectCollectionTemplate::vfunc_00()
{
    return DAT_00425470;
}

// ============================================================================
// [VERIFIED] EffectCollectionTemplate::vfunc_12 (0x001D7090, 38 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// EffectCollectionTemplate::vfunc_12 (Proto 0x001D7090, 38 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0020F860(int);
    void sub_00210530();
};

extern "C" int __cdecl sub_0020F3B0(void);

class EffectCollectionTemplate
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
    virtual void vfunc_09();
    virtual void vfunc_10();
    virtual void vfunc_11();
    virtual void vfunc_12();
    char m_pad04[0x1E];
    bool m_Field22; // +0x22
};

void EffectCollectionTemplate::vfunc_12()
{
    int t1;

    t1 = sub_0020F3B0();
    if (t1) {
        ((Object*)t1)->sub_00210530();
        ((Object*)t1)->sub_0020F860(0);
    }
    m_Field22 = false;
}

// ============================================================================
// [VERIFIED] EffectCollectionTemplate::vfunc_01 (0x001D71F0, 80 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// EffectCollectionTemplate::vfunc_01 (Proto 0x001D71F0, 80 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0020F860(int);
    void sub_00210530();
};

extern "C" char DAT_0037F29C[];
extern "C" char DAT_003A9004[];
extern "C" void __cdecl sub_00025160(int);
extern "C" int __cdecl sub_0020F3B0(void);

class EffectCollectionTemplate
{
public:
    virtual void vfunc_00();
    virtual EffectCollectionTemplate* vfunc_01(int a1);
    void sub_00029C00();
    char m_pad04[0x1E];
    bool m_Field22; // +0x22
};

EffectCollectionTemplate* EffectCollectionTemplate::vfunc_01(int a1)
{
    int t2;

    *(int*)this = (int)DAT_003A9004;
    if (m_Field22) {
        t2 = sub_0020F3B0();
        if (t2) {
            ((Object*)t2)->sub_00210530();
            ((Object*)t2)->sub_0020F860(0);
        }
    }
    *(int*)this = (int)DAT_0037F29C;
    sub_00029C00();
    if (a1 & 1) {
        sub_00025160((int)this);
    }
    return this;
}

