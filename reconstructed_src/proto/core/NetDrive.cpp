// ============================================================================
// SCARFACE: THE WORLD IS YOURS — April 2006 prototype game.xbe, core/NetDrive.cpp (2 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 2 of 16 functions matched (12.50%). NOT COMPLETE YET.
// The 14 still to do are listed in their place in Original_Binary_Order_Proto.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] core::NetDrive::vfunc_05 (0x00281B00, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as core::ControllerXBox::vfunc_05 (0x00247C10), which was matched first;
// its addresses and names were swapped for this function's.
// core::NetDrive::vfunc_05 (0x00281B00, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_003B4918[];

namespace core {

class NetDrive
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual void* vfunc_05();
};

void* NetDrive::vfunc_05()
{
    return DAT_003B4918;
}

}

// ============================================================================
// [VERIFIED] core::NetDrive::vfunc_03 (0x00282720, 36 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as core::ControllerSystemXBox::vfunc_03 (0x00248820), which was matched first;
// its addresses and names were swapped for this function's.
// core::NetDrive::vfunc_03 (0x00282720, 36 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_00429338;
extern "C" void __cdecl sub_00201990(int, int);
extern "C" void __cdecl sub_00281EB0(void);

namespace core {

class NetDrive
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual NetDrive* vfunc_03(int a1);
};

NetDrive* NetDrive::vfunc_03(int a1)
{
    sub_00281EB0();
    if (a1 & 1) {
        sub_00201990(DAT_00429338, (int)this);
    }
    return this;
}

}

