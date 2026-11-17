// bin: xb
// va: 0x002850D0
// tool: the portal's starter code (no AI)
// pure3d::CharacterAnimationLayer::vfunc_07 (0x002850D0, 12 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.
// This function keeps a frame pointer (push ebp; mov ebp, esp), so it is built with them on.
#pragma optimize("y", off)

struct Object
{
    void sub_00285DE0(int);
};

namespace pure3d {

class CharacterAnimationLayer
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual void vfunc_05();
    virtual void vfunc_06();
    virtual void vfunc_07(int a1);
};

void CharacterAnimationLayer::vfunc_07(int a1)
{
    ((Object*)(int)this + 40)->sub_00285DE0(a1);
}

}
