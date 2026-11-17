// bin: proto
// va: 0x0016B5D0
// tool: the portal's starter code (no AI)
// sub_0016B5D0 (0x0016B5D0, 62 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_003975F4[];

class Class_0016B5D0
{
public:
    Class_0016B5D0* sub_0016B5D0();
    int m_Field00; // +0x00
    float m_Field04; // +0x04
    float m_Field08; // +0x08
    int m_Field0C; // +0x0C
    int m_Field10; // +0x10
    int m_Field14; // +0x14
    unsigned short m_Field18; // +0x18
    unsigned short m_Field1A; // +0x1A
    unsigned short m_Field1C; // +0x1C
    unsigned short m_Field1E; // +0x1E
    float m_Field20; // +0x20
    float m_Field24; // +0x24
    bool m_Field28; // +0x28
};

Class_0016B5D0* Class_0016B5D0::sub_0016B5D0()
{
    m_Field04 = 0.0f;
    m_Field08 = 0.0f;
    m_Field00 = (int)DAT_003975F4;
    m_Field0C = 0;
    m_Field10 = 0;
    m_Field14 = 0;
    m_Field18 = 0;
    m_Field1A = 0;
    m_Field1C = 0;
    m_Field1E = 0;
    m_Field20 = 0.0f;
    m_Field24 = 0.0f;
    m_Field28 = false;
    return this;
}
