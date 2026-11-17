// bin: xb
// va: 0x001CC390
// tool: the portal's starter code (no AI)
// sub_001CC390 (0x001CC390, 21 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

class Class_001CC390
{
public:
    bool sub_001CC390(bool a1);
    char m_pad00[0x7C];
    bool m_Field7C; // +0x7C
    char m_pad7D[0x3];
    float m_Field80; // +0x80
};

bool Class_001CC390::sub_001CC390(bool a1)
{
    m_Field7C = a1;
    m_Field80 = 0.0f;
    return a1;
}
