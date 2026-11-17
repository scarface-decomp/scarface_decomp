// bin: xb
// va: 0x00164E80
// tool: the portal's starter code (no AI)
// sub_00164E80 (0x00164E80, 12 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

class Class_00164E80
{
public:
    bool sub_00164E80();
    char m_pad00[0x423];
    unsigned char : 4;
    unsigned char m_Field423_bit4 : 1; // +0x423, bit 4
};

bool Class_00164E80::sub_00164E80()
{
    return m_Field423_bit4;
}
