// bin: proto
// va: 0x001B53E0
// tool: the portal's starter code (no AI)
// sub_001B53E0 (0x001B53E0, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

class Class_001B53E0
{
public:
    void sub_001B53E0(int a1);
    char m_pad00[0x111];
    unsigned char m_Field111; // +0x111
};

void Class_001B53E0::sub_001B53E0(int a1)
{
    m_Field111 = (unsigned char)(m_Field111 ^ ((unsigned char)(((unsigned char)(m_Field111 ^ a1)) & 1)));
}
