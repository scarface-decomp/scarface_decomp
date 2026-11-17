// bin: proto
// va: 0x0016B530
// tool: the portal's starter code (no AI)
// sub_0016B530 (0x0016B530, 48 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_003975C0[];

class Class_0016B530
{
public:
    Class_0016B530* sub_0016B530();
    int m_Field00; // +0x00
    float m_Field04; // +0x04
    float m_Field08; // +0x08
    int m_Field0C; // +0x0C
    int m_Field10; // +0x10
    float m_Field14; // +0x14
    float m_Field18; // +0x18
    float m_Field1C; // +0x1C
    bool m_Field20; // +0x20
};

Class_0016B530* Class_0016B530::sub_0016B530()
{
    m_Field04 = 0.0f;
    m_Field08 = 0.0f;
    m_Field00 = (int)DAT_003975C0;
    m_Field0C = 0;
    m_Field10 = 0;
    m_Field14 = 0.0f;
    m_Field18 = 0.0f;
    m_Field1C = 0.0f;
    m_Field20 = false;
    return this;
}
