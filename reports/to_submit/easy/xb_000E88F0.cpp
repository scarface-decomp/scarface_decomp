// bin: xb
// va: 0x000E88F0
// tool: the portal's starter code (no AI)
// sub_000E88F0 (0x000E88F0, 16 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

class Class_000E88F0
{
public:
    bool sub_000E88F0(float a1);
    char m_pad00[0x4C];
    float m_Field4C; // +0x4C
};

bool Class_000E88F0::sub_000E88F0(float a1)
{
    m_Field4C = a1;
    return true;
}
