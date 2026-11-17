// bin: xb
// va: 0x0015FCB0
// tool: the portal's starter code (no AI)
// sub_0015FCB0 (0x0015FCB0, 76 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" float DAT_0039D580;
extern "C" float DAT_003A4974;
extern "C" char DAT_003B39F4[];
extern "C" float DAT_003D1C94;

class Class_0015FCB0
{
public:
    Class_0015FCB0* sub_0015FCB0(int a1, int a2);
    void sub_00029E60(int, int);
    int m_Field00; // +0x00
    char m_pad04[0x2C];
    float m_Field30; // +0x30
    float m_Field34; // +0x34
    float m_Field38; // +0x38
    float m_Field3C; // +0x3C
};

Class_0015FCB0* Class_0015FCB0::sub_0015FCB0(int a1, int a2)
{
    float t2, t4;

    sub_00029E60(a1, a2);
    t2 = DAT_003A4974;
    m_Field30 = t2;
    m_Field34 = t2;
    m_Field38 = DAT_0039D580;
    t4 = DAT_003D1C94;
    m_Field00 = (int)DAT_003B39F4;
    m_Field3C = t4;
    return this;
}
