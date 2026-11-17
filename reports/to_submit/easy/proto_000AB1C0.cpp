// bin: proto
// va: 0x000AB1C0
// tool: the portal's starter code (no AI)
// sub_000AB1C0 (0x000AB1C0, 11 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

class Class_000AB1C0
{
public:
    int sub_000AB1C0();
    char m_pad00[0xC];
    int m_Field0C; // +0x0C
};

int Class_000AB1C0::sub_000AB1C0()
{
    return m_Field0C != 0;
}
