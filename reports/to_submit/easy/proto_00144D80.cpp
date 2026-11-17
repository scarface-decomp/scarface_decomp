// bin: proto
// va: 0x00144D80
// tool: the portal's starter code (no AI)
// sub_00144D80 (0x00144D80, 27 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

class Class_00144D80
{
public:
    Class_00144D80* sub_00144D80(int a1);
    int m_Field00; // +0x00
    float m_Field04; // +0x04
    bool m_Field08; // +0x08
    bool m_Field09; // +0x09
};

Class_00144D80* Class_00144D80::sub_00144D80(int a1)
{
    m_Field00 = a1;
    m_Field04 = 0.0f;
    m_Field08 = false;
    m_Field09 = false;
    return this;
}
