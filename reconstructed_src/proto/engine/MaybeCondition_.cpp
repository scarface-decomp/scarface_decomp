// ============================================================================
// SCARFACE: THE WORLD IS YOURS — April 2006 prototype game.xbe, engine/MaybeCondition_.cpp (2 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: COMPLETE. All 2 functions are matched.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] fight::ConditionFactoryTemplate<fight::MaybeCondition>::vfunc_07 (0x001FB9C0, 65 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// What it does: Factory for fight::MaybeCondition: allocates a new one (20 bytes), constructs it, and hands it the factory's data at +8.
// ============================================================================
// fight::ConditionFactoryTemplate<fight::MaybeCondition>::vfunc_07 (Proto 0x001FB9C0, 65 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0008D490(int);
    void sub_001F7910();
};

extern "C" char DAT_003AD704[];
extern "C" int __cdecl sub_001FCF20(int);

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
    r_esi = sub_001FCF20(20);
    if (r_esi) {
        ((Object*)r_esi)->sub_001F7910();
        *(int*)r_esi = (int)DAT_003AD704;
        *(int*)(r_esi + 16) = 0x42C80000;
    } else {
        r_esi = 0;
    }
    if (r_edi) {
        r_edi += 8;
        ((Object*)r_esi + 8)->sub_0008D490(r_edi);
    }
    return r_esi;
}

// ============================================================================
// [VERIFIED] fight::ConditionFactoryTemplate<fight::MaybeCondition>::vfunc_03 (0x001FBA10, 43 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// fight::ConditionFactoryTemplate<fight::MaybeCondition>::vfunc_03 (Proto 0x001FBA10, 43 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_003AD76C[];
extern "C" void __cdecl sub_001FB8B0(void);
extern "C" void __cdecl sub_001FCF60(int);

namespace fight { class MaybeCondition; }

namespace fight { 
template <class T0> class ConditionFactoryTemplate
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual ConditionFactoryTemplate<fight::MaybeCondition>* vfunc_03(int a1);
    void sub_001F7900();
};
}

template <> fight::ConditionFactoryTemplate<fight::MaybeCondition>* fight::ConditionFactoryTemplate<fight::MaybeCondition>::vfunc_03(int a1)
{
    *(int*)this = (int)DAT_003AD76C;
    sub_001FB8B0();
    sub_001F7900();
    if (a1 & 1) {
        sub_001FCF60((int)this);
    }
    return this;
}

