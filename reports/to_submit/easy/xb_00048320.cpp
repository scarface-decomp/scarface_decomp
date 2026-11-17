// bin: xb
// va: 0x00048320
// tool: the portal's starter code (no AI)
// sub_00048320 (0x00048320, 41 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

class Class_00048320
{
public:
    Class_00048320* sub_00048320();
    float m_Field00; // +0x00
    float m_Field04; // +0x04
    float m_Field08; // +0x08
    int m_Field0C; // +0x0C
    int m_Field10; // +0x10
    int m_Field14; // +0x14
    int m_Field18; // +0x18
};

Class_00048320* Class_00048320::sub_00048320()
{
    m_Field00 = 0.0f;
    m_Field04 = 0.0f;
    m_Field08 = 0.0f;
    m_Field0C = 128;
    m_Field10 = 255;
    m_Field14 = 255;
    m_Field18 = 255;
    return this;
}
