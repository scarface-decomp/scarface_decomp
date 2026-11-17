// bin: proto
// va: 0x00181340
// tool: the portal's starter code (no AI)
// sub_00181340 (0x00181340, 52 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0039B264[];

class Class_00181340
{
public:
    Class_00181340* sub_00181340(int a1, int a2);
    void sub_00028470(int, int);
    int m_Field00; // +0x00
    char m_pad04[0x1C];
    int m_Field20; // +0x20
    float m_Field24; // +0x24
    int m_Field28; // +0x28
    char m_pad2C[0x4];
    unsigned char m_Field30; // +0x30
};

Class_00181340* Class_00181340::sub_00181340(int a1, int a2)
{
    sub_00028470(a1, a2);
    m_Field20 = 0;
    m_Field28 = 0;
    m_Field30 |= 1;
    m_Field00 = (int)DAT_0039B264;
    m_Field24 = 0.0f;
    return this;
}
