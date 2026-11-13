// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail Xbox default.xbe, core/ControllerXBox.cpp (3 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 3 of 19 functions matched (15.79%). NOT COMPLETE YET.
// The 16 still to do are listed in their place in Original_Binary_Order_Xbox.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] core::ControllerXBox::vfunc_05 (0x00247C10, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// core::ControllerXBox::vfunc_05 (0x00247C10, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_003D4E08[];

namespace core {

class ControllerXBox
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual void* vfunc_05();
};

void* ControllerXBox::vfunc_05()
{
    return DAT_003D4E08;
}

}

// ============================================================================
// [VERIFIED] core::ControllerXBox::vfunc_06 (0x00247C20, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as core::ControllerXBox::vfunc_05 (0x00247C10), which was matched first;
// its addresses and names were swapped for this function's.
// core::ControllerXBox::vfunc_06 (0x00247C20, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_003D4E18[];

namespace core {

class ControllerXBox
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual void* vfunc_06();
};

void* ControllerXBox::vfunc_06()
{
    return DAT_003D4E18;
}

}

// ============================================================================
// [VERIFIED] core::ControllerXBox::vfunc_03 (0x00247FA0, 30 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as CollisionManager::CollisionManagerFlowClient::vfunc_00 (0x00016060), which was matched first;
// its addresses and names were swapped for this function's.
// core::ControllerXBox::vfunc_03 (0x00247FA0, 30 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __cdecl sub_00247990(void);
extern "C" void __cdecl sub_00027600(int);

namespace core {

class ControllerXBox
{
public:
    virtual ControllerXBox* vfunc_03(int a1);
};

ControllerXBox* ControllerXBox::vfunc_03(int a1)
{
    sub_00247990();
    if (a1 & 1) {
        sub_00027600((int)this);
    }
    return this;
}

}

