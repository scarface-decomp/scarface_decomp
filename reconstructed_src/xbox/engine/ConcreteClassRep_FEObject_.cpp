// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail Xbox default.xbe, engine/ConcreteClassRep_FEObject_.cpp (2 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: COMPLETE. All 2 functions are matched.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] ConcreteClassRep<FEObject>::vfunc_01 (0x00024E50, 66 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// ConcreteClassRep<FEObject>::vfunc_01 (0x00024E50, 66 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0002BEE0(int, int);
};

extern "C" char DAT_0039E5C4[];
extern "C" int __cdecl sub_000275B0(int, int);

class FEObject;

template <class T0> class ConcreteClassRep
{
public:
    virtual void vfunc_00();
    virtual int vfunc_01();
    char m_pad04[0x24];
    char m_Field28; // +0x28
};

template <> int ConcreteClassRep<FEObject>::vfunc_01()
{
    int t2;

    t2 = sub_000275B0(40, m_Field28);
    if (t2) {
        ((Object*)t2)->sub_0002BEE0(0, m_Field28);
        *(int*)t2 = (int)DAT_0039E5C4;
        *(int*)(t2 + 32) = 0;
        *(bool*)(t2 + 36) = true;
        return t2;
    }
    return 0;
}

// ============================================================================
// [VERIFIED] ConcreteClassRep<FEObject>::vfunc_02 (0x000253C0, 61 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// ConcreteClassRep<FEObject>::vfunc_02 (0x000253C0, 61 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0039D520[];
extern "C" int DAT_0041AB58;
extern "C" int DAT_0041AB5C;
extern "C" char DAT_0041AFA0[];
extern "C" char DAT_0041BDC0[];
extern "C" int DAT_0041BDE0;
extern "C" char sub_00023D20[];
extern "C" void __cdecl sub_00025350(int, int, int, int, int, int);
extern "C" void __cdecl sub_00070520(int, int);

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
    sub_00070520(DAT_0041BDE0, DAT_0041AB58);
    DAT_0041AB5C = (int)DAT_0041BDC0;
    sub_00025350((int)DAT_0041AFA0, (int)DAT_0039D520, (int)sub_00023D20, 2, 2, (int)DAT_0039D520);
}

