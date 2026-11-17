// bin: xb
// va: 0x001C2670
// tool: the portal's starter code (no AI)
// sub_001C2670 (0x001C2670, 33 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

class Class_001C2670
{
public:
    void sub_001C2670(float a1, int a2, float a3);
    char m_pad00[0x6C];
    float m_Field6C; // +0x6C
    float m_Field70; // +0x70
    float m_Field74; // +0x74
};

void Class_001C2670::sub_001C2670(float a1, int a2, float a3)
{
    m_Field6C = a1;
    m_Field70 = 0.0f;
    m_Field74 = a3;
}
