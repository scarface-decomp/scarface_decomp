// bin: xb
// va: 0x000A3400
// tool: the portal's starter code (no AI)
// sub_000A3400 (0x000A3400, 14 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

class Class_000A3400
{
public:
    void sub_000A3400(float a1);
    char m_pad00[0x4];
    float m_Field04; // +0x04
};

void Class_000A3400::sub_000A3400(float a1)
{
    m_Field04 = a1;
}
