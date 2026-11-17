// bin: proto
// va: 0x0007CE40
// tool: the portal's starter code (no AI)
// sub_0007CE40 (0x0007CE40, 75 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" float DAT_003834D4;
extern "C" float DAT_003834D8;

class Class_0007CE40
{
public:
    Class_0007CE40* sub_0007CE40();
    bool m_Field00; // +0x00
    char m_pad01[0x3];
    int m_Field04; // +0x04
    int m_Field08; // +0x08
    int m_Field0C; // +0x0C
    int m_Field10; // +0x10
    int m_Field14; // +0x14
    float m_Field18; // +0x18
    float m_Field1C; // +0x1C
    float m_Field20; // +0x20
    int m_Field24; // +0x24
    int m_Field28; // +0x28
    bool m_Field2C; // +0x2C
    bool m_Field2D; // +0x2D
    bool m_Field2E; // +0x2E
    bool m_Field2F; // +0x2F
};

Class_0007CE40* Class_0007CE40::sub_0007CE40()
{
    m_Field18 = 0.0f;
    m_Field00 = false;
    m_Field04 = 0;
    m_Field08 = 0;
    m_Field0C = 0;
    m_Field10 = 0;
    m_Field14 = 0;
    m_Field1C = DAT_003834D4;
    m_Field20 = DAT_003834D8;
    m_Field24 = 0;
    m_Field28 = 0;
    m_Field2C = true;
    m_Field2D = false;
    m_Field2E = false;
    m_Field2F = false;
    return this;
}
