// bin: proto
// va: 0x00178FF0
// tool: the portal's starter code (no AI)
// sub_00178FF0 (0x00178FF0, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

class Class_00178FF0
{
public:
    void sub_00178FF0(int a1);
    char m_pad00[0x515];
    unsigned char m_Field515; // +0x515
};

void Class_00178FF0::sub_00178FF0(int a1)
{
    m_Field515 = (unsigned char)(m_Field515 ^ ((unsigned char)(((unsigned char)(m_Field515 ^ a1)) & 1)));
}
