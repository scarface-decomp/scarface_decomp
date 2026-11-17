// bin: proto
// va: 0x000FAAE0
// tool: the portal's starter code (no AI)
// sub_000FAAE0 (0x000FAAE0, 21 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

class Class_000FAAE0
{
public:
    void sub_000FAAE0(int a1);
    char m_pad00[0x78];
    int m_Field78; // +0x78
};

void Class_000FAAE0::sub_000FAAE0(int a1)
{
    m_Field78 = m_Field78 ^ ((m_Field78 ^ a1) & 15);
}
