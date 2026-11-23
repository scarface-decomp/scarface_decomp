// bin: xb
// va: 0x001EA850
// what: 
// tool: the portal's starter code (no AI)

// sub_001EA850 (0x001EA850, 8 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

class Class_001EA850
{
public:
    void sub_001EA850();
    char m_pad00[0x1F4];
    unsigned char m_Field1F4; // +0x1F4
};

void Class_001EA850::sub_001EA850()
{
    m_Field1F4 |= 1;
}
