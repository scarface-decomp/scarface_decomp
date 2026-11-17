// bin: xb
// va: 0x001345D0
// tool: the portal's starter code (no AI)
// sub_001345D0 (0x001345D0, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_003B1874[];

class Class_001345D0
{
public:
    Class_001345D0* sub_001345D0(int a1, float a2, bool a3);
    int m_Field00; // +0x00
    int m_Field04; // +0x04
    int m_Field08; // +0x08
    float m_Field0C; // +0x0C
    int m_Field10; // +0x10
    bool m_Field14; // +0x14
};

Class_001345D0* Class_001345D0::sub_001345D0(int a1, float a2, bool a3)
{
    m_Field04 = 10;
    m_Field00 = (int)DAT_003B1874;
    m_Field08 = a1;
    m_Field0C = a2;
    m_Field10 = 0;
    m_Field14 = a3;
    return this;
}
