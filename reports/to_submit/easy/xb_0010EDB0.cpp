// bin: xb
// va: 0x0010EDB0
// tool: the portal's starter code (no AI)
// sub_0010EDB0 (0x0010EDB0, 14 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

class Class_0010EDB0
{
public:
    int sub_0010EDB0();
    char m_pad00[0x8C];
    int m_Field8C; // +0x8C
};

int Class_0010EDB0::sub_0010EDB0()
{
    return m_Field8C != 0;
}
