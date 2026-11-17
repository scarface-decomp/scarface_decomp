// bin: xb
// va: 0x0023E050
// tool: the portal's starter code (no AI)
// fight::ConditionFactoryTemplate<fight::MaybeCondition>::vfunc_03 (0x0023E050, 46 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.
// This function keeps a frame pointer (push ebp; mov ebp, esp), so it is built with them on.
#pragma optimize("y", off)

extern "C" char DAT_003D4554[];
extern "C" void __cdecl sub_0023DED0(void);
extern "C" void __cdecl sub_0023F7A0(int);

namespace fight { class MaybeCondition; }

namespace fight { 
template <class T0> class ConditionFactoryTemplate
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual ConditionFactoryTemplate<fight::MaybeCondition>* vfunc_03(int a1);
    void sub_00239ED0();
};
}

template <> fight::ConditionFactoryTemplate<fight::MaybeCondition>* fight::ConditionFactoryTemplate<fight::MaybeCondition>::vfunc_03(int a1)
{
    *(int*)this = (int)DAT_003D4554;
    sub_0023DED0();
    sub_00239ED0();
    if (a1 & 1) {
        sub_0023F7A0((int)this);
    }
    return this;
}
