// ============================================================================
// SCARFACE: THE WORLD IS YOURS — April 2006 prototype game.xbe, engine/OrCondition_.cpp (1 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: COMPLETE. All 1 functions are matched.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] fight::ConditionParameterlessFactoryTemplate<fight::OrCondition>::vfunc_03 (0x001FBC30, 46 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// fight::ConditionParameterlessFactoryTemplate<fight::OrCondition>::vfunc_03 (Proto 0x001FBC30, 46 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    virtual void vfunc_00();
    virtual void vfunc_01();
};

extern "C" char DAT_003AD8A4[];
extern "C" void __cdecl sub_001FCF60(int);

namespace fight { class OrCondition; }

namespace fight { 
template <class T0> class ConditionParameterlessFactoryTemplate
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual ConditionParameterlessFactoryTemplate<fight::OrCondition>* vfunc_03(int a1);
    void sub_001F7900();
    char m_pad04[0x8];
    int m_Field0C; // +0x0C
};
}

template <> fight::ConditionParameterlessFactoryTemplate<fight::OrCondition>* fight::ConditionParameterlessFactoryTemplate<fight::OrCondition>::vfunc_03(int a1)
{
    int t1;

    t1 = m_Field0C;
    *(int*)this = (int)DAT_003AD8A4;
    ((Object*)t1)->vfunc_01();
    sub_001F7900();
    if (a1 & 1) {
        sub_001FCF60((int)this);
    }
    return this;
}

