// bin: xb
// va: 0x000B9950
// tool: the portal's starter code (no AI)
// sub_000B9950 (0x000B9950, 41 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" float DAT_0039D65C;

class Class_000B9950
{
public:
    Class_000B9950* sub_000B9950();
    float m_Field00; // +0x00
    float m_Field04; // +0x04
    float m_Field08; // +0x08
    float m_Field0C; // +0x0C
    int m_Field10; // +0x10
    int m_Field14; // +0x14
};

Class_000B9950* Class_000B9950::sub_000B9950()
{
    m_Field00 = 0.0f;
    m_Field04 = 0.0f;
    m_Field08 = 0.0f;
    m_Field0C = DAT_0039D65C;
    m_Field10 = 0;
    m_Field14 = 0;
    return this;
}
