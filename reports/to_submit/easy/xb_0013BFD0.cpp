// bin: xb
// va: 0x0013BFD0
// tool: the portal's starter code (no AI)
// sub_0013BFD0 (0x0013BFD0, 70 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" float DAT_0039D664;
extern "C" char DAT_003B211C[];

class Class_0013BFD0
{
public:
    Class_0013BFD0* sub_0013BFD0(int a1, int a2);
    void sub_0013BF30(int, int);
    int m_Field00; // +0x00
    char m_pad04[0x2C];
    int m_Field30; // +0x30
    float m_Field34; // +0x34
    float m_Field38; // +0x38
    float m_Field3C; // +0x3C
    float m_Field40; // +0x40
};

Class_0013BFD0* Class_0013BFD0::sub_0013BFD0(int a1, int a2)
{
    sub_0013BF30(a1, a2);
    m_Field00 = (int)DAT_003B211C;
    m_Field30 = 0;
    m_Field34 = 0.0f;
    m_Field38 = 0.0f;
    m_Field3C = 0.0f;
    m_Field40 = DAT_0039D664;
    return this;
}
