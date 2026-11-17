// bin: xb
// va: 0x00134820
// tool: the portal's starter code (no AI)
// sub_00134820 (0x00134820, 47 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_003B194C[];

class Class_00134820
{
public:
    Class_00134820* sub_00134820(int a1, float a2, float a3);
    int m_Field00; // +0x00
    int m_Field04; // +0x04
    int m_Field08; // +0x08
    float m_Field0C; // +0x0C
    float m_Field10; // +0x10
};

Class_00134820* Class_00134820::sub_00134820(int a1, float a2, float a3)
{
    m_Field0C = a2;
    m_Field04 = 18;
    m_Field00 = (int)DAT_003B194C;
    m_Field08 = a1;
    m_Field10 = a3;
    return this;
}
