// bin: xb
// va: 0x0015FB30
// tool: the portal's starter code (no AI)
// sub_0015FB30 (0x0015FB30, 30 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

class Class_0015FB30
{
public:
    Class_0015FB30* sub_0015FB30(int a1);
    int m_Field00; // +0x00
    float m_Field04; // +0x04
    bool m_Field08; // +0x08
    bool m_Field09; // +0x09
    bool m_Field0A; // +0x0A
};

Class_0015FB30* Class_0015FB30::sub_0015FB30(int a1)
{
    m_Field00 = a1;
    m_Field04 = 0.0f;
    m_Field08 = false;
    m_Field09 = false;
    m_Field0A = false;
    return this;
}
