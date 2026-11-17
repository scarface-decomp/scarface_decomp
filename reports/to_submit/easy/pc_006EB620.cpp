// bin: pc
// va: 0x006EB620
// tool: the portal's starter code (no AI)
// sub_006EB620 (0x006EB620, 5 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

class Class_006EB620
{
public:
    int sub_006EB620();
    char m_pad00[0x8];
    unsigned short m_Field08; // +0x08
};

int Class_006EB620::sub_006EB620()
{
    return m_Field08;
}
