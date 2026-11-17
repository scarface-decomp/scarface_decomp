// bin: xb
// va: 0x001A5F10
// tool: the portal's starter code (no AI)
// sub_001A5F10 (0x001A5F10, 93 bytes)
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
    virtual void vfunc_35();
    virtual void vfunc_36();
    virtual void vfunc_37();
    virtual void vfunc_38();
    virtual void vfunc_39();
    virtual void vfunc_40();
    virtual void vfunc_41();
    virtual void vfunc_42();
    virtual void vfunc_43();
    virtual void vfunc_44();
    virtual void vfunc_45();
    virtual void vfunc_46();
    virtual void vfunc_47();
    virtual void vfunc_48();
    virtual void vfunc_49();
    virtual void vfunc_50();
    virtual void vfunc_51();
    virtual void vfunc_52();
    virtual void vfunc_53();
    virtual void vfunc_54();
    virtual void vfunc_55();
    virtual void vfunc_56();
    virtual void vfunc_57();
    virtual void vfunc_58();
    virtual void vfunc_59();
    virtual void vfunc_60();
    virtual void vfunc_61();
    virtual void vfunc_62(int, int);
};

extern "C" int DAT_0048A9D8;

class Class_001A5F10
{
public:
    void sub_001A5F10(int a1, int a2);
};

void Class_001A5F10::sub_001A5F10(int a1, int a2)
{
    int r_eax, r_ecx;

    r_ecx = (int)this;
    r_eax = a1;
    *(int*)(r_ecx + 360) = a1;
    *(int*)(r_ecx + 364) = a2;
    r_ecx = DAT_0048A9D8;
    if (r_ecx) {
        if (a1 == 223) {
            r_eax = *(int*)r_ecx;
            a2 = 4;
            a1 = 1;
            ((void (__stdcall*)(int, int))*(int*)(r_eax + 248))(a1, a2);
            return;
        }
        if (r_eax != -1) goto L_5A;
        a2 = 4;
        a1 = 0;
        ((Object*)r_ecx)->vfunc_62(a1, a2);
        return;
    }
L_5A:
    ;
}
