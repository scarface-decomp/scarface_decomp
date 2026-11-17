// bin: proto
// va: 0x00092680
// tool: the portal's starter code (no AI)
// sub_00092680 (0x00092680, 66 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" float DAT_0037CE50;
extern "C" float DAT_0037CE60;
extern "C" float DAT_00383F40;

class Class_00092680
{
public:
    Class_00092680* sub_00092680();
    float m_Field00; // +0x00
    float m_Field04; // +0x04
    float m_Field08; // +0x08
    float m_Field0C; // +0x0C
    float m_Field10; // +0x10
    float m_Field14; // +0x14
    float m_Field18; // +0x18
    float m_Field1C; // +0x1C
};

Class_00092680* Class_00092680::sub_00092680()
{
    float t1, t2, t3;

    t1 = DAT_00383F40;
    t2 = DAT_0037CE60;
    m_Field00 = t1;
    m_Field08 = t1;
    t3 = DAT_0037CE50;
    m_Field04 = t2;
    m_Field0C = t2;
    m_Field10 = t3;
    m_Field14 = t3;
    m_Field18 = t3;
    m_Field1C = t3;
    return this;
}
