// bin: xb
// va: 0x0009AFF0
// tool: the portal's starter code (no AI)
// sub_0009AFF0 (0x0009AFF0, 74 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" float DAT_0039F068;
extern "C" float DAT_003A48FC;
extern "C" float DAT_003A4900;
extern "C" float DAT_003A4904;

class Class_0009AFF0
{
public:
    Class_0009AFF0* sub_0009AFF0();
    float m_Field00; // +0x00
    float m_Field04; // +0x04
    float m_Field08; // +0x08
    float m_Field0C; // +0x0C
    float m_Field10; // +0x10
    float m_Field14; // +0x14
    float m_Field18; // +0x18
    float m_Field1C; // +0x1C
};

Class_0009AFF0* Class_0009AFF0::sub_0009AFF0()
{
    float t2, t4;

    m_Field00 = DAT_003A4904;
    t2 = DAT_0039F068;
    m_Field08 = t2;
    m_Field10 = t2;
    m_Field18 = t2;
    m_Field04 = DAT_003A4900;
    t4 = DAT_003A48FC;
    m_Field0C = t4;
    m_Field14 = t4;
    m_Field1C = t4;
    return this;
}
