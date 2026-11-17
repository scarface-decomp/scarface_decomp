// bin: pc
// va: 0x006E3DD0
// tool: the portal's starter code (no AI)
// fight::ParamEnumConstList<DirectionalGetHitCondition>::vfunc_01 (0x006E3DD0, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

class DirectionalGetHitCondition;

namespace fight { 
template <class T0> class ParamEnumConstList
{
public:
    virtual void vfunc_00();
    virtual int vfunc_01();
};
}

template <> int fight::ParamEnumConstList<DirectionalGetHitCondition>::vfunc_01()
{
    return 5;
}
