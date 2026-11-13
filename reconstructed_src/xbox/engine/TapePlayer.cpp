// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail Xbox default.xbe, engine/TapePlayer.cpp (2 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 2 of 3 functions matched (66.67%). NOT COMPLETE YET.
// The 1 still to do are listed in their place in Original_Binary_Order_Xbox.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] TapePlayer::vfunc_00 (0x001D8150, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as CollisionBehaviourTypeGroup::vfunc_00 (0x000123B0), which was matched first;
// its addresses and names were swapped for this function's.
// TapePlayer::vfunc_00 (0x001D8150, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0043BA00[];

class TapePlayer
{
public:
    virtual void* vfunc_00();
};

void* TapePlayer::vfunc_00()
{
    return DAT_0043BA00;
}

// ============================================================================
// [VERIFIED] TapePlayer::vfunc_01 (0x001D8390, 66 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// TapePlayer::vfunc_01 (0x001D8390, 66 bytes)
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
    virtual void vfunc_30(int);
};

extern "C" char DAT_003C701C[];
extern "C" int DAT_00491FC4;
extern "C" void __cdecl sub_00027600(int);

class TapePlayer
{
public:
    virtual void vfunc_00();
    virtual TapePlayer* vfunc_01(int a1);
    void sub_00029F90();
};

TapePlayer* TapePlayer::vfunc_01(int a1)
{
    *(int*)this = (int)DAT_003C701C;
    ((Object*)*(int*)(DAT_00491FC4 + 48))->vfunc_30((int)this);
    ((Object*)*(int*)(DAT_00491FC4 + 36))->vfunc_30((int)this);
    sub_00029F90();
    if (a1 & 1) {
        sub_00027600((int)this);
    }
    return this;
}

