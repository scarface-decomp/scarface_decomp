// bin: proto
// va: 0x00097410
// tool: the portal's starter code (no AI)
// sub_00097410 (0x00097410, 25 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" float DAT_0037CE50;

class Class_00097410
{
public:
    void sub_00097410();
    float m_Field00; // +0x00
    bool m_Field04; // +0x04
    char m_pad05[0x3];
    float m_Field08; // +0x08
};

void Class_00097410::sub_00097410()
{
    m_Field00 = DAT_0037CE50;
    m_Field04 = false;
    m_Field08 = 0.0f;
}
