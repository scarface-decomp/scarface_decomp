// bin: xb
// va: 0x000C5550
// tool: the portal's starter code (no AI)
// sub_000C5550 (0x000C5550, 56 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field10
{
    void sub_00087410();
};

extern "C" float DAT_0039D65C;

class Class_000C5550
{
public:
    Class_000C5550* sub_000C5550();
    float m_Field00; // +0x00
    int m_Field04; // +0x04
    int m_Field08; // +0x08
    int m_Field0C; // +0x0C
    Field10 m_Field10; // +0x10
    char m_pad11[0xF];
    float m_Field20; // +0x20
    float m_Field24; // +0x24
    bool m_Field28; // +0x28
};

Class_000C5550* Class_000C5550::sub_000C5550()
{
    m_Field00 = DAT_0039D65C;
    m_Field04 = 0;
    m_Field08 = 0;
    m_Field0C = 0;
    m_Field10.sub_00087410();
    m_Field28 = false;
    m_Field20 = 0.0f;
    m_Field24 = 0.0f;
    return this;
}
