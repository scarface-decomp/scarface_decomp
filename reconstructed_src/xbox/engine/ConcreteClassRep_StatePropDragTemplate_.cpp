// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail Xbox default.xbe, engine/ConcreteClassRep_StatePropDragTemplate_.cpp (2 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: COMPLETE. All 2 functions are matched.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] ConcreteClassRep<StatePropDragTemplate>::vfunc_01 (0x001EE730, 42 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as ConcreteClassRep<PositionObject>::vfunc_01 (0x0002DAB0), which was matched first;
// its addresses and names were swapped for this function's.
// ConcreteClassRep<StatePropDragTemplate>::vfunc_01 (0x001EE730, 42 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    int sub_001F2040(int, int);
};

extern "C" int __cdecl sub_000275B0(int, int);

class StatePropDragTemplate;

template <class T0> class ConcreteClassRep
{
public:
    virtual void vfunc_00();
    virtual int vfunc_01();
    char m_pad04[0x24];
    char m_Field28; // +0x28
};

template <> int ConcreteClassRep<StatePropDragTemplate>::vfunc_01()
{
    int t2;

    t2 = sub_000275B0(44, m_Field28);
    if (t2) {
        return ((Object*)t2)->sub_001F2040(0, m_Field28);
    }
    return 0;
}

// ============================================================================
// [VERIFIED] ConcreteClassRep<StatePropDragTemplate>::vfunc_02 (0x001EE760, 84 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as ConcreteClassRep<StatePropDragTemplate>::vfunc_02 (Proto 0x001B47B0), which was matched first;
// its addresses and names were swapped for this function's.
// bin: proto
// va: 0x001EE760
// what: Fills in the script system's description of the StatePropDragTemplate class and lists its fields.
// tool: Claude Opus 5.5 (transplanted from proto:0x00024510, nearest by portal/tools/similar.py)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_0043E760;
extern "C" int DAT_0043E764;
extern "C" char DAT_0043E618[];
extern "C" char DAT_0043E62C[];
extern "C" char DAT_0043E150[];
extern "C" int DAT_0043E170;
extern "C" void __cdecl sub_00070520(int, int);
extern "C" void __cdecl sub_00073780(int, int, int, int, int, int, int, int, int);

class StatePropDragTemplate;

template <class T0> class ConcreteClassRep
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
};

template <> void ConcreteClassRep<StatePropDragTemplate>::vfunc_02()
{
    sub_00070520(DAT_0043E170, DAT_0043E760);
    DAT_0043E764 = (int)DAT_0043E150;
    sub_00073780((int)DAT_0043E62C, 6, 0, 0, 36, 0, 0, 0, 0);
    sub_00073780((int)DAT_0043E618, 6, 0, 0, 40, 0, 0, 0, 0);
}

