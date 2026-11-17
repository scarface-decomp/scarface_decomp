// bin: xb
// va: 0x000A7010
// tool: the portal's starter code (no AI)
// sub_000A7010 (0x000A7010, 45 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" float DAT_0039D664;

class Class_000A7010
{
public:
    Class_000A7010* sub_000A7010();
    float m_Field00; // +0x00
    float m_Field04; // +0x04
    float m_Field08; // +0x08
    float m_Field0C; // +0x0C
    float m_Field10; // +0x10
    float m_Field14; // +0x14
    float m_Field18; // +0x18
};

Class_000A7010* Class_000A7010::sub_000A7010()
{
    float t1;

    t1 = DAT_0039D664;
    m_Field00 = t1;
    m_Field04 = t1;
    m_Field08 = t1;
    m_Field0C = t1;
    m_Field10 = t1;
    m_Field14 = t1;
    m_Field18 = t1;
    return this;
}
