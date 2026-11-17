// bin: xb
// va: 0x000266D0
// tool: the portal's starter code (no AI)
// sub_000266D0 (0x000266D0, 52 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0039EFF4[];
extern "C" float DAT_0039F068;

class Class_000266D0
{
public:
    Class_000266D0* sub_000266D0(int a1, int a2);
    void sub_00029E60(int, int);
    int m_Field00; // +0x00
    char m_pad04[0x34];
    int m_Field38; // +0x38
    float m_Field3C; // +0x3C
};

Class_000266D0* Class_000266D0::sub_000266D0(int a1, int a2)
{
    float t2;

    sub_00029E60(a1, a2);
    t2 = DAT_0039F068;
    m_Field00 = (int)DAT_0039EFF4;
    m_Field38 = 0;
    m_Field3C = t2;
    return this;
}
