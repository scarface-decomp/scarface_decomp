// bin: proto
// va: 0x00011DE0
// tool: the portal's starter code (no AI)
// sub_00011DE0 (0x00011DE0, 53 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

class Class_00011DE0
{
public:
    int sub_00011DE0(int a1, int a2);
    float m_Field00; // +0x00
    float m_Field04; // +0x04
    float m_Field08; // +0x08
};

int Class_00011DE0::sub_00011DE0(int a1, int a2)
{
    m_Field00 = *(float*)a1 - *(float*)a2;
    m_Field04 = *(float*)(a1 + 4) - *(float*)(a2 + 4);
    m_Field08 = *(float*)(a1 + 8) - *(float*)(a2 + 8);
    return a1;
}
