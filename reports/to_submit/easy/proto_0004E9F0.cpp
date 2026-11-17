// bin: proto
// va: 0x0004E9F0
// tool: the portal's starter code (no AI)
// sub_0004E9F0 (0x0004E9F0, 22 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

class Class_0004E9F0
{
public:
    int sub_0004E9F0(int a1);
    char m_pad00[0x74];
    float m_Field74; // +0x74
};

int Class_0004E9F0::sub_0004E9F0(int a1)
{
    m_Field74 = *(float*)(a1 + 8) + m_Field74;
    return a1;
}
