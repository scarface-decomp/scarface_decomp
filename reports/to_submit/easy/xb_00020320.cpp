// bin: xb
// va: 0x00020320
// tool: the portal's starter code (no AI)
// sub_00020320 (0x00020320, 42 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

class Class_00020320
{
public:
    Class_00020320* sub_00020320();
    int m_Field00; // +0x00
    int m_Field04; // +0x04
    int m_Field08; // +0x08
    int m_Field0C; // +0x0C
    int m_Field10; // +0x10
    int m_Field14; // +0x14
    int m_Field18; // +0x18
    bool m_Field1C; // +0x1C
    char m_pad1D[0x3];
    int m_Field20; // +0x20
    float m_Field24; // +0x24
    bool m_Field28; // +0x28
};

Class_00020320* Class_00020320::sub_00020320()
{
    m_Field00 = 0;
    m_Field04 = 0;
    m_Field10 = 0;
    m_Field14 = 0;
    m_Field18 = 0;
    m_Field08 = 0;
    m_Field0C = 0;
    m_Field1C = false;
    m_Field20 = 0;
    m_Field24 = 0.0f;
    m_Field28 = false;
    return this;
}
