// bin: proto
// va: 0x000CE560
// tool: the portal's starter code (no AI)
// sub_000CE560 (0x000CE560, 9 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

class Class_000CE560
{
public:
    float sub_000CE560();
    char m_pad00[0xE0];
    int m_FieldE0; // +0xE0
};

float Class_000CE560::sub_000CE560()
{
    return *(float*)m_FieldE0;
}
