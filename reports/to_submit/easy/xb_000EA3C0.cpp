// bin: xb
// va: 0x000EA3C0
// tool: the portal's starter code (no AI)
// sub_000EA3C0 (0x000EA3C0, 22 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

class Class_000EA3C0
{
public:
    int sub_000EA3C0(float a1);
    char m_pad00[0x68];
    int m_Field68; // +0x68
};

int Class_000EA3C0::sub_000EA3C0(float a1)
{
    int t1;

    t1 = m_Field68 + 1;
    m_Field68 = m_Field68 + 1;
    *(float*)((int)this + (t1 * 4) + 84) = a1;
    return t1;
}
