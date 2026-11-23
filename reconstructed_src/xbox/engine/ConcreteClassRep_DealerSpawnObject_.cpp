// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail Xbox default.xbe, engine/ConcreteClassRep_DealerSpawnObject_.cpp (2 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: COMPLETE. All 2 functions are matched.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] ConcreteClassRep<DealerSpawnObject>::vfunc_01 (0x001E7930, 45 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// What it does: Creates a new DealerSpawnObject for the class system: allocates 488 bytes and runs its constructor; null if the allocation fails.
// ============================================================================
// ConcreteClassRep<DealerSpawnObject>::vfunc_01 (0x001E7930, 45 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    int sub_001DE9E0(int, int);
};

extern "C" int __cdecl sub_000275B0(int, int);

class DealerSpawnObject;

template <class T0> class ConcreteClassRep
{
public:
    virtual void vfunc_00();
    virtual int vfunc_01();
    char m_pad04[0x24];
    char m_Field28; // +0x28
};

template <> int ConcreteClassRep<DealerSpawnObject>::vfunc_01()
{
    int t2;

    t2 = sub_000275B0(488, m_Field28);
    if (t2) {
        return ((Object*)t2)->sub_001DE9E0(0, m_Field28);
    }
    return 0;
}

// ============================================================================
// [VERIFIED] ConcreteClassRep<DealerSpawnObject>::vfunc_02 (0x001E81E0, 66 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as ConcreteClassRep<AITask_Engage>::vfunc_02 (Proto 0x001018C0), which was matched first;
// its addresses and names were swapped for this function's.
// bin: proto
// va: 0x001E81E0
// what: Fills in the script system's description of the DealerSpawnObject class and lists its fields.
// tool: Claude Opus 5.5 (transplanted from proto:0x001AF2B0, nearest by portal/tools/similar.py)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0039D520[];
extern "C" int DAT_0043DB9C;
extern "C" int DAT_0043DBA0;
extern "C" char DAT_0043D840[];
extern "C" char DAT_0043D854[];
extern "C" char DAT_0043D864[];
extern "C" int DAT_0043D884;
extern "C" char sub_001DEC10[];
extern "C" void __cdecl sub_00070520(int, int);
extern "C" void __cdecl sub_001368B0(int, int, int, int, int, int, int);

class DealerSpawnObject;

template <class T0> class ConcreteClassRep
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
};

template <> void ConcreteClassRep<DealerSpawnObject>::vfunc_02()
{
    sub_00070520(DAT_0043D884, DAT_0043DB9C);
    DAT_0043DBA0 = (int)DAT_0043D864;
    sub_001368B0((int)DAT_0043D840, (int)DAT_0043D854, (int)DAT_0039D520, (int)sub_001DEC10, 3, 3, (int)DAT_0039D520);
}

