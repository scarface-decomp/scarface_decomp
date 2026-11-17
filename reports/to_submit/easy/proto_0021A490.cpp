// bin: proto
// va: 0x0021A490
// tool: the portal's starter code (no AI)
// sub_0021A490 (0x0021A490, 19 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field08
{
    void sub_00252550(int);
};

class Class_0021A490
{
public:
    void sub_0021A490();
    char m_pad00[0x8];
    Field08* m_Field08; // +0x08
    int m_Field0C; // +0x0C
};

void Class_0021A490::sub_0021A490()
{
    if (m_Field08) {
        m_Field08->sub_00252550(m_Field0C);
    }
}
