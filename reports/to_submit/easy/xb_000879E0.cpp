// bin: xb
// va: 0x000879E0
// tool: the portal's starter code (no AI)
// sub_000879E0 (0x000879E0, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    virtual void vfunc_00();
    virtual void vfunc_01();
};

class Class_000879E0
{
public:
    void sub_000879E0();
    unsigned char m_Field00; // +0x00
    char m_pad01[0x7];
    int m_Field08; // +0x08
    char m_pad0C[0x14];
    int m_Field20; // +0x20
    int m_Field24; // +0x24
    unsigned char m_Field28; // +0x28
};

void Class_000879E0::sub_000879E0()
{
    int t1;

    if (m_Field00) {
        m_Field28 &= 253;
        t1 = m_Field20;
        if (m_Field20) {
            ((Object*)t1)->vfunc_01();
            m_Field20 = 0;
        }
        m_Field08 = 0;
        m_Field24 = 0;
        m_Field00 = 0;
    }
}
