// bin: proto
// va: 0x0008C740
// tool: the portal's starter code (no AI)
// sub_0008C740 (0x0008C740, 53 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" float DAT_0037F550;

class Class_0008C740
{
public:
    Class_0008C740* sub_0008C740();
    int m_Field00; // +0x00
    float m_Field04; // +0x04
    float m_Field08; // +0x08
    float m_Field0C; // +0x0C
    float m_Field10; // +0x10
    bool m_Field14; // +0x14
    char m_pad15[0x3];
    int m_Field18; // +0x18
    bool m_Field1C; // +0x1C
    char m_pad1D[0x3];
    int m_Field20; // +0x20
    bool m_Field24; // +0x24
};

Class_0008C740* Class_0008C740::sub_0008C740()
{
    m_Field04 = DAT_0037F550;
    m_Field00 = 0;
    m_Field08 = 0.0f;
    m_Field0C = 0.0f;
    m_Field10 = 0.0f;
    m_Field14 = false;
    m_Field18 = 0;
    m_Field1C = false;
    m_Field20 = 0;
    m_Field24 = false;
    return this;
}
