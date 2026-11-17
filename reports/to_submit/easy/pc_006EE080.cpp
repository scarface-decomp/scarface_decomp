// bin: pc
// va: 0x006EE080
// tool: the portal's starter code (no AI)
// sub_006EE080 (0x006EE080, 5 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

class Class_006EE080
{
public:
    void sub_006EE080();
    char m_pad00[0x40];
    int m_Field40; // +0x40
};

void Class_006EE080::sub_006EE080()
{
    m_Field40 += 1;
}
