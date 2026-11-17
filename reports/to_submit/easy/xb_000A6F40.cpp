// bin: xb
// va: 0x000A6F40
// tool: the portal's starter code (no AI)
// sub_000A6F40 (0x000A6F40, 46 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" float DAT_0039D65C;
extern "C" float DAT_003A4980;

class Class_000A6F40
{
public:
    Class_000A6F40* sub_000A6F40();
    float m_Field00; // +0x00
    float m_Field04; // +0x04
    float m_Field08; // +0x08
    float m_Field0C; // +0x0C
    float m_Field10; // +0x10
};

Class_000A6F40* Class_000A6F40::sub_000A6F40()
{
    float t2;

    m_Field00 = DAT_003A4980;
    t2 = DAT_0039D65C;
    m_Field04 = t2;
    m_Field08 = 0.0f;
    m_Field0C = 0.0f;
    m_Field10 = t2;
    return this;
}
