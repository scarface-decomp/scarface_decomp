// bin: xb
// va: 0x002A0700
// tool: the portal's starter code (no AI)
// pure3d::d3dExtXboxControl::vfunc_01 (0x002A0700, 15 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.
// This function keeps a frame pointer (push ebp; mov ebp, esp), so it is built with them on.
#pragma optimize("y", off)

extern "C" int DAT_0045C340;

namespace pure3d {

class d3dExtXboxControl
{
public:
    virtual void vfunc_00();
    virtual int vfunc_01(int a1);
};

int d3dExtXboxControl::vfunc_01(int a1)
{
    DAT_0045C340 = a1;
    return a1;
}

}
