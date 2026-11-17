// bin: xb
// va: 0x00023320
// tool: the portal's starter code (no AI)
// sub_00023320 (0x00023320, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field20
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
};

struct Field28
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
};

class Class_00023320
{
public:
    void sub_00023320();
    char m_pad00[0x20];
    Field20* m_Field20; // +0x20
    bool m_Field24; // +0x24
    char m_pad25[0x3];
    Field28* m_Field28; // +0x28
};

void Class_00023320::sub_00023320()
{
    m_Field28->vfunc_16();
    if (m_Field24) {
        m_Field20->vfunc_08();
        return;
    }
}
