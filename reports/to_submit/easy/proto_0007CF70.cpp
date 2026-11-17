// bin: proto
// va: 0x0007CF70
// tool: the portal's starter code (no AI)
// sub_0007CF70 (0x0007CF70, 69 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" float DAT_003834D4;
extern "C" float DAT_003850D4;

class Class_0007CF70
{
public:
    Class_0007CF70* sub_0007CF70();
    bool m_Field00; // +0x00
    char m_pad01[0x3];
    int m_Field04; // +0x04
    int m_Field08; // +0x08
    int m_Field0C; // +0x0C
    int m_Field10; // +0x10
    int m_Field14; // +0x14
    int m_Field18; // +0x18
    float m_Field1C; // +0x1C
    float m_Field20; // +0x20
    float m_Field24; // +0x24
    bool m_Field28; // +0x28
    char m_pad29[0x1];
    unsigned short m_Field2A; // +0x2A
};

Class_0007CF70* Class_0007CF70::sub_0007CF70()
{
    m_Field1C = 0.0f;
    m_Field00 = false;
    m_Field04 = 0;
    m_Field08 = 0;
    m_Field0C = 0;
    m_Field10 = 0;
    m_Field14 = 0;
    m_Field18 = 0;
    m_Field20 = DAT_003834D4;
    m_Field24 = DAT_003850D4;
    m_Field28 = true;
    m_Field2A = 65535;
    return this;
}
