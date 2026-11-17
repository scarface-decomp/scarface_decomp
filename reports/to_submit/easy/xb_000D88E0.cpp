// bin: xb
// va: 0x000D88E0
// tool: the portal's starter code (no AI)
// sub_000D88E0 (0x000D88E0, 12 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

class Class_000D88E0
{
public:
    bool sub_000D88E0();
    char m_pad00[0x22D];
    unsigned char : 6;
    unsigned char m_Field22D_bit6 : 1; // +0x22D, bit 6
};

bool Class_000D88E0::sub_000D88E0()
{
    return m_Field22D_bit6;
}
