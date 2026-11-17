// bin: proto
// va: 0x000413C0
// tool: the portal's starter code (no AI)
// sub_000413C0 (0x000413C0, 43 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

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
    virtual void vfunc_12(int);
};

void __cdecl sub_000413C0(int a1, int a2)
{
    int t1;

    if (a1) {
        t1 = *(int*)(a1 + 4);
        if (!*(int*)(a1 + 4)) goto L_2A;
        if (*(int*)(t1 + 100) != *(int*)(a1 + 8)) goto L_2A;
        if (*(int*)(t1 + 84) == 8192) goto L_2A;
        ((Object*)t1)->vfunc_12(a2);
    }
L_2A:
    ;
}
