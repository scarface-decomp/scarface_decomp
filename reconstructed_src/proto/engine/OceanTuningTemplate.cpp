// ============================================================================
// SCARFACE: THE WORLD IS YOURS — April 2006 prototype game.xbe, engine/OceanTuningTemplate.cpp (2 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: COMPLETE. All 2 functions are matched.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] OceanTuningTemplate::vfunc_00 (0x001C4A70, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as CollisionBehaviourTypeGroup::vfunc_00 (0x000123B0), which was matched first;
// its addresses and names were swapped for this function's.
// OceanTuningTemplate::vfunc_00 (0x001C4A70, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0041AEBC[];

class OceanTuningTemplate
{
public:
    virtual void* vfunc_00();
};

void* OceanTuningTemplate::vfunc_00()
{
    return DAT_0041AEBC;
}

// ============================================================================
// [VERIFIED] OceanTuningTemplate::vfunc_05 (0x001C4A80, 53 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// OceanTuningTemplate::vfunc_05 (Proto 0x001C4A80, 53 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    int sub_0008D4E0(int);
    void sub_001926B0(int, int);
};

extern "C" Object DAT_00462EA4;
extern "C" int DAT_00462EA8;
extern "C" void __stdcall sub_00028C40(int);

class OceanTuningTemplate
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual void vfunc_05(int a1);
};

void OceanTuningTemplate::vfunc_05(int a1)
{
    int t3;

    sub_00028C40(a1);
    if (!((unsigned char)a1)) {
        t3 = DAT_00462EA4.sub_0008D4E0(DAT_00462EA8);
        if (!t3) goto L_30;
        ((Object*)t3)->sub_001926B0((int)this, 0);
    }
L_30:
    ;
}

