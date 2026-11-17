// bin: proto
// va: 0x000FABA0
// tool: the portal's starter code (no AI)
// sub_000FABA0 (0x000FABA0, 14 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

class Class_000FABA0
{
public:
    int sub_000FABA0();
    char m_pad00[0x84];
    int m_Field84; // +0x84
};

int Class_000FABA0::sub_000FABA0()
{
    return m_Field84 != 0;
}
