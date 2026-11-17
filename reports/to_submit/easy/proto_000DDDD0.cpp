// bin: proto
// va: 0x000DDDD0
// tool: the portal's starter code (no AI)
// sub_000DDDD0 (0x000DDDD0, 80 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

class Class_000DDDD0
{
public:
    void sub_000DDDD0(float a1, float a2, float a3, float a4, float a5);
    char m_pad00[0x3AC];
    float m_Field3AC; // +0x3AC
    float m_Field3B0; // +0x3B0
    float m_Field3B4; // +0x3B4
    float m_Field3B8; // +0x3B8
    float m_Field3BC; // +0x3BC
    bool m_Field3C0; // +0x3C0
};

void Class_000DDDD0::sub_000DDDD0(float a1, float a2, float a3, float a4, float a5)
{
    m_Field3AC = a1;
    m_Field3B0 = a2;
    m_Field3B4 = a3;
    m_Field3B8 = a4;
    m_Field3BC = a5;
    m_Field3C0 = true;
}
