// bin: xb
// va: 0x000881B0
// tool: the portal's starter code (no AI)
// sub_000881B0 (0x000881B0, 12 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

class Class_000881B0
{
public:
    bool sub_000881B0();
    char m_pad00[0x150];
    unsigned char : 4;
    unsigned char m_Field150_bit4 : 1; // +0x150, bit 4
};

bool Class_000881B0::sub_000881B0()
{
    return m_Field150_bit4;
}
