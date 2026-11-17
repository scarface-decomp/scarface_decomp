// ============================================================================
// SCARFACE: THE WORLD IS YOURS — April 2006 prototype game.xbe, engine/ConcreteClassRep_FEPageObject_.cpp (2 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: COMPLETE. All 2 functions are matched.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] ConcreteClassRep<FEPageObject>::vfunc_01 (0x00023220, 53 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// ConcreteClassRep<FEPageObject>::vfunc_01 (Proto 0x00023220, 53 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_00026980(int, int);
};

extern "C" char DAT_0037E1AC[];
extern "C" int __cdecl sub_00025140(int, int);

class FEPageObject;

template <class T0> class ConcreteClassRep
{
public:
    virtual void vfunc_00();
    virtual int vfunc_01();
    char m_pad04[0x18];
    int m_Field1C; // +0x1C
};

template <> int ConcreteClassRep<FEPageObject>::vfunc_01()
{
    int t2;

    t2 = sub_00025140(68, m_Field1C);
    if (t2) {
        ((Object*)t2)->sub_00026980(0, 7);
        *(int*)(t2 + 64) = 0;
        *(int*)t2 = (int)DAT_0037E1AC;
        return t2;
    }
    return 0;
}

// ============================================================================
// [VERIFIED] ConcreteClassRep<FEPageObject>::vfunc_02 (0x00023260, 32 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as ConcreteClassRep<CollisionBehaviourTypeGroup>::vfunc_02 (0x00011400), which was matched first;
// its addresses and names were swapped for this function's.
// ConcreteClassRep<FEPageObject>::vfunc_02 (0x00023260, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_003F5C58;
extern "C" int DAT_003F5C5C;
extern "C" char DAT_003F5BB0[];
extern "C" int DAT_003F5BD4;
extern "C" void __cdecl sub_000660D0(int, int);

class FEPageObject;

template <class T0> class ConcreteClassRep
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
};

template <> void ConcreteClassRep<FEPageObject>::vfunc_02()
{
    sub_000660D0(DAT_003F5BD4, DAT_003F5C58);
    DAT_003F5C5C = (int)DAT_003F5BB0;
}

