// bin: xb
// va: 0x000B8900
// tool: the portal's starter code (no AI)
// sub_000B8900 (0x000B8900, 11 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

class Class_000B8900
{
public:
    int sub_000B8900();
    char m_pad00[0xC];
    int m_Field0C; // +0x0C
};

int Class_000B8900::sub_000B8900()
{
    return m_Field0C != 0;
}
