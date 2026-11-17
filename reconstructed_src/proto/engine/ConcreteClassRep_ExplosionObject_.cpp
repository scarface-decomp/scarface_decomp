// ============================================================================
// SCARFACE: THE WORLD IS YOURS — April 2006 prototype game.xbe, engine/ConcreteClassRep_ExplosionObject_.cpp (2 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: COMPLETE. All 2 functions are matched.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] ConcreteClassRep<ExplosionObject>::vfunc_01 (0x001B3D80, 43 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as ConcreteClassRep<TargetHUD>::vfunc_01 (Proto 0x0018C130), which was matched first;
// its addresses and names were swapped for this function's.
// ConcreteClassRep<ExplosionObject>::vfunc_01 (Proto 0x001B3D80, 43 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    int sub_001B1CF0(int, int);
};

extern "C" int __cdecl sub_00025140(int, int);

class ExplosionObject;

template <class T0> class ConcreteClassRep
{
public:
    virtual void vfunc_00();
    virtual int vfunc_01();
    char m_pad04[0x18];
    int m_Field1C; // +0x1C
};

template <> int ConcreteClassRep<ExplosionObject>::vfunc_01()
{
    int t2;

    t2 = sub_00025140(244, m_Field1C);
    if (t2) {
        return ((Object*)t2)->sub_001B1CF0(0, m_Field1C);
    }
    return 0;
}

// ============================================================================
// [VERIFIED] ConcreteClassRep<ExplosionObject>::vfunc_02 (0x001B3DB0, 32 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as ConcreteClassRep<CollisionBehaviourTypeGroup>::vfunc_02 (0x00011400), which was matched first;
// its addresses and names were swapped for this function's.
// ConcreteClassRep<ExplosionObject>::vfunc_02 (0x001B3DB0, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_004177BC;
extern "C" int DAT_004177C0;
extern "C" char DAT_003F66E4[];
extern "C" int DAT_003F6708;
extern "C" void __cdecl sub_000660D0(int, int);

class ExplosionObject;

template <class T0> class ConcreteClassRep
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
};

template <> void ConcreteClassRep<ExplosionObject>::vfunc_02()
{
    sub_000660D0(DAT_003F6708, DAT_004177BC);
    DAT_004177C0 = (int)DAT_003F66E4;
}

