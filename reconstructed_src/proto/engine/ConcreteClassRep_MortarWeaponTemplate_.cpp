// ============================================================================
// SCARFACE: THE WORLD IS YOURS — April 2006 prototype game.xbe, engine/ConcreteClassRep_MortarWeaponTemplate_.cpp (2 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: COMPLETE. All 2 functions are matched.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] ConcreteClassRep<MortarWeaponTemplate>::vfunc_01 (0x001C3700, 43 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as ConcreteClassRep<AITask_BegForLife>::vfunc_01 (Proto 0x000FFDD0), which was matched first;
// its addresses and names were swapped for this function's.
// ConcreteClassRep<MortarWeaponTemplate>::vfunc_01 (Proto 0x001C3700, 43 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    int sub_001C46C0(int, int);
};

extern "C" int __cdecl sub_00025140(int, int);

class MortarWeaponTemplate;

template <class T0> class ConcreteClassRep
{
public:
    virtual void vfunc_00();
    virtual int vfunc_01();
    char m_pad04[0x18];
    int m_Field1C; // +0x1C
};

template <> int ConcreteClassRep<MortarWeaponTemplate>::vfunc_01()
{
    int t2;

    t2 = sub_00025140(228, m_Field1C);
    if (t2) {
        return ((Object*)t2)->sub_001C46C0(0, m_Field1C);
    }
    return 0;
}

// ============================================================================
// [VERIFIED] ConcreteClassRep<MortarWeaponTemplate>::vfunc_02 (0x001C3730, 90 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// What it does: Fills in the script system's description of the MortarWeaponTemplate class and lists its fields.
// ============================================================================
// bin: proto
// va: 0x001C3730
// what: Fills in the script system's description of the MortarWeaponTemplate class and lists its fields.
// tool: Claude Opus 5.5 (transplanted from proto:0x00024510, nearest by portal/tools/similar.py)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_0041A9A0;
extern "C" int DAT_0041A9A4;
extern "C" char DAT_0041A380[];
extern "C" char DAT_0041A3A0[];
extern "C" char DAT_0041A924[];
extern "C" int DAT_0041A948;
extern "C" void __cdecl sub_000660D0(int, int);
extern "C" void __cdecl sub_00069130(int, int, int, int, int, int, int, int, int);

class MortarWeaponTemplate;

template <class T0> class ConcreteClassRep
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
};

template <> void ConcreteClassRep<MortarWeaponTemplate>::vfunc_02()
{
    sub_000660D0(DAT_0041A948, DAT_0041A9A0);
    DAT_0041A9A4 = (int)DAT_0041A924;
    sub_00069130((int)DAT_0041A3A0, 8, 0, 0, 216, 0, 0, 0, 0);
    sub_00069130((int)DAT_0041A380, 8, 0, 0, 220, 0, 0, 0, 0);
}

