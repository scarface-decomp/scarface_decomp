// bin: xb
// va: 0x0024EF70
// tool: the portal's starter code (no AI)
// sub_0024EF70 (0x0024EF70, 46 bytes)
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
};

void __stdcall sub_0024EF70(int a1, int a2)
{
    int r_edi, r_esi;

    if (a1 > 0) {
        r_esi = a2;
        r_esi += 4;
        r_edi = a1;
        do {
            if (*(bool*)(r_esi + -4)) {
                ((Object*)*(int*)r_esi)->vfunc_12();
            }
            r_esi += 8;
            r_edi -= 1;
        } while (r_edi);
    }
}
