// bin: proto
// va: 0x0012AA20
// tool: the portal's starter code (no AI)
// sub_0012AA20 (0x0012AA20, 40 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0039055C[];

class Class_0012AA20
{
public:
    Class_0012AA20* sub_0012AA20(int a1, int a2);
    void sub_00129E80(int, int);
    int m_Field00; // +0x00
    char m_pad04[0x30];
    float m_Field34; // +0x34
};

Class_0012AA20* Class_0012AA20::sub_0012AA20(int a1, int a2)
{
    sub_00129E80(a1, a2);
    m_Field00 = (int)DAT_0039055C;
    m_Field34 = 0.0f;
    return this;
}
