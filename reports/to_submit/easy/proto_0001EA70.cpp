// bin: proto
// va: 0x0001EA70
// tool: the portal's starter code (no AI)
// sub_0001EA70 (0x0001EA70, 53 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

class Class_0001EA70
{
public:
    int sub_0001EA70(float a1, int a2);
    float m_Field00; // +0x00
    float m_Field04; // +0x04
    float m_Field08; // +0x08
};

int Class_0001EA70::sub_0001EA70(float a1, int a2)
{
    m_Field00 = *(float*)a2 * a1;
    m_Field04 = *(float*)(a2 + 4) * a1;
    m_Field08 = *(float*)(a2 + 8) * a1;
    return a2;
}
