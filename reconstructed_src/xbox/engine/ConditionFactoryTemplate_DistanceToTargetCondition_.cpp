// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail Xbox default.xbe, engine/ConditionFactoryTemplate_DistanceToTargetCondition_.cpp (2 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: COMPLETE. All 2 functions are matched.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] fight::ConditionFactoryTemplate<DistanceToTargetCondition>::vfunc_03 (0x000DEA10, 43 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as fight::ConditionFactoryTemplate<AnimationStateCondition>::vfunc_03 (0x000DE4D0), which was matched first;
// its addresses and names were swapped for this function's.
// fight::ConditionFactoryTemplate<DistanceToTargetCondition>::vfunc_03 (0x000DEA10, 43 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_003A7178[];
extern "C" void __cdecl sub_0023F7A0(int);
extern "C" void __cdecl sub_000DD2C0(void);

class DistanceToTargetCondition;

namespace fight { 
template <class T0> class ConditionFactoryTemplate
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual ConditionFactoryTemplate<DistanceToTargetCondition>* vfunc_03(int a1);
    void sub_00239ED0();
};
}

template <> fight::ConditionFactoryTemplate<DistanceToTargetCondition>* fight::ConditionFactoryTemplate<DistanceToTargetCondition>::vfunc_03(int a1)
{
    *(int*)this = (int)DAT_003A7178;
    sub_000DD2C0();
    sub_00239ED0();
    if (a1 & 1) {
        sub_0023F7A0((int)this);
    }
    return this;
}

// ============================================================================
// [VERIFIED] fight::ConditionFactoryTemplate<DistanceToTargetCondition>::vfunc_07 (0x000DEA40, 52 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// fight::ConditionFactoryTemplate<DistanceToTargetCondition>::vfunc_07 (0x000DEA40, 52 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    int sub_000DD2F0();
    void sub_00242D20(int);
};

extern "C" int __cdecl sub_0023F760(int);

class DistanceToTargetCondition;

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

template <> int fight::ConditionFactoryTemplate<DistanceToTargetCondition>::vfunc_07()
{
    int r_edi, r_esi, t1;

    r_edi = (int)this;
    t1 = sub_0023F760(24);
    if (t1) {
        r_esi = ((Object*)t1)->sub_000DD2F0();
    } else {
        r_esi = 0;
    }
    if (r_edi) {
        r_edi += 8;
        ((Object*)r_esi + 8)->sub_00242D20(r_edi);
    }
    return r_esi;
}

