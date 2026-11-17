// bin: xb
// va: 0x0012E9C0
// tool: the portal's starter code (no AI)
// sub_0012E9C0 (0x0012E9C0, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_003B14A4[];

class Class_0012E9C0
{
public:
    Class_0012E9C0* sub_0012E9C0(float a1);
    int m_Field00; // +0x00
    int m_Field04; // +0x04
    float m_Field08; // +0x08
};

Class_0012E9C0* Class_0012E9C0::sub_0012E9C0(float a1)
{
    m_Field04 = 8;
    m_Field00 = (int)DAT_003B14A4;
    m_Field08 = a1;
    return this;
}
