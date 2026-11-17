// bin: proto
// va: 0x0009DAB0
// tool: the portal's starter code (no AI)
// sub_0009DAB0 (0x0009DAB0, 90 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" float DAT_0037CE50;
extern "C" float DAT_0037E6C0;
extern "C" float DAT_00383E58;
extern "C" float DAT_003841D8;
extern "C" float DAT_003A1754;

class Class_0009DAB0
{
public:
    Class_0009DAB0* sub_0009DAB0();
    float m_Field00; // +0x00
    float m_Field04; // +0x04
    float m_Field08; // +0x08
    float m_Field0C; // +0x0C
    float m_Field10; // +0x10
    float m_Field14; // +0x14
    float m_Field18; // +0x18
    float m_Field1C; // +0x1C
    float m_Field20; // +0x20
};

Class_0009DAB0* Class_0009DAB0::sub_0009DAB0()
{
    float t3, t5;

    m_Field04 = DAT_0037E6C0;
    m_Field14 = DAT_003A1754;
    t3 = DAT_0037CE50;
    m_Field18 = t3;
    m_Field1C = t3;
    m_Field20 = t3;
    m_Field00 = DAT_00383E58;
    t5 = DAT_003841D8;
    m_Field0C = 0.0f;
    m_Field08 = 0.0f;
    m_Field10 = t5;
    return this;
}
