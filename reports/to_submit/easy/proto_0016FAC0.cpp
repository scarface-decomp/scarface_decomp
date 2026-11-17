// bin: proto
// va: 0x0016FAC0
// tool: the portal's starter code (no AI)
// sub_0016FAC0 (0x0016FAC0, 52 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0039861C[];

class Class_0016FAC0
{
public:
    Class_0016FAC0* sub_0016FAC0();
    int m_Field00; // +0x00
    float m_Field04; // +0x04
    float m_Field08; // +0x08
    int m_Field0C; // +0x0C
    int m_Field10; // +0x10
    int m_Field14; // +0x14
    int m_Field18; // +0x18
    int m_Field1C; // +0x1C
    int m_Field20; // +0x20
    char m_pad24[0x4];
    int m_Field28; // +0x28
    int m_Field2C; // +0x2C
};

Class_0016FAC0* Class_0016FAC0::sub_0016FAC0()
{
    m_Field00 = (int)DAT_0039861C;
    m_Field04 = 0.0f;
    m_Field08 = 0.0f;
    m_Field0C = 0;
    m_Field20 = 0;
    m_Field28 = -1;
    m_Field2C = 0;
    m_Field10 = 0;
    m_Field14 = 0;
    m_Field18 = 0;
    m_Field1C = 0;
    return this;
}
