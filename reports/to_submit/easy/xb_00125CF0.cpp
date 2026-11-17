// bin: xb
// va: 0x00125CF0
// tool: the portal's starter code (no AI)
// sub_00125CF0 (0x00125CF0, 72 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" float DAT_003A49EC;
extern "C" float DAT_003AFA88;
extern "C" char DAT_003AFAAC[];

class Class_00125CF0
{
public:
    Class_00125CF0* sub_00125CF0(int a1, int a2);
    void sub_00106D00(int, int);
    int m_Field00; // +0x00
    char m_pad04[0x48];
    int m_Field4C; // +0x4C
    float m_Field50; // +0x50
    float m_Field54; // +0x54
    bool m_Field58; // +0x58
    bool m_Field59; // +0x59
    bool m_Field5A; // +0x5A
};

Class_00125CF0* Class_00125CF0::sub_00125CF0(int a1, int a2)
{
    float t3;

    sub_00106D00(a1, a2);
    m_Field4C = 0;
    m_Field00 = (int)DAT_003AFAAC;
    m_Field50 = DAT_003A49EC;
    t3 = DAT_003AFA88;
    m_Field58 = false;
    m_Field59 = false;
    m_Field5A = false;
    m_Field54 = t3;
    return this;
}
