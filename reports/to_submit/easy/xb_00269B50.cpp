// bin: xb
// va: 0x00269B50
// tool: the portal's starter code (no AI)
// pure3d::d3dExtUnLitColourTint::vfunc_02 (0x00269B50, 19 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.
// This function keeps a frame pointer (push ebp; mov ebp, esp), so it is built with them on.
#pragma optimize("y", off)

extern "C" void __cdecl sub_0029F7C0(int);

namespace pure3d {

class d3dExtUnLitColourTint
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02(int a1);
};

void d3dExtUnLitColourTint::vfunc_02(int a1)
{
    sub_0029F7C0(a1);
}

}
