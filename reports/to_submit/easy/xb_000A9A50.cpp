// bin: xb
// va: 0x000A9A50
// tool: the portal's starter code (no AI)
// sub_000A9A50 (0x000A9A50, 90 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" float DAT_0039D664;
extern "C" float DAT_0039F068;
extern "C" float DAT_003A48FC;
extern "C" float DAT_003A4CA8;
extern "C" float DAT_003D1C98;

class Class_000A9A50
{
public:
    Class_000A9A50* sub_000A9A50();
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

Class_000A9A50* Class_000A9A50::sub_000A9A50()
{
    float t3, t5;

    m_Field04 = DAT_0039F068;
    m_Field14 = DAT_003D1C98;
    t3 = DAT_0039D664;
    m_Field18 = t3;
    m_Field1C = t3;
    m_Field20 = t3;
    m_Field00 = DAT_003A48FC;
    t5 = DAT_003A4CA8;
    m_Field0C = 0.0f;
    m_Field08 = 0.0f;
    m_Field10 = t5;
    return this;
}
