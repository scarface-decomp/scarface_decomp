// bin: proto
// va: 0x000B4950
// tool: the portal's starter code (no AI)
// sub_000B4950 (0x000B4950, 23 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

class Class_000B4950
{
public:
    bool sub_000B4950(bool a1);
    char m_pad00[0x26];
    unsigned char m_Field26; // +0x26
    char m_pad27[0x1];
    float m_Field28; // +0x28
};

bool Class_000B4950::sub_000B4950(bool a1)
{
    if (a1 != m_Field26) {
        m_Field28 = 0.0f;
        m_Field26 = a1;
    }
    return a1;
}
