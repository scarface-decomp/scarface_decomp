// bin: proto
// va: 0x000129F0
// tool: the portal's starter code (no AI)
// sub_000129F0 (0x000129F0, 49 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

class Class_000129F0
{
public:
    int sub_000129F0(int a1);
    float m_Field00; // +0x00
    float m_Field04; // +0x04
    float m_Field08; // +0x08
};

int Class_000129F0::sub_000129F0(int a1)
{
    m_Field00 = *(float*)a1 + m_Field00;
    m_Field04 = *(float*)(a1 + 4) + m_Field04;
    m_Field08 = *(float*)(a1 + 8) + m_Field08;
    return a1;
}
