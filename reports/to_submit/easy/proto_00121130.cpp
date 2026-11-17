// bin: proto
// va: 0x00121130
// tool: the portal's starter code (no AI)
// sub_00121130 (0x00121130, 70 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" float DAT_0037CE50;
extern "C" char DAT_003900C4[];

class Class_00121130
{
public:
    Class_00121130* sub_00121130(int a1, int a2);
    void sub_001210D0(int, int);
    int m_Field00; // +0x00
    char m_pad04[0x2C];
    int m_Field30; // +0x30
    float m_Field34; // +0x34
    float m_Field38; // +0x38
    float m_Field3C; // +0x3C
    float m_Field40; // +0x40
};

Class_00121130* Class_00121130::sub_00121130(int a1, int a2)
{
    sub_001210D0(a1, a2);
    m_Field00 = (int)DAT_003900C4;
    m_Field30 = 0;
    m_Field34 = 0.0f;
    m_Field38 = 0.0f;
    m_Field3C = 0.0f;
    m_Field40 = DAT_0037CE50;
    return this;
}
