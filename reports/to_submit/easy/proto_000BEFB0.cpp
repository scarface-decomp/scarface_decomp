// bin: proto
// va: 0x000BEFB0
// tool: the portal's starter code (no AI)
// sub_000BEFB0 (0x000BEFB0, 14 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

class Class_000BEFB0
{
public:
    int sub_000BEFB0();
    char m_pad00[0x18C];
    int m_Field18C; // +0x18C
};

int Class_000BEFB0::sub_000BEFB0()
{
    return m_Field18C != 0;
}
