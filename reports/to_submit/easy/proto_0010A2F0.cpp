// bin: proto
// va: 0x0010A2F0
// tool: the portal's starter code (no AI)
// sub_0010A2F0 (0x0010A2F0, 65 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" float DAT_0037CE50;
extern "C" float DAT_0038ADF0;
extern "C" char DAT_0038D8A4[];

class Class_0010A2F0
{
public:
    Class_0010A2F0* sub_0010A2F0(int a1, int a2);
    void sub_0010DC20(int, int);
    int m_Field00; // +0x00
    char m_pad04[0x50];
    int m_Field54; // +0x54
    float m_Field58; // +0x58
    float m_Field5C; // +0x5C
};

Class_0010A2F0* Class_0010A2F0::sub_0010A2F0(int a1, int a2)
{
    float t3;

    sub_0010DC20(a1, a2);
    m_Field58 = DAT_0038ADF0;
    t3 = DAT_0037CE50;
    m_Field00 = (int)DAT_0038D8A4;
    m_Field54 = 0;
    m_Field5C = t3;
    return this;
}
