// bin: xb
// va: 0x00134D90
// tool: the portal's starter code (no AI)
// sub_00134D90 (0x00134D90, 48 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_003B1B8C[];

class Class_00134D90
{
public:
    Class_00134D90* sub_00134D90(float a1, float a2);
    int m_Field00; // +0x00
    int m_Field04; // +0x04
    float m_Field08; // +0x08
    float m_Field0C; // +0x0C
    float m_Field10; // +0x10
};

Class_00134D90* Class_00134D90::sub_00134D90(float a1, float a2)
{
    m_Field08 = a1;
    m_Field0C = a2;
    m_Field04 = 35;
    m_Field00 = (int)DAT_003B1B8C;
    m_Field10 = 0.0f;
    return this;
}
