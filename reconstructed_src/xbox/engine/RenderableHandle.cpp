// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail Xbox default.xbe, engine/RenderableHandle.cpp (1 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: COMPLETE. All 1 functions are matched.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] renderer::RenderableHandle::vfunc_00 (0x00047DD0, 30 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as CollisionManager::CollisionManagerFlowClient::vfunc_00 (0x00016060), which was matched first;
// its addresses and names were swapped for this function's.
// renderer::RenderableHandle::vfunc_00 (0x00047DD0, 30 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __cdecl sub_00047D70(void);
extern "C" void __cdecl sub_00027600(int);

namespace renderer {

class RenderableHandle
{
public:
    virtual RenderableHandle* vfunc_00(int a1);
};

RenderableHandle* RenderableHandle::vfunc_00(int a1)
{
    sub_00047D70();
    if (a1 & 1) {
        sub_00027600((int)this);
    }
    return this;
}

}

