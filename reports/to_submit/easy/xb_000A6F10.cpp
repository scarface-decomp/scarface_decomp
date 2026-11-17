// bin: xb
// va: 0x000A6F10
// tool: the portal's starter code (no AI)
// sub_000A6F10 (0x000A6F10, 43 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" float DAT_0039D65C;
extern "C" float DAT_0039D664;

class Class_000A6F10
{
public:
    Class_000A6F10* sub_000A6F10();
    float m_Field00; // +0x00
    float m_Field04; // +0x04
    float m_Field08; // +0x08
    int m_Field0C; // +0x0C
};

Class_000A6F10* Class_000A6F10::sub_000A6F10()
{
    m_Field00 = DAT_0039D65C;
    m_Field04 = DAT_0039D664;
    m_Field08 = 0.0f;
    m_Field0C = 0;
    return this;
}
