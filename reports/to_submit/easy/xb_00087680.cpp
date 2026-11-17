// bin: xb
// va: 0x00087680
// tool: the portal's starter code (no AI)
// sub_00087680 (0x00087680, 39 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    virtual void vfunc_00();
    virtual void vfunc_01();
};

class Class_00087680
{
public:
    void sub_00087680();
    char m_pad00[0x8];
    int m_Field08; // +0x08
    char m_pad0C[0x6];
    bool m_Field12; // +0x12
    bool m_Field13; // +0x13
};

void Class_00087680::sub_00087680()
{
    int t1;

    if (m_Field13) {
        t1 = m_Field08;
        if (m_Field08) {
            ((Object*)t1)->vfunc_01();
            m_Field08 = 0;
        }
        m_Field12 = false;
        m_Field13 = false;
    }
}
