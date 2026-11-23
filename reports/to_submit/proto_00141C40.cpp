// bin: proto
// va: 0x00141C40
// what: 
// tool: the portal's starter code (no AI)

// sub_00141C40 (Proto 0x00141C40, 57 bytes)
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
    virtual void vfunc_23();
    virtual void vfunc_24();
    virtual void vfunc_25();
    virtual void vfunc_26();
    virtual void vfunc_27();
    virtual void vfunc_28();
    virtual void vfunc_29();
    virtual void vfunc_30();
    virtual void vfunc_31();
    virtual void vfunc_32();
    virtual void vfunc_33();
    virtual void vfunc_34();
    virtual void vfunc_35(int);
};

extern "C" int __cdecl sub_00028CF0(int, int);
extern "C" int __cdecl sub_002C96FE(int);

void __cdecl sub_00141C40(int a1, int a2, int a3)
{
    int r_eax;

    r_eax = *(int*)(a3 + 8);
    r_eax = sub_002C96FE(r_eax);
    if (r_eax <= 0) {
        r_eax = *(int*)(a3 + 8);
        r_eax = sub_00028CF0(r_eax, 0);
        if (!r_eax) goto L_37;
        r_eax = *(int*)(r_eax + 16);
    }
    ((Object*)a1)->vfunc_35(r_eax);
L_37:
    ;
}
