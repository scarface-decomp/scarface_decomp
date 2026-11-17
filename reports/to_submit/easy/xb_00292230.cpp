// bin: xb
// va: 0x00292230
// tool: the portal's starter code (no AI)
// pure3d::AdaptPDDI::vfunc_00 (0x00292230, 19 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.
// This function keeps a frame pointer (push ebp; mov ebp, esp), so it is built with them on.
#pragma optimize("y", off)

extern "C" void __cdecl sub_002A9290(int);

namespace pure3d {

class AdaptPDDI
{
public:
    virtual void vfunc_00(int a1);
};

void AdaptPDDI::vfunc_00(int a1)
{
    sub_002A9290(a1);
}

}
