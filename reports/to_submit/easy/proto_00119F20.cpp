// bin: proto
// va: 0x00119F20
// tool: the portal's starter code (no AI)
// sub_00119F20 (0x00119F20, 43 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0038F7D0[];

class Class_00119F20
{
public:
    Class_00119F20* sub_00119F20(int a1);
    int m_Field00; // +0x00
    int m_Field04; // +0x04
    int m_Field08; // +0x08
    float m_Field0C; // +0x0C
    float m_Field10; // +0x10
    float m_Field14; // +0x14
};

Class_00119F20* Class_00119F20::sub_00119F20(int a1)
{
    m_Field04 = 12;
    m_Field00 = (int)DAT_0038F7D0;
    m_Field08 = a1;
    m_Field14 = 0.0f;
    m_Field10 = 0.0f;
    m_Field0C = 0.0f;
    return this;
}
