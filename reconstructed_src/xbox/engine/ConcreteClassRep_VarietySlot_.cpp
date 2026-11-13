// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail Xbox default.xbe, engine/ConcreteClassRep_VarietySlot_.cpp (2 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: COMPLETE. All 2 functions are matched.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] ConcreteClassRep<VarietySlot>::vfunc_01 (0x00096720, 55 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as ConcreteClassRep<VarietyFile>::vfunc_01 (0x00095690), which was matched first;
// its addresses and names were swapped for this function's.
// ConcreteClassRep<VarietySlot>::vfunc_01 (0x00096720, 55 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0002AA50(int, int);
};

extern "C" char DAT_003A46DC[];
extern "C" int __cdecl sub_000275B0(int, int);

class VarietySlot;

template <class T0> class ConcreteClassRep
{
public:
    virtual void vfunc_00();
    virtual int vfunc_01();
    char m_pad04[0x24];
    char m_Field28; // +0x28
};

template <> int ConcreteClassRep<VarietySlot>::vfunc_01()
{
    int t2;

    t2 = sub_000275B0(32, m_Field28);
    if (t2) {
        ((Object*)t2)->sub_0002AA50(0, m_Field28);
        *(int*)t2 = (int)DAT_003A46DC;
        return t2;
    }
    return 0;
}

// ============================================================================
// [VERIFIED] ConcreteClassRep<VarietySlot>::vfunc_02 (0x00096760, 32 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as ConcreteClassRep<CollisionBehaviourTypeGroup>::vfunc_02 (0x00011400), which was matched first;
// its addresses and names were swapped for this function's.
// ConcreteClassRep<VarietySlot>::vfunc_02 (0x00096760, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_00423648;
extern "C" int DAT_0042364C;
extern "C" char DAT_0041BC5C[];
extern "C" int DAT_0041BC7C;
extern "C" void __cdecl sub_00070520(int, int);

class VarietySlot;

template <class T0> class ConcreteClassRep
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
};

template <> void ConcreteClassRep<VarietySlot>::vfunc_02()
{
    sub_00070520(DAT_0041BC7C, DAT_00423648);
    DAT_0042364C = (int)DAT_0041BC5C;
}

