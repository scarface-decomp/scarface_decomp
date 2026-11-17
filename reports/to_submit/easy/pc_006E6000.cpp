// bin: pc
// va: 0x006E6000
// tool: the portal's starter code (no AI)
// sub_006E6000 (0x006E6000, 38 bytes)
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
    virtual void vfunc_13();
    virtual void vfunc_14();
    virtual void vfunc_15();
    virtual void vfunc_16();
    virtual void vfunc_17();
    virtual void vfunc_18();
    virtual void vfunc_19();
    virtual void vfunc_20();
    virtual void vfunc_21();
    virtual void vfunc_22();
    virtual void vfunc_23(int);
};

extern "C" void __cdecl sub_006E7DE0(int, int, int);

void __cdecl sub_006E6000(int a1, int a2, int a3, int a4)
{
    sub_006E7DE0(a1, a2, a3);
    ((Object*)*(int*)a1)->vfunc_23(a4);
}
