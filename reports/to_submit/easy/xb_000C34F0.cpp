// bin: xb
// va: 0x000C34F0
// tool: the portal's starter code (no AI)
// sub_000C34F0 (0x000C34F0, 56 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" float DAT_0039D65C;

class Class_000C34F0
{
public:
    Class_000C34F0* sub_000C34F0();
    int m_Field00; // +0x00
    int m_Field04; // +0x04
    int m_Field08; // +0x08
    int m_Field0C; // +0x0C
    float m_Field10; // +0x10
    float m_Field14; // +0x14
    bool m_Field18; // +0x18
    char m_pad19[0x3];
    int m_Field1C; // +0x1C
    float m_Field20; // +0x20
    float m_Field24; // +0x24
    bool m_Field28; // +0x28
};

Class_000C34F0* Class_000C34F0::sub_000C34F0()
{
    float t1;

    t1 = DAT_0039D65C;
    m_Field00 = 0;
    m_Field04 = 0;
    m_Field08 = 0;
    m_Field0C = 0;
    m_Field10 = t1;
    m_Field14 = 0.0f;
    m_Field18 = false;
    m_Field1C = 0;
    m_Field20 = t1;
    m_Field24 = 0.0f;
    m_Field28 = false;
    return this;
}
