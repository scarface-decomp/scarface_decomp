// bin: xb
// va: 0x0028D4D0
// tool: the portal's starter code (no AI)
// pure3d::frontend::Child::vfunc_03 (0x0028D4D0, 39 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.
// This function keeps a frame pointer (push ebp; mov ebp, esp), so it is built with them on.
#pragma optimize("y", off)

extern "C" char DAT_003D86FC[];
extern "C" void __cdecl sub_0023F7A0(int);
extern "C" void __cdecl sub_002A6940(void);

namespace pure3d { namespace frontend {

class Child
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual Child* vfunc_03(int a1);
};

Child* Child::vfunc_03(int a1)
{
    *(int*)this = (int)DAT_003D86FC;
    sub_002A6940();
    if (a1 & 1) {
        sub_0023F7A0((int)this);
    }
    return this;
}

} }
