// bin: proto
// va: 0x0011D610
// what: 
// tool: the portal's starter code (no AI)

// sub_0011D610 (Proto 0x0011D610, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0038FE88[];

class Class_0011D610
{
public:
    Class_0011D610* sub_0011D610(int a1, int a2, float a3, bool a4);
    int m_Field00; // +0x00
    int m_Field04; // +0x04
    int m_Field08; // +0x08
    int m_Field0C; // +0x0C
    float m_Field10; // +0x10
    bool m_Field14; // +0x14
};

Class_0011D610* Class_0011D610::sub_0011D610(int a1, int a2, float a3, bool a4)
{
    m_Field08 = a1;
    m_Field04 = 5;
    m_Field00 = (int)DAT_0038FE88;
    m_Field0C = a2;
    m_Field10 = a3;
    m_Field14 = a4;
    return this;
}
