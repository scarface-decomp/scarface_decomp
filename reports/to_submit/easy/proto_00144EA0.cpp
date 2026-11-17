// bin: proto
// va: 0x00144EA0
// tool: the portal's starter code (no AI)
// sub_00144EA0 (0x00144EA0, 76 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" float DAT_0037CD90;
extern "C" float DAT_0038ADF0;
extern "C" char DAT_00391BC4[];
extern "C" float DAT_003A968C;

class Class_00144EA0
{
public:
    Class_00144EA0* sub_00144EA0(int a1, int a2);
    void sub_000276B0(int, int);
    int m_Field00; // +0x00
    char m_pad04[0x2C];
    float m_Field30; // +0x30
    float m_Field34; // +0x34
    float m_Field38; // +0x38
    float m_Field3C; // +0x3C
};

Class_00144EA0* Class_00144EA0::sub_00144EA0(int a1, int a2)
{
    float t2, t4;

    sub_000276B0(a1, a2);
    t2 = DAT_003A968C;
    m_Field30 = t2;
    m_Field34 = t2;
    m_Field38 = DAT_0037CD90;
    t4 = DAT_0038ADF0;
    m_Field00 = (int)DAT_00391BC4;
    m_Field3C = t4;
    return this;
}
