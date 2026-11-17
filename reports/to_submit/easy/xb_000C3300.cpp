// bin: xb
// va: 0x000C3300
// tool: the portal's starter code (no AI)
// sub_000C3300 (0x000C3300, 74 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" float DAT_0039F068;
extern "C" float DAT_003A4CA0;
extern "C" float DAT_003A4CBC;
extern "C" float DAT_003CA880;
extern "C" float DAT_003D111C;

class Class_000C3300
{
public:
    Class_000C3300* sub_000C3300();
    int m_Field00; // +0x00
    float m_Field04; // +0x04
    float m_Field08; // +0x08
    float m_Field0C; // +0x0C
    float m_Field10; // +0x10
    float m_Field14; // +0x14
};

Class_000C3300* Class_000C3300::sub_000C3300()
{
    float t5;

    m_Field04 = DAT_003D111C;
    m_Field0C = DAT_0039F068;
    m_Field14 = DAT_003CA880;
    m_Field08 = DAT_003A4CBC;
    t5 = DAT_003A4CA0;
    m_Field00 = 0;
    m_Field10 = t5;
    return this;
}
