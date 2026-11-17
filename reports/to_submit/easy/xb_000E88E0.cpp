// bin: xb
// va: 0x000E88E0
// tool: the portal's starter code (no AI)
// sub_000E88E0 (0x000E88E0, 16 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

class Class_000E88E0
{
public:
    bool sub_000E88E0(float a1);
    char m_pad00[0x48];
    float m_Field48; // +0x48
};

bool Class_000E88E0::sub_000E88E0(float a1)
{
    m_Field48 = a1;
    return true;
}
