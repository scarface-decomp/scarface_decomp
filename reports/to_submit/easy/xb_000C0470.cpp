// bin: xb
// va: 0x000C0470
// tool: the portal's starter code (no AI)
// sub_000C0470 (0x000C0470, 26 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" float DAT_003A4974;

class Class_000C0470
{
public:
    Class_000C0470* sub_000C0470();
    float m_Field00; // +0x00
    int m_Field04; // +0x04
    int m_Field08; // +0x08
    int m_Field0C; // +0x0C
};

Class_000C0470* Class_000C0470::sub_000C0470()
{
    m_Field00 = DAT_003A4974;
    m_Field04 = 0;
    m_Field08 = 0;
    m_Field0C = 0;
    return this;
}
