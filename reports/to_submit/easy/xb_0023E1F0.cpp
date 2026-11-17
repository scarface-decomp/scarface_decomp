// bin: xb
// va: 0x0023E1F0
// tool: the portal's starter code (no AI)
// fight::ConditionParameterlessFactoryTemplate<fight::AndCondition>::vfunc_03 (0x0023E1F0, 49 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.
// This function keeps a frame pointer (push ebp; mov ebp, esp), so it is built with them on.
#pragma optimize("y", off)

struct Object
{
    virtual void vfunc_00();
    virtual void vfunc_01();
};

extern "C" char DAT_003D4668[];
extern "C" void __cdecl sub_0023F7A0(int);

namespace fight { class AndCondition; }

namespace fight { 
template <class T0> class ConditionParameterlessFactoryTemplate
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual ConditionParameterlessFactoryTemplate<fight::AndCondition>* vfunc_03(int a1);
    void sub_00239ED0();
    char m_pad04[0x8];
    int m_Field0C; // +0x0C
};
}

template <> fight::ConditionParameterlessFactoryTemplate<fight::AndCondition>* fight::ConditionParameterlessFactoryTemplate<fight::AndCondition>::vfunc_03(int a1)
{
    int t1;

    t1 = m_Field0C;
    *(int*)this = (int)DAT_003D4668;
    ((Object*)t1)->vfunc_01();
    sub_00239ED0();
    if (a1 & 1) {
        sub_0023F7A0((int)this);
    }
    return this;
}
