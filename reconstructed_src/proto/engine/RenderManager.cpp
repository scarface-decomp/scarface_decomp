// ============================================================================
// SCARFACE: THE WORLD IS YOURS — April 2006 prototype game.xbe, engine/RenderManager.cpp (1 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: COMPLETE. All 1 functions are matched.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] renderer::RenderManager::vfunc_00 (0x00045920, 52 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as renderer::RenderManager::vfunc_00 (0x0004CFA0), which was matched first;
// its addresses and names were swapped for this function's.
// renderer::RenderManager::vfunc_00 (0x00045920, 52 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0037F8F0[];
extern "C" void __cdecl sub_00025160(int);
extern "C" void __cdecl sub_00044E40(void);

namespace renderer {

class RenderManager
{
public:
    virtual RenderManager* vfunc_00(int a1);
    int m_Field04; // +0x04
};

RenderManager* RenderManager::vfunc_00(int a1)
{
    int t2;

    *(int*)this = (int)DAT_0037F8F0;
    sub_00044E40();
    t2 = m_Field04;
    if (m_Field04) {
        sub_00025160(t2);
    }
    if (a1 & 1) {
        sub_00025160((int)this);
    }
    return this;
}

}

