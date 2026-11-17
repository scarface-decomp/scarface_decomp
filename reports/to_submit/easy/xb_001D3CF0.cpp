// bin: xb
// va: 0x001D3CF0
// tool: the portal's starter code (no AI)
// sub_001D3CF0 (0x001D3CF0, 24 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

class Class_001D3CF0
{
public:
    void sub_001D3CF0(float a1);
    char m_pad00[0xF0];
    float m_FieldF0; // +0xF0
    char m_padF4[0x1F];
    bool m_Field113; // +0x113
};

void Class_001D3CF0::sub_001D3CF0(float a1)
{
    m_FieldF0 = a1;
    m_Field113 = true;
}
