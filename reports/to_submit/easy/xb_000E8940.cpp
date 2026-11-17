// bin: xb
// va: 0x000E8940
// tool: the portal's starter code (no AI)
// sub_000E8940 (0x000E8940, 16 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

class Class_000E8940
{
public:
    bool sub_000E8940(float a1);
    char m_pad00[0x5C];
    float m_Field5C; // +0x5C
};

bool Class_000E8940::sub_000E8940(float a1)
{
    m_Field5C = a1;
    return true;
}
