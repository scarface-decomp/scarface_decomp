// bin: xb
// va: 0x000E8990
// tool: the portal's starter code (no AI)
// sub_000E8990 (0x000E8990, 16 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

class Class_000E8990
{
public:
    bool sub_000E8990(float a1);
    char m_pad00[0x6C];
    float m_Field6C; // +0x6C
};

bool Class_000E8990::sub_000E8990(float a1)
{
    m_Field6C = a1;
    return true;
}
