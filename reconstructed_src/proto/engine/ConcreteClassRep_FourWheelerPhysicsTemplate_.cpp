// ============================================================================
// SCARFACE: THE WORLD IS YOURS — April 2006 prototype game.xbe, engine/ConcreteClassRep_FourWheelerPhysicsTemplate_.cpp (2 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: COMPLETE. All 2 functions are matched.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] ConcreteClassRep<FourWheelerPhysicsTemplate>::vfunc_02 (0x001D0850, 36 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as ConcreteClassRep<CollisionSurfaceType>::vfunc_02 (0x00011450), which was matched first;
// its addresses and names were swapped for this function's.
// ConcreteClassRep<FourWheelerPhysicsTemplate>::vfunc_02 (0x001D0850, 36 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_004245DC;
extern "C" int DAT_004245E0;
extern "C" char DAT_0042458C[];
extern "C" int DAT_004245B0;
extern "C" void __cdecl sub_001D0470(void);
extern "C" void __cdecl sub_000660D0(int, int);

class FourWheelerPhysicsTemplate;

template <class T0> class ConcreteClassRep
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
};

template <> void ConcreteClassRep<FourWheelerPhysicsTemplate>::vfunc_02()
{
    sub_000660D0(DAT_004245B0, DAT_004245DC);
    DAT_004245E0 = (int)DAT_0042458C;
    sub_001D0470();
}

// ============================================================================
// [VERIFIED] ConcreteClassRep<FourWheelerPhysicsTemplate>::vfunc_01 (0x001D0880, 66 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// ConcreteClassRep<FourWheelerPhysicsTemplate>::vfunc_01 (Proto 0x001D0880, 66 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_001D0950(int, int);
};

extern "C" char DAT_003A6B78[];
extern "C" char DAT_003A6B84[];
extern "C" int __cdecl sub_00025140(int, int);

class FourWheelerPhysicsTemplate;

template <class T0> class ConcreteClassRep
{
public:
    virtual void vfunc_00();
    virtual int vfunc_01();
    char m_pad04[0x18];
    int m_Field1C; // +0x1C
};

template <> int ConcreteClassRep<FourWheelerPhysicsTemplate>::vfunc_01()
{
    int t2;

    t2 = sub_00025140(804, m_Field1C);
    if (t2) {
        ((Object*)t2)->sub_001D0950(0, m_Field1C);
        *(int*)t2 = (int)DAT_003A6B84;
        *(int*)(t2 + 792) = (int)DAT_003A6B78;
        return t2;
    }
    return 0;
}

