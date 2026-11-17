// bin: xb
// va: 0x00134CB0
// tool: the portal's starter code (no AI)
// sub_00134CB0 (0x00134CB0, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_003B1B20[];

class Class_00134CB0
{
public:
    Class_00134CB0* sub_00134CB0(float a1);
    int m_Field00; // +0x00
    int m_Field04; // +0x04
    float m_Field08; // +0x08
};

Class_00134CB0* Class_00134CB0::sub_00134CB0(float a1)
{
    m_Field04 = 31;
    m_Field00 = (int)DAT_003B1B20;
    m_Field08 = a1;
    return this;
}
