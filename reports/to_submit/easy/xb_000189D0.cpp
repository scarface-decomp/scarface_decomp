// bin: xb
// va: 0x000189D0
// tool: the portal's starter code (no AI)
// sub_000189D0 (0x000189D0, 7 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

class Class_000189D0
{
public:
    unsigned short sub_000189D0();
    int m_Field00; // +0x00
};

unsigned short Class_000189D0::sub_000189D0()
{
    return *(unsigned short*)(m_Field00 + 68);
}
