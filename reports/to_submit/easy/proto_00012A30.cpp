// bin: proto
// va: 0x00012A30
// tool: the portal's starter code (no AI)
// sub_00012A30 (0x00012A30, 71 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

class Class_00012A30
{
public:
    int sub_00012A30(int a1, float a2, int a3);
    float m_Field00; // +0x00
    float m_Field04; // +0x04
    float m_Field08; // +0x08
};

int Class_00012A30::sub_00012A30(int a1, float a2, int a3)
{
    m_Field00 = (*(float*)a3 * a2) + *(float*)a1;
    m_Field04 = (*(float*)(a3 + 4) * a2) + *(float*)(a1 + 4);
    m_Field08 = (*(float*)(a3 + 8) * a2) + *(float*)(a1 + 8);
    return a3;
}
