// bin: xb
// va: 0x000118D0
// tool: the portal's starter code (no AI)
// sub_000118D0 (0x000118D0, 49 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

class Class_000118D0
{
public:
    void sub_000118D0(float a1);
    float m_Field00; // +0x00
    float m_Field04; // +0x04
    float m_Field08; // +0x08
};

void Class_000118D0::sub_000118D0(float a1)
{
    m_Field00 = m_Field00 * a1;
    m_Field04 = m_Field04 * a1;
    m_Field08 = m_Field08 * a1;
}
