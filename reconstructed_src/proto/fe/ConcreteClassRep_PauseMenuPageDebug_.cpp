// ============================================================================
// SCARFACE: THE WORLD IS YOURS — April 2006 prototype game.xbe, fe/ConcreteClassRep_PauseMenuPageDebug_.cpp (2 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: COMPLETE. All 2 functions are matched.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] ConcreteClassRep<PauseMenuPageDebug>::vfunc_01 (0x00196C20, 40 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as ConcreteClassRep<SaveGameObject>::vfunc_01 (Proto 0x000BADA0), which was matched first;
// its addresses and names were swapped for this function's.
// ConcreteClassRep<PauseMenuPageDebug>::vfunc_01 (Proto 0x00196C20, 40 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    int sub_00194980(int, int);
};

extern "C" int __cdecl sub_00025140(int, int);

class PauseMenuPageDebug;

template <class T0> class ConcreteClassRep
{
public:
    virtual void vfunc_00();
    virtual int vfunc_01();
    char m_pad04[0x18];
    int m_Field1C; // +0x1C
};

template <> int ConcreteClassRep<PauseMenuPageDebug>::vfunc_01()
{
    int t2;

    t2 = sub_00025140(88, m_Field1C);
    if (t2) {
        return ((Object*)t2)->sub_00194980(0, m_Field1C);
    }
    return 0;
}

// ============================================================================
// [VERIFIED] ConcreteClassRep<PauseMenuPageDebug>::vfunc_02 (0x00196C50, 42 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as ConcreteClassRep<SaveGameObject>::vfunc_02 (Proto 0x000BADD0), which was matched first;
// its addresses and names were swapped for this function's.
// ConcreteClassRep<PauseMenuPageDebug>::vfunc_02 (Proto 0x00196C50, 42 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_00413408[];
extern "C" int DAT_0041342C;
extern "C" int DAT_004135B0;
extern "C" int DAT_004135B8;
extern "C" int DAT_004135BC;
extern "C" void __cdecl sub_000660D0(int, int);

class PauseMenuPageDebug;

template <class T0> class ConcreteClassRep
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
};

template <> void ConcreteClassRep<PauseMenuPageDebug>::vfunc_02()
{
    sub_000660D0(DAT_0041342C, DAT_004135B8);
    DAT_004135BC = (int)DAT_00413408;
    DAT_004135B0 = 7;
}

