// ============================================================================
// SCARFACE: THE WORLD IS YOURS — April 2006 prototype game.xbe, engine/SkidmarkContainer.cpp (2 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: COMPLETE. All 2 functions are matched.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] renderer::SkidmarkContainer::vfunc_23 (0x00050350, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// What it does: Always returns 0x4000000.
// ============================================================================
// bin: proto
// va: 0x00050350
// what: Always returns 0x4000000.
// tool: Claude Fable 5.2 (look-alike of xb 0x0005A920, names and addresses swapped)
// renderer::SkidmarkContainer::vfunc_23 (0x00050350, 6 bytes)
namespace renderer {

class SkidmarkContainer
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
    virtual void vfunc_09();
    virtual void vfunc_10();
    virtual void vfunc_11();
    virtual void vfunc_12();
    virtual void vfunc_13();
    virtual void vfunc_14();
    virtual void vfunc_15();
    virtual void vfunc_16();
    virtual void vfunc_17();
    virtual void vfunc_18();
    virtual void vfunc_19();
    virtual void vfunc_20();
    virtual void vfunc_21();
    virtual void vfunc_22();
    virtual int vfunc_23();
};

int SkidmarkContainer::vfunc_23()
{
    return 0x4000000;
}

}

// ============================================================================
// [VERIFIED] renderer::SkidmarkContainer::vfunc_03 (0x00050690, 36 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as LOSManager::LOSManagerFlowClient::vfunc_00 (0x000179C0), which was matched first;
// its addresses and names were swapped for this function's.
// renderer::SkidmarkContainer::vfunc_03 (0x00050690, 36 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_003802F4[];
extern "C" void __cdecl sub_001FCF60(int);
extern "C" void __cdecl sub_00217250(void);

namespace renderer {

class SkidmarkContainer
{
public:
    virtual SkidmarkContainer* vfunc_03(int a1);
};

SkidmarkContainer* SkidmarkContainer::vfunc_03(int a1)
{
    *(int*)this = (int)DAT_003802F4;
    sub_00217250();
    if (a1 & 1) {
        sub_001FCF60((int)this);
    }
    return this;
}

}

