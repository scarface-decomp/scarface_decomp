// bin: proto
// va: 0x0009AFE0
// tool: the portal's starter code (no AI)
// sub_0009AFE0 (0x0009AFE0, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field38
{
    void sub_0007D390();
};

extern "C" float DAT_0037CE60;
extern "C" void __cdecl sub_0007CE40(void);

class Class_0009AFE0
{
public:
    Class_0009AFE0* sub_0009AFE0();
    char m_pad00[0x30];
    int m_Field30; // +0x30
    int m_Field34; // +0x34
    Field38 m_Field38; // +0x38
    char m_pad39[0x47];
    float m_Field80; // +0x80
};

Class_0009AFE0* Class_0009AFE0::sub_0009AFE0()
{
    sub_0007CE40();
    m_Field30 = -1;
    m_Field34 = 0;
    m_Field38.sub_0007D390();
    m_Field80 = DAT_0037CE60;
    return this;
}
