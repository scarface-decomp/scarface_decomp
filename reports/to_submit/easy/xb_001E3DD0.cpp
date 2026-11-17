// bin: xb
// va: 0x001E3DD0
// tool: the portal's starter code (no AI)
// sub_001E3DD0 (0x001E3DD0, 9 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

class Class_001E3DD0
{
public:
    bool sub_001E3DD0();
    char m_pad00[0xA5];
    unsigned char m_FieldA5_bit0 : 1; // +0xA5, bit 0
};

bool Class_001E3DD0::sub_001E3DD0()
{
    return m_FieldA5_bit0;
}
