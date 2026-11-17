// bin: proto
// va: 0x001B53D0
// tool: the portal's starter code (no AI)
// sub_001B53D0 (0x001B53D0, 9 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

class Class_001B53D0
{
public:
    bool sub_001B53D0();
    char m_pad00[0x111];
    unsigned char m_Field111_bit0 : 1; // +0x111, bit 0
};

bool Class_001B53D0::sub_001B53D0()
{
    return m_Field111_bit0;
}
