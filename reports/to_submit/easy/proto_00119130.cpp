// bin: proto
// va: 0x00119130
// tool: the portal's starter code (no AI)
// sub_00119130 (0x00119130, 73 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0038F7F4[];

class Class_00119130
{
public:
    Class_00119130* sub_00119130(float a1, float a2, float a3, float a4, float a5);
    int m_Field00; // +0x00
    int m_Field04; // +0x04
    float m_Field08; // +0x08
    float m_Field0C; // +0x0C
    float m_Field10; // +0x10
    float m_Field14; // +0x14
    float m_Field18; // +0x18
};

Class_00119130* Class_00119130::sub_00119130(float a1, float a2, float a3, float a4, float a5)
{
    m_Field08 = a1;
    m_Field0C = a2;
    m_Field10 = a3;
    m_Field14 = a4;
    m_Field04 = 13;
    m_Field00 = (int)DAT_0038F7F4;
    m_Field18 = a5;
    return this;
}
