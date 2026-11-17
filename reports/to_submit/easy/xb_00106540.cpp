// bin: xb
// va: 0x00106540
// tool: the portal's starter code (no AI)
// sub_00106540 (0x00106540, 64 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_003AB734[];

class Class_00106540
{
public:
    Class_00106540* sub_00106540(int a1, int a2);
    void sub_00106D00(int, int);
    int m_Field00; // +0x00
    char m_pad04[0x48];
    int m_Field4C; // +0x4C
    float m_Field50; // +0x50
    float m_Field54; // +0x54
    float m_Field58; // +0x58
    int m_Field5C; // +0x5C
};

Class_00106540* Class_00106540::sub_00106540(int a1, int a2)
{
    sub_00106D00(a1, a2);
    m_Field00 = (int)DAT_003AB734;
    m_Field4C = 4;
    m_Field50 = 0.0f;
    m_Field54 = 0.0f;
    m_Field58 = 0.0f;
    m_Field5C = 0;
    return this;
}
