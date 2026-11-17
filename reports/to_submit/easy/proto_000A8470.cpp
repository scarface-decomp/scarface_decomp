// bin: proto
// va: 0x000A8470
// tool: the portal's starter code (no AI)
// sub_000A8470 (0x000A8470, 11 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

class Class_000A8470
{
public:
    bool sub_000A8470();
    char m_pad00[0x98];
    unsigned char : 1;
    unsigned char m_Field98_bit1 : 1; // +0x98, bit 1
};

bool Class_000A8470::sub_000A8470()
{
    return m_Field98_bit1;
}
