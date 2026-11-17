// bin: proto
// va: 0x000BEB70
// tool: the portal's starter code (no AI)
// sub_000BEB70 (0x000BEB70, 12 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

class Class_000BEB70
{
public:
    bool sub_000BEB70();
    char m_pad00[0x19C];
    unsigned char : 2;
    unsigned char m_Field19C_bit2 : 1; // +0x19C, bit 2
};

bool Class_000BEB70::sub_000BEB70()
{
    return m_Field19C_bit2;
}
