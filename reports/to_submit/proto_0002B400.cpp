// bin: proto
// va: 0x0002B400
// what: 
// tool: the portal's starter code (no AI)

// sub_0002B400 (Proto 0x0002B400, 18 bytes)
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
    virtual void vfunc_12();
    virtual void vfunc_13(int);
};

void __cdecl sub_0002B400(int a1, int a2, int a3)
{
    ((Object*)a1)->vfunc_13(*(int*)(a3 + 4));
}
