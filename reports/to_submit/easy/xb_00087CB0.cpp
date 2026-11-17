// bin: xb
// va: 0x00087CB0
// tool: the portal's starter code (no AI)
// sub_00087CB0 (0x00087CB0, 87 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field4C
{
    void sub_002A9290();
};

struct Object
{
    virtual void vfunc_00();
    virtual void vfunc_01();
};

extern "C" void __cdecl sub_00087780(void);

class Class_00087CB0
{
public:
    void sub_00087CB0();
    bool m_Field00; // +0x00
    char m_pad01[0x3];
    unsigned char m_Field04; // +0x04
    char m_pad05[0x7];
    int m_Field0C; // +0x0C
    char m_pad10[0x14];
    int m_Field24; // +0x24
    int m_Field28; // +0x28
    unsigned char m_Field2C; // +0x2C
    char m_pad2D[0x13];
    int m_Field40; // +0x40
    char m_pad44[0x6];
    bool m_Field4A; // +0x4A
    unsigned char m_Field4B; // +0x4B
    Field4C m_Field4C; // +0x4C
};

void Class_00087CB0::sub_00087CB0()
{
    int t3, t5;

    if (m_Field00) {
        sub_00087780();
    }
    m_Field4C.sub_002A9290();
    if (m_Field4B) {
        t3 = m_Field40;
        if (m_Field40) {
            ((Object*)t3)->vfunc_01();
            m_Field40 = 0;
        }
        m_Field4A = false;
        m_Field4B = 0;
    }
    if (m_Field04) {
        m_Field2C &= 253;
        t5 = m_Field24;
        if (m_Field24) {
            ((Object*)t5)->vfunc_01();
            m_Field24 = 0;
        }
        m_Field0C = 0;
        m_Field28 = 0;
        m_Field04 = 0;
    }
}
