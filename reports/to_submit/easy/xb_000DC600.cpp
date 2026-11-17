// bin: xb
// va: 0x000DC600
// tool: the portal's starter code (no AI)
// sub_000DC600 (0x000DC600, 13 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

class Class_000DC600
{
public:
    float sub_000DC600();
    char m_pad00[0x20];
    int m_Field20; // +0x20
};

float Class_000DC600::sub_000DC600()
{
    return *(float*)((int)this + ((m_Field20 + 3 + ((m_Field20 + 3) * 2)) * 4));
}
