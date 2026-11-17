// bin: xb
// va: 0x00217320
// tool: the portal's starter code (no AI)
// sub_00217320 (0x00217320, 24 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

class Class_00217320
{
public:
    void sub_00217320(float a1);
    char m_pad00[0x44];
    bool m_Field44; // +0x44
    char m_pad45[0x7B];
    float m_FieldC0; // +0xC0
};

void Class_00217320::sub_00217320(float a1)
{
    if (m_Field44) {
        m_FieldC0 = a1;
    }
}
