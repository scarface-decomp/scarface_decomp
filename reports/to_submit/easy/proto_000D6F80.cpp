// bin: proto
// va: 0x000D6F80
// tool: the portal's starter code (no AI)
// sub_000D6F80 (0x000D6F80, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

class Class_000D6F80
{
public:
    bool sub_000D6F80();
    char m_pad00[0x29];
    unsigned char m_Field29_bit0 : 1; // +0x29, bit 0
};

bool Class_000D6F80::sub_000D6F80()
{
    return m_Field29_bit0;
}
