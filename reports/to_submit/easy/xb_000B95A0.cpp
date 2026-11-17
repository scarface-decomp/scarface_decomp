// bin: xb
// va: 0x000B95A0
// tool: the portal's starter code (no AI)
// sub_000B95A0 (0x000B95A0, 52 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" float DAT_0039D664;

class Class_000B95A0
{
public:
    Class_000B95A0* sub_000B95A0();
    int m_Field00; // +0x00
    float m_Field04; // +0x04
    float m_Field08; // +0x08
    float m_Field0C; // +0x0C
    float m_Field10; // +0x10
    float m_Field14; // +0x14
    float m_Field18; // +0x18
    float m_Field1C; // +0x1C
};

Class_000B95A0* Class_000B95A0::sub_000B95A0()
{
    float t1;

    t1 = DAT_0039D664;
    m_Field00 = 0;
    m_Field04 = t1;
    m_Field08 = t1;
    m_Field0C = t1;
    m_Field10 = t1;
    m_Field14 = t1;
    m_Field18 = t1;
    m_Field1C = t1;
    return this;
}
