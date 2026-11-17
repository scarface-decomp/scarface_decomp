// bin: proto
// va: 0x0007D0F0
// tool: the portal's starter code (no AI)
// sub_0007D0F0 (0x0007D0F0, 42 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" float DAT_0037CE50;
extern "C" float DAT_003850D4;

class Class_0007D0F0
{
public:
    Class_0007D0F0* sub_0007D0F0();
    float m_Field00; // +0x00
    bool m_Field04; // +0x04
    char m_pad05[0x3];
    float m_Field08; // +0x08
    float m_Field0C; // +0x0C
    float m_Field10; // +0x10
};

Class_0007D0F0* Class_0007D0F0::sub_0007D0F0()
{
    float t2;

    m_Field00 = DAT_003850D4;
    t2 = DAT_0037CE50;
    m_Field04 = false;
    m_Field08 = t2;
    m_Field0C = t2;
    m_Field10 = t2;
    return this;
}
