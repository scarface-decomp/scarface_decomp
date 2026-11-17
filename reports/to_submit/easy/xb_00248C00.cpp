// bin: xb
// va: 0x00248C00
// tool: the portal's starter code (no AI)
// pure3d::frontend::Drawable::vfunc_03 (0x00248C00, 39 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.
// This function keeps a frame pointer (push ebp; mov ebp, esp), so it is built with them on.
#pragma optimize("y", off)

extern "C" char DAT_003D4F14[];
extern "C" void __cdecl sub_0023F7A0(int);
extern "C" void __cdecl sub_0028D470(void);

namespace pure3d { namespace frontend {

class Drawable
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual Drawable* vfunc_03(int a1);
};

Drawable* Drawable::vfunc_03(int a1)
{
    *(int*)this = (int)DAT_003D4F14;
    sub_0028D470();
    if (a1 & 1) {
        sub_0023F7A0((int)this);
    }
    return this;
}

} }
