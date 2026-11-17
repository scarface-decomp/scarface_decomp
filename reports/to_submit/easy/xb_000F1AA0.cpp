// bin: xb
// va: 0x000F1AA0
// tool: the portal's starter code (no AI)
// sub_000F1AA0 (0x000F1AA0, 69 bytes)
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
    virtual void vfunc_29(int);
};

extern "C" int __cdecl sub_0002AC90(int);

class Class_000F1AA0
{
public:
    void sub_000F1AA0(int a1);
    char m_pad00[0x98];
    int m_Field98; // +0x98
};

void Class_000F1AA0::sub_000F1AA0(int a1)
{
    if (!sub_0002AC90(m_Field98)) goto L_41;
    if (a1) {
        if (*(int*)(a1 + 172)) goto L_40;
        ((Object*)sub_0002AC90(m_Field98))->vfunc_29(a1);
    }
L_40:
L_41:
    ;
}
