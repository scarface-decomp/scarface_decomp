// bin: xb
// va: 0x00217710
// tool: the portal's starter code (no AI)
// sub_00217710 (0x00217710, 12 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

class Class_00217710
{
public:
    bool sub_00217710();
    char m_pad00[0xE9];
    unsigned char : 5;
    unsigned char m_FieldE9_bit5 : 1; // +0xE9, bit 5
};

bool Class_00217710::sub_00217710()
{
    return m_FieldE9_bit5;
}
