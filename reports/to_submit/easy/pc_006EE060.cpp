// bin: pc
// va: 0x006EE060
// tool: the portal's starter code (no AI)
// sub_006EE060 (0x006EE060, 15 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

class Class_006EE060
{
public:
    int sub_006EE060();
    char m_pad00[0x20];
    int m_Field20; // +0x20
    char m_pad24[0x18];
    int m_Field3C; // +0x3C
};

int Class_006EE060::sub_006EE060()
{
    m_Field3C += 1;
    *(int*)(m_Field20 + 72) += 1;
    return 1;
}
