// bin: xb
// va: 0x000E8980
// tool: the portal's starter code (no AI)
// sub_000E8980 (0x000E8980, 16 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

class Class_000E8980
{
public:
    bool sub_000E8980(float a1);
    char m_pad00[0x68];
    float m_Field68; // +0x68
};

bool Class_000E8980::sub_000E8980(float a1)
{
    m_Field68 = a1;
    return true;
}
