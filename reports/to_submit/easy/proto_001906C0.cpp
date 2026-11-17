// bin: proto
// va: 0x001906C0
// tool: the portal's starter code (no AI)
// sub_001906C0 (0x001906C0, 17 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

class Class_001906C0
{
public:
    unsigned short sub_001906C0();
    char m_pad00[0x4C];
    int m_Field4C; // +0x4C
};

unsigned short Class_001906C0::sub_001906C0()
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
