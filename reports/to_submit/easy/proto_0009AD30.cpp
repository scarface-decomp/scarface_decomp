// bin: proto
// va: 0x0009AD30
// tool: the portal's starter code (no AI)
// sub_0009AD30 (0x0009AD30, 58 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" float DAT_0037E6C0;
extern "C" float DAT_00382B18;
extern "C" float DAT_00384180;

class Class_0009AD30
{
public:
    Class_0009AD30* sub_0009AD30();
    float m_Field00; // +0x00
    float m_Field04; // +0x04
    float m_Field08; // +0x08
    int m_Field0C; // +0x0C
    int m_Field10; // +0x10
    int m_Field14; // +0x14
    int m_Field18; // +0x18
    int m_Field1C; // +0x1C
};

Class_0009AD30* Class_0009AD30::sub_0009AD30()
{
    m_Field00 = DAT_00384180;
    m_Field04 = DAT_00382B18;
    m_Field08 = DAT_0037E6C0;
    m_Field0C = 0;
    m_Field10 = 0;
    m_Field14 = 0;
    m_Field18 = 0;
    m_Field1C = 0;
    return this;
}
