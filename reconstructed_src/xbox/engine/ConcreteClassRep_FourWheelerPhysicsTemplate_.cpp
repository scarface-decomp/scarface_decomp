// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail Xbox default.xbe, engine/ConcreteClassRep_FourWheelerPhysicsTemplate_.cpp (2 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: COMPLETE. All 2 functions are matched.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] ConcreteClassRep<FourWheelerPhysicsTemplate>::vfunc_02 (0x0020BD80, 36 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as ConcreteClassRep<CollisionSurfaceType>::vfunc_02 (0x00011450), which was matched first;
// its addresses and names were swapped for this function's.
// ConcreteClassRep<FourWheelerPhysicsTemplate>::vfunc_02 (0x0020BD80, 36 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_0044AC80;
extern "C" int DAT_0044AC84;
extern "C" char DAT_0044AC34[];
extern "C" int DAT_0044AC54;
extern "C" void __cdecl sub_0020B9A0(void);
extern "C" void __cdecl sub_00070520(int, int);

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
    sub_00070520(DAT_0044AC54, DAT_0044AC80);
    DAT_0044AC84 = (int)DAT_0044AC34;
    sub_0020B9A0();
}

// ============================================================================
// [VERIFIED] ConcreteClassRep<FourWheelerPhysicsTemplate>::vfunc_01 (0x0020BDB0, 68 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// ConcreteClassRep<FourWheelerPhysicsTemplate>::vfunc_01 (0x0020BDB0, 68 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0020BE70(int, int);
};

extern "C" char DAT_003CCD4C[];
extern "C" char DAT_003CCD5C[];
extern "C" int __cdecl sub_000275B0(int, int);

class FourWheelerPhysicsTemplate;

template <class T0> class ConcreteClassRep
{
public:
    virtual void vfunc_00();
    virtual int vfunc_01();
    char m_pad04[0x24];
    char m_Field28; // +0x28
};

template <> int ConcreteClassRep<FourWheelerPhysicsTemplate>::vfunc_01()
{
    int t2;

    t2 = sub_000275B0(808, m_Field28);
    if (t2) {
        ((Object*)t2)->sub_0020BE70(0, m_Field28);
        *(int*)t2 = (int)DAT_003CCD5C;
        *(int*)(t2 + 796) = (int)DAT_003CCD4C;
        return t2;
    }
    return 0;
}

