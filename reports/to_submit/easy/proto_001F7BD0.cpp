// bin: proto
// va: 0x001F7BD0
// tool: the portal's starter code (no AI)
// sub_001F7BD0 (0x001F7BD0, 56 bytes)
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
    virtual void vfunc_21(int, int);
};

class Class_001F7BD0
{
public:
    void sub_001F7BD0(int a1, int a2);
};

void Class_001F7BD0::sub_001F7BD0(int a1, int a2)
{
    int r_ebx, r_esi, t1;

    if (a1) {
        r_ebx = *(int*)(a1 + 44);
        r_esi = 0;
        if (r_ebx > 0) {
            do {
                t1 = *(int*)(*(int*)(a1 + 48) + (r_esi * 4));
                if (*(int*)(*(int*)(a1 + 48) + (r_esi * 4))) {
                    ((Object*)t1)->vfunc_21(a2, (int)this);
                }
                r_esi += 1;
            } while (r_esi < r_ebx);
        }
    }
}
