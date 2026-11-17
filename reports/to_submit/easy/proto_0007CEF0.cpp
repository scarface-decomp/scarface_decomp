// bin: proto
// va: 0x0007CEF0
// tool: the portal's starter code (no AI)
// sub_0007CEF0 (0x0007CEF0, 26 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" float DAT_0037CE50;

class Class_0007CEF0
{
public:
    Class_0007CEF0* sub_0007CEF0();
    int m_Field00; // +0x00
    int m_Field04; // +0x04
    int m_Field08; // +0x08
    float m_Field0C; // +0x0C
};

Class_0007CEF0* Class_0007CEF0::sub_0007CEF0()
{
    float t1;

    t1 = DAT_0037CE50;
    m_Field00 = 0;
    m_Field04 = 0;
    m_Field08 = 0;
    m_Field0C = t1;
    return this;
}
