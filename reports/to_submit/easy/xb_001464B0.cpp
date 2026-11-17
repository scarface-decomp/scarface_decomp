// bin: xb
// va: 0x001464B0
// tool: the portal's starter code (no AI)
// sub_001464B0 (0x001464B0, 39 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

class Class_001464B0
{
public:
    void sub_001464B0();
    char m_pad00[0x7C];
    float m_Field7C; // +0x7C
    float m_Field80; // +0x80
    float m_Field84; // +0x84
    char m_pad88[0xE9];
    unsigned char m_Field171; // +0x171
};

void Class_001464B0::sub_001464B0()
{
    m_Field171 = (unsigned char)(m_Field171 & 143);
    m_Field7C = 0.0f;
    m_Field80 = 0.0f;
    m_Field84 = 0.0f;
}
