// bin: xb
// va: 0x000A71E0
// tool: the portal's starter code (no AI)
// sub_000A71E0 (0x000A71E0, 52 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" float DAT_0039D664;
extern "C" float DAT_003D0FE4;

class Class_000A71E0
{
public:
    Class_000A71E0* sub_000A71E0();
    int m_Field00; // +0x00
    int m_Field04; // +0x04
    int m_Field08; // +0x08
    int m_Field0C; // +0x0C
    float m_Field10; // +0x10
    float m_Field14; // +0x14
    float m_Field18; // +0x18
    float m_Field1C; // +0x1C
};

Class_000A71E0* Class_000A71E0::sub_000A71E0()
{
    float t2;

    m_Field10 = DAT_003D0FE4;
    t2 = DAT_0039D664;
    m_Field00 = 0;
    m_Field04 = 0;
    m_Field08 = 0;
    m_Field0C = 0;
    m_Field14 = t2;
    m_Field18 = t2;
    m_Field1C = t2;
    return this;
}
