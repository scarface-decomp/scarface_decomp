// bin: proto
// va: 0x0011D6A0
// tool: the portal's starter code (no AI)
// sub_0011D6A0 (0x0011D6A0, 43 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0038FEA8[];

class Class_0011D6A0
{
public:
    Class_0011D6A0* sub_0011D6A0(int a1, int a2, float a3);
    int m_Field00; // +0x00
    int m_Field04; // +0x04
    int m_Field08; // +0x08
    int m_Field0C; // +0x0C
    float m_Field10; // +0x10
};

Class_0011D6A0* Class_0011D6A0::sub_0011D6A0(int a1, int a2, float a3)
{
    m_Field04 = 7;
    m_Field08 = a1;
    m_Field00 = (int)DAT_0038FEA8;
    m_Field0C = a2;
    m_Field10 = a3;
    return this;
}
