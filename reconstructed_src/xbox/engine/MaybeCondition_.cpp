// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail Xbox default.xbe, engine/MaybeCondition_.cpp (2 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: COMPLETE. All 2 functions are matched.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] fight::ConditionFactoryTemplate<fight::MaybeCondition>::vfunc_07 (0x0023E000, 65 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as fight::ConditionFactoryTemplate<fight::MaybeCondition>::vfunc_07 (Proto 0x001FB9C0), which was matched first;
// its addresses and names were swapped for this function's.
// fight::ConditionFactoryTemplate<fight::MaybeCondition>::vfunc_07 (Proto 0x0023E000, 65 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_00242D20(int);
    void sub_00239EE0();
};

extern "C" char DAT_003D44EC[];
extern "C" int __cdecl sub_0023F760(int);

namespace fight { class MaybeCondition; }

namespace fight { 
template <class T0> class ConditionFactoryTemplate
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual void vfunc_05();
    virtual void vfunc_06();
    virtual int vfunc_07();
};
}

template <> int fight::ConditionFactoryTemplate<fight::MaybeCondition>::vfunc_07()
{
    int r_edi, r_esi;

    r_edi = (int)this;
    r_esi = sub_0023F760(20);
    if (r_esi) {
        ((Object*)r_esi)->sub_00239EE0();
        *(int*)r_esi = (int)DAT_003D44EC;
        *(int*)(r_esi + 16) = 0x42C80000;
    } else {
        r_esi = 0;
    }
    if (r_edi) {
        r_edi += 8;
        ((Object*)r_esi + 8)->sub_00242D20(r_edi);
    }
    return r_esi;
}

// ============================================================================
// [VERIFIED] fight::ConditionFactoryTemplate<fight::MaybeCondition>::vfunc_03 (0x0023E050, 46 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// What it does: Deleting destructor: puts back the class's vtable, runs its two destructors, then frees the object when asked to.
// ============================================================================
// bin: xb
// va: 0x0023E050
// what: Deleting destructor: puts back the class's vtable, runs its two destructors, then frees the object when asked to.
// tool: Claude Opus 5.5 (byte copy of the matched 0x0024A800 with its own addresses, examiner A6: ?$ConditionFactoryTemplate@VMaybeCondition@fight@@@fight::vfunc_03)
#pragma optimize("y", off)

extern "C" char DAT_003D4554[];
extern "C" void __cdecl sub_0023F7A0(int);
extern "C" void __cdecl sub_0023DED0(void);

class Class_0023E050
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual Class_0023E050* sub_0023E050(int a1);
    void sub_00239ED0();
};

Class_0023E050* Class_0023E050::sub_0023E050(int a1)
{
    *(int*)this = (int)DAT_003D4554;
    sub_0023DED0();
    sub_00239ED0();
    if (a1 & 1) {
        sub_0023F7A0((int)this);
    }
    return this;
}

