// bin: xb
// va: 0x000BC9F0
// tool: the portal's starter code (no AI)
// sub_000BC9F0 (0x000BC9F0, 11 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

class Class_000BC9F0
{
public:
    bool sub_000BC9F0();
    char m_pad00[0x8B];
    unsigned char : 1;
    unsigned char m_Field8B_bit1 : 1; // +0x8B, bit 1
};

bool Class_000BC9F0::sub_000BC9F0()
{
    return m_Field8B_bit1;
}
