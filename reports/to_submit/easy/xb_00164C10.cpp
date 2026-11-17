// bin: xb
// va: 0x00164C10
// tool: the portal's starter code (no AI)
// sub_00164C10 (0x00164C10, 12 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

class Class_00164C10
{
public:
    bool sub_00164C10();
    char m_pad00[0x269];
    unsigned char : 2;
    unsigned char m_Field269_bit2 : 1; // +0x269, bit 2
};

bool Class_00164C10::sub_00164C10()
{
    return m_Field269_bit2;
}
