// bin: xb
// va: 0x000A3460
// tool: the portal's starter code (no AI)
// sub_000A3460 (0x000A3460, 27 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" float DAT_0039D664;

class Class_000A3460
{
public:
    Class_000A3460* sub_000A3460();
    float m_Field00; // +0x00
    bool m_Field04; // +0x04
    char m_pad05[0x3];
    float m_Field08; // +0x08
};

Class_000A3460* Class_000A3460::sub_000A3460()
{
    m_Field00 = DAT_0039D664;
    m_Field04 = false;
    m_Field08 = 0.0f;
    return this;
}
