// bin: xb
// va: 0x001D8F20
// what: 
// tool: the portal's starter code (no AI)

// sub_001D8F20 (0x001D8F20, 20 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

class Class_001D8F20
{
public:
    void sub_001D8F20(int a1);
    char m_pad00[0x77];
    unsigned char m_Field77; // +0x77
};

void Class_001D8F20::sub_001D8F20(int a1)
{
    m_Field77 = (unsigned char)(m_Field77 ^ ((unsigned char)(((unsigned char)(m_Field77 ^ a1)) & 1)));
}
