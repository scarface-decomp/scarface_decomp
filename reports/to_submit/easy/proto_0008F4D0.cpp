// bin: proto
// va: 0x0008F4D0
// tool: the portal's starter code (no AI)
// sub_0008F4D0 (0x0008F4D0, 33 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" float DAT_0037CE50;

class Class_0008F4D0
{
public:
    Class_0008F4D0* sub_0008F4D0();
    float m_Field00; // +0x00
    float m_Field04; // +0x04
    float m_Field08; // +0x08
    float m_Field0C; // +0x0C
};

Class_0008F4D0* Class_0008F4D0::sub_0008F4D0()
{
    m_Field00 = 0.0f;
    m_Field04 = 0.0f;
    m_Field08 = 0.0f;
    m_Field0C = DAT_0037CE50;
    return this;
}
