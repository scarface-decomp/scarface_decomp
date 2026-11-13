// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail Xbox default.xbe, fe/ConcreteClassRep_PauseMenuPageMain_.cpp (2 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: COMPLETE. All 2 functions are matched.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] ConcreteClassRep<PauseMenuPageMain>::vfunc_01 (0x001CE480, 45 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as ConcreteClassRep<AttractPoint>::vfunc_01 (0x0011AE60), which was matched first;
// its addresses and names were swapped for this function's.
// ConcreteClassRep<PauseMenuPageMain>::vfunc_01 (0x001CE480, 45 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    int sub_001CC160(int, int);
};

extern "C" int __cdecl sub_000275B0(int, int);

class PauseMenuPageMain;

template <class T0> class ConcreteClassRep
{
public:
    virtual void vfunc_00();
    virtual int vfunc_01();
    char m_pad04[0x24];
    char m_Field28; // +0x28
};

template <> int ConcreteClassRep<PauseMenuPageMain>::vfunc_01()
{
    int t2;

    t2 = sub_000275B0(152, m_Field28);
    if (t2) {
        return ((Object*)t2)->sub_001CC160(0, m_Field28);
    }
    return 0;
}

// ============================================================================
// [VERIFIED] ConcreteClassRep<PauseMenuPageMain>::vfunc_02 (0x001CE4B0, 39 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as ConcreteClassRep<SaveGameObject>::vfunc_02 (0x000CA0D0), which was matched first;
// its addresses and names were swapped for this function's.
// ConcreteClassRep<PauseMenuPageMain>::vfunc_02 (0x001CE4B0, 39 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_00439D20[];
extern "C" int DAT_00439D40;
extern "C" int DAT_00439D98;
extern "C" int DAT_00439D9C;
extern "C" unsigned char DAT_00439DA0;
extern "C" void __cdecl sub_00070520(int, int);

class PauseMenuPageMain;

template <class T0> class ConcreteClassRep
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
};

template <> void ConcreteClassRep<PauseMenuPageMain>::vfunc_02()
{
    sub_00070520(DAT_00439D40, DAT_00439D98);
    DAT_00439D9C = (int)DAT_00439D20;
    DAT_00439DA0 = 7;
}

