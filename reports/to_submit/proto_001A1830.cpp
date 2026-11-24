// bin: proto
// va: 0x001A1830
// what: 
// tool: the portal's starter code (no AI)

// sub_001A1830 (Proto 0x001A1830, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

class Class_001A1830
{
public:
    bool sub_001A1830();
    char m_pad00[0x7B];
    unsigned char m_Field7B_bit0 : 1; // +0x7B, bit 0
};

bool Class_001A1830::sub_001A1830()
{
    return m_Field7B_bit0;
}
