// bin: proto
// va: 0x001AA910
// tool: the portal's starter code (no AI)
// sub_001AA910 (0x001AA910, 9 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

class Class_001AA910
{
public:
    bool sub_001AA910();
    char m_pad00[0xA9];
    unsigned char m_FieldA9_bit0 : 1; // +0xA9, bit 0
};

bool Class_001AA910::sub_001AA910()
{
    return m_FieldA9_bit0;
}
