// bin: xb
// va: 0x00286FC0
// tool: the portal's starter code (no AI)
// pure3d::PoseAnimationController::vfunc_07 (0x00286FC0, 95 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.
// This function keeps a frame pointer (push ebp; mov ebp, esp), so it is built with them on.
#pragma optimize("y", off)

struct Object
{
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
    virtual void vfunc_10();
    virtual void vfunc_11();
    virtual void vfunc_12();
    virtual int vfunc_13();
};

extern "C" char DAT_00419538[];
extern "C" char DAT_0041CF34[];
extern "C" char DAT_0045AC18[];
extern "C" int __cdecl sub_002FC034(int, int, int, int, int);

namespace pure3d {

class PoseAnimationController
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
    void sub_00286CF0(int);
};

void PoseAnimationController::vfunc_07(int a1)
{
    int r_edi, t1;

    r_edi = a1;
    t1 = sub_002FC034(a1, 0, (int)DAT_00419538, (int)DAT_0041CF34, 0);
    if (t1) {
        sub_00286CF0(((Object*)t1)->vfunc_13());
        return;
    }
    sub_00286CF0(sub_002FC034(r_edi, 0, (int)DAT_00419538, (int)DAT_0045AC18, 0));
}

}
