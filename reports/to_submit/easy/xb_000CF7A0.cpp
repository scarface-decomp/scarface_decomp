// bin: xb
// va: 0x000CF7A0
// tool: the portal's starter code (no AI)
// sub_000CF7A0 (0x000CF7A0, 11 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

class Class_000CF7A0
{
public:
    bool sub_000CF7A0();
    char m_pad00[0x199];
    unsigned char : 1;
    unsigned char m_Field199_bit1 : 1; // +0x199, bit 1
};

bool Class_000CF7A0::sub_000CF7A0()
{
    return m_Field199_bit1;
}
