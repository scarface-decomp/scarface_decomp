// bin: proto
// va: 0x001B83F0
// tool: the portal's starter code (no AI)
// sub_001B83F0 (0x001B83F0, 10 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

class Class_001B83F0
{
public:
    float sub_001B83F0();
    char m_pad00[0x12C];
    int m_Field12C; // +0x12C
};

float Class_001B83F0::sub_001B83F0()
{
    return *(float*)(m_Field12C + 96);
}
