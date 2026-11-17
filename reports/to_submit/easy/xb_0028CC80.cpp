// bin: xb
// va: 0x0028CC80
// tool: the portal's starter code (no AI)
// pure3d::CameraAnimationController::vfunc_07 (0x0028CC80, 45 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.
// This function keeps a frame pointer (push ebp; mov ebp, esp), so it is built with them on.
#pragma optimize("y", off)

extern "C" char DAT_00419538[];
extern "C" char DAT_0041A57C[];
extern "C" int __cdecl sub_002FC034(int, int, int, int, int);

namespace pure3d {

class CameraAnimationController
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
    void sub_0028C530(int);
};

void CameraAnimationController::vfunc_07(int a1)
{
    sub_0028C530(sub_002FC034(a1, 0, (int)DAT_00419538, (int)DAT_0041A57C, 0));
}

}
