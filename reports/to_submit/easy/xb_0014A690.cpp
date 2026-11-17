// bin: xb
// va: 0x0014A690
// tool: the portal's starter code (no AI)
// sub_0014A690 (0x0014A690, 45 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_003B2B3C[];
extern "C" float DAT_003D1058;

class Class_0014A690
{
public:
    Class_0014A690* sub_0014A690(int a1, int a2);
    void sub_00029450(int, int);
    int m_Field00; // +0x00
    char m_pad04[0x70];
    float m_Field74; // +0x74
};

Class_0014A690* Class_0014A690::sub_0014A690(int a1, int a2)
{
    float t2;

    sub_00029450(a1, a2);
    t2 = DAT_003D1058;
    m_Field00 = (int)DAT_003B2B3C;
    m_Field74 = t2;
    return this;
}
