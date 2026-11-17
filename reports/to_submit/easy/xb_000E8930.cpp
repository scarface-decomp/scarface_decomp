// bin: xb
// va: 0x000E8930
// tool: the portal's starter code (no AI)
// sub_000E8930 (0x000E8930, 16 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

class Class_000E8930
{
public:
    bool sub_000E8930(float a1);
    char m_pad00[0x58];
    float m_Field58; // +0x58
};

bool Class_000E8930::sub_000E8930(float a1)
{
    m_Field58 = a1;
    return true;
}
