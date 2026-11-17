// bin: pc
// va: 0x006E9280
// tool: the portal's starter code (no AI)
// sub_006E9280 (0x006E9280, 22 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

class Class_006E9280
{
public:
    Class_006E9280* sub_006E9280(int a1);
    int m_Field00; // +0x00
    int m_Field04; // +0x04
    int m_Field08; // +0x08
    int m_Field0C; // +0x0C
};

Class_006E9280* Class_006E9280::sub_006E9280(int a1)
{
    m_Field00 = a1;
    m_Field04 = 0;
    m_Field08 = 0;
    m_Field0C = 0;
    return this;
}
