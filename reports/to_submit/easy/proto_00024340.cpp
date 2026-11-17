// bin: proto
// va: 0x00024340
// tool: the portal's starter code (no AI)
// sub_00024340 (0x00024340, 52 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0037E654[];
extern "C" float DAT_0037E6C0;

class Class_00024340
{
public:
    Class_00024340* sub_00024340(int a1, int a2);
    void sub_000276B0(int, int);
    int m_Field00; // +0x00
    char m_pad04[0x34];
    int m_Field38; // +0x38
    float m_Field3C; // +0x3C
};

Class_00024340* Class_00024340::sub_00024340(int a1, int a2)
{
    float t2;

    sub_000276B0(a1, a2);
    t2 = DAT_0037E6C0;
    m_Field00 = (int)DAT_0037E654;
    m_Field38 = 0;
    m_Field3C = t2;
    return this;
}
