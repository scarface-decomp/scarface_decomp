// bin: proto
// va: 0x000C6D20
// what: 
// tool: the portal's starter code (no AI)

// sub_000C6D20 (Proto 0x000C6D20, 12 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

class Class_000C6D20
{
public:
    bool sub_000C6D20();
    char m_pad00[0x237];
    unsigned char : 6;
    unsigned char m_Field237_bit6 : 1; // +0x237, bit 6
};

bool Class_000C6D20::sub_000C6D20()
{
    return m_Field237_bit6;
}
