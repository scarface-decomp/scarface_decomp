// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail Xbox default.xbe, engine/ConcreteClassRep_BoatAIBehaviour_.cpp (2 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: COMPLETE. All 2 functions are matched.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] ConcreteClassRep<BoatAIBehaviour>::vfunc_01 (0x00149BD0, 45 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// ConcreteClassRep<BoatAIBehaviour>::vfunc_01 (0x00149BD0, 45 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    int sub_00138D70(int, int);
};

extern "C" int __cdecl sub_000275B0(int, int);

class BoatAIBehaviour;

template <class T0> class ConcreteClassRep
{
public:
    virtual void vfunc_00();
    virtual int vfunc_01();
    char m_pad04[0x24];
    char m_Field28; // +0x28
};

template <> int ConcreteClassRep<BoatAIBehaviour>::vfunc_01()
{
    int t2;

    t2 = sub_000275B0(332, m_Field28);
    if (t2) {
        return ((Object*)t2)->sub_00138D70(0, m_Field28);
    }
    return 0;
}

// ============================================================================
// [VERIFIED] ConcreteClassRep<BoatAIBehaviour>::vfunc_02 (0x00149C00, 32 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as ConcreteClassRep<CollisionBehaviourTypeGroup>::vfunc_02 (0x00011400), which was matched first;
// its addresses and names were swapped for this function's.
// ConcreteClassRep<BoatAIBehaviour>::vfunc_02 (0x00149C00, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_0042DDC4;
extern "C" int DAT_0042DDC8;
extern "C" char DAT_0042E2AC[];
extern "C" int DAT_0042E2CC;
extern "C" void __cdecl sub_00070520(int, int);

class BoatAIBehaviour;

template <class T0> class ConcreteClassRep
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
};

template <> void ConcreteClassRep<BoatAIBehaviour>::vfunc_02()
{
    sub_00070520(DAT_0042E2CC, DAT_0042DDC4);
    DAT_0042DDC8 = (int)DAT_0042E2AC;
}

