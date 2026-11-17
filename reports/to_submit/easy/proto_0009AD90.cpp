// bin: proto
// va: 0x0009AD90
// tool: the portal's starter code (no AI)
// sub_0009AD90 (0x0009AD90, 48 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" float DAT_0037CE50;
extern "C" float DAT_003850D4;

class Class_0009AD90
{
public:
    Class_0009AD90* sub_0009AD90();
    float m_Field00; // +0x00
    float m_Field04; // +0x04
    float m_Field08; // +0x08
    float m_Field0C; // +0x0C
    float m_Field10; // +0x10
    float m_Field14; // +0x14
};

Class_0009AD90* Class_0009AD90::sub_0009AD90()
{
    float t1, t2;

    t1 = DAT_003850D4;
    m_Field00 = t1;
    m_Field04 = t1;
    t2 = DAT_0037CE50;
    m_Field08 = t2;
    m_Field0C = t2;
    m_Field10 = t2;
    m_Field14 = t2;
    return this;
}
