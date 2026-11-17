// bin: xb
// va: 0x001C4B50
// tool: the portal's starter code (no AI)
// sub_001C4B50 (0x001C4B50, 40 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_003C327C[];

class Class_001C4B50
{
public:
    Class_001C4B50* sub_001C4B50();
    int m_Field00; // +0x00
    char m_pad04[0x4];
    float m_Field08; // +0x08
    float m_Field0C; // +0x0C
    float m_Field10; // +0x10
    float m_Field14; // +0x14
    char m_pad18[0x4];
    bool m_Field1C; // +0x1C
    char m_pad1D[0x3];
    int m_Field20; // +0x20
};

Class_001C4B50* Class_001C4B50::sub_001C4B50()
{
    m_Field08 = 0.0f;
    m_Field0C = 0.0f;
    m_Field10 = 0.0f;
    m_Field14 = 0.0f;
    m_Field1C = false;
    m_Field20 = 0;
    m_Field00 = (int)DAT_003C327C;
    return this;
}
