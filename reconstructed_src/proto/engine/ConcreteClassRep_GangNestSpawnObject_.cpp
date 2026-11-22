// ============================================================================
// SCARFACE: THE WORLD IS YOURS — April 2006 prototype game.xbe, engine/ConcreteClassRep_GangNestSpawnObject_.cpp (2 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: COMPLETE. All 2 functions are matched.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] ConcreteClassRep<GangNestSpawnObject>::vfunc_01 (0x001AE1C0, 40 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as ConcreteClassRep<SaveGameObject>::vfunc_01 (Proto 0x000BADA0), which was matched first;
// its addresses and names were swapped for this function's.
// ConcreteClassRep<GangNestSpawnObject>::vfunc_01 (Proto 0x001AE1C0, 40 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    int sub_001A7960(int, int);
};

extern "C" int __cdecl sub_00025140(int, int);

class GangNestSpawnObject;

template <class T0> class ConcreteClassRep
{
public:
    virtual void vfunc_00();
    virtual int vfunc_01();
    char m_pad04[0x18];
    int m_Field1C; // +0x1C
};

template <> int ConcreteClassRep<GangNestSpawnObject>::vfunc_01()
{
    int t2;

    t2 = sub_00025140(88, m_Field1C);
    if (t2) {
        return ((Object*)t2)->sub_001A7960(0, m_Field1C);
    }
    return 0;
}

// ============================================================================
// [VERIFIED] ConcreteClassRep<GangNestSpawnObject>::vfunc_02 (0x001AE1F0, 84 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// What it does: Fills in the script system's description of the GangNestSpawnObject class and lists its fields.
// ============================================================================
// bin: proto
// va: 0x001AE1F0
// what: Fills in the script system's description of the GangNestSpawnObject class and lists its fields.
// tool: Claude Opus 5.5 (transplanted from xb:0x000268A0, nearest by portal/tools/similar.py)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_00417128;
extern "C" int DAT_0041712C;
extern "C" char DAT_00415A08[];
extern "C" char DAT_00415A18[];
extern "C" char DAT_004170D8[];
extern "C" int DAT_004170FC;
extern "C" void __cdecl sub_000660D0(int, int);
extern "C" void __cdecl sub_00069130(int, int, int, int, int, int, int, int, int);

class GangNestSpawnObject;

template <class T0> class ConcreteClassRep
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
};

template <> void ConcreteClassRep<GangNestSpawnObject>::vfunc_02()
{
    sub_000660D0(DAT_004170FC, DAT_00417128);
    DAT_0041712C = (int)DAT_004170D8;
    sub_00069130((int)DAT_00415A18, 2, 0, 0, 72, 0, 0, 0, 0);
    sub_00069130((int)DAT_00415A08, 2, 0, 0, 76, 0, 0, 0, 0);
}

