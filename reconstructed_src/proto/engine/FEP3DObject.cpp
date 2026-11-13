// ============================================================================
// SCARFACE: THE WORLD IS YOURS — April 2006 prototype game.xbe, engine/FEP3DObject.cpp (2 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 2 of 5 functions matched (40.00%). NOT COMPLETE YET.
// The 3 still to do are listed in their place in Original_Binary_Order_Proto.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] FEP3DObject::vfunc_05 (0x00020F40, 30 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as FEP3DObject::vfunc_04 (0x00023080), which was matched first;
// its addresses and names were swapped for this function's.
class FEP3DObject
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_05(unsigned char mode);
    void sub_00028C40(int a1);
};

// Calls the same method with 0 once, and a second time unless the mode is 1.
void FEP3DObject::vfunc_05(unsigned char mode)
{
    sub_00028C40(0);
    if (mode != 1)
        sub_00028C40(0);
}

// ============================================================================
// [VERIFIED] FEP3DObject::vfunc_00 (0x00021020, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as CollisionBehaviourTypeGroup::vfunc_00 (0x000123B0), which was matched first;
// its addresses and names were swapped for this function's.
// FEP3DObject::vfunc_00 (0x00021020, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_003F5D3C[];

class FEP3DObject
{
public:
    virtual void* vfunc_00();
};

void* FEP3DObject::vfunc_00()
{
    return DAT_003F5D3C;
}

