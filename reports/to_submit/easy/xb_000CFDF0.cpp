// bin: xb
// va: 0x000CFDF0
// tool: the portal's starter code (no AI)
// sub_000CFDF0 (0x000CFDF0, 14 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

class Class_000CFDF0
{
public:
    int sub_000CFDF0();
    char m_pad00[0x118];
    int m_Field118; // +0x118
};

int Class_000CFDF0::sub_000CFDF0()
{
    return m_Field118 != 0;
}
