// bin: pc
// va: 0x006E3F00
// tool: the portal's starter code (no AI)
// fight::ParamBranch<ExitConditionTrack>::vfunc_01 (0x006E3F00, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

class ExitConditionTrack;

namespace fight { 
template <class T0> class ParamBranch
{
public:
    virtual void vfunc_00();
    virtual int vfunc_01();
};
}

template <> int fight::ParamBranch<ExitConditionTrack>::vfunc_01()
{
    return 9;
}
