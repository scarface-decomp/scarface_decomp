// bin: xb
// va: 0x000B8530
// tool: the portal's starter code (no AI)
// sub_000B8530 (0x000B8530, 11 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

class Class_000B8530
{
public:
    int sub_000B8530();
    char m_pad00[0x4];
    int m_Field04; // +0x04
};

int Class_000B8530::sub_000B8530()
{
    return m_Field04 != 0;
}
