// bin: proto
// va: 0x0025DF20
// tool: the portal's starter code (no AI)
// pure3d::d3dDisplay::vfunc_05 (0x0025DF20, 76 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

namespace pure3d {

class d3dDisplay
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual bool vfunc_05(int a1, int a2, int a3);
};

bool d3dDisplay::vfunc_05(int a1, int a2, int a3)
{
    int r_ecx, r_edx;

    r_ecx = (int)this;
    r_edx = a1;
    if (a1 == *(int*)(r_ecx + 1148)) {
        if (a2 != *(int*)(r_ecx + 1144)) goto L_2D;
        if (a3 != *(int*)(r_ecx + 1152)) goto L_2D;
        return true;
    }
L_2D:
    *(int*)(r_ecx + 1084) = r_edx;
    r_edx = *(int*)r_ecx;
    *(int*)(r_ecx + 1088) = a2;
    *(int*)(r_ecx + 1092) = a3;
    return ((bool (__stdcall*)(int))*(int*)(r_edx + 16))(r_ecx + 1084);
}

}
