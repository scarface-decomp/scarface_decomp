// bin: xb
// va: 0x0018BA50
// tool: the portal's starter code (no AI)
// sub_0018BA50 (0x0018BA50, 50 bytes)
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
    virtual void vfunc_17(int);
};

class Class_0018BA50
{
public:
    void sub_0018BA50();
    void sub_0018B410(int);
    char m_pad00[0xA8];
    int m_FieldA8; // +0xA8
    char m_padAC[0x15];
    bool m_FieldC1; // +0xC1
};

void Class_0018BA50::sub_0018BA50()
{
    int t1;

    if (m_FieldC1) {
        t1 = m_FieldA8;
        if (m_FieldA8) {
            ((Object*)t1)->vfunc_17(0);
        }
        m_FieldC1 = false;
        return;
    }
    sub_0018B410(1);
}
