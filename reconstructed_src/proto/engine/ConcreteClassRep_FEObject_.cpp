// ============================================================================
// SCARFACE: THE WORLD IS YOURS — April 2006 prototype game.xbe, engine/ConcreteClassRep_FEObject_.cpp (2 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: COMPLETE. All 2 functions are matched.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] ConcreteClassRep<FEObject>::vfunc_01 (0x000230A0, 60 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// ConcreteClassRep<FEObject>::vfunc_01 (Proto 0x000230A0, 60 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_00028470(int, int);
};

extern "C" char DAT_0037DBF4[];
extern "C" int __cdecl sub_00025140(int, int);

class FEObject;

template <class T0> class ConcreteClassRep
{
public:
    virtual void vfunc_00();
    virtual int vfunc_01();
    char m_pad04[0x18];
    int m_Field1C; // +0x1C
};

template <> int ConcreteClassRep<FEObject>::vfunc_01()
{
    int t2;

    t2 = sub_00025140(36, m_Field1C);
    if (t2) {
        ((Object*)t2)->sub_00028470(0, m_Field1C);
        *(int*)t2 = (int)DAT_0037DBF4;
        *(int*)(t2 + 32) = 0;
        return t2;
    }
    return 0;
}

// ============================================================================
// [VERIFIED] ConcreteClassRep<FEObject>::vfunc_02 (0x000235A0, 61 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as ConcreteClassRep<FEObject>::vfunc_02 (0x000253C0), which was matched first;
// its addresses and names were swapped for this function's.
// ConcreteClassRep<FEObject>::vfunc_02 (0x000235A0, 61 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0037CD30[];
extern "C" int DAT_003F5BA8;
extern "C" int DAT_003F5BAC;
extern "C" char DAT_003F6048[];
extern "C" char DAT_003F6D24[];
extern "C" int DAT_003F6D48;
extern "C" char sub_00021AC0[];
extern "C" void __cdecl sub_00023530(int, int, int, int, int, int);
extern "C" void __cdecl sub_000660D0(int, int);

class FEObject;

template <class T0> class ConcreteClassRep
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
};

template <> void ConcreteClassRep<FEObject>::vfunc_02()
{
    sub_000660D0(DAT_003F6D48, DAT_003F5BA8);
    DAT_003F5BAC = (int)DAT_003F6D24;
    sub_00023530((int)DAT_003F6048, (int)DAT_0037CD30, (int)sub_00021AC0, 2, 2, (int)DAT_0037CD30);
}

