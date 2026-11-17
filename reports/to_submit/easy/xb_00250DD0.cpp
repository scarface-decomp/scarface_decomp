// bin: xb
// va: 0x00250DD0
// tool: the portal's starter code (no AI)
// pure3d::frontend::Project::vfunc_03 (0x00250DD0, 33 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.
// This function keeps a frame pointer (push ebp; mov ebp, esp), so it is built with them on.
#pragma optimize("y", off)

extern "C" void __cdecl sub_0023F7A0(int);
extern "C" void __cdecl sub_0024FB50(void);

namespace pure3d { namespace frontend {

class Project
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual Project* vfunc_03(int a1);
};

Project* Project::vfunc_03(int a1)
{
    sub_0024FB50();
    if (a1 & 1) {
        sub_0023F7A0((int)this);
    }
    return this;
}

} }
