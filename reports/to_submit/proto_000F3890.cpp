// bin: proto
// va: 0x000F3890
// what: 
// tool: the portal's starter code (no AI)

// sub_000F3890 (Proto 0x000F3890, 70 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0038A55C[];
extern "C" char DAT_0038A644[];
extern "C" float DAT_003A968C;
extern "C" char sub_000F30E0[];

class Class_000F3890
{
public:
    Class_000F3890* sub_000F3890(int a1, int a2);
    void sub_000F0360(int, int);
    int m_Field00; // +0x00
    char m_pad04[0x48];
    int m_Field4C; // +0x4C
    float m_Field50; // +0x50
    int m_Field54; // +0x54
    int m_Field58; // +0x58
    int m_Field5C; // +0x5C
    int m_Field60; // +0x60
};

Class_000F3890* Class_000F3890::sub_000F3890(int a1, int a2)
{
    float t2;

    sub_000F0360(a1, a2);
    t2 = DAT_003A968C;
    m_Field4C = 0;
    m_Field54 = 0;
    m_Field58 = 0;
    m_Field50 = t2;
    m_Field00 = (int)DAT_0038A644;
    m_Field5C = (int)DAT_0038A55C;
    m_Field60 = (int)sub_000F30E0;
    return this;
}
