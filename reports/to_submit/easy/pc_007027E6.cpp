// bin: pc
// va: 0x007027E6
// tool: the portal's starter code (no AI)
// fight::ConditionFactory::vfunc_07 (0x007027E6, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_0072F214;

namespace fight {

class ConditionFactory
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual void vfunc_05();
    virtual void vfunc_06();
    virtual void vfunc_07();
};

void ConditionFactory::vfunc_07()
{
    ((void (__cdecl*)(void))DAT_0072F214)();
}

}
