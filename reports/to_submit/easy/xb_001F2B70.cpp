// bin: xb
// va: 0x001F2B70
// tool: the portal's starter code (no AI)
// sub_001F2B70 (0x001F2B70, 10 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

class Class_001F2B70
{
public:
    float sub_001F2B70();
    char m_pad00[0x150];
    int m_Field150; // +0x150
};

float Class_001F2B70::sub_001F2B70()
{
    return *(float*)(m_Field150 + 92);
}
