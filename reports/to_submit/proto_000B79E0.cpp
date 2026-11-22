// bin: proto
// va: 0x000B79E0
// what: 
// tool: the portal's starter code (no AI)

// sub_000B79E0 (Proto 0x000B79E0, 56 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field10
{
    void sub_0007CEF0();
};

extern "C" float DAT_0037CE60;

class Class_000B79E0
{
public:
    Class_000B79E0* sub_000B79E0();
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

Class_000B79E0* Class_000B79E0::sub_000B79E0()
{
    m_Field00 = DAT_0037CE60;
    m_Field04 = 0;
    m_Field08 = 0;
    m_Field0C = 0;
    m_Field10.sub_0007CEF0();
    m_Field28 = false;
    m_Field20 = 0.0f;
    m_Field24 = 0.0f;
    return this;
}
