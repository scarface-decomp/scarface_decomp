// bin: proto
// va: 0x000D7330
// tool: the portal's starter code (no AI)
// sub_000D7330 (0x000D7330, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

class Class_000D7330
{
public:
    bool sub_000D7330();
    char m_pad00[0x1C];
    unsigned char m_Field1C_bit0 : 1; // +0x1C, bit 0
};

bool Class_000D7330::sub_000D7330()
{
    return m_Field1C_bit0;
}
