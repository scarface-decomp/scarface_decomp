// bin: xb
// va: 0x00023120
// tool: the portal's starter code (no AI)
// sub_00023120 (0x00023120, 45 bytes)
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

struct Field2C
{
    void sub_0024A390(int, int, int);
};

class Class_00023120
{
public:
    void sub_00023120(int a1, int a2, int a3);
    char m_pad00[0x20];
    Field20* m_Field20; // +0x20
    bool m_Field24; // +0x24
    char m_pad25[0x7];
    Field2C* m_Field2C; // +0x2C
};

void Class_00023120::sub_00023120(int a1, int a2, int a3)
{
    m_Field2C->sub_0024A390(a1, a2, a3);
    if (m_Field24) {
        m_Field20->vfunc_08();
    }
}
