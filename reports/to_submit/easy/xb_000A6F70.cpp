// bin: xb
// va: 0x000A6F70
// tool: the portal's starter code (no AI)
// sub_000A6F70 (0x000A6F70, 36 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" float DAT_003A48F4;

class Class_000A6F70
{
public:
    void sub_000A6F70();
    float m_Field00; // +0x00
    float m_Field04; // +0x04
    float m_Field08; // +0x08
    float m_Field0C; // +0x0C
};

void Class_000A6F70::sub_000A6F70()
{
    float t1;

    t1 = DAT_003A48F4;
    m_Field04 = m_Field00 * t1;
    m_Field0C = m_Field08 * t1;
}
