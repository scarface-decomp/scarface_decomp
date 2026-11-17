// bin: proto
// va: 0x0004EA40
// tool: the portal's starter code (no AI)
// sub_0004EA40 (0x0004EA40, 30 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

class Class_0004EA40
{
public:
    void sub_0004EA40(float a1);
    char m_pad00[0x68];
    float m_Field68; // +0x68
    float m_Field6C; // +0x6C
    char m_pad70[0xC];
    unsigned char m_Field7C; // +0x7C
};

void Class_0004EA40::sub_0004EA40(float a1)
{
    unsigned char t1;

    t1 = m_Field7C;
    m_Field6C = 0.0f;
    m_Field68 = a1;
    m_Field7C = (unsigned char)(t1 | 4);
}
