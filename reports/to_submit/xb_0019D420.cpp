// bin: xb
// va: 0x0019D420
// what: Forwards one argument to virtual method slot 17 on the member pointer at +0x04 if non-null.
// tool: Gemini 4 Neon

struct Field04_0019D420
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
    virtual void vfunc_17(int a1);
};

class Class_0019D420
{
public:
    void sub_0019D420(int a1);
    char m_pad00[0x4];
    Field04_0019D420* m_Field04; // +0x04
};

void Class_0019D420::sub_0019D420(int a1)
{
    if (m_Field04) {
        m_Field04->vfunc_17(a1);
    }
}
