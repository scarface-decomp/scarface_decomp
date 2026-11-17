// bin: xb
// va: 0x00164EB0
// tool: the portal's starter code (no AI)
// sub_00164EB0 (0x00164EB0, 12 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

class Class_00164EB0
{
public:
    bool sub_00164EB0();
    char m_pad00[0x423];
    unsigned char : 5;
    unsigned char m_Field423_bit5 : 1; // +0x423, bit 5
};

bool Class_00164EB0::sub_00164EB0()
{
    return m_Field423_bit5;
}
