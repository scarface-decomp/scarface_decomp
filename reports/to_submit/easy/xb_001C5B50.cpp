// bin: xb
// va: 0x001C5B50
// tool: the portal's starter code (no AI)
// sub_001C5B50 (0x001C5B50, 17 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

class Class_001C5B50
{
public:
    unsigned short sub_001C5B50();
    char m_pad00[0x4C];
    int m_Field4C; // +0x4C
};

unsigned short Class_001C5B50::sub_001C5B50()
{
    int r_eax;

    r_eax = m_Field4C;
    if (r_eax) {
        r_eax = *(unsigned short*)(r_eax + 28);
        return r_eax;
    }
    r_eax |= 65535;
    return r_eax;
}
