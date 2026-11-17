// ============================================================================
// SCARFACE: THE WORLD IS YOURS — April 2006 prototype game.xbe, engine/ConcreteClassRep_TriggeredSpawnObject_.cpp (2 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: COMPLETE. All 2 functions are matched.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] ConcreteClassRep<TriggeredSpawnObject>::vfunc_01 (0x001AE540, 43 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// ConcreteClassRep<TriggeredSpawnObject>::vfunc_01 (Proto 0x001AE540, 43 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    int sub_001B12A0(int, int);
};

extern "C" int __cdecl sub_00025140(int, int);

class TriggeredSpawnObject;

template <class T0> class ConcreteClassRep
{
public:
    virtual void vfunc_00();
    virtual int vfunc_01();
    char m_pad04[0x18];
    int m_Field1C; // +0x1C
};

template <> int ConcreteClassRep<TriggeredSpawnObject>::vfunc_01()
{
    int t2;

    t2 = sub_00025140(492, m_Field1C);
    if (t2) {
        return ((Object*)t2)->sub_001B12A0(0, m_Field1C);
    }
    return 0;
}

// ============================================================================
// [VERIFIED] ConcreteClassRep<TriggeredSpawnObject>::vfunc_02 (0x001AF2B0, 66 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as ConcreteClassRep<GameGroup>::vfunc_02 (0x0002D2E0), which was matched first;
// its addresses and names were swapped for this function's.
// ConcreteClassRep<TriggeredSpawnObject>::vfunc_02 (0x001AF2B0, 66 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0037CD30[];
extern "C" int DAT_00417288;
extern "C" int DAT_0041728C;
extern "C" char DAT_00416CFC[];
extern "C" char DAT_00416D14[];
extern "C" char DAT_00417130[];
extern "C" int DAT_00417154;
extern "C" char sub_001B1320[];
extern "C" void __cdecl sub_000660D0(int, int);
extern "C" void __cdecl sub_001591E0(int, int, int, int, int, int, int);

class TriggeredSpawnObject;

template <class T0> class ConcreteClassRep
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
};

template <> void ConcreteClassRep<TriggeredSpawnObject>::vfunc_02()
{
    sub_000660D0(DAT_00417154, DAT_00417288);
    DAT_0041728C = (int)DAT_00417130;
    sub_001591E0((int)DAT_00416CFC, (int)DAT_00416D14, (int)DAT_0037CD30, (int)sub_001B1320, 2, 2, (int)DAT_0037CD30);
}

