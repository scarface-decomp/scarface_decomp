// bin: xb
// va: 0x00134740
// tool: the portal's starter code (no AI)
// sub_00134740 (0x00134740, 37 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_003B1904[];

class Class_00134740
{
public:
    Class_00134740* sub_00134740(float a1);
    int m_Field00; // +0x00
    int m_Field04; // +0x04
    float m_Field08; // +0x08
    float m_Field0C; // +0x0C
};

Class_00134740* Class_00134740::sub_00134740(float a1)
{
    m_Field08 = a1;
    m_Field04 = 15;
    m_Field00 = (int)DAT_003B1904;
    m_Field0C = 0.0f;
    return this;
}
