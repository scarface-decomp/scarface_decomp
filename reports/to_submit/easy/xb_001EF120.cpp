// bin: xb
// va: 0x001EF120
// tool: the portal's starter code (no AI)
// sub_001EF120 (0x001EF120, 9 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

class Class_001EF120
{
public:
    bool sub_001EF120();
    char m_pad00[0x129];
    unsigned char m_Field129_bit0 : 1; // +0x129, bit 0
};

bool Class_001EF120::sub_001EF120()
{
    return m_Field129_bit0;
}
