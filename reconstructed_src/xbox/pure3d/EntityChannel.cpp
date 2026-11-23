// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail Xbox default.xbe, pure3d/EntityChannel.cpp (2 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 2 of 3 functions matched (66.67%). NOT COMPLETE YET.
// The 1 still to do are listed in their place in Original_Binary_Order_Xbox.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] pure3d::EntityChannel::vfunc_02 (0x00287CD0, 6 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// What it does: pure3d::EntityChannel: Always returns 5525061.
// ============================================================================
// Same machine code as pure3d::EntityChannel::vfunc_02 (Proto 0x00243FD0), which was matched first;
// its addresses and names were swapped for this function's.
// pure3d::EntityChannel::vfunc_02 (Proto 0x00287CD0, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

namespace pure3d {

class EntityChannel
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual int vfunc_02();
};

int EntityChannel::vfunc_02()
{
    return 0x544E45;
}

}

// ============================================================================
// [VERIFIED] pure3d::EntityChannel::vfunc_00 (0x0028A710, 33 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// What it does: pure3d::EntityChannel's deleting destructor: destroys the object, frees its memory when asked (flag bit 0), and returns it.
// ============================================================================
// Same machine code as fight::Branch::vfunc_03 (0x0023B160), which was matched first;
// its addresses and names were swapped for this function's.
extern "C" void __cdecl sub_00027600(void* p);

namespace pure3d {

class EntityChannel
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual EntityChannel* vfunc_00(unsigned int flags);
    void sub_00288E50();
};

#pragma optimize("y", off)
EntityChannel* EntityChannel::vfunc_00(unsigned int flags)
{
    sub_00288E50();
    if (flags & 1)
        sub_00027600(this);
    return this;
}
#pragma optimize("", on)

}

