// bin: xb
// va: 0x000400D0
// tool: the portal's starter code (no AI)
// sub_000400D0 (0x000400D0, 62 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    virtual void vfunc_00();
    virtual void vfunc_01();
    void sub_0003FF40(int);
};

extern "C" char DAT_0039E22C[];
extern "C" char DAT_003A030C[];
extern "C" int DAT_00474E38;

class Class_000400D0
{
public:
    void sub_000400D0();
    int m_Field00; // +0x00
    char m_pad04[0x8];
    int m_Field0C; // +0x0C
    char m_pad10[0xC];
    unsigned char m_Field1C; // +0x1C
};

void Class_000400D0::sub_000400D0()
{
    int t2;

    m_Field00 = (int)DAT_003A030C;
    if (DAT_00474E38) {
        if (!(m_Field1C & 2)) goto L_23;
        ((Object*)DAT_00474E38)->sub_0003FF40((int)this);
        m_Field1C &= 253;
    }
L_23:
    t2 = m_Field0C;
    if (m_Field0C) {
        ((Object*)t2)->vfunc_01();
        m_Field0C = 0;
    }
    m_Field00 = (int)DAT_0039E22C;
}
