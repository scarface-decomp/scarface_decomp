// bin: xb
// va: 0x0018F0B0
// what: Forwards three arguments to virtual method slot 31 on the member pointer at +0x14 if non-null.
// tool: Gemini 4 Neon

struct Field14
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
    virtual void vfunc_31(int a1, int a2, int a3);
};

class Class_0018F0B0
{
public:
    void sub_0018F0B0(int a1, int a2, int a3);
    char m_pad00[0x14];
    Field14* m_Field14; // +0x14
};

void Class_0018F0B0::sub_0018F0B0(int a1, int a2, int a3)
{
    if (m_Field14) {
        m_Field14->vfunc_31(a1, a2, a3);
    }
}
