// bin: xb
// va: 0x00292670
// tool: the portal's starter code (no AI)
// pure3d::SpriteObject::vfunc_10 (0x00292670, 9 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.
// This function keeps a frame pointer (push ebp; mov ebp, esp), so it is built with them on.
#pragma optimize("y", off)

extern "C" void __stdcall sub_0025A690(int);

namespace pure3d {

class SpriteObject
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
    virtual void vfunc_08();
    virtual void vfunc_09();
    virtual void vfunc_10(int a1);
};

void SpriteObject::vfunc_10(int a1)
{
    sub_0025A690(a1);
}

}
