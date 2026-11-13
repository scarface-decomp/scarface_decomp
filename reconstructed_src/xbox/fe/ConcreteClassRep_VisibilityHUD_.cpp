// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail Xbox default.xbe, fe/ConcreteClassRep_VisibilityHUD_.cpp (2 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: COMPLETE. All 2 functions are matched.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] ConcreteClassRep<VisibilityHUD>::vfunc_01 (0x001BFC90, 42 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as ConcreteClassRep<AITask_ReactToDangerReaction>::vfunc_01 (0x0011BA70), which was matched first;
// its addresses and names were swapped for this function's.
// ConcreteClassRep<VisibilityHUD>::vfunc_01 (0x001BFC90, 42 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    int sub_001C23D0(int, int);
};

extern "C" int __cdecl sub_000275B0(int, int);

class VisibilityHUD;

template <class T0> class ConcreteClassRep
{
public:
    virtual void vfunc_00();
    virtual int vfunc_01();
    char m_pad04[0x24];
    char m_Field28; // +0x28
};

template <> int ConcreteClassRep<VisibilityHUD>::vfunc_01()
{
    int t2;

    t2 = sub_000275B0(120, m_Field28);
    if (t2) {
        return ((Object*)t2)->sub_001C23D0(0, m_Field28);
    }
    return 0;
}

// ============================================================================
// [VERIFIED] ConcreteClassRep<VisibilityHUD>::vfunc_02 (0x001BFCC0, 44 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as ConcreteClassRep<GenericWeaponHUD>::vfunc_02 (0x001BCB10), which was matched first;
// its addresses and names were swapped for this function's.
extern "C" int DAT_00438000;
extern "C" int DAT_00438004;
extern "C" unsigned char DAT_00438008;
extern "C" char DAT_00436664[];
extern "C" int DAT_00436684;
extern "C" unsigned char DAT_0043668C;
extern "C" void __cdecl sub_00070520(int, int);

class VisibilityHUD;

template <class T0> class ConcreteClassRep
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
};

template <> void ConcreteClassRep<VisibilityHUD>::vfunc_02()
{
    sub_00070520(DAT_00436684, DAT_00438000);
    DAT_00438004 = (int)DAT_00436664;
    DAT_00438008 = 22;
    DAT_0043668C = 22;
}

