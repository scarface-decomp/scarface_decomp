// bin: xb
// va: 0x00164E40
// tool: the portal's starter code (no AI)
// sub_00164E40 (0x00164E40, 12 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

class Class_00164E40
{
public:
    bool sub_00164E40();
    char m_pad00[0x423];
    unsigned char : 3;
    unsigned char m_Field423_bit3 : 1; // +0x423, bit 3
};

bool Class_00164E40::sub_00164E40()
{
    return m_Field423_bit3;
}
