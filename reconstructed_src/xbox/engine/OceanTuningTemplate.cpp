// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail Xbox default.xbe, engine/OceanTuningTemplate.cpp (2 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: COMPLETE. All 2 functions are matched.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] OceanTuningTemplate::vfunc_00 (0x00200050, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as CollisionBehaviourTypeGroup::vfunc_00 (0x000123B0), which was matched first;
// its addresses and names were swapped for this function's.
// OceanTuningTemplate::vfunc_00 (0x00200050, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_004415F8[];

class OceanTuningTemplate
{
public:
    virtual void* vfunc_00();
};

void* OceanTuningTemplate::vfunc_00()
{
    return DAT_004415F8;
}

// ============================================================================
// [VERIFIED] OceanTuningTemplate::vfunc_04 (0x00200060, 53 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as OceanTuningTemplate::vfunc_05 (Proto 0x001C4A80), which was matched first;
// its addresses and names were swapped for this function's.
// OceanTuningTemplate::vfunc_04 (Proto 0x00200060, 53 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    int sub_00098BB0(int);
    void sub_001C8ED0(int, int);
};

extern "C" Object DAT_00491EC8;
extern "C" int DAT_00491ECC;
extern "C" void __stdcall sub_0002B700(int);

class OceanTuningTemplate
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04(int a1);
};

void OceanTuningTemplate::vfunc_04(int a1)
{
    int t3;

    sub_0002B700(a1);
    if (!((unsigned char)a1)) {
        t3 = DAT_00491EC8.sub_00098BB0(DAT_00491ECC);
        if (!t3) goto L_30;
        ((Object*)t3)->sub_001C8ED0((int)this, 0);
    }
L_30:
    ;
}

