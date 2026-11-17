// bin: xb
// va: 0x0018EED0
// tool: the portal's starter code (no AI)
// sub_0018EED0 (0x0018EED0, 48 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_003B9FD4[];

class Class_0018EED0
{
public:
    Class_0018EED0* sub_0018EED0();
    int m_Field00; // +0x00
    float m_Field04; // +0x04
    float m_Field08; // +0x08
    int m_Field0C; // +0x0C
    int m_Field10; // +0x10
    float m_Field14; // +0x14
    float m_Field18; // +0x18
    float m_Field1C; // +0x1C
    bool m_Field20; // +0x20
};

Class_0018EED0* Class_0018EED0::sub_0018EED0()
{
    m_Field04 = 0.0f;
    m_Field08 = 0.0f;
    m_Field00 = (int)DAT_003B9FD4;
    m_Field0C = 0;
    m_Field10 = 0;
    m_Field14 = 0.0f;
    m_Field18 = 0.0f;
    m_Field1C = 0.0f;
    m_Field20 = false;
    return this;
}
