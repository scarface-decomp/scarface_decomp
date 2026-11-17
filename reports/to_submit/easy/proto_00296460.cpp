// bin: proto
// va: 0x00296460
// tool: the portal's starter code (no AI)
// sub_00296460 (0x00296460, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

class Class_00296460
{
public:
    void sub_00296460(int a1);
    char m_pad00[0x98];
    unsigned char m_Field98; // +0x98
};

void Class_00296460::sub_00296460(int a1)
{
    m_Field98 = (unsigned char)(m_Field98 ^ ((unsigned char)(((unsigned char)(m_Field98 ^ a1)) & 1)));
}
