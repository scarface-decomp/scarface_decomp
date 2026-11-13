// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail Xbox default.xbe, fe/ConcreteClassRep_PromptHUD_.cpp (2 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: COMPLETE. All 2 functions are matched.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] ConcreteClassRep<PromptHUD>::vfunc_01 (0x001BF480, 45 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as ConcreteClassRep<HUDTrackable>::vfunc_01 (0x001BE8E0), which was matched first;
// its addresses and names were swapped for this function's.
// ConcreteClassRep<PromptHUD>::vfunc_01 (0x001BF480, 45 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    int sub_001ABFE0(int, int);
};

extern "C" int __cdecl sub_000275B0(int, int);

class PromptHUD;

template <class T0> class ConcreteClassRep
{
public:
    virtual void vfunc_00();
    virtual int vfunc_01();
    char m_pad04[0x24];
    char m_Field28; // +0x28
};

template <> int ConcreteClassRep<PromptHUD>::vfunc_01()
{
    int t2;

    t2 = sub_000275B0(160, m_Field28);
    if (t2) {
        return ((Object*)t2)->sub_001ABFE0(0, m_Field28);
    }
    return 0;
}

// ============================================================================
// [VERIFIED] ConcreteClassRep<PromptHUD>::vfunc_02 (0x001BF4B0, 39 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// ConcreteClassRep<PromptHUD>::vfunc_02 (0x001BF4B0, 39 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_00436664[];
extern "C" int DAT_00436684;
extern "C" int DAT_00437A68;
extern "C" int DAT_00437A6C;
extern "C" unsigned char DAT_00437A70;
extern "C" void __cdecl sub_00070520(int, int);

class PromptHUD;

template <class T0> class ConcreteClassRep
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
};

template <> void ConcreteClassRep<PromptHUD>::vfunc_02()
{
    sub_00070520(DAT_00436684, DAT_00437A68);
    DAT_00437A6C = (int)DAT_00436664;
    DAT_00437A70 = 22;
}

