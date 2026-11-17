// bin: xb
// va: 0x00134BD0
// tool: the portal's starter code (no AI)
// sub_00134BD0 (0x00134BD0, 62 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_003B1AB4[];

class Class_00134BD0
{
public:
    Class_00134BD0* sub_00134BD0(float a1, float a2, float a3, float a4);
    int m_Field00; // +0x00
    int m_Field04; // +0x04
    float m_Field08; // +0x08
    float m_Field0C; // +0x0C
    float m_Field10; // +0x10
    float m_Field14; // +0x14
};

Class_00134BD0* Class_00134BD0::sub_00134BD0(float a1, float a2, float a3, float a4)
{
    m_Field08 = a1;
    m_Field0C = a2;
    m_Field10 = a3;
    m_Field04 = 28;
    m_Field00 = (int)DAT_003B1AB4;
    m_Field14 = a4;
    return this;
}
