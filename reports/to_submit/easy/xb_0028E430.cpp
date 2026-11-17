// bin: xb
// va: 0x0028E430
// tool: the portal's starter code (no AI)
// pure3d::frontend::Layer::vfunc_03 (0x0028E430, 39 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.
// This function keeps a frame pointer (push ebp; mov ebp, esp), so it is built with them on.
#pragma optimize("y", off)

extern "C" char DAT_003D88A8[];
extern "C" void __cdecl sub_0023F7A0(int);
extern "C" void __cdecl sub_0028D930(void);

namespace pure3d { namespace frontend {

class Layer
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual Layer* vfunc_03(int a1);
};

Layer* Layer::vfunc_03(int a1)
{
    *(int*)this = (int)DAT_003D88A8;
    sub_0028D930();
    if (a1 & 1) {
        sub_0023F7A0((int)this);
    }
    return this;
}

} }
