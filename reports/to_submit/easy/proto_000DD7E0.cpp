// bin: proto
// va: 0x000DD7E0
// tool: the portal's starter code (no AI)
// sub_000DD7E0 (0x000DD7E0, 59 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

class Class_000DD7E0
{
public:
    void sub_000DD7E0(float a1, float a2, float a3, float a4);
    char m_pad00[0x3E8];
    float m_Field3E8; // +0x3E8
    float m_Field3EC; // +0x3EC
    float m_Field3F0; // +0x3F0
    float m_Field3F4; // +0x3F4
};

void Class_000DD7E0::sub_000DD7E0(float a1, float a2, float a3, float a4)
{
    m_Field3E8 = a1;
    m_Field3EC = a2;
    m_Field3F0 = a3;
    m_Field3F4 = a4;
}
