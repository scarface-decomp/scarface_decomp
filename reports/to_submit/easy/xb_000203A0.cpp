// bin: xb
// va: 0x000203A0
// tool: the portal's starter code (no AI)
// sub_000203A0 (0x000203A0, 58 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    virtual void vfunc_00();
    virtual void vfunc_01();
};

class Class_000203A0
{
public:
    void sub_000203A0();
    char m_pad00[0x10];
    int m_Field10; // +0x10
    int m_Field14; // +0x14
    char m_pad18[0x8];
    int m_Field20; // +0x20
    float m_Field24; // +0x24
};

void Class_000203A0::sub_000203A0()
{
    int t1, t3;

    t1 = m_Field10;
    if (m_Field10) {
        ((Object*)t1)->vfunc_01();
        m_Field10 = 0;
    }
    t3 = m_Field14;
    if (m_Field14) {
        ((Object*)t3)->vfunc_01();
        m_Field14 = 0;
    }
    m_Field20 = 0;
    m_Field24 = 0.0f;
}
