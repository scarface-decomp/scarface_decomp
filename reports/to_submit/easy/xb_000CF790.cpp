// bin: xb
// va: 0x000CF790
// tool: the portal's starter code (no AI)
// sub_000CF790 (0x000CF790, 9 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

class Class_000CF790
{
public:
    bool sub_000CF790();
    char m_pad00[0x199];
    unsigned char m_Field199_bit0 : 1; // +0x199, bit 0
};

bool Class_000CF790::sub_000CF790()
{
    return m_Field199_bit0;
}
