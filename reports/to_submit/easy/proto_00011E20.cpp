// bin: proto
// va: 0x00011E20
// tool: the portal's starter code (no AI)
// sub_00011E20 (0x00011E20, 49 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

class Class_00011E20
{
public:
    void sub_00011E20(float a1);
    float m_Field00; // +0x00
    float m_Field04; // +0x04
    float m_Field08; // +0x08
};

void Class_00011E20::sub_00011E20(float a1)
{
    m_Field00 = m_Field00 * a1;
    m_Field04 = m_Field04 * a1;
    m_Field08 = m_Field08 * a1;
}
