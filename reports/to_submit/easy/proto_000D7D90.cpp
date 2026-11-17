// bin: proto
// va: 0x000D7D90
// tool: the portal's starter code (no AI)
// sub_000D7D90 (0x000D7D90, 22 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

class Class_000D7D90
{
public:
    int sub_000D7D90(float a1);
    char m_pad00[0x78];
    int m_Field78; // +0x78
};

int Class_000D7D90::sub_000D7D90(float a1)
{
    int t1;

    t1 = m_Field78 + 1;
    m_Field78 = m_Field78 + 1;
    *(float*)((int)this + (t1 * 4) + 100) = a1;
    return t1;
}
