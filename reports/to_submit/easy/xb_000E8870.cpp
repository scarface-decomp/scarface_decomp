// bin: xb
// va: 0x000E8870
// tool: the portal's starter code (no AI)
// sub_000E8870 (0x000E8870, 16 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

class Class_000E8870
{
public:
    bool sub_000E8870(float a1);
    char m_pad00[0x30];
    float m_Field30; // +0x30
};

bool Class_000E8870::sub_000E8870(float a1)
{
    m_Field30 = a1;
    return true;
}
