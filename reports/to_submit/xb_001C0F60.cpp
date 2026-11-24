// bin: xb
// va: 0x001C0F60
// what: Calls virtual method slot 29 with argument 0 on the member pointer at +0x84 if non-null.
// tool: Gemini 4 Neon

struct Field84_001C0F60
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
    virtual void vfunc_29(int a1);
};

class Class_001C0F60
{
public:
    void sub_001C0F60();
    char m_pad00[0x84];
    Field84_001C0F60* m_Field84; // +0x84
};

void Class_001C0F60::sub_001C0F60()
{
    if (m_Field84) {
        m_Field84->vfunc_29(0);
    }
}
