// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail Xbox default.xbe, engine/ConcreteClassRep_WheeledVehicleTemplate_.cpp (2 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: COMPLETE. All 2 functions are matched.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] ConcreteClassRep<WheeledVehicleTemplate>::vfunc_01 (0x0020C3D0, 45 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as ConcreteClassRep<BlackjackHUD>::vfunc_01 (0x001BC7B0), which was matched first;
// its addresses and names were swapped for this function's.
// ConcreteClassRep<WheeledVehicleTemplate>::vfunc_01 (0x0020C3D0, 45 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    int sub_00211B00(int, int);
};

extern "C" int __cdecl sub_000275B0(int, int);

class WheeledVehicleTemplate;

template <class T0> class ConcreteClassRep
{
public:
    virtual void vfunc_00();
    virtual int vfunc_01();
    char m_pad04[0x24];
    char m_Field28; // +0x28
};

template <> int ConcreteClassRep<WheeledVehicleTemplate>::vfunc_01()
{
    int t2;

    t2 = sub_000275B0(260, m_Field28);
    if (t2) {
        return ((Object*)t2)->sub_00211B00(0, m_Field28);
    }
    return 0;
}

// ============================================================================
// [VERIFIED] ConcreteClassRep<WheeledVehicleTemplate>::vfunc_02 (0x0020C400, 64 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as ConcreteClassRep<FEGroupObject>::vfunc_02 (0x00024EF0), which was matched first;
// its addresses and names were swapped for this function's.
// ConcreteClassRep<WheeledVehicleTemplate>::vfunc_02 (0x0020C400, 64 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_0044B09C;
extern "C" int DAT_0044B0A0;
extern "C" char DAT_0044AED8[];
extern "C" char DAT_00447AB4[];
extern "C" int DAT_00447AD4;
extern "C" char sub_0020C230[];
extern "C" char sub_0020C270[];
extern "C" void __cdecl sub_00070520(int, int);
extern "C" void __cdecl sub_00073780(int, int, int, int, int, int, int, int, int);

class WheeledVehicleTemplate;

template <class T0> class ConcreteClassRep
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
};

template <> void ConcreteClassRep<WheeledVehicleTemplate>::vfunc_02()
{
    sub_00070520(DAT_00447AD4, DAT_0044B09C);
    DAT_0044B0A0 = (int)DAT_00447AB4;
    sub_00073780((int)DAT_0044AED8, 8, 0, 0, 0, 0, 0, (int)sub_0020C230, (int)sub_0020C270);
}

