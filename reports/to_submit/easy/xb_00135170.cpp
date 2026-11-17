// bin: xb
// va: 0x00135170
// tool: the portal's starter code (no AI)
// sub_00135170 (0x00135170, 43 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_003B18BC[];

class Class_00135170
{
public:
    Class_00135170* sub_00135170(int a1);
    int m_Field00; // +0x00
    int m_Field04; // +0x04
    int m_Field08; // +0x08
    float m_Field0C; // +0x0C
    float m_Field10; // +0x10
    float m_Field14; // +0x14
};

Class_00135170* Class_00135170::sub_00135170(int a1)
{
    m_Field04 = 12;
    m_Field00 = (int)DAT_003B18BC;
    m_Field08 = a1;
    m_Field14 = 0.0f;
    m_Field10 = 0.0f;
    m_Field0C = 0.0f;
    return this;
}
