// ============================================================================
// SCARFACE: THE WORLD IS YOURS — April 2006 prototype game.xbe, engine/LoadPackage.cpp (3 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 3 of 6 functions matched (50.00%). NOT COMPLETE YET.
// The 3 still to do are listed in their place in Original_Binary_Order_Proto.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] LoadPackage::vfunc_00 (0x001908B0, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as CollisionBehaviourTypeGroup::vfunc_00 (0x000123B0), which was matched first;
// its addresses and names were swapped for this function's.
// LoadPackage::vfunc_00 (0x001908B0, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0041233C[];

class LoadPackage
{
public:
    virtual void* vfunc_00();
};

void* LoadPackage::vfunc_00()
{
    return DAT_0041233C;
}

// ============================================================================
// [VERIFIED] LoadPackage::vfunc_07 (0x00190ED0, 16 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as LoadPackage::vfunc_06 (0x001C63F0), which was matched first;
// its addresses and names were swapped for this function's.
// LoadPackage::vfunc_07 (0x00190ED0, 16 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __cdecl sub_00029BC0(void);

class LoadPackage
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual void vfunc_05();
    virtual void vfunc_07();
    void sub_00190D10();
};

void LoadPackage::vfunc_07()
{
    sub_00029BC0();
    sub_00190D10();
}

// ============================================================================
// [VERIFIED] LoadPackage::vfunc_01 (0x00190F70, 30 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as Collidable::vfunc_03 (0x00011F20), which was matched first;
// its addresses and names were swapped for this function's.
// LoadPackage::vfunc_01 (0x00190F70, 30 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __cdecl sub_00190EE0(void);
extern "C" void __cdecl sub_00025160(int);

class LoadPackage
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual LoadPackage* vfunc_01(int a1);
};

LoadPackage* LoadPackage::vfunc_01(int a1)
{
    sub_00190EE0();
    if (a1 & 1) {
        sub_00025160((int)this);
    }
    return this;
}

