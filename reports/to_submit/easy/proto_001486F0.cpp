// bin: proto
// va: 0x001486F0
// tool: the portal's starter code (no AI)
// sub_001486F0 (0x001486F0, 11 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

class Class_001486F0
{
public:
    bool sub_001486F0();
    char m_pad00[0x241];
    unsigned char : 1;
    unsigned char m_Field241_bit1 : 1; // +0x241, bit 1
};

bool Class_001486F0::sub_001486F0()
{
    return m_Field241_bit1;
}
