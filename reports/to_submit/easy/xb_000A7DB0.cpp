// bin: xb
// va: 0x000A7DB0
// tool: the portal's starter code (no AI)
// sub_000A7DB0 (0x000A7DB0, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" float DAT_003A00FC;

class Class_000A7DB0
{
public:
    void sub_000A7DB0();
    float m_Field00; // +0x00
    float m_Field04; // +0x04
    float m_Field08; // +0x08
    float m_Field0C; // +0x0C
    float m_Field10; // +0x10
    float m_Field14; // +0x14
};

void Class_000A7DB0::sub_000A7DB0()
{
    float t1;

    t1 = DAT_003A00FC;
    m_Field00 = m_Field04 * t1;
    m_Field08 = m_Field0C * t1;
    m_Field10 = m_Field14 * t1;
}
