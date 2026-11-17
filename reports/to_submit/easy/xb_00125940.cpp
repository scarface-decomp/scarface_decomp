// bin: xb
// va: 0x00125940
// tool: the portal's starter code (no AI)
// sub_00125940 (0x00125940, 39 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

class Class_00125940
{
public:
    int sub_00125940(int a1, float a2, float a3, bool a4);
    char m_pad00[0x4C];
    int m_Field4C; // +0x4C
    float m_Field50; // +0x50
    float m_Field54; // +0x54
    bool m_Field58; // +0x58
};

int Class_00125940::sub_00125940(int a1, float a2, float a3, bool a4)
{
    m_Field54 = a2;
    m_Field4C = a1;
    m_Field50 = a3;
    m_Field58 = a4;
    return a1;
}
