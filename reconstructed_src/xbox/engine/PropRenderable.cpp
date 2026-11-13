// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail Xbox default.xbe, engine/PropRenderable.cpp (2 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: COMPLETE. All 2 functions are matched.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] renderer::PropRenderable::vfunc_09 (0x00055D10, 31 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// renderer::PropRenderable::vfunc_09 (0x00055D10, 31 bytes)
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
    virtual void vfunc_08(int, int);
};

extern "C" int __stdcall sub_00058900(int);

namespace renderer {

class PropRenderable
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual void vfunc_05();
    virtual void vfunc_06();
    virtual void vfunc_07();
    virtual void vfunc_08();
    virtual void vfunc_09(int a1);
};

void PropRenderable::vfunc_09(int a1)
{
    int t1;

    t1 = sub_00058900(0);
    if (t1) {
        ((Object*)t1)->vfunc_08(*(int*)(a1 + 8), 0);
    }
}

}

// ============================================================================
// [VERIFIED] renderer::PropRenderable::vfunc_03 (0x00055DE0, 36 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as LOSManager::LOSManagerFlowClient::vfunc_00 (0x000179C0), which was matched first;
// its addresses and names were swapped for this function's.
// renderer::PropRenderable::vfunc_03 (0x00055DE0, 36 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_003A0DDC[];
extern "C" void __cdecl sub_0023F7A0(int);
extern "C" void __cdecl sub_00059290(void);

namespace renderer {

class PropRenderable
{
public:
    virtual PropRenderable* vfunc_03(int a1);
};

PropRenderable* PropRenderable::vfunc_03(int a1)
{
    *(int*)this = (int)DAT_003A0DDC;
    sub_00059290();
    if (a1 & 1) {
        sub_0023F7A0((int)this);
    }
    return this;
}

}

