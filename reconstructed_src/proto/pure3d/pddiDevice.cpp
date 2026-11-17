// ============================================================================
// SCARFACE: THE WORLD IS YOURS — April 2006 prototype game.xbe, pure3d/pddiDevice.cpp (2 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: COMPLETE. All 2 functions are matched.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] pure3d::pddiDevice::vfunc_03 (0x0024EBE0, 36 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as LOSManager::LOSManagerFlowClient::vfunc_00 (0x000179C0), which was matched first;
// its addresses and names were swapped for this function's.
// pure3d::pddiDevice::vfunc_03 (0x0024EBE0, 36 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_003B1D88[];
extern "C" void __cdecl sub_00025160(int);
extern "C" void __cdecl sub_00264490(void);

namespace pure3d {

class pddiDevice
{
public:
    virtual pddiDevice* vfunc_03(int a1);
};

pddiDevice* pddiDevice::vfunc_03(int a1)
{
    *(int*)this = (int)DAT_003B1D88;
    sub_00264490();
    if (a1 & 1) {
        sub_00025160((int)this);
    }
    return this;
}

}

// ============================================================================
// [VERIFIED] pure3d::pddiDevice::vfunc_13 (0x00262540, 12 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as pure3d::d3dExtTODFactor::vfunc_04 (Proto 0x00232B20), which was matched first;
// its addresses and names were swapped for this function's.
// pure3d::pddiDevice::vfunc_13 (Proto 0x00262540, 12 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_0048E898;

namespace pure3d {

class pddiDevice
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
    virtual int vfunc_13(int a1);
};

int pddiDevice::vfunc_13(int a1)
{
    DAT_0048E898 = a1;
    return a1;
}

}

