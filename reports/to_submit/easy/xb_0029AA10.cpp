// bin: xb
// va: 0x0029AA10
// tool: the portal's starter code (no AI)
// pure3d::d3dDisplay::vfunc_06 (0x0029AA10, 78 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.
// This function keeps a frame pointer (push ebp; mov ebp, esp), so it is built with them on.
#pragma optimize("y", off)

namespace pure3d {

class d3dDisplay
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual void vfunc_05();
    virtual bool vfunc_06(int a1, int a2, int a3);
};

bool d3dDisplay::vfunc_06(int a1, int a2, int a3)
{
    int r_ecx, r_edi, r_edx, r_esi;

    r_ecx = (int)this;
    r_edx = a1;
    r_esi = a3;
    r_edi = a2;
    if (a1 == *(int*)(r_ecx + 1148)) {
        if (a2 != *(int*)(r_ecx + 1144)) goto L_2E;
        if (a3 != *(int*)(r_ecx + 1152)) goto L_2E;
        return true;
    }
L_2E:
    *(int*)(r_ecx + 1084) = r_edx;
    r_edx = *(int*)r_ecx;
    *(int*)(r_ecx + 1088) = r_edi;
    *(int*)(r_ecx + 1092) = r_esi;
    return ((bool (__stdcall*)(int))*(int*)(r_edx + 20))(r_ecx + 1084);
}

}
