// bin: xb
// va: 0x000C6270
// tool: the portal's starter code (no AI)
// sub_000C6270 (0x000C6270, 11 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

class Class_000C6270
{
public:
    int sub_000C6270();
    char m_pad00[0x64];
    int m_Field64; // +0x64
};

int Class_000C6270::sub_000C6270()
{
    return m_Field64 != 0;
}
