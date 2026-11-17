// bin: xb
// va: 0x000E7570
// tool: the portal's starter code (no AI)
// sub_000E7570 (0x000E7570, 16 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

class Class_000E7570
{
public:
    bool sub_000E7570(float a1);
    char m_pad00[0x24];
    float m_Field24; // +0x24
};

bool Class_000E7570::sub_000E7570(float a1)
{
    m_Field24 = a1;
    return true;
}
