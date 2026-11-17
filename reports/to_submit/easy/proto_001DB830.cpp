// bin: proto
// va: 0x001DB830
// tool: the portal's starter code (no AI)
// sub_001DB830 (0x001DB830, 24 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

class Class_001DB830
{
public:
    void sub_001DB830(float a1);
    char m_pad00[0x44];
    bool m_Field44; // +0x44
    char m_pad45[0x7F];
    float m_FieldC4; // +0xC4
};

void Class_001DB830::sub_001DB830(float a1)
{
    if (m_Field44) {
        m_FieldC4 = a1;
    }
}
