// bin: xb
// va: 0x000E8890
// tool: the portal's starter code (no AI)
// sub_000E8890 (0x000E8890, 16 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

class Class_000E8890
{
public:
    bool sub_000E8890(float a1);
    char m_pad00[0x38];
    float m_Field38; // +0x38
};

bool Class_000E8890::sub_000E8890(float a1)
{
    m_Field38 = a1;
    return true;
}
