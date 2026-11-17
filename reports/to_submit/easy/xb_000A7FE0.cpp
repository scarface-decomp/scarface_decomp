// bin: xb
// va: 0x000A7FE0
// tool: the portal's starter code (no AI)
// sub_000A7FE0 (0x000A7FE0, 40 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" float DAT_0039D65C;

class Class_000A7FE0
{
public:
    Class_000A7FE0* sub_000A7FE0();
    float m_Field00; // +0x00
    int m_Field04; // +0x04
    float m_Field08; // +0x08
    int m_Field0C; // +0x0C
    int m_Field10; // +0x10
    int m_Field14; // +0x14
    int m_Field18; // +0x18
    int m_Field1C; // +0x1C
};

Class_000A7FE0* Class_000A7FE0::sub_000A7FE0()
{
    float t1;

    t1 = DAT_0039D65C;
    m_Field00 = t1;
    m_Field04 = 0;
    m_Field08 = t1;
    m_Field0C = 0;
    m_Field10 = 0;
    m_Field14 = 0;
    m_Field18 = 0;
    m_Field1C = 0;
    return this;
}
