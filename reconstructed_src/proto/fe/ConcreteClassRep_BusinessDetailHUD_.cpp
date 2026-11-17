// ============================================================================
// SCARFACE: THE WORLD IS YOURS — April 2006 prototype game.xbe, fe/ConcreteClassRep_BusinessDetailHUD_.cpp (2 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: COMPLETE. All 2 functions are matched.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] ConcreteClassRep<BusinessDetailHUD>::vfunc_01 (0x0018A020, 40 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as ConcreteClassRep<AITask_PedTraffic>::vfunc_01 (Proto 0x00100070), which was matched first;
// its addresses and names were swapped for this function's.
// ConcreteClassRep<BusinessDetailHUD>::vfunc_01 (Proto 0x0018A020, 40 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    int sub_0016C0D0(int, int);
};

extern "C" int __cdecl sub_00025140(int, int);

class BusinessDetailHUD;

template <class T0> class ConcreteClassRep
{
public:
    virtual void vfunc_00();
    virtual int vfunc_01();
    char m_pad04[0x18];
    int m_Field1C; // +0x1C
};

template <> int ConcreteClassRep<BusinessDetailHUD>::vfunc_01()
{
    int t2;

    t2 = sub_00025140(76, m_Field1C);
    if (t2) {
        return ((Object*)t2)->sub_0016C0D0(0, m_Field1C);
    }
    return 0;
}

// ============================================================================
// [VERIFIED] ConcreteClassRep<BusinessDetailHUD>::vfunc_02 (0x0018A050, 42 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as ConcreteClassRep<SaveGameObject>::vfunc_02 (Proto 0x000BADD0), which was matched first;
// its addresses and names were swapped for this function's.
// ConcreteClassRep<BusinessDetailHUD>::vfunc_02 (Proto 0x0018A050, 42 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0041052C[];
extern "C" int DAT_00410550;
extern "C" int DAT_00410230;
extern "C" int DAT_00410238;
extern "C" int DAT_0041023C;
extern "C" void __cdecl sub_000660D0(int, int);

class BusinessDetailHUD;

template <class T0> class ConcreteClassRep
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
};

template <> void ConcreteClassRep<BusinessDetailHUD>::vfunc_02()
{
    sub_000660D0(DAT_00410550, DAT_00410238);
    DAT_0041023C = (int)DAT_0041052C;
    DAT_00410230 = 7;
}

