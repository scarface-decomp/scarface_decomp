// bin: proto
// va: 0x001A1810
// what: 
// tool: the portal's starter code (no AI)

// sub_001A1810 (Proto 0x001A1810, 20 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

class Class_001A1810
{
public:
    void sub_001A1810(int a1);
    char m_pad00[0x7B];
    unsigned char m_Field7B; // +0x7B
};

void Class_001A1810::sub_001A1810(int a1)
{
    m_Field7B = (unsigned char)(m_Field7B ^ ((unsigned char)(((unsigned char)(m_Field7B ^ a1)) & 1)));
}
