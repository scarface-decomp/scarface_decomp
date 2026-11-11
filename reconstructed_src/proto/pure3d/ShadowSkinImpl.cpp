// ============================================================================
// SCARFACE: THE WORLD IS YOURS — April 2006 prototype game.xbe, pure3d/ShadowSkinImpl.cpp (1 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 1 of 3 functions matched (33.33%). NOT COMPLETE YET.
// The 2 still to do are listed in their place in Original_Binary_Order_Proto.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] pure3d::ShadowSkinImpl::vfunc_03 (0x002153A0, 30 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as CollisionManager::CollisionManagerFlowClient::vfunc_00 (0x00016060), which was matched first;
// its addresses and names were swapped for this function's.
// pure3d::ShadowSkinImpl::vfunc_03 (0x002153A0, 30 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __cdecl sub_00214550(void);
extern "C" void __cdecl sub_001FCF60(int);

namespace pure3d {

class ShadowSkinImpl
{
public:
    virtual ShadowSkinImpl* vfunc_03(int a1);
};

ShadowSkinImpl* ShadowSkinImpl::vfunc_03(int a1)
{
    sub_00214550();
    if (a1 & 1) {
        sub_001FCF60((int)this);
    }
    return this;
}

}

