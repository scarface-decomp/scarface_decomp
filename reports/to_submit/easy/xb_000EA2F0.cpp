// bin: xb
// va: 0x000EA2F0
// tool: the portal's starter code (no AI)
// sub_000EA2F0 (0x000EA2F0, 16 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

class Class_000EA2F0
{
public:
    bool sub_000EA2F0(float a1);
    char m_pad00[0x18];
    float m_Field18; // +0x18
};

bool Class_000EA2F0::sub_000EA2F0(float a1)
{
    m_Field18 = a1;
    return true;
}
