// bin: xb
// va: 0x001D8F40
// what: 
// tool: the portal's starter code (no AI)

// sub_001D8F40 (0x001D8F40, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

class Class_001D8F40
{
public:
    bool sub_001D8F40();
    char m_pad00[0x77];
    unsigned char m_Field77_bit0 : 1; // +0x77, bit 0
};

bool Class_001D8F40::sub_001D8F40()
{
    return m_Field77_bit0;
}
