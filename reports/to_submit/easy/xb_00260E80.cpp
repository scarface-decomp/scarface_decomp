// bin: xb
// va: 0x00260E80
// tool: the portal's starter code (no AI)
// sub_00260E80 (0x00260E80, 19 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field08
{
    void sub_00295CD0(int);
};

class Class_00260E80
{
public:
    void sub_00260E80();
    char m_pad00[0x8];
    Field08* m_Field08; // +0x08
    int m_Field0C; // +0x0C
};

void Class_00260E80::sub_00260E80()
{
    if (m_Field08) {
        m_Field08->sub_00295CD0(m_Field0C);
    }
}
