// ============================================================================
// SCARFACE: THE WORLD IS YOURS — April 2006 prototype game.xbe, engine/ConcreteClassRep_SkyTemplate_.cpp (2 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: COMPLETE. All 2 functions are matched.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] ConcreteClassRep<SkyTemplate>::vfunc_01 (0x001C23D0, 40 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as ConcreteClassRep<LoadObject>::vfunc_01 (Proto 0x00191BA0), which was matched first;
// its addresses and names were swapped for this function's.
// ConcreteClassRep<SkyTemplate>::vfunc_01 (Proto 0x001C23D0, 40 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    int sub_001C38D0(int, int);
};

extern "C" int __cdecl sub_00025140(int, int);

class SkyTemplate;

template <class T0> class ConcreteClassRep
{
public:
    virtual void vfunc_00();
    virtual int vfunc_01();
    char m_pad04[0x18];
    int m_Field1C; // +0x1C
};

template <> int ConcreteClassRep<SkyTemplate>::vfunc_01()
{
    int t2;

    t2 = sub_00025140(44, m_Field1C);
    if (t2) {
        return ((Object*)t2)->sub_001C38D0(0, m_Field1C);
    }
    return 0;
}

// ============================================================================
// [VERIFIED] ConcreteClassRep<SkyTemplate>::vfunc_02 (0x001C2400, 84 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// What it does: Fills in the script system's description of the SkyTemplate class and lists its fields.
// ============================================================================
// bin: proto
// va: 0x001C2400
// what: Fills in the script system's description of the SkyTemplate class and lists its fields.
// tool: Claude Opus 5.5 (transplanted from proto:0x00024510, nearest by portal/tools/similar.py)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_00419A84;
extern "C" int DAT_00419A88;
extern "C" char DAT_00419A14[];
extern "C" char DAT_00419A20[];
extern "C" char DAT_003F6F68[];
extern "C" int DAT_003F6F8C;
extern "C" void __cdecl sub_000660D0(int, int);
extern "C" void __cdecl sub_00069130(int, int, int, int, int, int, int, int, int);

class SkyTemplate;

template <class T0> class ConcreteClassRep
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
};

template <> void ConcreteClassRep<SkyTemplate>::vfunc_02()
{
    sub_000660D0(DAT_003F6F8C, DAT_00419A84);
    DAT_00419A88 = (int)DAT_003F6F68;
    sub_00069130((int)DAT_00419A20, 8, 0, 0, 36, 0, 0, 0, 0);
    sub_00069130((int)DAT_00419A14, 8, 0, 0, 40, 0, 0, 0, 0);
}

