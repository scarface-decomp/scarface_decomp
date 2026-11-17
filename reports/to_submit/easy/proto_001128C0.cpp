// bin: proto
// va: 0x001128C0
// tool: the portal's starter code (no AI)
// sub_001128C0 (0x001128C0, 71 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0038F2D0[];

class Class_001128C0
{
public:
    Class_001128C0* sub_001128C0(int a1, float a2, bool a3, bool a4, bool a5, bool a6);
    int m_Field00; // +0x00
    int m_Field04; // +0x04
    int m_Field08; // +0x08
    int m_Field0C; // +0x0C
    float m_Field10; // +0x10
    bool m_Field14; // +0x14
    bool m_Field15; // +0x15
    bool m_Field16; // +0x16
    bool m_Field17; // +0x17
};

Class_001128C0* Class_001128C0::sub_001128C0(int a1, float a2, bool a3, bool a4, bool a5, bool a6)
{
    m_Field08 = a1;
    m_Field14 = a3;
    m_Field15 = a4;
    m_Field04 = 7;
    m_Field00 = (int)DAT_0038F2D0;
    m_Field0C = 0;
    m_Field10 = a2;
    m_Field16 = a5;
    m_Field17 = a6;
    return this;
}
