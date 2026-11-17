// bin: xb
// va: 0x0023E8B0
// tool: the portal's starter code (no AI)
// fight::ParamString<fight::EnterExitScriptTrack>::vfunc_00 (0x0023E8B0, 33 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.
// This function keeps a frame pointer (push ebp; mov ebp, esp), so it is built with them on.
#pragma optimize("y", off)

extern "C" void __cdecl sub_00027600(int);
extern "C" void __cdecl sub_0023EA70(void);

namespace fight { class EnterExitScriptTrack; }

namespace fight { 
template <class T0> class ParamString
{
public:
    virtual ParamString<fight::EnterExitScriptTrack>* vfunc_00(int a1);
};
}

template <> fight::ParamString<fight::EnterExitScriptTrack>* fight::ParamString<fight::EnterExitScriptTrack>::vfunc_00(int a1)
{
    sub_0023EA70();
    if (a1 & 1) {
        sub_00027600((int)this);
    }
    return this;
}
