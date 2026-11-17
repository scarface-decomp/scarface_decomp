// bin: xb
// va: 0x000A8FB0
// tool: the portal's starter code (no AI)
// sub_000A8FB0 (0x000A8FB0, 62 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" float DAT_0039D580;
extern "C" float DAT_0039D65C;
extern "C" float DAT_003A4AD4;
extern "C" float DAT_003A4C8C;

class Class_000A8FB0
{
public:
    Class_000A8FB0* sub_000A8FB0();
    float m_Field00; // +0x00
    float m_Field04; // +0x04
    float m_Field08; // +0x08
    float m_Field0C; // +0x0C
    float m_Field10; // +0x10
};

Class_000A8FB0* Class_000A8FB0::sub_000A8FB0()
{
    m_Field00 = 0.0f;
    m_Field04 = DAT_0039D65C;
    m_Field08 = DAT_003A4AD4;
    m_Field0C = DAT_0039D580;
    m_Field10 = DAT_003A4C8C;
    return this;
}
