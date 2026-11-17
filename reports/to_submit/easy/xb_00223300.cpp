// bin: xb
// va: 0x00223300
// tool: the portal's starter code (no AI)
// sub_00223300 (0x00223300, 48 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_003D1BB4[];

class Class_00223300
{
public:
    Class_00223300* sub_00223300(int a1, int a2);
    void sub_0002BEE0(int, int);
    int m_Field00; // +0x00
    char m_pad04[0x1C];
    int m_Field20; // +0x20
    int m_Field24; // +0x24
    float m_Field28; // +0x28
};

Class_00223300* Class_00223300::sub_00223300(int a1, int a2)
{
    sub_0002BEE0(a1, a2);
    m_Field20 = 0;
    m_Field24 = 0;
    m_Field00 = (int)DAT_003D1BB4;
    m_Field28 = 0.0f;
    return this;
}
