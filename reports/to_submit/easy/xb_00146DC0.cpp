// bin: xb
// va: 0x00146DC0
// tool: the portal's starter code (no AI)
// sub_00146DC0 (0x00146DC0, 40 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_003B2594[];

class Class_00146DC0
{
public:
    Class_00146DC0* sub_00146DC0(int a1, int a2);
    void sub_00146140(int, int);
    int m_Field00; // +0x00
    char m_pad04[0x30];
    float m_Field34; // +0x34
};

Class_00146DC0* Class_00146DC0::sub_00146DC0(int a1, int a2)
{
    sub_00146140(a1, a2);
    m_Field00 = (int)DAT_003B2594;
    m_Field34 = 0.0f;
    return this;
}
