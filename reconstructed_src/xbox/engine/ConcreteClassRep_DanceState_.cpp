// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail Xbox default.xbe, engine/ConcreteClassRep_DanceState_.cpp (2 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: COMPLETE. All 2 functions are matched.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] ConcreteClassRep<DanceState>::vfunc_01 (0x00177EB0, 42 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as ConcreteClassRep<CarAITask>::vfunc_01 (0x00149E40), which was matched first;
// its addresses and names were swapped for this function's.
// ConcreteClassRep<DanceState>::vfunc_01 (0x00177EB0, 42 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    int sub_0015FAD0(int, int);
};

extern "C" int __cdecl sub_000275B0(int, int);

class DanceState;

template <class T0> class ConcreteClassRep
{
public:
    virtual void vfunc_00();
    virtual int vfunc_01();
    char m_pad04[0x24];
    char m_Field28; // +0x28
};

template <> int ConcreteClassRep<DanceState>::vfunc_01()
{
    int t2;

    t2 = sub_000275B0(52, m_Field28);
    if (t2) {
        return ((Object*)t2)->sub_0015FAD0(0, m_Field28);
    }
    return 0;
}

// ============================================================================
// [VERIFIED] ConcreteClassRep<DanceState>::vfunc_02 (0x00177EE0, 32 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as ConcreteClassRep<CollisionBehaviourTypeGroup>::vfunc_02 (0x00011400), which was matched first;
// its addresses and names were swapped for this function's.
// ConcreteClassRep<DanceState>::vfunc_02 (0x00177EE0, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_0042F94C;
extern "C" int DAT_0042F950;
extern "C" char DAT_0041B86C[];
extern "C" int DAT_0041B88C;
extern "C" void __cdecl sub_00070520(int, int);

class DanceState;

template <class T0> class ConcreteClassRep
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
};

template <> void ConcreteClassRep<DanceState>::vfunc_02()
{
    sub_00070520(DAT_0041B88C, DAT_0042F94C);
    DAT_0042F950 = (int)DAT_0041B86C;
}

