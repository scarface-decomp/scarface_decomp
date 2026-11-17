// bin: xb
// va: 0x0010A770
// tool: the portal's starter code (no AI)
// sub_0010A770 (0x0010A770, 70 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" float DAT_003A4974;
extern "C" char DAT_003AC12C[];
extern "C" char DAT_003AC224[];
extern "C" char sub_00109ED0[];

class Class_0010A770
{
public:
    Class_0010A770* sub_0010A770(int a1, int a2);
    void sub_00106D00(int, int);
    int m_Field00; // +0x00
    char m_pad04[0x48];
    int m_Field4C; // +0x4C
    float m_Field50; // +0x50
    int m_Field54; // +0x54
    int m_Field58; // +0x58
    int m_Field5C; // +0x5C
    int m_Field60; // +0x60
};

Class_0010A770* Class_0010A770::sub_0010A770(int a1, int a2)
{
    float t2;

    sub_00106D00(a1, a2);
    t2 = DAT_003A4974;
    m_Field4C = 0;
    m_Field54 = 0;
    m_Field58 = 0;
    m_Field50 = t2;
    m_Field00 = (int)DAT_003AC224;
    m_Field5C = (int)DAT_003AC12C;
    m_Field60 = (int)sub_00109ED0;
    return this;
}
