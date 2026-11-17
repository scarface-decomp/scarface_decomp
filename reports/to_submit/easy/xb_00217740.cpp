// bin: xb
// va: 0x00217740
// tool: the portal's starter code (no AI)
// sub_00217740 (0x00217740, 12 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

class Class_00217740
{
public:
    bool sub_00217740();
    char m_pad00[0xE9];
    unsigned char : 6;
    unsigned char m_FieldE9_bit6 : 1; // +0xE9, bit 6
};

bool Class_00217740::sub_00217740()
{
    return m_FieldE9_bit6;
}
