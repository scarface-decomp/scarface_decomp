// bin: xb
// va: 0x00267E90
// tool: the portal's starter code (no AI)
// pure3d::d3dExtAntialiasControl::vfunc_03 (0x00267E90, 9 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.
// This function keeps a frame pointer (push ebp; mov ebp, esp), so it is built with them on.
#pragma optimize("y", off)

extern "C" void __stdcall sub_0032DE90(int);

namespace pure3d {

class d3dExtAntialiasControl
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03(int a1);
};

void d3dExtAntialiasControl::vfunc_03(int a1)
{
    sub_0032DE90(a1);
}

}
