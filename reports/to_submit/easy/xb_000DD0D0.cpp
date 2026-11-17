// bin: xb
// va: 0x000DD0D0
// tool: the portal's starter code (no AI)
// sub_000DD0D0 (0x000DD0D0, 16 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

class Class_000DD0D0
{
public:
    bool sub_000DD0D0(float a1);
    char m_pad00[0x14];
    float m_Field14; // +0x14
};

bool Class_000DD0D0::sub_000DD0D0(float a1)
{
    m_Field14 = a1;
    return true;
}
