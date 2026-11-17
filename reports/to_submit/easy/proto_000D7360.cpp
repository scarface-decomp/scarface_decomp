// bin: proto
// va: 0x000D7360
// tool: the portal's starter code (no AI)
// sub_000D7360 (0x000D7360, 8 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

class Class_000D7360
{
public:
    bool sub_000D7360();
    char m_pad00[0x1C];
    unsigned char : 1;
    unsigned char m_Field1C_bit1 : 1; // +0x1C, bit 1
};

bool Class_000D7360::sub_000D7360()
{
    return m_Field1C_bit1;
}
