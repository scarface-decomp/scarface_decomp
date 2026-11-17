// bin: xb
// va: 0x000A6C00
// tool: the portal's starter code (no AI)
// sub_000A6C00 (0x000A6C00, 55 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" float DAT_0039F068;
extern "C" float DAT_003A3A28;
extern "C" float DAT_003A4C54;

class Class_000A6C00
{
public:
    Class_000A6C00* sub_000A6C00();
    float m_Field00; // +0x00
    float m_Field04; // +0x04
    float m_Field08; // +0x08
    int m_Field0C; // +0x0C
    int m_Field10; // +0x10
    int m_Field14; // +0x14
    int m_Field18; // +0x18
};

Class_000A6C00* Class_000A6C00::sub_000A6C00()
{
    m_Field00 = DAT_003A4C54;
    m_Field04 = DAT_003A3A28;
    m_Field08 = DAT_0039F068;
    m_Field0C = 0;
    m_Field10 = 0;
    m_Field14 = 0;
    m_Field18 = 0;
    return this;
}
