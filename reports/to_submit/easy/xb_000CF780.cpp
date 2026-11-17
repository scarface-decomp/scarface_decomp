// bin: xb
// va: 0x000CF780
// tool: the portal's starter code (no AI)
// sub_000CF780 (0x000CF780, 14 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

class Class_000CF780
{
public:
    int sub_000CF780();
    char m_pad00[0x184];
    int m_Field184; // +0x184
};

int Class_000CF780::sub_000CF780()
{
    return m_Field184 != 0;
}
