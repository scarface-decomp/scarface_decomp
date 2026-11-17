// bin: xb
// va: 0x00138490
// tool: the portal's starter code (no AI)
// sub_00138490 (0x00138490, 43 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_003B1ED0[];

class Class_00138490
{
public:
    Class_00138490* sub_00138490(int a1, int a2, float a3);
    int m_Field00; // +0x00
    int m_Field04; // +0x04
    int m_Field08; // +0x08
    int m_Field0C; // +0x0C
    float m_Field10; // +0x10
};

Class_00138490* Class_00138490::sub_00138490(int a1, int a2, float a3)
{
    m_Field04 = 7;
    m_Field08 = a1;
    m_Field00 = (int)DAT_003B1ED0;
    m_Field0C = a2;
    m_Field10 = a3;
    return this;
}
