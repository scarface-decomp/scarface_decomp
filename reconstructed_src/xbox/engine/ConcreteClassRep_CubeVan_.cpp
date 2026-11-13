// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail Xbox default.xbe, engine/ConcreteClassRep_CubeVan_.cpp (2 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: COMPLETE. All 2 functions are matched.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] ConcreteClassRep<CubeVan>::vfunc_01 (0x00217030, 45 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as ConcreteClassRep<TraceFireObject>::vfunc_01 (0x001D35C0), which was matched first;
// its addresses and names were swapped for this function's.
// ConcreteClassRep<CubeVan>::vfunc_01 (0x00217030, 45 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    int sub_0021C300(int, int);
};

extern "C" int __cdecl sub_000275B0(int, int);

class CubeVan;

template <class T0> class ConcreteClassRep
{
public:
    virtual void vfunc_00();
    virtual int vfunc_01();
    char m_pad04[0x24];
    char m_Field28; // +0x28
};

template <> int ConcreteClassRep<CubeVan>::vfunc_01()
{
    int t2;

    t2 = sub_000275B0(280, m_Field28);
    if (t2) {
        return ((Object*)t2)->sub_0021C300(0, m_Field28);
    }
    return 0;
}

// ============================================================================
// [VERIFIED] ConcreteClassRep<CubeVan>::vfunc_02 (0x00217060, 39 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// ConcreteClassRep<CubeVan>::vfunc_02 (0x00217060, 39 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0044C288[];
extern "C" int DAT_0044C2A8;
extern "C" int DAT_0044CC54;
extern "C" int DAT_0044CC58;
extern "C" unsigned char DAT_0044CC5C;
extern "C" void __cdecl sub_00070520(int, int);

class CubeVan;

template <class T0> class ConcreteClassRep
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
};

template <> void ConcreteClassRep<CubeVan>::vfunc_02()
{
    sub_00070520(DAT_0044C2A8, DAT_0044CC54);
    DAT_0044CC58 = (int)DAT_0044C288;
    DAT_0044CC5C = 13;
}

