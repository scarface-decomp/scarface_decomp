// bin: xb
// va: 0x001F2B40
// tool: the portal's starter code (no AI)
// sub_001F2B40 (0x001F2B40, 10 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

class Class_001F2B40
{
public:
    float sub_001F2B40();
    char m_pad00[0x150];
    int m_Field150; // +0x150
};

float Class_001F2B40::sub_001F2B40()
{
    return *(float*)(m_Field150 + 80);
}
