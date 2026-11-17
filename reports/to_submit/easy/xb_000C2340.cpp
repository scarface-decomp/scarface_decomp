// bin: xb
// va: 0x000C2340
// tool: the portal's starter code (no AI)
// sub_000C2340 (0x000C2340, 23 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

class Class_000C2340
{
public:
    bool sub_000C2340(bool a1);
    char m_pad00[0x2D];
    unsigned char m_Field2D; // +0x2D
    char m_pad2E[0x2];
    float m_Field30; // +0x30
};

bool Class_000C2340::sub_000C2340(bool a1)
{
    if (a1 != m_Field2D) {
        m_Field30 = 0.0f;
        m_Field2D = a1;
    }
    return a1;
}
