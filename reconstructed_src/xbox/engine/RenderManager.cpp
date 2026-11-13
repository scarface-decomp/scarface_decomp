// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail Xbox default.xbe, engine/RenderManager.cpp (1 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: COMPLETE. All 1 functions are matched.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] renderer::RenderManager::vfunc_00 (0x0004CFA0, 52 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// renderer::RenderManager::vfunc_00 (0x0004CFA0, 52 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_003A05D8[];
extern "C" void __cdecl sub_00027600(int);
extern "C" void __cdecl sub_0004C410(void);

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

    *(int*)this = (int)DAT_003A05D8;
    sub_0004C410();
    t2 = m_Field04;
    if (m_Field04) {
        sub_00027600(t2);
    }
    if (a1 & 1) {
        sub_00027600((int)this);
    }
    return this;
}

}

