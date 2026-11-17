// bin: xb
// va: 0x000206F0
// tool: the portal's starter code (no AI)
// sub_000206F0 (0x000206F0, 66 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field08
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
    virtual int vfunc_16(int);
};

struct Object
{
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual void vfunc_05();
    virtual int vfunc_06(int);
};

extern "C" int __cdecl sub_00247970(void);

class Class_000206F0
{
public:
    void sub_000206F0();
    int m_Field00; // +0x00
    int m_Field04; // +0x04
    Field08* m_Field08; // +0x08
    int m_Field0C; // +0x0C
};

void Class_000206F0::sub_000206F0()
{
    int t3, t6;

    if (!m_Field08) {
        t3 = ((Object*)sub_00247970())->vfunc_06(m_Field00);
        m_Field08 = (Field08*)t3;
        if (!t3) goto L_40;
        ((Object*)t3)->vfunc_00();
        t6 = m_Field08->vfunc_16(m_Field04);
        m_Field0C = t6;
        if (!t6) goto L_40;
        ((Object*)t6)->vfunc_00();
        return;
    }
L_40:
    ;
}
