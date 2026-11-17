// bin: xb
// va: 0x002ACB10
// tool: the portal's starter code (no AI)
// sub_002ACB10 (0x002ACB10, 52 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field6C
{
    virtual void vfunc_00();
    virtual void vfunc_01();
};

struct Object
{
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04(int);
};

class Class_002ACB10
{
public:
    void sub_002ACB10(int a1);
    char m_pad00[0x20];
    int m_Field20; // +0x20
    char m_pad24[0x48];
    Field6C* m_Field6C; // +0x6C
    int m_Field70; // +0x70
};

void Class_002ACB10::sub_002ACB10(int a1)
{
    Field6C* t1;

    t1 = m_Field6C;
    m_Field20 = a1;
    if (m_Field6C) {
        ((Object*)(int)t1)->vfunc_04(m_Field70);
        m_Field6C->vfunc_01();
        m_Field6C = 0;
        m_Field70 = 0;
    }
}
