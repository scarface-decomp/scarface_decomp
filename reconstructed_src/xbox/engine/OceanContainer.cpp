// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail Xbox default.xbe, engine/OceanContainer.cpp (2 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: COMPLETE. All 2 functions are matched.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] renderer::OceanContainer::vfunc_25 (0x00055240, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as pure3d::TargaHandler::vfunc_07 (0x0004A760), which was matched first;
// its addresses and names were swapped for this function's.
// renderer::OceanContainer::vfunc_25 (0x00055240, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_00040000[];

namespace renderer {

class OceanContainer
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual void vfunc_05();
    virtual void vfunc_06();
    virtual void* vfunc_25();
};

void* OceanContainer::vfunc_25()
{
    return DAT_00040000;
}

}

// ============================================================================
// [VERIFIED] renderer::OceanContainer::vfunc_03 (0x00055350, 36 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as LOSManager::LOSManagerFlowClient::vfunc_00 (0x000179C0), which was matched first;
// its addresses and names were swapped for this function's.
// renderer::OceanContainer::vfunc_03 (0x00055350, 36 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_003A0C3C[];
extern "C" void __cdecl sub_0023F7A0(int);
extern "C" void __cdecl sub_0025AFE0(void);

namespace renderer {

class OceanContainer
{
public:
    virtual OceanContainer* vfunc_03(int a1);
};

OceanContainer* OceanContainer::vfunc_03(int a1)
{
    *(int*)this = (int)DAT_003A0C3C;
    sub_0025AFE0();
    if (a1 & 1) {
        sub_0023F7A0((int)this);
    }
    return this;
}

}

