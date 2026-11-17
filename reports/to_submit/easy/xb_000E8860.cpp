// bin: xb
// va: 0x000E8860
// tool: the portal's starter code (no AI)
// sub_000E8860 (0x000E8860, 16 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

class Class_000E8860
{
public:
    bool sub_000E8860(float a1);
    char m_pad00[0x2C];
    float m_Field2C; // +0x2C
};

bool Class_000E8860::sub_000E8860(float a1)
{
    m_Field2C = a1;
    return true;
}
