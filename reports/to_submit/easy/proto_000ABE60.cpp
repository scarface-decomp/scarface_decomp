// bin: proto
// va: 0x000ABE60
// tool: the portal's starter code (no AI)
// sub_000ABE60 (0x000ABE60, 52 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" float DAT_0037CE50;

class Class_000ABE60
{
public:
    Class_000ABE60* sub_000ABE60();
    int m_Field00; // +0x00
    float m_Field04; // +0x04
    float m_Field08; // +0x08
    float m_Field0C; // +0x0C
    float m_Field10; // +0x10
    float m_Field14; // +0x14
    float m_Field18; // +0x18
    float m_Field1C; // +0x1C
};

Class_000ABE60* Class_000ABE60::sub_000ABE60()
{
    float t1;

    t1 = DAT_0037CE50;
    m_Field00 = 0;
    m_Field04 = t1;
    m_Field08 = t1;
    m_Field0C = t1;
    m_Field10 = t1;
    m_Field14 = t1;
    m_Field18 = t1;
    m_Field1C = t1;
    return this;
}
